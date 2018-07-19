#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <map>
#include <sstream>
#include <string>
 
#include <TString.h>
#include "TexTable.h"


using namespace std;

string SamplesName(string name);

void EventYieldTable(vector<string> names, vector<float> yields);

int main(int nArguments, char* argument[]) {

  if(nArguments !=2) {
    cout << "Wrong Number of Arguments" << endl;
    return 0; 
  }
      
  TString path      = argument[1]; 

  ///////////////////////////////////////////////////
  ////// Print initial information //////////////////  
  ///////////////////////////////////////////////////
  cout<<" ############################################################# " <<endl;
  cout<<" ## Input file  =  "<<path<<std::endl;
  cout<<" ############################################################# " <<endl;

  vector<string> names; 
  vector<float> yields;

  string line;
  ifstream sampleFileIn(path);

  if (!sampleFileIn.is_open()) {
    cout << "Input event yield file isnot open! " << endl;
    return(1);
  }

  while(getline(sampleFileIn,line)) {

    string token;
    stringstream lineStream;
    int counter = 0;
    lineStream << line;
    while(lineStream >> token) {
      if (counter == 0) {
        names.push_back(token);
      }
      else if (counter == 1)
        yields.push_back(atof(token.c_str()));
      else {
        cerr << "line = " << line << " has too many columns!" << endl;
      }
      counter++;
    }
  }

  EventYieldTable(names, yields);

  return(0);
}

void EventYieldTable(vector<string> names, vector<float> yields){

  // create document header and table
  string placement = "ht!";
  string columnRules = "l | r"; 

  TexTable table(placement);
 
  //Z+jets eventyield table
  table.AddHeader(placement,columnRules);
   

  // add header row with labels
  table.hline();
  table.hline();
  table.AddRow("Process & Signal region");
  table.hline();

  vector<double> vtotalmc;
  vector<string> samples;
  double totalmc=0, sum_ttbar=0, sum_Diboson=0, sum_stop=0, sum_ttV=0, sum_Zjets=0;
  //double etotalmc=0;
  unsigned int ysize = (names.size()-2);

  for(unsigned int i=0;i<ysize;++i){

    if((names[i].find("Ztautau") != string::npos) || (names[i].find("Zmumu") != string::npos) || (names[i].find("Zee") != string::npos)){
      stringstream row;
      row.precision(2);
      row.setf(ios::fixed);
      row<<SamplesName(names[i]);
      row<<" & ";
      row<<yields[i];
      table.AddRow(row.str());
      sum_Zjets +=yields[i];
    }
    else if((names[i].find("schan") != string::npos) || (names[i].find("Wt") != string::npos) || (names[i].find("tbarchan") != string::npos) || (names[i].find("tchan") != string::npos)){
      sum_stop +=yields[i];
    }
    else if((names[i].find("ttZ") != string::npos) || (names[i].find("ttW") != string::npos) || (names[i].find("ttH") != string::npos) ){
      sum_ttV +=yields[i];
    }
    else if((names[i].find("ZZ") != string::npos) || (names[i].find("WZ") != string::npos) || (names[i].find("WW") != string::npos) ){
      sum_Diboson +=yields[i];
    }
    else if(names[i].find("ttbar") != string::npos){
	sum_ttbar +=yields[i];
    }

    if(i==(ysize-1)){

      samples.push_back("ttbar");
      vtotalmc.push_back(sum_ttbar);

      samples.push_back("stop");
      vtotalmc.push_back(sum_stop);

      samples.push_back("ttV");
      vtotalmc.push_back(sum_ttV);

      samples.push_back("Zjets");
      vtotalmc.push_back(sum_Zjets);

      samples.push_back("Diboson");
      vtotalmc.push_back(sum_Diboson);

    }
    
    totalmc += yields[i];

    //etotalmc += pow(eyields[i],2);
  }

  //double emc = sqrt(etotalmc);

  
  table.hline();
  table.hline();

  TString caption = "Predicted event yields in the signal region for Z+jets.";
  TString filename = "Tables/EventYieldTable.tex";
  TString label = "tab:eventyield_Zjets";

  table.AddTrailer(caption,label);



  //event yield table
  table.AddHeader(placement,columnRules);
   
  // add header row with labels
  table.hline();
  table.hline();
  table.AddRow("Process & Signal region");
  table.hline();

  for(unsigned int i=0;i<ysize;++i){

  if((names[i].find("Ztautau") != string::npos) || (names[i].find("Zmumu") != string::npos) || (names[i].find("Zee") != string::npos)){
  }
  else{
      stringstream row;
      row.precision(2);
      row.setf(ios::fixed);
      row<<SamplesName(names[i]);
      row<<" & ";
      row<<yields[i];
      table.AddRow(row.str());
  }
  }


  table.hline();
  table.hline();

  TString caption1 = "Predicted event yields in the signal region for all backgrounds except Z+jets.";
  TString label1 = "tab:eventyield_BG";

  table.AddTrailer(caption1,label1);

  //event yield table
  table.AddHeader(placement,columnRules);
   
  // add header row with labels
  table.hline();
  table.hline();
  table.AddRow("Process & Signal region");
  table.hline();

  for(unsigned int i=0;i<samples.size();++i){
      stringstream row;
      row.precision(2);
      row.setf(ios::fixed);
      row<<SamplesName(samples[i]);
      row<<" & ";
      row<<vtotalmc[i];
      table.AddRow(row.str());
  }

  table.hline();
  stringstream rowtZ;
  rowtZ.precision(2);
  rowtZ.setf(ios::fixed);
  rowtZ<<SamplesName(names[ysize]);
  rowtZ<<" & ";
  rowtZ<<yields[ysize];
  table.AddRow(rowtZ.str());

  double SoB=yields[ysize]/totalmc;
  double SosqrtB=yields[ysize]/sqrt(totalmc);
  totalmc +=yields[ysize];
    
  table.hline();
  stringstream rowmc;
  rowmc.precision(2);
  rowmc.setf(ios::fixed);
  rowmc<<"Total Expected";
  rowmc<<" & ";
  rowmc<<totalmc;
  //rowmc<<"$\\pm$";
  //rowmc<<emc;
  table.AddRow(rowmc.str());

  stringstream rowdata;
  rowdata.precision(2);
  rowdata.setf(ios::fixed);
  rowdata<<names[ysize+1];
  rowdata<<" Observed";
  rowdata<<" & ";
  rowdata<<yields[ysize+1];
  table.AddRow(rowdata.str());

  table.hline();

  stringstream rowSoB;
  rowSoB.precision(2);
  rowSoB.setf(ios::fixed);
  rowSoB<<" S/B";
  rowSoB<<" & ";
  rowSoB<<SoB;
  table.AddRow(rowSoB.str());
   
  stringstream rowSosqrtB;
  rowSosqrtB.precision(2);
  rowSosqrtB.setf(ios::fixed);
  rowSosqrtB<<" S/sqrtB";
  rowSosqrtB<<" & ";
  rowSosqrtB<<SosqrtB;
  table.AddRow(rowSosqrtB.str());
  
  table.hline();
  table.hline();


  TString caption2 = "Observed and predicted event yields in the signal region for an integrated luminosity of $3,21 fb^{-1}$.";
  TString label2 = "tab:eventyield";

  table.AddTrailer(caption2,label2);

  ofstream outfile(filename,ios_base::trunc);
  if(!outfile){
    cerr << "ERROR opening file " << filename << " for writing.\n";
    return;
  }
  
  outfile << table.GetTableText();

  outfile.close();

}


string SamplesName(string name){
  
  string output = name;

  if(name=="schan") output="$s$-channel";
  if(name=="Wtbar_inc") output="$W\\bar{t}$";
  if(name=="Wt_inc") output= "$Wt$";
  if(name=="tbarchan") output= "$\\bar{t}$-channel";
  if(name=="tchan") output= "$t$-channel";
  if(name=="ttZnnqq_Np2") output= "ttZnnqq Np2";
  if(name=="ttZnnqq_Np1") output= "ttZnnqq Np1";
  if(name=="ttZnnqq_Np0") output= "ttZnnqq Np0";
  if(name=="tttautau_Np1")output="tttautau Np1";
  if(name=="tttautau_Np0")output="tttautau Np0";
  if(name=="ttmumu_Np1")output="ttmumu Np1";
  if(name=="ttmumu_Np0")output="ttmumu Np0";
  if(name=="ttee_Np1")output="ttee Np1";
  if(name=="ttee_Np0")output="ttee Np0";
  if(name=="ttZllonshell_Np1") output= "ttZllonshell Np1";
  if(name=="ttZllonshell_Np0") output= "ttZllonshell Np0";
  if(name=="ttW_Np2") output= "ttW Np2";
  if(name=="ttW_Np1") output= "ttW Np1";
  if(name=="ttW_Np0") output= "ttW Np0";
  if(name=="ZZqqll") output= "ZZqqll";
  if(name=="WZlvqq") output= "WZlvqq";
  if(name=="WZqqll") output= "WZqqll";
  if(name=="WWlvqq") output= "WWlvqq";
  if(name=="ZZvvll") output= "ZZvvll";
  if(name=="ZZllll") output= "ZZllll";
  if(name=="WZlvvv") output= "WZlvvv";
  if(name=="WZlvll") output= "WZlvll";
  if(name=="WWlvlv") output= "WWlvlv";
  if(name=="Ztautau_Pt2000_E_CMS_BFil") output= "$Z \\rightarrow \\tau\\tau$ $p_T$ (2000) ECMS BFil";
  if(name=="Ztautau_Pt2000_E_CMS_CFilBVet") output= "$Z \\rightarrow \\tau\\tau$ $p_T$ (2000) ECMS CFilBVet";
  if(name=="Ztautau_Pt2000_E_CMS_CVetBVet") output= "$Z \\rightarrow \\tau\\tau$ $p_T$ (2000 ECMS CVetBVet";
  if(name=="Ztautau_Pt1000_2000_BFil") output= "$Z \\rightarrow \\tau\\tau$ $p_T$ (1000,2000) BFil";
  if(name=="Ztautau_Pt1000_2000_CFilBVet") output= "$Z \\rightarrow \\tau\\tau$ $p_T$ (1000,2000) CFilBVet";
  if(name=="Ztautau_Pt1000_2000_CVetBVet") output= "$Z \\rightarrow \\tau\\tau$ $p_T$ (1000,2000) CVetBVet";
  if(name=="Ztautau_Pt700_1000_BFil") output= "$Z \\rightarrow \\tau\\tau$ $p_T$ (700,1000) BFil";
  if(name=="Ztautau_Pt700_1000_CFilBVet") output= "$Z \\rightarrow \\tau\\tau$ $p_T$ (700,1000) CFilBVet";
  if(name=="Ztautau_Pt700_1000_CVetBVet") output= "$Z \\rightarrow \\tau\\tau$ $p_T$ (700,1000) CVetBVet";
  if(name=="Ztautau_Pt500_700_BFil") output= "$Z \\rightarrow \\tau\\tau$ $p_T$ (500,700) BFil";
  if(name=="Ztautau_Pt500_700_CFilBVet") output= "$Z \\rightarrow \\tau\\tau$ $p_T$ (500,700) CFilBVet";
  if(name=="Ztautau_Pt500_700_CVetBVet") output= "$Z \\rightarrow \\tau \\tau$ $p_T$ (500,700) CVetBVet";
  if(name=="Ztautau_Pt280_500_BFil") output= "$Z \\rightarrow \\tau \\tau$ $p_T$ (280,500) BFil";
  if(name=="Ztautau_Pt280_500_CFilBVet") output= "$Z \\rightarrow \\tau \\tau$ $p_T$ (280,500) CFilBVet";
  if(name=="Ztautau_Pt500_700_CVetBVet") output= "$Z \\rightarrow \\tau \\tau$ $p_T$ (500,700) CVetBVet";
  if(name=="Ztautau_Pt280_500_BFil") output= "$Z \\rightarrow \\tau \\tau$ $p_T$ (280,500) BFil";
  if(name=="Ztautau_Pt280_500_CFilBVet") output= "$Z \\rightarrow \\tau \\tau$ $p_T$ (280,500) CFilBVet";
  if(name=="Ztautau_Pt280_500_CVetBVet") output= "$Z \\rightarrow \\tau \\tau$ $p_T$ (280,500) CVetBVet";
  if(name=="Ztautau_Pt140_280_BFil") output= "$Z \\rightarrow \\tau \\tau$ $p_T$ (140,280) BFil";
  if(name=="Ztautau_Pt140_280_CFilBVet") output= "$Z \\rightarrow \\tau \\tau$ $p_T$ (140,280) CFilBVet";
  if(name=="Ztautau_Pt140_280_CVetBVet") output= "$Z \\rightarrow \\tau \\tau$ $p_T$ (140,280) CVetBVet";
  if(name=="Ztautau_Pt70_140_BFil") output= "$Z \\rightarrow \\tau \\tau$ $p_T$ (70,140) BFil";
  if(name=="Ztautau_Pt70_140_CFilBVet") output= "$Z \\rightarrow \\tau \\tau$ $p_T$ (70,140) CFilBVet";
  if(name=="Ztautau_Pt70_140_CVetBVet") output= "$Z \\rightarrow \\tau \\tau$ $p_T$ (70,140) CVetBVet";
  if(name=="Ztautau_Pt0_70_BFil") output= "$Z \\rightarrow \\tau \\tau$ $p_T$ (0,70) BFil";
  if(name=="Ztautau_Pt0_70_CFilBVet") output= "$Z \\rightarrow \\tau \\tau$ $p_T$ (0,70) CFilBVet";
  if(name=="Ztautau_Pt0_70_CVetBVet") output= "$Z \\rightarrow \\tau \\tau$ $p_T$ (0,70) CVetBVet";
  if(name=="Zmumu_Pt2000_E_CMS_BFil") output= "$Z \\rightarrow \\mu \\mu$ $p_T$ (2000) ECMS BFil";
  if(name=="Zmumu_Pt2000_E_CMS_CFilBVet") output= "$Z \\rightarrow \\mu \\mu$ $p_T$ (2000) ECMS CFilBVet";
  if(name=="Zmumu_Pt2000_E_CMS_CVetBVet") output= "$Z \\rightarrow \\mu \\mu$ $p_T$ (2000) ECMS CVetBVet";
  if(name=="Zmumu_Pt1000_2000_BFil") output= "$Z \\rightarrow \\mu \\mu$ $p_T$ (1000,2000) BFil";
  if(name=="Zmumu_Pt1000_2000_CFilBVet") output= "$Z \\rightarrow \\mu \\mu$ $p_T$ (1000,2000) CFilBVet";
  if(name=="Zmumu_Pt1000_2000_CVetBVet") output= "$Z \\rightarrow \\mu \\mu$ $p_T$ (1000,2000) CVetBVet";
  if(name=="Zmumu_Pt700_1000_BFil") output= "$Z \\rightarrow \\mu \\mu$ $p_T$ (700,1000) BFil";
  if(name=="Zmumu_Pt700_1000_CFilBVet") output= "$Z \\rightarrow \\mu \\mu$ $p_T$ (700,1000) CFilBVet";
  if(name=="Zmumu_Pt700_1000_CVetBVet") output= "$Z \\rightarrow \\mu \\mu$ $p_T$ (700,1000) CVetBVet";
  if(name=="Zmumu_Pt500_700_BFil") output= "$Z \\rightarrow \\mu \\mu$ $p_T$ (500,700) BFil";
  if(name=="Zmumu_Pt500_700_CFilBVet") output= "$Z \\rightarrow \\mu \\mu$ $p_T$ (500,700) CFilBVet";
  if(name=="Zmumu_Pt500_700_CVetBVet") output= "$Z \\rightarrow \\mu \\mu$ $p_T$ (500,700) CVetBVet";
  if(name=="Zmumu_Pt280_500_BFil") output= "$Z \\rightarrow \\mu \\mu$ $p_T$ (280,500) BFil";
  if(name=="Zmumu_Pt280_500_CFilBVet") output= "$Z \\rightarrow \\mu \\mu$ $p_T$ (280,500) CFilBVet";
  if(name=="Zmumu_Pt280_500_CVetBVet") output= "$Z \\rightarrow \\mu \\mu$ $p_T$ (280,500) CVetBVet";
  if(name=="Zmumu_Pt140_280_BFil") output= "$Z \\rightarrow \\mu \\mu$ $p_T$ (140,280) BFil";
  if(name=="Zmumu_Pt140_280_CFilBVet") output= "$Z \\rightarrow \\mu \\mu$ $p_T$ (140,280) CFilBVet";
  if(name=="Zmumu_Pt140_280_CVetBVet") output= "$Z \\rightarrow \\mu \\mu$ $p_T$ (140,280) CVetBVet";
  if(name=="Zmumu_Pt70_140_BFil") output= "$Z \\rightarrow \\mu \\mu$ $p_T$ (70,140) BFil";
  if(name=="Zmumu_Pt70_140_CFilBVet") output= "$Z \\rightarrow \\mu \\mu$ $p_T$ (70,140) CFilBVet";
  if(name=="Zmumu_Pt70_140_CVetBVet") output= "$Z \\rightarrow \\mu \\mu$ $p_T$ (70,140) CVetBVet";
  if(name=="Zmumu_Pt0_70_BFil") output= "$Z \\rightarrow \\mu \\mu$ $p_T$ (0,70) BFil";
  if(name=="Zmumu_Pt0_70_CFilBVet") output= "$Z \\rightarrow \\mu \\mu$ $p_T$ (0,70) CFilBVet";
  if(name=="Zmumu_Pt0_70_CVetBVet") output= "$Z \\rightarrow \\mu \\mu$ $p_T$ (0,70) CVetBVet";
  if(name=="Zee_Pt2000_E_CMS_BFil") output= "$Z \\rightarrow e e$ $p_T$ (2000) ECMS BFil";
  if(name=="Zee_Pt2000_E_CMS_CFilBVet") output= "$Z \\rightarrow e e$ $p_T$ (2000) ECMS CFilBVet";
  if(name=="Zee_Pt2000_E_CMS_CVetBVet") output= "$Z \\rightarrow e e$ $p_T$ (2000) ECMS CVetBVet";
  if(name=="Zee_Pt1000_2000_BFil") output= "$Z \\rightarrow e e$ $p_T$ (1000,2000) BFil";
  if(name=="Zee_Pt1000_2000_CFilBVet") output= "$Z \\rightarrow e e$ $p_T$ (1000,2000) CFilBVet";
  if(name=="Zee_Pt1000_2000_CVetBVet") output= "$Z \\rightarrow e e$ $p_T$ (1000,2000) CVetBVet";
  if(name=="Zee_Pt700_1000_BFil") output= "$Z \\rightarrow e e$ $p_T$ (700,1000) BFil";
  if(name=="Zee_Pt700_1000_CFilBVet") output= "$Z \\rightarrow e e$ $p_T$ (700,1000) CFilBVet";
  if(name=="Zee_Pt500_700_BFil") output= "$Z \\rightarrow e e$ $p_T$ (500,700) BFil";
  if(name=="Zee_Pt500_700_CFilBVet") output= "$Z \\rightarrow e e$ $p_T$ (500,700) CFilBVet";
  if(name=="Zee_Pt500_700_CVetBVet") output= "$Z \\rightarrow e e$ $p_T$ (500,700) CVetBVet";
  if(name=="Zee_Pt280_500_BFil") output= "$Z \\rightarrow e e$ $p_T$ (280,50) BFil";
  if(name=="Zee_Pt280_500_CFilBVet") output= "$Z \\rightarrow e e$ $p_T$ (280,500) CFilBVet";
  if(name=="Zee_Pt280_500_CVetBVet") output= "$Z \\rightarrow e e$ $p_T$ (280,500) CVetBVet";
  if(name=="Zee_Pt140_280_BFil") output= "$Z \\rightarrow e e$ $p_T$ (140,280) BFil";
  if(name=="Zee_Pt140_280_CFilBVet") output= "$Z \\rightarrow e e$ $p_T$ (140,280) CFilBVet";
  if(name=="Zee_Pt140_280_CVetBVet") output= "$Z \\rightarrow e e$ $p_T$ (140,280) CVetBVet";
  if(name=="Zee_Pt70_140_BFil") output= "$Z \\rightarrow e e$ $p_T$ (70,140) BFil";
  if(name=="Zee_Pt70_140_CFilBVet") output= "$Z \\rightarrow e e$ $p_T$ (70,140) CFilBVet";
  if(name=="Zee_Pt70_140_CVetBVet") output= "$Z \\rightarrow e e$ $p_T$ (70,140) CVetBVet";
  if(name=="Zee_Pt0_70_BFil") output= "$Z \\rightarrow e e$ $p_T$ (0,70) BFil";
  if(name=="Zee_Pt0_70_CFilBVet") output= "$Z \\rightarrow e e$ $p_T$ (0,70) CFilBVet";
  if(name=="Zee_Pt0_70_CVetBVet") output= "$Z \\rightarrow e e$ $p_T$ (0,70) CVetBVet";
  if(name=="Wjets") output= "$W$+jets";
  if(name=="ttbar") output= "$t\\bar{t}$";
  if(name=="tZ") output= "$tZ$";
  if(name=="stop") output= "single top";
  if(name=="ttV") output= "$ttV$";
  if(name=="Zjets") output= "$Z$ + jets";


  return output;
}
