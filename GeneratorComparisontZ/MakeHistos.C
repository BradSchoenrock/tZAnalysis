#include "TH2.h"
#include "TH1.h"
#include "TCanvas.h"
#include "TLegend.h"
#include "THStack.h"
#include "TStyle.h"
#include "assert.h"
#include <vector>
#include "TFile.h" 
#include <iostream>
using namespace std;

void MakeHistos()
{
  gStyle->SetOptStat(0);

  TFile *fout = new TFile("fout.root","RECREATE");
  
  
  
  TFile *rootfile1=new TFile("/home/schoenr1/work/GeneratorComparisontZ/madgraph/histos-DucMad.root");
  TFile *rootfile2=new TFile("/home/schoenr1/work/GeneratorComparisontZ/amcnlo/histos-truth-amcnlo.root");
  //TFile *rootfile3=new TFile("/home/schoenr1/work/GeneratorComparisontZ/FULL/histos-truth-FULL.root");
  TFile *rootfile4=new TFile("/home/schoenr1/work/GeneratorComparisontZ/AF2/histos-truth-AF2.root");
  //TFile *rootfile5=new TFile("/home/schoenr1/work/GeneratorComparisontZ/COMMON/histos-truth-COMMON.root");
  //TFile *rootfile6=new TFile("/home/schoenr1/work/GeneratorComparisontZ/MCFM/histos-MCFM.root");
    
  TCanvas *c1 = new TCanvas("c1","c1",560,720);
  
  c1->cd();

  vector<string> histNameVec;
  
 
  histNameVec.push_back("lepton1PT");
  histNameVec.push_back("lepton2PT");
  histNameVec.push_back("lepton3PT");  
  histNameVec.push_back("lepton1Eta");
  histNameVec.push_back("lepton2Eta");
  histNameVec.push_back("lepton3Eta");

  histNameVec.push_back("zLepton1PT");
  histNameVec.push_back("zLepton2PT");
  histNameVec.push_back("leftoverLeptonPT");

  histNameVec.push_back("LeadJetPT");
  histNameVec.push_back("LeadJetEta");
  histNameVec.push_back("SecondJetPT");
  histNameVec.push_back("SecondJetEta");


  histNameVec.push_back("recoZmass");
  histNameVec.push_back("recoZPT");

  histNameVec.push_back("recovPT");
  histNameVec.push_back("recovEta");
  histNameVec.push_back("recovpz");

  histNameVec.push_back("WTmass");
  histNameVec.push_back("recoWPT");
  histNameVec.push_back("recoWEta");

  histNameVec.push_back("recotopPT");
  histNameVec.push_back("recotopEta");
  histNameVec.push_back("recotopmass");

  histNameVec.push_back("h");
  histNameVec.push_back("ht");
  histNameVec.push_back("sphericity");
  histNameVec.push_back("aplanarity");
  histNameVec.push_back("circularity");
  histNameVec.push_back("centrality");
  histNameVec.push_back("WHel");
  histNameVec.push_back("TopPolHB");
  histNameVec.push_back("TopPolOB");
 
 //histNameVec.push_back("");
  //histNameVec.push_back("");
  
  
  for (unsigned int istack = 0; istack < histNameVec.size(); istack++) 
    {

      vector<double> maxs;
      vector<TH1F> thethifs;
     
      TH1F *thif1 = (TH1F*)rootfile1->Get(histNameVec.at(istack).c_str());
      TH1F *thif2 = (TH1F*)rootfile2->Get(histNameVec.at(istack).c_str());
      //TH1F *thif3 = (TH1F*)rootfile3->Get(histNameVec.at(istack).c_str());
      TH1F *thif4 = (TH1F*)rootfile4->Get(histNameVec.at(istack).c_str());
   

      thif1->SetFillColor(0);
      thif1->SetLineColor(2);
      thif2->SetFillColor(0);
      thif2->SetLineColor(4);
      //thif3->SetFillColor(0);
      //thif3->SetLineColor(6);
      thif4->SetFillColor(0);
      thif4->SetLineColor(8);
     

      thif1->SetStats(kFALSE);
      thif2->SetStats(kFALSE);
      //thif3->SetStats(kFALSE);
      thif4->SetStats(kFALSE);


      if(istack==0 || istack==1)
	{
	  string GeV=" (GeV)";
	  string temp=histNameVec.at(istack).c_str()+GeV;
	  thif1->GetXaxis()->SetTitle(temp.c_str());
	  thif2->GetXaxis()->SetTitle(temp.c_str());
	  //thif3->GetXaxis()->SetTitle(temp.c_str());
	  thif4->GetXaxis()->SetTitle(temp.c_str());
	}
      else
	{
 	  thif1->GetXaxis()->SetTitle(histNameVec.at(istack).c_str());
	  thif2->GetXaxis()->SetTitle(histNameVec.at(istack).c_str());
	  //thif3->GetXaxis()->SetTitle(histNameVec.at(istack).c_str());
	  thif4->GetXaxis()->SetTitle(histNameVec.at(istack).c_str());
	}

         
      thethifs.push_back(*thif1);
      thethifs.push_back(*thif2);
      //thethifs.push_back(*thif3);
      thethifs.push_back(*thif4);
      

      for(unsigned int k=0;k<thethifs.size();k++)
	{
	  if((thethifs.at(k)).Integral()>0)
	    {
	      (thethifs.at(k)).Scale(1.0/(thethifs.at(k)).Integral()); 
	      maxs.push_back((thethifs.at(k)).GetBinContent((thethifs.at(k)).GetMaximumBin()));
	    }
	  else 
	    maxs.push_back(0);
	}
      for(unsigned int a=0;a<maxs.size();a++)
	{
	  bool ismax=true;
	  for(unsigned int b=0;b<maxs.size();b++)
	    {
	      if(maxs.at(b)>maxs.at(a))
		ismax=false;
	    }
	  
	  if(ismax)
	    thethifs.at(a).Draw();
	  
	  for(unsigned int c=0;c<thethifs.size();c++)
	    {
	      if(a!=c)
		thethifs.at(c).Draw("SAME");
	    }
	}
               
      // c1->cd();
      gStyle->SetOptTitle(1);
      string name=histNameVec.at(istack).c_str();
      string cname = "canvas_"+name;
      c1->SetName(cname.c_str());

      TLegend *leg = new TLegend(0.5,0.65,0.85,0.85);
      leg->SetFillColor(0);
      leg->SetLineColor(0);
      leg->SetShadowColor(0);
      leg->AddEntry(thif1, "madgraph", "l");
      leg->AddEntry(thif2,"aMC@NLO" , "l");
      //leg->AddEntry(thif3,"TOP_FULL" , "l");
      leg->AddEntry(thif4,"TOP_AF2" , "l");
      
      leg->SetTextFont(72);
      leg->SetTextSize(0.05);
      

      leg->Draw();
      leg->Draw();
      c1->Update();
      // c1->SetLogy(0);
      c1->Print(Form("%s/%s.root", "./histos",name.c_str()));
      c1->Print(Form("%s/%s.pdf","./histos",name.c_str()));
      c1->Print(Form("%s/%s.png","./histos",name.c_str()));
      fout->cd();
      gStyle->SetOptStat(0);

      c1->Write();


      if(istack==0)
	c1->SaveAs("CombinedHists.pdf(");
      else if(istack==histNameVec.size() - 1)
	c1->SaveAs("CombinedHists.pdf");
      else
	c1->SaveAs("CombinedHists.pdf");
    }

}//void Makehistos


