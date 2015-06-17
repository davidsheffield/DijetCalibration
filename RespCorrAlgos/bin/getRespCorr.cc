#include "DijetCalibration/RespCorrAlgos/bin/getRespCorr.h"

using namespace std;

int main(int argc, char *argv[])
{
    int debug = 0;

    bool isMC = false;
    float maxDeltaEta_ = 0.5;
    float minSumJetEt_ = 50.0;
    float minJetEt_ = 25.0;
    float maxThirdJetEt_ = 15.0;
    float maxAlpha_ = 1000.0;

    cout << argc << endl;
    if (argc > 1) {
	if (atoi(argv[1]) == 1)
	    isMC = true;
	else if (atoi(argv[1]) == 0)
	    isMC = false;
	else {
	    cout << " Usage: getRespCorr isMC dEta sumEt Et 3rdEt alpha [debug]"
		 << endl;
	    return 1;
	}
    }
    if (argc > 2)
	maxDeltaEta_ = atof(argv[2]);
    if (argc > 3)
	minSumJetEt_ = atof(argv[3]);
    if (argc > 4)
	minJetEt_ = atof(argv[4]);
    if (argc > 5)
	maxThirdJetEt_ = atof(argv[5]);
    if (argc > 6)
	maxAlpha_ = atof(argv[6]);
    if (argc > 7)
	debug = atoi(argv[7]);
    if (argc > 8) {
	cout << "Too many arguments." << endl;
	cout << " Usage: getRespCorr isMC dEta sumEt Et 3rdEt alpha [debug]"
	     << endl;
	return 1;
    }

    cout << "isMC: " << isMC << endl;
    cout << "dEta: " << maxDeltaEta_ << endl;
    cout << "sumEt: " << minSumJetEt_ << endl;
    cout << "3rdEt: " << maxThirdJetEt_ << endl;

    int seed = 1;
    TTree *param_tree = new TTree("Parameters", "Parameters");
    param_tree->Branch("maxDeltaEta", &maxDeltaEta_, "maxDeltaEta/F");
    param_tree->Branch("minSumJetEt", &minSumJetEt_, "minSumJetEt/F");
    param_tree->Branch("minJetEt", &minJetEt_, "minJetEt/F");
    param_tree->Branch("maxThirdJetEt", &maxThirdJetEt_, "maxThirdJetEt/F");
    param_tree->Branch("maxAlpha", &maxAlpha_, "maxAlpha/F");
    param_tree->Branch("initial_seed", &seed, "initial_seed/I");
    param_tree->Fill();

    TTree *datasets_tree = new TTree("Datasets", "Datasets used");
    TString dataset_name;
    double dataset_prob;
    int dataset_seed;
    int dataset_events;
    datasets_tree->Branch("name", &dataset_name, "name/C");
    datasets_tree->Branch("probability", &dataset_prob, "probability/D");
    datasets_tree->Branch("seed", &dataset_seed, "seed/I");
    datasets_tree->Branch("events", &dataset_events, "events/I");

    int decimal1 = static_cast<int>(maxDeltaEta_*10)
	         - static_cast<int>(maxDeltaEta_)*10;
    int decimal2 = static_cast<int>(maxAlpha_*10)
	         - static_cast<int>(maxAlpha_)*10;
    TString output =
	"/uscms_data/d1/dgsheffi/HCal/corrections/sampling/corrections_dEta-"
	+ to_string(static_cast<int>(maxDeltaEta_)) + "p" + to_string(decimal1)
	+ "_sumEt-" + to_string(static_cast<int>(minSumJetEt_))
	+ "_Et-" + to_string(static_cast<int>(minJetEt_))
	+ "_3rdEt-" + to_string(static_cast<int>(maxThirdJetEt_))
	+ "_alpha-" + to_string(static_cast<int>(maxAlpha_)) + "p"
	+ to_string(decimal2) + ".root";
    if (debug & 0x1)
	output = "test.root";

    DijetRespCorrData data;

    TH1D *h_PassSel = new TH1D("h_PassSelection", "Selection Pass Failures",
			       256, -0.5, 255.5);
    TH1D *h_weights = LogXTH1D("h_weights","weights",200,1.0e-12,1.1);
    h_weights->GetXaxis()->SetTitle("weight");
    h_weights->GetYaxis()->SetTitle("events");

    if (debug & 0x1) {
	TString input = "/eos/uscms/store/user/dgsheffi/QCD_Pt_50to80_TuneCUETP8M1_13TeV_pythia8/DijetCalibration_dEta-1p5_sumEt-50_Et-20_3rdEt-100/5c7aa9a575a3633aed507656e4d402e2/tree_1_1_KKQ.root";
	cout << "Opening file: " << input << endl;
	TChain *tree = new TChain("dijettree");
	tree->Add(input);
	DijetTree dijettree(tree);
	dijettree.SetCuts(maxDeltaEta_, minSumJetEt_, minJetEt_,
			  maxThirdJetEt_, maxAlpha_);
	dijettree.Loop(&data, h_PassSel, 1, 1.0);

	dataset_name = input;
	dataset_prob = 1.0;
	dataset_seed = 1;
	dataset_events = data.GetSize();
	datasets_tree->Fill();
    } else {
	TString input[6] =
{"/eos/uscms/store/user/dgsheffi/QCD_Pt_30to50_TuneCUETP8M1_13TeV_pythia8/DijetCalibration_dEta-1p5_sumEt-50_Et-20_3rdEt-100/5c7aa9a575a3633aed507656e4d402e2/tree_*.root",
 "/eos/uscms/store/user/dgsheffi/QCD_Pt_50to80_TuneCUETP8M1_13TeV_pythia8/DijetCalibration_dEta-1p5_sumEt-50_Et-20_3rdEt-100/5c7aa9a575a3633aed507656e4d402e2/tree_*.root",
 "/eos/uscms/store/user/dgsheffi/QCD_Pt_80to120_TuneCUETP8M1_13TeV_pythia8/DijetCalibration_dEta-1p5_sumEt-50_Et-20_3rdEt-100/5c7aa9a575a3633aed507656e4d402e2/tree_*.root",
 "/eos/uscms/store/user/dgsheffi/QCD_Pt_120to170_TuneCUETP8M1_13TeV_pythia8/DijetCalibration_dEta-1p5_sumEt-50_Et-20_3rdEt-100/5c7aa9a575a3633aed507656e4d402e2/tree_*.root",
 "/eos/uscms/store/user/dgsheffi/QCD_Pt_170to300_TuneCUETP8M1_13TeV_pythia8/DijetCalibration_dEta-1p5_sumEt-50_Et-20_3rdEt-100/5c7aa9a575a3633aed507656e4d402e2/tree_*.root",
 "/eos/uscms/store/user/dgsheffi/QCD_Pt_300to470_TuneCUETP8M1_13TeV_pythia8/DijetCalibration_dEta-1p5_sumEt-50_Et-20_3rdEt-100/5c7aa9a575a3633aed507656e4d402e2/tree_*.root"};
	double probability[6] = {1.0, 1.372714e-1, 2.805324e-2, 4.675765e-3,
				 1.175536e-3, 9.256953e-5};
	int sampledEvents = 0;
	for (int i=0; i<6; ++i) {
	    cout << "Opening " << input[i] << endl;
	    TChain *tree = new TChain("dijettree");
	    tree->Add(input[i]);
	    DijetTree dijettree(tree);
	    dijettree.SetCuts(maxDeltaEta_, minSumJetEt_, minJetEt_,
			      maxThirdJetEt_, maxAlpha_);
	    dijettree.Loop(&data, h_PassSel, seed, probability[i]);

	    dataset_name = input[i];
	    dataset_prob = probability[i];
	    dataset_seed = seed;
	    dataset_events = data.GetSize() - sampledEvents;
	    datasets_tree->Fill();

	    ++seed;
	    sampledEvents = data.GetSize();
	}
    }

    cout << data.GetSize() << " data" << endl;

    cout << "Do CandTrack? " << data.GetDoCandTrackEnergyDiff() << endl;
    data.SetDoCandTrackEnergyDiff(false);
    cout << "Do CandTrack? " << data.GetDoCandTrackEnergyDiff() << endl;

    //return 0;

    TH1D *h_respcorr_init = new TH1D("h_respcorr_init",
				     "responce corrections of 1",
				     83, -41.5, 41.5);
    for(int i=1; i<84; ++i){
	h_respcorr_init->SetBinContent(i, 1.0);
    }
    TH1D *h_balance = new TH1D("h_balance", "dijet balance", 200, -2.0, 2.0);
    TH2D *h_Eratio_vs_Eta = new TH2D("h_Eratio_vs_Eta",
				     "E_{reco}/E_{gen} vs. #eta",
				     200, -5.0, 5.0, 200, 0.0, 2.0);
    TH2D *h_balance_term_vs_weight = LogXLogYTH2D("h_balance_term_vs_weight",
						  "B^{2}/(#DeltaB)^{2} vs weight",
						  200, 1.0e-7, 1.01,
						  200, 1.0e-7, 1.0e2);
    data.SetResolution(0.384);
    data.GetPlots(h_respcorr_init, h_balance, h_Eratio_vs_Eta,
		  h_balance_term_vs_weight);
    data.SetResolution(h_balance);

    TH1D *hist = 0;
    if (!(debug & 0x2)) {
	hist = data.doFit("h_corr", "Response Corrections");
	hist->GetXaxis()->SetTitle("i_{#eta}");
	hist->GetYaxis()->SetTitle("response corrections");
    }

    TFile *fout = new TFile(output, "RECREATE");
    fout->cd();
    param_tree->Write();
    datasets_tree->Write();
    if (!(debug & 0x2))
	hist->Write();
    h_PassSel->Write();
    h_weights->Write();
    h_balance->Write();
    h_Eratio_vs_Eta->Write();
    h_balance_term_vs_weight->Write();
    fout->Close();

    cout << "Events that passed cuts: " << h_PassSel->GetBinContent(1) << endl;

    return 0;
}

TH1D* LogXTH1D(const char* name, const char* title, Int_t nbinsx,
	       Double_t xlow, Double_t xup)
{
    Double_t logxlow = TMath::Log10(xlow);
    Double_t logxup = TMath::Log10(xup);
    Double_t binwidth = (logxup - logxlow)/nbinsx;
    Double_t xbins[nbinsx+1];
    for (int i=0; i<=nbinsx; ++i) {
	xbins[i] = TMath::Power(10,logxlow + i*binwidth);
    }
    TH1D *histogram = new TH1D(name, title, nbinsx, xbins);
    return histogram;
}

TH2D *LogXLogYTH2D(const char* name, const char* title,
		   Int_t nbinsx, Double_t xlow, Double_t xup,
		   Int_t nbinsy, Double_t ylow, Double_t yup)
{
    Double_t logxlow = TMath::Log10(xlow);
    Double_t logxup = TMath::Log10(xup);
    Double_t xbinwidth = (logxup - logxlow)/nbinsx;
    Double_t xbins[nbinsx+1];
    for (int i=0; i<=nbinsx; ++i) {
	xbins[i] = TMath::Power(10,logxlow + i*xbinwidth);
    }
    Double_t logylow = TMath::Log10(ylow);
    Double_t logyup = TMath::Log10(yup);
    Double_t ybinwidth = (logyup - logylow)/nbinsy;
    Double_t ybins[nbinsy+1];
    for (int i=0; i<=nbinsy; ++i) {
	ybins[i] = TMath::Power(10,logylow + i*ybinwidth);
    }
    TH2D *histogram = new TH2D(name, title, nbinsx, xbins, nbinsy, ybins);
    return histogram;
}
