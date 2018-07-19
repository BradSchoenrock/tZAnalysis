#include "ztAnalysis.h"
#include "Loop.C"
//#include "TopD3PD.C"

//typedef TopD3PD D3PDEvent;

int main(int argc, char **argv) {
   lum = 3.20905; // luminosity units of fb^-1
 
   string line;
   ifstream sampleFileIn(argv[1]);//read in the samplefile
   if (!sampleFileIn.is_open()) {
      cerr << "file = " << argv[1] << " not open! " << endl;
      return -1;
   }
   string numIn(argv[2]);

   vector<string> paths; //these 4 vectors hold the four pieces of information in each line of the samplefile
   vector<float> xsecs;
   vector<string> names;
   vector<int> colors;
   while(getline(sampleFileIn,line)) {
      string token;
      stringstream lineStream;
      int counter = 0;
      lineStream << line;
      while(lineStream >> token) {
	if (counter == 0) {
            paths.push_back(token);
	    cout<<"token = "<<token<<endl;
	}
         else if (counter == 1) 
            xsecs.push_back(atof(token.c_str()));
         else if (counter == 2) 
            names.push_back(token);
         else if (counter == 3)
            colors.push_back(atoi(token.c_str()));
         else {
            cerr << "line = " << line << " has too many columns!" << endl; 
         }
         counter++;
      }
   }
   //print out that information to check it was being read correctly
   for (unsigned int isample = 0; isample < paths.size(); isample++) {
     cout << " path = " << paths[isample] << '\n' << " xsec [pb] = " << xsecs[isample] << '\n' << " names = " << names[isample] << '\n' << " color = " << colors[isample] << endl;
   }

  
   unsigned int itype = 0;
    
   hist_struct *thisstruct = new hist_struct;
   InitStruct(thisstruct, names[itype], colors[itype]);
   TChain *ch = new TChain("nominal_Loose");//what tree we are reading in
   ch->Add(paths[itype].c_str());
   //cout<<"just added to ch "<<paths[itype].c_str()<<'\n';
   cout << '\n'<<"about to loop over " << names[itype] << endl;
 
   cout<<"lum="<<(double)lum<<'\n'<<"xsec="<<xsecs[itype]<<'\n'<<"ch->GetEntries()="<<ch->GetEntries()<<'\n';
   // cout<<"before loop"<<'\n';

   bool isData=(names[itype]=="Data");//data is weighted differently than MC so it is treated differently in loop
   Loop(ch, lum, xsecs[itype], thisstruct, isData);
   //cout<<"after loop"<<'\n';
   delete ch;
   
   stringstream ss("");//creating the name of the output root file
   ss<<(string)"output/fout";
   ss<<numIn;
   ss<<(string)".root";
   string s2;
   ss>>s2;
   cout<<s2<<'\n';
   const char* nam=s2.c_str();

   cout<<"file name = "<<nam<<'\n';

   TFile *fout = new TFile(nam,"RECREATE"); 
   fout->cd();

   //filling the output root file with histograms
   for (unsigned int istack = 0; istack < histNameVec.size(); istack++) {
     //vector<TH1F> thethifs;
     //int n=-1;
         
     for (unsigned int itter = 0; itter < paths.size(); itter++) {
       //cout<<"itter="<<itter<<'\n';
       
       //cout<<"names[itter]="<<names[itter]<<'\n';
       
       string fullname = histNameVec[istack]+"_"+names[itter];
       //cout<<"fullname.c_str()="<<fullname.c_str()<<'\n';
       
       TH1F *hist = allHists.at(istack);  //(TH1F*)thedir->FindObjectAny(fullname.c_str());
       hist->SetNameTitle(histNameVec[istack].c_str(),histNameVec[istack].c_str());
       if (!hist) cerr << "BAD! Could not find " << fullname << endl;
       else {	 
	 hist->SetFillColor(colors[itter]);
	 hist->SetLineColor(colors[itter]);
	 	
	 //thethifs.push_back(*hist);
	 hist->Write();
	 //n++;
	
       }
     }
     
   
     gStyle->SetOptStat(0);
     
   }   
   (thisstruct->METvsWtm).Write();
   (thisstruct->METvsLpt).Write();
   (thisstruct->WtmvsLpt).Write();
   
   fout->Write();
   delete fout;
   delete thisstruct;

}

