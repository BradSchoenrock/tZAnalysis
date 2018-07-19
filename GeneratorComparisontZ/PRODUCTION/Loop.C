
#include "TZ_D3PD.C"
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

void Loop()
{ 
 
  TH1F *tbeforePT=new TH1F("tbeforePT","t quark before PT",40,0,400);
  TH1F *tbeforeEta=new TH1F("tbeforeEta","t quark before Eta",20,-5,5);
  TH1F *tbeforephi=new TH1F("tbeforephi","t quark before phi",16,-4,4);
  TH1F *tbeforeE=new TH1F("tbeforeE","t quark before E",40,0,1000);
  TH1F *tbeforeM=new TH1F("tbeforeM","t quark before M",40,0,1000);

  TH1F *tafterPT=new TH1F("tafterPT","t quark after PT",40,0,400);
  TH1F *tafterEta=new TH1F("tafterEta","t quark after Eta",20,-5,5);
  TH1F *tafterphi=new TH1F("tafterphi","t quark after phi",16,-4,4);
  TH1F *tafterE=new TH1F("tafterE","t quark after E",60,0,600);
  TH1F *tafterM=new TH1F("tafterM","t quark after M",40,140,200);

  TH1F *vPT=new TH1F("vPT","neutrino PT",40,0,400);
  TH1F *vEta=new TH1F("vEta","neutrino Eta",20,-5,5);
  TH1F *vphi=new TH1F("vphi","neutrino phi",16,-4,4);
  TH1F *vE=new TH1F("vE","neutrino E",40,0,400);
  TH1F *vM=new TH1F("vM","neutrino M",20,0,1);

  TH1F *bPT=new TH1F("bPT","b quark PT",40,0,400);
  TH1F *bEta=new TH1F("bEta","b quark Eta",20,-5,5);
  TH1F *bphi=new TH1F("bphi","b quark phi",16,-4,4);
  TH1F *bE=new TH1F("bE","b quark E",40,0,400);
  TH1F *bM=new TH1F("bM","b quark M",20,0,10);

  TH1F *tlPT=new TH1F("tlPT","top lepton PT",40,0,400);
  TH1F *tlEta=new TH1F("tlEta","top lepton Eta",20,-5,5);
  TH1F *tlphi=new TH1F("tlphi","top lepton phi",16,-4,4);
  TH1F *tlE=new TH1F("tlE","top lepton E",40,0,400);
  TH1F *tlM=new TH1F("tlM","top lepton M",20,0,10);

  TH1F *zl1PT=new TH1F("zl1PT","z lepton 1 PT",40,0,400);
  TH1F *zl1Eta=new TH1F("zl1Eta","z lepton 1 Eta",20,-5,5);
  TH1F *zl1phi=new TH1F("zl1phi","z lepton 1 phi",16,-4,4);
  TH1F *zl1E=new TH1F("zl1E","z lepton 1 E",40,0,400);
  TH1F *zl1M=new TH1F("zl1M","z lepton 1 M",40,0,400);

  TH1F *zl2PT=new TH1F("zl2PT","z lepton 2 PT",40,0,400);
  TH1F *zl2Eta=new TH1F("zl2Eta","z lepton 2 Eta",20,-5,5);
  TH1F *zl2phi=new TH1F("zl2phi","z lepton 2 phi",16,-4,4);
  TH1F *zl2E=new TH1F("zl2E","z lepton 2 E",40,0,400);
  TH1F *zl2M=new TH1F("zl2M","z lepton 2 M",40,0,400);

  TH1F *wPT=new TH1F("wPT","W PT",40,0,400);
  TH1F *wEta=new TH1F("wEta","W Eta",20,-5,5);
  TH1F *wphi=new TH1F("wphi","W phi",16,-4,4);
  TH1F *wE=new TH1F("wE","W E",40,0,400);
  TH1F *wM=new TH1F("wM","W M",30,0,150);

  TH1F *zPT=new TH1F("zPT","Z PT",40,0,400);
  TH1F *zEta=new TH1F("zEta","Z Eta",20,-5,5);
  TH1F *zphi=new TH1F("zphi","Z phi",16,-4,4);
  TH1F *zE=new TH1F("zE","z E",60,0,600);
  TH1F *zM=new TH1F("zM","z M",20,50,150);

  /*
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
  */
  int nEvents=5000;
  double Lumi=20.3;
  double crossSection=1.652;
  double theweight=1000*Lumi*crossSection/nEvents;
  double afterNothing=0;

  TChain * t = new TChain("truth");
  t->Add("MC12_8TeV.110491.NTUP_TRUTH.root");
  t->SetCacheSize(100000000);
 
  TZ_D3PD* event = new TZ_D3PD(t);

  //TFile *TruthFile=new TFile("unweighted_events.root");
  
  //TTree* LHEF=(TTree*)TruthFile->Get("LHEF");
  
  for(int q=0;q<nEvents;q++)
    {
      afterNothing+=theweight;
      
      t->GetEntry(q);
      
      //int nparticles = *event->(Event_Nparticles);
      //int nparticles = *event->Event_Nparticles();
      
      
      //if(q%100==0)
	cout<<"event "<<q<<'\n';

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
      
      //cout<<"nparticles "<<event->mc_n<<'\n';

      for(int i=0;i<event->mc_n;i++)
	{
	  int one=0;
	  int two=0;
	  if((*event->mc_status).at(i)==3)
	    {
	      TLorentzVector temp;
	      temp.SetPtEtaPhiE((*event->mc_pt).at(i),(*event->mc_eta).at(i),(*event->mc_phi).at(i),(*event->mc_E).at(i));
	      std::vector<int, std::allocator<int> > mc_parents=(*event->mc_parents).at(i);
	      vector<int>::iterator p = mc_parents.begin();
	      while(p!=mc_parents.end())
		{
		  //cout<<"particle status = "<< (*event->mc_status).at(i) ;
		  //cout<<" : particle parents = "<<*p;
		  //cout<<" : particle PID = " << (*event->mc_pdgId).at(i);
		  //cout<<" : temp.Pt() = " << temp.Pt()/1000;
		  //cout<<" : temp.Eta() = " << temp.Eta();
		  //cout<<" : temp.Phi() = " << temp.Phi();
		  //cout<<" : temp.E() = " << temp.E()/1000;
		  //cout<<'\n';
		  one=*p++;
		}

	      for(int j=0;j<event->mc_n;j++)
		{
		  if((*event->mc_status).at(j)==3)
		    {
		      TLorentzVector temp2;
		      temp2.SetPtEtaPhiE((*event->mc_pt).at(j),(*event->mc_eta).at(j),(*event->mc_phi).at(j),(*event->mc_E).at(j));
		      std::vector<int, std::allocator<int> > mc_parents2=(*event->mc_parents).at(j);
		      vector<int>::iterator p2 = mc_parents2.begin();
		      
		      while(p2!=mc_parents2.end())
			{
			  //cout<<" : particle parents2 = "<<*p2<<'\n';
			  two=*p2++;
			}
		      if((*event->mc_pdgId).at(i) > (*event->mc_pdgId).at(j) && (one==two))
			{
			  cout<<"found pair"<<"  "<<(*event->mc_pdgId).at(i)<<"  "<<(*event->mc_pdgId).at(j)<<"  "<<one<<"  "<<two<<'\n';

			  cout<<"found pair particle 1   "<< (*event->mc_pt).at(i)<<"  " << (*event->mc_eta).at(i)<<"  " << (*event->mc_phi).at(i)<<"  " << (*event->mc_E).at(i)<<'\n'<<"found pair particle 2   " << (*event->mc_pt).at(j)<<"  " << (*event->mc_eta).at(j)<<"  " << (*event->mc_phi).at(j)<<"  " << (*event->mc_E).at(j)<<"  " << '\n';

			  
			  if( abs((*event->mc_pdgId).at(i)) == abs((*event->mc_pdgId).at(j)) && abs((*event->mc_pdgId).at(i))>10 && abs((*event->mc_pdgId).at(i))<19)//lepton pair
			    {
			      //cout<<"hey"<<'\n';
			      TLorentzVector lep1;
			      TLorentzVector lep2;
			      if((*event->mc_pt).at(i)>(*event->mc_pt).at(j))
				{
				  lep1.SetPtEtaPhiE((*event->mc_pt).at(i)/1000,(*event->mc_eta).at(i),(*event->mc_phi).at(i),(*event->mc_E).at(i)/1000);
				  lep2.SetPtEtaPhiE((*event->mc_pt).at(j)/1000,(*event->mc_eta).at(j),(*event->mc_phi).at(j),(*event->mc_E).at(j)/1000);
				}
			      else
				{
				  lep2.SetPtEtaPhiE((*event->mc_pt).at(i),(*event->mc_eta).at(i),(*event->mc_phi).at(i),(*event->mc_E).at(i));
				  lep1.SetPtEtaPhiE((*event->mc_pt).at(j),(*event->mc_eta).at(j),(*event->mc_phi).at(j),(*event->mc_E).at(j));
				}
			      
			      TLorentzVector Z;
			      Z=lep1+lep2;

			      zl1PT->Fill(lep1.Pt(),theweight);
			      zl1Eta->Fill(lep1.Eta(),theweight);
			      zl1phi->Fill(lep1.Phi(),theweight);
			      zl1E->Fill(lep1.E(),theweight);
			      zl1M->Fill(lep1.M(),theweight);
			      zl2PT->Fill(lep2.Pt(),theweight);
			      zl2Eta->Fill(lep2.Eta(),theweight);
			      zl2phi->Fill(lep2.Phi(),theweight);
			      zl2E->Fill(lep2.E(),theweight);
			      zl2M->Fill(lep2.M(),theweight);
			      zPT->Fill(Z.Pt(),theweight);
			      zEta->Fill(Z.Eta(),theweight);
			      zphi->Fill(Z.Phi(),theweight);
			      zE->Fill(Z.E(),theweight);
			      zM->Fill(Z.M(),theweight);

			    }
			  else if(abs((*event->mc_pdgId).at(i))>10 && abs((*event->mc_pdgId).at(i))<19 && (abs((*event->mc_pdgId).at(i)) == (abs((*event->mc_pdgId).at(j)) +1) || abs((*event->mc_pdgId).at(i)) == (abs((*event->mc_pdgId).at(j)) -1) ) )//lep v pair from w
			    {//********** check if v l are switched 
			      TLorentzVector v;
			      TLorentzVector wlep;
			     
			      if(abs((*event->mc_pdgId).at(i))%2 ==0) // is even ie v
				{
				  v.SetPtEtaPhiE((*event->mc_pt).at(i)/1000,(*event->mc_eta).at(i),(*event->mc_phi).at(i),(*event->mc_E).at(i)/1000);
				  wlep.SetPtEtaPhiE((*event->mc_pt).at(j)/1000,(*event->mc_eta).at(j),(*event->mc_phi).at(j),(*event->mc_E).at(j)/1000);
				}
			      else
				{
				  wlep.SetPtEtaPhiE((*event->mc_pt).at(i)/1000,(*event->mc_eta).at(i),(*event->mc_phi).at(i),(*event->mc_E).at(i)/1000);
				  v.SetPtEtaPhiE((*event->mc_pt).at(j)/1000,(*event->mc_eta).at(j),(*event->mc_phi).at(j),(*event->mc_E).at(j)/1000);
				}


			      TLorentzVector W;
			      W=v+wlep;

			      wPT->Fill(W.Pt(),theweight);
			      wEta->Fill(W.Eta(),theweight);
			      wphi->Fill(W.Phi(),theweight);
			      wE->Fill(W.E(),theweight);
			      wM->Fill(W.M(),theweight);
			      tlPT->Fill(wlep.Pt(),theweight);
			      tlEta->Fill(wlep.Eta(),theweight);
			      tlphi->Fill(wlep.Phi(),theweight);
			      tlE->Fill(wlep.E(),theweight);
			      tlM->Fill(wlep.M(),theweight);
			      vPT->Fill(v.Pt(),theweight);
			      vEta->Fill(v.Eta(),theweight);
			      vphi->Fill(v.Phi(),theweight);
			      vE->Fill(v.E(),theweight);
			      vM->Fill(v.M(),theweight);
			    }
			  else if( (abs((*event->mc_pdgId).at(i))==24 && abs((*event->mc_pdgId).at(j))==5) || (abs((*event->mc_pdgId).at(j))==24 && abs((*event->mc_pdgId).at(i))==5) )//W b from top
			    {
			      TLorentzVector W;
			      TLorentzVector b;
			     
			      if(abs((*event->mc_pdgId).at(i))==24)
				{
				  W.SetPtEtaPhiE((*event->mc_pt).at(i)/1000,(*event->mc_eta).at(i),(*event->mc_phi).at(i),(*event->mc_E).at(i)/1000);
				  b.SetPtEtaPhiE((*event->mc_pt).at(j)/1000,(*event->mc_eta).at(j),(*event->mc_phi).at(j),(*event->mc_E).at(j)/1000);
				}
			      else if(abs((*event->mc_pdgId).at(j))==24)
				{
				  b.SetPtEtaPhiE((*event->mc_pt).at(i)/1000,(*event->mc_eta).at(i),(*event->mc_phi).at(i),(*event->mc_E).at(i)/1000);
				  W.SetPtEtaPhiE((*event->mc_pt).at(j)/1000,(*event->mc_eta).at(j),(*event->mc_phi).at(j),(*event->mc_E).at(j)/1000);
				}

			      TLorentzVector tafter;
			      tafter=W+b;

			      wPT->Fill(W.Pt(),theweight);
			      wEta->Fill(W.Eta(),theweight);
			      wphi->Fill(W.Phi(),theweight);
			      wE->Fill(W.E(),theweight);
			      wM->Fill(W.M(),theweight);
			      bPT->Fill(b.Pt(),theweight);
			      bEta->Fill(b.Eta(),theweight);
			      bphi->Fill(b.Phi(),theweight);
			      bE->Fill(b.E(),theweight);
			      bM->Fill(b.M(),theweight);
			      tafterPT->Fill(tafter.Pt(),theweight);
			      tafterEta->Fill(tafter.Eta(),theweight);
			      tafterphi->Fill(tafter.Phi(),theweight);
			      tafterE->Fill(tafter.E(),theweight);
			      tafterM->Fill(tafter.M(),theweight);
			    }
			  else if(abs((*event->mc_pdgId).at(i))==23 && abs((*event->mc_pdgId).at(j))==6)// z top from top
			    {
			      TLorentzVector Z;
			      TLorentzVector topafter;
			     
			      Z.SetPtEtaPhiE((*event->mc_pt).at(i)/1000,(*event->mc_eta).at(i),(*event->mc_phi).at(i),(*event->mc_E).at(i)/1000);
			      topafter.SetPtEtaPhiE((*event->mc_pt).at(j)/1000,(*event->mc_eta).at(j),(*event->mc_phi).at(j),(*event->mc_E).at(j)/1000);
			      
			      TLorentzVector tbefore;
			      tbefore=Z+topafter;

			      tbeforePT->Fill(tbefore.Pt(),theweight);
			      tbeforeEta->Fill(tbefore.Eta(),theweight);
			      tbeforephi->Fill(tbefore.Phi(),theweight);
			      tbeforeE->Fill(tbefore.E(),theweight);
			      tbeforeM->Fill(tbefore.M(),theweight);
			      zPT->Fill(Z.Pt(),theweight);
			      zEta->Fill(Z.Eta(),theweight);
			      zphi->Fill(Z.Phi(),theweight);
			      zE->Fill(Z.E(),theweight);
			      zM->Fill(Z.M(),theweight);
			      tafterPT->Fill(topafter.Pt(),theweight);
			      tafterEta->Fill(topafter.Eta(),theweight);
			      tafterphi->Fill(topafter.Phi(),theweight);
			      tafterE->Fill(topafter.E(),theweight);
			      tafterM->Fill(topafter.M(),theweight);
			    }
			  else
			    {
			      cout<<"found exception event!  "<<(*event->mc_pdgId).at(i)<<"  "<<(*event->mc_pdgId).at(j)<<"  "<<one<<"  "<<two<<'\n';
			    }
			}
		      

		      //cout<<" : particle parents2 = "<<*p2;
		      
		      //if(*p==*p2)
		      //{
			//cout<<"same parents";
		      //}

		      



		    }
		}
	    }
	}


	     
      // if(fabs((*event->mc_pdgId).at(i))==6)
      // {}

      //if(fabs((*event->mc_pdgId).at(i))==5)
      //    {}
      
      //  if(fabs((*event->mc_pdgId).at(i))==23)
      //    {}
      //  if(fabs((*event->mc_pdgId).at(i))==24)
      //    {}

      //  if(fabs((*event->mc_pdgId).at(i))==11)
      //    {}
      //  if(fabs((*event->mc_pdgId).at(i))==13)
      //    {}
      //  if(fabs((*event->mc_pdgId).at(i))==15)
      //    {}

      //  if(fabs((*event->mc_pdgId).at(i))==12)
      //    {}
      //  if(fabs((*event->mc_pdgId).at(i))==14)
      //    {}
      //  if(fabs((*event->mc_pdgId).at(i))==16)
      //    {}

	  // if(fabs((*event->mc_pdgId).at(i))==23)
	  //  {}
	  //if(fabs((*event->mc_pdgId).at(i))==23)
	  //  {}

      //cout<<"filling"<<'\n';
      //now we have done jet recombination and are sorted making a plot of Njets
           
      //making plots of leading and subleading jet
      
      /*
      double WTransverseMass=0;
      double TopPolHel=0;
      double TopPolOpt=0;
      double centrality=0;
      double sphericity=0;
      double aplanarity=0;
      double circularity=0;
      double WHelicity=0;
      double h=0;
      double ht=0;
      */
      //here is where i would calculate these things... 

      /*WTmass->Fill(WTransverseMass/1000,theweight);
      TopPolHB->Fill(TopPolHel,theweight);
      TopPolOB->Fill(TopPolOpt,theweight);
      centralityhist->Fill(centrality,theweight);
      sphericityhist->Fill(sphericity,theweight);
      aplanarityhist->Fill(aplanarity,theweight);
      circularityhist->Fill(circularity,theweight);
      WHel->Fill(WHelicity,theweight);
      h_hist->Fill(h,theweight);
      ht_hist->Fill(ht,theweight);
      */   
      
    }//end event loop
 
  
  tbeforePT->Scale(Lumi*crossSection/afterNothing);
  tbeforePT->Draw();
  tbeforeEta->Scale(Lumi*crossSection/afterNothing);
  tbeforeEta->Draw();
  tbeforephi->Scale(Lumi*crossSection/afterNothing);
  tbeforephi->Draw();
  tbeforeE->Scale(Lumi*crossSection/afterNothing);
  tbeforeE->Draw();
  tbeforeM->Scale(Lumi*crossSection/afterNothing);
  tbeforeM->Draw();

  tafterPT->Scale(Lumi*crossSection/afterNothing);
  tafterPT->Draw();
  tafterEta->Scale(Lumi*crossSection/afterNothing);
  tafterEta->Draw();
  tafterphi->Scale(Lumi*crossSection/afterNothing);
  tafterphi->Draw();
  tafterE->Scale(Lumi*crossSection/afterNothing);
  tafterE->Draw();
  tafterM->Scale(Lumi*crossSection/afterNothing);
  tafterM->Draw();

  bPT->Scale(Lumi*crossSection/afterNothing);
  bPT->Draw();
  bEta->Scale(Lumi*crossSection/afterNothing);
  bEta->Draw();
  bphi->Scale(Lumi*crossSection/afterNothing);
  bphi->Draw();
  bE->Scale(Lumi*crossSection/afterNothing);
  bE->Draw();
  bM->Scale(Lumi*crossSection/afterNothing);
  bM->Draw();

  tlPT->Scale(Lumi*crossSection/afterNothing);
  tlPT->Draw();
  tlEta->Scale(Lumi*crossSection/afterNothing);
  tlEta->Draw();
  tlphi->Scale(Lumi*crossSection/afterNothing);
  tlphi->Draw();
  tlE->Scale(Lumi*crossSection/afterNothing);
  tlE->Draw();
  tlM->Scale(Lumi*crossSection/afterNothing);
  tlM->Draw();
 
  zl1PT->Scale(Lumi*crossSection/afterNothing);
  zl1PT->Draw();
  zl1Eta->Scale(Lumi*crossSection/afterNothing);
  zl1Eta->Draw();
  zl1phi->Scale(Lumi*crossSection/afterNothing);
  zl1phi->Draw();
  zl1E->Scale(Lumi*crossSection/afterNothing);
  zl1E->Draw();
  zl1M->Scale(Lumi*crossSection/afterNothing);
  zl1M->Draw();

  zl2PT->Scale(Lumi*crossSection/afterNothing);
  zl2PT->Draw();
  zl2Eta->Scale(Lumi*crossSection/afterNothing);
  zl2Eta->Draw();
  zl2phi->Scale(Lumi*crossSection/afterNothing);
  zl2phi->Draw();
  zl2E->Scale(Lumi*crossSection/afterNothing);
  zl2E->Draw();
  zl2M->Scale(Lumi*crossSection/afterNothing);
  zl2M->Draw();

  vPT->Scale(Lumi*crossSection/afterNothing);
  vPT->Draw();
  vEta->Scale(Lumi*crossSection/afterNothing);
  vEta->Draw();
  vphi->Scale(Lumi*crossSection/afterNothing);
  vphi->Draw();
  vE->Scale(Lumi*crossSection/afterNothing);
  vE->Draw();
  vM->Scale(Lumi*crossSection/afterNothing);
  vM->Draw();
   
  wPT->Scale(Lumi*crossSection/afterNothing);
  wPT->Draw();
  wEta->Scale(Lumi*crossSection/afterNothing);
  wEta->Draw();
  wphi->Scale(Lumi*crossSection/afterNothing);
  wphi->Draw();
  wE->Scale(Lumi*crossSection/afterNothing);
  wE->Draw();
  wM->Scale(Lumi*crossSection/afterNothing);
  wM->Draw();

  zPT->Scale(Lumi*crossSection/afterNothing);
  zPT->Draw();
  zEta->Scale(Lumi*crossSection/afterNothing);
  zEta->Draw();
  zphi->Scale(Lumi*crossSection/afterNothing);
  zphi->Draw();
  zE->Scale(Lumi*crossSection/afterNothing);
  zE->Draw();
  zM->Scale(Lumi*crossSection/afterNothing);
  zM->Draw();
    
  //WTmass->Scale(Lumi*crossSection/afterNothing);
  //WTmass->Draw();
  
  /*
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
  */
  
  gStyle->SetOptTitle(0);
  gStyle->SetOptStat(0);
  //gStyle->SetOptStat(0);
      
 
  TFile outfile("histos-tzValidation.root","recreate");

  tbeforePT->Write();
  tbeforeEta->Write();
  tbeforephi->Write();
  tbeforeE->Write();
  tbeforeM->Write();

  tafterPT->Write();
  tafterEta->Write();
  tafterphi->Write();
  tafterE->Write();
  tafterM->Write();

  bPT->Write();
  bEta->Write();
  bphi->Write();
  bE->Write();
  bM->Write();

  tlPT->Write();
  tlEta->Write();
  tlphi->Write();
  tlE->Write();
  tlM->Write();

  zl1PT->Write();
  zl1Eta->Write();
  zl1phi->Write();
  zl1E->Write();
  zl1M->Write();

  zl2PT->Write();
  zl2Eta->Write();
  zl2phi->Write();
  zl2E->Write();
  zl2M->Write();

  vPT->Write();
  vEta->Write();
  vphi->Write();
  vE->Write();
  vM->Write();

  wPT->Write();
  wEta->Write();
  wphi->Write();
  wE->Write();
  wM->Write();

  zPT->Write();
  zEta->Write();
  zphi->Write();
  zE->Write();
  zM->Write();
 
  //WTmass->Write();

  outfile.Write();
    
  cout<<'\n'<<'\n'<<'\n';
}

int main(int argc, char **argv)
{
  argc=0;
  argv[0][0]='0';
  return 0;
}
