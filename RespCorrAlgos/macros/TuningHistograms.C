//
// TuningPlots.C
//
// author: David G. Sheffield (Rutgers)
//

void GetPlots(TDirectory*, const int, const TString[], double[]);
double GetImprovement(const double, const double);
double GetNormImprovement(const double, const double, const double,
			  const double);

void TuningHistograms()
{
    const int num_files_dEta = 10;
    TString files_dEta[num_files_dEta] =
{"/uscms_data/d1/dgsheffi/HCal/corrections/sampling/Tuning/histograms_dEta-0p1_sumEt-100_Et-20_3rdEt-15_alpha-1000p0.root",
 "/uscms_data/d1/dgsheffi/HCal/corrections/sampling/Tuning/histograms_dEta-0p2_sumEt-100_Et-20_3rdEt-15_alpha-1000p0.root",
 "/uscms_data/d1/dgsheffi/HCal/corrections/sampling/Tuning/histograms_dEta-0p3_sumEt-100_Et-20_3rdEt-15_alpha-1000p0.root",
 "/uscms_data/d1/dgsheffi/HCal/corrections/sampling/Tuning/histograms_dEta-0p4_sumEt-100_Et-20_3rdEt-15_alpha-1000p0.root",
 "/uscms_data/d1/dgsheffi/HCal/corrections/sampling/Tuning/histograms_dEta-0p5_sumEt-100_Et-20_3rdEt-15_alpha-1000p0.root",
 "/uscms_data/d1/dgsheffi/HCal/corrections/sampling/Tuning/histograms_dEta-0p6_sumEt-100_Et-20_3rdEt-15_alpha-1000p0.root",
 "/uscms_data/d1/dgsheffi/HCal/corrections/sampling/Tuning/histograms_dEta-0p7_sumEt-100_Et-20_3rdEt-15_alpha-1000p0.root",
 "/uscms_data/d1/dgsheffi/HCal/corrections/sampling/Tuning/histograms_dEta-0p8_sumEt-100_Et-20_3rdEt-15_alpha-1000p0.root",
 "/uscms_data/d1/dgsheffi/HCal/corrections/sampling/Tuning/histograms_dEta-0p9_sumEt-100_Et-20_3rdEt-15_alpha-1000p0.root",
 "/uscms_data/d1/dgsheffi/HCal/corrections/sampling/Tuning/histograms_dEta-1p0_sumEt-100_Et-20_3rdEt-15_alpha-1000p0.root"};
    double bins_dEta[num_files_dEta+1] = {0.05, 0.15, 0.25, 0.35, 0.45, 0.55,
					  0.65, 0.75, 0.85, 0.95, 1.05};

    const int num_files_sumEt = 11;
    TString files_sumEt[num_files_sumEt] =
{"/uscms_data/d1/dgsheffi/HCal/corrections/sampling/Tuning/histograms_dEta-0p5_sumEt-50_Et-20_3rdEt-15_alpha-1000p0.root",
 "/uscms_data/d1/dgsheffi/HCal/corrections/sampling/Tuning/histograms_dEta-0p5_sumEt-60_Et-20_3rdEt-15_alpha-1000p0.root",
 "/uscms_data/d1/dgsheffi/HCal/corrections/sampling/Tuning/histograms_dEta-0p5_sumEt-70_Et-20_3rdEt-15_alpha-1000p0.root",
 "/uscms_data/d1/dgsheffi/HCal/corrections/sampling/Tuning/histograms_dEta-0p5_sumEt-80_Et-20_3rdEt-15_alpha-1000p0.root",
 "/uscms_data/d1/dgsheffi/HCal/corrections/sampling/Tuning/histograms_dEta-0p5_sumEt-90_Et-20_3rdEt-15_alpha-1000p0.root",
 "/uscms_data/d1/dgsheffi/HCal/corrections/sampling/Tuning/histograms_dEta-0p5_sumEt-100_Et-20_3rdEt-15_alpha-1000p0.root",
 "/uscms_data/d1/dgsheffi/HCal/corrections/sampling/Tuning/histograms_dEta-0p5_sumEt-110_Et-20_3rdEt-15_alpha-1000p0.root",
 "/uscms_data/d1/dgsheffi/HCal/corrections/sampling/Tuning/histograms_dEta-0p5_sumEt-120_Et-20_3rdEt-15_alpha-1000p0.root",
 "",
 "/uscms_data/d1/dgsheffi/HCal/corrections/sampling/Tuning/histograms_dEta-0p5_sumEt-140_Et-20_3rdEt-15_alpha-1000p0.root",
 "/uscms_data/d1/dgsheffi/HCal/corrections/sampling/Tuning/histograms_dEta-0p5_sumEt-150_Et-20_3rdEt-15_alpha-1000p0.root"};
    double bins_sumEt[num_files_sumEt+1] = {45.0, 55.0, 65.0, 75.0, 85.0, 95.0,
					    105.0, 115.0, 125.0, 135.0, 145.0,
					    155.0};

    const int num_files_thirdEt = 9;
    TString files_thirdEt[num_files_thirdEt] =
{"/uscms_data/d1/dgsheffi/HCal/corrections/sampling/Tuning/histograms_dEta-0p5_sumEt-100_Et-20_3rdEt-5_alpha-1000p0.root",
"/uscms_data/d1/dgsheffi/HCal/corrections/sampling/Tuning/histograms_dEta-0p5_sumEt-100_Et-20_3rdEt-10_alpha-1000p0.root",
 "/uscms_data/d1/dgsheffi/HCal/corrections/sampling/Tuning/histograms_dEta-0p5_sumEt-100_Et-20_3rdEt-15_alpha-1000p0.root",
 "/uscms_data/d1/dgsheffi/HCal/corrections/sampling/Tuning/histograms_dEta-0p5_sumEt-100_Et-20_3rdEt-20_alpha-1000p0.root",
 "/uscms_data/d1/dgsheffi/HCal/corrections/sampling/Tuning/histograms_dEta-0p5_sumEt-100_Et-20_3rdEt-25_alpha-1000p0.root",
 "/uscms_data/d1/dgsheffi/HCal/corrections/sampling/Tuning/histograms_dEta-0p5_sumEt-100_Et-20_3rdEt-30_alpha-1000p0.root",
 "/uscms_data/d1/dgsheffi/HCal/corrections/sampling/Tuning/histograms_dEta-0p5_sumEt-100_Et-20_3rdEt-50_alpha-1000p0.root",
 "/uscms_data/d1/dgsheffi/HCal/corrections/sampling/Tuning/histograms_dEta-0p5_sumEt-100_Et-20_3rdEt-75_alpha-1000p0.root",
 "/uscms_data/d1/dgsheffi/HCal/corrections/sampling/Tuning/histograms_dEta-0p5_sumEt-100_Et-20_3rdEt-100_alpha-1000p0.root"};
    double bins_thirdEt[num_files_thirdEt+1] = {2.5, 7.5, 12.5, 17.5, 22.5,
						27.5, 32.5, 67.5, 82.5, 117.5};

    const int num_files_alpha = 7;
    TString files_alpha[num_files_alpha] =
{"/uscms_data/d1/dgsheffi/HCal/corrections/sampling/Tuning/histograms_dEta-0p5_sumEt-100_Et-20_3rdEt-1000_alpha-0p05.root",
 "/uscms_data/d1/dgsheffi/HCal/corrections/sampling/Tuning/histograms_dEta-0p5_sumEt-100_Et-20_3rdEt-1000_alpha-0p1.root",
 "/uscms_data/d1/dgsheffi/HCal/corrections/sampling/Tuning/histograms_dEta-0p5_sumEt-100_Et-20_3rdEt-1000_alpha-0p15.root",
 "/uscms_data/d1/dgsheffi/HCal/corrections/sampling/Tuning/histograms_dEta-0p5_sumEt-100_Et-20_3rdEt-1000_alpha-0p2.root",
 "/uscms_data/d1/dgsheffi/HCal/corrections/sampling/Tuning/histograms_dEta-0p5_sumEt-100_Et-20_3rdEt-1000_alpha-0p25.root",
 "/uscms_data/d1/dgsheffi/HCal/corrections/sampling/Tuning/histograms_dEta-0p5_sumEt-100_Et-20_3rdEt-1000_alpha-0p3.root",
 "/uscms_data/d1/dgsheffi/HCal/corrections/sampling/Tuning/histograms_dEta-0p5_sumEt-100_Et-20_3rdEt-1000_alpha-0p5.root"};
    double bins_alpha[num_files_alpha+1] = {0.025, 0.075, 0.125, 0.175, 0.225,
					    0.275, 0.325, 0.675};

    TString output = "/uscms_data/d1/dgsheffi/HCal/corrections/sampling/Tuning/tuning_histograms.root";
    TFile *fout = new TFile(output, "RECREATE");

    TDirectory *dir_dEta = fout->mkdir("dEta");
    GetPlots(dir_dEta, num_files_dEta, files_dEta, bins_dEta);

    TDirectory *dir_sumEt = fout->mkdir("sumEt");
    GetPlots(dir_sumEt, num_files_sumEt, files_sumEt, bins_sumEt);

    TDirectory *dir_thirdEt = fout->mkdir("thirdEt");
    GetPlots(dir_thirdEt, num_files_thirdEt, files_thirdEt, bins_thirdEt);

    TDirectory *dir_alpha = fout->mkdir("alpha");
    GetPlots(dir_alpha, num_files_alpha, files_alpha, bins_alpha);


    fout->Close();

    return;
}

void GetPlots(TDirectory *dir, const int num_files, const TString files[100],
	      double bins[101])
{
    // RMS
    TH1D *h_rms_sel_all = new TH1D("h_rms_sel_all", "Improvment",
				   num_files, bins);
    TH1D *h_rms_sel_HB = new TH1D("h_rms_sel_HB", "Improvment",
				  num_files, bins);
    TH1D *h_rms_sel_HE = new TH1D("h_rms_sel_HE", "Improvment",
				  num_files, bins);
    TH1D *h_rms_sel_all_norm = new TH1D("h_rms_sel_all_norm", "Improvment",
					num_files, bins);
    TH1D *h_rms_sel_HB_norm = new TH1D("h_rms_sel_HB_norm", "Improvment",
				       num_files, bins);
    TH1D *h_rms_sel_HE_norm = new TH1D("h_rms_sel_HE_norm", "Improvment",
				       num_files, bins);
    TH1D *h_rms_samp_all = new TH1D("h_rms_samp_all", "Improvment",
				    num_files, bins);
    TH1D *h_rms_samp_HB = new TH1D("h_rms_samp_HB", "Improvment",
				   num_files, bins);
    TH1D *h_rms_samp_HE = new TH1D("h_rms_samp_HE", "Improvment",
				   num_files, bins);
    TH1D *h_rms_samp_all_norm = new TH1D("h_rms_samp_all_norm", "Improvment",
					 num_files, bins);
    TH1D *h_rms_samp_HB_norm = new TH1D("h_rms_samp_HB_norm", "Improvment",
					num_files, bins);
    TH1D *h_rms_samp_HE_norm = new TH1D("h_rms_samp_HE_norm", "Improvment",
					num_files, bins);

    // Gaussian sigma
    TH1D *h_gaus_sel_all = new TH1D("h_gaus_sel_all", "Improvment",
				   num_files, bins);
    TH1D *h_gaus_sel_HB = new TH1D("h_gaus_sel_HB", "Improvment",
				  num_files, bins);
    TH1D *h_gaus_sel_HE = new TH1D("h_gaus_sel_HE", "Improvment",
				  num_files, bins);
    TH1D *h_gaus_sel_all_norm = new TH1D("h_gaus_sel_all_norm", "Improvment",
					num_files, bins);
    TH1D *h_gaus_sel_HB_norm = new TH1D("h_gaus_sel_HB_norm", "Improvment",
				       num_files, bins);
    TH1D *h_gaus_sel_HE_norm = new TH1D("h_gaus_sel_HE_norm", "Improvment",
				       num_files, bins);
    TH1D *h_gaus_samp_all = new TH1D("h_gaus_samp_all", "Improvment",
				    num_files, bins);
    TH1D *h_gaus_samp_HB = new TH1D("h_gaus_samp_HB", "Improvment",
				   num_files, bins);
    TH1D *h_gaus_samp_HE = new TH1D("h_gaus_samp_HE", "Improvment",
				   num_files, bins);
    TH1D *h_gaus_samp_all_norm = new TH1D("h_gaus_samp_all_norm", "Improvment",
					 num_files, bins);
    TH1D *h_gaus_samp_HB_norm = new TH1D("h_gaus_samp_HB_norm", "Improvment",
					num_files, bins);
    TH1D *h_gaus_samp_HE_norm = new TH1D("h_gaus_samp_HE_norm", "Improvment",
					num_files, bins);

    // Effective sigma
    TH1D *h_eff_sel_all = new TH1D("h_eff_sel_all", "Improvment",
				   num_files, bins);
    TH1D *h_eff_sel_HB = new TH1D("h_eff_sel_HB", "Improvment",
				  num_files, bins);
    TH1D *h_eff_sel_HE = new TH1D("h_eff_sel_HE", "Improvment",
				  num_files, bins);
    TH1D *h_eff_sel_all_norm = new TH1D("h_eff_sel_all_norm", "Improvment",
					num_files, bins);
    TH1D *h_eff_sel_HB_norm = new TH1D("h_eff_sel_HB_norm", "Improvment",
				       num_files, bins);
    TH1D *h_eff_sel_HE_norm = new TH1D("h_eff_sel_HE_norm", "Improvment",
				       num_files, bins);
    TH1D *h_eff_samp_all = new TH1D("h_eff_samp_all", "Improvment",
				    num_files, bins);
    TH1D *h_eff_samp_HB = new TH1D("h_eff_samp_HB", "Improvment",
				   num_files, bins);
    TH1D *h_eff_samp_HE = new TH1D("h_eff_samp_HE", "Improvment",
				   num_files, bins);
    TH1D *h_eff_samp_all_norm = new TH1D("h_eff_samp_all_norm", "Improvment",
					 num_files, bins);
    TH1D *h_eff_samp_HB_norm = new TH1D("h_eff_samp_HB_norm", "Improvment",
					num_files, bins);
    TH1D *h_eff_samp_HE_norm = new TH1D("h_eff_samp_HE_norm", "Improvment",
					num_files, bins);

    for (int i=0; i<num_files; ++i){
	if (files[i] == "")
	    continue;

	TFile *file = new TFile(files[i], "READ");
	TTree *tree = 0;
	file->GetObject("resolution_tree", tree);

	double rms_sel_nocorr = 0.0;
	double gaus_sel_nocorr = 0.0;
	double eff_sel_nocorr = 0.0;
	double ave_sel_nocorr = 0.0;
	double rms_sel_respcorr = 0.0;
	double gaus_sel_respcorr = 0.0;
	double eff_sel_respcorr = 0.0;
	double ave_sel_respcorr = 0.0;
	double rms_samp_nocorr = 0.0;
	double gaus_samp_nocorr = 0.0;
	double eff_samp_nocorr = 0.0;
	double ave_samp_nocorr = 0.0;
	double rms_samp_respcorr = 0.0;
	double gaus_samp_respcorr = 0.0;
	double eff_samp_respcorr = 0.0;
	double ave_samp_respcorr = 0.0;

	tree->SetBranchAddress("rms_sel_nocorr", &rms_sel_nocorr);
	tree->SetBranchAddress("gaus_sel_nocorr", &gaus_sel_nocorr);
	tree->SetBranchAddress("eff_sel_nocorr", &eff_sel_nocorr);
	tree->SetBranchAddress("ave_sel_nocorr", &ave_sel_nocorr);
	tree->SetBranchAddress("rms_sel_respcorr", &rms_sel_respcorr);
	tree->SetBranchAddress("gaus_sel_respcorr", &gaus_sel_respcorr);
	tree->SetBranchAddress("eff_sel_respcorr", &eff_sel_respcorr);
	tree->SetBranchAddress("ave_sel_respcorr", &ave_sel_respcorr);
	tree->SetBranchAddress("rms_samp_nocorr", &rms_samp_nocorr);
	tree->SetBranchAddress("gaus_samp_nocorr", &gaus_samp_nocorr);
	tree->SetBranchAddress("eff_samp_nocorr", &eff_samp_nocorr);
	tree->SetBranchAddress("ave_samp_nocorr", &ave_samp_nocorr);
	tree->SetBranchAddress("rms_samp_respcorr", &rms_samp_respcorr);
	tree->SetBranchAddress("gaus_samp_respcorr", &gaus_samp_respcorr);
	tree->SetBranchAddress("eff_samp_respcorr", &eff_samp_respcorr);
	tree->SetBranchAddress("ave_samp_respcorr", &ave_samp_respcorr);

	// All
	tree->GetEntry(0);

	h_rms_sel_all->SetBinContent(i+1, GetImprovement(rms_sel_nocorr,
							 rms_sel_respcorr));
	h_rms_sel_all_norm->SetBinContent(i+1, GetNormImprovement(
					      rms_sel_nocorr, rms_sel_respcorr,
					      ave_sel_nocorr,
					      ave_sel_respcorr));
	h_rms_samp_all->SetBinContent(i+1, GetImprovement(rms_samp_nocorr,
							  rms_samp_respcorr));
	h_rms_samp_all_norm->SetBinContent(i+1, GetNormImprovement(
					       rms_samp_nocorr,
					       rms_samp_respcorr,
					       ave_samp_nocorr,
					       ave_samp_respcorr));
	h_gaus_sel_all->SetBinContent(i+1, GetImprovement(gaus_sel_nocorr,
							  gaus_sel_respcorr));
	h_gaus_sel_all_norm->SetBinContent(i+1, GetNormImprovement(
					       gaus_sel_nocorr,
					       gaus_sel_respcorr,
					       ave_sel_nocorr,
					       ave_sel_respcorr));
	h_gaus_samp_all->SetBinContent(i+1, GetImprovement(gaus_samp_nocorr,
							   gaus_samp_respcorr));
	h_gaus_samp_all_norm->SetBinContent(i+1, GetNormImprovement(
						gaus_samp_nocorr,
						gaus_samp_respcorr,
						ave_samp_nocorr,
						ave_samp_respcorr));
	h_eff_sel_all->SetBinContent(i+1, GetImprovement(eff_sel_nocorr,
							 eff_sel_respcorr));
	h_eff_sel_all_norm->SetBinContent(i+1, GetNormImprovement(
					      eff_sel_nocorr, eff_sel_respcorr,
					      ave_sel_nocorr,
					      ave_sel_respcorr));
	h_eff_samp_all->SetBinContent(i+1, GetImprovement(eff_samp_nocorr,
							  eff_samp_respcorr));
	h_eff_samp_all_norm->SetBinContent(i+1, GetNormImprovement(
					       eff_samp_nocorr,
					       eff_samp_respcorr,
					       ave_samp_nocorr,
					       ave_samp_respcorr));

	// HB
	tree->GetEntry(1);

	h_rms_sel_HB->SetBinContent(i+1, GetImprovement(rms_sel_nocorr,
							rms_sel_respcorr));
	h_rms_sel_HB_norm->SetBinContent(i+1, GetNormImprovement(
					     rms_sel_nocorr, rms_sel_respcorr,
					     ave_sel_nocorr,
					     ave_sel_respcorr));
	h_rms_samp_HB->SetBinContent(i+1, GetImprovement(rms_samp_nocorr,
							 rms_samp_respcorr));
	h_rms_samp_HB_norm->SetBinContent(i+1, GetNormImprovement(
					      rms_samp_nocorr,
					      rms_samp_respcorr,
					      ave_samp_nocorr,
					      ave_samp_respcorr));
	h_gaus_sel_HB->SetBinContent(i+1, GetImprovement(gaus_sel_nocorr,
							 gaus_sel_respcorr));
	h_gaus_sel_HB_norm->SetBinContent(i+1, GetNormImprovement(
					      gaus_sel_nocorr,
					      gaus_sel_respcorr,
					      ave_sel_nocorr,
					      ave_sel_respcorr));
	h_gaus_samp_HB->SetBinContent(i+1, GetImprovement(gaus_samp_nocorr,
							  gaus_samp_respcorr));
	h_gaus_samp_HB_norm->SetBinContent(i+1, GetNormImprovement(
					       gaus_samp_nocorr,
					       gaus_samp_respcorr,
					       ave_samp_nocorr,
					       ave_samp_respcorr));
	h_eff_sel_HB->SetBinContent(i+1, GetImprovement(eff_sel_nocorr,
							eff_sel_respcorr));
	h_eff_sel_HB_norm->SetBinContent(i+1, GetNormImprovement(
					     eff_sel_nocorr, eff_sel_respcorr,
					     ave_sel_nocorr,
					     ave_sel_respcorr));
	h_eff_samp_HB->SetBinContent(i+1, GetImprovement(eff_samp_nocorr,
							 eff_samp_respcorr));
	h_eff_samp_HB_norm->SetBinContent(i+1, GetNormImprovement(
					      eff_samp_nocorr,
					      eff_samp_respcorr,
					      ave_samp_nocorr,
					      ave_samp_respcorr));

	// HE
	tree->GetEntry(2);

	h_rms_sel_HE->SetBinContent(i+1, GetImprovement(rms_sel_nocorr,
							rms_sel_respcorr));
	h_rms_sel_HE_norm->SetBinContent(i+1, GetNormImprovement(
					     rms_sel_nocorr, rms_sel_respcorr,
					     ave_sel_nocorr,
					     ave_sel_respcorr));
	h_rms_samp_HE->SetBinContent(i+1, GetImprovement(rms_samp_nocorr,
							 rms_samp_respcorr));
	h_rms_samp_HE_norm->SetBinContent(i+1, GetNormImprovement(
					      rms_samp_nocorr,
					      rms_samp_respcorr,
					      ave_samp_nocorr,
					      ave_samp_respcorr));
	h_gaus_sel_HE->SetBinContent(i+1, GetImprovement(gaus_sel_nocorr,
							 gaus_sel_respcorr));
	h_gaus_sel_HE_norm->SetBinContent(i+1, GetNormImprovement(
					      gaus_sel_nocorr,
					      gaus_sel_respcorr,
					      ave_sel_nocorr,
					      ave_sel_respcorr));
	h_gaus_samp_HE->SetBinContent(i+1, GetImprovement(gaus_samp_nocorr,
							  gaus_samp_respcorr));
	h_gaus_samp_HE_norm->SetBinContent(i+1, GetNormImprovement(
					       gaus_samp_nocorr,
					       gaus_samp_respcorr,
					       ave_samp_nocorr,
					       ave_samp_respcorr));
	h_eff_sel_HE->SetBinContent(i+1, GetImprovement(eff_sel_nocorr,
							eff_sel_respcorr));
	h_eff_sel_HE_norm->SetBinContent(i+1, GetNormImprovement(
					     eff_sel_nocorr, eff_sel_respcorr,
					     ave_sel_nocorr,
					     ave_sel_respcorr));
	h_eff_samp_HE->SetBinContent(i+1, GetImprovement(eff_samp_nocorr,
							 eff_samp_respcorr));
	h_eff_samp_HE_norm->SetBinContent(i+1, GetNormImprovement(
					      eff_samp_nocorr,
					      eff_samp_respcorr,
					      ave_samp_nocorr,
					      ave_samp_respcorr));

	file->Close();
    }

    dir->cd();
    h_rms_sel_all->Write();
    h_rms_sel_HB->Write();
    h_rms_sel_HE->Write();
    h_rms_sel_all_norm->Write();
    h_rms_sel_HB_norm->Write();
    h_rms_sel_HE_norm->Write();
    h_rms_samp_all->Write();
    h_rms_samp_HB->Write();
    h_rms_samp_HE->Write();
    h_rms_samp_all_norm->Write();
    h_rms_samp_HB_norm->Write();
    h_rms_samp_HE_norm->Write();
    h_gaus_sel_all->Write();
    h_gaus_sel_HB->Write();
    h_gaus_sel_HE->Write();
    h_gaus_sel_all_norm->Write();
    h_gaus_sel_HB_norm->Write();
    h_gaus_sel_HE_norm->Write();
    h_gaus_samp_all->Write();
    h_gaus_samp_HB->Write();
    h_gaus_samp_HE->Write();
    h_gaus_samp_all_norm->Write();
    h_gaus_samp_HB_norm->Write();
    h_gaus_samp_HE_norm->Write();
    h_eff_sel_all->Write();
    h_eff_sel_HB->Write();
    h_eff_sel_HE->Write();
    h_eff_sel_all_norm->Write();
    h_eff_sel_HB_norm->Write();
    h_eff_sel_HE_norm->Write();
    h_eff_samp_all->Write();
    h_eff_samp_HB->Write();
    h_eff_samp_HE->Write();
    h_eff_samp_all_norm->Write();
    h_eff_samp_HB_norm->Write();
    h_eff_samp_HE_norm->Write();

    return;
}

double GetImprovement(const double sigma_nocorr, const double sigma_respcorr)
{
    return 1.0 - sigma_respcorr/sigma_nocorr;
}

double GetNormImprovement(const double sigma_nocorr,
			  const double sigma_respcorr, const double ave_nocorr,
			  const double ave_respcorr)
{
    return 1.0 - sigma_respcorr/sigma_nocorr*ave_nocorr/ave_respcorr;
}
