
#include "tz_d3pd.C"
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

  TH1F *LeadJetPT=new TH1F("LeadJetPT","Leading Jet PT",10,0,400);
  TH1F *LeadJetEta=new TH1F("LeadJetEta","Leading Jet Eta",10,-5,5);
  TH1F *LeadJetphi=new TH1F("LeadJetphi","Leading Jet phi",8,-4,4);
  TH1F *LeadJetmass=new TH1F("LeadJetmass","Leading Jet mass",50,0,50);

  TH1F *SecondJetPT=new TH1F("SecondJetPT","Second Jet PT",10,0,400);
  TH1F *SecondJetEta=new TH1F("SecondJetEta","Second Jet Eta",10,-5,5);
  TH1F *SecondJetphi=new TH1F("SecondJetphi","Second Jet phi",8,-4,4);
  TH1F *SecondJetmass=new TH1F("SecondJetmass","Second Jet mass",50,0,50);

  TH1F *MET_PT=new TH1F("recovPT","Reconstructed neutrino PT",6,0,240);
  TH1F *MET_Eta=new TH1F("recovEta","Reconstructed neutrino Eta",10,-5,5);
  TH1F *MET_phi=new TH1F("recovphi","Reconstructed neutrino phi",8,-4,4);
  TH1F *MET_pz=new TH1F("recovpz","Reconstructed neutrino pz",12,-240,240);

  TH1F *lepton1PT=new TH1F("lepton1PT","Leading lepton PT",12,0,240);
  TH1F *lepton1Eta=new TH1F("lepton1Eta","Leading lepton Eta",10,-5,5);
  TH1F *lepton1phi=new TH1F("lepton1phi","Leading lepton phi",8,-4,4);
  TH1F *lepton1mass=new TH1F("lepton1mass","Leading lepton mass",50,0,2);

  TH1F *recoWPT=new TH1F("recoWPT","Reconstructed W PT",10,0,400);
  TH1F *recoWEta=new TH1F("recoWEta","Reconstructed W Eta",10,-5,5);
  TH1F *recoWphi=new TH1F("recoWphi","Reconstructed W phi",8,-4,4);
  TH1F *recoWmass=new TH1F("recoWmass","Reconstructed W mass",500,80,80.8);

  TH1F *recotopPT=new TH1F("recotopPT","Reconstructed top PT",10,0,400);
  TH1F *recotopEta=new TH1F("recotopEta","Reconstructed top Eta",10,-5,5);
  TH1F *recotopphi=new TH1F("recotopphi","Reconstructed top phi",8,-4,4);
  TH1F *recotopmass=new TH1F("recotopmass","Reconstructed top mass",6,120,240);

  TH1F *recoZPT=new TH1F("recoZPT","Reconstructed Z PT",10,0,400);
  TH1F *recoZEta=new TH1F("recoZEta","Reconstructed Z Eta",10,-5,5);
  TH1F *recoZphi=new TH1F("recoZphi","Reconstructed Z phi",8,-4,4);
  TH1F *recoZmass=new TH1F("recoZmass","Reconstructed Z mass",15,70,110);

  TH1F *lepton2PT=new TH1F("lepton2PT","Second lepton PT",12,0,240);
  TH1F *lepton2Eta=new TH1F("lepton2Eta","Second lepton Eta",10,-5,5);
  TH1F *lepton2phi=new TH1F("lepton2phi","Second lepton phi",8,-4,4);
  TH1F *lepton2mass=new TH1F("lepton2mass","Second lepton mass",50,0,2);

  TH1F *lepton3PT=new TH1F("lepton3PT","Third lepton PT",12,0,240);
  TH1F *lepton3Eta=new TH1F("lepton3Eta","Third lepton Eta",10,-5,5);
  TH1F *lepton3phi=new TH1F("lepton3phi","Third lepton phi",8,-4,4);
  TH1F *lepton3mass=new TH1F("lepton3mass","Third lepton mass",50,0,2);

  TH1F *leftoverLeptonPT=new TH1F("leftoverLeptonPT","Leftover lepton PT",12,0,240);
  TH1F *leftoverLeptonEta=new TH1F("leftoverLeptonEta","Leftover lepton Eta",10,-5,5);
  TH1F *leftoverLeptonphi=new TH1F("leftoverLeptonphi","Leftover lepton phi",8,-4,4);
  TH1F *leftoverLeptonmass=new TH1F("leftoverLeptonmass","Leftover lepton mass",50,0,2);

  TH1F *zLepton1PT=new TH1F("zLepton1PT","Leading z Lepton PT",12,0,240);
  TH1F *zLepton1Eta=new TH1F("zLepton1Eta","Leading z Lepton Eta",10,-5,5);
  TH1F *zLepton1phi=new TH1F("zLepton1phi","Leading z Lepton phi",8,-4,4);
  TH1F *zLepton1mass=new TH1F("zLepton1mass","Leading z Lepton mass",50,0,2);

  TH1F *zLepton2PT=new TH1F("zLepton2PT","Second z Lepton PT",12,0,240);
  TH1F *zLepton2Eta=new TH1F("zLepton2Eta","Second z Lepton Eta",10,-5,5);
  TH1F *zLepton2phi=new TH1F("zLepton2phi","Second z Lepton phi",8,-4,4);
  TH1F *zLepton2mass=new TH1F("zLepton2mass","Second z Lepton mass",50,0,2);

  TH1F *WTmass=new TH1F("WTmass","W Transverse mass",12,0,240);
  TH1F *TopPolHB=new TH1F("TopPolHB","Top Polarization Helicity Basis",10,-1,1);
  TH1F *TopPolOB=new TH1F("TopPolOB","Top Polarization Optimal Basis",10,-1,1);
  TH1F *centralityhist=new TH1F("centrality","centrality",10,0,1);
  TH1F *sphericityhist=new TH1F("sphericity","sphericity",10,0,1);
  TH1F *aplanarityhist=new TH1F("aplanarity","aplanarity",10,0,1);
  TH1F *circularityhist=new TH1F("circularity","circularity",10,0,1);
  TH1F *WHel=new TH1F("WHel","W Helicity",8,-1,1);
  TH1F *h_hist=new TH1F("h","h",15,0,3000);
  TH1F *ht_hist=new TH1F("ht","ht",10,0,1000);



  double afterNlep=0;
  double afterjetQ=0;
  double afterMET=0;
  double totalPassed=0;
  double afterNothing=0;





  int nEvents=100000;
  double Lumi=20.3;
  double crossSection=1.652;
  double theweight=1000*Lumi*crossSection/nEvents;

  TChain * t = new TChain("physics");
  t->Add("/home/schoenr1/rootFiles/tz/FULL/mc12_8TeV.179992.MadGraphPythia_AUET2B_CTEQ6L1_tZ_stchan_Zll_PythiaDecays.merge.NTUP_TOP.e2241_s1773_s1776_r4485_r4540_p1400_tid01371606_00/NTUP_TOP.01371606._000001.root.1"); 
  t->Add("/home/schoenr1/rootFiles/tz/FULL/mc12_8TeV.179992.MadGraphPythia_AUET2B_CTEQ6L1_tZ_stchan_Zll_PythiaDecays.merge.NTUP_TOP.e2241_s1773_s1776_r4485_r4540_p1400_tid01371606_00/NTUP_TOP.01371606._000002.root.1"); 
  t->Add("/home/schoenr1/rootFiles/tz/FULL/mc12_8TeV.179992.MadGraphPythia_AUET2B_CTEQ6L1_tZ_stchan_Zll_PythiaDecays.merge.NTUP_TOP.e2241_s1773_s1776_r4485_r4540_p1400_tid01371606_00/NTUP_TOP.01371606._000003.root.1"); 
  t->Add("/home/schoenr1/rootFiles/tz/FULL/mc12_8TeV.179992.MadGraphPythia_AUET2B_CTEQ6L1_tZ_stchan_Zll_PythiaDecays.merge.NTUP_TOP.e2241_s1773_s1776_r4485_r4540_p1400_tid01371606_00/NTUP_TOP.01371606._000004.root.1"); 
  t->Add("/home/schoenr1/rootFiles/tz/FULL/mc12_8TeV.179992.MadGraphPythia_AUET2B_CTEQ6L1_tZ_stchan_Zll_PythiaDecays.merge.NTUP_TOP.e2241_s1773_s1776_r4485_r4540_p1400_tid01371606_00/NTUP_TOP.01371606._000005.root.1"); 
  t->Add("/home/schoenr1/rootFiles/tz/FULL/mc12_8TeV.179992.MadGraphPythia_AUET2B_CTEQ6L1_tZ_stchan_Zll_PythiaDecays.merge.NTUP_TOP.e2241_s1773_s1776_r4485_r4540_p1400_tid01371606_00/NTUP_TOP.01371606._000006.root.1"); 
  t->Add("/home/schoenr1/rootFiles/tz/FULL/mc12_8TeV.179992.MadGraphPythia_AUET2B_CTEQ6L1_tZ_stchan_Zll_PythiaDecays.merge.NTUP_TOP.e2241_s1773_s1776_r4485_r4540_p1400_tid01371606_00/NTUP_TOP.01371606._000007.root.1"); 
  t->Add("/home/schoenr1/rootFiles/tz/FULL/mc12_8TeV.179992.MadGraphPythia_AUET2B_CTEQ6L1_tZ_stchan_Zll_PythiaDecays.merge.NTUP_TOP.e2241_s1773_s1776_r4485_r4540_p1400_tid01371606_00/NTUP_TOP.01371606._000008.root.1"); 
  t->Add("/home/schoenr1/rootFiles/tz/FULL/mc12_8TeV.179992.MadGraphPythia_AUET2B_CTEQ6L1_tZ_stchan_Zll_PythiaDecays.merge.NTUP_TOP.e2241_s1773_s1776_r4485_r4540_p1400_tid01371606_00/NTUP_TOP.01371606._000009.root.1"); 
  t->Add("/home/schoenr1/rootFiles/tz/FULL/mc12_8TeV.179992.MadGraphPythia_AUET2B_CTEQ6L1_tZ_stchan_Zll_PythiaDecays.merge.NTUP_TOP.e2241_s1773_s1776_r4485_r4540_p1400_tid01371606_00/NTUP_TOP.01371606._000010.root.1"); 
 
  
  t->SetCacheSize(100000000);
  tz_d3pd* event = new tz_d3pd(t);
  

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
      vector<int> isZ;
      //int nelec=0;

      //for(int i=0;i<event->mc_n;i++)
      //{
      //  cout<<"status="<<(*event->mc_status).at(i)<<'\n';
      //  cout<<"pdgid="<<(*event->mc_pdgId).at(i)<<'\n';
      //}


 
      bool eventSel=true;//this holds my event selection stuff
     
      for(int i=0;i<event->jet_AntiKt4Truth_n;i++)
	{
	  TLorentzVector temp;
	  temp.SetPtEtaPhiE((*event->jet_AntiKt4Truth_pt).at(i)/1000,(*event->jet_AntiKt4Truth_eta).at(i),(*event->jet_AntiKt4Truth_phi).at(i),(*event->jet_AntiKt4Truth_E).at(i)/1000);
	  jet.push_back(temp);
	}
      
      for(unsigned int i=0;i<(*event->el_truth_E).size();i++)
	{
	  if((*event->el_truth_mothertype).at(i)==23 || fabs((*event->el_truth_mothertype).at(i))==24)
	    {
	      TLorentzVector temp;
	      temp.SetPtEtaPhiE((*event->el_truth_pt).at(i)/1000,(*event->el_truth_eta).at(i),(*event->el_truth_phi).at(i),(*event->el_truth_E).at(i)/1000);
	      lepton.push_back(temp);
	      ltype.push_back(1);
	      isZ.push_back((*event->el_truth_mothertype).at(i));
	    }
	  //if((*event->el_truth_mothertype).at(i)==23)
	  //cout<<"q="<<q<<"  :  mothertype="<<(*event->el_truth_mothertype).at(i)<<'\n';
	}

      for(unsigned int i=0;i<(*event->mu_truth_E).size();i++)
	{
	  if((*event->mu_truth_mothertype).at(i)==23 || fabs((*event->mu_truth_mothertype).at(i))==24)
	    {
	      TLorentzVector temp;
	      temp.SetPtEtaPhiE((*event->mu_truth_pt).at(i)/1000,(*event->mu_truth_eta).at(i),(*event->mu_truth_phi).at(i),(*event->mu_truth_E).at(i)/1000);
	      lepton.push_back(temp);
	      ltype.push_back(2);
	      isZ.push_back((*event->mu_truth_mothertype).at(i));
	    }
	}
    
      //cout<<"stuff"<<'\n';
      
      for(unsigned int c=0;c<lepton.size();c++)
	{
	  //cout<<c<<'\n';
	  //cout<<lepton.size()<<'\n';
	  //cout<<lepton.at(c).Eta()<<'\n';
	  //cout<<lepton.at(c).Pt()<<'\n';

	  if(lepton.size()>0)
	    if( (lepton.at(c)).Pt()<=25 || fabs((lepton.at(c)).Eta())>2.5)
		{
		  vector<TLorentzVector>::iterator Iter;
		  Iter=lepton.begin()+c;
		  lepton.erase(Iter);
		  vector<int>::iterator Ite;
		  Ite=ltype.begin()+c;
		  ltype.erase(Ite);
		  vector<int>::iterator It;
		  It=isZ.begin()+c;
		  isZ.erase(It);
		  c--;
		  
		}
	 
	}
      
      if(lepton.size()!=3)
	eventSel=false;

      if(eventSel)
     	afterNlep+=theweight;

      //cout<<"you"<<'\n';

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
	      int temps=isZ.at(place);
	      isZ.at(place)=isZ.at(0);
	      isZ.at(0)=temps;
	    }
	  if( (lepton.at(1)).Pt() < (lepton.at(2)).Pt() )
	    {
	      TLorentzVector temp=lepton.at(1);
	      lepton.at(1)=lepton.at(2);
	      lepton.at(2)=temp;
	      int tempt=ltype.at(1);
	      ltype.at(1)=ltype.at(2);
	      ltype.at(2)=tempt;
	      int temps=isZ.at(1);
	      isZ.at(1)=isZ.at(2);
	      isZ.at(2)=temps;
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

      //cout<<"goooooo"<<'\n';

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
      TLorentzVector zLepton1;
      TLorentzVector zLepton2;

      
      //cout<<"hey"<<'\n';

      int nelec=0;
      int nmuon=0;


      if(eventSel)
	{
	  
	  //cout<<"listen"<<'\n';

	  //now we will reconstruct things ************
	 
	  //reconstruct the z
	    
	  int nZ=0;
	  
	  for(unsigned int u=0;u<ltype.size();u++)
	    {
	      if(ltype.at(u)==1)
		nelec++;
	      else
		{
		  assert(ltype.at(u)==2);
		  nmuon++;
		}
	      if(isZ.at(u)== 23)
		nZ++;
	    }
	  if(nZ!=2)
	    eventSel=false;
	}

      //cout<<"listen"<<'\n';

      if(eventSel)
	{
  	  //cout<<"1"<<'\n';

	  assert(nelec+nmuon==3);
	  assert(lepton.size()==3);
	  assert(isZ.size()==3);
	  
	  //cout<<"2"<<'\n';

	  if(isZ.at(0)==23)
	    {
	      zLepton1=lepton.at(0);
	      if(isZ.at(1)==23)
		{
		  zLepton2=lepton.at(1);
		  leftoverLepton=lepton.at(2);		
		}
	      else
		{		  
		  zLepton2=lepton.at(2);
		  leftoverLepton=lepton.at(1);		
		}
	    }
	  else
	    {
	      zLepton1=lepton.at(1);
	      zLepton2=lepton.at(2);
	      leftoverLepton=lepton.at(0);		
	    }
	  
	  zFourVec=zLepton1+zLepton2;
	  
	  //cout<<"there"<<'\n';

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
	 	  
	  double ht=AngularVariables::ht(jet,lepton);
	  double h=AngularVariables::h(jet,lepton);
	  double centrality=AngularVariables::centrality(ht,h);

	  //cout<<"h="<<h<<'\n';
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

	  //cout<<"aft"<<'\n';


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
	      
	      //cout<<"a"<<'\n';
	      
	      LeadJetPT->Fill((jet.at(0)).Pt(),theweight);
	      LeadJetEta->Fill((jet.at(0)).Eta(),theweight);
	      LeadJetphi->Fill((jet.at(0)).Phi(),theweight);
	      LeadJetmass->Fill((jet.at(0)).M(),theweight);
	      
	      SecondJetPT->Fill((jet.at(1)).Pt(),theweight);
	      SecondJetEta->Fill((jet.at(1)).Eta(),theweight);
	      SecondJetphi->Fill((jet.at(1)).Phi(),theweight);
	      SecondJetmass->Fill((jet.at(1)).M(),theweight);
	      
	      //cout<<"b"<<'\n';

	      
	      assert(lepton.size()==3);
	      //making plots for leptons
	      lepton1PT->Fill((lepton.at(0)).Pt(),theweight);
	      lepton1Eta->Fill((lepton.at(0)).Eta(),theweight);
	      lepton1phi->Fill((lepton.at(0)).Phi(),theweight);
	      lepton1mass->Fill((lepton.at(0)).M(),theweight);

	      lepton2PT->Fill((lepton.at(1)).Pt(),theweight);
	      lepton2Eta->Fill((lepton.at(1)).Eta(),theweight);
	      lepton2phi->Fill((lepton.at(1)).Phi(),theweight);
	      lepton2mass->Fill((lepton.at(1)).M(),theweight);

	      lepton3PT->Fill((lepton.at(2)).Pt(),theweight);
	      lepton3Eta->Fill((lepton.at(2)).Eta(),theweight);
	      lepton3phi->Fill((lepton.at(2)).Phi(),theweight);
	      lepton3mass->Fill((lepton.at(2)).M(),theweight);
	      
	      //cout<<"c"<<'\n';

	      leftoverLeptonPT->Fill(leftoverLepton.Pt(),theweight);
	      leftoverLeptonEta->Fill(leftoverLepton.Eta(),theweight);
	      leftoverLeptonphi->Fill(leftoverLepton.Phi(),theweight);
	      leftoverLeptonmass->Fill(leftoverLepton.M(),theweight);

	      zLepton1PT->Fill(zLepton1.Pt(),theweight);
	      zLepton1Eta->Fill(zLepton1.Eta(),theweight);
	      zLepton1phi->Fill(zLepton1.Phi(),theweight);
	      zLepton1mass->Fill(zLepton1.M(),theweight);

	      zLepton2PT->Fill(zLepton2.Pt(),theweight);
	      zLepton2Eta->Fill(zLepton2.Eta(),theweight);
	      zLepton2phi->Fill(zLepton2.Phi(),theweight);
	      zLepton2mass->Fill(zLepton2.M(),theweight);
	      
	      ////cout<<"zLeptonPt"<<zLepton.Pt()<<'\n';
	      ////cout<<"zLeptonPt"<<zLepton.Pt()<<'\n';

	      //making plots for reco objects
	      
	      //cout<<"d"<<'\n';
	      
	      recoZPT->Fill(zFourVec.Pt(),theweight);
	      recoZEta->Fill(zFourVec.Eta(),theweight);
	      recoZphi->Fill(zFourVec.Phi(),theweight);
	      recoZmass->Fill(zFourVec.M(),theweight);
	     
	      //cout<<"e"<<'\n';

	      MET_PT->Fill(MET.Pt(),theweight);
	      MET_Eta->Fill(MET.Eta(),theweight);
	      MET_phi->Fill(MET.Phi(),theweight);
	      MET_pz->Fill(MET.Pz(),theweight);
	      
	      //cout<<"f"<<'\n';

	      recoWPT->Fill(wFourVec.Pt(),theweight);
	      recoWEta->Fill(wFourVec.Eta(),theweight);
	      recoWphi->Fill(wFourVec.Phi(),theweight);
	      recoWmass->Fill(wFourVec.M(),theweight);
	      
	      //cout<<"g"<<'\n';

	      recotopPT->Fill(tFourVec.Pt(),theweight);
	      recotopEta->Fill(tFourVec.Eta(),theweight);
	      recotopphi->Fill(tFourVec.Phi(),theweight);
	      recotopmass->Fill(tFourVec.M(),theweight);

	      assert(WTransverseMass>0);
	     
	      //cout<<"h"<<'\n';

	      WTmass->Fill(WTransverseMass,theweight);
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

          
      LeadJetPT->Scale(Lumi*crossSection/afterNothing);
      LeadJetPT->Draw();
      LeadJetEta->Scale(Lumi*crossSection/afterNothing);
      LeadJetEta->Draw();
      LeadJetphi->Scale(Lumi*crossSection/afterNothing);
      LeadJetphi->Draw();
      LeadJetmass->Scale(Lumi*crossSection/afterNothing);
      LeadJetmass->Draw();
      
      SecondJetPT->Scale(Lumi*crossSection/afterNothing);
      SecondJetPT->Draw();
      SecondJetEta->Scale(Lumi*crossSection/afterNothing);
      SecondJetEta->Draw();
      SecondJetphi->Scale(Lumi*crossSection/afterNothing);
      SecondJetphi->Draw();
      SecondJetmass->Scale(Lumi*crossSection/afterNothing);
      SecondJetmass->Draw();
            
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

      zLepton1PT->Scale(Lumi*crossSection/afterNothing);
      zLepton1PT->Draw();
      zLepton1Eta->Scale(Lumi*crossSection/afterNothing);
      zLepton1Eta->Draw();
      zLepton1phi->Scale(Lumi*crossSection/afterNothing);
      zLepton1phi->Draw();
      zLepton1mass->Scale(Lumi*crossSection/afterNothing);
      zLepton1mass->Draw();

      zLepton2PT->Scale(Lumi*crossSection/afterNothing);
      zLepton2PT->Draw();
      zLepton2Eta->Scale(Lumi*crossSection/afterNothing);
      zLepton2Eta->Draw();
      zLepton2phi->Scale(Lumi*crossSection/afterNothing);
      zLepton2phi->Draw();
      zLepton2mass->Scale(Lumi*crossSection/afterNothing);
      zLepton2mass->Draw();

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
      aplanarityhist->Draw();
      circularityhist->Draw();
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

      zLepton1PT->UseCurrentStyle();
      zLepton1PT->SetFillColor(0);
      zLepton1PT->SetLineColor(3);
      zLepton1PT->Draw("SAME");

      zLepton2PT->UseCurrentStyle();
      zLepton2PT->SetFillColor(0);
      zLepton2PT->SetLineColor(4);
      zLepton2PT->Draw("SAME");

      TLegend *leg = new TLegend(0.53,0.79,0.94,0.97);
      leg->SetFillColor(0);
      leg->SetLineColor(0);

      leg->SetShadowColor(0);
      
      leg->AddEntry(leftoverLeptonPT ,"wLeptonPT","l" ); 
      leg->AddEntry(zLepton1PT ,"zLepton1PT","l" ); 
      leg->AddEntry(zLepton2PT ,"zLepton2PT","l" ); 

      
      leg->SetTextFont(132);
      leg->SetTextSize(0.05);
      leg->Draw();
      
      TAxis *xaxis = leftoverLeptonPT->GetXaxis();
      xaxis->SetTitle("Lepton Pt (GeV)");






      //myText(0.55, 0.83, 1, Form("#int L dt = %.1f fb^{-1}",(float)lum));
      
       

      //c1->Print("Blah.pdf");

         
    }
  
  TFile outfile("histos-truth-FULL.root","recreate");

  c1->Write();

  zLepton1PT->SetLineColor(4);

  zLepton2PT->SetLineColor(3);
  
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

  LeadJetPT->Write();
  LeadJetEta->Write();
  LeadJetphi->Write();
  LeadJetmass->Write();
  
  SecondJetPT->Write();
  SecondJetEta->Write();
  SecondJetphi->Write();
  SecondJetmass->Write();
  
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

  zLepton1PT->Write();
  zLepton1Eta->Write();
  zLepton1phi->Write();
  zLepton1mass->Write();

  zLepton2PT->Write();
  zLepton2Eta->Write();
  zLepton2phi->Write();
  zLepton2mass->Write();

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
  aplanarityhist->Write();
  circularityhist->Write();
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
