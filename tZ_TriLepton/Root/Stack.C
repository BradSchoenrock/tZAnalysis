#include "TLatex.h"
#include "TLorentzVector.h"
#include "stdio.h"
#include <sstream>
#include <string>
#include <algorithm>
#include <iostream>
#include <fstream>
#include "TH2.h"
#include "TH1.h"
#include "TCanvas.h"
#include "TLegend.h"
#include "TAxis.h"
#include "THStack.h"
#include "TRandom3.h"
#include "TStyle.h"
#include "TClonesArray.h"
#include "ExRootTreeReader.h"
#include "assert.h"
#include <vector>
#include "ztAnalysis.h"
#include "TKey.h" 
#include "AtlasUtils.h"
#include "AtlasLabels.h"
#include "AtlasStyle.h"
#include "TPaletteAxis.h"
#include "THistPainter.h"
#include "TColor.h"

using namespace std;


void PrintSHsize(vector<vector <TH1F*> >samplehistos)//a function to make sure this data structure is being filled correctly
{
  cout<<"PrintSHsize"<<endl;
  if(samplehistos.size()==0)
    cout<<"samplehistos.size()= its empty... "<<endl;
  else
    {
      cout<<"samplehistos.size()="<<samplehistos.size()<<endl;//how many vectors are in our vector of vectors
      for(unsigned int k=0;k<samplehistos.size();k++)
	cout<<"(samplehistos.at("<<k<<")).size()="<<(samplehistos.at(k)).size()<<endl;//how big is each vector in our vector of vectors. 
    }
    
  cout<<"Whats inside?"<<endl;// lets make sure the histograms have values and can be read. prints the memory addresses and the integral of each histogram for ensuring that the structure has been filled apropriatly. 
  
  cout<<"samplehistos.size()="<<samplehistos.size()<<endl;
  for(unsigned int i=0;i<samplehistos.size();i++)
    for(unsigned int j=0;j<(samplehistos.at(i)).size();j++)
      {
	cout<<"((samplehistos.at(i)).at(j)) address "<<((samplehistos.at(i)).at(j))<<'\n'; 
	cout<<"  -  (samplehistos.at("<<i<<")).at("<<j<<").Integral="<<((samplehistos.at(i)).at(j))->Integral()<<endl;
      }
  
}


void PrintInputs(vector<string> paths,vector<float> xsecs,vector<string> samplenames,vector<int> colors)//a function to ensure the samplefile is being read correctly. 
{
    assert(paths.size()==xsecs.size());
    assert(paths.size()==samplenames.size());
    assert(paths.size()==colors.size());

    cout<<"paths.size()="<<paths.size()<<endl<<"xsecs.size()="<<xsecs.size()<<endl<<"samplenames.size()="<<samplenames.size()<<endl<<"colors.size()="<<colors.size()<<endl;
    
    for (unsigned int isample = 0; isample < paths.size(); isample++) {
    cout << " path = " << paths.at(isample) << endl << " xsec [pb] = " << xsecs.at(isample) << endl << " samplenames = " << samplenames.at(isample) << endl << " color = " << colors.at(isample) << endl;
  }
  
}

vector<int>CalcNameSpots(vector<string> samplenames)//calculates the places where the samplefile switches samples ie how many lines of the samplefile belong to each sample. the vector that is returned notes the positions where we switch samples. Assumes that the samplefile is written with all of the same sample grouped 
{
  vector<int>iname;
  int p=0;
  for(unsigned int i=0;i<samplenames.size();i++)
    {
       if(p==0)
	{
	  iname.push_back(i);
	  p++;
	}
       else if( samplenames.at(i) != samplenames.at(iname.at(p-1)))//we have switched samples (ttbar to tZ) 
	{
	  iname.push_back(i);
	  p++;
	}
    }
  return iname;
}

vector<double> CalcWeightFix(vector<string> paths,vector<string> samplenames,vector<double> weightfix)//because the histograms we are reading in have no information on how many events are in each sample they need to be reweighted. this holds the number of events in each sample. 
{
  int p=0;
  for(unsigned int i=0;i<paths.size()-1;i++)
    {
      TFile rootfile((paths.at(i)).c_str());
      TDirectory* dir=(TDirectory*)rootfile.Get("eee");
      dir->cd();
      TH1F *hist;
      TIter next(dir->GetListOfKeys());
      TKey *key;
      key = (TKey*)next();//cutflow
      key = (TKey*)next();//cutflow_mc
      key = (TKey*)next();//cutflow_mc_pu_
      key = (TKey*)next();//cutflow_mc_pu_zvtx
      TClass *cl = gROOT->GetClass(key->GetClassName());
      if (!cl->InheritsFrom("TH1")) continue;
      std::string histname = key->GetName();
      //histname = key->GetName();
      //cout<<"histname="<<histname<<endl;
      
      hist = (TH1F*)key->ReadObj();
      Double_t binContent = hist->GetBinContent(1);// have number of generated events in this one file.       
      //cout<<"i="<<i<<endl;
      stringstream ss;
      ss << "output/fout";
      ss << i+1;// note that file names are 1 indexed while the vectors here are 0 indexed
      ss << ".root";
      
      string st;
      ss>>st;
      
      //cout<<"st= "<<st<<endl;
      
      TFile fin(st.c_str());  
     
      
      if(p==0)
	{  
	  weightfix.push_back((double)binContent);
	  p++;
	}
      else if(samplenames.at(i)!=samplenames.at(i-1))
	{
	  weightfix.push_back((double)binContent);
	  p++;
	}
      else
	{
	  weightfix.at(p-1)=weightfix.at(p-1)+((double)binContent);
	}
      
    }
  
  return weightfix;
  
}

vector<vector <TH1F*> >FillHistos(vector<vector <TH1F*> > samplehistos, vector<string> iname, vector<string> samplenames,vector<string> histNames)//this function actually fills the vector<vector <TH1F> > and is the cause of 90% of your headaches when understanding this piece of code. Lots of cout were left commented out here which were used for debugging this function.  
{
  int p=0;//this variable counts up how many samples have been added to the structure so far, ttbar, tZ, data, etc.... Each time we add a new one we incrament p. 
  
  //cout<<"samplenames.size()="<<samplenames.size()<<endl;
  
  for(unsigned int i=0;i<iname.size();i++)//for starters we fill the structure with empty pointers. 
    {
      vector<TH1F*> tempvec; 
      samplehistos.push_back(tempvec); 
      //PrintSHsize(samplehistos);

      for(unsigned int j=0;j<histNames.size(); j++)
	{
	  TH1F *h1;
	  (samplehistos.at(i)).push_back(h1);
	  //PrintSHsize(samplehistos);

	}
    }
  //go ahead and check that the size is correct. the current samplefile leaves this at 73x328 that is 73 samples (ttbar, data, Zee_Pt500_700_CVetBVet, etc...) by 328 histograms (nlep, njet, lepPt, etc...)
  //PrintSHsize(samplehistos);

  
  for(unsigned int i=0;i<samplenames.size()-1;i++)//loop over files and add up same sample histograms into one histo - note that file names are one indexed
    {
      //cout<<endl<<endl<<"i="<<i<<"     p="<<p<<endl;
      stringstream ss;
      ss << "output/fout";
      ss << i+1;// note that file names are 1 indexed while the vectors here are 0 indexed
      ss << ".root";
      
      string st;
      ss>>st;
      //stringstreams are how i concatinate strings, so the following cout shows what the string is. 
      //cout<<"st= "<<st<<endl;
      
      TFile fin(st.c_str());  
    	      
      //PrintSHsize(samplehistos);

      if(!fin.IsZombie())//as long as the file is openable
	{
	  //if(i==0)
	  //cout<<"samplenames.at("<<i<<")="<<samplenames.at(i)<<endl;
	 
	  if(p==0 || samplenames.at(i-1) != samplenames.at(i))//p=0 means we are just starting (the first sample is going in. if the sample names are different between itterations (the second condition) then we have switched samples and need to go to the next itteration in p 
	    {
	      //cout<<"in if"<<endl;
	      //cout<<"histNames.size()="<<histNames.size()<<'\n';
	    
	      for(unsigned int j=0;j<histNames.size(); j++)
		{
		  //if(p==0)
		  //cout<<"p="<<p<<"     j="<<j<<'\n';
		  //cout<<"j="<<j<<"   histNames.at("<<j<<")="<<(histNames.at(j)).c_str()<<'\n';
		  TH1F *h1 = (TH1F*)fin.Get((histNames.at(j)).c_str());
		  h1->SetDirectory(0); // "detach" the histogram from the file. This is nesicarry otherwise when the file closes, the data in our structure gets removed and we are left with pointers pointing to nothing  
		  ((samplehistos.at(p)).at(j))=h1;
		  //cout<<"h1 address "<<h1<<"  -  h1->Integral="<<h1->Integral()<<endl;
		  //cout<<"the adress of ((samplehistos.at("<<p<<")).at("<<j<<"))=";
		  //cout<<((samplehistos.at(p)).at(j))<<'\n';
		  //tempvec.push_back(h1); 
		}
	      // for(unsigned int q=0;q<tempvec.size();q++)
	      //cout<<"tempvec.at(q) adress "<<tempvec.at(q)<<"  -  tempvec.at("<<q<<")->Integral()="<<tempvec.at(q)->Integral()<<endl;  
	      //PrintSHsize(samplehistos);

	      p++;
              //cout<<"p(iter):"<<p<<endl;
	    }//end if
	  else //this is for adding further histograms to the data structure once the first one has been added. each file being read in is not unique samples so we need to add them up. There are currently 121 data files that need to be added together for example. 
	    {
	      //cout<<"in else"<<endl;
	      
	      for(unsigned int j=0;j<histNames.size(); j++)
		{
		  // if(p==0)
		  // cout<<"p-1="<<p-1<<"     j="<<j<<'\n';
		  //cout<<"j="<<j<<"   histNames.at("<<j<<")="<<(histNames.at(j)).c_str()<<'\n';
		  TH1F *h1 = (TH1F*)fin.Get((histNames.at(j)).c_str());
		  h1->SetDirectory(0); // "detach" the histogram from the file   This is nesicarry otherwise when the file closes, the data in our structure gets removed and we are left with pointers pointing to nothing  
		  //cout<<"h1 address "<<h1<<"  -  h1->Integral="<<h1->Integral()<<endl;
		  //cout<< "SHbinsX"<<((samplehistos.at(p-1)).at(j))->GetNbinsX()<<'\n';
		  //cout<< "h1binsX"<<h1->GetNbinsX()<<'\n';
		  ((samplehistos.at(p-1)).at(j))->Add(h1); 
		    
		}
	      // for(unsigned int q=0;q<tempvec.size();q++)
	      // cout<<"tempvec.at(q) adress "<<tempvec.at(q)<<"  -  tempvec.at("<<q<<")->Integral()="<<tempvec.at(q)->Integral()<<endl;  

	       //PrintSHsize(samplehistos);
	       
	       
	    }//end else if
	  
	  //cout<<""<<endl;
	}//end if fin zombie
      
      //cout<<"end of itteration "<<i<<endl;
    }//end loop over fin files
  
  //cout<<"about to return"<<endl;
  //PrintSHsize(samplehistos);

 return samplehistos;
}


vector<vector <TH2F*> >Fill2DHistos(vector<vector <TH2F*> >TwoDhistos,vector<string> iname,vector<string> samplenames)
{
  int p=0;//this variable counts up how many samples have been added to the structure so far, ttbar, tZ, data, etc.... Each time we add a new one we incrament p. 
  
  //cout<<"samplenames.size()="<<samplenames.size()<<endl;
  
  for(unsigned int i=0;i<iname.size();i++)//for starters we fill the structure with empty pointers. 
    {
      vector<TH2F*> tempvec; 
      TwoDhistos.push_back(tempvec); 
      
      for(unsigned int j=0;j<3; j++)//This is hard coded, the three corresponds to the three TH2Fs defined in ztAnalysis.h which plot Wtm, MET, and leading lepton Pt against each other. 
	{
	  TH2F *h1;
	  (TwoDhistos.at(i)).push_back(h1);
	}
    }
  

  for(unsigned int i=0;i<samplenames.size()-1;i++)//loop over files and add up same sample histograms into one histo - note that file names are one indexed
    {
      stringstream ss;
      ss << "output/fout";
      ss << i+1;// note that file names are 1 indexed while the vectors here are 0 indexed
      ss << ".root";
      
      string st;
      ss>>st;
      //stringstreams are how i concatinate strings, so the following cout shows what the string is. 
      //cout<<"st= "<<st<<endl;
      
      TFile fin(st.c_str());  
    	      
      if(!fin.IsZombie())//as long as the file is openable
	{
	  //if(i==0)
	  //cout<<"samplenames.at("<<i<<")="<<samplenames.at(i)<<endl;
	 
	  if(p==0 || samplenames.at(i-1) != samplenames.at(i))//p=0 means we are just starting (the first sample is going in. if the sample names are different between itterations (the second condition) then we have switched samples and need to go to the next itteration in p 
	    {
	      //cout<<"in if"<<endl;
	      //cout<<"histNames.size()="<<histNames.size()<<'\n';
	    
	      TH2F *h1 = (TH2F*)fin.Get("METvsWtm");
	      TH2F *h2 = (TH2F*)fin.Get("METvsLpt");
	      TH2F *h3 = (TH2F*)fin.Get("WtmvsLpt");

	      h1->SetDirectory(0); // "detach" the histogram from the file. This is nesicarry otherwise when the file closes, the data in our structure gets removed and we are left with pointers pointing to nothing  
	      h2->SetDirectory(0);
	      h3->SetDirectory(0);
	      ((TwoDhistos.at(p)).at(0))=h1;
	      ((TwoDhistos.at(p)).at(1))=h2;
	      ((TwoDhistos.at(p)).at(2))=h3;

	      p++;
              //cout<<"p(iter):"<<p<<endl;
	    }//end if
	  else //this is for adding further histograms to the data structure once the first one has been added. each file being read in is not unique samples so we need to add them up. There are currently 121 data files that need to be added together for example. 
	    {
	      //cout<<"in else"<<endl;
	       
	      TH2F *h1 = (TH2F*)fin.Get("METvsWtm");
	      TH2F *h2 = (TH2F*)fin.Get("METvsLpt");
	      TH2F *h3 = (TH2F*)fin.Get("WtmvsLpt");

	      h1->SetDirectory(0); // "detach" the histogram from the file. This is nesicarry otherwise when the file closes, the data in our structure gets removed and we are left with pointers pointing to nothing  
	      h2->SetDirectory(0);
	      h3->SetDirectory(0);

	      ((TwoDhistos.at(p-1)).at(0))->Add(h1); 
	      ((TwoDhistos.at(p-1)).at(1))->Add(h2); 
	      ((TwoDhistos.at(p-1)).at(2))->Add(h3); 
	       
	    }//end else if
	  
	}//end if fin zombie
      
      //cout<<"end of itteration "<<i<<endl;
    }//end loop over fin files
  
  return TwoDhistos;
  
}



vector<THStack*> InitStacks( vector<THStack*> stacks, vector<string> histNames)//note this function currently causes a memory leak, a destructor has not yet been written. This structure holds THStacks and is the size of the number of histograms that is being made. 
{
  for(unsigned int i=0;i<histNames.size();i++)
    {
      //cout<<"i="<<i<<'\n';
      THStack *thestack=new THStack((histNames.at(i)).c_str(),(histNames.at(i)).c_str());
      stacks.push_back(thestack);
    }
  return stacks;
}

vector<double> getYeilds(vector<double> yields,vector<string> iname,vector< vector<TH1F*> >samplehistos)// gets how many events are in each sample. fills them into the vec double and returns it. 
{
  for(unsigned int z=0;z<iname.size();z++)
    {
      //if(y==0)
      //cout<<"sample:"<<iname.at(z)<<"  weightfix="<<weightfix.at(z)<<'\n';
      yields.push_back(samplehistos[z][0]->Integral());
    }
  
  ofstream myfile;
  myfile.open ("Tables/yields.txt");
  for(unsigned int q=0;q<yields.size();q++)
    {
      assert(iname.size()==yields.size());
      myfile<<iname.at(q)<<"   "<<yields.at(q)<<'\n';
    }
  myfile.close();
  
  return yields;
}


int main(int argc, char **argv) {

  string line;
  ifstream sampleFileIn("../samplefiles/samplefileN");//it reads the samplefile to know the composition of the fout##.root files. the fout##.root files were created using this samplefile so they need to correspond 1:1 with this. if the samplefileN was edited between running ztAnalsyis and Stack then you have to start over so they match. If you run run_things.sh both steps are done in succession but sometimes it is better to run just this program to change formatting of plots as it saves time. 
  if (!sampleFileIn.is_open()) {
    cerr << "file = " << "../samplefiles/samplefileN" << " not open! " << endl;
    return(1);
  }
  
   //reading in the samplefile to know what we need to stack. the samplefile consists of 4 pieces of information per line, a path to an input root file (flat ntuple), the cross section of that sample, the name of that sample, and the color it is to be drawn in. if there are more than 4 columns then this will spit out an error. 
  
  vector<string> paths; 
  vector<float> xsecs;
  vector<string> samplenames;
  vector<int> colors;
  while(getline(sampleFileIn,line)) {
    string token;
    stringstream lineStream;
    int counter = 0;
    lineStream << line;
    while(lineStream >> token) {
      if (counter == 0) {
	paths.push_back(token);
	//cout<<"token = "<<token<<endl;
      }
      else if (counter == 1) 
	xsecs.push_back(atof(token.c_str()));
      else if (counter == 2) 
	samplenames.push_back(token);
      else if (counter == 3)
	colors.push_back(atoi(token.c_str()));
      else {
	cerr << "line = " << line << " has too many columns!" << endl; 
      }
      counter++;
    }
  }
  
 
  //this line prints the results of reading in the file. 
  //PrintInputs(paths,xsecs,samplenames,colors);
    
  //initializing the histogram struct. This function is stored in ztAnalysis.h I want to move that.  *******************************************
  hist_struct *thisstruct = new hist_struct;
  InitStruct(thisstruct, samplenames[0], colors[0]);

  //cout<< "histNameVec.size() = " <<  histNameVec.size() << endl; 
  

  vector<int> namespot=CalcNameSpots(samplenames);//holds the positions of new samples ttbar, tz etc... 
        
  vector<string> iname;//holds the unique sample names
  for(unsigned int i=0;i<namespot.size();i++)
    iname.push_back(samplenames.at(namespot.at(i)));
  
  // for(unsigned int i=0;i<iname.size();i++)
  // cout<<"iname.at("<<i<<")="<<iname.at(i)<<endl;
  
  
  vector<double> weightfix;//because we have to weight by all events in a given sample we need to calculate the number of MC events across multiple files. weightfix has this number. 
  weightfix=CalcWeightFix(paths,samplenames,weightfix);

  
  assert(weightfix.size()==namespot.size());//these three should all be the size of the number of samples we have. if they are not then something is wrong. 
  assert(weightfix.size()==iname.size());
  

  //for(unsigned int i=0;i<weightfix.size();i++)
  //  cout<<i<<"  "<<iname.at(i)<<" has a fix of "<<weightfix.at(i)<<endl;
  
  vector< vector<TH1F*> > samplehistos; //holds histograms.
  vector< vector<TH2F*> > TwoDhistos; // holds 2d histos. 
  
  samplehistos=FillHistos(samplehistos,iname,samplenames,histNameVec);//fills the samplehistos data structure. 
  TwoDhistos=Fill2DHistos(TwoDhistos,iname,samplenames);//fills the samplehistos data structure. 

  vector<THStack*> stacks; //holds all our stacked histograms 
  
  stacks=InitStacks(stacks,histNameVec);//fills the stacks data structure. 

  vector<TH1F*> data;//holds TH1Fs with the data in them 

  for(unsigned int y=0;y<samplehistos.size();y++)//these nested loops fill both stacks and data as well as apply the weightfix for the number of events in each MC sample.
    {
      for(unsigned int z=0;z<(samplehistos.at(y)).size();z++)
	{
	  cout<<"y="<<y<<'\n';
	  cout<<"z="<<z<<'\n';
	  cout<<"iname.at("<<y<<")="<<iname.at(y)<<'\n';
	  cout<<"histNameVec.at("<<z<<")="<<histNameVec.at(z)<<'\n';
	  cout<<"samplehistos["<<y<<"]["<<z<<"]->Integral()="<<samplehistos[y][z]->Integral()<<'\n';
	  if(y!=samplehistos.size()-1)//this means data... 
	    {
	      //cout<<"case1"<<'\n';
	      if(z<(samplehistos.at(y)).size()-4)//the last 4 histograms are plots of the 4 weights and scaling them makes no sense. 
		samplehistos[y][z]->Scale(1.0/weightfix.at(y));
	      (stacks.at(z))->Add(samplehistos[y][z]);
	    }
	  else
	    {
	      //cout<<"case2"<<'\n';
	      data.push_back(samplehistos[y][z]);
	    }
	}
    }

 
  //getting event yeilds and writing them to a text file in histos/yields.txt
  vector<double> yields;
  yields=getYeilds(yields,iname,samplehistos);

  //make the legend
  TLegend *leg = new TLegend(0.65,0.45,0.95,0.85);
  leg->SetFillStyle(0);
  leg->SetFillColor(0);
  leg->SetLineColor(0);
  leg->SetShadowColor(0);
 
  //the commented out code below gets sample names by searching, but will list legend entries for Z 70-140 seperatly from Z 140-260 (or whatever) instead of one Z+jets label in the legend. hard coded for now. in the future i would like to improve this. 

  //for(unsigned int z=iname.size()-1;z>0;z--)
  //{
  //if(z==iname.size()-1)
  //leg->AddEntry(samplehistos[0][z], (iname.at(z)).c_str() ,"pe");//is data... 
  //else
  //leg->AddEntry(samplehistos[0][z], (iname.at(z)).c_str() ,"f");//is MC...
  //}
  
  leg->AddEntry(samplehistos[58][0], "Data" ,"pe");
  leg->AddEntry(samplehistos[57][0], "tZ" ,"f");
  leg->AddEntry(samplehistos[56][0], "t#bar{t}" ,"f");
  //leg->AddEntry(samplehistos[66][0], "W+jets" ,"f");
  leg->AddEntry(samplehistos[25][0], "Z+jets" ,"f");
  leg->AddEntry(samplehistos[16][0], "Diboson" ,"f");
  leg->AddEntry(samplehistos[5][0], "t#bar{t}V" ,"f");
  leg->AddEntry(samplehistos[0][0], "SingleTop" ,"f");
  leg->AddEntry(samplehistos[40][0], "tZx5" ,"l");//**********tzx25**********
  
  leg->SetTextFont(42);
  leg->SetTextSize(0.05);
  
  outputDir = "./histos";
  
  cout<<"histNameVec.size()="<<histNameVec.size()<<'\n';
  
  
  for(unsigned int q=0; q<histNameVec.size(); q++)
    //for(unsigned int q=0; q<10; q++)
    {
      cout<<'\n'<<'\n';

      cout<<"q="<<q<<'\n';   
      cout<<"histNameVec.at("<<q<<")="<<histNameVec.at(q)<<'\n';
      //cout<<"stacks.size()="<<stacks.size()<<'\n';
      //cout<<"stacks.at("<<q<<")="<<stacks.at(q)<<'\n';
      //cout<<"data.size()="<<data.size()<<'\n';
      //cout<<"data.at("<<q<<")="<<data.at(q)<<'\n';
      //cout<<"(*data.at(q)).GetMaximumBin()="<<(*data.at(q)).GetMaximumBin()<<'\n';
      //cout<<"(*data.at(q)).GetBinContent((*data.at(q)).GetMaximumBin())="<<(*data.at(q)).GetBinContent((*data.at(q)).GetMaximumBin())<<'\n';
      //cout<<"stacks.at(q).GetXaxis()="<<(*stacks.at(q)).GetXaxis()<<'\n';
      //cout<<"data.at(q).GetXaxis()="<<(*data.at(q)).GetXaxis()<<'\n';
      
      //string stuff = ("canvas_"+(histNameVec.at(q))).c_str();
      //string stuff2=(histNameVec.at(q)).c_str();
      
      //cout<<"stuff="<<stuff<<'\n'<<"stuff2="<<stuff2<<'\n';
  
      //creates a canvas to be saved. formatting is done on this canvas. 
      TCanvas can1( ("canvas_"+(histNameVec.at(q))).c_str() , (histNameVec.at(q)).c_str() , 600 , 600);

      can1.cd();
           
      //removing stat box, title, etc... 
      gStyle->SetOptTitle(0);
      gStyle->SetOptStat(0);
      
      //formatting the data points
      (data.at(q))->SetFillColor(0);
      (data.at(q))->SetLineWidth(2);
      (data.at(q))->SetLineColor(1);
      (data.at(q))->SetMarkerSize(1.2);
      (data.at(q))->SetMarkerStyle(20);
      
      //now we want both the data and the MC to fit on the plot, so we find the max of each and make sure that fits on the canvas. 
      double maxbinstack=(*stacks.at(q)).GetMaximum();
      double maxbindata=(*data.at(q)).GetBinContent((*data.at(q)).GetMaximumBin());

      if(maxbinstack>maxbindata)
	(*stacks.at(q)).SetMaximum((*stacks.at(q)).GetMaximum()*1.50);
      else
	(*stacks.at(q)).SetMaximum((*data.at(q)).GetMaximum()*1.50);
            
      //format the legend
      leg->SetFillStyle(0);
      leg->SetBorderSize(0);
      //gStyle->SetLegendBorderSize(0);
      //leg->SetFillColor(-1);
      //leg->SetLineColor(0);
      //leg->SetShadowColor(-1);
      //gStyle->ForceStyle();
 
      SetAtlasStyle();
          
      (*stacks.at(q)).Draw();
      (*data.at(q)).Draw("SAMEEX0");
      
      TH1F temp=*(samplehistos[namespot.size()-2][q]);//i want to draw the signal as a line on the canvas but i dont want to change the THStack which is built from samplehistos, so i have to copy the contents of the samplehistos vector at the relevant point. 
      temp.SetFillColor(0);
      temp.Scale(5);// ************************ tz line x25 ******************

      if(q<histNameVec.size()-4)
	temp.Draw("SAME");


      leg->Draw();
          
      //getting axis labels and applying them
            
      TAxis *xaxis = (stacks.at(q))->GetXaxis();
      TAxis *yaxis = (stacks.at(q))->GetYaxis();
      yaxis->SetTitleOffset(1.7);
      
      TList *histos = (*stacks.at(q)).GetHists();
      TIter next(histos);
      TH1F *hist = (TH1F*)next();
           
      xaxis->SetTitle(hist->GetXaxis()->GetTitle());
      yaxis->SetTitle(hist->GetYaxis()->GetTitle());
     
      //adding words to the histogram
      ATLAS_LABEL(0.2,0.88,1);
      //myText(0.15, 0.9, 1, "ATLAS internal");
      


      //can1.SetTicks(1,1);//!@#$%^&*()   see note above ^^ why are they not the same the options for each are 0,1,2 which correspond to standard axes, tickmarks on both sides, and numbers on both sides for x and y respectivly. oddly the first one seems to set the y axis and the second does nothing at all. 
      
      //can1.SetTickx(0);//these two lines apear to do nothing. They are supposed to format the x and y axis above and to the right of the plot. 
      //can1.SetTicky(0);


      can1.SetLogy(0);//this line causes a segfault. i have no idea why. 
      can1.Print(Form("%s/%s.eps",outputDir.c_str(),(histNameVec.at(q)).c_str()));
      can1.Print(Form("%s/%s.pdf",outputDir.c_str(),(histNameVec.at(q)).c_str()));
      can1.Print(Form("%s/%s.png",outputDir.c_str(),(histNameVec.at(q)).c_str()));
      can1.Print(Form("%s/%s.root",outputDir.c_str(),(histNameVec.at(q)).c_str()));
      
      
      can1.SetLogy(1);//this line causes a segfault. i have no idea why. It doesn't make sense to wright log histograms if i cant set log y ... 
      can1.Print(Form("%s/%s_log.eps",outputDir.c_str(),(histNameVec.at(q)).c_str()));
      can1.Print(Form("%s/%s_log.pdf",outputDir.c_str(),(histNameVec.at(q)).c_str()));
      can1.Print(Form("%s/%s_log.png",outputDir.c_str(),(histNameVec.at(q)).c_str()));
      can1.Print(Form("%s/%s_log.root",outputDir.c_str(),(histNameVec.at(q)).c_str()));
      

      //delete can1;
      
    }
 
  
  for(unsigned int w=0;w<TwoDhistos.size();w++)
    {
      for(unsigned int x=0;x<(TwoDhistos.at(w)).size();x++)
	{
	  
	  cout<<"w="<<w<<"   x="<<x<<'\n';
	  
	  if(x==0)
	    {
	      if(w==58)
		{
		  TCanvas can1( "canvas_METvsWtm" , "METvsWtm Data" , 600 , 600);
		  
		  can1.cd();
		  
		  SetAtlasStyle();
		  
		  //gStyle->SetPalette(1);
		  
		  //TwoDhistos[w][x]->SetAxisColor(7,"Z");
		    
		  TwoDhistos[w][x]->Draw("COLZ");
		  
		  TwoDhistos[w][x]->GetXaxis()->SetTitle("MET (GEV)");
		  TwoDhistos[w][x]->GetYaxis()->SetTitle("W Transverse Mass (GeV)");
		  TwoDhistos[w][x]->GetXaxis()->CenterTitle();
		  TwoDhistos[w][x]->GetYaxis()->CenterTitle();
		  TwoDhistos[w][x]->GetYaxis()->SetTitleOffset(1.4);

		  ATLAS_LABEL(0.2,0.88,1);
		 
		  //gStyle->SetPalette(1);
		  //gStyle->SetOptTitle(0);
		  //gStyle->SetOptStat(0);
				       
		  can1.Print("histos/METvsWtm_Data.root");
		  can1.Print("histos/METvsWtm_Data.pdf");
		  can1.Print("histos/METvsWtm_Data.png");

		}
	       if(w==57)
		{
		  TCanvas can1( "canvas_METvsWtm" , "METvsWtm Signal" , 600 , 600);
		  
		  can1.cd();
		  
		  SetAtlasStyle();
		  
		  TwoDhistos[w][x]->Draw("COLZ");
		   
		  TwoDhistos[w][x]->GetXaxis()->SetTitle("MET (GeV)");
		  TwoDhistos[w][x]->GetYaxis()->SetTitle("W Transverse Mass (GeV)");  
		  TwoDhistos[w][x]->GetXaxis()->CenterTitle();
		  TwoDhistos[w][x]->GetYaxis()->CenterTitle();
		  TwoDhistos[w][x]->GetYaxis()->SetTitleOffset(1.4);

		  ATLAS_LABEL(0.2,0.88,1);
		 
		  //gStyle->SetPalette(1);
		  //gStyle->SetOptTitle(0);
		  //gStyle->SetOptStat(0);
		   
		  can1.Print("histos/METvsWtm_Signal.root");
		  can1.Print("histos/METvsWtm_Signal.pdf");
		  can1.Print("histos/METvsWtm_Signal.png");

		}
	      
	    }
	  
	}
    }
  

  
  cout<< "done" << endl;
  delete thisstruct;
  delete leg;

  return(0);

}
