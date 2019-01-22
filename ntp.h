//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Tue Jul 17 01:05:49 2018 by ROOT version 6.10/09
// from TTree nom/nom
// found on file: TT_powheg_tot.root
//////////////////////////////////////////////////////////

#ifndef ntp_h
#define ntp_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.
#include "vector"
#include "vector"

class ntp {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

// Fixed size dimensions of array or collections stored in the TTree if any.

   // Declaration of leaf types
   Int_t           nvertex;
   Int_t           step;
   Int_t           channel;
   Int_t           njet30;
   Int_t           nbjetL30;
   Int_t           nbjetM30;
   Int_t           nbjetT30;
   Bool_t          step1;
   Bool_t          step2;
   Bool_t          step3;
   Bool_t          step4;
   Bool_t          step5;
   Bool_t          step6;
   Float_t         tri;
   Float_t         tri_up;
   Float_t         tri_dn;
   Bool_t          filtered;
   Float_t         met;
   Float_t         metphi;
   Float_t         weight;
   vector<float>   *pdfWeights;
   vector<float>   *scaleWeightsUp;
   vector<float>   *scaleWeightsDown;
   vector<float>   *csvweights;
   vector<float>   *csvweights2;
   vector<float>   *btagweightsCSVL;
   vector<float>   *btagweightsCSVM;
   vector<float>   *btagweightsCSVT;
   Float_t         topPtWeight;
   Float_t         puweight;
   Float_t         puweightUp;
   Float_t         puweightDown;
   Float_t         mueffweight;
   Float_t         mueffweight_up;
   Float_t         mueffweight_dn;
   Float_t         eleffweight;
   Float_t         eleffweight_up;
   Float_t         eleffweight_dn;
   Int_t           genTtbarId;
   Float_t         lep1_pt;
   Float_t         lep1_eta;
   Float_t         lep1_phi;
   Float_t         lep1_RelIso;
   Int_t           lep1_q;
   Float_t         lep2_pt;
   Float_t         lep2_eta;
   Float_t         lep2_phi;
   Float_t         lep2_RelIso;
   Int_t           lep2_q;
   Float_t         ll_pt;
   Float_t         ll_eta;
   Float_t         ll_phi;
   Float_t         ll_m;
   vector<float>   *jets_pt;
   vector<float>   *jets_eta;
   vector<float>   *jets_phi;
   vector<float>   *jets_m;
   vector<int>     *jets_flavor;
   vector<float>   *jets_bDiscriminatorCSV;
   vector<int>     *csvd_jetid;
   Float_t         bbM;
   Float_t         bbDR;
   Float_t         lepton1_pt;
   Float_t         lepton1_eta;
   Float_t         lepton1_phi;
   Float_t         lepton2_pt;
   Float_t         lepton2_eta;
   Float_t         lepton2_phi;
   Bool_t          allHadronic;
   Bool_t          semiLeptonicM1;
   Bool_t          semiLeptonic0;
   Bool_t          semiLeptonicP1;
   Bool_t          diLeptonicM1;
   Bool_t          diLeptonic0;
   Bool_t          diLeptonicP1;
   Bool_t          diLeptonicMuoMuo;
   Bool_t          diLeptonicMuoEle;
   Bool_t          diLeptonicEleEle;
   Bool_t          diLeptonicTauMuo;
   Bool_t          diLeptonicTauEle;
   Bool_t          diLeptonicTauTau;
   Int_t           NJets20;
   Int_t           NbJets20;
   Int_t           NcJets20;
   Int_t           NaddJets20;
   Int_t           NaddbJets20;
   Int_t           NaddcJets20;
   Int_t           NJets30;
   Int_t           NbJets30;
   Int_t           NcJets30;
   Int_t           NaddJets30;
   Int_t           NaddbJets30;
   Int_t           NaddcJets30;

   // List of branches
   TBranch        *b_nvertex;   //!
   TBranch        *b_step;   //!
   TBranch        *b_channel;   //!
   TBranch        *b_njet30;   //!
   TBranch        *b_nbjetL30;   //!
   TBranch        *b_nbjetM30;   //!
   TBranch        *b_nbjetT30;   //!
   TBranch        *b_step1;   //!
   TBranch        *b_step2;   //!
   TBranch        *b_step3;   //!
   TBranch        *b_step4;   //!
   TBranch        *b_step5;   //!
   TBranch        *b_step6;   //!
   TBranch        *b_tri;   //!
   TBranch        *b_tri_up;   //!
   TBranch        *b_tri_dn;   //!
   TBranch        *b_filtered;   //!
   TBranch        *b_met;   //!
   TBranch        *b_metphi;   //!
   TBranch        *b_weight;   //!
   TBranch        *b_pdfWeights;   //!
   TBranch        *b_scaleWeightsUp;   //!
   TBranch        *b_scaleWeightsDown;   //!
   TBranch        *b_csvweights;   //!
   TBranch        *b_csvweights2;   //!
   TBranch        *b_btagweightsCSVL;   //!
   TBranch        *b_btagweightsCSVM;   //!
   TBranch        *b_btagweightsCSVT;   //!
   TBranch        *b_topPtWeight;   //!
   TBranch        *b_puweight;   //!
   TBranch        *b_puweightUp;   //!
   TBranch        *b_puweightDown;   //!
   TBranch        *b_mueffweight;   //!
   TBranch        *b_mueffweight_up;   //!
   TBranch        *b_mueffweight_dn;   //!
   TBranch        *b_eleffweight;   //!
   TBranch        *b_eleffweight_up;   //!
   TBranch        *b_eleffweight_dn;   //!
   TBranch        *b_genTtbarId;   //!
   TBranch        *b_lep1_pt;   //!
   TBranch        *b_lep1_eta;   //!
   TBranch        *b_lep1_phi;   //!
   TBranch        *b_lep1_RelIso;   //!
   TBranch        *b_lep1_q;   //!
   TBranch        *b_lep2_pt;   //!
   TBranch        *b_lep2_eta;   //!
   TBranch        *b_lep2_phi;   //!
   TBranch        *b_lep2_RelIso;   //!
   TBranch        *b_lep2_q;   //!
   TBranch        *b_ll_pt;   //!
   TBranch        *b_ll_eta;   //!
   TBranch        *b_ll_phi;   //!
   TBranch        *b_ll_m;   //!
   TBranch        *b_jets_pt;   //!
   TBranch        *b_jets_eta;   //!
   TBranch        *b_jets_phi;   //!
   TBranch        *b_jets_m;   //!
   TBranch        *b_jets_flavor;   //!
   TBranch        *b_jets_bDiscriminatorCSV;   //!
   TBranch        *b_csvd_jetid;   //!
   TBranch        *b_bbM;   //!
   TBranch        *b_bbDR;   //!
   TBranch        *b_lepton1_pt;   //!
   TBranch        *b_lepton1_eta;   //!
   TBranch        *b_lepton1_phi;   //!
   TBranch        *b_lepton2_pt;   //!
   TBranch        *b_lepton2_eta;   //!
   TBranch        *b_lepton2_phi;   //!
   TBranch        *b_allHadronic;   //!
   TBranch        *b_semiLeptonicM1;   //!
   TBranch        *b_semiLeptonic0;   //!
   TBranch        *b_semiLeptonicP1;   //!
   TBranch        *b_diLeptonicM1;   //!
   TBranch        *b_diLeptonic0;   //!
   TBranch        *b_diLeptonicP1;   //!
   TBranch        *b_diLeptonicMuoMuo;   //!
   TBranch        *b_diLeptonicMuoEle;   //!
   TBranch        *b_diLeptonicEleEle;   //!
   TBranch        *b_diLeptonicTauMuo;   //!
   TBranch        *b_diLeptonicTauEle;   //!
   TBranch        *b_diLeptonicTauTau;   //!
   TBranch        *b_NJets20;   //!
   TBranch        *b_NbJets20;   //!
   TBranch        *b_NcJets20;   //!
   TBranch        *b_NaddJets20;   //!
   TBranch        *b_NaddbJets20;   //!
   TBranch        *b_NaddcJets20;   //!
   TBranch        *b_NJets30;   //!
   TBranch        *b_NbJets30;   //!
   TBranch        *b_NcJets30;   //!
   TBranch        *b_NaddJets30;   //!
   TBranch        *b_NaddbJets30;   //!
   TBranch        *b_NaddcJets30;   //!

   ntp(TTree *tree=0);
   virtual ~ntp();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef ntp_cxx
ntp::ntp(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("TT_powheg_tot.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("TT_powheg_tot.root");
      }
      TDirectory * dir = (TDirectory*)f->Get("TT_powheg_tot.root:/cattree");
      dir->GetObject("nom",tree);

   }
   Init(tree);
}

ntp::~ntp()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t ntp::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t ntp::LoadTree(Long64_t entry)
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

void ntp::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set object pointer
   pdfWeights = 0;
   scaleWeightsUp = 0;
   scaleWeightsDown = 0;
   csvweights = 0;
   csvweights2 = 0;
   btagweightsCSVL = 0;
   btagweightsCSVM = 0;
   btagweightsCSVT = 0;
   jets_pt = 0;
   jets_eta = 0;
   jets_phi = 0;
   jets_m = 0;
   jets_flavor = 0;
   jets_bDiscriminatorCSV = 0;
   csvd_jetid = 0;
   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("nvertex", &nvertex, &b_nvertex);
   fChain->SetBranchAddress("step", &step, &b_step);
   fChain->SetBranchAddress("channel", &channel, &b_channel);
   fChain->SetBranchAddress("njet30", &njet30, &b_njet30);
   fChain->SetBranchAddress("nbjetL30", &nbjetL30, &b_nbjetL30);
   fChain->SetBranchAddress("nbjetM30", &nbjetM30, &b_nbjetM30);
   fChain->SetBranchAddress("nbjetT30", &nbjetT30, &b_nbjetT30);
   fChain->SetBranchAddress("step1", &step1, &b_step1);
   fChain->SetBranchAddress("step2", &step2, &b_step2);
   fChain->SetBranchAddress("step3", &step3, &b_step3);
   fChain->SetBranchAddress("step4", &step4, &b_step4);
   fChain->SetBranchAddress("step5", &step5, &b_step5);
   fChain->SetBranchAddress("step6", &step6, &b_step6);
   fChain->SetBranchAddress("tri", &tri, &b_tri);
   fChain->SetBranchAddress("tri_up", &tri_up, &b_tri_up);
   fChain->SetBranchAddress("tri_dn", &tri_dn, &b_tri_dn);
   fChain->SetBranchAddress("filtered", &filtered, &b_filtered);
   fChain->SetBranchAddress("met", &met, &b_met);
   fChain->SetBranchAddress("metphi", &metphi, &b_metphi);
   fChain->SetBranchAddress("weight", &weight, &b_weight);
   fChain->SetBranchAddress("pdfWeights", &pdfWeights, &b_pdfWeights);
   fChain->SetBranchAddress("scaleWeightsUp", &scaleWeightsUp, &b_scaleWeightsUp);
   fChain->SetBranchAddress("scaleWeightsDown", &scaleWeightsDown, &b_scaleWeightsDown);
   fChain->SetBranchAddress("csvweights", &csvweights, &b_csvweights);
   fChain->SetBranchAddress("csvweights2", &csvweights2, &b_csvweights2);
   fChain->SetBranchAddress("btagweightsCSVL", &btagweightsCSVL, &b_btagweightsCSVL);
   fChain->SetBranchAddress("btagweightsCSVM", &btagweightsCSVM, &b_btagweightsCSVM);
   fChain->SetBranchAddress("btagweightsCSVT", &btagweightsCSVT, &b_btagweightsCSVT);
   fChain->SetBranchAddress("topPtWeight", &topPtWeight, &b_topPtWeight);
   fChain->SetBranchAddress("puweight", &puweight, &b_puweight);
   fChain->SetBranchAddress("puweightUp", &puweightUp, &b_puweightUp);
   fChain->SetBranchAddress("puweightDown", &puweightDown, &b_puweightDown);
   fChain->SetBranchAddress("mueffweight", &mueffweight, &b_mueffweight);
   fChain->SetBranchAddress("mueffweight_up", &mueffweight_up, &b_mueffweight_up);
   fChain->SetBranchAddress("mueffweight_dn", &mueffweight_dn, &b_mueffweight_dn);
   fChain->SetBranchAddress("eleffweight", &eleffweight, &b_eleffweight);
   fChain->SetBranchAddress("eleffweight_up", &eleffweight_up, &b_eleffweight_up);
   fChain->SetBranchAddress("eleffweight_dn", &eleffweight_dn, &b_eleffweight_dn);
   fChain->SetBranchAddress("genTtbarId", &genTtbarId, &b_genTtbarId);
   fChain->SetBranchAddress("lep1_pt", &lep1_pt, &b_lep1_pt);
   fChain->SetBranchAddress("lep1_eta", &lep1_eta, &b_lep1_eta);
   fChain->SetBranchAddress("lep1_phi", &lep1_phi, &b_lep1_phi);
   fChain->SetBranchAddress("lep1_RelIso", &lep1_RelIso, &b_lep1_RelIso);
   fChain->SetBranchAddress("lep1_q", &lep1_q, &b_lep1_q);
   fChain->SetBranchAddress("lep2_pt", &lep2_pt, &b_lep2_pt);
   fChain->SetBranchAddress("lep2_eta", &lep2_eta, &b_lep2_eta);
   fChain->SetBranchAddress("lep2_phi", &lep2_phi, &b_lep2_phi);
   fChain->SetBranchAddress("lep2_RelIso", &lep2_RelIso, &b_lep2_RelIso);
   fChain->SetBranchAddress("lep2_q", &lep2_q, &b_lep2_q);
   fChain->SetBranchAddress("ll_pt", &ll_pt, &b_ll_pt);
   fChain->SetBranchAddress("ll_eta", &ll_eta, &b_ll_eta);
   fChain->SetBranchAddress("ll_phi", &ll_phi, &b_ll_phi);
   fChain->SetBranchAddress("ll_m", &ll_m, &b_ll_m);
   fChain->SetBranchAddress("jets_pt", &jets_pt, &b_jets_pt);
   fChain->SetBranchAddress("jets_eta", &jets_eta, &b_jets_eta);
   fChain->SetBranchAddress("jets_phi", &jets_phi, &b_jets_phi);
   fChain->SetBranchAddress("jets_m", &jets_m, &b_jets_m);
   fChain->SetBranchAddress("jets_flavor", &jets_flavor, &b_jets_flavor);
   fChain->SetBranchAddress("jets_bDiscriminatorCSV", &jets_bDiscriminatorCSV, &b_jets_bDiscriminatorCSV);
   fChain->SetBranchAddress("csvd_jetid", &csvd_jetid, &b_csvd_jetid);
   fChain->SetBranchAddress("bbM", &bbM, &b_bbM);
   fChain->SetBranchAddress("bbDR", &bbDR, &b_bbDR);
   fChain->SetBranchAddress("lepton1_pt", &lepton1_pt, &b_lepton1_pt);
   fChain->SetBranchAddress("lepton1_eta", &lepton1_eta, &b_lepton1_eta);
   fChain->SetBranchAddress("lepton1_phi", &lepton1_phi, &b_lepton1_phi);
   fChain->SetBranchAddress("lepton2_pt", &lepton2_pt, &b_lepton2_pt);
   fChain->SetBranchAddress("lepton2_eta", &lepton2_eta, &b_lepton2_eta);
   fChain->SetBranchAddress("lepton2_phi", &lepton2_phi, &b_lepton2_phi);
   fChain->SetBranchAddress("allHadronic", &allHadronic, &b_allHadronic);
   fChain->SetBranchAddress("semiLeptonicM1", &semiLeptonicM1, &b_semiLeptonicM1);
   fChain->SetBranchAddress("semiLeptonic0", &semiLeptonic0, &b_semiLeptonic0);
   fChain->SetBranchAddress("semiLeptonicP1", &semiLeptonicP1, &b_semiLeptonicP1);
   fChain->SetBranchAddress("diLeptonicM1", &diLeptonicM1, &b_diLeptonicM1);
   fChain->SetBranchAddress("diLeptonic0", &diLeptonic0, &b_diLeptonic0);
   fChain->SetBranchAddress("diLeptonicP1", &diLeptonicP1, &b_diLeptonicP1);
   fChain->SetBranchAddress("diLeptonicMuoMuo", &diLeptonicMuoMuo, &b_diLeptonicMuoMuo);
   fChain->SetBranchAddress("diLeptonicMuoEle", &diLeptonicMuoEle, &b_diLeptonicMuoEle);
   fChain->SetBranchAddress("diLeptonicEleEle", &diLeptonicEleEle, &b_diLeptonicEleEle);
   fChain->SetBranchAddress("diLeptonicTauMuo", &diLeptonicTauMuo, &b_diLeptonicTauMuo);
   fChain->SetBranchAddress("diLeptonicTauEle", &diLeptonicTauEle, &b_diLeptonicTauEle);
   fChain->SetBranchAddress("diLeptonicTauTau", &diLeptonicTauTau, &b_diLeptonicTauTau);
   fChain->SetBranchAddress("NJets20", &NJets20, &b_NJets20);
   fChain->SetBranchAddress("NbJets20", &NbJets20, &b_NbJets20);
   fChain->SetBranchAddress("NcJets20", &NcJets20, &b_NcJets20);
   fChain->SetBranchAddress("NaddJets20", &NaddJets20, &b_NaddJets20);
   fChain->SetBranchAddress("NaddbJets20", &NaddbJets20, &b_NaddbJets20);
   fChain->SetBranchAddress("NaddcJets20", &NaddcJets20, &b_NaddcJets20);
   fChain->SetBranchAddress("NJets30", &NJets30, &b_NJets30);
   fChain->SetBranchAddress("NbJets30", &NbJets30, &b_NbJets30);
   fChain->SetBranchAddress("NcJets30", &NcJets30, &b_NcJets30);
   fChain->SetBranchAddress("NaddJets30", &NaddJets30, &b_NaddJets30);
   fChain->SetBranchAddress("NaddbJets30", &NaddbJets30, &b_NaddbJets30);
   fChain->SetBranchAddress("NaddcJets30", &NaddcJets30, &b_NaddcJets30);
   Notify();
}

Bool_t ntp::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void ntp::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t ntp::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef ntp_cxx
