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
#include "Wvariables.cxx"
#include "TopPolarization.C"
#include "assert.h"
#include <vector>
#include "AtlasUtils.h"
#include "AtlasLabels.h"
#include "AtlasStyle.h"

using namespace std;
using std::cerr;
using std::cout;
using std::endl;

struct hist_struct {
  TH1F *h_junk;
  TH1F *h_nlep;
  TH1F *h_nelec;
  TH1F *h_nmuon;
  TH1F *h_njet;
  TH1F *h_nbjet;
  TH1F *h_mv1;
  TH1F *h_Leadmv1;
  TH1F *h_Highmv1;
  TH1F *h_met;
  TH1F *h_Wt;
  TH1F *h_Whel;
  TH1F *h_TopPolHel;
  TH1F *h_TopPolOpt;
  TH1F *h_tM;
  TH1F *h_3lM;
  TH1F *h_AllJetsM;
  TH1F *h_jetdr;

  TH1F *h_MCSF;
  TH1F *h_PileupSF;
  TH1F *h_BtagSF;
  TH1F *h_leptonSF;

  TH2F METvsWtm;
  TH2F METvsLpt;
  TH2F WtmvsLpt;

  std::vector<string> names;//holds which object we are looking at
  std::vector<TH1F*> histos;//hold basic variables for objects
  
  std::vector<TH1F*> combhistos;//hold dr, deta etc... for differences between objects

};

//std::vector<hist_struct*> thestructs; 

void InitStruct(hist_struct *thestruct, string name, Int_t color);

std::vector<TH1F*> allHists;
std::vector<string> histNameVec;

double lum;
string outputDir;
void Loop(TChain *ch, double lum, float xsec, hist_struct *thestruct);



inline TH1F* InitHist(string histname, string histtype, 
                      Int_t nbins, float low, float high, Int_t color, string xaxisName, string yaxisName) {

   if (std::find(histNameVec.begin(), histNameVec.end(), histname) == histNameVec.end()) 
      histNameVec.push_back(histname);

   string fullname = histname+"_"+histtype;
   TH1F *hist= new TH1F(fullname.c_str(), fullname.c_str(),nbins, low, high);
   allHists.push_back(hist);
   hist->GetXaxis()->SetTitle(xaxisName.c_str());
   hist->GetYaxis()->SetTitle(yaxisName.c_str());
   hist->GetYaxis()->SetTitleOffset(1.2);
   return hist;
}

inline void InitStruct(hist_struct *thestruct, string name, Int_t color) {
  thestruct->h_junk = InitHist("junk", name, 10,-0.5,9.5, color, "junk", "Events");
  thestruct->h_nlep = InitHist("nlep", name, 10,-0.5,9.5, color, "Num Leptons", "Events");
  thestruct->h_nelec = InitHist("nelec", name, 10,-0.5,9.5, color, "Num Electrons", "Events");
  thestruct->h_nmuon = InitHist("nmuon", name, 10,-0.5,9.5, color, "Num Muons", "Events");
  thestruct->h_njet = InitHist("njet", name, 10,-0.5,9.5, color, "Num Jets", "Events");
  thestruct->h_nbjet = InitHist("nbjet", name, 10,-0.5,9.5, color, "Num b-Jets", "Events");
  thestruct->h_mv1 = InitHist("mv2c20", name, 25,-1.5,1.5, color, "mv2c00 All Jets", "Events");
  thestruct->h_Leadmv1 = InitHist("Leadmv2c20", name, 25,-1.5,1.5, color, "mv2c00 Leading Jet", "Events");
  thestruct->h_Highmv1 = InitHist("Highestmv2c20", name, 25,-1.5,1.5, color, "Highest mv2c00", "Events");
  thestruct->h_met = InitHist("met", name, 10,0,200, color, "met", "Events");
  thestruct->h_Wt = InitHist("W_transverse_mass", name, 25,0,250, color, "W transverse mass (GeV)", "Events");
  thestruct->h_tM = InitHist("Top_mass", name, 25,0,500, color, "Top-Quark mass (GeV)", "Events");
  thestruct->h_Whel = InitHist("W_helicity", name, 30,-1.5,1.5, color, "W-boson helicity", "Events");
  thestruct->h_TopPolOpt = InitHist("TopPolOpt", name, 30,-1.5,1.5, color, "Top-Quark Polarization Optimal Basis", "Events");
  thestruct->h_TopPolHel = InitHist("TopPolHel", name, 30,-1.5,1.5, color, "Top-Quark Polarization Helicity Basis", "Events");
  thestruct->h_3lM = InitHist("3lMass", name, 25,0,750, color, "3lMass", "Events");
  thestruct->h_AllJetsM = InitHist("AllJetsM", name, 15,0,150, color, "AllJetsM", "Events");
  thestruct->h_jetdr = InitHist("jetdr", name, 14,0,7, color, "b-jet + Leading non b-jet dR", "Events");




  (thestruct->names).push_back("Z_boson"); 
  (thestruct->names).push_back("b-jet");     
  (thestruct->names).push_back("Neutrino");     
  (thestruct->names).push_back("W_boson");     
  (thestruct->names).push_back("Top_Quark");     
  (thestruct->names).push_back("Leading Non b-jet");     
  (thestruct->names).push_back("Z_lepton");     
  (thestruct->names).push_back("Z_antilepton");     
  (thestruct->names).push_back("W_lepton");     
  

  (thestruct->names).push_back("Leading_Lepton");     
  (thestruct->names).push_back("Second_Lepton");   
  (thestruct->names).push_back("Third_Lepton");     
  
  //(thestruct->names).push_back("Leading_Electron");     
  //(thestruct->names).push_back("Second_Electron");     
  //(thestruct->names).push_back("Third_Electron");     
  
  //(thestruct->names).push_back("Leading_Muon");     
  //(thestruct->names).push_back("Second_Muon");     
  //(thestruct->names).push_back("Third_Muon");     
  
  (thestruct->names).push_back("Leading_Jet");     
  (thestruct->names).push_back("Second_Jet");     
  (thestruct->names).push_back("Third_Jet");     
  
  for(unsigned int i=0;i<(thestruct->names).size();i++)
    {
      TH1F *temp1;
      (thestruct->histos).push_back(temp1);//pt
      (thestruct->histos).push_back(temp1);//eta
      (thestruct->histos).push_back(temp1);//phi
      (thestruct->histos).push_back(temp1);//M
  
      for(unsigned int j=0;j<(thestruct->names).size();j++)
	{
	  if(i<j)//for combined objetcts i and j 
	    {
	      TH1F *temp2;
	      (thestruct->combhistos).push_back(temp2);//dr
	      (thestruct->combhistos).push_back(temp2);//deta
	      (thestruct->combhistos).push_back(temp2);//dphi
	      (thestruct->combhistos).push_back(temp2);//inv m
	    }
	}
    }

  for(unsigned int i=0; i<(thestruct->names).size();i++)
    {
      string temp=(thestruct->names).at(i);

      (thestruct->histos).at(4*i+0) = InitHist(temp+" Pt",name,20,0,400,color,temp+" Pt (GeV)","Events");
      (thestruct->histos).at(4*i+1) = InitHist(temp+" Eta",name,10,-5,5,color,temp+" Eta","Events");
      (thestruct->histos).at(4*i+2) = InitHist(temp+" Phi",name,25,-4,4,color,temp+" Phi","Events");
      (thestruct->histos).at(4*i+3) = InitHist(temp+" M",name,25,0,200,color,temp+" Mass (GeV)","Events");
    }

  unsigned int k=0;
  for(unsigned int i=0; i<(thestruct->names).size();i++)
    {

      for(unsigned int j=i+1; j<(thestruct->names).size();j++)
	{
	  string temp=(thestruct->names).at(i);
	  temp=temp+"+"; 
	  temp=temp+(thestruct->names).at(j);
	  
	  (thestruct->combhistos).at(k++) = InitHist("("+temp+")dR",name,14,0,7,color,"("+temp+")dR","Events");
	  (thestruct->combhistos).at(k++) = InitHist("("+temp+")dEta",name,12,-10,10,color,"("+temp+")dEta","Events");
	  (thestruct->combhistos).at(k++) = InitHist("("+temp+")dPhi",name,12,-4,4,color,"("+temp+")dPhi","Events");
	  (thestruct->combhistos).at(k++) = InitHist("("+temp+")invM",name,50,0,500,color,"("+temp+").invM (GeV)","Events");
	}
    }

  //cout<<"k="<<k<<'\n';
  //cout<<"combsize="<<(thestruct->combhistos).size()<<'\n';

  assert(k==(thestruct->combhistos).size());
  

  thestruct->h_MCSF = InitHist("MCSF", name, 201,-20,20, color, "MCSF", "Events");
  thestruct->h_PileupSF = InitHist("pileupSF", name,50,-5,5 , color, "pileupSF", "Events");
  thestruct->h_BtagSF = InitHist("btagSF", name, 50,-5,5, color, "btagSF", "Events");
  thestruct->h_leptonSF = InitHist("leptonSF", name, 50,-5,5 , color, "leptonSF", "Events");



  thestruct->METvsWtm=TH2F("METvsWtm","METvsWtm",50,0,250,50,0,250);
  thestruct->METvsLpt=TH2F("METvsLpt","METvsLpt",50,0,250,50,0,250);
  thestruct->WtmvsLpt=TH2F("WtmvsLpt","WtmvsLpt",50,0,250,50,0,250);

  
}

inline void Fill(TH1F *h, float value, float weight=1) {
  TAxis *x = h->GetXaxis();
  int nbins = x->GetNbins();
  float max = x->GetBinUpEdge(nbins);
  float min = x->GetBinLowEdge(1);
  float thisvalue = value;
  float widthlow = h->GetBinWidth(1);
  float widthhigh = h->GetBinWidth(nbins);
  if (thisvalue > max) thisvalue = max-widthhigh/2;
  if (thisvalue < min) thisvalue = min+widthlow/2;
  h->Fill(thisvalue, weight);
}

