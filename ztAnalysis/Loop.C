#include "LeptonContainer.C"
#include "TopD3PD.C"

typedef TopD3PD D3PDEvent;


void Loop(TChain *ch, float xsec, hist_struct *thestruct) {
  
  cout<<"before"<<'\n';
  
  //double topMass=175;

  double NEvents = 0;
  double beforeall=0;
  double afterNLeptonReq =0;
  double afterMETReq = 0;
  double afterBTagReq = 0;
  //double afterWTransverseMassReq = 0;
  double afterJetReq = 0;
  double afterTopMassReq=0;
  double afterForJetReq=0;
  //double afterForJetReq2=0;
  //double afterWpt=0;
  double afterTopPol=0;
  //double afterForBJet=0;
  //double afterBPt=0;
  //double afterAllJetM=0;
  double afterLeadJetPt=0;
  //double afterLepPt=0;
  double afterTopPt=0;
  double afterHt=0;
 
  cout<<"ch->GetEntries()="<<ch->GetEntries()<<'\n';

  D3PDEvent* event = new D3PDEvent(ch);
     
  for (unsigned int ientry = 0; ientry < ch->GetEntries(); ientry++) {
    //for (unsigned int ientry = 0; ientry <100; ientry++) {
          
    ch->GetEntry(ientry);
   
    if (ientry % 100000 == 0) cout << " ientry = " << ientry << " out of " << ch->GetEntries() << endl;
       
    bool eventsel=true;//variable that holds if passed selection up to this point
    
    float weight=(lum*1000*xsec/ch->GetEntries());
    double theweight=weight;

    //beforeall+=theweight;
    
    //TLorentzVector metvec;
    
    //int eventNumber=event->eventNumber;
    //int runNumber=event->runNumber;

    //cout<<"event->eventNumber="<<eventNumber<<'\n';
    //cout<<"event->runNumber="<<runNumber<<'\n';

        
    //analysis goes here! 

    LeptonContainer* leptons=new LeptonContainer();
    
    for(unsigned int c=0;c<event->lep_n;c++)
      {
	
	if( (*event->lep_type)==11 && (fabs((*event->lep_eta))<maxElectronEta || (*event->lep_pt)>minElectronPt) )//electron cuts
	  {
	    TLorentzVector temp;
	    temp.SetPtEtaPhiE( (*event->lep_pt)/1000,(*event->lep_eta),(*event->lep_phi),(*event->lep_E) );
	    leptons->addLepNode(temp,(int)(*event->lep_charge),(*event->lep_type));
	  }

	else if ( (*event->lep_type)==13 && (fabs((*event->lep_eta))<maxMuonEta || (*event->lep_pt)>minMuonPt) )//muon cuts
	  {
	    TLorentzVector temp;
	    temp.SetPtEtaPhiE( (*event->lep_pt)/1000,(*event->lep_eta),(*event->lep_phi),(*event->lep_E) );
	    leptons->addLepNode(temp,(int)(*event->lep_charge),(*event->lep_type));
	  }
	
      }
    
    Fill(thestruct->h_nlep,leptons->nLep(),theweight);
    Fill(thestruct->h_nelec,leptons->nElec(),theweight);
    Fill(thestruct->h_nmuon,leptons->nMuon(),theweight);

    if(leptons->nLep()!=3)
      eventsel=false;

    if(eventsel)
      {
	//Fill(thestruct->hostos.at(0),((leptons->GetLepNode(1)).lep).Pt(),theweight);

      }


    Fill(thestruct->histos.at(0),((leptons->GetLepNode(1))->lep).Pt(),theweight);


















    
  }//end of event loop
    
  //cout<<"Stuff"<<'\n';
  ofstream myfile;
  myfile.open("NEvents.txt", ios::in|ios::app);
  myfile.seekp(0,ios_base::end);

  myfile<<"before all = "<<beforeall<<endl;
  myfile<<"afterNLeptonReq = "<<afterNLeptonReq<<endl;
  myfile<<"afterJetReq = "<<afterJetReq<<endl;
  myfile<<"afterBTagReq = "<<afterBTagReq<<endl;
  myfile<<"afterMETReq = "<<afterMETReq<<endl;
  
  //myfile<<"afterLepPt = "<<afterLepPt<<endl;
  myfile<<"afterForLeadnonBJet = "<<afterForJetReq<<endl;
  myfile<<"afterLeadnonBJetPt = "<<afterLeadJetPt<<endl;
  // myfile<<"afterForJetReq2nd = "<<afterForJetReq2<<endl;
  // myfile<<"afterForBJet = "<<afterForBJet<<endl;
  //myfile<<"afterBPt = "<<afterBPt<<endl;
  //myfile<<"afterWpt = "<<afterWpt<<endl;
  //myfile<<"afterWTransverseMassReq = "<<afterWTransverseMassReq<<endl;
  myfile<<"afterTopMass = "<<afterTopMassReq<<endl;
  myfile<<"afterTopPt = "<<afterTopPt<<endl;
  myfile<<"afterTopPol = "<<afterTopPol<<endl;
  //myfile<<"afterAllJetM = "<<afterAllJetM<<endl;
  myfile<<"afterHt = "<<afterHt<<endl;
  myfile<<"afterAll = "<<NEvents<<endl;
  myfile<<endl;
  myfile.close();

  /*
  cout<<"NEventsbefore = "<<beforeall<<endl;
  cout<<"weight = "<<theweight<<endl;
  cout<<"before all = "<<beforeall<<endl;
  
  cout<<"afterNLeptonReq = "<<afterNLeptonReq<<endl;
  cout<<"afterJetReq = "<<afterJetReq<<endl;
  cout<<"afterBTagReq = "<<afterBTagReq<<endl;
  cout<<"afterMETReq = "<<afterMETReq<<endl;

  cout<<"afterLepPt = "<<afterLepPt<<endl;
  cout<<"afterForJetReqLead = "<<afterForJetReq<<endl;
  // cout<<"afterLeadJetPt = "<<afterLeadJetPt<<endl;
  // cout<<"afterForJetReq2nd = "<<afterForJetReq2<<endl;
  // cout<<"afterForBJet = "<<afterForBJet<<endl;
  //cout<<"afterBPt = "<<afterBPt<<endl;
  cout<<"afterWpt = "<<afterWpt<<endl;
  cout<<"afterWTransverseMassReq = "<<afterWTransverseMassReq<<endl;
  cout<<"afterTopMassReq = "<<afterTopMassReq<<endl;
  cout<<"afterTopPol = "<<afterTopPol<<endl;
  //cout<<"afterAllJetM = "<<afterAllJetM<<endl;
  */

  cout<<"after"<<'\n';

} // Loop function

