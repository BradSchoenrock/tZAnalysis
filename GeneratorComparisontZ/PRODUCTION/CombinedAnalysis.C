#include <iostream>
#include <fstream>
#include "TFile.h"
#include "TTree.h"
#include "TLeaf.h"
#include "TH1.h"
#include "TH2.h"
#include "TCanvas.h"
#include "TLorentzVector.h"
#include "TString.h"
#include <cmath>

using namespace std;

bool MySort(TLorentzVector i,TLorentzVector j)
{
  return (i.Pt()>j.Pt());
}

void CombinedAnalysis( TString in="/home/schoenr1/work/GeneratorComparisontZ/PRODUCTION/MC12_8TeV.110491.NTUP_TRUTH.root",TString out="histos-tz-production.root",double crossSection=0.216)
{
  cout<<"in = "<<in<<'\n'<<"out = "<<out<<'\n'<<"crossSection = "<<crossSection<<'\n'<<'\n';
  TFile *rootfile=new TFile(in);

  TTree* TREE=(TTree*)rootfile->Get("CollectionTree");
  //Double_t xbins[26] = {0.0, 0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9, 1.0, 1.1, 1.2, 1.3, 1.37, 1.52, 1.6, 1.7, 1.8, 1.9, 2.0, 2.1, 2.2, 2.3, 2.4, 2.47};
   
  //TH2F *etaPhiLossMap = new TH2F("etaPhiLossMap","etaPhiLossMap",27,xbins,65,-3.2,3.2);
  

  TH1F *testNjets=new TH1F("testNjets","testNjets",10,0,10);

  TH1F *tPT=new TH1F("tPT","t quark PT",100,0,400);
  TH1F *tEta=new TH1F("tEta","t quark Eta",100,-5,5);
  TH1F *tphi=new TH1F("tphi","t quark phi",100,-4,4);

  TH1F *bPT=new TH1F("bPT","b quark PT",100,0,400);
  TH1F *bEta=new TH1F("bEta","b quark Eta",100,-5,5);
  TH1F *bphi=new TH1F("bphi","b quark phi",100,-4,4);

  TH1F *lPT=new TH1F("lPT","lepton PT",100,0,400);
  TH1F *lEta=new TH1F("lEta","lepton Eta",100,-5,5);
  TH1F *lphi=new TH1F("lphi","lepton phi",100,-4,4);

  TH1F *vPT=new TH1F("vPT","neutrino PT",100,0,400);
  TH1F *vEta=new TH1F("vEta","neutrino Eta",100,-5,5);
  TH1F *vphi=new TH1F("vphi","neutrino phi",100,-4,4);

  TH1F *wPT=new TH1F("wPT","W PT",100,0,400);
  TH1F *wEta=new TH1F("wEta","W Eta",100,-5,5);
  TH1F *wphi=new TH1F("wphi","W phi",100,-4,4);

  TH1F *zPT=new TH1F("zPT","Z PT",40,0,400);
  TH1F *zEta=new TH1F("zEta","Z Eta",20,-5,5);
  TH1F *zphi=new TH1F("zphi","Z phi",16,-4,4);

  TH1F *Njets=new TH1F("Njets","Njets",6,0,6);

  TH1F *LeadingJetPT=new TH1F("LeadingJetPT","LeadingJet PT",100,0,400);
  TH1F *LeadingJetEta=new TH1F("LeadingJetEta","LeadingJet Eta",100,-5,5);
  TH1F *LeadingJetphi=new TH1F("LeadingJetphi","LeadingJet phi",100,-4,4);
  TH1F *LeadingJetmass=new TH1F("LeadingJetmass","LeadingJet mass",100,0,50);

  TH1F *SecondJetPT=new TH1F("SecondJetPT","SecondJet PT",100,0,400);
  TH1F *SecondJetEta=new TH1F("SecondJetEta","SecondJet Eta",100,-5,5);
  TH1F *SecondJetphi=new TH1F("SecondJetphi","SecondJet phi",100,-4,4);
  TH1F *SecondJetmass=new TH1F("SecondJetmass","SecondJet mass",100,0,50);

  TH1F *MET_PT=new TH1F("MET_PT","MET PT",100,0,250);
  TH1F *MET_Eta=new TH1F("MET_Eta","MET Eta",100,-5,5);
  TH1F *MET_phi=new TH1F("MET_phi","MET phi",100,-4,4);
  TH1F *MET_pz=new TH1F("MET_pz","MET pz",100,-350,350);

  TH1F *leptonPT=new TH1F("leptonPT","lepton PT",100,0,250);
  TH1F *leptonEta=new TH1F("leptonEta","lepton Eta",100,-5,5);
  TH1F *leptonphi=new TH1F("leptonphi","lepton phi",100,-4,4);
  TH1F *leptonmass=new TH1F("leptonmass","lepton mass",100,0,2);

  TH1F *recoWPT=new TH1F("recoWPT","recoW PT",100,0,400);
  TH1F *recoWEta=new TH1F("recoWEta","recoW Eta",100,-5,5);
  TH1F *recoWphi=new TH1F("recoWphi","recoW phi",100,-4,4);
  TH1F *recoWmass=new TH1F("recoWmass","recoW mass",1000,80,80.8);

  TH1F *recotopPT=new TH1F("recotopPT","recotop PT",100,0,400);
  TH1F *recotopEta=new TH1F("recotopEta","recotop Eta",100,-5,5);
  TH1F *recotopphi=new TH1F("recotopphi","recotop phi",100,-4,4);
  TH1F *recotopmass=new TH1F("recotopmass","recotop mass",2000,140,210);

  int afterNothing=0;
  int afterLeptonCuts=0;
  int afterLeptonIso=0;
  int afterNlep=0;
  int afterChargeReq=0;
  int afterjetQ=0;
  int afterjetIso=0;
  int afterNjets=0;
  int afterMET=0;
  int afterMETPz=0;
  int afterWpt=0;
  int afterWeta=0;
  int afterTopPt=0;
  int afterTopMass=0;

  int totalPassed=0;

  double theweight=1;

  for(int q=0;q<5000;q++)//event loop
    {
      afterNothing++;
      //cout<<'\n'<<"start"<<'\n';
      //if(q%100==0)
	cout<<"event "<<q<<'\n';
      TREE->GetEntry(q);

      TLorentzVector NegMET;
      		   
      TLorentzVector MET;

      TLorentzVector wFourVec;
      TLorentzVector tFourVec;


      vector<TLorentzVector> jet;
      vector<TLorentzVector> lepton;
      vector<int> lcharge;

      bool eventSel=true;//this holds my event selection stuff

      //fill lepton jet and MET four vectors ********

      int nparticles=TREE->GetLeaf("mc_n")->GetValue();
      cout<<"nparticles="<<nparticles<<'\n';
      for(int i=0;i<nparticles;i++)//particle loop fills basic histograms
	{
	  cout<<"i="<<i<<'\n';
	  TLeaf *leaf=(TREE->GetLeaf("mc_pdgId"));
	  cout<<"leaf="<<&leaf<<'\n';
	  cout<<""<<leaf<<'\n';
	  cout<<"stuff="<<leaf->GetValue()<<'\n';
	  
	  int PID=(TREE->GetLeaf("mc_pdgId"))->GetValue();
	  double pt=(TREE->GetLeaf("mc_pt"))->GetValue();
	  double eta=(TREE->GetLeaf("mc_eta"))->GetValue();
	  double phi=(TREE->GetLeaf("mc_phi"))->GetValue();
	  double E=(TREE->GetLeaf("mc_E"))->GetValue();
	  int status=(TREE->GetLeaf("mc_status"))->GetValue();
	  
	  //cout<<"listen"<<'\n';
	  cout<<"PID="<<PID<<'\n';
	  cout<<"pt="<<pt<<'\n';
	  cout<<"eta="<<eta<<'\n';
	  cout<<"phi="<<phi<<'\n';
	  cout<<"E="<<E<<'\n';
	  cout<<"status="<<status<<'\n';


	  if(abs(PID)==11 || abs(PID)==13)
	    {
	      lPT->Fill(pt,theweight);
	      lEta->Fill(eta,theweight);
	      lphi->Fill(phi,theweight);
	      TLorentzVector temp;
	      temp.SetPtEtaPhiE(pt,eta,phi,E);
	      lepton.push_back(temp);
	     
	    }
	  else if(abs(PID)==5 && status==1)
	    {
	      bPT->Fill(pt,theweight);
	      bEta->Fill(eta,theweight);
	      bphi->Fill(phi,theweight);
	    }
	  else if(abs(PID)==6)
	    {
	      tPT->Fill(pt,theweight);
	      tEta->Fill(eta,theweight);
	      tphi->Fill(phi,theweight);
	    }
	  else if(abs(PID)==12)
	    {
	      vPT->Fill(pt,theweight);
	      vEta->Fill(eta,theweight);
	      vphi->Fill(phi,theweight);
	    }
	  else if(abs(PID)==24)
	    {
	      wPT->Fill(pt,theweight);
	      wEta->Fill(eta,theweight);
	      wphi->Fill(phi,theweight);
	    }

	  else if(abs(PID)==23)
	    {
	      zPT->Fill(pt,theweight);
	      zEta->Fill(eta,theweight);
	      zphi->Fill(phi,theweight);
	      //cout<<pt<<'\n';
	    }


	  if(status==1)
	    {
	      if(PID==9 || PID==21 || (PID<=6 && PID>=-6 && PID!=0))
		{
		  TLorentzVector temp;
		  temp.SetPtEtaPhiE(pt,eta,phi,E);
		  jet.push_back(temp);
		 
		  //cout<<PID<<"filling jet["<<njets<<"].Pt="<<jet[njets].Pt()<<'\n';
		}
	    }

	}


      //for(int i=0;i<el_n;i++)
      //	{}

      //for(int i=0;i<mu_n;i++)
      //	{}
      
      //double MetPhi=atan(MET_Truth_Int_ety/MET_Truth_Int_etx);
      //double MetPt=sqrt(MET_Truth_Int_ety*MET_Truth_Int_ety+MET_Truth_Int_etx*MET_Truth_Int_etx);

      //MET->SetPtEtaPhiM(MetPt,0,MetPhi,0);


      testNjets->Fill(jet.size());


      for(unsigned int c=0;c<lepton.size();c++)
	{
	  if(lepton.size()>0 && (fabs((lepton.at(c)).Eta())>2.5 || ((lepton.at(c)).Pt())<25))//lepton cuts
	    {
	      vector<TLorentzVector>::iterator Iter;
	      Iter=lepton.begin()+c;
	      lepton.erase(Iter);
	      vector<int>::iterator It;
	      It=lcharge.begin()+c;
	      lcharge.erase(It);
	      c--;
	    }
	}

      if(lepton.size()==0)
	eventSel=false;

      if(eventSel)
	afterLeptonCuts++;
      
      if(eventSel)
	{
	  for(unsigned int j=0;j<lepton.size();j++)
	    {
	      if(lepton.size()>0)
		{
		  for(unsigned int i=0;i<jet.size();i++)//checking lepton vs jet isolation
		    {
		      if(jet.size()>0)
			{
			  double dR=(lepton.at(j)).DeltaR(jet.at(i));
			  if(dR<0.2)
			    {
			      vector<TLorentzVector>::iterator Iter;
			      Iter=lepton.begin()+j;
			      lepton.erase(Iter);
			      vector<int>::iterator It;
			      It=lcharge.begin()+j;
			      lcharge.erase(It);
			      j--;
			      i=jet.size();
			    }
			}
		    }
		}
	    }
	}

      if(lepton.size()==0)
	eventSel=false;

      if(eventSel)
	afterLeptonIso++;

      if(lepton.size()!=1)
	eventSel=false;
      	    
      if(eventSel)
       	  afterNlep++;

      if(eventSel)
	{
	  if(lcharge.size()!=1)
	    cout<<"Hey Listen!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"<<'\n';
	  if(lcharge.at(0)!=1)
	    eventSel=false;
	}
	
      if(eventSel)
	afterChargeReq++;

      if(eventSel)
	{
	  //cout<<"passed lepton and neutrino_ requirements!"<<'\n';
	  
	  sort(jet.begin(),jet.end(),MySort);
	  
	  for(unsigned int c=0;c<jet.size()-1;c++)//checking jet isolation requirements
	    {
	      for(unsigned int d=0;d<jet.size();d++)
		{
		  if(c<d)
		    {
		      double dR=(jet.at(c)).DeltaR(jet.at(d));
		      
		      if(dR<0.4)
			{
			  TLorentzVector tempjet=jet.at(c);
			  jet.at(c)=tempjet+jet.at(d);
			  vector<TLorentzVector>::iterator Iter;
			  Iter=jet.begin()+d;
			  //cout<<"dr works Iter="<<Iter<<'\n';
			  jet.erase(Iter);
			  
			  sort(jet.begin(),jet.end(),MySort);
			  d=jet.size();//these two lines ensure we restart the c and d loops 
			  c=-1;//note: c is -1 so at the end of the loop it gets incremented to 0
			}
		    }
		}
	    }
	}

      if(jet.size()==0)
	eventSel=false;

      if(eventSel)
	afterjetIso++;

      if(eventSel)
	{	  
	  for(unsigned int w=0;w<jet.size();w++)
	    {
	      if(jet.size()>0 && ((jet.at(w)).Pt()<25 || fabs((jet.at(w)).Eta())>4.5) )//checking jet quality 
		{
		  vector<TLorentzVector>::iterator Iter;
		  Iter=jet.begin()+w;
		  jet.erase(Iter);
		  if(w!=jet.size())//rechecks the position we are at so that we don't let a bad jet slip through, 
		    w--;//unless we just deleted the last element, then we can stop
		}
	    }//after this point jets only has "good" jets
	}

      if(jet.size()==0)
	eventSel=false;
     
      if(eventSel)
	afterjetQ++;
      
      if(jet.size()<2)
	eventSel=false;
      
      if(eventSel)
	afterNjets++;
	       
     

      //fill met four vectors here ******

	  if(NegMET.Pt()<25)
	    {
	      eventSel=false;
	      //cout<<"failed neutrino_ cut: neutrino_="<<NegMET.Pt()<<'\n';
	    }
	
      
      if(eventSel)
	afterMET++;
                  
      if(eventSel)
	{
	  //now we will reconstruct things
	  //TLorentzVector wFourVec=lepton+NegMET; 
	  double DPHI=(lepton.at(0)).Phi()-NegMET.Phi();
	  if(fabs(DPHI)>3.14) DPHI = DPHI - 2*3.14;
	  double mu=0.5*80.4*80.4-cos(DPHI)*(lepton.at(0)).Pt()*NegMET.Pt();
	  double temp1=mu*(lepton.at(0)).Pz()/((lepton.at(0)).Pt()*(lepton.at(0)).Pt());
	  double temp2=mu*mu*(lepton.at(0)).Pz()*(lepton.at(0)).Pz()/pow((lepton.at(0)).Pt(),4) - ((lepton.at(0)).E()*(lepton.at(0)).E() * NegMET.Pt()*NegMET.Pt() -mu*mu )/((lepton.at(0)).Pt()*(lepton.at(0)).Pt());
	  double METPz=0;
	  
	  if(temp2>0)
	    {
	      if(fabs(temp1+sqrt(temp2)) > fabs(temp1-sqrt(temp2)))
		METPz=temp1-sqrt(temp2);
	      else 
		METPz=temp1+sqrt(temp2);
	    }
	  else
	    {
	      METPz=temp1;
	    }
	  
	  double METPx=-1*NegMET.Px();
	  double METPy=-1*NegMET.Py();
	  double METenergy=sqrt(METPx*METPx+METPy*METPy+METPz*METPz);
	  
  	  MET.SetPxPyPzE(METPx,METPy,METPz,METenergy);
	  
	  wFourVec=(lepton.at(0))+MET;
	  
	  //reconstructing the top quark
	  
	  tFourVec=wFourVec+jet.at(0);


	  //reco cuts

	  bool goodevent=true;
	  
	  if(fabs(METPz)>150)
	    goodevent=false;
	  
	  if(goodevent)
	    afterMETPz++;

	  if(goodevent)
	    {
	      if(fabs(wFourVec.Pt())>250)
		goodevent=false;
	    }
	  
	  if(goodevent)
	    afterWpt++;

	  if(goodevent)
	    {
	      if(fabs(wFourVec.Eta())>4)
		goodevent=false;
	    }

	  if(goodevent)
	    afterWeta++;

	  if(goodevent)
	    {
	      if(tFourVec.Pt()>250)
		goodevent=false;
	    }
	  
	  if(goodevent)
	    afterTopPt++;
	  
	  
	  if(goodevent)
	    {
	      if(fabs(tFourVec.M()-175.0)>25.0)
		goodevent=false;
	    }
	  if(goodevent)
	    afterTopMass++;



	  if(goodevent)
	    {
	      
	      //now we have done jet recombination and are sorted making a plot of Njets
	      Njets->Fill(jet.size());
	      
	      //making plots of leading and subleading jet
	      
	      LeadingJetPT->Fill((jet.at(0)).Pt());
	      LeadingJetEta->Fill((jet.at(0)).Eta());
	      LeadingJetphi->Fill((jet.at(0)).Phi());
	      LeadingJetmass->Fill((jet.at(0)).M());
	      
	      SecondJetPT->Fill((jet.at(1)).Pt());
	      SecondJetEta->Fill((jet.at(1)).Eta());
	      SecondJetphi->Fill((jet.at(1)).Phi());
	      SecondJetmass->Fill((jet.at(1)).M());
	      
	      //making plots for lepton
	      leptonPT->Fill((lepton.at(0)).Pt());
	      leptonEta->Fill((lepton.at(0)).Eta());
	      leptonphi->Fill((lepton.at(0)).Phi());
	      leptonmass->Fill((lepton.at(0)).M());
	      
	      MET_PT->Fill(MET.Pt());
	      MET_Eta->Fill(MET.Eta());
	      MET_phi->Fill(MET.Phi());
	      MET_pz->Fill(METPz);
	      
	      //filling plots for recontructed W
	      recoWPT->Fill(wFourVec.Pt());
	      recoWEta->Fill(wFourVec.Eta());
	      recoWphi->Fill(wFourVec.Phi());
	      recoWmass->Fill(wFourVec.M());
	      
	      recotopPT->Fill(tFourVec.Pt());
	      recotopEta->Fill(tFourVec.Eta());
	      recotopphi->Fill(tFourVec.Phi());
	      recotopmass->Fill(tFourVec.M());
	      
	      totalPassed++;
	    }
	  //cout<<"end"<<'\n';
	}
    }
  
  cout<<"afterNothing="<<afterNothing<<'\n';
  cout<<"afterLeptonCuts="<<afterLeptonCuts<<'\n';
  cout<<"afterLeptonIso="<<afterLeptonIso<<'\n';
  cout<<"afterNlep="<<afterNlep<<'\n';
  cout<<"afterChargeReq="<<afterChargeReq<<'\n';
  cout<<"afterJetIso="<<afterjetIso<<'\n';
  cout<<"afterJetQ="<<afterjetQ<<'\n';
  cout<<"afterNjets="<<afterNjets<<'\n';
  cout<<"afterMET="<<afterMET<<'\n';
  cout<<"afterMETPz="<<afterMETPz<<'\n';
  cout<<"afterWpt="<<afterWpt<<'\n';
  cout<<"afterWeta="<<afterWeta<<'\n';
  cout<<"afterTopPt="<<afterTopPt<<'\n';
  cout<<"afterTopMass="<<afterTopMass<<'\n';

  cout<<"totalPassed="<<totalPassed<<'\n';

  ofstream comboResults;
  comboResults.open ("/msu/data/t3work5/schoenr1/Madgraph/comboResults.txt", ios::out | ios::app); 

  comboResults<<out<<'\n'<<"afterNothing="<<afterNothing<<'\n'<<"afterLeptonCuts="<<afterLeptonCuts<<'\n'<<"afterLeptonIso="<<afterLeptonIso<<'\n'<<"afterNlep="<<afterNlep<<'\n'<<"afterChargeReq="<<afterChargeReq<<'\n'<<"afterJetIso="<<afterjetIso<<'\n'<<"afterJetQ="<<afterjetQ<<'\n'<<"afterNjets"<<afterNjets<<'\n'<<"afterMET="<<afterMET<<'\n'<<"afterMETPz="<<afterMETPz<<'\n'<<"afterWpt="<<afterWpt<<'\n'<<"afterWeta="<<afterWeta<<'\n'<<"afterTopPt="<<afterTopPt<<'\n'<<"afterTopMass="<<afterTopMass<<'\n'<<"totalPassed="<<totalPassed<<'\n'<<'\n'<<'\n'<<'\n';

  if(totalPassed>0)
    {
   
      testNjets->Draw();

      tPT->Scale(crossSection/afterNothing);
      tPT->Draw();
      tEta->Scale(crossSection/afterNothing);
      tEta->Draw();
      tphi->Scale(crossSection/afterNothing);
      tphi->Draw();
      
      bPT->Scale(crossSection/afterNothing);
      bPT->Draw();
      bEta->Scale(crossSection/afterNothing);
      bEta->Draw();
      bphi->Scale(crossSection/afterNothing);
      bphi->Draw();
      
      lPT->Scale(crossSection/afterNothing);
      lPT->Draw();
      lEta->Scale(crossSection/afterNothing);
      lEta->Draw();
      lphi->Scale(crossSection/afterNothing);
      lphi->Draw();
      
      vPT->Scale(crossSection/afterNothing);
      vPT->Draw();
      vEta->Scale(crossSection/afterNothing);
      vEta->Draw();
      vphi->Scale(crossSection/afterNothing);
      vphi->Draw();
      
      wPT->Scale(crossSection/afterNothing);
      wPT->Draw();
      wEta->Scale(crossSection/afterNothing);
      wEta->Draw();
      wphi->Scale(crossSection/afterNothing);
      wphi->Draw();
      
      Njets->Draw();
      
      LeadingJetPT->Scale(crossSection/afterNothing);
      LeadingJetPT->Draw();
      LeadingJetEta->Scale(crossSection/afterNothing);
      LeadingJetEta->Draw();
      LeadingJetphi->Scale(crossSection/afterNothing);
      LeadingJetphi->Draw();
      LeadingJetmass->Scale(crossSection/afterNothing);
      LeadingJetmass->Draw();
      
      SecondJetPT->Scale(crossSection/afterNothing);
      SecondJetPT->Draw();
      SecondJetEta->Scale(crossSection/afterNothing);
      SecondJetEta->Draw();
      SecondJetphi->Scale(crossSection/afterNothing);
      SecondJetphi->Draw();
      SecondJetmass->Scale(crossSection/afterNothing);
      SecondJetmass->Draw();
            
      MET_PT->Scale(crossSection/afterNothing);
      MET_PT->Draw();
      MET_Eta->Scale(crossSection/afterNothing);
      MET_Eta->Draw();
      MET_phi->Scale(crossSection/afterNothing);
      MET_phi->Draw();
      MET_pz->Scale(crossSection/afterNothing);
      MET_pz->Draw();
      
      leptonPT->Scale(crossSection/afterNothing);
      leptonPT->Draw();
      leptonEta->Scale(crossSection/afterNothing);
      leptonEta->Draw();
      leptonphi->Scale(crossSection/afterNothing);
      leptonphi->Draw();
      leptonmass->Scale(crossSection/afterNothing);
      leptonmass->Draw();
      
      recoWPT->Scale(crossSection/afterNothing);
      recoWPT->Draw();
      recoWEta->Scale(crossSection/afterNothing);
      recoWEta->Draw();
      recoWphi->Scale(crossSection/afterNothing);
      recoWphi->Draw();
      recoWmass->Scale(crossSection/afterNothing);
      recoWmass->Draw();
      
      recotopPT->Scale(crossSection/afterNothing);
      recotopPT->Draw();
      recotopEta->Scale(crossSection/afterNothing);
      recotopEta->Draw();
      recotopphi->Scale(crossSection/afterNothing);
      recotopphi->Draw();
      recotopmass->Scale(crossSection/afterNothing);
      recotopmass->Draw();
    }

  TFile outfile(out,"recreate");
  
  tPT->Write();
  tEta->Write();
  tphi->Write();
  
  bPT->Write();
  bEta->Write();
  bphi->Write();
  
  lPT->Write();
  lEta->Write();
  lphi->Write();
  
  vPT->Write();
  vEta->Write();
  vphi->Write();
  
  wPT->Write();
  wEta->Write();
  wphi->Write();
  
  Njets->Write();

  testNjets->Write();
  
  LeadingJetPT->Write();
  LeadingJetEta->Write();
  LeadingJetphi->Write();
  LeadingJetmass->Write();
  
  SecondJetPT->Write();
  SecondJetEta->Write();
  SecondJetphi->Write();
  SecondJetmass->Write();
  
  MET_PT->Write();
  MET_Eta->Write();
  MET_phi->Write();
  MET_pz->Write();
  
  leptonPT->Write();
  leptonEta->Write();
  leptonphi->Write();
  leptonmass->Write();
  
  recoWPT->Write();
  recoWEta->Write();
  recoWphi->Write();
  recoWmass->Write();
  
  recotopPT->Write();
  recotopEta->Write();
  recotopphi->Write();
  recotopmass->Write();
  
  outfile.Write();
    
  cout<<'\n'<<'\n'<<'\n';
}



