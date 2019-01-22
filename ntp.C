#define ntp_cxx
#include "ntp.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>

void ntp::Loop()
{
//   In a ROOT session, you can do:
//      root> .L ntp.C
//      root> ntp t
//      root> t.GetEntry(12); // Fill t data members with entry number 12
//      root> t.Show();       // Show values of entry 12
//      root> t.Show(16);     // Read and show values of entry 16
//      root> t.Loop();       // Loop on all entries
//

//     This is the loop skeleton where:
//    jentry is the global entry number in the chain
//    ientry is the entry number in the current Tree
//  Note that the argument to GetEntry must be:
//    jentry for TChain::GetEntry
//    ientry for TTree::GetEntry and TBranch::GetEntry
//
//       To read only selected branches, Insert statements like:
// METHOD1:
//    fChain->SetBranchStatus("*",0);  // disable all branches
//    fChain->SetBranchStatus("branchname",1);  // activate branchname
// METHOD2: replace line
//    fChain->GetEntry(jentry);       //read all branches
//by  b_branchname->GetEntry(ientry); //read only this branch

   TFile *mva = new TFile("mva.root", "RECREATE");
   TTree *sigTree = new TTree("sigTree","sigTree");

   double csv3Sig;
   double csv4Sig;
   double jetPt3Sig;
   double jetPt4Sig;
   double jetEta3Sig;
   double jetEta4Sig;
   double jetPhi3Sig;
   double jetPhi4Sig;
   double jetM3Sig;
   double jetM4Sig;
   double bbMSig;
   double bbDRSig;
   int nbjetMSig;
   int nbjetTSig;

   sigTree->Branch("csv3",&csv3Sig);
   sigTree->Branch("csv4",&csv4Sig);
   sigTree->Branch("jetPt3",&jetPt3Sig);
   sigTree->Branch("jetPt4",&jetPt4Sig);
   sigTree->Branch("jetEta3",&jetEta3Sig);
   sigTree->Branch("jetEta4",&jetEta4Sig);
   sigTree->Branch("jetPhi3",&jetPhi3Sig);
   sigTree->Branch("jetPhi4",&jetPhi4Sig);
   sigTree->Branch("jetM3",&jetM3Sig);
   sigTree->Branch("jetM4",&jetM4Sig);
   sigTree->Branch("bbM",&bbMSig);
   sigTree->Branch("bbDR",&bbDRSig);
   sigTree->Branch("nbjetM",&nbjetMSig);
   sigTree->Branch("nbjetT",&nbjetTSig);

   TTree *bkgTree = new TTree("bkgTree","bkgTree");

   double csv3Bkg;
   double csv4Bkg;
   double jetPt3Bkg;
   double jetPt4Bkg;
   double jetEta3Bkg;
   double jetEta4Bkg;
   double jetPhi3Bkg;
   double jetPhi4Bkg;
   double jetM3Bkg;
   double jetM4Bkg;
   double bbMBkg;
   double bbDRBkg;
   int nbjetMBkg;
   int nbjetTBkg;

   bkgTree->Branch("csv3",&csv3Bkg);
   bkgTree->Branch("csv4",&csv4Bkg);
   bkgTree->Branch("jetPt3",&jetPt3Bkg);
   bkgTree->Branch("jetPt4",&jetPt4Bkg);
   bkgTree->Branch("jetEta3",&jetEta3Bkg);
   bkgTree->Branch("jetEta4",&jetEta4Bkg);
   bkgTree->Branch("jetPhi3",&jetPhi3Bkg);
   bkgTree->Branch("jetPhi4",&jetPhi4Bkg);
   bkgTree->Branch("jetM3",&jetM3Bkg);
   bkgTree->Branch("jetM4",&jetM4Bkg);
   bkgTree->Branch("bbM",&bbMBkg);
   bkgTree->Branch("bbDR",&bbDRBkg);
   bkgTree->Branch("nbjetM",&nbjetMBkg);
   bkgTree->Branch("nbjetT",&nbjetTBkg);

   ofstream inputX;
   ofstream inputY;
   inputX.open ("inputX.txt");
   inputY.open ("inputY.txt");
   if (fChain == 0) return;

   Long64_t nentries = fChain->GetEntriesFast();

   //cout << fChain->GetEntries("NJets30>=4 && NbJets30>=4 && lepton1_pt>20 && lepton2_pt>20 && abs(lepton1_eta)<2.4 && abs(lepton2_eta)<2.4") << endl;
   Long64_t nbytes = 0, nb = 0;
   int nttbb = 0;
   int nttbj = 0;
   int nttccLF = 0;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
   //for (Long64_t jentry=0; jentry<100;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;

      if (step<5 or filtered!=1 or tri<=0 or channel==0) continue;
      //if (nttbb == 10000 && nttbj ==10000 && nttccLF == 10000) break;
      if (nttbb >= 20000 && nttccLF >= 20000) break;
      //if (nttbb >= 3 && nttccLF >= 3) break;
      double jetPt3 = jets_pt->at(csvd_jetid->at(2));
      double jetPt4 = jets_pt->at(csvd_jetid->at(3));
      double jetEta3 = jets_eta->at(csvd_jetid->at(2));
      double jetEta4 = jets_eta->at(csvd_jetid->at(3));
      double jetPhi3 = jets_phi->at(csvd_jetid->at(2));
      double jetPhi4 = jets_phi->at(csvd_jetid->at(3));
      double jetM3 = jets_m->at(csvd_jetid->at(2));
      double jetM4 = jets_m->at(csvd_jetid->at(3));
      double csv3 = jets_bDiscriminatorCSV->at(csvd_jetid->at(2));
      double csv4 = jets_bDiscriminatorCSV->at(csvd_jetid->at(3));
      char* input = Form("%f %f %f %f %f %f %f %f %f %f %f %f %i %i", jetPt3, jetPt4, jetEta3, jetEta4, jetPhi3, jetPhi4, jetM3, jetM4, csv3, csv4, bbM, bbDR, nbjetM30, nbjetT30);

/*
      cout << jentry*100./nentries << " " << nttbb << " " << nttbj << " " << nttccLF << endl;

      if (NJets30>=4 && NbJets30>=4 && lepton1_pt>20 && lepton2_pt>20 && abs(lepton1_eta)<2.4 && abs(lepton2_eta)<2.4) {
        if (nttbb>= 10000) continue;
        nttbb += 1;
        inputX << input << endl; 
        inputY << "1 0 0" << endl;
        
      }
      else if (NJets30>=4 && NbJets30==3 && lepton1_pt>20 && lepton2_pt>20 && abs(lepton1_eta)<2.4 && abs(lepton2_eta)<2.4) {
        if (nttbj>= 10000) continue;
        nttbj += 1;
        inputX << input << endl; 
        inputY << "0 1 0" << endl;
        
      }
*/
      cout << jentry*100./nentries << " " << nttbb << " " << nttccLF << endl;
      if (NJets30>=4 && NbJets30>=3 && lepton1_pt>20 && lepton2_pt>20 && abs(lepton1_eta)<2.4 && abs(lepton2_eta)<2.4) {
        if (nttbb>= 20000) continue;
        csv3Sig = csv3;
        csv4Sig = csv4;
        jetPt3Sig = jetPt3;
        jetPt4Sig = jetPt4;
        jetEta3Sig = jetEta3;
        jetEta4Sig = jetEta4;
        jetPhi3Sig = jetPhi3;
        jetPhi4Sig = jetPhi4;
        jetM3Sig = jetM3;
        jetM4Sig = jetM4;
        bbMSig = bbM;
        bbDRSig = bbDR;
        nbjetMSig = nbjetM30;
        nbjetTSig = nbjetT30;
        sigTree->Fill();
        nttbb += 1;
        inputX << input << endl; 
        inputY << "1" << endl;
        
      }
      else if (NJets30>=4 && lepton1_pt>20 && lepton2_pt>20 && abs(lepton1_eta)<2.4 && abs(lepton2_eta)<2.4) {
      //else {
        if (nttccLF>= 20000) continue;
        csv3Bkg = csv3;
        csv4Bkg = csv4;
        jetPt3Bkg = jetPt3;
        jetPt4Bkg = jetPt4;
        jetEta3Bkg = jetEta3;
        jetEta4Bkg = jetEta4;
        jetPhi3Bkg = jetPhi3;
        jetPhi4Bkg = jetPhi4;
        jetM3Bkg = jetM3;
        jetM4Bkg = jetM4;
        bbMBkg = bbM;
        bbDRBkg = bbDR;
        nbjetMBkg = nbjetM30;
        nbjetTBkg = nbjetT30;
        bkgTree->Fill();
        nttccLF += 1;
        inputX << input << endl; 
        inputY << "0" << endl;
        
      }
      // if (Cut(ientry) < 0) continue;
   }
   inputX.close();
   inputY.close();
   mva->Write();
   mva->Close();
}
