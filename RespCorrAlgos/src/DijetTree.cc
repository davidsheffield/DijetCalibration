#include "DijetCalibration/RespCorrAlgos/interface/DijetTree.h"

using namespace std;

DijetTree::DijetTree(TTree *tree, bool MC) : fChain(0)
{
    isMC = MC;
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
    tjet_had_E = 0;
    tjet_had_px = 0;
    tjet_had_py = 0;
    tjet_had_pz = 0;
    tjet_had_EcalE = 0;
    tjet_had_rawHcalE = 0;
    tjet_had_emf = 0;
    tjet_had_id = 0;
    tjet_had_candtrackind = 0;
    tjet_had_E_mctruth = 0;
    tjet_had_mcpdgId = 0;
    tjet_had_ntwrs = 0;
    tjet_twr_ieta = 0;
    tjet_twr_iphi = 0;
    tjet_twr_depth = 0;
    tjet_twr_subdet = 0;
    tjet_twr_hade = 0;
    tjet_twr_frac = 0;
    tjet_twr_candtrackind = 0;
    tjet_twr_hadind = 0;
    tjet_twr_elmttype = 0;
    tjet_twr_dR = 0;
    tjet_twr_clusterind = 0;
    tjet_cluster_eta = 0;
    tjet_cluster_phi = 0;
    tjet_cluster_dR = 0;
    tjet_candtrack_px = 0;
    tjet_candtrack_py = 0;
    tjet_candtrack_pz = 0;
    tjet_candtrack_EcalE = 0;
    pjet_had_E = 0;
    pjet_had_px = 0;
    pjet_had_py = 0;
    pjet_had_pz = 0;
    pjet_had_EcalE = 0;
    pjet_had_rawHcalE = 0;
    pjet_had_emf = 0;
    pjet_had_id = 0;
    pjet_had_candtrackind = 0;
    pjet_had_E_mctruth = 0;
    pjet_had_mcpdgId = 0;
    pjet_had_ntwrs = 0;
    pjet_twr_ieta = 0;
    pjet_twr_iphi = 0;
    pjet_twr_depth = 0;
    pjet_twr_subdet = 0;
    pjet_twr_hade = 0;
    pjet_twr_frac = 0;
    pjet_twr_candtrackind = 0;
    pjet_twr_hadind = 0;
    pjet_twr_elmttype = 0;
    pjet_twr_dR = 0;
    pjet_twr_clusterind = 0;
    pjet_cluster_eta = 0;
    pjet_cluster_phi = 0;
    pjet_cluster_dR = 0;
    pjet_candtrack_px = 0;
    pjet_candtrack_py = 0;
    pjet_candtrack_pz = 0;
    pjet_candtrack_EcalE = 0;
    // Set branch addresses and branch pointers
    if (!tree) return;
    fChain = tree;
    fCurrent = -1;
    fChain->SetMakeClass(1);

    fChain->SetBranchAddress("tjet_pt", &tjet_pt, &b_tjet_pt);
    fChain->SetBranchAddress("tjet_p", &tjet_p, &b_tjet_p);
    fChain->SetBranchAddress("tjet_E", &tjet_E, &b_tjet_E);
    fChain->SetBranchAddress("tjet_eta", &tjet_eta, &b_tjet_eta);
    fChain->SetBranchAddress("tjet_phi", &tjet_phi, &b_tjet_phi);
    fChain->SetBranchAddress("tjet_EMfrac", &tjet_EMfrac, &b_tjet_EMfrac);
    fChain->SetBranchAddress("tjet_hadEcalEfrac", &tjet_hadEcalEfrac,
			     &b_tjet_hadEcalEfrac);
    fChain->SetBranchAddress("tjet_scale", &tjet_scale, &b_tjet_scale);
    fChain->SetBranchAddress("tjet_area", &tjet_area, &b_tjet_area);
    fChain->SetBranchAddress("tjet_jetID", &tjet_jetID, &b_tjet_jetID);
    if (isMC) {
	fChain->SetBranchAddress("tjet_genpt", &tjet_genpt, &b_tjet_genpt);
	fChain->SetBranchAddress("tjet_genp", &tjet_genp, &b_tjet_genp);
	fChain->SetBranchAddress("tjet_genE", &tjet_genE, &b_tjet_genE);
	fChain->SetBranchAddress("tjet_gendr", &tjet_gendr, &b_tjet_gendr);
    }
    fChain->SetBranchAddress("tjet_unkown_E", &tjet_unkown_E, &b_tjet_unkown_E);
    fChain->SetBranchAddress("tjet_electron_E", &tjet_electron_E,
			     &b_tjet_electron_E);
    fChain->SetBranchAddress("tjet_muon_E", &tjet_muon_E, &b_tjet_muon_E);
    fChain->SetBranchAddress("tjet_photon_E", &tjet_photon_E, &b_tjet_photon_E);
    fChain->SetBranchAddress("tjet_unkown_px", &tjet_unkown_px,
			     &b_tjet_unkown_px);
    fChain->SetBranchAddress("tjet_electron_px", &tjet_electron_px,
			     &b_tjet_electron_px);
    fChain->SetBranchAddress("tjet_muon_px", &tjet_muon_px, &b_tjet_muon_px);
    fChain->SetBranchAddress("tjet_photon_px", &tjet_photon_px,
			     &b_tjet_photon_px);
    fChain->SetBranchAddress("tjet_unkown_py", &tjet_unkown_py,
			     &b_tjet_unkown_py);
    fChain->SetBranchAddress("tjet_electron_py", &tjet_electron_py,
			     &b_tjet_electron_py);
    fChain->SetBranchAddress("tjet_muon_py", &tjet_muon_py, &b_tjet_muon_py);
    fChain->SetBranchAddress("tjet_photon_py", &tjet_photon_py,
			     &b_tjet_photon_py);
    fChain->SetBranchAddress("tjet_unkown_pz", &tjet_unkown_pz,
			     &b_tjet_unkown_pz);
    fChain->SetBranchAddress("tjet_electron_pz", &tjet_electron_pz,
			     &b_tjet_electron_pz);
    fChain->SetBranchAddress("tjet_muon_pz", &tjet_muon_pz, &b_tjet_muon_pz);
    fChain->SetBranchAddress("tjet_photon_pz", &tjet_photon_pz,
			     &b_tjet_photon_pz);
    fChain->SetBranchAddress("tjet_unkown_EcalE", &tjet_unkown_EcalE,
			     &b_tjet_unkown_EcalE);
    fChain->SetBranchAddress("tjet_electron_EcalE", &tjet_electron_EcalE,
			     &b_tjet_electron_EcalE);
    fChain->SetBranchAddress("tjet_muon_EcalE", &tjet_muon_EcalE,
			     &b_tjet_muon_EcalE);
    fChain->SetBranchAddress("tjet_photon_EcalE", &tjet_photon_EcalE,
			     &b_tjet_photon_EcalE);
    fChain->SetBranchAddress("tjet_unkown_n", &tjet_unkown_n, &b_tjet_unkown_n);
    fChain->SetBranchAddress("tjet_electron_n", &tjet_electron_n,
			     &b_tjet_electron_n);
    fChain->SetBranchAddress("tjet_muon_n", &tjet_muon_n, &b_tjet_muon_n);
    fChain->SetBranchAddress("tjet_photon_n", &tjet_photon_n, &b_tjet_photon_n);
    fChain->SetBranchAddress("tjet_had_n", &tjet_had_n, &b_tjet_had_n);
    fChain->SetBranchAddress("tjet_had_E", &tjet_had_E, &b_tjet_had_E);
    fChain->SetBranchAddress("tjet_had_px", &tjet_had_px, &b_tjet_had_px);
    fChain->SetBranchAddress("tjet_had_py", &tjet_had_py, &b_tjet_had_py);
    fChain->SetBranchAddress("tjet_had_pz", &tjet_had_pz, &b_tjet_had_pz);
    fChain->SetBranchAddress("tjet_had_EcalE", &tjet_had_EcalE,
			     &b_tjet_had_EcalE);
    fChain->SetBranchAddress("tjet_had_rawHcalE", &tjet_had_rawHcalE,
			     &b_tjet_had_rawHcalE);
    fChain->SetBranchAddress("tjet_had_emf", &tjet_had_emf, &b_tjet_had_emf);
    fChain->SetBranchAddress("tjet_had_id", &tjet_had_id, &b_tjet_had_id);
    fChain->SetBranchAddress("tjet_had_candtrackind", &tjet_had_candtrackind,
			     &b_tjet_had_candtrackind);
    if (isMC) {
	fChain->SetBranchAddress("tjet_had_E_mctruth", &tjet_had_E_mctruth,
				 &b_tjet_had_E_mctruth);
	fChain->SetBranchAddress("tjet_had_mcpdgId", &tjet_had_mcpdgId,
				 &b_tjet_had_mcpdgId);
    }
    fChain->SetBranchAddress("tjet_had_ntwrs", &tjet_had_ntwrs,
			     &b_tjet_had_ntwrs);
    fChain->SetBranchAddress("tjet_ntwrs", &tjet_ntwrs, &b_tjet_ntwrs);
    fChain->SetBranchAddress("tjet_twr_ieta", &tjet_twr_ieta, &b_tjet_twr_ieta);
    fChain->SetBranchAddress("tjet_twr_iphi", &tjet_twr_iphi, &b_tjet_twr_iphi);
    fChain->SetBranchAddress("tjet_twr_depth", &tjet_twr_depth,
			     &b_tjet_twr_depth);
    fChain->SetBranchAddress("tjet_twr_subdet", &tjet_twr_subdet,
			     &b_tjet_twr_subdet);
    fChain->SetBranchAddress("tjet_twr_hade", &tjet_twr_hade, &b_tjet_twr_hade);
    fChain->SetBranchAddress("tjet_twr_frac", &tjet_twr_frac, &b_tjet_twr_frac);
    fChain->SetBranchAddress("tjet_twr_candtrackind", &tjet_twr_candtrackind,
			     &b_tjet_twr_candtrackind);
    fChain->SetBranchAddress("tjet_twr_hadind", &tjet_twr_hadind,
			     &b_tjet_twr_hadind);
    fChain->SetBranchAddress("tjet_twr_elmttype", &tjet_twr_elmttype,
			     &b_tjet_twr_elmttype);
    fChain->SetBranchAddress("tjet_twr_dR", &tjet_twr_dR, &b_tjet_twr_dR);
    fChain->SetBranchAddress("tjet_twr_clusterind", &tjet_twr_clusterind,
			     &b_tjet_twr_clusterind);
    fChain->SetBranchAddress("tjet_cluster_n", &tjet_cluster_n,
			     &b_tjet_cluster_n);
    fChain->SetBranchAddress("tjet_cluster_eta", &tjet_cluster_eta,
			     &b_tjet_cluster_eta);
    fChain->SetBranchAddress("tjet_cluster_phi", &tjet_cluster_phi,
			     &b_tjet_cluster_phi);
    fChain->SetBranchAddress("tjet_cluster_dR", &tjet_cluster_dR,
			     &b_tjet_cluster_dR);
    fChain->SetBranchAddress("tjet_ncandtracks", &tjet_ncandtracks,
			     &b_tjet_ncandtracks);
    fChain->SetBranchAddress("tjet_candtrack_px", &tjet_candtrack_px,
			     &b_tjet_candtrack_px);
    fChain->SetBranchAddress("tjet_candtrack_py", &tjet_candtrack_py,
			     &b_tjet_candtrack_py);
    fChain->SetBranchAddress("tjet_candtrack_pz", &tjet_candtrack_pz,
			     &b_tjet_candtrack_pz);
    fChain->SetBranchAddress("tjet_candtrack_EcalE", &tjet_candtrack_EcalE,
			     &b_tjet_candtrack_EcalE);
    fChain->SetBranchAddress("pjet_pt", &pjet_pt, &b_pjet_pt);
    fChain->SetBranchAddress("pjet_p", &pjet_p, &b_pjet_p);
    fChain->SetBranchAddress("pjet_E", &pjet_E, &b_pjet_E);
    fChain->SetBranchAddress("pjet_eta", &pjet_eta, &b_pjet_eta);
    fChain->SetBranchAddress("pjet_phi", &pjet_phi, &b_pjet_phi);
    fChain->SetBranchAddress("pjet_EMfrac", &pjet_EMfrac, &b_pjet_EMfrac);
    fChain->SetBranchAddress("pjet_hadEcalEfrac", &pjet_hadEcalEfrac,
			     &b_pjet_hadEcalEfrac);
    fChain->SetBranchAddress("pjet_scale", &pjet_scale, &b_pjet_scale);
    fChain->SetBranchAddress("pjet_area", &pjet_area, &b_pjet_area);
    fChain->SetBranchAddress("pjet_jetID", &pjet_jetID, &b_pjet_jetID);
    if (isMC) {
	fChain->SetBranchAddress("pjet_genpt", &pjet_genpt, &b_pjet_genpt);
	fChain->SetBranchAddress("pjet_genp", &pjet_genp, &b_pjet_genp);
	fChain->SetBranchAddress("pjet_genE", &pjet_genE, &b_pjet_genE);
	fChain->SetBranchAddress("pjet_gendr", &pjet_gendr, &b_pjet_gendr);
    }
    fChain->SetBranchAddress("pjet_unkown_E", &pjet_unkown_E, &b_pjet_unkown_E);
    fChain->SetBranchAddress("pjet_electron_E", &pjet_electron_E,
			     &b_pjet_electron_E);
    fChain->SetBranchAddress("pjet_muon_E", &pjet_muon_E, &b_pjet_muon_E);
    fChain->SetBranchAddress("pjet_photon_E", &pjet_photon_E, &b_pjet_photon_E);
    fChain->SetBranchAddress("pjet_unkown_px", &pjet_unkown_px,
			     &b_pjet_unkown_px);
    fChain->SetBranchAddress("pjet_electron_px", &pjet_electron_px,
			     &b_pjet_electron_px);
    fChain->SetBranchAddress("pjet_muon_px", &pjet_muon_px, &b_pjet_muon_px);
    fChain->SetBranchAddress("pjet_photon_px", &pjet_photon_px,
			     &b_pjet_photon_px);
    fChain->SetBranchAddress("pjet_unkown_py", &pjet_unkown_py,
			     &b_pjet_unkown_py);
    fChain->SetBranchAddress("pjet_electron_py", &pjet_electron_py,
			     &b_pjet_electron_py);
    fChain->SetBranchAddress("pjet_muon_py", &pjet_muon_py, &b_pjet_muon_py);
    fChain->SetBranchAddress("pjet_photon_py", &pjet_photon_py,
			     &b_pjet_photon_py);
    fChain->SetBranchAddress("pjet_unkown_pz", &pjet_unkown_pz,
			     &b_pjet_unkown_pz);
    fChain->SetBranchAddress("pjet_electron_pz", &pjet_electron_pz,
			     &b_pjet_electron_pz);
    fChain->SetBranchAddress("pjet_muon_pz", &pjet_muon_pz, &b_pjet_muon_pz);
    fChain->SetBranchAddress("pjet_photon_pz", &pjet_photon_pz,
			     &b_pjet_photon_pz);
    fChain->SetBranchAddress("pjet_unkown_EcalE", &pjet_unkown_EcalE,
			     &b_pjet_unkown_EcalE);
    fChain->SetBranchAddress("pjet_electron_EcalE", &pjet_electron_EcalE,
			     &b_pjet_electron_EcalE);
    fChain->SetBranchAddress("pjet_muon_EcalE", &pjet_muon_EcalE,
			     &b_pjet_muon_EcalE);
    fChain->SetBranchAddress("pjet_photon_EcalE", &pjet_photon_EcalE,
			     &b_pjet_photon_EcalE);
    fChain->SetBranchAddress("pjet_unkown_n", &pjet_unkown_n, &b_pjet_unkown_n);
    fChain->SetBranchAddress("pjet_electron_n", &pjet_electron_n,
			     &b_pjet_electron_n);
    fChain->SetBranchAddress("pjet_muon_n", &pjet_muon_n, &b_pjet_muon_n);
    fChain->SetBranchAddress("pjet_photon_n", &pjet_photon_n, &b_pjet_photon_n);
    fChain->SetBranchAddress("pjet_had_n", &pjet_had_n, &b_pjet_had_n);
    fChain->SetBranchAddress("pjet_had_E", &pjet_had_E, &b_pjet_had_E);
    fChain->SetBranchAddress("pjet_had_px", &pjet_had_px, &b_pjet_had_px);
    fChain->SetBranchAddress("pjet_had_py", &pjet_had_py, &b_pjet_had_py);
    fChain->SetBranchAddress("pjet_had_pz", &pjet_had_pz, &b_pjet_had_pz);
    fChain->SetBranchAddress("pjet_had_EcalE", &pjet_had_EcalE,
			     &b_pjet_had_EcalE);
    fChain->SetBranchAddress("pjet_had_rawHcalE", &pjet_had_rawHcalE,
			     &b_pjet_had_rawHcalE);
    fChain->SetBranchAddress("pjet_had_emf", &pjet_had_emf, &b_pjet_had_emf);
    fChain->SetBranchAddress("pjet_had_id", &pjet_had_id, &b_pjet_had_id);
    fChain->SetBranchAddress("pjet_had_candtrackind", &pjet_had_candtrackind,
			     &b_pjet_had_candtrackind);
    if (isMC) {
	fChain->SetBranchAddress("pjet_had_E_mctruth", &pjet_had_E_mctruth,
				 &b_pjet_had_E_mctruth);
	fChain->SetBranchAddress("pjet_had_mcpdgId", &pjet_had_mcpdgId,
				 &b_pjet_had_mcpdgId);
    }
    fChain->SetBranchAddress("pjet_had_ntwrs", &pjet_had_ntwrs,
			     &b_pjet_had_ntwrs);
    fChain->SetBranchAddress("pjet_ntwrs", &pjet_ntwrs, &b_pjet_ntwrs);
    fChain->SetBranchAddress("pjet_twr_ieta", &pjet_twr_ieta, &b_pjet_twr_ieta);
    fChain->SetBranchAddress("pjet_twr_iphi", &pjet_twr_iphi, &b_pjet_twr_iphi);
    fChain->SetBranchAddress("pjet_twr_depth", &pjet_twr_depth,
			     &b_pjet_twr_depth);
    fChain->SetBranchAddress("pjet_twr_subdet", &pjet_twr_subdet,
			     &b_pjet_twr_subdet);
    fChain->SetBranchAddress("pjet_twr_hade", &pjet_twr_hade, &b_pjet_twr_hade);
    fChain->SetBranchAddress("pjet_twr_frac", &pjet_twr_frac, &b_pjet_twr_frac);
    fChain->SetBranchAddress("pjet_twr_candtrackind", &pjet_twr_candtrackind,
			     &b_pjet_twr_candtrackind);
    fChain->SetBranchAddress("pjet_twr_hadind", &pjet_twr_hadind,
			     &b_pjet_twr_hadind);
    fChain->SetBranchAddress("pjet_twr_elmttype", &pjet_twr_elmttype,
			     &b_pjet_twr_elmttype);
    fChain->SetBranchAddress("pjet_twr_dR", &pjet_twr_dR, &b_pjet_twr_dR);
    fChain->SetBranchAddress("pjet_twr_clusterind", &pjet_twr_clusterind,
			     &b_pjet_twr_clusterind);
    fChain->SetBranchAddress("pjet_cluster_n", &pjet_cluster_n,
			     &b_pjet_cluster_n);
    fChain->SetBranchAddress("pjet_cluster_eta", &pjet_cluster_eta,
			     &b_pjet_cluster_eta);
    fChain->SetBranchAddress("pjet_cluster_phi", &pjet_cluster_phi,
			     &b_pjet_cluster_phi);
    fChain->SetBranchAddress("pjet_cluster_dR", &pjet_cluster_dR,
			     &b_pjet_cluster_dR);
    fChain->SetBranchAddress("pjet_ncandtracks", &pjet_ncandtracks,
			     &b_pjet_ncandtracks);
    fChain->SetBranchAddress("pjet_candtrack_px", &pjet_candtrack_px,
			     &b_pjet_candtrack_px);
    fChain->SetBranchAddress("pjet_candtrack_py", &pjet_candtrack_py,
			     &b_pjet_candtrack_py);
    fChain->SetBranchAddress("pjet_candtrack_pz", &pjet_candtrack_pz,
			     &b_pjet_candtrack_pz);
    fChain->SetBranchAddress("pjet_candtrack_EcalE", &pjet_candtrack_EcalE,
			     &b_pjet_candtrack_EcalE);
    fChain->SetBranchAddress("dijet_deta", &dijet_deta, &b_dijet_deta);
    fChain->SetBranchAddress("dijet_dphi", &dijet_dphi, &b_dijet_dphi);
    fChain->SetBranchAddress("dijet_balance", &dijet_balance, &b_dijet_balance);
    fChain->SetBranchAddress("thirdjet_px", &thirdjet_px, &b_thirdjet_px);
    fChain->SetBranchAddress("thirdjet_py", &thirdjet_py, &b_thirdjet_py);
    fChain->SetBranchAddress("thirdjet_px_uncorr", &thirdjet_px_uncorr,
			     &b_thirdjet_px_uncorr);
    fChain->SetBranchAddress("thirdjet_py_uncorr", &thirdjet_py_uncorr,
			     &b_thirdjet_py_uncorr);
    fChain->SetBranchAddress("Run", &Run, &b_Run);
    fChain->SetBranchAddress("Lumi", &Lumi, &b_Lumi);
    fChain->SetBranchAddress("Event", &Event, &b_Event);
    fChain->SetBranchAddress("NPV", &NPV, &b_NPV);
    if (isMC)
	fChain->SetBranchAddress("weight", &weight, &b_weight);
    else
	weight = 1.0;
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

void DijetTree::SetCuts(Double_t maxDeltaEta_, Double_t minSumJetEt_,
			Double_t minJetEt_, Double_t maxThirdJetEt_)
{
    cut_maxDeltaEta   = maxDeltaEta_;
    cut_minSumJetEt   = minSumJetEt_;
    cut_minJetEt      = minJetEt_;
    cut_maxThirdJetEt = maxThirdJetEt_;
    return;
}

Int_t DijetTree::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  0 if entry is accepted.
// returns >0 otherwise.
    int passSel = 0;
    if (tjet_ntwrs == 0 || pjet_ntwrs == 0) {
	passSel |= 0x80;
    }
    float tjet_Et = tjet_E / cosh(tjet_eta);
    float pjet_Et = pjet_E / cosh(pjet_eta);
    if (tjet_Et + pjet_Et < cut_minSumJetEt)
	passSel |= 0x1;
    if (tjet_Et < cut_minJetEt || pjet_Et < cut_minJetEt)
	passSel |= 0x2;
    if (sqrt(thirdjet_px * thirdjet_px + thirdjet_py * thirdjet_py)
	> cut_maxThirdJetEt)
	passSel |= 0x4;
    if (dijet_deta > cut_maxDeltaEta)
	passSel |= 0x8;
    if (tjet_jetID != 3 || pjet_jetID != 3)
	passSel |= 0x100;

    return passSel;
}

Double_t DijetTree::GetNeutralPUCorr(Double_t eta, Double_t area)
{
    double dNPV = static_cast<double>(NPV);
    double etaArray[101] =
	{ -5.0, -4.9, -4.8, -4.7, -4.6, -4.5, -4.4, -4.3, -4.2, -4.1, -4.0,
    -3.9, -3.8, -3.7, -3.6, -3.5, -3.4, -3.3, -3.2, -3.1, -3.0, -2.9, -2.8,
    -2.7, -2.6, -2.5, -2.4, -2.3, -2.2, -2.1, -2.0, -1.9, -1.8, -1.7, -1.6,
    -1.5, -1.4, -1.3, -1.2, -1.1, -1.0, -0.9, -0.8, -0.7, -0.6, -0.5, -0.4,
    -0.3, -0.2, -0.1, 0.0, 0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9, 1.0,
       1.1, 1.2, 1.3, 1.4, 1.5, 1.6, 1.7, 1.8, 1.9, 2.0, 2.1, 2.2, 2.3, 2.4,
       2.5, 2.6, 2.7, 2.8, 2.9, 3.0, 3.1, 3.2, 3.3, 3.4, 3.5, 3.6, 3.7, 3.8,
       3.9, 4.0, 4.1, 4.2, 4.3, 4.4, 4.5, 4.6, 4.7, 4.8, 4.9, 5.0 };

    int ind = -1;
    for (int i=0; i<100; ++i) {
	if (eta > etaArray[i] && eta < etaArray[i + 1]) {
	    ind = i;
	    break;
	}
    }
    if (ind < 0)
	return 0;

    double pt_density;
    if (isMC) {
	double p0[100] =
	    { 0.08187, 0.096718, 0.11565, 0.12115, 0.12511, 0.12554,
   0.13858, 0.14282, 0.14302, 0.15054, 0.14136, 0.14992, 0.13812, 0.13771,
   0.13165, 0.12609, 0.12446, 0.11311, 0.13771, 0.16401, 0.20454, 0.27899,
   0.34242, 0.43096, 0.50742, 0.59683, 0.66877, 0.68664, 0.69541, 0.66873,
   0.64175, 0.61097, 0.58524, 0.5712, 0.55752, 0.54869, 0.31073, 0.22667,
   0.55614, 0.55962, 0.54348, 0.53206, 0.51594, 0.49928, 0.49139, 0.48766,
   0.49157, 0.49587, 0.50109, 0.5058, 0.51279, 0.51515, 0.51849, 0.52607,
   0.52362, 0.52169, 0.53579, 0.54821, 0.56262, 0.58355, 0.58809, 0.57525,
   0.52539, 0.53505, 0.52307, 0.52616, 0.52678, 0.53536, 0.55141, 0.58107,
   0.60556, 0.62601, 0.60897, 0.59018, 0.49593, 0.40462, 0.32052, 0.24436,
   0.18867, 0.12591, 0.095421, 0.090578, 0.078767, 0.11797, 0.14057,
   0.14614, 0.15232, 0.14742, 0.15647, 0.14947, 0.15805, 0.14467, 0.14526,
   0.14081, 0.1262, 0.12429, 0.11951, 0.11146, 0.095677, 0.083126 };
	double p1[100] =
	    { 0.26831, 0.30901, 0.37017, 0.38747, 0.41547, 0.45237,
   0.49963, 0.54074, 0.54949, 0.5937, 0.56904, 0.60766, 0.58042, 0.59823,
   0.58535, 0.54594, 0.58403, 0.601, 0.65401, 0.65049, 0.65264, 0.6387,
   0.60646, 0.59669, 0.55561, 0.5053, 0.42889, 0.37264, 0.36456, 0.36088,
   0.36728, 0.37439, 0.38779, 0.40133, 0.40989, 0.41722, 0.47539, 0.49848,
   0.42642, 0.42431, 0.42113, 0.41285, 0.41003, 0.41116, 0.41231, 0.41634,
   0.41795, 0.41806, 0.41786, 0.41765, 0.41779, 0.41961, 0.42144, 0.42192,
   0.4209, 0.41885, 0.4163, 0.4153, 0.41864, 0.4257, 0.43018, 0.43218,
   0.43798, 0.42723, 0.42185, 0.41349, 0.40553, 0.39132, 0.3779, 0.37055,
   0.36522, 0.37057, 0.38058, 0.43259, 0.51052, 0.55918, 0.60178, 0.60995,
   0.64087, 0.65554, 0.65308, 0.65654, 0.60466, 0.58678, 0.54392, 0.58277,
   0.59651, 0.57916, 0.60744, 0.56882, 0.59323, 0.5499, 0.54003, 0.49938,
   0.4511, 0.41499, 0.38676, 0.36955, 0.30803, 0.26659 };
	double p2[100] =
	    { 0.00080918, 0.00083447, 0.0011378, 0.0011221, 0.0013613,
   0.0016362, 0.0015854, 0.0019131, 0.0017474, 0.0020078, 0.001856,
   0.0020331, 0.0020823, 0.001898, 0.0020096, 0.0016464, 0.0032413,
   0.0045615, 0.0054495, 0.0057584, 0.0058982, 0.0058956, 0.0055109,
   0.0051433, 0.0042098, 0.0032096, 0.00044089, -0.0003884, -0.0007059,
   -0.00092769, -0.001116, -0.0010437, -0.00080318, -0.00044142,
   6.7232e-05, 0.00055265, -0.0014486, -0.0020432, 0.0015121, 0.0016343,
   0.0015638, 0.0015707, 0.0014403, 0.0012886, 0.0011684, 0.00099089,
   0.00091497, 0.00087915, 0.00084703, 0.00084542, 0.00087419, 0.00088013,
   0.00090493, 0.00095853, 0.0010389, 0.0011191, 0.0012643, 0.0013833,
   0.001474, 0.0015401, 0.0015582, 0.0014265, 0.00087453, 0.00086639,
   0.00042986, -5.0257e-06, -0.00053124, -0.00086417, -0.0011228,
   -0.0011749, -0.0010068, -0.00083012, -0.00062906, 0.00021515, 0.0028714,
   0.0038835, 0.0047212, 0.0051427, 0.0055762, 0.0055872, 0.0054989,
   0.0053033, 0.0044519, 0.0032223, 0.0017641, 0.0021165, 0.0019909,
   0.0021061, 0.0020322, 0.0018357, 0.0019829, 0.001683, 0.0018553,
   0.0015304, 0.0015822, 0.0013119, 0.0010745, 0.0010808, 0.00080678,
   0.00079756 };
	pt_density = p0[ind] + p1[ind]*(dNPV - 1)
	           + p2[ind]*(dNPV - 1)*(dNPV - 1);
    } else {
	double p0[100] =
	    { 0.12523, 0.14896, 0.17696, 0.19376, 0.20038, 0.21353,
   0.25069, 0.27089, 0.29124, 0.31947, 0.31781, 0.35453, 0.35424, 0.38159,
   0.39453, 0.4003, 0.34798, 0.26303, 0.24824, 0.22857, 0.22609, 0.26793,
   0.30096, 0.37637, 0.44461, 0.55692, 0.70328, 0.72458, 0.75065, 0.73569,
   0.72485, 0.69933, 0.69804, 0.70775, 0.70965, 0.71439, 0.72189, 0.73691,
   0.74847, 0.74968, 0.73467, 0.70115, 0.6732, 0.65971, 0.65724, 0.67751,
   0.69569, 0.70905, 0.71815, 0.72119, 0.72128, 0.71645, 0.70588, 0.68958,
   0.66978, 0.65959, 0.66889, 0.68713, 0.71063, 0.74283, 0.75153, 0.74733,
   0.73335, 0.71346, 0.70168, 0.69445, 0.68841, 0.67761, 0.67654, 0.6957,
   0.70276, 0.71057, 0.68176, 0.64651, 0.49156, 0.38366, 0.31375, 0.24127,
   0.21395, 0.17783, 0.19026, 0.21486, 0.24689, 0.3434, 0.40184, 0.39876,
   0.3873, 0.36462, 0.36337, 0.32777, 0.328, 0.29868, 0.28087, 0.25713,
   0.22466, 0.20784, 0.19798, 0.18054, 0.15022, 0.12811 };
	double p1[100] =
	    { 0.26829, 0.30825, 0.37034, 0.38736, 0.41645, 0.45985,
   0.51433, 0.56215, 0.5805, 0.63926, 0.62007, 0.67895, 0.66015, 0.68817,
   0.67975, 0.64161, 0.70887, 0.74454, 0.80197, 0.78873, 0.77892, 0.74943,
   0.70034, 0.6735, 0.60774, 0.53312, 0.42132, 0.36279, 0.3547, 0.35014,
   0.35655, 0.3646, 0.37809, 0.38922, 0.39599, 0.40116, 0.40468, 0.40645,
   0.40569, 0.4036, 0.39874, 0.39326, 0.39352, 0.39761, 0.40232, 0.40729,
   0.41091, 0.41247, 0.413, 0.41283, 0.41289, 0.4134, 0.41322, 0.41185,
   0.40769, 0.40193, 0.39707, 0.39254, 0.39274, 0.3989, 0.40474, 0.40758,
   0.40788, 0.40667, 0.40433, 0.40013, 0.39371, 0.38154, 0.36723, 0.3583,
   0.35148, 0.35556, 0.36172, 0.41073, 0.50629, 0.57068, 0.62972, 0.65188,
   0.69954, 0.72967, 0.74333, 0.76148, 0.71418, 0.69062, 0.63065, 0.67117,
   0.68278, 0.66028, 0.68147, 0.62494, 0.64452, 0.58685, 0.57076, 0.52387,
   0.47132, 0.42637, 0.39554, 0.37989, 0.31825, 0.27969 };
	double p2[100] =
	    { -0.0014595, -0.0014618, -0.0011988, -0.00095404, -5.3893e-05,
   0.00018901, 0.00012553, 0.0004172, 0.00020229, 0.00051942, 0.00052088,
   0.00076727, 0.0010407, 0.0010184, 0.0013442, 0.0011271, 0.0032841,
   0.0045259, 0.0051803, 0.0054477, 0.0055691, 0.0056668, 0.0053084,
   0.0050978, 0.0042061, 0.003321, 0.00045155, 0.00021376, 0.0001178,
   -2.6836e-05, -0.00017689, -0.00014723, 0.00016887, 0.00067322,
   0.0012952, 0.0019229, 0.0024702, 0.0028854, 0.0031576, 0.003284,
   0.0032643, 0.0031061, 0.0028377, 0.0025386, 0.0022583, 0.0020448,
   0.001888, 0.0017968, 0.0017286, 0.0016989, 0.0017014, 0.0017302,
   0.0017958, 0.0018891, 0.0020609, 0.0022876, 0.0025391, 0.0028109,
   0.0030294, 0.0031867, 0.0032068, 0.0030755, 0.0028181, 0.0023893,
   0.0018359, 0.0012192, 0.00061654, 0.00016088, -0.00015204, -0.00019503,
   -3.7236e-05, 0.00016663, 0.00033833, 0.00082988, 0.0034005, 0.0042941,
   0.0050884, 0.0052612, 0.0055901, 0.0054357, 0.0052671, 0.0049174,
   0.0042236, 0.0031138, 0.0011733, 0.0014057, 0.0010843, 0.0010992,
   0.0007966, 0.00052196, 0.00053029, 0.00021273, 0.00041664, 0.00010455,
   0.00015173, -9.7827e-05, -0.0010859, -0.0013748, -0.0016641,
   -0.0016887 };
	pt_density = p0[ind] + p1[ind]*(dNPV - 1)
	           + p2[ind]*(dNPV - 1)*(dNPV - 1);
    }

    double ECorr = pt_density*area*cosh(eta);

    return ECorr;
}

void DijetTree::Loop(DijetRespCorrData *data)
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
    cout << "Running over " << nentries << " events" << endl;

    Long64_t nbytes = 0, nb = 0;
    for (Long64_t jentry=0; jentry<nentries;jentry++) {
	if (jentry % 10000 == 0) {
	    cout << "Processing event " << jentry << endl;
	}
	Long64_t ientry = LoadTree(jentry);
	if (ientry < 0) break;
	nb = fChain->GetEntry(jentry);
	nbytes += nb;
	if (Cut(ientry))
	    continue;

	DijetRespCorrDatum datum;

	// Fill datum
	datum.SetWeight(weight);

	float sumt = 0;
	datum.SetTagEta(tjet_eta);
	datum.SetTagPhi(tjet_phi);
	datum.SetTagGenE(tjet_genE);
	for (int i = 0; i < tjet_ntwrs; ++i) {
	    if (tjet_twr_hade->at(i) > 0.0
		&& (tjet_twr_clusterind->at(i) < 0
		    || tjet_cluster_dR->at(tjet_twr_clusterind->at(i)) < 0.5)) {
		datum.AddTagHcalE(tjet_twr_hade->at(i) * tjet_twr_frac->at(i),
				  tjet_twr_ieta->at(i));
		sumt += tjet_twr_hade->at(i) * tjet_twr_frac->at(i);
	    }
	}

	float tjet_had_EcalE_total = 0;
	float tjet_had_candNoRecHits_E = 0;
	for (int iHad=0; iHad<tjet_had_n; ++iHad) {
	    if (tjet_had_id->at(iHad) < 2)
		tjet_had_EcalE_total += tjet_had_EcalE->at(iHad);
	    if (tjet_had_ntwrs->at(iHad) == 0
		&& tjet_had_candtrackind->at(iHad) > -1) {
		tjet_had_candNoRecHits_E +=
		    sqrt(tjet_candtrack_px->
			 at(tjet_had_candtrackind->at(iHad))
			 * tjet_candtrack_px->at(tjet_had_candtrackind->
						 at(iHad))
			 + tjet_candtrack_py->at(tjet_had_candtrackind->
						 at(iHad))
			 * tjet_candtrack_py->at(tjet_had_candtrackind->
						 at(iHad))
			 + tjet_candtrack_pz->at(tjet_had_candtrackind->
						 at(iHad))
			 * tjet_candtrack_pz->at(tjet_had_candtrackind->
						 at(iHad)))
		    - tjet_had_EcalE->at(iHad);
	    }
	}
	datum.SetTagEcalE(tjet_unkown_E + tjet_electron_E
			  + tjet_muon_E + tjet_photon_E
			  + tjet_had_EcalE_total + tjet_had_candNoRecHits_E
			  - GetNeutralPUCorr(tjet_eta, tjet_area));

	float sump = 0;
	datum.SetProbeEta(pjet_eta);
	datum.SetProbePhi(pjet_phi);
	datum.SetProbeGenE(pjet_genE);
	for (int i=0; i<pjet_ntwrs; ++i) {
	    if (pjet_twr_hade->at(i) > 0.0
		&& (pjet_twr_clusterind->at(i) < 0
		    || pjet_cluster_dR->at(pjet_twr_clusterind->at(i)) < 0.5)) {
		datum.AddProbeHcalE(pjet_twr_hade->at(i)
				    * pjet_twr_frac->at(i),
				    pjet_twr_ieta->at(i));
		sump += pjet_twr_hade->at(i) * pjet_twr_frac->at(i);
	    }
	}

	float pjet_had_EcalE_total = 0;
	float pjet_had_candNoRecHits_E = 0;
	for (int iHad=0; iHad<pjet_had_n; ++iHad) {
	    if (pjet_had_id->at(iHad) < 2)
		pjet_had_EcalE_total += pjet_had_EcalE->at(iHad);
	    if (pjet_had_ntwrs->at(iHad) == 0
		&& pjet_had_candtrackind->at(iHad) > -1) {
		pjet_had_candNoRecHits_E +=
		    sqrt(pjet_candtrack_px->
			 at(pjet_had_candtrackind->at(iHad))
			 * pjet_candtrack_px->at(pjet_had_candtrackind->
						 at(iHad))
			 + pjet_candtrack_py->at(pjet_had_candtrackind->
						 at(iHad))
			 * pjet_candtrack_py->at(pjet_had_candtrackind->
						 at(iHad))
			 + pjet_candtrack_pz->at(pjet_had_candtrackind->
						 at(iHad))
			 * pjet_candtrack_pz->at(pjet_had_candtrackind->
						 at(iHad)))
		    - pjet_had_EcalE->at(iHad);
	    }
	}
	datum.SetProbeEcalE(pjet_unkown_E + pjet_electron_E
			    + pjet_muon_E + pjet_photon_E
			    + pjet_had_EcalE_total
			    + pjet_had_candNoRecHits_E
			    - GetNeutralPUCorr(pjet_eta, pjet_area));

	datum.SetThirdJetPx(thirdjet_px);
	datum.SetThirdJetPy(thirdjet_py);

	if (sumt == 0 || sump == 0) {
	    continue;
	}

	data->push_back(datum);
    }
}
