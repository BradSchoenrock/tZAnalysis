#include "ztAnalysis.h"
#include "Loop.C"
//#include "TopD3PD.C"

//typedef TopD3PD D3PDEvent;

int main(int argc, char **argv) {
   lum = 21.7; // units of fb
   detString = "pp #sqrt{s} = 8 TeV"; 
   outputDir = "./output";

   minMET = 5;

   minJet = 2;
   maxJet = 3;
   minJetPt = 5;
   maxJetEta = 4.5;

   nTag = 1;
   minBJetPt = 5;
   maxBJetEta = 2.5;

   minElectronPt = 5;
   maxElectronEta = 2.5;

   minMuonPt = 5;
   maxMuonEta = 2.5;

   nlep = 3;
    
   string line;
   ifstream sampleFileIn(argv[1]);
   if (!sampleFileIn.is_open()) {
      cerr << "file = " << argv[1] << " not open! " << endl;
      return -1;
   }
   string numIn(argv[2]);

   vector<string> paths; 
   vector<float> xsecs;
   vector<string> names;
   vector<int> colors;
   while(getline(sampleFileIn,line)) {
      string token;
      stringstream lineStream;
      int counter = 0;
      lineStream << line;
      while(lineStream >> token) {
	if (counter == 0) {
            paths.push_back(token);
	    //cout<<"token = "<<token<<endl;
	}
         else if (counter == 1) 
            xsecs.push_back(atof(token.c_str()));
         else if (counter == 2) 
            names.push_back(token);
         else if (counter == 3)
            colors.push_back(atoi(token.c_str()));
         else {
            cerr << "line = " << line << " has too many columns!" << endl; 
         }
         counter++;
      }
   }
   for (unsigned int isample = 0; isample < paths.size(); isample++) {
     cout << "path = " << paths[isample] << " xsec [pb] = " << xsecs[isample] << " names = " << names[isample] << " and color = " << colors[isample] << endl;
   }

   SetStyle();
   thedir = gDirectory;
   TLegend *leg = new TLegend(0.53,0.79,0.94,0.97);
   TLegend *leg2 = new TLegend(0.53,0.79,0.94,0.97);
   leg->SetFillColor(0);
   leg->SetLineColor(0);
   leg->SetShadowColor(0);
   leg2->SetFillColor(0);
   leg2->SetLineColor(0);
   leg2->SetShadowColor(0);
   unsigned int itype = 0;
    
   hist_struct *thisstruct = new hist_struct;
   InitStruct(thisstruct, names[itype], colors[itype]);
   TChain *ch = new TChain("mini");
   ch->Add(paths[itype].c_str());
   //cout<<"just added to ch "<<paths[itype].c_str()<<'\n';
   cout << '\n'<<"about to loop over " << names[itype] << endl;
   ofstream myfile;
   myfile.open("NEvents.txt", ios::in|ios::app);
   myfile.seekp(0,ios_base::end);
   myfile<<names[itype]<<'\n';
   myfile.close();
   //cout<<"lum="<<(double)lum<<'\n'<<"xsec="<<xsecs[itype]<<'\n'<<"ch->GetEntries()="<<ch->GetEntries()<<'\n';
   // cout<<"before loop"<<'\n';
   Loop(ch, xsecs[itype], thisstruct);
   //cout<<"after loop"<<'\n';
   delete ch;
   //delete thisstruct;
   
   stringstream ss("");
   ss<<(string)"output/fout";
   ss<<numIn;
   ss<<(string)".root";
   string s2;
   ss>>s2;
   cout<<s2<<'\n';
   const char* nam=s2.c_str();

   TFile *fout = new TFile(nam,"RECREATE"); 
   fout->cd();

   for (unsigned int istack = 0; istack < histNameVec.size(); istack++) {
     vector<TH1F> thethifs;
     int n=-1;
         
     for (unsigned int itype = 0; itype < paths.size(); itype++) {
       //cout<<"itype="<<itype<<'\n';
       
       //cout<<"names[itype]="<<names[itype]<<'\n';
       
       string fullname = histNameVec[istack]+"_"+names[itype];
       //cout<<"fullname.c_str()="<<fullname.c_str()<<'\n';
       
       TH1F *hist = allHists.at(istack);  //(TH1F*)thedir->FindObjectAny(fullname.c_str());
       hist->SetNameTitle(histNameVec[istack].c_str(),histNameVec[istack].c_str());
       if (!hist) cerr << "BAD! Could not find " << fullname << endl;
       else {	 
	 hist->SetFillColor(colors[itype]);
	 hist->SetLineColor(colors[itype]);
	 	
	 thethifs.push_back(*hist);
	 hist->Write();
	 n++;
	
       }
     }
     
     gStyle->SetOptStat(0);
         
   }   
   fout->Write();
   delete fout;
   delete thisstruct;

}

