#include "DijetCalibration/RespCorrAlgos/bin/getPlots.h"

using namespace std;

int main(int argc, char *argv[])
{
    bool isMC;
    TString input_name;
    TString output_name;
    cout << argc << endl;
    if (argc == 4) {
	if (atoi(argv[1]) == 1)
	    isMC = true;
	else if (atoi(argv[1]) == 0)
	    isMC = false;
	else {
	    cout << " Usage: getPlots isMC input output" << endl;
	    return 1;
	}
	input_name = argv[2];
	output_name = argv[3];
    } else {
	cout << " Usage: getPlots isMC input output" << endl;
	return 1;
    }

    cout << "isMC: " << isMC << endl;
    cout << "input: " << input_name << endl;
    cout << "output: " << output_name << endl;

    float maxDeltaEta;
    float minSumJetEt;
    float minJetEt;
    float maxThirdJetEt;
    float maxAlpha;
    int initial_seed;

    TFile *input = new TFile(input_name, "READ");
    TTree *param_tree = 0;
    input->GetObject("Parameters", param_tree);
    param_tree->SetBranchAddress("maxDeltaEta", &maxDeltaEta);
    param_tree->SetBranchAddress("minSumJetEt", &minSumJetEt);
    param_tree->SetBranchAddress("minJetEt", &minJetEt);
    param_tree->SetBranchAddress("maxThirdJetEt", &maxThirdJetEt);
    param_tree->SetBranchAddress("maxAlpha", &maxAlpha);
    param_tree->SetBranchAddress("initial_seed", &initial_seed);
    param_tree->GetEntry(0);

    cout << maxDeltaEta << endl;
    cout << minSumJetEt << endl;
    cout << minJetEt << endl;
    cout << maxThirdJetEt << endl;
    cout << maxAlpha << endl;
    cout << initial_seed << endl;

    DijetRespCorrData data_selected;
    DijetRespCorrData data_sampled;

    TH1D *h_PassSel = new TH1D("h_PassSelection", "Selection Pass Failures",
			       256, -0.5, 255.5);

    TString inputs[6] =
{"/eos/uscms/store/user/dgsheffi/QCD_Pt_30to50_TuneCUETP8M1_13TeV_pythia8/DijetCalibration_dEta-1p5_sumEt-50_Et-20_3rdEt-100/5c7aa9a575a3633aed507656e4d402e2/tree_*.root",
 "/eos/uscms/store/user/dgsheffi/QCD_Pt_50to80_TuneCUETP8M1_13TeV_pythia8/DijetCalibration_dEta-1p5_sumEt-50_Et-20_3rdEt-100/5c7aa9a575a3633aed507656e4d402e2/tree_*.root",
 "/eos/uscms/store/user/dgsheffi/QCD_Pt_80to120_TuneCUETP8M1_13TeV_pythia8/DijetCalibration_dEta-1p5_sumEt-50_Et-20_3rdEt-100/5c7aa9a575a3633aed507656e4d402e2/tree_*.root",
 "/eos/uscms/store/user/dgsheffi/QCD_Pt_120to170_TuneCUETP8M1_13TeV_pythia8/DijetCalibration_dEta-1p5_sumEt-50_Et-20_3rdEt-100/5c7aa9a575a3633aed507656e4d402e2/tree_*.root",
 "/eos/uscms/store/user/dgsheffi/QCD_Pt_170to300_TuneCUETP8M1_13TeV_pythia8/DijetCalibration_dEta-1p5_sumEt-50_Et-20_3rdEt-100/5c7aa9a575a3633aed507656e4d402e2/tree_*.root",
 "/eos/uscms/store/user/dgsheffi/QCD_Pt_300to470_TuneCUETP8M1_13TeV_pythia8/DijetCalibration_dEta-1p5_sumEt-50_Et-20_3rdEt-100/5c7aa9a575a3633aed507656e4d402e2/tree_*.root"};
    double probability[6] = {1.0, 1.372714e-1, 2.805324e-2, 4.675765e-3,
				 1.175536e-3, 9.256953e-5};
    int seed = initial_seed;
    for (int i=0; i<6; ++i) {
	cout << "Opening " << inputs[i] << endl;
	TChain *tree = new TChain("dijettree");
	tree->Add(inputs[i]);

	DijetTree dijet_selected(tree, isMC);
	dijet_selected.SetCuts(maxDeltaEta, minSumJetEt, minJetEt,
			       maxThirdJetEt, maxAlpha);
	dijet_selected.Loop(&data_selected, h_PassSel, seed, probability[i]);

	DijetTree dijet_sampled(tree, isMC);
	dijet_sampled.SetCuts(1000.0, 0.0, 0.0, 1000.0, 1000.0);
	dijet_sampled.Loop(&data_sampled, h_PassSel, seed, probability[i]);


	++seed;
    }

    cout << data_selected.GetSize() << " data selected" << endl;

    TH1D *h_respcorr_init = new TH1D("h_respcorr_init",
				     "responce corrections of 1",
				     83, -41.5, 41.5);
    for (int i=1; i<84; ++i) {
	h_respcorr_init->SetBinContent(i, 1.0);
    }

    // Selected events, no corrections
    data_selected.SetPlotBalance("h_balance", "dijet balance", 200, -2.0, 2.0);
    data_selected.SetPlotEratiovsEta("h_Eratio_vs_Eta",
				     "E_{reco}/E_{gen} vs. #eta",
				     200, -5.0, 5.0, 200, 0.0, 2.0);
    data_selected.SetPlotEt("h_Et", "E_{T}", 200, 0.0, 400.0);
    data_selected.SetPlotEta("h_Eta", "#eta", 200, -5.0, 5.0);
    data_selected.SetPlotPhi("h_Phi", "#phi", 200, -3.1416, 3.1416);
    data_selected.SetPlotDEta("h_dEta", "#Delta|#eta|", 200, 0.0, 1.5);
    data_selected.SetPlotDPhi("h_dPhi", "#Delta#phi", 200, 0, 3.1416);
    data_selected.SetPlotEt2overEt1("h_Et2_over_Et1", "E_{T,2}/E_{T,1}",
				    200, 0.0, 1.0);
    data_selected.GetPlots(h_respcorr_init);
    TH1D *h_balance_sel_nocorr = data_selected.GetPlotBalance();
    TH2D *h_Eratio_vs_Eta_sel_nocorr = data_selected.GetPlotEratiovsEta();
    TH1D *h_Et_sel_nocorr = data_selected.GetPlotEt();
    TH1D *h_Eta_sel_nocorr = data_selected.GetPlotEta();
    TH1D *h_Phi_sel_nocorr = data_selected.GetPlotPhi();
    TH1D *h_dEta_sel_nocorr = data_selected.GetPlotDEta();
    TH1D *h_dPhi_sel_nocorr = data_selected.GetPlotDPhi();
    TH1D *h_Et2_over_Et1_sel_nocorr = data_selected.GetPlotEt2overEt1();
    TH1D *h_Eratio_all_sel_nocorr = static_cast<TH1D*>(
	h_Eratio_vs_Eta_sel_nocorr->ProjectionY("h_Eratio_all")->Clone());
    TH1D *h_Eratio_HB_sel_nocorr = static_cast<TH1D*>(
	h_Eratio_vs_Eta_sel_nocorr->ProjectionY(
	    "h_Eratio_HB", 74, 128)->Clone());
    TH1D *h_Eratio_HE_sel_nocorr = static_cast<TH1D*>(
	h_Eratio_vs_Eta_sel_nocorr->ProjectionY(
	    "h_Eratio_HE", 41, 73)->Clone());
    h_Eratio_HE_sel_nocorr->Add(
	static_cast<TH1D*>(h_Eratio_vs_Eta_sel_nocorr->ProjectionY(
			       "", 129, 161)->Clone()));

    TH1D *h_respcorr;
    input->GetObject("h_corr", h_respcorr);
    for (int i=1; i<84; ++i) {
	if (h_respcorr->GetBinContent(i) < 0.0)
	    h_respcorr->SetBinContent(i, 1.0);
    }

    double factor = data_selected.GetRespCorrScaleFactor(h_respcorr);
    h_respcorr->Scale(factor);

    // Selected events, with response corrections
    data_selected.SetPlotBalance("h_balance", "dijet balance", 200, -2.0, 2.0);
    data_selected.SetPlotEratiovsEta("h_Eratio_vs_Eta",
				     "E_{reco}/E_{gen} vs. #eta",
				     200, -5.0, 5.0, 200, 0.0, 2.0);
    data_selected.SetPlotEt("h_Et", "E_{T}", 200, 0.0, 400.0);
    data_selected.SetPlotEta("h_Eta", "#eta", 200, -5.0, 5.0);
    data_selected.SetPlotPhi("h_Phi", "#phi", 200, -3.1416, 3.1416);
    data_selected.SetPlotDEta("h_dEta", "#Delta|#eta|", 200, 0.0, 1.5);
    data_selected.SetPlotDPhi("h_dPhi", "#Delta#phi", 200, 0, 3.1416);
    data_selected.SetPlotEt2overEt1("h_Et2_over_Et1", "E_{T,2}/E_{T,1}",
				    200, 0.0, 1.0);
    data_selected.GetPlots(h_respcorr);
    TH1D *h_balance_sel_respcorr = data_selected.GetPlotBalance();
    TH2D *h_Eratio_vs_Eta_sel_respcorr = data_selected.GetPlotEratiovsEta();
    TH1D *h_Et_sel_respcorr = data_selected.GetPlotEt();
    TH1D *h_Eta_sel_respcorr = data_selected.GetPlotEta();
    TH1D *h_Phi_sel_respcorr = data_selected.GetPlotPhi();
    TH1D *h_dEta_sel_respcorr = data_selected.GetPlotDEta();
    TH1D *h_dPhi_sel_respcorr = data_selected.GetPlotDPhi();
    TH1D *h_Et2_over_Et1_sel_respcorr = data_selected.GetPlotEt2overEt1();
    TH1D *h_Eratio_all_sel_respcorr = static_cast<TH1D*>(
	h_Eratio_vs_Eta_sel_respcorr->ProjectionY("h_Eratio_all")->Clone());
    TH1D *h_Eratio_HB_sel_respcorr = static_cast<TH1D*>(
	h_Eratio_vs_Eta_sel_respcorr->ProjectionY(
	    "h_Eratio_HB", 74, 128)->Clone());
    TH1D *h_Eratio_HE_sel_respcorr = static_cast<TH1D*>(
	h_Eratio_vs_Eta_sel_respcorr->ProjectionY(
	    "h_Eratio_HE", 41, 73)->Clone());
    h_Eratio_HE_sel_respcorr->Add(
	static_cast<TH1D*>(h_Eratio_vs_Eta_sel_respcorr->ProjectionY(
			       "", 129, 161)->Clone()));

    // Sampled events, no corrections
    data_sampled.SetPlotBalance("h_balance", "dijet balance", 200, -2.0, 2.0);
    data_sampled.SetPlotEratiovsEta("h_Eratio_vs_Eta",
				    "E_{reco}/E_{gen} vs. #eta",
				    200, -5.0, 5.0, 200, 0.0, 2.0);
    data_sampled.SetPlotEt("h_Et", "E_{T}", 200, 0.0, 400.0);
    data_sampled.SetPlotEta("h_Eta", "#eta", 200, -5.0, 5.0);
    data_sampled.SetPlotPhi("h_Phi", "#phi", 200, -3.1416, 3.1416);
    data_sampled.SetPlotDEta("h_dEta", "#Delta|#eta|", 200, 0.0, 1.5);
    data_sampled.SetPlotDPhi("h_dPhi", "#Delta#phi", 200, 0, 3.1416);
    data_sampled.SetPlotEt2overEt1("h_Et2_over_Et1", "E_{T,2}/E_{T,1}",
				   200, 0.0, 1.0);
    data_sampled.GetPlots(h_respcorr_init);
    TH1D *h_balance_samp_nocorr = data_sampled.GetPlotBalance();
    TH2D *h_Eratio_vs_Eta_samp_nocorr = data_sampled.GetPlotEratiovsEta();
    TH1D *h_Et_samp_nocorr = data_sampled.GetPlotEt();
    TH1D *h_Eta_samp_nocorr = data_sampled.GetPlotEta();
    TH1D *h_Phi_samp_nocorr = data_sampled.GetPlotPhi();
    TH1D *h_dEta_samp_nocorr = data_sampled.GetPlotDEta();
    TH1D *h_dPhi_samp_nocorr = data_sampled.GetPlotDPhi();
    TH1D *h_Et2_over_Et1_samp_nocorr = data_sampled.GetPlotEt2overEt1();
    TH1D *h_Eratio_all_samp_nocorr = static_cast<TH1D*>(
	h_Eratio_vs_Eta_samp_nocorr->ProjectionY("h_Eratio_all")->Clone());
    TH1D *h_Eratio_HB_samp_nocorr = static_cast<TH1D*>(
	h_Eratio_vs_Eta_samp_nocorr->ProjectionY(
	    "h_Eratio_HB", 74, 128)->Clone());
    TH1D *h_Eratio_HE_samp_nocorr = static_cast<TH1D*>(
	h_Eratio_vs_Eta_samp_nocorr->ProjectionY(
	    "h_Eratio_HE", 41, 73)->Clone());
    h_Eratio_HE_samp_nocorr->Add(
	static_cast<TH1D*>(h_Eratio_vs_Eta_samp_nocorr->ProjectionY(
			       "", 129, 161)->Clone()));

    // Sampled events, with response corrections
    data_sampled.SetPlotBalance("h_balance", "dijet balance", 200, -2.0, 2.0);
    data_sampled.SetPlotEratiovsEta("h_Eratio_vs_Eta",
				    "E_{reco}/E_{gen} vs. #eta",
				    200, -5.0, 5.0, 200, 0.0, 2.0);
    data_sampled.SetPlotEt("h_Et", "E_{T}", 200, 0.0, 400.0);
    data_sampled.SetPlotEta("h_Eta", "#eta", 200, -5.0, 5.0);
    data_sampled.SetPlotPhi("h_Phi", "#phi", 200, -3.1416, 3.1416);
    data_sampled.SetPlotDEta("h_dEta", "#Delta|#eta|", 200, 0.0, 1.5);
    data_sampled.SetPlotDPhi("h_dPhi", "#Delta#phi", 200, 0, 3.1416);
    data_sampled.SetPlotEt2overEt1("h_Et2_over_Et1", "E_{T,2}/E_{T,1}",
				   200, 0.0, 1.0);
    data_sampled.GetPlots(h_respcorr);
    TH1D *h_balance_samp_respcorr = data_sampled.GetPlotBalance();
    TH2D *h_Eratio_vs_Eta_samp_respcorr = data_sampled.GetPlotEratiovsEta();
    TH1D *h_Et_samp_respcorr = data_sampled.GetPlotEt();
    TH1D *h_Eta_samp_respcorr = data_sampled.GetPlotEta();
    TH1D *h_Phi_samp_respcorr = data_sampled.GetPlotPhi();
    TH1D *h_dEta_samp_respcorr = data_sampled.GetPlotDEta();
    TH1D *h_dPhi_samp_respcorr = data_sampled.GetPlotDPhi();
    TH1D *h_Et2_over_Et1_samp_respcorr = data_sampled.GetPlotEt2overEt1();
    TH1D *h_Eratio_all_samp_respcorr = static_cast<TH1D*>(
	h_Eratio_vs_Eta_samp_respcorr->ProjectionY("h_Eratio_all")->Clone());
    TH1D *h_Eratio_HB_samp_respcorr = static_cast<TH1D*>(
	h_Eratio_vs_Eta_samp_respcorr->ProjectionY(
	    "h_Eratio_HB", 74, 128)->Clone());
    TH1D *h_Eratio_HE_samp_respcorr = static_cast<TH1D*>(
	h_Eratio_vs_Eta_samp_respcorr->ProjectionY(
	    "h_Eratio_HE", 41, 73)->Clone());
    h_Eratio_HE_samp_respcorr->Add(
	static_cast<TH1D*>(h_Eratio_vs_Eta_samp_respcorr->ProjectionY(
			       "", 129, 161)->Clone()));

    TFile *fout = new TFile(output_name, "RECREATE");

    TDirectory *dir_selected = fout->mkdir("Selected");
    TDirectory *dir_selected_respcorr
	= dir_selected->mkdir("Response_Corrections");
    TDirectory *dir_selected_nocorr = dir_selected->mkdir("No_Corrections");

    TDirectory *dir_sampled = fout->mkdir("Sampled");
    TDirectory *dir_sampled_respcorr
	= dir_sampled->mkdir("Response_Corrections");
    TDirectory *dir_sampled_nocorr = dir_sampled->mkdir("No_Corrections");

    dir_selected_nocorr->cd();
    h_balance_sel_nocorr->Write();
    h_Eratio_vs_Eta_sel_nocorr->Write();
    h_Eratio_all_sel_nocorr->Write();
    h_Eratio_HB_sel_nocorr->Write();
    h_Eratio_HE_sel_nocorr->Write();
    h_Et_sel_nocorr->Write();
    h_Eta_sel_nocorr->Write();
    h_Phi_sel_nocorr->Write();
    h_dEta_sel_nocorr->Write();
    h_dPhi_sel_nocorr->Write();
    h_Et2_over_Et1_sel_nocorr->Write();

    dir_selected_respcorr->cd();
    h_balance_sel_respcorr->Write();
    h_Eratio_vs_Eta_sel_respcorr->Write();
    h_Eratio_HB_sel_respcorr->Write();
    h_Eratio_HE_sel_respcorr->Write();
    h_Eratio_all_sel_respcorr->Write();
    h_Et_sel_respcorr->Write();
    h_Eta_sel_respcorr->Write();
    h_Phi_sel_respcorr->Write();
    h_dEta_sel_respcorr->Write();
    h_dPhi_sel_respcorr->Write();
    h_Et2_over_Et1_sel_respcorr->Write();

    dir_sampled_nocorr->cd();
    h_balance_samp_nocorr->Write();
    h_Eratio_vs_Eta_samp_nocorr->Write();
    h_Eratio_all_samp_nocorr->Write();
    h_Eratio_HB_samp_nocorr->Write();
    h_Eratio_HE_samp_nocorr->Write();
    h_Et_samp_nocorr->Write();
    h_Eta_samp_nocorr->Write();
    h_Phi_samp_nocorr->Write();
    h_dEta_samp_nocorr->Write();
    h_dPhi_samp_nocorr->Write();
    h_Et2_over_Et1_samp_nocorr->Write();

    dir_sampled_respcorr->cd();
    h_balance_samp_respcorr->Write();
    h_Eratio_vs_Eta_samp_respcorr->Write();
    h_Eratio_all_samp_respcorr->Write();
    h_Eratio_HB_samp_respcorr->Write();
    h_Eratio_HE_samp_respcorr->Write();
    h_Et_samp_respcorr->Write();
    h_Eta_samp_respcorr->Write();
    h_Phi_samp_respcorr->Write();
    h_dEta_samp_respcorr->Write();
    h_dPhi_samp_respcorr->Write();
    h_Et2_over_Et1_samp_respcorr->Write();

    fout->Close();

    return 0;
}
