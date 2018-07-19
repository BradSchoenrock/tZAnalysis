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
#include "THStack.h"
#include "TRandom3.h"
#include "TStyle.h"
#include "TClonesArray.h"
#include "ExRootTreeReader.h"
#include "Wvariables.cxx"
#include "TopPolarization.C"
#include "assert.h"
#include <vector>

using namespace std;
using std::cerr;
using std::cout;
using std::endl;

struct hist_struct {
  TH1F *h_nlep;
  TH1F *h_nelec;
  TH1F *h_nmuon;
  TH1F *h_njet;
  TH1F *h_ntag;
  TH1F *h_wtransversemass;
  TH1F *h_scalarHT;
  TH1F *topMass;
  TH1F *topRapidity;
  TH1F *InvMassAllJets;
  TH1F *WHelicity;
  TH1F *TopPolHelBasis;
  TH1F *TopPolOptimalBasis;
  TH1F *Shat;
  
  std::vector<TH1F*> combhistos;
  std::vector<string> names;
  std::vector<TH1F*> histos;
 
};

//std::vector<hist_struct*> thestructs; 

void InitStruct(hist_struct *thestruct, string name, Int_t color);

std::vector<TH1F*> allHists;
std::vector<string> histNameVec;

float minMET;

int minJet;
int maxJet;
float minJetPt;
float maxJetEta;

int nTag;
float minBJetPt;
float maxBJetEta;

float minElectronPt;
float maxElectronEta;

float minMuonPt;
float maxMuonEta;

int nlep;

double lum;
TCanvas *c1;
TCanvas *c2;
TFile *fout;
string outputDir;
string detString;
void Loop(TChain *ch, float xsec, hist_struct *thestruct);
void Print(THStack stack, string name, TLegend *l, TFile *fout);
TDirectory *thedir;



inline TH1F* InitHist(string histname, string histtype, 
                      Int_t nbins, float low, float high, Int_t color, string xaxisName, string yaxisName) {

   if (std::find(histNameVec.begin(), histNameVec.end(), histname) == histNameVec.end()) 
      histNameVec.push_back(histname);

   string fullname = histname+"_"+histtype;
   TH1F *hist= new TH1F(fullname.c_str(), fullname.c_str(),nbins, low, high);
   allHists.push_back(hist);
   hist->SetMarkerStyle(20);
   hist->SetMarkerSize(0.8);
   //if (color != 0) {
   hist->SetFillColor(color);
   hist->SetLineColor(color);
   //}
   //else {
   //hist->SetFillColor(0);
   //hist->SetLineColor(1);
   //}
   hist->SetLineWidth(2);
   hist->GetXaxis()->SetTitle(xaxisName.c_str());
   hist->GetYaxis()->SetTitle(yaxisName.c_str());
   hist->GetYaxis()->SetTitleOffset(1.2);
   return hist;
}

inline void InitStruct(hist_struct *thestruct, string name, Int_t color) {
  thestruct->h_nlep = InitHist("nlep", name, 10,-0.5,9.5, color, "Num Leptons", "Events");
  thestruct->h_nelec = InitHist("nelec", name, 10,-0.5,9.5, color, "Num Electrons", "Events");
  thestruct->h_nmuon = InitHist("nmuon", name, 10,-0.5,9.5, color, "Num Muons", "Events");

  thestruct->h_njet = InitHist("njet", name, 10,-0.5,9.5, color, "Num Jets", "Events");
  thestruct->h_scalarHT = InitHist("ScalarHT",name,20 ,0 ,1000 , color, "ScalarHT (GeV)","Events / 80GeV");
  thestruct->h_ntag = InitHist("ntag", name, 6, -0.5, 5.5, color, "nbtags", "Events");
  thestruct->h_wtransversemass = InitHist("wtransversemass", name,10,0,400,color, "W Transverse Mass [GeV]", "Events / 40GeV");
  thestruct->topMass = InitHist("TopMass",name,15,0,300,color,"Top Mass [GeV]","Events / 20 GeV");
  thestruct->topRapidity=InitHist("TopRapidity",name,10,-2,2,color,"Top Rapidity","Events");
  thestruct->WHelicity = InitHist("WHelicity",name,10,-2,2,color,"WHelicity","Events");
  thestruct->TopPolHelBasis = InitHist("TopPolHelBasis",name,10,-2,2,color,"TopPolHelBasis","Events");
  thestruct->TopPolOptimalBasis = InitHist("TopPolOptimalBasis",name,10,-2,2,color,"TopPolOptimalBasis","Events");
  thestruct->InvMassAllJets = InitHist("InvMassAllJets",name,15,0,3000,color,"InvMassAllJets (GeV)","Events / 200GeV");
  thestruct->Shat = InitHist("Shat",name,15,0,3000,color,"Shat (GeV)","Events / 200GeV");
  

  (thestruct->names).push_back("Lepton1");     
  (thestruct->names).push_back("Lepton2");      
  (thestruct->names).push_back("Lepton3");
 
  (thestruct->names).push_back("ZLepton");
  (thestruct->names).push_back("ZAntiLepton");      
  (thestruct->names).push_back("WLepton"); 
     
  (thestruct->names).push_back("bJet");   
  (thestruct->names).push_back("LeadingNonBJet");  
 
  (thestruct->names).push_back("RecoNeutrino");   
  (thestruct->names).push_back("RecoW");   
  (thestruct->names).push_back("RecoTop");   
  (thestruct->names).push_back("RecoZ");   
  

  for(unsigned int i=0;i<(thestruct->names).size();i++)
    {
      TH1F *temp;
      (thestruct->histos).push_back(temp);//pt
      (thestruct->histos).push_back(temp);//eta
      (thestruct->histos).push_back(temp);//phi
      (thestruct->histos).push_back(temp);//M
    }

  for(unsigned int i=0;i<(thestruct->names).size();i++)
    {
      for(unsigned int j=0;j<(thestruct->names).size();j++)
	{
	  if(i<j)//for combined objetcts i and j 
	    {
	      TH1F *temp;
	      (thestruct->combhistos).push_back(temp);//dr
	      (thestruct->combhistos).push_back(temp);//deta
	      (thestruct->combhistos).push_back(temp);//dphi
	      (thestruct->combhistos).push_back(temp);//inv m
	    }
	}
    }

  for(unsigned int i=0; i<(thestruct->names).size();i++)
    {
      string temp=(thestruct->names).at(i);

      (thestruct->histos).at(4*i+0) = InitHist(temp+"Pt",name,10,0,250,color,temp+".Pt (GeV)","Events / 25GeV");
      (thestruct->histos).at(4*i+1) = InitHist(temp+"Eta",name,10,-5,5,color,temp+".Eta","Events");
      (thestruct->histos).at(4*i+2) = InitHist(temp+"Phi",name,10,-4,4,color,temp+".Phi","Events");
      (thestruct->histos).at(4*i+3) = InitHist(temp+"M",name,10,0,100,color,temp+".M (GeV)","Events / 10GeV");
    }

  unsigned int k=0;
  for(unsigned int i=0; i<(thestruct->names).size();i++)
    {

      for(unsigned int j=0; j<(thestruct->names).size();j++)
	
	if(i<j)
	  {
	    string temp=(thestruct->names).at(i);
	    temp=temp+"+";
	    temp=temp+(thestruct->names).at(j);
	   	    
	    (thestruct->combhistos).at(k++) = InitHist("("+temp+")dR",name,10,0,8,color,"("+temp+")dR","Events");
	    (thestruct->combhistos).at(k++) = InitHist("("+temp+")dEta",name,10,-10,10,color,"("+temp+")dEta","Events");
	    (thestruct->combhistos).at(k++) = InitHist("("+temp+")dPhi",name,10,-4,4,color,"("+temp+")dPhi","Events");
	    (thestruct->combhistos).at(k++) = InitHist("("+temp+")invM",name,10,0,800,color,"("+temp+").invM (GeV)","Events / 16GeV");
	  }
    }

  assert(k==(thestruct->combhistos).size());


}

inline void myText(Double_t x,Double_t y,Color_t color, const char *text) {

  //Double_t tsize=0.05;
  TLatex l; //l.SetTextAlign(12); l.SetTextSize(tsize); 
  l.SetNDC();
  l.SetTextColor(color);
  l.DrawLatex(x,y,text);
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

inline void SetStyle() {
  gStyle->SetCanvasColor(0);
  gStyle->SetCanvasBorderMode(0);
  gStyle->SetPadColor(0);
  gStyle->SetPadBorderMode(0);
  gStyle->SetStatColor(0);
  gStyle->SetPalette(1);
  gStyle->SetHistFillColor(5);
  gStyle->SetMarkerStyle(20);
  gStyle->SetMarkerSize(.4);
  gStyle->SetHistLineWidth((Width_t)3.0);
  gStyle->SetErrorX(0);
  gStyle->SetPadTopMargin(0.1);
  gStyle->SetStatY(0.9);
  gStyle->SetPadRightMargin(0.05);
  gStyle->SetStatX(0.95);
  gStyle->SetPadBottomMargin(0.12);
  gStyle->SetPadLeftMargin(0.12);
  gStyle->SetTitleStyle(0);
  gStyle->SetTitleBorderSize(0);
  gStyle->SetTitleX(0.12);
  gStyle->SetTitleY(1.0);
  gStyle->SetTitleH(.1);
  gStyle->SetTitleW(.83);
  gStyle->SetStatBorderSize((Width_t)1.0);
  gStyle->SetLabelSize(.05,"xyz");
  gStyle->SetTitleSize(.05,"xyz");
  gStyle->SetTitleOffset(1.0,"xy");
  gStyle->SetStatW(0.20);
  gStyle->SetStatH(0.15);
  Int_t icol=0; // WHITE
  gStyle->SetFrameBorderMode(icol);
  gStyle->SetFrameFillColor(icol);
  gStyle->SetCanvasBorderMode(icol);
  gStyle->SetCanvasColor(icol);
  gStyle->SetPadBorderMode(icol);
  gStyle->SetPadColor(icol);
  gStyle->SetStatColor(icol);
  gStyle->SetPaperSize(20,26);
  gStyle->SetPadTopMargin(0.05);
  gStyle->SetPadRightMargin(0.05);
  gStyle->SetPadBottomMargin(0.16);
  gStyle->SetPadLeftMargin(0.16);
  // set title offsets (for axis label)
  gStyle->SetTitleXOffset(1.4);
  gStyle->SetTitleYOffset(1.4);
  // use large fonts
  //Int_t font=72; // Helvetica italics
  Int_t font=42; // Helvetica
  Double_t tsize=0.05;
  gStyle->SetTextFont(font);
  gStyle->SetTextSize(tsize);
  gStyle->SetLabelFont(font,"x");
  gStyle->SetTitleFont(font,"x");
  gStyle->SetLabelFont(font,"y");
  gStyle->SetTitleFont(font,"y");
  gStyle->SetLabelFont(font,"z");
  gStyle->SetTitleFont(font,"z");
  gStyle->SetLabelSize(tsize,"x");
  gStyle->SetTitleSize(tsize,"x");
  gStyle->SetLabelSize(tsize,"y");
  gStyle->SetTitleSize(tsize,"y");
  gStyle->SetLabelSize(tsize,"z");
  gStyle->SetTitleSize(tsize,"z");
  gStyle->SetMarkerStyle(20);
  gStyle->SetMarkerSize(1.2);
  gStyle->SetHistLineWidth(3);
  gStyle->SetLineWidth(3);
  gStyle->SetLineStyleString(2,"[12 12]"); // postscript dashes
  gStyle->SetEndErrorSize(0.);
  gStyle->SetOptTitle(0);
  gStyle->SetOptStat(1111);
  gStyle->SetOptFit(1111);
  gROOT->ForceStyle();
}
