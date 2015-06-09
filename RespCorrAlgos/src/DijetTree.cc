#include "DijetCalibration/RespCorrAlgos/interface/DijetTree.h"

using namespace std;

DijetTree::DijetTree(TTree *tree) : fChain(0)
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      // The following code should be used if you want this class to access a chain
      // of trees.
      TChain * chain = new TChain("dijettree","");
      chain->Add("/eos/uscms/store/user/dgsheffi/QCD_Pt_50to80_TuneCUETP8M1_13TeV_pythia8/DijetCalibration_dEta-1p5_sumEt-20_Et-10_3rdEt-100/c2c0917434f62ea410bdbeda02a50761/tree_100_1_Xom.root/dijettree");
      tree = chain;
   }
   Init(tree);
}

DijetTree::~DijetTree()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t DijetTree::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}

Long64_t DijetTree::LoadTree(Long64_t entry)
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

void DijetTree::Init(TTree *tree)
{
   // Set object pointer
   tpfjet_had_E = 0;
   tpfjet_had_px = 0;
   tpfjet_had_py = 0;
   tpfjet_had_pz = 0;
   tpfjet_had_EcalE = 0;
   tpfjet_had_rawHcalE = 0;
   tpfjet_had_emf = 0;
   tpfjet_had_id = 0;
   tpfjet_had_candtrackind = 0;
   tpfjet_had_E_mctruth = 0;
   tpfjet_had_mcpdgId = 0;
   tpfjet_had_ntwrs = 0;
   tpfjet_twr_ieta = 0;
   tpfjet_twr_iphi = 0;
   tpfjet_twr_depth = 0;
   tpfjet_twr_subdet = 0;
   tpfjet_twr_hade = 0;
   tpfjet_twr_frac = 0;
   tpfjet_twr_candtrackind = 0;
   tpfjet_twr_hadind = 0;
   tpfjet_twr_elmttype = 0;
   tpfjet_twr_dR = 0;
   tpfjet_twr_clusterind = 0;
   tpfjet_cluster_eta = 0;
   tpfjet_cluster_phi = 0;
   tpfjet_cluster_dR = 0;
   tpfjet_candtrack_px = 0;
   tpfjet_candtrack_py = 0;
   tpfjet_candtrack_pz = 0;
   tpfjet_candtrack_EcalE = 0;
   ppfjet_had_E = 0;
   ppfjet_had_px = 0;
   ppfjet_had_py = 0;
   ppfjet_had_pz = 0;
   ppfjet_had_EcalE = 0;
   ppfjet_had_rawHcalE = 0;
   ppfjet_had_emf = 0;
   ppfjet_had_id = 0;
   ppfjet_had_candtrackind = 0;
   ppfjet_had_E_mctruth = 0;
   ppfjet_had_mcpdgId = 0;
   ppfjet_had_ntwrs = 0;
   ppfjet_twr_ieta = 0;
   ppfjet_twr_iphi = 0;
   ppfjet_twr_depth = 0;
   ppfjet_twr_subdet = 0;
   ppfjet_twr_hade = 0;
   ppfjet_twr_frac = 0;
   ppfjet_twr_candtrackind = 0;
   ppfjet_twr_hadind = 0;
   ppfjet_twr_elmttype = 0;
   ppfjet_twr_dR = 0;
   ppfjet_twr_clusterind = 0;
   ppfjet_cluster_eta = 0;
   ppfjet_cluster_phi = 0;
   ppfjet_cluster_dR = 0;
   ppfjet_candtrack_px = 0;
   ppfjet_candtrack_py = 0;
   ppfjet_candtrack_pz = 0;
   ppfjet_candtrack_EcalE = 0;
   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("tpfjet_pt", &tpfjet_pt, &b_tpfjet_pt);
   fChain->SetBranchAddress("tpfjet_p", &tpfjet_p, &b_tpfjet_p);
   fChain->SetBranchAddress("tpfjet_E", &tpfjet_E, &b_tpfjet_E);
   fChain->SetBranchAddress("tpfjet_eta", &tpfjet_eta, &b_tpfjet_eta);
   fChain->SetBranchAddress("tpfjet_phi", &tpfjet_phi, &b_tpfjet_phi);
   fChain->SetBranchAddress("tpfjet_EMfrac", &tpfjet_EMfrac, &b_tpfjet_EMfrac);
   fChain->SetBranchAddress("tpfjet_hadEcalEfrac", &tpfjet_hadEcalEfrac, &b_tpfjet_hadEcalEfrac);
   fChain->SetBranchAddress("tpfjet_scale", &tpfjet_scale, &b_tpfjet_scale);
   fChain->SetBranchAddress("tpfjet_area", &tpfjet_area, &b_tpfjet_area);
   fChain->SetBranchAddress("tpfjet_jetID", &tpfjet_jetID, &b_tpfjet_jetID);
   fChain->SetBranchAddress("tpfjet_genpt", &tpfjet_genpt, &b_tpfjet_genpt);
   fChain->SetBranchAddress("tpfjet_genp", &tpfjet_genp, &b_tpfjet_genp);
   fChain->SetBranchAddress("tpfjet_genE", &tpfjet_genE, &b_tpfjet_genE);
   fChain->SetBranchAddress("tpfjet_gendr", &tpfjet_gendr, &b_tpfjet_gendr);
   fChain->SetBranchAddress("tpfjet_unkown_E", &tpfjet_unkown_E, &b_tpfjet_unkown_E);
   fChain->SetBranchAddress("tpfjet_electron_E", &tpfjet_electron_E, &b_tpfjet_electron_E);
   fChain->SetBranchAddress("tpfjet_muon_E", &tpfjet_muon_E, &b_tpfjet_muon_E);
   fChain->SetBranchAddress("tpfjet_photon_E", &tpfjet_photon_E, &b_tpfjet_photon_E);
   fChain->SetBranchAddress("tpfjet_unkown_px", &tpfjet_unkown_px, &b_tpfjet_unkown_px);
   fChain->SetBranchAddress("tpfjet_electron_px", &tpfjet_electron_px, &b_tpfjet_electron_px);
   fChain->SetBranchAddress("tpfjet_muon_px", &tpfjet_muon_px, &b_tpfjet_muon_px);
   fChain->SetBranchAddress("tpfjet_photon_px", &tpfjet_photon_px, &b_tpfjet_photon_px);
   fChain->SetBranchAddress("tpfjet_unkown_py", &tpfjet_unkown_py, &b_tpfjet_unkown_py);
   fChain->SetBranchAddress("tpfjet_electron_py", &tpfjet_electron_py, &b_tpfjet_electron_py);
   fChain->SetBranchAddress("tpfjet_muon_py", &tpfjet_muon_py, &b_tpfjet_muon_py);
   fChain->SetBranchAddress("tpfjet_photon_py", &tpfjet_photon_py, &b_tpfjet_photon_py);
   fChain->SetBranchAddress("tpfjet_unkown_pz", &tpfjet_unkown_pz, &b_tpfjet_unkown_pz);
   fChain->SetBranchAddress("tpfjet_electron_pz", &tpfjet_electron_pz, &b_tpfjet_electron_pz);
   fChain->SetBranchAddress("tpfjet_muon_pz", &tpfjet_muon_pz, &b_tpfjet_muon_pz);
   fChain->SetBranchAddress("tpfjet_photon_pz", &tpfjet_photon_pz, &b_tpfjet_photon_pz);
   fChain->SetBranchAddress("tpfjet_unkown_EcalE", &tpfjet_unkown_EcalE, &b_tpfjet_unkown_EcalE);
   fChain->SetBranchAddress("tpfjet_electron_EcalE", &tpfjet_electron_EcalE, &b_tpfjet_electron_EcalE);
   fChain->SetBranchAddress("tpfjet_muon_EcalE", &tpfjet_muon_EcalE, &b_tpfjet_muon_EcalE);
   fChain->SetBranchAddress("tpfjet_photon_EcalE", &tpfjet_photon_EcalE, &b_tpfjet_photon_EcalE);
   fChain->SetBranchAddress("tpfjet_unkown_n", &tpfjet_unkown_n, &b_tpfjet_unkown_n);
   fChain->SetBranchAddress("tpfjet_electron_n", &tpfjet_electron_n, &b_tpfjet_electron_n);
   fChain->SetBranchAddress("tpfjet_muon_n", &tpfjet_muon_n, &b_tpfjet_muon_n);
   fChain->SetBranchAddress("tpfjet_photon_n", &tpfjet_photon_n, &b_tpfjet_photon_n);
   fChain->SetBranchAddress("tpfjet_had_n", &tpfjet_had_n, &b_tpfjet_had_n);
   fChain->SetBranchAddress("tpfjet_had_E", &tpfjet_had_E, &b_tpfjet_had_E);
   fChain->SetBranchAddress("tpfjet_had_px", &tpfjet_had_px, &b_tpfjet_had_px);
   fChain->SetBranchAddress("tpfjet_had_py", &tpfjet_had_py, &b_tpfjet_had_py);
   fChain->SetBranchAddress("tpfjet_had_pz", &tpfjet_had_pz, &b_tpfjet_had_pz);
   fChain->SetBranchAddress("tpfjet_had_EcalE", &tpfjet_had_EcalE, &b_tpfjet_had_EcalE);
   fChain->SetBranchAddress("tpfjet_had_rawHcalE", &tpfjet_had_rawHcalE, &b_tpfjet_had_rawHcalE);
   fChain->SetBranchAddress("tpfjet_had_emf", &tpfjet_had_emf, &b_tpfjet_had_emf);
   fChain->SetBranchAddress("tpfjet_had_id", &tpfjet_had_id, &b_tpfjet_had_id);
   fChain->SetBranchAddress("tpfjet_had_candtrackind", &tpfjet_had_candtrackind, &b_tpfjet_had_candtrackind);
   fChain->SetBranchAddress("tpfjet_had_E_mctruth", &tpfjet_had_E_mctruth, &b_tpfjet_had_E_mctruth);
   fChain->SetBranchAddress("tpfjet_had_mcpdgId", &tpfjet_had_mcpdgId, &b_tpfjet_had_mcpdgId);
   fChain->SetBranchAddress("tpfjet_had_ntwrs", &tpfjet_had_ntwrs, &b_tpfjet_had_ntwrs);
   fChain->SetBranchAddress("tpfjet_ntwrs", &tpfjet_ntwrs, &b_tpfjet_ntwrs);
   fChain->SetBranchAddress("tpfjet_twr_ieta", &tpfjet_twr_ieta, &b_tpfjet_twr_ieta);
   fChain->SetBranchAddress("tpfjet_twr_iphi", &tpfjet_twr_iphi, &b_tpfjet_twr_iphi);
   fChain->SetBranchAddress("tpfjet_twr_depth", &tpfjet_twr_depth, &b_tpfjet_twr_depth);
   fChain->SetBranchAddress("tpfjet_twr_subdet", &tpfjet_twr_subdet, &b_tpfjet_twr_subdet);
   fChain->SetBranchAddress("tpfjet_twr_hade", &tpfjet_twr_hade, &b_tpfjet_twr_hade);
   fChain->SetBranchAddress("tpfjet_twr_frac", &tpfjet_twr_frac, &b_tpfjet_twr_frac);
   fChain->SetBranchAddress("tpfjet_twr_candtrackind", &tpfjet_twr_candtrackind, &b_tpfjet_twr_candtrackind);
   fChain->SetBranchAddress("tpfjet_twr_hadind", &tpfjet_twr_hadind, &b_tpfjet_twr_hadind);
   fChain->SetBranchAddress("tpfjet_twr_elmttype", &tpfjet_twr_elmttype, &b_tpfjet_twr_elmttype);
   fChain->SetBranchAddress("tpfjet_twr_dR", &tpfjet_twr_dR, &b_tpfjet_twr_dR);
   fChain->SetBranchAddress("tpfjet_twr_clusterind", &tpfjet_twr_clusterind, &b_tpfjet_twr_clusterind);
   fChain->SetBranchAddress("tpfjet_cluster_n", &tpfjet_cluster_n, &b_tpfjet_cluster_n);
   fChain->SetBranchAddress("tpfjet_cluster_eta", &tpfjet_cluster_eta, &b_tpfjet_cluster_eta);
   fChain->SetBranchAddress("tpfjet_cluster_phi", &tpfjet_cluster_phi, &b_tpfjet_cluster_phi);
   fChain->SetBranchAddress("tpfjet_cluster_dR", &tpfjet_cluster_dR, &b_tpfjet_cluster_dR);
   fChain->SetBranchAddress("tpfjet_ncandtracks", &tpfjet_ncandtracks, &b_tpfjet_ncandtracks);
   fChain->SetBranchAddress("tpfjet_candtrack_px", &tpfjet_candtrack_px, &b_tpfjet_candtrack_px);
   fChain->SetBranchAddress("tpfjet_candtrack_py", &tpfjet_candtrack_py, &b_tpfjet_candtrack_py);
   fChain->SetBranchAddress("tpfjet_candtrack_pz", &tpfjet_candtrack_pz, &b_tpfjet_candtrack_pz);
   fChain->SetBranchAddress("tpfjet_candtrack_EcalE", &tpfjet_candtrack_EcalE, &b_tpfjet_candtrack_EcalE);
   fChain->SetBranchAddress("ppfjet_pt", &ppfjet_pt, &b_ppfjet_pt);
   fChain->SetBranchAddress("ppfjet_p", &ppfjet_p, &b_ppfjet_p);
   fChain->SetBranchAddress("ppfjet_E", &ppfjet_E, &b_ppfjet_E);
   fChain->SetBranchAddress("ppfjet_eta", &ppfjet_eta, &b_ppfjet_eta);
   fChain->SetBranchAddress("ppfjet_phi", &ppfjet_phi, &b_ppfjet_phi);
   fChain->SetBranchAddress("ppfjet_EMfrac", &ppfjet_EMfrac, &b_ppfjet_EMfrac);
   fChain->SetBranchAddress("ppfjet_hadEcalEfrac", &ppfjet_hadEcalEfrac, &b_ppfjet_hadEcalEfrac);
   fChain->SetBranchAddress("ppfjet_scale", &ppfjet_scale, &b_ppfjet_scale);
   fChain->SetBranchAddress("ppfjet_area", &ppfjet_area, &b_ppfjet_area);
   fChain->SetBranchAddress("ppfjet_jetID", &ppfjet_jetID, &b_ppfjet_jetID);
   fChain->SetBranchAddress("ppfjet_genpt", &ppfjet_genpt, &b_ppfjet_genpt);
   fChain->SetBranchAddress("ppfjet_genp", &ppfjet_genp, &b_ppfjet_genp);
   fChain->SetBranchAddress("ppfjet_genE", &ppfjet_genE, &b_ppfjet_genE);
   fChain->SetBranchAddress("ppfjet_gendr", &ppfjet_gendr, &b_ppfjet_gendr);
   fChain->SetBranchAddress("ppfjet_unkown_E", &ppfjet_unkown_E, &b_ppfjet_unkown_E);
   fChain->SetBranchAddress("ppfjet_electron_E", &ppfjet_electron_E, &b_ppfjet_electron_E);
   fChain->SetBranchAddress("ppfjet_muon_E", &ppfjet_muon_E, &b_ppfjet_muon_E);
   fChain->SetBranchAddress("ppfjet_photon_E", &ppfjet_photon_E, &b_ppfjet_photon_E);
   fChain->SetBranchAddress("ppfjet_unkown_px", &ppfjet_unkown_px, &b_ppfjet_unkown_px);
   fChain->SetBranchAddress("ppfjet_electron_px", &ppfjet_electron_px, &b_ppfjet_electron_px);
   fChain->SetBranchAddress("ppfjet_muon_px", &ppfjet_muon_px, &b_ppfjet_muon_px);
   fChain->SetBranchAddress("ppfjet_photon_px", &ppfjet_photon_px, &b_ppfjet_photon_px);
   fChain->SetBranchAddress("ppfjet_unkown_py", &ppfjet_unkown_py, &b_ppfjet_unkown_py);
   fChain->SetBranchAddress("ppfjet_electron_py", &ppfjet_electron_py, &b_ppfjet_electron_py);
   fChain->SetBranchAddress("ppfjet_muon_py", &ppfjet_muon_py, &b_ppfjet_muon_py);
   fChain->SetBranchAddress("ppfjet_photon_py", &ppfjet_photon_py, &b_ppfjet_photon_py);
   fChain->SetBranchAddress("ppfjet_unkown_pz", &ppfjet_unkown_pz, &b_ppfjet_unkown_pz);
   fChain->SetBranchAddress("ppfjet_electron_pz", &ppfjet_electron_pz, &b_ppfjet_electron_pz);
   fChain->SetBranchAddress("ppfjet_muon_pz", &ppfjet_muon_pz, &b_ppfjet_muon_pz);
   fChain->SetBranchAddress("ppfjet_photon_pz", &ppfjet_photon_pz, &b_ppfjet_photon_pz);
   fChain->SetBranchAddress("ppfjet_unkown_EcalE", &ppfjet_unkown_EcalE, &b_ppfjet_unkown_EcalE);
   fChain->SetBranchAddress("ppfjet_electron_EcalE", &ppfjet_electron_EcalE, &b_ppfjet_electron_EcalE);
   fChain->SetBranchAddress("ppfjet_muon_EcalE", &ppfjet_muon_EcalE, &b_ppfjet_muon_EcalE);
   fChain->SetBranchAddress("ppfjet_photon_EcalE", &ppfjet_photon_EcalE, &b_ppfjet_photon_EcalE);
   fChain->SetBranchAddress("ppfjet_unkown_n", &ppfjet_unkown_n, &b_ppfjet_unkown_n);
   fChain->SetBranchAddress("ppfjet_electron_n", &ppfjet_electron_n, &b_ppfjet_electron_n);
   fChain->SetBranchAddress("ppfjet_muon_n", &ppfjet_muon_n, &b_ppfjet_muon_n);
   fChain->SetBranchAddress("ppfjet_photon_n", &ppfjet_photon_n, &b_ppfjet_photon_n);
   fChain->SetBranchAddress("ppfjet_had_n", &ppfjet_had_n, &b_ppfjet_had_n);
   fChain->SetBranchAddress("ppfjet_had_E", &ppfjet_had_E, &b_ppfjet_had_E);
   fChain->SetBranchAddress("ppfjet_had_px", &ppfjet_had_px, &b_ppfjet_had_px);
   fChain->SetBranchAddress("ppfjet_had_py", &ppfjet_had_py, &b_ppfjet_had_py);
   fChain->SetBranchAddress("ppfjet_had_pz", &ppfjet_had_pz, &b_ppfjet_had_pz);
   fChain->SetBranchAddress("ppfjet_had_EcalE", &ppfjet_had_EcalE, &b_ppfjet_had_EcalE);
   fChain->SetBranchAddress("ppfjet_had_rawHcalE", &ppfjet_had_rawHcalE, &b_ppfjet_had_rawHcalE);
   fChain->SetBranchAddress("ppfjet_had_emf", &ppfjet_had_emf, &b_ppfjet_had_emf);
   fChain->SetBranchAddress("ppfjet_had_id", &ppfjet_had_id, &b_ppfjet_had_id);
   fChain->SetBranchAddress("ppfjet_had_candtrackind", &ppfjet_had_candtrackind, &b_ppfjet_had_candtrackind);
   fChain->SetBranchAddress("ppfjet_had_E_mctruth", &ppfjet_had_E_mctruth, &b_ppfjet_had_E_mctruth);
   fChain->SetBranchAddress("ppfjet_had_mcpdgId", &ppfjet_had_mcpdgId, &b_ppfjet_had_mcpdgId);
   fChain->SetBranchAddress("ppfjet_had_ntwrs", &ppfjet_had_ntwrs, &b_ppfjet_had_ntwrs);
   fChain->SetBranchAddress("ppfjet_ntwrs", &ppfjet_ntwrs, &b_ppfjet_ntwrs);
   fChain->SetBranchAddress("ppfjet_twr_ieta", &ppfjet_twr_ieta, &b_ppfjet_twr_ieta);
   fChain->SetBranchAddress("ppfjet_twr_iphi", &ppfjet_twr_iphi, &b_ppfjet_twr_iphi);
   fChain->SetBranchAddress("ppfjet_twr_depth", &ppfjet_twr_depth, &b_ppfjet_twr_depth);
   fChain->SetBranchAddress("ppfjet_twr_subdet", &ppfjet_twr_subdet, &b_ppfjet_twr_subdet);
   fChain->SetBranchAddress("ppfjet_twr_hade", &ppfjet_twr_hade, &b_ppfjet_twr_hade);
   fChain->SetBranchAddress("ppfjet_twr_frac", &ppfjet_twr_frac, &b_ppfjet_twr_frac);
   fChain->SetBranchAddress("ppfjet_twr_candtrackind", &ppfjet_twr_candtrackind, &b_ppfjet_twr_candtrackind);
   fChain->SetBranchAddress("ppfjet_twr_hadind", &ppfjet_twr_hadind, &b_ppfjet_twr_hadind);
   fChain->SetBranchAddress("ppfjet_twr_elmttype", &ppfjet_twr_elmttype, &b_ppfjet_twr_elmttype);
   fChain->SetBranchAddress("ppfjet_twr_dR", &ppfjet_twr_dR, &b_ppfjet_twr_dR);
   fChain->SetBranchAddress("ppfjet_twr_clusterind", &ppfjet_twr_clusterind, &b_ppfjet_twr_clusterind);
   fChain->SetBranchAddress("ppfjet_cluster_n", &ppfjet_cluster_n, &b_ppfjet_cluster_n);
   fChain->SetBranchAddress("ppfjet_cluster_eta", &ppfjet_cluster_eta, &b_ppfjet_cluster_eta);
   fChain->SetBranchAddress("ppfjet_cluster_phi", &ppfjet_cluster_phi, &b_ppfjet_cluster_phi);
   fChain->SetBranchAddress("ppfjet_cluster_dR", &ppfjet_cluster_dR, &b_ppfjet_cluster_dR);
   fChain->SetBranchAddress("ppfjet_ncandtracks", &ppfjet_ncandtracks, &b_ppfjet_ncandtracks);
   fChain->SetBranchAddress("ppfjet_candtrack_px", &ppfjet_candtrack_px, &b_ppfjet_candtrack_px);
   fChain->SetBranchAddress("ppfjet_candtrack_py", &ppfjet_candtrack_py, &b_ppfjet_candtrack_py);
   fChain->SetBranchAddress("ppfjet_candtrack_pz", &ppfjet_candtrack_pz, &b_ppfjet_candtrack_pz);
   fChain->SetBranchAddress("ppfjet_candtrack_EcalE", &ppfjet_candtrack_EcalE, &b_ppfjet_candtrack_EcalE);
   fChain->SetBranchAddress("pf_dijet_deta", &pf_dijet_deta, &b_pf_dijet_deta);
   fChain->SetBranchAddress("pf_dijet_dphi", &pf_dijet_dphi, &b_pf_dijet_dphi);
   fChain->SetBranchAddress("pf_dijet_balance", &pf_dijet_balance, &b_pf_dijet_balance);
   fChain->SetBranchAddress("pf_thirdjet_px", &pf_thirdjet_px, &b_pf_thirdjet_px);
   fChain->SetBranchAddress("pf_thirdjet_py", &pf_thirdjet_py, &b_pf_thirdjet_py);
   fChain->SetBranchAddress("pf_thirdjet_px_uncorr", &pf_thirdjet_px_uncorr, &b_pf_thirdjet_px_uncorr);
   fChain->SetBranchAddress("pf_thirdjet_py_uncorr", &pf_thirdjet_py_uncorr, &b_pf_thirdjet_py_uncorr);
   fChain->SetBranchAddress("pf_Run", &pf_Run, &b_pf_Run);
   fChain->SetBranchAddress("pf_Lumi", &pf_Lumi, &b_pf_Lumi);
   fChain->SetBranchAddress("pf_Event", &pf_Event, &b_pf_Event);
   fChain->SetBranchAddress("pf_NPV", &pf_NPV, &b_pf_NPV);
   fChain->SetBranchAddress("pf_weight", &pf_weight, &b_pf_weight);
   Notify();
}

Bool_t DijetTree::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void DijetTree::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}

Int_t DijetTree::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  0 if entry is accepted.
// returns >0 otherwise.
   return 0;
}

void DijetTree::Loop()
{
//   In a ROOT session, you can do:
//      root> .L DijetTree.C
//      root> DijetTree t
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
   if (fChain == 0) return;

   Long64_t nentries = fChain->GetEntriesFast();

   Long64_t nbytes = 0, nb = 0;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;
      // if (Cut(ientry) < 0) continue;
   }
}
