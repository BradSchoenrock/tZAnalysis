
//#include "TZ_D3PD.h"
#include "TruthD3PD.C"
#include <iostream>
#include <fstream> 
#include "TROOT.h"
#include "TFile.h"
#include "TTree.h"
#include "TLeaf.h"
#include "TH1.h"
#include "TH2.h"
#include "TCanvas.h"
#include "TLorentzVector.h"
#include "TString.h"
#include "Wvariables.cxx"
#include "THStack.h"
#include "TStyle.h"
#include "TLegend.h"
#include <vector>
using namespace std;

void shortloop()
{
  TCanvas *can1=new TCanvas("can1","Canvas 1",600,600);
  TH1F *testNjets=new TH1F("testNjets","testNjets",10,0,10);
  TH1F *testNlep=new TH1F("testNlep","testNlep",10,0,10);
  TH1F *testNelec=new TH1F("testNelec","testNelec",10,0,10);
  
  TCanvas *can4=new TCanvas("can4","Canvas 4",1600,600);
  TH1F *tPT=new TH1F("tPT","t quark PT",40,0,400);
  TH1F *tEta=new TH1F("tEta","t quark Eta",20,-5,5);
  TH1F *tphi=new TH1F("tphi","t quark phi",16,-4,4);

  TCanvas *can5=new TCanvas("can5","Canvas 5",1600,600);
  TH1F *bPT=new TH1F("bPT","b quark PT",40,0,400);
  TH1F *bEta=new TH1F("bEta","b quark Eta",20,-5,5);
  TH1F *bphi=new TH1F("bphi","b quark phi",16,-4,4);

  TCanvas *can7=new TCanvas("can7","Canvas 7",1600,600);
  TH1F *lPT=new TH1F("lPT","lepton PT",40,0,400);
  TH1F *lEta=new TH1F("lEta","lepton Eta",20,-5,5);
  TH1F *lphi=new TH1F("lphi","lepton phi",16,-4,4);

  TCanvas *can8=new TCanvas("can8","Canvas 8",1600,600);
  TH1F *vPT=new TH1F("vPT","neutrino PT",40,0,400);
  TH1F *vEta=new TH1F("vEta","neutrino Eta",20,-5,5);
  TH1F *vphi=new TH1F("vphi","neutrino phi",16,-4,4);

  TCanvas *can9=new TCanvas("can9","Canvas 9",1600,600);
  TH1F *wPT=new TH1F("wPT","W PT",40,0,400);
  TH1F *wEta=new TH1F("wEta","W Eta",20,-5,5);
  TH1F *wphi=new TH1F("wphi","W phi",16,-4,4);

  TCanvas *can18=new TCanvas("can18","Canvas 18",1600,600);
  TH1F *zPT=new TH1F("zPT","Z PT",40,0,400);
  TH1F *zEta=new TH1F("zEta","Z Eta",20,-5,5);
  TH1F *zphi=new TH1F("zphi","Z phi",16,-4,4);

  TCanvas *can11=new TCanvas("can11","Canvas 11",1600,600);
  TH1F *BJetPT=new TH1F("BJetPT","BJet PT",40,0,400);
  TH1F *BJetEta=new TH1F("BJetEta","BJet Eta",20,-5,5);
  TH1F *BJetphi=new TH1F("BJetphi","BJet phi",16,-4,4);
  TH1F *BJetmass=new TH1F("BJetmass","BJet mass",100,0,50);

  TCanvas *can12=new TCanvas("can12","Canvas 12",1600,600);
  TH1F *nonBJetPT=new TH1F("nonBJetPT","nonBJet PT",40,0,400);
  TH1F *nonBJetEta=new TH1F("nonBJetEta","nonBJet Eta",20,-5,5);
  TH1F *nonBJetphi=new TH1F("nonBJetphi","nonBJet phi",16,-4,4);
  TH1F *nonBJetmass=new TH1F("nonBJetmass","nonBJet mass",100,0,50);

  TCanvas *can14=new TCanvas("can14","Canvas 14",1600,600);
  TH1F *MET_PT=new TH1F("recovPT","MET PT",25,0,250);
  TH1F *MET_Eta=new TH1F("recovEta","MET Eta",20,-5,5);
  TH1F *MET_phi=new TH1F("recovphi","MET phi",16,-4,4);
  TH1F *MET_pz=new TH1F("recovpz","MET pz",100,-350,350);

  TCanvas *can15=new TCanvas("can15","Canvas 15",1600,600);
  TH1F *lepton1PT=new TH1F("lepton1PT","lepton1 PT",25,0,250);
  TH1F *lepton1Eta=new TH1F("lepton1Eta","lepton1 Eta",20,-5,5);
  TH1F *lepton1phi=new TH1F("lepton1phi","lepton1 phi",16,-4,4);
  TH1F *lepton1mass=new TH1F("lepton1mass","lepton1 mass",100,0,2);

  TCanvas *can16=new TCanvas("can16","Canvas 16",1600,600);
  TH1F *recoWPT=new TH1F("recoWPT","recoW PT",40,0,400);
  TH1F *recoWEta=new TH1F("recoWEta","recoW Eta",20,-5,5);
  TH1F *recoWphi=new TH1F("recoWphi","recoW phi",16,-4,4);
  TH1F *recoWmass=new TH1F("recoWmass","recoW mass",1000,80,80.8);

  TCanvas *can17=new TCanvas("can17","Canvas 17",1600,600);
  TH1F *recotopPT=new TH1F("recotopPT","recotop PT",40,0,400);
  TH1F *recotopEta=new TH1F("recotopEta","recotop Eta",20,-5,5);
  TH1F *recotopphi=new TH1F("recotopphi","recotop phi",16,-4,4);
  TH1F *recotopmass=new TH1F("recotopmass","recotop mass",200,140,210);

  TCanvas *can19=new TCanvas("can19","Canvas 19",1600,600);
  TH1F *recoZPT=new TH1F("recoZPT","recoZ PT",40,0,400);
  TH1F *recoZEta=new TH1F("recoZEta","recoZ Eta",20,-5,5);
  TH1F *recoZphi=new TH1F("recoZphi","recoZ phi",16,-4,4);
  TH1F *recoZmass=new TH1F("recoZmass","recoZ mass",1000,0,200);

  TCanvas *can20=new TCanvas("can20","Canvas 20",1600,600);
  TH1F *lepton2PT=new TH1F("lepton2PT","lepton2 PT",25,0,250);
  TH1F *lepton2Eta=new TH1F("lepton2Eta","lepton2 Eta",20,-5,5);
  TH1F *lepton2phi=new TH1F("lepton2phi","lepton2 phi",16,-4,4);
  TH1F *lepton2mass=new TH1F("lepton2mass","lepton2 mass",100,0,2);

  TCanvas *can21=new TCanvas("can21","Canvas 21",1600,600);
  TH1F *lepton3PT=new TH1F("lepton3PT","lepton3 PT",25,0,250);
  TH1F *lepton3Eta=new TH1F("lepton3Eta","lepton3 Eta",20,-5,5);
  TH1F *lepton3phi=new TH1F("lepton3phi","lepton3 phi",16,-4,4);
  TH1F *lepton3mass=new TH1F("lepton3mass","lepton3 mass",100,0,2);

  TCanvas *can22=new TCanvas("can22","Canvas 22",1600,600);
  TH1F *leftoverLeptonPT=new TH1F("leftoverLeptonPT","leftoverLepton PT",25,0,250);
  TH1F *leftoverLeptonEta=new TH1F("leftoverLeptonEta","leftoverLepton Eta",20,-5,5);
  TH1F *leftoverLeptonphi=new TH1F("leftoverLeptonphi","leftoverLepton phi",16,-4,4);
  TH1F *leftoverLeptonmass=new TH1F("leftoverLeptonmass","leftoverLepton mass",100,0,2);

  TCanvas *can23=new TCanvas("can23","Canvas 23",1600,600);
  TH1F *zLeptonPT=new TH1F("zLeptonPT","zLepton PT",25,0,250);
  TH1F *zLeptonEta=new TH1F("zLeptonEta","zLepton Eta",20,-5,5);
  TH1F *zLeptonphi=new TH1F("zLeptonphi","zLepton phi",16,-4,4);
  TH1F *zLeptonmass=new TH1F("zLeptonmass","zLepton mass",100,0,2);

  TCanvas *can24=new TCanvas("can24","Canvas 24",1600,600);
  TH1F *zAntiLeptonPT=new TH1F("zAntiLeptonPT","zAntiLepton PT",25,0,250);
  TH1F *zAntiLeptonEta=new TH1F("zAntiLeptonEta","zAntiLepton Eta",20,-5,5);
  TH1F *zAntiLeptonphi=new TH1F("zAntiLeptonphi","zAntiLepton phi",16,-4,4);
  TH1F *zAntiLeptonmass=new TH1F("zAntiLeptonmass","zAntiLepton mass",100,0,2);

  TH1F *WTmass=new TH1F("WTmass","WTransversemass",250,0,250);



  double afterNlep=0;
  double afterjetQ=0;
  double afterBjet=0;
  double afterMET=0;
  double totalPassed=0;
  double afterNothing=0;





  int nEvents=10000;
  double Lumi=20.3;
  double crossSection=1.652;
  double theweight=1000*Lumi*crossSection/nEvents;

  TChain * t = new TChain("LHEF");
  t->Add("/home/schoenr1/work/RecoTopAlgorithm/unweighted_events.root");
  t->SetCacheSize(100000000);
  TruthD3PD* event = new TruthD3PD(t);
  

  //TFile *TruthFile=new TFile("unweighted_events.root");

  //TTree* LHEF=(TTree*)TruthFile->Get("LHEF");

  for(int q=0;q<nEvents;q++)
    {
      afterNothing+=theweight;
      
      t->GetEntry(q);
      
      //int nparticles = *event->(Event_Nparticles);
      int nparticles = *event->Event_Nparticles;


      if(q%100==0)
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
      vector<bool> isb;
      vector<TLorentzVector> lepton;
      vector<int> lcharge;
      vector<int> ltype;
      vector<int> isZ;
      //int nelec=0;
 
      bool eventSel=true;//this holds my event selection stuff
     
      for(int i=0;i<nparticles;i++)//particle loop fills basic histograms
	{
	  //int PID=(int)LHEF->GetLeaf("Particle.PID")->GetValue(i);
	  //double pt=LHEF->GetLeaf("Particle.PT")->GetValue(i);
	  //double eta=LHEF->GetLeaf("Particle.Eta")->GetValue(i);
	  //double phi=LHEF->GetLeaf("Particle.Phi")->GetValue(i);
	  //double E=LHEF->GetLeaf("Particle.E")->GetValue(i);
	  //int status=(int)LHEF->GetLeaf("Particle.Status")->GetValue(i);
	  int PID=event->Particle_PID[i];
	  double pt=event->Particle_PT[i];
	  double eta=event->Particle_Eta[i];
	  double phi=event->Particle_Phi[i];
	  double E=event->Particle_E[i];
	  int status=(int)event->Particle_Status[i];
	  //cout<<"PID="<<PID<<'\n'<<"pt="<<pt<<'\n'<<"eta="<<eta<<'\n'<<"phi="<<phi<<'\n'<<"E="<<E<<'\n'<<"status="<<status<<'\n';
	  
	  if(abs(PID)==11 || abs(PID)==13)
	    {
	      lPT->Fill(pt,theweight);
	      lEta->Fill(eta,theweight);
	      lphi->Fill(phi,theweight);
	      TLorentzVector temp;
	      temp.SetPtEtaPhiE(pt,eta,phi,E);
	      lepton.push_back(temp);
	      if(PID > 0)
		lcharge.push_back(-1);
	      else
		lcharge.push_back(1);
	      if(abs(PID)==11)
		{
		  //nelec++;
		  ltype.push_back(1);
		}
	      else if(abs(PID)==13)
		ltype.push_back(2);
	      isZ.push_back((int)event->Particle_Mother1[i]);
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
		  if(abs(PID)==5)
		    isb.push_back(true);
		  else
		    isb.push_back(false);
		  //cout<<PID<<"filling jet["<<njets<<"].Pt="<<jet[njets].Pt()<<'\n';
		}
	    }

	}

     
      //cout<<"hey"<<'\n';

      if(lepton.size()!=3)
	eventSel=false;

      if(eventSel)
     	afterNlep+=theweight;

 
      if(eventSel)
	{
	  double maxpt=0;
	  int place=-1;
	  for(unsigned int v=0;v<lepton.size();v++)
	    {
	      if( (lepton.at(v)).Pt()>maxpt)
		{
		  maxpt=(lepton.at(v)).Pt();
		  place=v;
		}
	    }
	  assert(place>=0);
	  if(place!=0)
	    {
	      TLorentzVector temp=lepton.at(place);
	      lepton.at(place)=lepton.at(0);
	      lepton.at(0)=temp;
	      int tempi=lcharge.at(place);
	      lcharge.at(place)=lcharge.at(0);
	      lcharge.at(0)=tempi;
	      int tempt=ltype.at(place);
	      ltype.at(place)=ltype.at(0);
	      ltype.at(0)=tempt;
	      int tempq=isZ.at(place);
	      isZ.at(place)=isZ.at(0);
	      isZ.at(0)=tempq;
	    }
	  if( (lepton.at(1)).Pt() < (lepton.at(2)).Pt() )
	    {
	      TLorentzVector temp=lepton.at(1);
	      lepton.at(1)=lepton.at(2);
	      lepton.at(2)=temp;
	      int tempi=lcharge.at(1);
	      lcharge.at(1)=lcharge.at(2);
	      lcharge.at(2)=tempi;
	      int tempt=ltype.at(1);
	      ltype.at(1)=ltype.at(2);
	      ltype.at(2)=tempt;
	      int tempq=isZ.at(1);
	      isZ.at(1)=isZ.at(2);
	      isZ.at(2)=tempq;
	    }
	  //cout<<"leptons sorted"<<'\n';
	}

      //cout<<"listen"<<'\n';
       
      if(jet.size()<1)
      	eventSel=false;
      
      if(eventSel)
	{
	  //cout<<"passed lepton and neutrino_ requirements!"<<'\n';
	  
	  for(unsigned int c=0;c<jet.size()-1;c++)//sorts jets with isb information
	    {
	      for(unsigned int d=c+1;d<jet.size();d++)
		{
		  if( (jet.at(c)).Pt()< (jet.at(d)).Pt())
		    {
		      TLorentzVector temp=jet.at(c);
		      jet.at(d)=jet.at(c);
		      jet.at(c)=temp;
		      int tempi=isb.at(c);
		      isb.at(c)=isb.at(d);
		      isb.at(d)=tempi;
		    }
		}
	    }
	}

      //cout<<"hey"<<'\n';

      if(jet.size()==0)
      	eventSel=false;

      if(eventSel)
	afterjetQ+=theweight;

      if(eventSel)
	afterBjet+=theweight;
            
           	       
      if(eventSel)//MET requirements
	{
	  for(int y=0;y<nparticles;y++)
	    {
	      int status=(int)event->Particle_Status[y];
	      int PID=(int)event->Particle_PID[y];

	      
	      if(status==1 && (PID==9 || PID==21 || (PID<=6 && PID>=-6 && PID!=0) || PID==11 || PID==-11 || PID==13 || PID==-13) )
		{
		  double pt=event->Particle_PT[y];
		  double eta=event->Particle_Eta[y];
		  double phi=event->Particle_Phi[y];
		  double E=event->Particle_E[y];

		  TLorentzVector temp = NegMET;
		  TLorentzVector temp2;
		  temp2.SetPtEtaPhiE(pt,eta,phi,E);
		  NegMET=temp+temp2;
		}
	    }
	}
      
      if(eventSel)
	afterMET+=theweight;
      
      TLorentzVector leftoverLepton;
      TLorentzVector zLepton;
      TLorentzVector zAntiLepton;

      


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

	  bool correctzlep=true;

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
		      if(lcharge.at(u)==-1)
			zLepton=lepton.at(u);
		      else
			{
			  assert(lcharge.at(u)==1);
			  zAntiLepton=lepton.at(u);
			}
		      if(isZ.at(u)!=5 && isZ.at(u)!=1)
			correctzlep=false;
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
		      if(lcharge.at(u)==-1)
			zLepton=lepton.at(u);
		      else
			{
			  assert(lcharge.at(u)==1);
			  zAntiLepton=lepton.at(u);
			}
		      if(isZ.at(u)!=5 && isZ.at(u)!=1)
			correctzlep=false;
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
	      //cout<<"correctZlep="<<correctzlep<<'\n';
	      //cout<<"isZ.at(0)="<<isZ.at(0)<<"isZ.at(1)="<<isZ.at(1)<<"isZ.at(2)="<<isZ.at(2)<<'\n';
	      if(lcharge.at(0)!=lcharge.at(1))
		{
		  temp=lepton.at(0)+lepton.at(1);
		  if(zFourVec.M()==0 || fabs(temp.M()-91.1) < fabs(zFourVec.M()-91.1) )
		    {
		      //cout<<"in01"<<'\n';
		      zFourVec=temp;
		      setz=true;
		      if(lcharge.at(0)==-1)
			{
			  zLepton=lepton.at(0);
			  zAntiLepton=lepton.at(1);
			}
		      else
			{
			  assert(lcharge.at(0)==1);
			  zLepton=lepton.at(1);
			  zAntiLepton=lepton.at(0);
			}
		      if( (isZ.at(0)!=5  && isZ.at(0)!=1) || (isZ.at(1)!=5 && isZ.at(1)!=1) )
			correctzlep=false;
		      else
			correctzlep=true;
		      leftoverLepton=lepton.at(2);
		    }
		}
	      //cout<<"zmass="<<zFourVec.M()<<'\n';
	      //cout<<"correctZlep="<<correctzlep<<'\n';
	      if(lcharge.at(0)!=lcharge.at(2))
		{
		  temp=lepton.at(0)+lepton.at(2);
		  if(zFourVec.M()==0 ||  fabs(temp.M()-91.1) < fabs(zFourVec.M()-91.1) )
		    {
		      //cout<<"in02"<<'\n';
		      zFourVec=temp;
		      setz=true;
		      if(lcharge.at(0)==-1)
			{
			  zLepton=lepton.at(0);
			  zAntiLepton=lepton.at(2);
			}
		      else
			{
			  assert(lcharge.at(0)==1);
			  zLepton=lepton.at(2);
			  zAntiLepton=lepton.at(0);
			}
		      if((isZ.at(0)!=5  && isZ.at(0)!=1) || (isZ.at(2)!=5 && isZ.at(2)!=1))
			correctzlep=false;
		      else
			correctzlep=true;
		      leftoverLepton=lepton.at(1);
		    }
		}
	      //cout<<"zmass="<<zFourVec.M()<<'\n';
	      //cout<<"correctZlep="<<correctzlep<<'\n';
	      if(lcharge.at(1)!=lcharge.at(2))
		{
		  temp=lepton.at(1)+lepton.at(2);
		  if(zFourVec.M()==0 ||  fabs(temp.M()-91.1) < fabs(zFourVec.M()-91.1) )
		    {
		      //cout<<"in12"<<'\n';
		      zFourVec=temp;
		      setz=true;
		      if(lcharge.at(1)==-1)
			{
			  zLepton=lepton.at(1);
			  zAntiLepton=lepton.at(2);
			}
		      else
			{
			  assert(lcharge.at(1)==1);
			  zLepton=lepton.at(2);
			  zAntiLepton=lepton.at(1);
			}
		      if((isZ.at(1)!=5  && isZ.at(1)!=1) || (isZ.at(2)!=5 && isZ.at(2)!=1))
			correctzlep=false;
		      else
			correctzlep=true;
		      leftoverLepton=lepton.at(0);
		    }
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
	  
	  if(isb.at(0))
	    tFourVec=wFourVec+jet.at(0);
	  else if(isb.at(1))
	    tFourVec=wFourVec+jet.at(1);
	  

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
	      assert(isb.size()==2);
	      int nbjets=0;
	      if(isb.at(0)==true)nbjets++;
	      if(isb.at(1)==true)nbjets++;
	      
	      //assert(nbjets==1);
	      
	      if(isb.at(0))
		{
		  BJetPT->Fill((jet.at(0)).Pt(),theweight);
		  BJetEta->Fill((jet.at(0)).Eta(),theweight);
		  BJetphi->Fill((jet.at(0)).Phi(),theweight);
		  BJetmass->Fill((jet.at(0)).M(),theweight);
		  
		  nonBJetPT->Fill((jet.at(1)).Pt(),theweight);
		  nonBJetEta->Fill((jet.at(1)).Eta(),theweight);
		  nonBJetphi->Fill((jet.at(1)).Phi(),theweight);
		  nonBJetmass->Fill((jet.at(1)).M(),theweight);
		}
	      else if(isb.at(1))
		{
		  BJetPT->Fill((jet.at(1)).Pt(),theweight);
		  BJetEta->Fill((jet.at(1)).Eta(),theweight);
		  BJetphi->Fill((jet.at(1)).Phi(),theweight);
		  BJetmass->Fill((jet.at(1)).M(),theweight);
		  
		  nonBJetPT->Fill((jet.at(0)).Pt(),theweight);
		  nonBJetEta->Fill((jet.at(0)).Eta(),theweight);
		  nonBJetphi->Fill((jet.at(0)).Phi(),theweight);
		  nonBJetmass->Fill((jet.at(0)).M(),theweight);
		}
	      
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

	      leftoverLeptonPT->Fill(leftoverLepton.Pt(),theweight);
	      leftoverLeptonEta->Fill(leftoverLepton.Eta(),theweight);
	      leftoverLeptonphi->Fill(leftoverLepton.Phi(),theweight);
	      leftoverLeptonmass->Fill(leftoverLepton.M(),theweight);

	      zLeptonPT->Fill(zLepton.Pt(),theweight);
	      zLeptonEta->Fill(zLepton.Eta(),theweight);
	      zLeptonphi->Fill(zLepton.Phi(),theweight);
	      zLeptonmass->Fill(zLepton.M(),theweight);

	      zAntiLeptonPT->Fill(zAntiLepton.Pt(),theweight);
	      zAntiLeptonEta->Fill(zAntiLepton.Eta(),theweight);
	      zAntiLeptonphi->Fill(zAntiLepton.Phi(),theweight);
	      zAntiLeptonmass->Fill(zAntiLepton.M(),theweight);
	      
	      //cout<<"zLeptonPt"<<zLepton.Pt()<<'\n';
	      //cout<<"zAntiLeptonPt"<<zAntiLepton.Pt()<<'\n';

	      //making plots for reco objects
	      recoZPT->Fill(zFourVec.Pt(),theweight);
	      recoZEta->Fill(zFourVec.Eta(),theweight);
	      recoZphi->Fill(zFourVec.Phi(),theweight);
	      recoZmass->Fill(zFourVec.M(),theweight);

	      MET_PT->Fill(MET.Pt(),theweight);
	      MET_Eta->Fill(MET.Eta(),theweight);
	      MET_phi->Fill(MET.Phi(),theweight);
	      MET_pz->Fill(MET.Pz() ,theweight);

	      recoWPT->Fill(wFourVec.Pt(),theweight);
	      recoWEta->Fill(wFourVec.Eta(),theweight);
	      recoWphi->Fill(wFourVec.Phi(),theweight);
	      recoWmass->Fill(wFourVec.M(),theweight);
	      
	      recotopPT->Fill(tFourVec.Pt(),theweight);
	      recotopEta->Fill(tFourVec.Eta(),theweight);
	      recotopphi->Fill(tFourVec.Phi(),theweight);
	      recotopmass->Fill(tFourVec.M(),theweight);

	      assert(WTransverseMass>0);

	      WTmass->Fill(WTransverseMass,theweight);


	      totalPassed+=theweight;
	    }
	  //cout<<"end"<<'\n';
	}
      
    }
  
  cout<<'\n'<<"afterNothing="<<afterNothing<<'\n'<<"afterNlep="<<afterNlep<<'\n'<<"afterJetQ="<<afterjetQ<<'\n'<<"afterMET="<<afterMET<<'\n'<<"totalPassed="<<totalPassed<<'\n'<<'\n'<<'\n'<<'\n';

  TCanvas *c1 = new TCanvas("c1","c1",560,720);
  if(true)//totalPassed>0)
    {
      can4->Divide(3,1);
      can5->Divide(3,1);  
      can7->Divide(3,1); 
      can8->Divide(3,1);
      can9->Divide(3,1);
      can18->Divide(3,1);
	    
      can11->Divide(4,1);
      can12->Divide(4,1);
      can14->Divide(4,1);
      can15->Divide(4,1);
      can16->Divide(4,1);
      can17->Divide(4,1);
      can20->Divide(4,1);
      can21->Divide(4,1);
      can22->Divide(4,1);
      can23->Divide(4,1);
      can24->Divide(4,1);

      
      can1->cd();
      testNjets->Draw();
      testNjets->Scale(Lumi*crossSection/afterNothing);
      testNlep->Draw();
      testNlep->Scale(Lumi*crossSection/afterNothing);
      testNelec->Draw();
      testNelec->Scale(Lumi*crossSection/afterNothing);

      can4->cd(1);
      tPT->Scale(Lumi*crossSection/afterNothing);
      tPT->Draw();
      can4->cd(2);
      tEta->Scale(Lumi*crossSection/afterNothing);
      tEta->Draw();
      can4->cd(3);
      tphi->Scale(Lumi*crossSection/afterNothing);
      tphi->Draw();
      
      can5->cd(1);
      bPT->Scale(Lumi*crossSection/afterNothing);
      bPT->Draw();
      can5->cd(2);
      bEta->Scale(Lumi*crossSection/afterNothing);
      bEta->Draw();
      can5->cd(3);
      bphi->Scale(Lumi*crossSection/afterNothing);
      bphi->Draw();
      
      can7->cd(1);
      lPT->Scale(Lumi*crossSection/afterNothing);
      lPT->Draw();
      can7->cd(2);
      lEta->Scale(Lumi*crossSection/afterNothing);
      lEta->Draw();
      can7->cd(3);
      lphi->Scale(Lumi*crossSection/afterNothing);
      lphi->Draw();
      
      can8->cd(1);
      vPT->Scale(Lumi*crossSection/afterNothing);
      vPT->Draw();
      can8->cd(2);
      vEta->Scale(Lumi*crossSection/afterNothing);
      vEta->Draw();
      can8->cd(3);
      vphi->Scale(Lumi*crossSection/afterNothing);
      vphi->Draw();
      
      can9->cd(1);
      wPT->Scale(Lumi*crossSection/afterNothing);
      wPT->Draw();
      can9->cd(2);
      wEta->Scale(Lumi*crossSection/afterNothing);
      wEta->Draw();
      can9->cd(3);
      wphi->Scale(Lumi*crossSection/afterNothing);
      wphi->Draw();
      
      can18->cd(1);
      zPT->Scale(Lumi*crossSection/afterNothing);
      zPT->Draw();
      can18->cd(2);
      zEta->Scale(Lumi*crossSection/afterNothing);
      zEta->Draw();
      can18->cd(3);
      zphi->Scale(Lumi*crossSection/afterNothing);
      zphi->Draw();

          
      can11->cd(1);
      BJetPT->Scale(Lumi*crossSection/afterNothing);
      BJetPT->Draw();
      can11->cd(2);
      BJetEta->Scale(Lumi*crossSection/afterNothing);
      BJetEta->Draw();
      can11->cd(3);
      BJetphi->Scale(Lumi*crossSection/afterNothing);
      BJetphi->Draw();
      can11->cd(4);
      BJetmass->Scale(Lumi*crossSection/afterNothing);
      BJetmass->Draw();
      
      can12->cd(1);
      nonBJetPT->Scale(Lumi*crossSection/afterNothing);
      nonBJetPT->Draw();
      can12->cd(2);
      nonBJetEta->Scale(Lumi*crossSection/afterNothing);
      nonBJetEta->Draw();
      can12->cd(3);
      nonBJetphi->Scale(Lumi*crossSection/afterNothing);
      nonBJetphi->Draw();
      can12->cd(4);
      nonBJetmass->Scale(Lumi*crossSection/afterNothing);
      nonBJetmass->Draw();
            
      can14->cd(1);
      MET_PT->Scale(Lumi*crossSection/afterNothing);
      MET_PT->Draw();
      can14->cd(2);
      MET_Eta->Scale(Lumi*crossSection/afterNothing);
      MET_Eta->Draw();
      can14->cd(3);
      MET_phi->Scale(Lumi*crossSection/afterNothing);
      MET_phi->Draw();
      can14->cd(4);
      MET_pz->Scale(Lumi*crossSection/afterNothing);
      MET_pz->Draw();
      
      can15->cd(1);
      lepton1PT->Scale(Lumi*crossSection/afterNothing);
      lepton1PT->Draw();
      can15->cd(2);
      lepton1Eta->Scale(Lumi*crossSection/afterNothing);
      lepton1Eta->Draw();
      can15->cd(3);
      lepton1phi->Scale(Lumi*crossSection/afterNothing);
      lepton1phi->Draw();
      can15->cd(4);
      lepton1mass->Scale(Lumi*crossSection/afterNothing);
      lepton1mass->Draw();
      
      can16->cd(1);
      recoWPT->Scale(Lumi*crossSection/afterNothing);
      recoWPT->Draw();
      can16->cd(2);
      recoWEta->Scale(Lumi*crossSection/afterNothing);
      recoWEta->Draw();
      can16->cd(3);
      recoWphi->Scale(Lumi*crossSection/afterNothing);
      recoWphi->Draw();
      can16->cd(4);
      recoWmass->Scale(Lumi*crossSection/afterNothing);
      recoWmass->Draw();

      can19->cd(1);
      recoZPT->Scale(Lumi*crossSection/afterNothing);
      recoZPT->Draw();
      can19->cd(2);
      recoZEta->Scale(Lumi*crossSection/afterNothing);
      recoZEta->Draw();
      can19->cd(3);
      recoZphi->Scale(Lumi*crossSection/afterNothing);
      recoZphi->Draw();
      can19->cd(4);
      recoZmass->Scale(Lumi*crossSection/afterNothing);
      recoZmass->Draw();
      
      can17->cd(1);
      recotopPT->Scale(Lumi*crossSection/afterNothing);
      recotopPT->Draw();
      can17->cd(2);
      recotopEta->Scale(Lumi*crossSection/afterNothing);
      recotopEta->Draw();
      can17->cd(3);
      recotopphi->Scale(Lumi*crossSection/afterNothing);
      recotopphi->Draw();
      can17->cd(4);
      recotopmass->Scale(Lumi*crossSection/afterNothing);
      recotopmass->Draw();

      can20->cd(1);
      lepton2PT->Scale(Lumi*crossSection/afterNothing);
      lepton2PT->Draw();
      can20->cd(2);
      lepton2Eta->Scale(Lumi*crossSection/afterNothing);
      lepton2Eta->Draw();
      can20->cd(3);
      lepton2phi->Scale(Lumi*crossSection/afterNothing);
      lepton2phi->Draw();
      can20->cd(4);
      lepton2mass->Scale(Lumi*crossSection/afterNothing);
      lepton2mass->Draw();
      
      can21->cd(1);
      lepton3PT->Scale(Lumi*crossSection/afterNothing);
      lepton3PT->Draw();
      can21->cd(2);
      lepton3Eta->Scale(Lumi*crossSection/afterNothing);
      lepton3Eta->Draw();
      can21->cd(3);
      lepton3phi->Scale(Lumi*crossSection/afterNothing);
      lepton3phi->Draw();
      can21->cd(4);
      lepton3mass->Scale(Lumi*crossSection/afterNothing);
      lepton3mass->Draw();

      can22->cd(1);
      leftoverLeptonPT->Scale(Lumi*crossSection/afterNothing);
      leftoverLeptonPT->Draw();
      can22->cd(2);
      leftoverLeptonEta->Scale(Lumi*crossSection/afterNothing);
      leftoverLeptonEta->Draw();
      can22->cd(3);
      leftoverLeptonphi->Scale(Lumi*crossSection/afterNothing);
      leftoverLeptonphi->Draw();
      can22->cd(4);
      leftoverLeptonmass->Scale(Lumi*crossSection/afterNothing);
      leftoverLeptonmass->Draw();

      can23->cd(1);
      zLeptonPT->Scale(Lumi*crossSection/afterNothing);
      zLeptonPT->Draw();
      can23->cd(2);
      zLeptonEta->Scale(Lumi*crossSection/afterNothing);
      zLeptonEta->Draw();
      can23->cd(3);
      zLeptonphi->Scale(Lumi*crossSection/afterNothing);
      zLeptonphi->Draw();
      can23->cd(4);
      zLeptonmass->Scale(Lumi*crossSection/afterNothing);
      zLeptonmass->Draw();

      can24->cd(1);
      zAntiLeptonPT->Scale(Lumi*crossSection/afterNothing);
      zAntiLeptonPT->Draw();
      can24->cd(2);
      zAntiLeptonEta->Scale(Lumi*crossSection/afterNothing);
      zAntiLeptonEta->Draw();
      can24->cd(3);
      zAntiLeptonphi->Scale(Lumi*crossSection/afterNothing);
      zAntiLeptonphi->Draw();
      can24->cd(4);
      zAntiLeptonmass->Scale(Lumi*crossSection/afterNothing);
      zAntiLeptonmass->Draw();

      WTmass->Scale(Lumi*crossSection/afterNothing);
      WTmass->Draw();

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
  
  TFile outfile("histos-truth-tZ.root","recreate");

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

  outfile.Write();
    
  cout<<'\n'<<'\n'<<'\n';
}


int main(int argc, char **argv)
{
  argc=0;
  argv[0][0]='0';
  return 0;
}
