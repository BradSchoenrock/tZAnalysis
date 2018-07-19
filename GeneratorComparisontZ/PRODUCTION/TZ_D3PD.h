//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Thu Nov 20 14:54:03 2014 by ROOT version 5.34/03
// from TTree truth/truth
// found on file: MC12_8TeV.110491.NTUP_TRUTH.root
//////////////////////////////////////////////////////////

#ifndef TZ_D3PD_h
#define TZ_D3PD_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.
#include <vector>
#include <vector>
#include <vector>
#include <vector>

// Fixed size dimensions of array or collections stored in the TTree if any.

class TZ_D3PD {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

   // Declaration of leaf types
   UInt_t          RunNumber;
   UInt_t          EventNumber;
   UInt_t          mc_channel_number;
   UInt_t          mc_event_number;
   Float_t         mc_event_weight;
   Int_t           mcevt_n;
   vector<int>     *mcevt_signal_process_id;
   vector<int>     *mcevt_event_number;
   vector<double>  *mcevt_event_scale;
   vector<double>  *mcevt_alphaQCD;
   vector<double>  *mcevt_alphaQED;
   vector<int>     *mcevt_pdf_id1;
   vector<int>     *mcevt_pdf_id2;
   vector<double>  *mcevt_pdf_x1;
   vector<double>  *mcevt_pdf_x2;
   vector<double>  *mcevt_pdf_scale;
   vector<double>  *mcevt_pdf1;
   vector<double>  *mcevt_pdf2;
   vector<vector<double> > *mcevt_weight;
   Int_t           jet_AntiKt4TruthJets_n;
   vector<float>   *jet_AntiKt4TruthJets_E;
   vector<float>   *jet_AntiKt4TruthJets_pt;
   vector<float>   *jet_AntiKt4TruthJets_m;
   vector<float>   *jet_AntiKt4TruthJets_eta;
   vector<float>   *jet_AntiKt4TruthJets_phi;
   vector<float>   *jet_AntiKt4TruthJets_flavor_partonDR;
   vector<int>     *jet_AntiKt4TruthJets_flavor_partonFlavor;
   vector<int>     *jet_AntiKt4TruthJets_flavor_hadronFlavor;
   vector<int>     *jet_AntiKt4TruthJets_flavor_hadronPDGID;
   Int_t           jet_AntiKt4TruthJets_WZ_n;
   vector<float>   *jet_AntiKt4TruthJets_WZ_E;
   vector<float>   *jet_AntiKt4TruthJets_WZ_pt;
   vector<float>   *jet_AntiKt4TruthJets_WZ_m;
   vector<float>   *jet_AntiKt4TruthJets_WZ_eta;
   vector<float>   *jet_AntiKt4TruthJets_WZ_phi;
   vector<float>   *jet_AntiKt4TruthJets_WZ_flavor_partonDR;
   vector<int>     *jet_AntiKt4TruthJets_WZ_flavor_partonFlavor;
   vector<int>     *jet_AntiKt4TruthJets_WZ_flavor_hadronFlavor;
   vector<int>     *jet_AntiKt4TruthJets_WZ_flavor_hadronPDGID;
   Int_t           jet_AntiKt6TruthJets_WZ_n;
   vector<float>   *jet_AntiKt6TruthJets_WZ_E;
   vector<float>   *jet_AntiKt6TruthJets_WZ_pt;
   vector<float>   *jet_AntiKt6TruthJets_WZ_m;
   vector<float>   *jet_AntiKt6TruthJets_WZ_eta;
   vector<float>   *jet_AntiKt6TruthJets_WZ_phi;
   vector<float>   *jet_AntiKt6TruthJets_WZ_flavor_partonDR;
   vector<int>     *jet_AntiKt6TruthJets_WZ_flavor_partonFlavor;
   vector<int>     *jet_AntiKt6TruthJets_WZ_flavor_hadronFlavor;
   vector<int>     *jet_AntiKt6TruthJets_WZ_flavor_hadronPDGID;
   Int_t           mc_n;
   vector<float>   *mc_E;
   vector<float>   *mc_pt;
   vector<float>   *mc_m;
   vector<float>   *mc_eta;
   vector<float>   *mc_phi;
   vector<int>     *mc_status;
   vector<int>     *mc_barcode;
   vector<int>     *mc_pdgId;
   vector<float>   *mc_charge;
   vector<vector<int> > *mc_parents;
   vector<vector<int> > *mc_children;
   vector<float>   *mc_vx_x;
   vector<float>   *mc_vx_y;
   vector<float>   *mc_vx_z;
   vector<int>     *mc_vx_barcode;
   vector<vector<int> > *mc_child_index;
   vector<vector<int> > *mc_parent_index;
   Float_t         MET_Truth_NonInt_etx;
   Float_t         MET_Truth_NonInt_ety;
   Float_t         MET_Truth_Int_etx;
   Float_t         MET_Truth_Int_ety;
   Float_t         MET_Truth_IntCentral_etx;
   Float_t         MET_Truth_IntCentral_ety;
   Float_t         MET_Truth_IntFwd_etx;
   Float_t         MET_Truth_IntFwd_ety;
   Float_t         MET_Truth_IntOutCover_etx;
   Float_t         MET_Truth_IntOutCover_ety;
   Float_t         MET_Truth_IntMuons_etx;
   Float_t         MET_Truth_IntMuons_ety;
   Int_t           el_n;
   vector<float>   *el_pt;
   vector<float>   *el_m;
   vector<float>   *el_eta;
   vector<float>   *el_phi;
   vector<int>     *el_status;
   vector<int>     *el_barcode;
   vector<float>   *el_charge;
   vector<float>   *el_dressed_pt;
   vector<float>   *el_dressed_eta;
   vector<float>   *el_dressed_phi;
   vector<float>   *el_dressed_m;
   vector<float>   *el_iso02;
   vector<float>   *el_iso03;
   vector<vector<int> > *el_parent_index;
   Int_t           mu_n;
   vector<float>   *mu_pt;
   vector<float>   *mu_m;
   vector<float>   *mu_eta;
   vector<float>   *mu_phi;
   vector<int>     *mu_status;
   vector<int>     *mu_barcode;
   vector<float>   *mu_charge;
   vector<float>   *mu_dressed_pt;
   vector<float>   *mu_dressed_eta;
   vector<float>   *mu_dressed_phi;
   vector<float>   *mu_dressed_m;
   vector<float>   *mu_iso02;
   vector<float>   *mu_iso03;
   vector<vector<int> > *mu_parent_index;
   Int_t           tau_n;
   vector<float>   *tau_pt;
   vector<float>   *tau_m;
   vector<float>   *tau_eta;
   vector<float>   *tau_phi;
   vector<int>     *tau_status;
   vector<int>     *tau_barcode;
   vector<float>   *tau_charge;
   vector<vector<int> > *tau_parent_index;
   vector<vector<int> > *tau_decay_index;
   Int_t           ph_n;
   vector<float>   *ph_pt;
   vector<float>   *ph_m;
   vector<float>   *ph_eta;
   vector<float>   *ph_phi;
   vector<int>     *ph_status;
   vector<int>     *ph_barcode;

   // List of branches
   TBranch        *b_RunNumber;   //!
   TBranch        *b_EventNumber;   //!
   TBranch        *b_mc_channel_number;   //!
   TBranch        *b_mc_event_number;   //!
   TBranch        *b_mc_event_weight;   //!
   TBranch        *b_mcevt_n;   //!
   TBranch        *b_mcevt_signal_process_id;   //!
   TBranch        *b_mcevt_event_number;   //!
   TBranch        *b_mcevt_event_scale;   //!
   TBranch        *b_mcevt_alphaQCD;   //!
   TBranch        *b_mcevt_alphaQED;   //!
   TBranch        *b_mcevt_pdf_id1;   //!
   TBranch        *b_mcevt_pdf_id2;   //!
   TBranch        *b_mcevt_pdf_x1;   //!
   TBranch        *b_mcevt_pdf_x2;   //!
   TBranch        *b_mcevt_pdf_scale;   //!
   TBranch        *b_mcevt_pdf1;   //!
   TBranch        *b_mcevt_pdf2;   //!
   TBranch        *b_mcevt_weight;   //!
   TBranch        *b_jet_AntiKt4TruthJets_n;   //!
   TBranch        *b_jet_AntiKt4TruthJets_E;   //!
   TBranch        *b_jet_AntiKt4TruthJets_pt;   //!
   TBranch        *b_jet_AntiKt4TruthJets_m;   //!
   TBranch        *b_jet_AntiKt4TruthJets_eta;   //!
   TBranch        *b_jet_AntiKt4TruthJets_phi;   //!
   TBranch        *b_jet_AntiKt4TruthJets_flavor_partonDR;   //!
   TBranch        *b_jet_AntiKt4TruthJets_flavor_partonFlavor;   //!
   TBranch        *b_jet_AntiKt4TruthJets_flavor_hadronFlavor;   //!
   TBranch        *b_jet_AntiKt4TruthJets_flavor_hadronPDGID;   //!
   TBranch        *b_jet_AntiKt4TruthJets_WZ_n;   //!
   TBranch        *b_jet_AntiKt4TruthJets_WZ_E;   //!
   TBranch        *b_jet_AntiKt4TruthJets_WZ_pt;   //!
   TBranch        *b_jet_AntiKt4TruthJets_WZ_m;   //!
   TBranch        *b_jet_AntiKt4TruthJets_WZ_eta;   //!
   TBranch        *b_jet_AntiKt4TruthJets_WZ_phi;   //!
   TBranch        *b_jet_AntiKt4TruthJets_WZ_flavor_partonDR;   //!
   TBranch        *b_jet_AntiKt4TruthJets_WZ_flavor_partonFlavor;   //!
   TBranch        *b_jet_AntiKt4TruthJets_WZ_flavor_hadronFlavor;   //!
   TBranch        *b_jet_AntiKt4TruthJets_WZ_flavor_hadronPDGID;   //!
   TBranch        *b_jet_AntiKt6TruthJets_WZ_n;   //!
   TBranch        *b_jet_AntiKt6TruthJets_WZ_E;   //!
   TBranch        *b_jet_AntiKt6TruthJets_WZ_pt;   //!
   TBranch        *b_jet_AntiKt6TruthJets_WZ_m;   //!
   TBranch        *b_jet_AntiKt6TruthJets_WZ_eta;   //!
   TBranch        *b_jet_AntiKt6TruthJets_WZ_phi;   //!
   TBranch        *b_jet_AntiKt6TruthJets_WZ_flavor_partonDR;   //!
   TBranch        *b_jet_AntiKt6TruthJets_WZ_flavor_partonFlavor;   //!
   TBranch        *b_jet_AntiKt6TruthJets_WZ_flavor_hadronFlavor;   //!
   TBranch        *b_jet_AntiKt6TruthJets_WZ_flavor_hadronPDGID;   //!
   TBranch        *b_mc_n;   //!
   TBranch        *b_mc_E;   //!
   TBranch        *b_mc_pt;   //!
   TBranch        *b_mc_m;   //!
   TBranch        *b_mc_eta;   //!
   TBranch        *b_mc_phi;   //!
   TBranch        *b_mc_status;   //!
   TBranch        *b_mc_barcode;   //!
   TBranch        *b_mc_pdgId;   //!
   TBranch        *b_mc_charge;   //!
   TBranch        *b_mc_parents;   //!
   TBranch        *b_mc_children;   //!
   TBranch        *b_mc_vx_x;   //!
   TBranch        *b_mc_vx_y;   //!
   TBranch        *b_mc_vx_z;   //!
   TBranch        *b_mc_vx_barcode;   //!
   TBranch        *b_mc_child_index;   //!
   TBranch        *b_mc_parent_index;   //!
   TBranch        *b_MET_Truth_NonInt_etx;   //!
   TBranch        *b_MET_Truth_NonInt_ety;   //!
   TBranch        *b_MET_Truth_Int_etx;   //!
   TBranch        *b_MET_Truth_Int_ety;   //!
   TBranch        *b_MET_Truth_IntCentral_etx;   //!
   TBranch        *b_MET_Truth_IntCentral_ety;   //!
   TBranch        *b_MET_Truth_IntFwd_etx;   //!
   TBranch        *b_MET_Truth_IntFwd_ety;   //!
   TBranch        *b_MET_Truth_IntOutCover_etx;   //!
   TBranch        *b_MET_Truth_IntOutCover_ety;   //!
   TBranch        *b_MET_Truth_IntMuons_etx;   //!
   TBranch        *b_MET_Truth_IntMuons_ety;   //!
   TBranch        *b_el_n;   //!
   TBranch        *b_el_pt;   //!
   TBranch        *b_el_m;   //!
   TBranch        *b_el_eta;   //!
   TBranch        *b_el_phi;   //!
   TBranch        *b_el_status;   //!
   TBranch        *b_el_barcode;   //!
   TBranch        *b_el_charge;   //!
   TBranch        *b_el_dressed_pt;   //!
   TBranch        *b_el_dressed_eta;   //!
   TBranch        *b_el_dressed_phi;   //!
   TBranch        *b_el_dressed_m;   //!
   TBranch        *b_el_iso02;   //!
   TBranch        *b_el_iso03;   //!
   TBranch        *b_el_parent_index;   //!
   TBranch        *b_mu_n;   //!
   TBranch        *b_mu_pt;   //!
   TBranch        *b_mu_m;   //!
   TBranch        *b_mu_eta;   //!
   TBranch        *b_mu_phi;   //!
   TBranch        *b_mu_status;   //!
   TBranch        *b_mu_barcode;   //!
   TBranch        *b_mu_charge;   //!
   TBranch        *b_mu_dressed_pt;   //!
   TBranch        *b_mu_dressed_eta;   //!
   TBranch        *b_mu_dressed_phi;   //!
   TBranch        *b_mu_dressed_m;   //!
   TBranch        *b_mu_iso02;   //!
   TBranch        *b_mu_iso03;   //!
   TBranch        *b_mu_parent_index;   //!
   TBranch        *b_tau_n;   //!
   TBranch        *b_tau_pt;   //!
   TBranch        *b_tau_m;   //!
   TBranch        *b_tau_eta;   //!
   TBranch        *b_tau_phi;   //!
   TBranch        *b_tau_status;   //!
   TBranch        *b_tau_barcode;   //!
   TBranch        *b_tau_charge;   //!
   TBranch        *b_tau_parent_index;   //!
   TBranch        *b_tau_decay_index;   //!
   TBranch        *b_ph_n;   //!
   TBranch        *b_ph_pt;   //!
   TBranch        *b_ph_m;   //!
   TBranch        *b_ph_eta;   //!
   TBranch        *b_ph_phi;   //!
   TBranch        *b_ph_status;   //!
   TBranch        *b_ph_barcode;   //!

   TZ_D3PD(TTree *tree=0);
   virtual ~TZ_D3PD();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef TZ_D3PD_cxx
TZ_D3PD::TZ_D3PD(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("MC12_8TeV.110491.NTUP_TRUTH.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("MC12_8TeV.110491.NTUP_TRUTH.root");
      }
      f->GetObject("truth",tree);

   }
   Init(tree);
}

TZ_D3PD::~TZ_D3PD()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t TZ_D3PD::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t TZ_D3PD::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (fChain->GetTreeNumber() != fCurrent) {
      fCurrent = fChain->GetTreeNumber();
      Notify();
   }
   return centry;
}

void TZ_D3PD::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set object pointer
   mcevt_signal_process_id = 0;
   mcevt_event_number = 0;
   mcevt_event_scale = 0;
   mcevt_alphaQCD = 0;
   mcevt_alphaQED = 0;
   mcevt_pdf_id1 = 0;
   mcevt_pdf_id2 = 0;
   mcevt_pdf_x1 = 0;
   mcevt_pdf_x2 = 0;
   mcevt_pdf_scale = 0;
   mcevt_pdf1 = 0;
   mcevt_pdf2 = 0;
   mcevt_weight = 0;
   jet_AntiKt4TruthJets_E = 0;
   jet_AntiKt4TruthJets_pt = 0;
   jet_AntiKt4TruthJets_m = 0;
   jet_AntiKt4TruthJets_eta = 0;
   jet_AntiKt4TruthJets_phi = 0;
   jet_AntiKt4TruthJets_flavor_partonDR = 0;
   jet_AntiKt4TruthJets_flavor_partonFlavor = 0;
   jet_AntiKt4TruthJets_flavor_hadronFlavor = 0;
   jet_AntiKt4TruthJets_flavor_hadronPDGID = 0;
   jet_AntiKt4TruthJets_WZ_E = 0;
   jet_AntiKt4TruthJets_WZ_pt = 0;
   jet_AntiKt4TruthJets_WZ_m = 0;
   jet_AntiKt4TruthJets_WZ_eta = 0;
   jet_AntiKt4TruthJets_WZ_phi = 0;
   jet_AntiKt4TruthJets_WZ_flavor_partonDR = 0;
   jet_AntiKt4TruthJets_WZ_flavor_partonFlavor = 0;
   jet_AntiKt4TruthJets_WZ_flavor_hadronFlavor = 0;
   jet_AntiKt4TruthJets_WZ_flavor_hadronPDGID = 0;
   jet_AntiKt6TruthJets_WZ_E = 0;
   jet_AntiKt6TruthJets_WZ_pt = 0;
   jet_AntiKt6TruthJets_WZ_m = 0;
   jet_AntiKt6TruthJets_WZ_eta = 0;
   jet_AntiKt6TruthJets_WZ_phi = 0;
   jet_AntiKt6TruthJets_WZ_flavor_partonDR = 0;
   jet_AntiKt6TruthJets_WZ_flavor_partonFlavor = 0;
   jet_AntiKt6TruthJets_WZ_flavor_hadronFlavor = 0;
   jet_AntiKt6TruthJets_WZ_flavor_hadronPDGID = 0;
   mc_E = 0;
   mc_pt = 0;
   mc_m = 0;
   mc_eta = 0;
   mc_phi = 0;
   mc_status = 0;
   mc_barcode = 0;
   mc_pdgId = 0;
   mc_charge = 0;
   mc_parents = 0;
   mc_children = 0;
   mc_vx_x = 0;
   mc_vx_y = 0;
   mc_vx_z = 0;
   mc_vx_barcode = 0;
   mc_child_index = 0;
   mc_parent_index = 0;
   el_pt = 0;
   el_m = 0;
   el_eta = 0;
   el_phi = 0;
   el_status = 0;
   el_barcode = 0;
   el_charge = 0;
   el_dressed_pt = 0;
   el_dressed_eta = 0;
   el_dressed_phi = 0;
   el_dressed_m = 0;
   el_iso02 = 0;
   el_iso03 = 0;
   el_parent_index = 0;
   mu_pt = 0;
   mu_m = 0;
   mu_eta = 0;
   mu_phi = 0;
   mu_status = 0;
   mu_barcode = 0;
   mu_charge = 0;
   mu_dressed_pt = 0;
   mu_dressed_eta = 0;
   mu_dressed_phi = 0;
   mu_dressed_m = 0;
   mu_iso02 = 0;
   mu_iso03 = 0;
   mu_parent_index = 0;
   tau_pt = 0;
   tau_m = 0;
   tau_eta = 0;
   tau_phi = 0;
   tau_status = 0;
   tau_barcode = 0;
   tau_charge = 0;
   tau_parent_index = 0;
   tau_decay_index = 0;
   ph_pt = 0;
   ph_m = 0;
   ph_eta = 0;
   ph_phi = 0;
   ph_status = 0;
   ph_barcode = 0;
   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("RunNumber", &RunNumber, &b_RunNumber);
   fChain->SetBranchAddress("EventNumber", &EventNumber, &b_EventNumber);
   fChain->SetBranchAddress("mc_channel_number", &mc_channel_number, &b_mc_channel_number);
   fChain->SetBranchAddress("mc_event_number", &mc_event_number, &b_mc_event_number);
   fChain->SetBranchAddress("mc_event_weight", &mc_event_weight, &b_mc_event_weight);
   fChain->SetBranchAddress("mcevt_n", &mcevt_n, &b_mcevt_n);
   fChain->SetBranchAddress("mcevt_signal_process_id", &mcevt_signal_process_id, &b_mcevt_signal_process_id);
   fChain->SetBranchAddress("mcevt_event_number", &mcevt_event_number, &b_mcevt_event_number);
   fChain->SetBranchAddress("mcevt_event_scale", &mcevt_event_scale, &b_mcevt_event_scale);
   fChain->SetBranchAddress("mcevt_alphaQCD", &mcevt_alphaQCD, &b_mcevt_alphaQCD);
   fChain->SetBranchAddress("mcevt_alphaQED", &mcevt_alphaQED, &b_mcevt_alphaQED);
   fChain->SetBranchAddress("mcevt_pdf_id1", &mcevt_pdf_id1, &b_mcevt_pdf_id1);
   fChain->SetBranchAddress("mcevt_pdf_id2", &mcevt_pdf_id2, &b_mcevt_pdf_id2);
   fChain->SetBranchAddress("mcevt_pdf_x1", &mcevt_pdf_x1, &b_mcevt_pdf_x1);
   fChain->SetBranchAddress("mcevt_pdf_x2", &mcevt_pdf_x2, &b_mcevt_pdf_x2);
   fChain->SetBranchAddress("mcevt_pdf_scale", &mcevt_pdf_scale, &b_mcevt_pdf_scale);
   fChain->SetBranchAddress("mcevt_pdf1", &mcevt_pdf1, &b_mcevt_pdf1);
   fChain->SetBranchAddress("mcevt_pdf2", &mcevt_pdf2, &b_mcevt_pdf2);
   fChain->SetBranchAddress("mcevt_weight", &mcevt_weight, &b_mcevt_weight);
   fChain->SetBranchAddress("jet_AntiKt4TruthJets_n", &jet_AntiKt4TruthJets_n, &b_jet_AntiKt4TruthJets_n);
   fChain->SetBranchAddress("jet_AntiKt4TruthJets_E", &jet_AntiKt4TruthJets_E, &b_jet_AntiKt4TruthJets_E);
   fChain->SetBranchAddress("jet_AntiKt4TruthJets_pt", &jet_AntiKt4TruthJets_pt, &b_jet_AntiKt4TruthJets_pt);
   fChain->SetBranchAddress("jet_AntiKt4TruthJets_m", &jet_AntiKt4TruthJets_m, &b_jet_AntiKt4TruthJets_m);
   fChain->SetBranchAddress("jet_AntiKt4TruthJets_eta", &jet_AntiKt4TruthJets_eta, &b_jet_AntiKt4TruthJets_eta);
   fChain->SetBranchAddress("jet_AntiKt4TruthJets_phi", &jet_AntiKt4TruthJets_phi, &b_jet_AntiKt4TruthJets_phi);
   fChain->SetBranchAddress("jet_AntiKt4TruthJets_flavor_partonDR", &jet_AntiKt4TruthJets_flavor_partonDR, &b_jet_AntiKt4TruthJets_flavor_partonDR);
   fChain->SetBranchAddress("jet_AntiKt4TruthJets_flavor_partonFlavor", &jet_AntiKt4TruthJets_flavor_partonFlavor, &b_jet_AntiKt4TruthJets_flavor_partonFlavor);
   fChain->SetBranchAddress("jet_AntiKt4TruthJets_flavor_hadronFlavor", &jet_AntiKt4TruthJets_flavor_hadronFlavor, &b_jet_AntiKt4TruthJets_flavor_hadronFlavor);
   fChain->SetBranchAddress("jet_AntiKt4TruthJets_flavor_hadronPDGID", &jet_AntiKt4TruthJets_flavor_hadronPDGID, &b_jet_AntiKt4TruthJets_flavor_hadronPDGID);
   fChain->SetBranchAddress("jet_AntiKt4TruthJets_WZ_n", &jet_AntiKt4TruthJets_WZ_n, &b_jet_AntiKt4TruthJets_WZ_n);
   fChain->SetBranchAddress("jet_AntiKt4TruthJets_WZ_E", &jet_AntiKt4TruthJets_WZ_E, &b_jet_AntiKt4TruthJets_WZ_E);
   fChain->SetBranchAddress("jet_AntiKt4TruthJets_WZ_pt", &jet_AntiKt4TruthJets_WZ_pt, &b_jet_AntiKt4TruthJets_WZ_pt);
   fChain->SetBranchAddress("jet_AntiKt4TruthJets_WZ_m", &jet_AntiKt4TruthJets_WZ_m, &b_jet_AntiKt4TruthJets_WZ_m);
   fChain->SetBranchAddress("jet_AntiKt4TruthJets_WZ_eta", &jet_AntiKt4TruthJets_WZ_eta, &b_jet_AntiKt4TruthJets_WZ_eta);
   fChain->SetBranchAddress("jet_AntiKt4TruthJets_WZ_phi", &jet_AntiKt4TruthJets_WZ_phi, &b_jet_AntiKt4TruthJets_WZ_phi);
   fChain->SetBranchAddress("jet_AntiKt4TruthJets_WZ_flavor_partonDR", &jet_AntiKt4TruthJets_WZ_flavor_partonDR, &b_jet_AntiKt4TruthJets_WZ_flavor_partonDR);
   fChain->SetBranchAddress("jet_AntiKt4TruthJets_WZ_flavor_partonFlavor", &jet_AntiKt4TruthJets_WZ_flavor_partonFlavor, &b_jet_AntiKt4TruthJets_WZ_flavor_partonFlavor);
   fChain->SetBranchAddress("jet_AntiKt4TruthJets_WZ_flavor_hadronFlavor", &jet_AntiKt4TruthJets_WZ_flavor_hadronFlavor, &b_jet_AntiKt4TruthJets_WZ_flavor_hadronFlavor);
   fChain->SetBranchAddress("jet_AntiKt4TruthJets_WZ_flavor_hadronPDGID", &jet_AntiKt4TruthJets_WZ_flavor_hadronPDGID, &b_jet_AntiKt4TruthJets_WZ_flavor_hadronPDGID);
   fChain->SetBranchAddress("jet_AntiKt6TruthJets_WZ_n", &jet_AntiKt6TruthJets_WZ_n, &b_jet_AntiKt6TruthJets_WZ_n);
   fChain->SetBranchAddress("jet_AntiKt6TruthJets_WZ_E", &jet_AntiKt6TruthJets_WZ_E, &b_jet_AntiKt6TruthJets_WZ_E);
   fChain->SetBranchAddress("jet_AntiKt6TruthJets_WZ_pt", &jet_AntiKt6TruthJets_WZ_pt, &b_jet_AntiKt6TruthJets_WZ_pt);
   fChain->SetBranchAddress("jet_AntiKt6TruthJets_WZ_m", &jet_AntiKt6TruthJets_WZ_m, &b_jet_AntiKt6TruthJets_WZ_m);
   fChain->SetBranchAddress("jet_AntiKt6TruthJets_WZ_eta", &jet_AntiKt6TruthJets_WZ_eta, &b_jet_AntiKt6TruthJets_WZ_eta);
   fChain->SetBranchAddress("jet_AntiKt6TruthJets_WZ_phi", &jet_AntiKt6TruthJets_WZ_phi, &b_jet_AntiKt6TruthJets_WZ_phi);
   fChain->SetBranchAddress("jet_AntiKt6TruthJets_WZ_flavor_partonDR", &jet_AntiKt6TruthJets_WZ_flavor_partonDR, &b_jet_AntiKt6TruthJets_WZ_flavor_partonDR);
   fChain->SetBranchAddress("jet_AntiKt6TruthJets_WZ_flavor_partonFlavor", &jet_AntiKt6TruthJets_WZ_flavor_partonFlavor, &b_jet_AntiKt6TruthJets_WZ_flavor_partonFlavor);
   fChain->SetBranchAddress("jet_AntiKt6TruthJets_WZ_flavor_hadronFlavor", &jet_AntiKt6TruthJets_WZ_flavor_hadronFlavor, &b_jet_AntiKt6TruthJets_WZ_flavor_hadronFlavor);
   fChain->SetBranchAddress("jet_AntiKt6TruthJets_WZ_flavor_hadronPDGID", &jet_AntiKt6TruthJets_WZ_flavor_hadronPDGID, &b_jet_AntiKt6TruthJets_WZ_flavor_hadronPDGID);
   fChain->SetBranchAddress("mc_n", &mc_n, &b_mc_n);
   fChain->SetBranchAddress("mc_E", &mc_E, &b_mc_E);
   fChain->SetBranchAddress("mc_pt", &mc_pt, &b_mc_pt);
   fChain->SetBranchAddress("mc_m", &mc_m, &b_mc_m);
   fChain->SetBranchAddress("mc_eta", &mc_eta, &b_mc_eta);
   fChain->SetBranchAddress("mc_phi", &mc_phi, &b_mc_phi);
   fChain->SetBranchAddress("mc_status", &mc_status, &b_mc_status);
   fChain->SetBranchAddress("mc_barcode", &mc_barcode, &b_mc_barcode);
   fChain->SetBranchAddress("mc_pdgId", &mc_pdgId, &b_mc_pdgId);
   fChain->SetBranchAddress("mc_charge", &mc_charge, &b_mc_charge);
   fChain->SetBranchAddress("mc_parents", &mc_parents, &b_mc_parents);
   fChain->SetBranchAddress("mc_children", &mc_children, &b_mc_children);
   fChain->SetBranchAddress("mc_vx_x", &mc_vx_x, &b_mc_vx_x);
   fChain->SetBranchAddress("mc_vx_y", &mc_vx_y, &b_mc_vx_y);
   fChain->SetBranchAddress("mc_vx_z", &mc_vx_z, &b_mc_vx_z);
   fChain->SetBranchAddress("mc_vx_barcode", &mc_vx_barcode, &b_mc_vx_barcode);
   fChain->SetBranchAddress("mc_child_index", &mc_child_index, &b_mc_child_index);
   fChain->SetBranchAddress("mc_parent_index", &mc_parent_index, &b_mc_parent_index);
   fChain->SetBranchAddress("MET_Truth_NonInt_etx", &MET_Truth_NonInt_etx, &b_MET_Truth_NonInt_etx);
   fChain->SetBranchAddress("MET_Truth_NonInt_ety", &MET_Truth_NonInt_ety, &b_MET_Truth_NonInt_ety);
   fChain->SetBranchAddress("MET_Truth_Int_etx", &MET_Truth_Int_etx, &b_MET_Truth_Int_etx);
   fChain->SetBranchAddress("MET_Truth_Int_ety", &MET_Truth_Int_ety, &b_MET_Truth_Int_ety);
   fChain->SetBranchAddress("MET_Truth_IntCentral_etx", &MET_Truth_IntCentral_etx, &b_MET_Truth_IntCentral_etx);
   fChain->SetBranchAddress("MET_Truth_IntCentral_ety", &MET_Truth_IntCentral_ety, &b_MET_Truth_IntCentral_ety);
   fChain->SetBranchAddress("MET_Truth_IntFwd_etx", &MET_Truth_IntFwd_etx, &b_MET_Truth_IntFwd_etx);
   fChain->SetBranchAddress("MET_Truth_IntFwd_ety", &MET_Truth_IntFwd_ety, &b_MET_Truth_IntFwd_ety);
   fChain->SetBranchAddress("MET_Truth_IntOutCover_etx", &MET_Truth_IntOutCover_etx, &b_MET_Truth_IntOutCover_etx);
   fChain->SetBranchAddress("MET_Truth_IntOutCover_ety", &MET_Truth_IntOutCover_ety, &b_MET_Truth_IntOutCover_ety);
   fChain->SetBranchAddress("MET_Truth_IntMuons_etx", &MET_Truth_IntMuons_etx, &b_MET_Truth_IntMuons_etx);
   fChain->SetBranchAddress("MET_Truth_IntMuons_ety", &MET_Truth_IntMuons_ety, &b_MET_Truth_IntMuons_ety);
   fChain->SetBranchAddress("el_n", &el_n, &b_el_n);
   fChain->SetBranchAddress("el_pt", &el_pt, &b_el_pt);
   fChain->SetBranchAddress("el_m", &el_m, &b_el_m);
   fChain->SetBranchAddress("el_eta", &el_eta, &b_el_eta);
   fChain->SetBranchAddress("el_phi", &el_phi, &b_el_phi);
   fChain->SetBranchAddress("el_status", &el_status, &b_el_status);
   fChain->SetBranchAddress("el_barcode", &el_barcode, &b_el_barcode);
   fChain->SetBranchAddress("el_charge", &el_charge, &b_el_charge);
   fChain->SetBranchAddress("el_dressed_pt", &el_dressed_pt, &b_el_dressed_pt);
   fChain->SetBranchAddress("el_dressed_eta", &el_dressed_eta, &b_el_dressed_eta);
   fChain->SetBranchAddress("el_dressed_phi", &el_dressed_phi, &b_el_dressed_phi);
   fChain->SetBranchAddress("el_dressed_m", &el_dressed_m, &b_el_dressed_m);
   fChain->SetBranchAddress("el_iso02", &el_iso02, &b_el_iso02);
   fChain->SetBranchAddress("el_iso03", &el_iso03, &b_el_iso03);
   fChain->SetBranchAddress("el_parent_index", &el_parent_index, &b_el_parent_index);
   fChain->SetBranchAddress("mu_n", &mu_n, &b_mu_n);
   fChain->SetBranchAddress("mu_pt", &mu_pt, &b_mu_pt);
   fChain->SetBranchAddress("mu_m", &mu_m, &b_mu_m);
   fChain->SetBranchAddress("mu_eta", &mu_eta, &b_mu_eta);
   fChain->SetBranchAddress("mu_phi", &mu_phi, &b_mu_phi);
   fChain->SetBranchAddress("mu_status", &mu_status, &b_mu_status);
   fChain->SetBranchAddress("mu_barcode", &mu_barcode, &b_mu_barcode);
   fChain->SetBranchAddress("mu_charge", &mu_charge, &b_mu_charge);
   fChain->SetBranchAddress("mu_dressed_pt", &mu_dressed_pt, &b_mu_dressed_pt);
   fChain->SetBranchAddress("mu_dressed_eta", &mu_dressed_eta, &b_mu_dressed_eta);
   fChain->SetBranchAddress("mu_dressed_phi", &mu_dressed_phi, &b_mu_dressed_phi);
   fChain->SetBranchAddress("mu_dressed_m", &mu_dressed_m, &b_mu_dressed_m);
   fChain->SetBranchAddress("mu_iso02", &mu_iso02, &b_mu_iso02);
   fChain->SetBranchAddress("mu_iso03", &mu_iso03, &b_mu_iso03);
   fChain->SetBranchAddress("mu_parent_index", &mu_parent_index, &b_mu_parent_index);
   fChain->SetBranchAddress("tau_n", &tau_n, &b_tau_n);
   fChain->SetBranchAddress("tau_pt", &tau_pt, &b_tau_pt);
   fChain->SetBranchAddress("tau_m", &tau_m, &b_tau_m);
   fChain->SetBranchAddress("tau_eta", &tau_eta, &b_tau_eta);
   fChain->SetBranchAddress("tau_phi", &tau_phi, &b_tau_phi);
   fChain->SetBranchAddress("tau_status", &tau_status, &b_tau_status);
   fChain->SetBranchAddress("tau_barcode", &tau_barcode, &b_tau_barcode);
   fChain->SetBranchAddress("tau_charge", &tau_charge, &b_tau_charge);
   fChain->SetBranchAddress("tau_parent_index", &tau_parent_index, &b_tau_parent_index);
   fChain->SetBranchAddress("tau_decay_index", &tau_decay_index, &b_tau_decay_index);
   fChain->SetBranchAddress("ph_n", &ph_n, &b_ph_n);
   fChain->SetBranchAddress("ph_pt", &ph_pt, &b_ph_pt);
   fChain->SetBranchAddress("ph_m", &ph_m, &b_ph_m);
   fChain->SetBranchAddress("ph_eta", &ph_eta, &b_ph_eta);
   fChain->SetBranchAddress("ph_phi", &ph_phi, &b_ph_phi);
   fChain->SetBranchAddress("ph_status", &ph_status, &b_ph_status);
   fChain->SetBranchAddress("ph_barcode", &ph_barcode, &b_ph_barcode);
   Notify();
}

Bool_t TZ_D3PD::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void TZ_D3PD::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t TZ_D3PD::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
  entry=1;
   return 1;
}
#endif // #ifdef TZ_D3PD_cxx
