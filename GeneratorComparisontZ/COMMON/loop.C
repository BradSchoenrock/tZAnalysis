
#include "TZ_COMMON.C"
#include <iostream>
#include <fstream> 
//#include "TROOT.h"
#include "TFile.h"
#include "TTree.h"
#include "TLeaf.h"
#include "TH1.h"
#include "TH2.h"
#include "TCanvas.h"
#include "assert.h"
#include "TLorentzVector.h"
#include "TString.h"
#include "Wvariables.cxx"
#include "TopPolarization.C"
#include "AngularVariables.C"
#include "THStack.h"
#include "TStyle.h"
#include "TLegend.h"
#include <vector>
using namespace std;

void loop()
{
  
  TH1F *testNjets=new TH1F("testNjets","testNjets",10,0,10);
  TH1F *testNlep=new TH1F("testNlep","testNlep",10,0,10);
  TH1F *testNelec=new TH1F("testNelec","testNelec",10,0,10);
  
  TH1F *tPT=new TH1F("tPT","t quark PT",40,0,400);
  TH1F *tEta=new TH1F("tEta","t quark Eta",20,-5,5);
  TH1F *tphi=new TH1F("tphi","t quark phi",16,-4,4);
  
  TH1F *bPT=new TH1F("bPT","b quark PT",40,0,400);
  TH1F *bEta=new TH1F("bEta","b quark Eta",20,-5,5);
  TH1F *bphi=new TH1F("bphi","b quark phi",16,-4,4);
  
  TH1F *lPT=new TH1F("lPT","lepton PT",40,0,400);
  TH1F *lEta=new TH1F("lEta","lepton Eta",20,-5,5);
  TH1F *lphi=new TH1F("lphi","lepton phi",16,-4,4);
  
  TH1F *vPT=new TH1F("vPT","neutrino PT",40,0,400);
  TH1F *vEta=new TH1F("vEta","neutrino Eta",20,-5,5);
  TH1F *vphi=new TH1F("vphi","neutrino phi",16,-4,4);
  
  TH1F *wPT=new TH1F("wPT","W PT",40,0,400);
  TH1F *wEta=new TH1F("wEta","W Eta",20,-5,5);
  TH1F *wphi=new TH1F("wphi","W phi",16,-4,4);
  
  TH1F *zPT=new TH1F("zPT","Z PT",40,0,400);
  TH1F *zEta=new TH1F("zEta","Z Eta",20,-5,5);
  TH1F *zphi=new TH1F("zphi","Z phi",16,-4,4);
  
  TH1F *BJetPT=new TH1F("BJetPT","BJet PT",40,0,400);
  TH1F *BJetEta=new TH1F("BJetEta","BJet Eta",20,-5,5);
  TH1F *BJetphi=new TH1F("BJetphi","BJet phi",16,-4,4);
  TH1F *BJetmass=new TH1F("BJetmass","BJet mass",100,0,50);
  
  TH1F *nonBJetPT=new TH1F("nonBJetPT","nonBJet PT",40,0,400);
  TH1F *nonBJetEta=new TH1F("nonBJetEta","nonBJet Eta",20,-5,5);
  TH1F *nonBJetphi=new TH1F("nonBJetphi","nonBJet phi",16,-4,4);
  TH1F *nonBJetmass=new TH1F("nonBJetmass","nonBJet mass",100,0,50);
  
  TH1F *MET_PT=new TH1F("recovPT","MET PT",25,0,250);
  TH1F *MET_Eta=new TH1F("recovEta","MET Eta",20,-5,5);
  TH1F *MET_phi=new TH1F("recovphi","MET phi",16,-4,4);
  TH1F *MET_pz=new TH1F("recovpz","MET pz",100,-350,350);
  
  TH1F *lepton1PT=new TH1F("lepton1PT","lepton1 PT",25,0,250);
  TH1F *lepton1Eta=new TH1F("lepton1Eta","lepton1 Eta",20,-5,5);
  TH1F *lepton1phi=new TH1F("lepton1phi","lepton1 phi",16,-4,4);
  TH1F *lepton1mass=new TH1F("lepton1mass","lepton1 mass",100,0,2);
  
  TH1F *recoWPT=new TH1F("recoWPT","recoW PT",40,0,400);
  TH1F *recoWEta=new TH1F("recoWEta","recoW Eta",20,-5,5);
  TH1F *recoWphi=new TH1F("recoWphi","recoW phi",16,-4,4);
  TH1F *recoWmass=new TH1F("recoWmass","recoW mass",1000,80,80.8);

  TH1F *recotopPT=new TH1F("recotopPT","recotop PT",40,0,400);
  TH1F *recotopEta=new TH1F("recotopEta","recotop Eta",20,-5,5);
  TH1F *recotopphi=new TH1F("recotopphi","recotop phi",16,-4,4);
  TH1F *recotopmass=new TH1F("recotopmass","recotop mass",10,140,210);

  TH1F *recoZPT=new TH1F("recoZPT","recoZ PT",40,0,400);
  TH1F *recoZEta=new TH1F("recoZEta","recoZ Eta",20,-5,5);
  TH1F *recoZphi=new TH1F("recoZphi","recoZ phi",16,-4,4);
  TH1F *recoZmass=new TH1F("recoZmass","recoZ mass",1000,0,200);

  TH1F *lepton2PT=new TH1F("lepton2PT","lepton2 PT",25,0,250);
  TH1F *lepton2Eta=new TH1F("lepton2Eta","lepton2 Eta",20,-5,5);
  TH1F *lepton2phi=new TH1F("lepton2phi","lepton2 phi",16,-4,4);
  TH1F *lepton2mass=new TH1F("lepton2mass","lepton2 mass",100,0,2);

  TH1F *lepton3PT=new TH1F("lepton3PT","lepton3 PT",25,0,250);
  TH1F *lepton3Eta=new TH1F("lepton3Eta","lepton3 Eta",20,-5,5);
  TH1F *lepton3phi=new TH1F("lepton3phi","lepton3 phi",16,-4,4);
  TH1F *lepton3mass=new TH1F("lepton3mass","lepton3 mass",100,0,2);

  TH1F *leftoverLeptonPT=new TH1F("leftoverLeptonPT","leftoverLepton PT",25,0,250);
  TH1F *leftoverLeptonEta=new TH1F("leftoverLeptonEta","leftoverLepton Eta",20,-5,5);
  TH1F *leftoverLeptonphi=new TH1F("leftoverLeptonphi","leftoverLepton phi",16,-4,4);
  TH1F *leftoverLeptonmass=new TH1F("leftoverLeptonmass","leftoverLepton mass",100,0,2);

  TH1F *zLeptonPT=new TH1F("zLeptonPT","zLepton PT",25,0,250);
  TH1F *zLeptonEta=new TH1F("zLeptonEta","zLepton Eta",20,-5,5);
  TH1F *zLeptonphi=new TH1F("zLeptonphi","zLepton phi",16,-4,4);
  TH1F *zLeptonmass=new TH1F("zLeptonmass","zLepton mass",100,0,2);

  TH1F *zAntiLeptonPT=new TH1F("zAntiLeptonPT","zAntiLepton PT",25,0,250);
  TH1F *zAntiLeptonEta=new TH1F("zAntiLeptonEta","zAntiLepton Eta",20,-5,5);
  TH1F *zAntiLeptonphi=new TH1F("zAntiLeptonphi","zAntiLepton phi",16,-4,4);
  TH1F *zAntiLeptonmass=new TH1F("zAntiLeptonmass","zAntiLepton mass",100,0,2);

  TH1F *WTmass=new TH1F("WTmass","WTransversemass",25,0,250);
  TH1F *TopPolHB=new TH1F("TopPolHB","TopPolarizationHelicityBasis",10,-1,1);
  TH1F *TopPolOB=new TH1F("TopPolOB","TopPolarizationOptimalBasis",10,-1,1);
  TH1F *centralityhist=new TH1F("centrality","centrality",10,0,1);
  TH1F *sphericityhist=new TH1F("sphericity","sphericity",20,0,1);
  TH1F *aplanarityhist=new TH1F("aplanarity","aplanarity",20,0,1);
  TH1F *circularityhist=new TH1F("circularity","circularity",20,0,1);
  TH1F *WHel=new TH1F("WHel","WHelicity",10,-1,1);
  TH1F *h_hist=new TH1F("h","h",30,0,3000);
  TH1F *ht_hist=new TH1F("ht","ht",20,0,1000);




  double afterNlep=0;
  double afterjetQ=0;
  double afterMET=0;
  double totalPassed=0;
  double afterNothing=0;





  int nEvents=100;
  double Lumi=20.3;
  double crossSection=1.652;
  double theweight=1000*Lumi*crossSection/nEvents;

  TChain * t = new TChain("physics");
  t->Add("/home/schoenr1/rootFiles/tz/COMMON/mc12_8TeV.179992.MadGraphPythia_AUET2B_CTEQ6L1_tZ_stchan_Zll_PythiaDecays.merge.NTUP_COMMON.e2241_a188_a205_r4540_p1575_tid01356314_00/NTUP_COMMON.01356314._000001.root.1"); 
  t->Add("/home/schoenr1/rootFiles/tz/COMMON/mc12_8TeV.179992.MadGraphPythia_AUET2B_CTEQ6L1_tZ_stchan_Zll_PythiaDecays.merge.NTUP_COMMON.e2241_a188_a205_r4540_p1575_tid01356314_00/NTUP_COMMON.01356314._000002.root.1"); 
  t->Add("/home/schoenr1/rootFiles/tz/COMMON/mc12_8TeV.179992.MadGraphPythia_AUET2B_CTEQ6L1_tZ_stchan_Zll_PythiaDecays.merge.NTUP_COMMON.e2241_a188_a205_r4540_p1575_tid01356314_00/NTUP_COMMON.01356314._000003.root.1"); 
  t->Add("/home/schoenr1/rootFiles/tz/COMMON/mc12_8TeV.179992.MadGraphPythia_AUET2B_CTEQ6L1_tZ_stchan_Zll_PythiaDecays.merge.NTUP_COMMON.e2241_a188_a205_r4540_p1575_tid01356314_00/NTUP_COMMON.01356314._000004.root.1"); 
  t->Add("/home/schoenr1/rootFiles/tz/COMMON/mc12_8TeV.179992.MadGraphPythia_AUET2B_CTEQ6L1_tZ_stchan_Zll_PythiaDecays.merge.NTUP_COMMON.e2241_a188_a205_r4540_p1575_tid01356314_00/NTUP_COMMON.01356314._000005.root.1"); 
  t->Add("/home/schoenr1/rootFiles/tz/COMMON/mc12_8TeV.179992.MadGraphPythia_AUET2B_CTEQ6L1_tZ_stchan_Zll_PythiaDecays.merge.NTUP_COMMON.e2241_a188_a205_r4540_p1575_tid01356314_00/NTUP_COMMON.01356314._000006.root.1"); 
  t->Add("/home/schoenr1/rootFiles/tz/COMMON/mc12_8TeV.179992.MadGraphPythia_AUET2B_CTEQ6L1_tZ_stchan_Zll_PythiaDecays.merge.NTUP_COMMON.e2241_a188_a205_r4540_p1575_tid01356314_00/NTUP_COMMON.01356314._000007.root.1"); 
  t->Add("/home/schoenr1/rootFiles/tz/COMMON/mc12_8TeV.179992.MadGraphPythia_AUET2B_CTEQ6L1_tZ_stchan_Zll_PythiaDecays.merge.NTUP_COMMON.e2241_a188_a205_r4540_p1575_tid01356314_00/NTUP_COMMON.01356314._000008.root.1"); 
  t->Add("/home/schoenr1/rootFiles/tz/COMMON/mc12_8TeV.179992.MadGraphPythia_AUET2B_CTEQ6L1_tZ_stchan_Zll_PythiaDecays.merge.NTUP_COMMON.e2241_a188_a205_r4540_p1575_tid01356314_00/NTUP_COMMON.01356314._000009.root.1"); 
  t->Add("/home/schoenr1/rootFiles/tz/COMMON/mc12_8TeV.179992.MadGraphPythia_AUET2B_CTEQ6L1_tZ_stchan_Zll_PythiaDecays.merge.NTUP_COMMON.e2241_a188_a205_r4540_p1575_tid01356314_00/NTUP_COMMON.01356314._000010.root.1"); 
  t->Add("/home/schoenr1/rootFiles/tz/COMMON/mc12_8TeV.179992.MadGraphPythia_AUET2B_CTEQ6L1_tZ_stchan_Zll_PythiaDecays.merge.NTUP_COMMON.e2241_a188_a205_r4540_p1575_tid01356314_00/NTUP_COMMON.01356314._000011.root.1"); 
  t->Add("/home/schoenr1/rootFiles/tz/COMMON/mc12_8TeV.179992.MadGraphPythia_AUET2B_CTEQ6L1_tZ_stchan_Zll_PythiaDecays.merge.NTUP_COMMON.e2241_a188_a205_r4540_p1575_tid01356314_00/NTUP_COMMON.01356314._000012.root.1"); 
  t->Add("/home/schoenr1/rootFiles/tz/COMMON/mc12_8TeV.179992.MadGraphPythia_AUET2B_CTEQ6L1_tZ_stchan_Zll_PythiaDecays.merge.NTUP_COMMON.e2241_a188_a205_r4540_p1575_tid01356314_00/NTUP_COMMON.01356314._000013.root.1"); 
  t->Add("/home/schoenr1/rootFiles/tz/COMMON/mc12_8TeV.179992.MadGraphPythia_AUET2B_CTEQ6L1_tZ_stchan_Zll_PythiaDecays.merge.NTUP_COMMON.e2241_a188_a205_r4540_p1575_tid01356314_00/NTUP_COMMON.01356314._000014.root.1"); 
  t->Add("/home/schoenr1/rootFiles/tz/COMMON/mc12_8TeV.179992.MadGraphPythia_AUET2B_CTEQ6L1_tZ_stchan_Zll_PythiaDecays.merge.NTUP_COMMON.e2241_a188_a205_r4540_p1575_tid01356314_00/NTUP_COMMON.01356314._000015.root.1"); 
  t->Add("/home/schoenr1/rootFiles/tz/COMMON/mc12_8TeV.179992.MadGraphPythia_AUET2B_CTEQ6L1_tZ_stchan_Zll_PythiaDecays.merge.NTUP_COMMON.e2241_a188_a205_r4540_p1575_tid01356314_00/NTUP_COMMON.01356314._000016.root.1"); 
  t->Add("/home/schoenr1/rootFiles/tz/COMMON/mc12_8TeV.179992.MadGraphPythia_AUET2B_CTEQ6L1_tZ_stchan_Zll_PythiaDecays.merge.NTUP_COMMON.e2241_a188_a205_r4540_p1575_tid01356314_00/NTUP_COMMON.01356314._000017.root.1"); 
  t->Add("/home/schoenr1/rootFiles/tz/COMMON/mc12_8TeV.179992.MadGraphPythia_AUET2B_CTEQ6L1_tZ_stchan_Zll_PythiaDecays.merge.NTUP_COMMON.e2241_a188_a205_r4540_p1575_tid01356314_00/NTUP_COMMON.01356314._000018.root.1"); 
  t->Add("/home/schoenr1/rootFiles/tz/COMMON/mc12_8TeV.179992.MadGraphPythia_AUET2B_CTEQ6L1_tZ_stchan_Zll_PythiaDecays.merge.NTUP_COMMON.e2241_a188_a205_r4540_p1575_tid01356314_00/NTUP_COMMON.01356314._000019.root.1"); 
  t->Add("/home/schoenr1/rootFiles/tz/COMMON/mc12_8TeV.179992.MadGraphPythia_AUET2B_CTEQ6L1_tZ_stchan_Zll_PythiaDecays.merge.NTUP_COMMON.e2241_a188_a205_r4540_p1575_tid01356314_00/NTUP_COMMON.01356314._000020.root.1"); 

 
  
  t->SetCacheSize(100000000);
  TZ_COMMON* event = new TZ_COMMON(t);
  

  //TFile *TruthFile=new TFile("unweighted_events.root");
  
  //TTree* LHEF=(TTree*)TruthFile->Get("LHEF");
  
  for(int q=0;q<nEvents;q++)
    {
      afterNothing+=theweight;
      
      t->GetEntry(q);
      
      //int nparticles = *event->(Event_Nparticles);
      //int nparticles = *event->Event_Nparticles();
      
      
      if(q%1000==0)
	cout<<q<<'\n';

      //cout<<"q="<<q<<'\n'<<"nparticles="<<nparticles<<'\n';


      TLorentzVector NegMET;
      TLorentzVector MET;
      TLorentzVector wFourVec;
      TLorentzVector zFourVec;
      TLorentzVector tFourVec;

      zFourVec.SetPtEtaPhiM(0,0,0,0);
      wFourVec.SetPtEtaPhiM(0,0,0,0);
      tFourVec.SetPtEtaPhiM(0,0,0,0);
      MET.SetPtEtaPhiM(0,0,0,0);


      vector<TLorentzVector> jet;
      //vector<bool> isb;
      vector<TLorentzVector> lepton;
      //vector<int> lcharge;
      vector<int> ltype;
      //vector<int> isZ;
      //int nelec=0;
 
      bool eventSel=true;//this holds my event selection stuff
     
      for(int i=0;i<event->AntiKt4Truth_n;i++)
	{
	  TLorentzVector temp;
	  temp.SetPtEtaPhiE((*event->AntiKt4Truth_pt).at(i),(*event->AntiKt4Truth_eta).at(i),(*event->AntiKt4Truth_phi).at(i),(*event->AntiKt4Truth_E).at(i));
	  jet.push_back(temp);
	}
      
      for(unsigned int i=0;i<(*event->el_truth_E).size();i++)
	{
	  TLorentzVector temp;
	  temp.SetPtEtaPhiE((*event->el_truth_pt).at(i),(*event->el_truth_eta).at(i),(*event->el_truth_phi).at(i),(*event->el_truth_E).at(i));
	  lepton.push_back(temp);
	  ltype.push_back(1);
	}

      for(unsigned int i=0;i<(*event->mu_truth_E).size();i++)
	{
	  TLorentzVector temp;
	  temp.SetPtEtaPhiE((*event->mu_truth_pt).at(i),(*event->mu_truth_eta).at(i),(*event->mu_truth_phi).at(i),(*event->mu_truth_E).at(i));
	  lepton.push_back(temp);
	  ltype.push_back(2);
	}

    
      cout<<"hey"<<'\n';
      
      for(unsigned int c=0;c<lepton.size();c++)
	{
	  cout<<c<<'\n';
	  cout<<lepton.size()<<'\n';
	  cout<<lepton.at(c).Eta()<<'\n';
	  cout<<lepton.at(c).Pt()<<'\n';
	  if(lepton.size()>0)
	    if( (lepton.at(c)).Pt()<=25000 || fabs((lepton.at(c)).Eta())>2.5)
		{
		  vector<TLorentzVector>::iterator Iter;
		  Iter=lepton.begin()+c;
		  lepton.erase(Iter);
		  vector<int>::iterator Ite;
		  Ite=ltype.begin()+c;
		  ltype.erase(Ite);
		  c--;
		  
		}
	 
	}
      
      if(lepton.size()!=3)
	eventSel=false;

      if(eventSel)
     	afterNlep+=theweight;

      //cout<<"hey"<<'\n';

      if(eventSel)
	{
	  //cout<<"hey"<<'\n';
	  //cout<<lepton.size()<<'\n';
	  //cout<<ltype.size()<<'\n';
	  double maxpt=0;
	  int place=-1;
	  for(unsigned int v=0;v<lepton.size();v++)
	    {
	      //cout<<maxpt<<'\n';
	      //cout<<(lepton.at(v)).Pt()<<'\n';
	      if( (lepton.at(v)).Pt()>maxpt)
		{
		  maxpt=(lepton.at(v)).Pt();
		  place=v;
		}
	    }
	  //cout<<place<<'\n';
	  assert(place>=0);
	  if(place!=0)
	    {
	      TLorentzVector temp=lepton.at(place);
	      lepton.at(place)=lepton.at(0);
	      lepton.at(0)=temp;
	      int tempt=ltype.at(place);
	      ltype.at(place)=ltype.at(0);
	      ltype.at(0)=tempt;
	     
	    }
	  if( (lepton.at(1)).Pt() < (lepton.at(2)).Pt() )
	    {
	      TLorentzVector temp=lepton.at(1);
	      lepton.at(1)=lepton.at(2);
	      lepton.at(2)=temp;
	      int tempt=ltype.at(1);
	      ltype.at(1)=ltype.at(2);
	      ltype.at(2)=tempt;
	     
	    }
	  //cout<<"leptons sorted"<<'\n';
	}

       
      if(jet.size()<1)
      	eventSel=false;
      
      if(eventSel)
	{
	  //cout<<"passed lepton and neutrino_ requirements!"<<'\n';
	  //cout<<"listen"<<'\n';
	  for(unsigned int c=0;c<jet.size()-1;c++)//sorts jets with isb information
	    {
	      for(unsigned int d=c+1;d<jet.size();d++)
		{
		  if( (jet.at(c)).Pt()< (jet.at(d)).Pt())
		    {
		      TLorentzVector temp=jet.at(c);
		      jet.at(d)=jet.at(c);
		      jet.at(c)=temp;
		    }
		}
	    }
	 
	}


      if(jet.size()==0)
      	eventSel=false;

     
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

      if(jet.size()!=2) 
	eventSel=false;

      if(eventSel)
	afterjetQ+=theweight;

      //cout<<"hey"<<'\n';
          	      
      if(eventSel)//MET requirements
	{
	  //cout<<jet.size();
	  //cout<<lepton.size();
	  for(unsigned int y=0;y<jet.size();y++)
	    {
	      double pt=(jet.at(y)).Pt();
	      double eta=(jet.at(y)).Eta();
	      double phi=(jet.at(y)).Phi();
	      double E=(jet.at(y)).E();
	      
	      TLorentzVector temp;
	      temp.SetPtEtaPhiE(pt,eta,phi,E);
	      NegMET=NegMET+temp;
	    }

	  for(unsigned int y=0;y<lepton.size();y++)
	    {
	      double pt=(lepton.at(y)).Pt();
	      double eta=(lepton.at(y)).Eta();
	      double phi=(lepton.at(y)).Phi();
	      double E=(lepton.at(y)).E();
	      
	      TLorentzVector temp;
	      temp.SetPtEtaPhiE(pt,eta,phi,E);
	      NegMET=NegMET+temp;
	    }


	  if(NegMET.Pt()<15)
	    {
	      eventSel=false;
	      //cout<<"failed neutrino_ cut: neutrino_="<<NegMET.Pt()<<'\n';
	    }
	}
      
      if(eventSel)
	afterMET+=theweight;
      
      TLorentzVector leftoverLepton;
      TLorentzVector zLepton;
      TLorentzVector zAntiLepton;

      
      //cout<<"listen"<<'\n';


      if(eventSel)
	{
	  
	  //cout<<"listen"<<'\n';

	  //now we will reconstruct things ************
	 
	  //reconstruct the z
	  
	  //zFourVec=NegMET;

	  bool setz=false;
	  
	  int nelec=0;
	  int nmuon=0;
	  for(unsigned int u=0;u<ltype.size();u++)
	    {
	      if(ltype.at(u)==1)
		nelec++;
	      else
		{
		  assert(ltype.at(u)==2);
		  nmuon++;
		}
	    }

	  //cout<<'\n';
	  
	  assert(nelec+nmuon==3);
	  
	  //cout<<"nelec="<<nelec<<'\n';
	  
	  
	  if(nelec==2)
	    {
	      //cout<<"2electrons"<<'\n';
	      for(unsigned int u=0;u<lepton.size();u++)
		{
		  if(ltype.at(u)==1)
		    {
		      TLorentzVector temp=zFourVec;
		      zFourVec=temp+lepton.at(u);
		      setz=true;
		      zLepton=lepton.at(u);
		      zAntiLepton=lepton.at(u);
		     
		    }
		  else
		    leftoverLepton=lepton.at(u);
		}
	      //cout<<"zmass"<<zFourVec.M()<<'\n';
	    }
	  else if(nmuon==2)
	    {
	      //cout<<"2muons"<<'\n';
	      for(unsigned int u=0;u<lepton.size();u++)
		{
		  if(ltype.at(u)==2)
		    {
		      TLorentzVector temp=zFourVec;
		      zFourVec=temp+lepton.at(u);
		      setz=true;
		      zLepton=lepton.at(u);
		      zAntiLepton=lepton.at(u);
		     
		    }
		  else
		    leftoverLepton=lepton.at(u);
		}
	      //cout<<"zmass"<<zFourVec.M()<<'\n';
	    }
	  else//find pair that gives closest to z mass while keeping Z charge=0
	    {
	      //cout<<nmuon<<" "<<nelec<<'\n';
	      //cout<<lcharge.at(0)<<" "<<lcharge.at(1)<<" "<<lcharge.at(2)<<'\n';
	      TLorentzVector temp;
	      //cout<<"zmass="<<zFourVec.M()<<'\n';
	      
	      temp=lepton.at(0)+lepton.at(1);
	      if(zFourVec.M()==0 || fabs(temp.M()-91.1) < fabs(zFourVec.M()-91.1) )
		{
		  //cout<<"in01"<<'\n';
		  zFourVec=temp;
		  setz=true;
		  zLepton=lepton.at(0);
		  zAntiLepton=lepton.at(1);
		  
		 
		  leftoverLepton=lepton.at(2);
		}
	      
	      //cout<<"zmass="<<zFourVec.M()<<'\n';
	      
	      temp=lepton.at(0)+lepton.at(2);
	      if(zFourVec.M()==0 ||  fabs(temp.M()-91.1) < fabs(zFourVec.M()-91.1) )
		{
		  //cout<<"in02"<<'\n';
		  zFourVec=temp;
		  setz=true;
		  
		  zLepton=lepton.at(0);
		  zAntiLepton=lepton.at(2);
		  
		
		  leftoverLepton=lepton.at(1);
		}
	      
	      //cout<<"zmass="<<zFourVec.M()<<'\n';
	      //cout<<"correctZlep="<<correctzlep<<'\n';
	      temp=lepton.at(1)+lepton.at(2);
	      if(zFourVec.M()==0 ||  fabs(temp.M()-91.1) < fabs(zFourVec.M()-91.1) )
		{
		  //cout<<"in12"<<'\n';
		  zFourVec=temp;
		  setz=true;
		  
		  zLepton=lepton.at(1);
		  zAntiLepton=lepton.at(2);
		  
		 
		  leftoverLepton=lepton.at(0);
		}
	      
	      //cout<<"zmass="<<zFourVec.M()<<'\n';
	      //cout<<"correctZlep="<<correctzlep<<'\n';
	    }
	  
	  if(!setz)
	    {
	      TLorentzVector temp;
	      cout<<"nelec="<<nelec<<"nmuon="<<nmuon<<'\n';
	      cout<<"zFourVec.M()="<<zFourVec.M()<<'\n';
	      temp=lepton.at(0)+lepton.at(1);
	      cout<<"01temp.M()="<<temp.M()<<'\n';
	      temp=lepton.at(0)+lepton.at(2);
	      cout<<"02temp.M()="<<temp.M()<<'\n';
	      temp=lepton.at(1)+lepton.at(2);
	      cout<<"12temp.M()="<<temp.M()<<'\n';
	    }

	  assert(setz);

	  //if(correctzlep)
	  //nRightZ+=theweight;
	  //else
	  //nWrongZ+=theweight;



	  //reconstruct the v from remaining lepton and assume w mass

	  double METPhi=NegMET.Phi();
	  METPhi+=3.14;
	  if(METPhi>3.14)
	    METPhi-=6.28;
	  
	  MET=Wvariables::Wneutrino(-1.0*NegMET.Pt(), METPhi, leftoverLepton.Pt(), leftoverLepton.Eta(), leftoverLepton.Phi() );

	  //cout<<"leftoverLepton.Pt() ="<<leftoverLepton.Pt() <<'\n';
	  //cout<<"leftoverLepton.Phi() ="<<leftoverLepton.Phi() <<'\n';
	  //cout<<"-1.0*NegMET.Pt() ="<<-1.0*NegMET.Pt() <<'\n';
	  //cout<<"METPhi ="<<METPhi <<'\n';
	  //cout<<" ="<< <<'\n';
	  //cout<<" ="<< <<'\n';



	  double WTransverseMass=Wvariables::WtransverseMass(leftoverLepton.Pt(),leftoverLepton.Phi(),-1.0*NegMET.Pt(),METPhi);
	  
	  //cout<<"WTransversemass="<<WTransverseMass<<'\n';
	  //reconstruct w

	  wFourVec=MET+leftoverLepton;

	  //reconstruct top from w+bjet
	  
	  tFourVec=wFourVec+jet.at(0);
	 	  
	  double ht=AngularVariables::ht(jet,lepton)/1000;
	  double h=AngularVariables::h(jet,lepton)/1000;
	  double centrality=AngularVariables::centrality(ht,h);

	  //cout<<h<<'\n';
	  //cout<<ht<<'\n';
	   

	  vector<double> a_s=AngularVariables::aplan_spher(jet,lepton,MET);
	  
	  double aplanarity=a_s.at(0);
	  double sphericity=a_s.at(1);
	  double circularity=a_s.at(2);

	  TLorentzVector CMframe=wFourVec+zFourVec;
	  for(unsigned int i=0; i<jet.size();i++)
	    CMframe=CMframe+jet.at(i);
	  
	  TLorentzVector tlSpec;//leading jet not from top
	  
	    tlSpec=jet.at(1);
	 	  
	  double WHelicity=TopPolarization::WHelicity(leftoverLepton,wFourVec,tFourVec);
	  double TopPolHel=TopPolarization::TopPolHelBasis(leftoverLepton,CMframe,tFourVec);
	  double TopPolOpt=TopPolarization::TopPolOptimalBasis(leftoverLepton,tlSpec,tFourVec);

	  //cout<<"listen"<<'\n';


	  bool goodevent=true;

	  //reco cuts affect goodevent



	  if(goodevent)
	    {
	      //cout<<"filling"<<'\n';
	      //now we have done jet recombination and are sorted making a plot of Njets
	      testNjets->Fill(jet.size(),theweight);
	      testNlep->Fill(lepton.size(),theweight);
	      testNelec->Fill(nelec,theweight);
	      
	      //making plots of leading and subleading jet
	      
	      assert(jet.size()==2);
	     
	      //assert(nbjets==1);
	      
	    
		  BJetPT->Fill((jet.at(0)).Pt()/1000,theweight);
		  BJetEta->Fill((jet.at(0)).Eta(),theweight);
		  BJetphi->Fill((jet.at(0)).Phi(),theweight);
		  BJetmass->Fill((jet.at(0)).M()/1000,theweight);
		  
		  nonBJetPT->Fill((jet.at(1)).Pt()/1000,theweight);
		  nonBJetEta->Fill((jet.at(1)).Eta(),theweight);
		  nonBJetphi->Fill((jet.at(1)).Phi(),theweight);
		  nonBJetmass->Fill((jet.at(1)).M()/1000,theweight);
		
	     
	      
	      assert(lepton.size()==3);
	      //making plots for leptons
	      lepton1PT->Fill((lepton.at(0)).Pt()/1000,theweight);
	      lepton1Eta->Fill((lepton.at(0)).Eta(),theweight);
	      lepton1phi->Fill((lepton.at(0)).Phi(),theweight);
	      lepton1mass->Fill((lepton.at(0)).M()/1000,theweight);

	      lepton2PT->Fill((lepton.at(1)).Pt()/1000,theweight);
	      lepton2Eta->Fill((lepton.at(1)).Eta(),theweight);
	      lepton2phi->Fill((lepton.at(1)).Phi(),theweight);
	      lepton2mass->Fill((lepton.at(1)).M()/1000,theweight);

	      lepton3PT->Fill((lepton.at(2)).Pt()/1000,theweight);
	      lepton3Eta->Fill((lepton.at(2)).Eta(),theweight);
	      lepton3phi->Fill((lepton.at(2)).Phi(),theweight);
	      lepton3mass->Fill((lepton.at(2)).M()/1000,theweight);

	      leftoverLeptonPT->Fill(leftoverLepton.Pt()/1000,theweight);
	      leftoverLeptonEta->Fill(leftoverLepton.Eta(),theweight);
	      leftoverLeptonphi->Fill(leftoverLepton.Phi(),theweight);
	      leftoverLeptonmass->Fill(leftoverLepton.M()/1000,theweight);

	      zLeptonPT->Fill(zLepton.Pt()/1000,theweight);
	      zLeptonEta->Fill(zLepton.Eta(),theweight);
	      zLeptonphi->Fill(zLepton.Phi(),theweight);
	      zLeptonmass->Fill(zLepton.M()/1000,theweight);

	      zAntiLeptonPT->Fill(zAntiLepton.Pt()/1000,theweight);
	      zAntiLeptonEta->Fill(zAntiLepton.Eta(),theweight);
	      zAntiLeptonphi->Fill(zAntiLepton.Phi(),theweight);
	      zAntiLeptonmass->Fill(zAntiLepton.M()/1000,theweight);
	      
	      //cout<<"zLeptonPt"<<zLepton.Pt()<<'\n';
	      //cout<<"zAntiLeptonPt"<<zAntiLepton.Pt()<<'\n';

	      //making plots for reco objects
	      recoZPT->Fill(zFourVec.Pt()/1000,theweight);
	      recoZEta->Fill(zFourVec.Eta(),theweight);
	      recoZphi->Fill(zFourVec.Phi(),theweight);
	      recoZmass->Fill(zFourVec.M()/1000,theweight);

	      MET_PT->Fill(MET.Pt()/1000,theweight);
	      MET_Eta->Fill(MET.Eta(),theweight);
	      MET_phi->Fill(MET.Phi(),theweight);
	      MET_pz->Fill(MET.Pz()/1000,theweight);

	      recoWPT->Fill(wFourVec.Pt()/1000,theweight);
	      recoWEta->Fill(wFourVec.Eta(),theweight);
	      recoWphi->Fill(wFourVec.Phi(),theweight);
	      recoWmass->Fill(wFourVec.M()/1000,theweight);
	      
	      recotopPT->Fill(tFourVec.Pt()/1000,theweight);
	      recotopEta->Fill(tFourVec.Eta(),theweight);
	      recotopphi->Fill(tFourVec.Phi(),theweight);
	      recotopmass->Fill(tFourVec.M()/1000,theweight);

	      assert(WTransverseMass>0);

	      WTmass->Fill(WTransverseMass/1000,theweight);
	      TopPolHB->Fill(TopPolHel,theweight);
	      TopPolOB->Fill(TopPolOpt,theweight);
	      centralityhist->Fill(centrality,theweight);
	      sphericityhist->Fill(sphericity,theweight);
	      aplanarityhist->Fill(aplanarity,theweight);
	      circularityhist->Fill(circularity,theweight);
	      WHel->Fill(WHelicity,theweight);
	      h_hist->Fill(h,theweight);
	      ht_hist->Fill(ht,theweight);



	      totalPassed+=theweight;
	    }//if(goodevent)
	  //cout<<"end"<<'\n';
	}//if(eventsel)
    }//end event loop
  
  cout<<'\n'<<"afterNothing="<<afterNothing<<'\n'<<"afterNlep="<<afterNlep<<'\n'<<"afterJetQ="<<afterjetQ<<'\n'<<"afterMET="<<afterMET<<'\n'<<"totalPassed="<<totalPassed<<'\n'<<'\n'<<'\n'<<'\n';

  TCanvas *c1 = new TCanvas("c1","c1",560,720);
  if(true)//totalPassed>0)
    {
 
      testNjets->Draw();
      testNjets->Scale(Lumi*crossSection/afterNothing);
      testNlep->Draw();
      testNlep->Scale(Lumi*crossSection/afterNothing);
      testNelec->Draw();
      testNelec->Scale(Lumi*crossSection/afterNothing);

      tPT->Scale(Lumi*crossSection/afterNothing);
      tPT->Draw();
      tEta->Scale(Lumi*crossSection/afterNothing);
      tEta->Draw();
      tphi->Scale(Lumi*crossSection/afterNothing);
      tphi->Draw();
      
      bPT->Scale(Lumi*crossSection/afterNothing);
      bPT->Draw();
      bEta->Scale(Lumi*crossSection/afterNothing);
      bEta->Draw();
      bphi->Scale(Lumi*crossSection/afterNothing);
      bphi->Draw();
      
      lPT->Scale(Lumi*crossSection/afterNothing);
      lPT->Draw();
      lEta->Scale(Lumi*crossSection/afterNothing);
      lEta->Draw();
      lphi->Scale(Lumi*crossSection/afterNothing);
      lphi->Draw();
      
      vPT->Scale(Lumi*crossSection/afterNothing);
      vPT->Draw();
      vEta->Scale(Lumi*crossSection/afterNothing);
      vEta->Draw();
      vphi->Scale(Lumi*crossSection/afterNothing);
      vphi->Draw();
      
      wPT->Scale(Lumi*crossSection/afterNothing);
      wPT->Draw();
      wEta->Scale(Lumi*crossSection/afterNothing);
      wEta->Draw();
      wphi->Scale(Lumi*crossSection/afterNothing);
      wphi->Draw();
      
      zPT->Scale(Lumi*crossSection/afterNothing);
      zPT->Draw();
      zEta->Scale(Lumi*crossSection/afterNothing);
      zEta->Draw();
      zphi->Scale(Lumi*crossSection/afterNothing);
      zphi->Draw();

          
      BJetPT->Scale(Lumi*crossSection/afterNothing);
      BJetPT->Draw();
      BJetEta->Scale(Lumi*crossSection/afterNothing);
      BJetEta->Draw();
      BJetphi->Scale(Lumi*crossSection/afterNothing);
      BJetphi->Draw();
      BJetmass->Scale(Lumi*crossSection/afterNothing);
      BJetmass->Draw();
      
      nonBJetPT->Scale(Lumi*crossSection/afterNothing);
      nonBJetPT->Draw();
      nonBJetEta->Scale(Lumi*crossSection/afterNothing);
      nonBJetEta->Draw();
      nonBJetphi->Scale(Lumi*crossSection/afterNothing);
      nonBJetphi->Draw();
      nonBJetmass->Scale(Lumi*crossSection/afterNothing);
      nonBJetmass->Draw();
            
      MET_PT->Scale(Lumi*crossSection/afterNothing);
      MET_PT->Draw();
      MET_Eta->Scale(Lumi*crossSection/afterNothing);
      MET_Eta->Draw();
      MET_phi->Scale(Lumi*crossSection/afterNothing);
      MET_phi->Draw();
      MET_pz->Scale(Lumi*crossSection/afterNothing);
      MET_pz->Draw();
      
      lepton1PT->Scale(Lumi*crossSection/afterNothing);
      lepton1PT->Draw();
      lepton1Eta->Scale(Lumi*crossSection/afterNothing);
      lepton1Eta->Draw();
      lepton1phi->Scale(Lumi*crossSection/afterNothing);
      lepton1phi->Draw();
      lepton1mass->Scale(Lumi*crossSection/afterNothing);
      lepton1mass->Draw();
      
      recoWPT->Scale(Lumi*crossSection/afterNothing);
      recoWPT->Draw();
      recoWEta->Scale(Lumi*crossSection/afterNothing);
      recoWEta->Draw();
      recoWphi->Scale(Lumi*crossSection/afterNothing);
      recoWphi->Draw();
      recoWmass->Scale(Lumi*crossSection/afterNothing);
      recoWmass->Draw();

      recoZPT->Scale(Lumi*crossSection/afterNothing);
      recoZPT->Draw();
      recoZEta->Scale(Lumi*crossSection/afterNothing);
      recoZEta->Draw();
      recoZphi->Scale(Lumi*crossSection/afterNothing);
      recoZphi->Draw();
      recoZmass->Scale(Lumi*crossSection/afterNothing);
      recoZmass->Draw();
      
      recotopPT->Scale(Lumi*crossSection/afterNothing);
      recotopPT->Draw();
      recotopEta->Scale(Lumi*crossSection/afterNothing);
      recotopEta->Draw();
      recotopphi->Scale(Lumi*crossSection/afterNothing);
      recotopphi->Draw();
      recotopmass->Scale(Lumi*crossSection/afterNothing);
      recotopmass->Draw();

      lepton2PT->Scale(Lumi*crossSection/afterNothing);
      lepton2PT->Draw();
      lepton2Eta->Scale(Lumi*crossSection/afterNothing);
      lepton2Eta->Draw();
      lepton2phi->Scale(Lumi*crossSection/afterNothing);
      lepton2phi->Draw();
      lepton2mass->Scale(Lumi*crossSection/afterNothing);
      lepton2mass->Draw();
      
      lepton3PT->Scale(Lumi*crossSection/afterNothing);
      lepton3PT->Draw();
      lepton3Eta->Scale(Lumi*crossSection/afterNothing);
      lepton3Eta->Draw();
      lepton3phi->Scale(Lumi*crossSection/afterNothing);
      lepton3phi->Draw();
      lepton3mass->Scale(Lumi*crossSection/afterNothing);
      lepton3mass->Draw();

      leftoverLeptonPT->Scale(Lumi*crossSection/afterNothing);
      leftoverLeptonPT->Draw();
      leftoverLeptonEta->Scale(Lumi*crossSection/afterNothing);
      leftoverLeptonEta->Draw();
      leftoverLeptonphi->Scale(Lumi*crossSection/afterNothing);
      leftoverLeptonphi->Draw();
      leftoverLeptonmass->Scale(Lumi*crossSection/afterNothing);
      leftoverLeptonmass->Draw();

      zLeptonPT->Scale(Lumi*crossSection/afterNothing);
      zLeptonPT->Draw();
      zLeptonEta->Scale(Lumi*crossSection/afterNothing);
      zLeptonEta->Draw();
      zLeptonphi->Scale(Lumi*crossSection/afterNothing);
      zLeptonphi->Draw();
      zLeptonmass->Scale(Lumi*crossSection/afterNothing);
      zLeptonmass->Draw();

      zAntiLeptonPT->Scale(Lumi*crossSection/afterNothing);
      zAntiLeptonPT->Draw();
      zAntiLeptonEta->Scale(Lumi*crossSection/afterNothing);
      zAntiLeptonEta->Draw();
      zAntiLeptonphi->Scale(Lumi*crossSection/afterNothing);
      zAntiLeptonphi->Draw();
      zAntiLeptonmass->Scale(Lumi*crossSection/afterNothing);
      zAntiLeptonmass->Draw();

      WTmass->Scale(Lumi*crossSection/afterNothing);
      WTmass->Draw();
 
      TopPolHB->Scale(Lumi*crossSection/afterNothing);
      TopPolOB->Scale(Lumi*crossSection/afterNothing);
      centralityhist->Scale(Lumi*crossSection/afterNothing);
      sphericityhist->Scale(Lumi*crossSection/afterNothing);
      aplanarityhist->Scale(Lumi*crossSection/afterNothing);
      circularityhist->Scale(Lumi*crossSection/afterNothing);
      WHel->Scale(Lumi*crossSection/afterNothing);
      h_hist->Scale(Lumi*crossSection/afterNothing);
      ht_hist->Scale(Lumi*crossSection/afterNothing);

      TopPolHB->Draw();
      TopPolOB->Draw();
      centralityhist->Draw();
      sphericityhist->Draw();
      circularityhist->Draw();
      aplanarityhist->Draw();
      WHel->Draw();
      h_hist->Draw();
      ht_hist->Draw();

      c1->cd();
      c1->SetBorderMode(0);

      //c1->SetName("tz leptons");
      //gROOT->SetStyle("Plain");
      gStyle->SetOptTitle(0);
      //gStyle->SetOptTitle(0);
      gStyle->SetOptStat(0);
      //gStyle->SetOptStat(0);
      //gStyle->SetStatBorderSize(0);
      //gStyle->SetStatColor(0);

      //gStyle->UseCurrentStyle();
           
      //gROOT->ForceStyle();

      leftoverLeptonPT->SetTitle(" ");
      
      leftoverLeptonPT->UseCurrentStyle();
      leftoverLeptonPT->SetFillColor(0);
      leftoverLeptonPT->SetLineColor(2);
      leftoverLeptonPT->Draw();

      zAntiLeptonPT->UseCurrentStyle();
      zAntiLeptonPT->SetFillColor(0);
      zAntiLeptonPT->SetLineColor(3);
      zAntiLeptonPT->Draw("SAME");

      zLeptonPT->UseCurrentStyle();
      zLeptonPT->SetFillColor(0);
      zLeptonPT->SetLineColor(4);
      zLeptonPT->Draw("SAME");

      TLegend *leg = new TLegend(0.53,0.79,0.94,0.97);
      leg->SetFillColor(0);
      leg->SetLineColor(0);

      leg->SetShadowColor(0);
      
      leg->AddEntry(leftoverLeptonPT ,"wLeptonPT","l" ); 
      leg->AddEntry(zAntiLeptonPT ,"zAntiLeptonPT","l" ); 
      leg->AddEntry(zLeptonPT ,"zLeptonPT","l" ); 

      
      leg->SetTextFont(132);
      leg->SetTextSize(0.05);
      leg->Draw();
      
      TAxis *xaxis = leftoverLeptonPT->GetXaxis();
      xaxis->SetTitle("Lepton Pt (GeV)");






      //myText(0.55, 0.83, 1, Form("#int L dt = %.1f fb^{-1}",(float)lum));
      
       

      //c1->Print("Blah.pdf");

         
    }
  
  TFile outfile("histos-truth-COMMON.root","recreate");

  c1->Write();

  zLeptonPT->SetLineColor(4);

  zAntiLeptonPT->SetLineColor(3);
  
  leftoverLeptonPT->SetLineColor(2);

  leftoverLeptonPT->SetTitle("Leftover Lepton PT");

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
  
  zPT->Write();
  zEta->Write();
  zphi->Write();
  
  testNjets->Write();
  testNlep->Write();
  testNelec->Write();

  BJetPT->Write();
  BJetEta->Write();
  BJetphi->Write();
  BJetmass->Write();
  
  nonBJetPT->Write();
  nonBJetEta->Write();
  nonBJetphi->Write();
  nonBJetmass->Write();
  
  MET_PT->Write();
  MET_Eta->Write();
  MET_phi->Write();
  MET_pz->Write();
  
  lepton1PT->Write();
  lepton1Eta->Write();
  lepton1phi->Write();
  lepton1mass->Write();
  
  lepton2PT->Write();
  lepton2Eta->Write();
  lepton2phi->Write();
  lepton2mass->Write();

  lepton3PT->Write();
  lepton3Eta->Write();
  lepton3phi->Write();
  lepton3mass->Write();

  leftoverLeptonPT->Write();
  leftoverLeptonEta->Write();
  leftoverLeptonphi->Write();
  leftoverLeptonmass->Write();

  zLeptonPT->Write();
  zLeptonEta->Write();
  zLeptonphi->Write();
  zLeptonmass->Write();

  zAntiLeptonPT->Write();
  zAntiLeptonEta->Write();
  zAntiLeptonphi->Write();
  zAntiLeptonmass->Write();

  recoWPT->Write();
  recoWEta->Write();
  recoWphi->Write();
  recoWmass->Write();
  
  recoZPT->Write();
  recoZEta->Write();
  recoZphi->Write();
  recoZmass->Write();
  
  recotopPT->Write();
  recotopEta->Write();
  recotopphi->Write();
  recotopmass->Write();

  WTmass->Write();
  TopPolHB->Write();
  TopPolOB->Write();
  centralityhist->Write();
  sphericityhist->Write();
  circularityhist->Write();
  aplanarityhist->Write();
  WHel->Write();
  h_hist->Write();
  ht_hist->Write();

  outfile.Write();
    
  cout<<'\n'<<'\n'<<'\n';
}

int main(int argc, char **argv)
{
  argc=0;
  argv[0][0]='0';
  return 0;
}
