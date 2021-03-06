#include "TopD3PD.C"
#include "DataD3PD.C"
//#include "Wvariables.cxx"
//#include "TopPolarization.C"
//#include "KinematicUtils.cxx"

typedef TopD3PD MCD3PDEvent;
typedef DataD3PD DataD3PDEvent;


void MySort(vector<TLorentzVector>& vec, vector<int>& num)//sorts vectors of objects by pt with an adjoining value. currently num is used for lep charge type using pythia particle codes. bubble sort will become ineficient if vec.size starts to get large. 
{
  assert(vec.size()==num.size());
  
  for(unsigned int i=0;i<vec.size();i++)
    for(unsigned int j=i+1;j<vec.size();j++)
      if( (vec.at(j)).Pt() > (vec.at(i)).Pt() )
	{
	  TLorentzVector tempvec = vec.at(i);
	  vec.at(i)=vec.at(j);
	  vec.at(j)=tempvec;
	  int tempnum=num.at(i);
	  num.at(i)=num.at(j);
	  num.at(j)=tempnum;
	}
  return; 
}

void MySort(vector<TLorentzVector>& vec, vector<double>& num)//overloaded to take double instead of int. This is used for jets
{
  assert(vec.size()==num.size());
  
  for(unsigned int i=0;i<vec.size();i++)
    for(unsigned int j=i+1;j<vec.size();j++)
      if( (vec.at(j)).Pt() > (vec.at(i)).Pt() )
	{
	  TLorentzVector tempvec = vec.at(i);
	  vec.at(i)=vec.at(j);
	  vec.at(j)=tempvec;
	  double tempnum=num.at(i);
	  num.at(i)=num.at(j);
	  num.at(j)=tempnum;
	}
  return; 
}


void Loop(TChain *ch, double lumi, float xsec, hist_struct *thestruct, bool isData) {
  //cout<<"before"<<'\n';
    
  // cout<<"ch->GetEntries()="<<ch->GetEntries()<<'\n';

  // cout<<"ch = " << ch << '\n';
  
  double minLepPt=10;
  double minJetPt=25;
  double maxJetEta=4.5;
  double MVscore=-0.7887;

  float weight=1;
  if(!isData)
    weight= (lumi*1000*xsec);//the scale factor is missing / by number of entries, that must be done after the entire sample is compiled into one histogram. 
  double theweight=weight;
  

  //for (unsigned int ientry = 0; ientry < 10; ientry++) {
  for (unsigned int ientry = 0; ientry < ch->GetEntries(); ientry++) {
      
    bool debug=false;
  
    //cout<<"start"<<'\n';

    weight=theweight;//when an event fails a cut, weight is set to 0. this resets it for each event. 
    
    double MCSF=1;
    double pileupSF=1;
    double leptonSF=1;
    double bTagSF=1;
  
    if (ientry % 1000 == 0) 
      cout << " ientry = " << ientry << " out of " << ch->GetEntries() << endl;
    
    //********************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************

    //cout<<"end basic test"<<'\n';
   
    double MET=0;
    double METphi=0;
    
    vector<TLorentzVector> lepvecs;
    vector<int> leptype;
    vector<TLorentzVector> elvecs;
    vector<int> elcharge;
    vector<TLorentzVector> muvecs;
    vector<int> mucharge;
   
    vector<TLorentzVector> jetvecs;
    vector<double> mv1;



    //^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

    if(!isData)
      {
	
    	MCD3PDEvent* MCevent = new MCD3PDEvent(ch);
	
	ch->GetEntry(ientry);

	MCSF=(MCevent->weight_mc);
	//pileupSF=1;//(MCevent->weight_pileup);
	pileupSF=(MCevent->weight_pileup);
	leptonSF=(MCevent->weight_leptonSF);
	bTagSF=(MCevent->weight_bTagSF_85);
	//bTagSF=(MCevent->weight_bTagSF_77);
	weight=weight*MCSF*pileupSF*leptonSF*bTagSF;
	
	//if( fabs(MCSF) > 20) 
	//weight=0;

	/*
	  if(weight!=0 && MCSF*pileupSF*leptonSF*bTagSF>2 )
	  {
	  cout<<"****************"<<'\n';
	  cout<<"lumi="<<lumi<<'\n';
	  cout<<"xsec="<<xsec<<'\n';
	  cout<<"MCSF="<<MCSF<<'\n';
	  cout<<"pileupSF="<<pileupSF<<'\n';
	  cout<<"leptonSF="<<leptonSF<<'\n';
	  cout<<"bTagSF="<<bTagSF<<'\n';
	  cout<<"****************"<<'\n';
	  }
	*/
	MET=(MCevent->met_met)/1000;
	METphi=(MCevent->met_phi);
		
	for(unsigned int i=0;i<(*MCevent->el_pt).size();i++)
	  {
	    TLorentzVector temp; temp.SetPtEtaPhiE((*MCevent->el_pt)[i]/1000,(*MCevent->el_eta)[i],(*MCevent->el_phi)[i],(*MCevent->el_e)[i]/1000);
	    //cout<<"lep pt = " << temp.Pt() << '\n';
	    if(temp.Pt()>=minLepPt)//no leptons get in if their pt is less than
	      {
		lepvecs.push_back(temp);
		if((*MCevent->el_charge)[i] >0)//charge is +1 so positron
		  leptype.push_back(-11);
		else
		  leptype.push_back(11);
		elvecs.push_back(temp);
		elcharge.push_back((*MCevent->el_charge)[i]);
	      }
	  }
	for(unsigned int i=0;i<(*MCevent->mu_pt).size();i++)
	  {
	    TLorentzVector temp; temp.SetPtEtaPhiE((*MCevent->mu_pt)[i]/1000,(*MCevent->mu_eta)[i],(*MCevent->mu_phi)[i],(*MCevent->mu_e)[i]/1000);
	    //cout<<"lep pt = " << temp.Pt() << '\n';
	    if(temp.Pt()>=minLepPt)//no leptons get in if their pt is less than 
	      {
		lepvecs.push_back(temp);
		if((*MCevent->mu_charge)[i] >0)//charge is +1 
		  leptype.push_back(-13);
		else
		  leptype.push_back(13);
		muvecs.push_back(temp);
		mucharge.push_back((*MCevent->mu_charge)[i]);
	      }
	  }
	for(unsigned int i=0;i<(*MCevent->jet_pt).size();i++)
	  {
	    TLorentzVector temp; temp.SetPtEtaPhiE((*MCevent->jet_pt)[i]/1000,(*MCevent->jet_eta)[i],(*MCevent->jet_phi)[i],(*MCevent->jet_e)[i]/1000);
	    if(temp.Pt()>minJetPt && fabs(temp.Eta())<maxJetEta)
	      {
		jetvecs.push_back(temp);
		mv1.push_back((*MCevent->jet_mv2c20)[i]);
	      }
	  }

	cout<<"eventNumber = "<<MCevent->eventNumber;

      }
    else
      {
			
	DataD3PDEvent* DATAevent = new DataD3PDEvent(ch);
	
	ch->GetEntry(ientry);

	MET=(DATAevent->met_met)/1000;
	METphi=(DATAevent->met_phi);

	for(unsigned int i=0;i<(*DATAevent->el_pt).size();i++)
	  {
	    TLorentzVector temp; temp.SetPtEtaPhiE((*DATAevent->el_pt)[i]/1000,(*DATAevent->el_eta)[i],(*DATAevent->el_phi)[i],(*DATAevent->el_e)[i]/1000);
	    if(temp.Pt()>=minLepPt)//no leptons get in if their pt is less than
	      {
		lepvecs.push_back(temp);
		if((*DATAevent->el_charge)[i] >0)//charge is +1 so positron
		  leptype.push_back(-11);
		else
		  leptype.push_back(11);
		elvecs.push_back(temp);
		elcharge.push_back((*DATAevent->el_charge)[i]);
	      }
	  }
	for(unsigned int i=0;i<(*DATAevent->mu_pt).size();i++)
	  {
	    TLorentzVector temp; temp.SetPtEtaPhiE((*DATAevent->mu_pt)[i]/1000,(*DATAevent->mu_eta)[i],(*DATAevent->mu_phi)[i],(*DATAevent->mu_e)[i]/1000);
	    if(temp.Pt()>=minLepPt)//no leptons get in if their pt is less than 
	      {
		lepvecs.push_back(temp);
		if((*DATAevent->mu_charge)[i] >0)//charge is +1
		  leptype.push_back(-13);
		else
		  leptype.push_back(13);
		muvecs.push_back(temp);
		mucharge.push_back((*DATAevent->mu_charge)[i]);
	      }
	  }
	for(unsigned int i=0;i<(*DATAevent->jet_pt).size();i++)
	  {
	    TLorentzVector temp; temp.SetPtEtaPhiE((*DATAevent->jet_pt)[i]/1000,(*DATAevent->jet_eta)[i],(*DATAevent->jet_phi)[i],(*DATAevent->jet_e)[i]/1000);
	    if(temp.Pt()>minJetPt && fabs(temp.Eta())<maxJetEta)
	      {
		jetvecs.push_back(temp);
		mv1.push_back((*DATAevent->jet_mv2c20)[i]);
	      }
	  }


	cout<<"eventNumber = "<<DATAevent->eventNumber;
	
	//if(DATAevent->eventNumber==1585356779)
	if(false)  debug=true;
	  
	if(debug)
	  {
	    cout<<"why did this event fail? "<< ""<<""<<'\n';
	   
	    cout<<"weight="<<weight<<'\n';
	  }
	
	
	//cout<<"data in elvecs.size()=" <<lepvecs.size() << '\n';
	
      }
    
    //^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^


    //cout<<"after elvecs.size()=" <<lepvecs.size() << '\n';
   
    assert(lepvecs.size()==leptype.size());
    assert(elvecs.size()==elcharge.size());
    assert(muvecs.size()==mucharge.size());
    assert(jetvecs.size()==mv1.size());
    
    //cout<<"vectors filled"<<'\n';
    
    //now vectors are filled we want to sort them by pt. 

    if(lepvecs.size()>1)
      MySort(lepvecs, leptype);
    if(elvecs.size()>1)
      MySort(elvecs, elcharge);
    if(muvecs.size()>1)
      MySort(muvecs, mucharge);
    if(jetvecs.size()>1)
      MySort(jetvecs, mv1);

  
    //if(jetvecs.size()!=1)
    //weight=0;
    
    if( jetvecs.size()<2 || jetvecs.size()>4)
      weight=0;
    
    if(jetvecs.size()==0 || (jetvecs.at(0)).Pt()<=40)//leading jet pt requirement
      weight=0;
    
    //cout<<"lepvecs.size()="<<lepvecs.size()<<'\n';
    
    if(lepvecs.size()!=3)
      weight=0;
    
    if(debug)
      cout<<"after nlep weight="<<weight<<'\n';
    
    if(debug)
      {
	cout<<"lepvecs.size()="<<lepvecs.size()<<'\n';
	for(unsigned int p=0; p < lepvecs.size();p++)
	  cout<<"lepvecs.at("<<p<<")="<<(lepvecs.at(p)).Pt()<<'\n';
	cout<<"jetvecs.size()="<<jetvecs.size()<<'\n';
	for(unsigned int p=0; p < jetvecs.size();p++)
	  {
	    cout<<"jetvecs.at("<<p<<")="<<(jetvecs.at(p)).Pt()<<'\n';
	    cout<<"mv2.at("<<p<<")="<<mv1.at(p)<<'\n';
	  }
	cout<<"MET="<<MET<<'\n';
      }
    
    if(lepvecs.size()==3 && (lepvecs.at(0)).Pt() < 40 )
      weight=0;

    if(lepvecs.size()==3 && (lepvecs.at(1)).Pt() < 20 )
      weight=0;
        
    if(lepvecs.size()==3 && (lepvecs.at(2)).Pt() < 10 )
      weight=0;
      
    int numbjets=0; 
    
    for(unsigned int i=0;i< mv1.size(); i++)
      {
	if(mv1.at(i)>MVscore)
	  numbjets++;
      }

    if(numbjets!=1)
      weight=0;

    if(debug)
      cout<<"after b weight="<<weight<<'\n';
    
    
    //cout<<"a"<<'\n';
    
    //***************************************************************
    TLorentzVector dud;
    dud = TLorentzVector(10,10,10,10);// the actual value of this isn't important. it goes in with 0 weight. It is a placeholder for when the event wont pass the cutflow anyway. 

    //cout<<"dud mass = "<<dud.M()<<'\n';
    
    //calculate composite quantities 
    
    TLorentzVector Zboson=dud;
    TLorentzVector Zlep=dud;
    TLorentzVector Zantilep=dud;
    TLorentzVector Wlep=dud;
    int WlepType=0;
    int ZlepType=0;

    //cout<<"b"<<'\n';

    //cout<<"num lep = "<<lepvecs.size()<< '\n';

    if(lepvecs.size()==3)
      {
	double Zmass=90;
	TLorentzVector Z1, Z2, Z3;
	Z1=dud;
	Z2=dud;
	Z3=dud;

	if(leptype.at(1)==-1*leptype.at(2))
	  Z1=lepvecs.at(1)+lepvecs.at(2);
	if(leptype.at(0)==-1*leptype.at(2))
	  Z2=lepvecs.at(0)+lepvecs.at(2);
	if(leptype.at(0)==-1*leptype.at(1))
	  Z3=lepvecs.at(0)+lepvecs.at(1);
	
	if(Z1==dud && Z2==dud && Z3==dud)
	  {
	    cout<<"no valid OSSF pair found. No Z reconstructed. Event thrown out. "<<'\n';
	    cout<<"leptypes = "<<leptype.at(0)<<"  "<<leptype.at(1)<<"  "<<leptype.at(2)<<'\n';
	    cout<<"Ztempvecs.M = "<<Z1.M()<<"  "<<Z2.M()<<"  "<<Z3.M()<<'\n';
	    cout<<"dud.M() = "<<dud.M()<<'\n';
	  }
	else if(Z1!=dud && Z2!=dud && Z3!=dud)
	  {
	    cout<<"How were three valid OSSF pairs found in three leptons? uhhhh someone call Turing, we broke logic..."<<'\n';
	    cout<<"leptypes = "<<leptype.at(0)<<"  "<<leptype.at(1)<<"  "<<leptype.at(2)<<'\n';
	    cout<<"Ztempvecs.M = "<<Z1.M()<<"  "<<Z2.M()<<"  "<<Z3.M()<<'\n';
	    cout<<"dud.M() = "<<dud.M()<<'\n';
	  }
	else if(Z1!=dud && Z2==dud && Z3==dud)
	  {
	    Zboson=Z1;
	    Wlep=lepvecs.at(0);
	    WlepType=leptype.at(0);
	    ZlepType=leptype.at(1);
	    if(leptype.at(1)>0)
	      {
		Zlep=lepvecs.at(1);
		Zantilep=lepvecs.at(2);
	      }
	    else
	      {
		Zlep=lepvecs.at(2);
		Zantilep=lepvecs.at(1);
	      }
	  }
	else if(Z1==dud && Z2!=dud && Z3==dud)
	  {
	    Zboson=Z2;
	    Wlep=lepvecs.at(1);
	    WlepType=leptype.at(1);
	    ZlepType=leptype.at(0);
	    if(leptype.at(0)>0)
	      {
		Zlep=lepvecs.at(0);
		Zantilep=lepvecs.at(2);
	      }
	    else
	      {
		Zlep=lepvecs.at(2);
		Zantilep=lepvecs.at(0);
	      }
	  }
	else if(Z1==dud && Z2==dud && Z3!=dud)
	  {
	    Zboson=Z3;
	    Wlep=lepvecs.at(2);
	    WlepType=leptype.at(2);
	    ZlepType=leptype.at(1);
	    if(leptype.at(0)>0)
	      {
		Zlep=lepvecs.at(0);
		Zantilep=lepvecs.at(1);
	      }
	    else
	      {
		Zlep=lepvecs.at(1);
		Zantilep=lepvecs.at(0);
	      }
	  }
	else if(Z1!=dud && Z2!=dud && fabs(Z1.M()-Zmass)<fabs(Z2.M()-Zmass) )
	  {
	    Zboson=Z1;
	    Wlep=lepvecs.at(0);
	    WlepType=leptype.at(0);
	    ZlepType=leptype.at(1);
	    if(leptype.at(1)>0)
	      {
		Zlep=lepvecs.at(1);
		Zantilep=lepvecs.at(2);
	      }
	    else
	      {
		Zlep=lepvecs.at(2);
		Zantilep=lepvecs.at(1);
	      }
	  }
	else if(Z1!=dud && Z2!=dud && fabs(Z1.M()-Zmass)>fabs(Z2.M()-Zmass) )
	  {
	    Zboson=Z2;
	    Wlep=lepvecs.at(1);
	    WlepType=leptype.at(1);
	    ZlepType=leptype.at(2);
	    if(leptype.at(0)>0)
	      {
		Zlep=lepvecs.at(0);
		Zantilep=lepvecs.at(2);
	      }
	    else
	      {
		Zlep=lepvecs.at(2);
		Zantilep=lepvecs.at(0);
	      }
	  }
	else if(Z1!=dud && Z3!=dud && fabs(Z1.M()-Zmass)<fabs(Z3.M()-Zmass) )
	  {
	    Zboson=Z1;
	    Wlep=lepvecs.at(0);
	    WlepType=leptype.at(0);
	    ZlepType=leptype.at(2);
	    if(leptype.at(1)>0)
	      {
		Zlep=lepvecs.at(1);
		Zantilep=lepvecs.at(2);
	      }
	    else
	      {
		Zlep=lepvecs.at(2);
		Zantilep=lepvecs.at(1);
	      }
	  }
	else if(Z1!=dud && Z3!=dud && fabs(Z1.M()-Zmass)>fabs(Z3.M()-Zmass) )
	  {
	    Zboson=Z3;
	    Wlep=lepvecs.at(2);
	    WlepType=leptype.at(2);
	    ZlepType=leptype.at(1);
	    if(leptype.at(0)>0)
	      {
		Zlep=lepvecs.at(0);
		Zantilep=lepvecs.at(1);
	      }
	    else
	      {
		Zlep=lepvecs.at(1);
		Zantilep=lepvecs.at(0);
	      }
	  }
	else if(Z2!=dud && Z3!=dud && fabs(Z2.M()-Zmass)<fabs(Z3.M()-Zmass) )
	  {
	    Zboson=Z2;
	    Wlep=lepvecs.at(1);
	    WlepType=leptype.at(1);
	    ZlepType=leptype.at(2);
	    if(leptype.at(0)>0)
	      {
		Zlep=lepvecs.at(0);
		Zantilep=lepvecs.at(2);
	      }
	    else
	      {
		Zlep=lepvecs.at(2);
		Zantilep=lepvecs.at(0);
	      }
	  }
	else if(Z2!=dud && Z3!=dud && fabs(Z2.M()-Zmass)>fabs(Z3.M()-Zmass) )
	  {
	    Zboson=Z3;
	    Wlep=lepvecs.at(2);
	    WlepType=leptype.at(2);
	    ZlepType=leptype.at(1);
	    if(leptype.at(0)>0)
	      {
		Zlep=lepvecs.at(0);
		Zantilep=lepvecs.at(1);
	      }
	    else
	      {
		Zlep=lepvecs.at(1);
		Zantilep=lepvecs.at(0);
	      }
	  }

      }
    
    if(Zboson==dud)
      weight=0;

    //cout<<"Zboson.M() = "<<Zboson.M()<<'\n';
    
    //if(WlepType < 0 )    
    //weight=0;
    
    //if( fabs(ZlepType)!=11 )
    //weight=0;
    
    if(Zboson.M()<80 || Zboson.M()>100)//on Z requirement
      weight=0;
    
    if(debug)
      cout<<"after Z mass window weight="<<weight<<'\n';
    
 
    //if(Zboson.M()>80 && Zboson.M()<100)//off Z requirement
	//weight=0;
    
    //if(Zboson.M() > 50)
    //weight=0;
    
    double WtransM=Wvariables::WtransverseMass(Wlep.Pt(),Wlep.Phi(),MET,METphi);
 
    if(MET<20)
      weight=0;
    
    if(WtransM<40 && MET<30)
      weight=0;
    
    
    TLorentzVector Neutrino=Wvariables::Wneutrino(MET,METphi,Wlep.Pt(),Wlep.Eta(),Wlep.Phi());

    TLorentzVector Wboson=Neutrino+Wlep;

    TLorentzVector Bjet=dud;
    TLorentzVector LeadNonBjet=dud;
    double maxMV1=MVscore;
    int tempk=-1;//holds the position of the b jet in the jet vector
    //cout<<"d"<<'\n';

    //cout<<"MVscore="<<MVscore<<'\n';
    //picks the leading b-jet
    for(unsigned int i=0;i<jetvecs.size();i++)
      {
	//cout<<"i="<<i<<'\n';
	//cout<<"mv1.at(i)="<<mv1.at(i)<<'\n';
	
	if(mv1.at(i)>MVscore && fabs((jetvecs.at(i)).Eta())<2.5 && tempk==-1)//takes leading b-jet 
	  {
	    maxMV1=mv1.at(i);
	    Bjet=jetvecs.at(i);
	    tempk=i;
	  }
      }
    //cout<<"e"<<'\n';
    
    if(tempk==0 && jetvecs.size()>1)
      LeadNonBjet=jetvecs.at(1);
    else if(tempk!=0 && jetvecs.size()>1)
      LeadNonBjet=jetvecs.at(0);
    

    //using leading jet instead of B jet
    /* if(jetvecs.size()>1)
       {
       Bjet=jetvecs.at(0);
       LeadNonBjet=jetvecs.at(1);
       }
    */

  

    TLorentzVector Top=Bjet+Wboson;

    double Whel=TopPolarization::WHelicity(Wlep, Wboson,Top);
    
    TLorentzVector CM=Neutrino;
        
    //cout<<"f"<<'\n';

    for(unsigned int i=0; i<lepvecs.size();i++)
      CM=CM+lepvecs.at(i);
    for(unsigned int i=0; i<jetvecs.size();i++)
      CM=CM+jetvecs.at(i);
    
    double TopPolHel=TopPolarization::TopPolHelBasis(Wlep, CM, Top );
    
    double TopPolOpt=0;
        
    //cout<<"g"<<'\n';

    if(jetvecs.size()>1)
      TopPolOpt=TopPolarization::TopPolOptimalBasis(Wlep, LeadNonBjet,Top);
    
    //cout<<"h"<<'\n';

   if(debug)
      {
	cout<<"Zmass="<<Zboson.M()<<'\n';
	cout<<"Topmass"<<Top.M()<<'\n';
	cout<<"weight="<<weight<<'\n';

      }
    




    //end preselection

    
    /*        ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^final selection cuts.......
   
    if(Top.M()<160 )
    weight=0;
     
    if(Top.M()>280 )
    weight=0;

    //add in dR between Zlepton and Zantilepton

    if(LeadNonBjet.DeltaR(Bjet) < 2.5)
    weight=0;
    
    if( Wlep.DeltaR(Bjet) > 3.5)
    weight=0;
   
    if( WtransM < 60 )
    weight=0;
   
    if(fabs(LeadNonBjet.Eta()) < 3.0)
     weight=0;
      */   
 


   //if( WtransM < 50 )
   //weight=0;
   
   //if(fabs(LeadNonBjet.Eta()) < 1.5)
   //weight=0;
   
   //if(LeadNonBjet.DeltaR(Bjet) < 2.0 )
   //weight=0;
   
   
   //if(weight==0)
   //cout<<" failed"<<'\n';
   //if(weight!=0)
   //{
   //cout<<" passed : ";
   //cout<<" : Leading Lepton Pt = "<<(lepvecs.at(0)).Pt();
   //cout<<" : Second Lepton Pt = "<<(lepvecs.at(1)).Pt();
   //cout<<" : Third Lepton Pt = "<<(lepvecs.at(2)).Pt();
   //cout<<'\n';
   //}
    
    if(weight!=0)//checking if outlier MCSF events with large weights are leaking into my histograms. 
      {
	cout<<"abczyx****************"<<'\n';
	cout<<"lumi="<<lumi<<'\n';
	cout<<"xsec="<<xsec<<'\n';
	cout<<"MCSF="<<MCSF<<'\n';
	cout<<"pileupSF="<<pileupSF<<'\n';
	cout<<"leptonSF="<<leptonSF<<'\n';
	cout<<"bTagSF="<<bTagSF<<'\n';
	cout<<"****************"<<'\n';
      }
    
   
    
    //What follows is a dumb solution to a few problems, checking the existance of objects to be put in histograms, and weighting the end result properly if an event gets rejected an event with 0 weight must be put into the plot to ensure the number of mc events can be corrected for in the weight later. dud is created because trying to push back lepvecs.at(2) when there isn't a second lepton will of course cause everything to break. when a new TLorentzVector must be added for plot creation, it must be added to the InitStruct function in ztAnalysis, as well as added to objects with a weight as is done here.  

    vector<TLorentzVector> objects;
    vector<double> mask;
    

    objects.push_back(Zboson); mask.push_back(weight);
    objects.push_back(Bjet); mask.push_back(weight);
    objects.push_back(Neutrino); mask.push_back(weight);
    objects.push_back(Wboson); mask.push_back(weight);
    objects.push_back(Top); mask.push_back(weight);
    objects.push_back(LeadNonBjet); mask.push_back(weight);
    //objects.push_back(); mask.push_back(weight);
    objects.push_back(Zlep); mask.push_back(weight);
    objects.push_back(Zantilep); mask.push_back(weight);
    objects.push_back(Wlep); mask.push_back(weight);
   
    if(lepvecs.size()>0)
      {objects.push_back(lepvecs.at(0)); mask.push_back(weight);}
    else
      {objects.push_back(dud); mask.push_back(0);}
    if(lepvecs.size()>1)
      {objects.push_back(lepvecs.at(1)); mask.push_back(weight);}
    else
      {objects.push_back(dud); mask.push_back(0);}
    if(lepvecs.size()>2)
      {objects.push_back(lepvecs.at(2)); mask.push_back(weight);}   
    else
      {objects.push_back(dud); mask.push_back(0);}

    if(jetvecs.size()>0)
      {objects.push_back(jetvecs.at(0)); mask.push_back(weight);}    
    else
      {objects.push_back(dud); mask.push_back(0);}
    if(jetvecs.size()>1)
      {objects.push_back(jetvecs.at(1)); mask.push_back(weight);}  
    else
      {objects.push_back(dud); mask.push_back(0);}
    if(jetvecs.size()>2)
      {objects.push_back(jetvecs.at(2)); mask.push_back(weight);}  
    else
      {objects.push_back(dud); mask.push_back(0);}



    /* if(elvecs.size()>0)
       {objects.push_back(elvecs.at(0)); mask.push_back(weight);}    
       else
       {objects.push_back(dud); mask.push_back(0);}
       if(elvecs.size()>1)
       {objects.push_back(elvecs.at(1)); mask.push_back(weight);}
       else
       {objects.push_back(dud); mask.push_back(0);}
       if(elvecs.size()>2)
       {objects.push_back(elvecs.at(2)); mask.push_back(weight);} 
       else
       {objects.push_back(dud); mask.push_back(0);}
       if(muvecs.size()>0)
       {objects.push_back(muvecs.at(0)); mask.push_back(weight);}    
       else
       {objects.push_back(dud); mask.push_back(0);}
       if(muvecs.size()>1)
       {objects.push_back(muvecs.at(1)); mask.push_back(weight);}     
       else
       {objects.push_back(dud); mask.push_back(0);}
       if(muvecs.size()>2)
       {objects.push_back(muvecs.at(2)); mask.push_back(weight);} 
       else
       {objects.push_back(dud); mask.push_back(0);}
       if(jetvecs.size()>0)
       {objects.push_back(jetvecs.at(0)); mask.push_back(weight);}    
       else
       {objects.push_back(dud); mask.push_back(0);}
       if(jetvecs.size()>1)
       {objects.push_back(jetvecs.at(1)); mask.push_back(weight);}  
       else
       {objects.push_back(dud); mask.push_back(0);}
       if(jetvecs.size()>2)
       {objects.push_back(jetvecs.at(2)); mask.push_back(weight);}    
       else
       {objects.push_back(dud); mask.push_back(0);}
    */
    assert(objects.size()==mask.size());
    assert(objects.size()==(thestruct->names).size());// if this is not the case then filling the histograms that follow will fail. check ztAnalysis.C to ensure that the objects getting pushed back match the names that are given there. 


    //********************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************

    //cout<<"mask created"<<'\n';
    
    if(weight>0)
      {
	// Fill histograms
	unsigned int max_index=(thestruct->names).size();
	
	//cout<<"objects.size="<<objects.size()<<'\n';
	//cout<<"max index = "<<max_index<<'\n';
	//cout<<"histos.size()="<<thestruct->histos.size()<<'\n';
	//cout<<"combhistos.size()="<<thestruct->combhistos.size()<<'\n';
	
	int k=0;
	
	for(unsigned int i=0; i<max_index;i++)
	  {
	    //cout<<"i="<<i<<'\n';
	    
	    Fill(thestruct->histos.at(4*i+0),objects.at(i).Pt(),mask.at(i));
	    Fill(thestruct->histos.at(4*i+1),objects.at(i).Eta(),mask.at(i));
	    Fill(thestruct->histos.at(4*i+2),objects.at(i).Phi(),mask.at(i));
	    Fill(thestruct->histos.at(4*i+3),objects.at(i).M(),mask.at(i));
	    
	    for(unsigned int j=i+1; j<max_index;j++)
	      {
		
		Fill(thestruct->combhistos.at(k++),(objects.at(i)).DeltaR(objects.at(j)), std::sqrt(mask.at(i)*mask.at(j)));
		Fill(thestruct->combhistos.at(k++),(objects.at(i)).Eta()-(objects.at(j)).Eta(),std::sqrt(mask.at(i)*mask.at(j)));
		double dphi=(objects.at(i)).Phi()-(objects.at(j)).Phi();
		while(dphi>3.14)
		  dphi=dphi-6.28;
		while(dphi<-3.14)
		  dphi=dphi+6.28;
		Fill(thestruct->combhistos.at(k++),dphi,std::sqrt(mask.at(i)*mask.at(j)));
		Fill(thestruct->combhistos.at(k++),( objects.at(i)+objects.at(j) ).M(),std::sqrt(mask.at(i)*mask.at(j)));
	      }
	  }
	
	//cout<<"filled hist struct"<<'\n';
	//if(lepvecs.size()!=3)
	//weight=0;
	Fill(thestruct->h_junk,lepvecs.size(), weight);
	Fill(thestruct->h_nlep,lepvecs.size(), weight);
	Fill(thestruct->h_nelec,elvecs.size(), weight);
	Fill(thestruct->h_nmuon,muvecs.size(), weight);
	Fill(thestruct->h_njet,jetvecs.size(), weight);
	Fill(thestruct->h_nbjet, numbjets , weight);

	//cout<<"mv1.size()="<<mv1.size()<<'\n';
	
	for(unsigned int i=0;i<mv1.size();i++)
	  Fill(thestruct->h_mv1, mv1.at(i), weight);
	
	if(mv1.size()>0)
	  Fill(thestruct->h_Leadmv1, mv1.at(0), weight);
	
	Fill(thestruct->h_Highmv1, maxMV1, weight);
	
	Fill(thestruct->h_met,MET, weight);
	Fill(thestruct->h_Wt,WtransM, weight);
	Fill(thestruct->h_tM,Top.M(), weight);
	
	Fill(thestruct->h_Whel,Whel, weight);
	Fill(thestruct->h_TopPolOpt,TopPolOpt, weight);
	Fill(thestruct->h_TopPolHel,TopPolHel, weight);
	
	TLorentzVector AllLep=dud;
	TLorentzVector AllJet=dud;
	if(lepvecs.size()==3)
	  AllLep=lepvecs.at(0)+lepvecs.at(1)+lepvecs.at(2);
	if(jetvecs.size()>0)
	  {
	    AllJet=jetvecs.at(0);
	    for(unsigned int i=1;i<jetvecs.size();i++)
	      AllJet=AllJet+jetvecs.at(i);
	  }
	
	Fill(thestruct->h_3lM,AllLep.M(), weight);
	Fill(thestruct->h_AllJetsM,AllJet.M(), weight);
	Fill(thestruct->h_jetdr, LeadNonBjet.DeltaR(Bjet), weight);

	if(!isData)
	  {
	    //if(fabs(MCSF)>10)
	    Fill(thestruct->h_MCSF,MCSF,1);
	    Fill(thestruct->h_PileupSF,pileupSF,1);
	    Fill(thestruct->h_BtagSF,bTagSF,1);
	    Fill(thestruct->h_leptonSF,leptonSF,1);
	  }
	
	thestruct->METvsWtm.Fill((Double_t)MET,(Double_t)WtransM,weight);
	thestruct->METvsLpt.Fill((Double_t)MET,(Double_t)lepvecs.at(0).Pt(),weight);
	thestruct->WtmvsLpt.Fill((Double_t)WtransM,(Double_t)lepvecs.at(0).Pt(),weight);
	
	
      }//end of if(weight>0)
    //cout<<"end"<<'\n';
    
    
  }//end of event loop
  
  //cout<<"after"<<'\n';
  
} // Loop function

