//
// makeTuningPlots.C
//
// author: David G. Sheffield (Rutgers)
//

void makeCanvases(TH1D*, TH1D*, TH1D*, TString, TString, TString);

void makeTuningPlots()
{
    TString input = "/uscms_data/d1/dgsheffi/HCal/corrections/sampling/Tuning/tuning_histograms.root";
    TFile *file = new TFile(input, "READ");

    TH1D *h_rms = 0;
    TH1D *h_gaus = 0;
    TH1D *h_eff = 0;

    //////////////////////
    // dEta selected
    //////////////////////

    file->GetObject("dEta/h_rms_sel_all", h_rms);
    file->GetObject("dEta/h_gaus_sel_all", h_gaus);
    file->GetObject("dEta/h_eff_sel_all", h_eff);
    makeCanvases(h_rms, h_gaus, h_eff,
		 "Selected events: E_{T}^{t} + E_{T}^{p} > 100 GeV, E_{T} > 20 GeV, E_{T}^{3rd} < 15 GeV",
		 "#Delta|#eta| cut",
		 "tuning_dEta_sumEt-100_Et-20_3rdEt-15_alpha-1000_sel_all");
    file->GetObject("dEta/h_rms_sel_HB", h_rms);
    file->GetObject("dEta/h_gaus_sel_HB", h_gaus);
    file->GetObject("dEta/h_eff_sel_HB", h_eff);
    makeCanvases(h_rms, h_gaus, h_eff,
		 "Selected events in HB: E_{T}^{t} + E_{T}^{p} > 100 GeV, E_{T} > 20 GeV, E_{T}^{3rd} < 15 GeV",
		 "#Delta|#eta| cut",
		 "tuning_dEta_sumEt-100_Et-20_3rdEt-15_alpha-1000_sel_HB");
    file->GetObject("dEta/h_rms_sel_HE", h_rms);
    file->GetObject("dEta/h_gaus_sel_HE", h_gaus);
    file->GetObject("dEta/h_eff_sel_HE", h_eff);
    makeCanvases(h_rms, h_gaus, h_eff,
		 "Selected events in HE: E_{T}^{t} + E_{T}^{p} > 100 GeV, E_{T} > 20 GeV, E_{T}^{3rd} < 15 GeV",
		 "#Delta|#eta| cut",
		 "tuning_dEta_sumEt-100_Et-20_3rdEt-15_alpha-1000_sel_HE");
    file->GetObject("dEta/h_rms_sel_all_norm", h_rms);
    file->GetObject("dEta/h_gaus_sel_all_norm", h_gaus);
    file->GetObject("dEta/h_eff_sel_all_norm", h_eff);
    makeCanvases(h_rms, h_gaus, h_eff,
		 "Selected events, normalized: E_{T}^{t} + E_{T}^{p} > 100 GeV, E_{T} > 20 GeV, E_{T}^{3rd} < 15 GeV",
		 "#Delta|#eta| cut",
		 "tuning_dEta_sumEt-100_Et-20_3rdEt-15_alpha-1000_sel_all_norm");
    file->GetObject("dEta/h_rms_sel_HB_norm", h_rms);
    file->GetObject("dEta/h_gaus_sel_HB_norm", h_gaus);
    file->GetObject("dEta/h_eff_sel_HB_norm", h_eff);
    makeCanvases(h_rms, h_gaus, h_eff,
		 "Selected events in HB, normalized: E_{T}^{t} + E_{T}^{p} > 100 GeV, E_{T} > 20 GeV, E_{T}^{3rd} < 15 GeV",
		 "#Delta|#eta| cut",
		 "tuning_dEta_sumEt-100_Et-20_3rdEt-15_alpha-1000_sel_HB_norm");
    file->GetObject("dEta/h_rms_sel_HE_norm", h_rms);
    file->GetObject("dEta/h_gaus_sel_HE_norm", h_gaus);
    file->GetObject("dEta/h_eff_sel_HE_norm", h_eff);
    makeCanvases(h_rms, h_gaus, h_eff,
		 "Selected events in HE, normalized: E_{T}^{t} + E_{T}^{p} > 100 GeV, E_{T} > 20 GeV, E_{T}^{3rd} < 15 GeV",
		 "#Delta|#eta| cut",
		 "tuning_dEta_sumEt-100_Et-20_3rdEt-15_alpha-1000_sel_HE_norm");

    //////////////////////
    // dEta sampled
    //////////////////////

    file->GetObject("dEta/h_rms_samp_all", h_rms);
    file->GetObject("dEta/h_gaus_samp_all", h_gaus);
    file->GetObject("dEta/h_eff_samp_all", h_eff);
    makeCanvases(h_rms, h_gaus, h_eff,
		 "All sampled events: E_{T}^{t} + E_{T}^{p} > 100 GeV, E_{T} > 20 GeV, E_{T}^{3rd} < 15 GeV",
		 "#Delta|#eta| cut",
		 "tuning_dEta_sumEt-100_Et-20_3rdEt-15_alpha-1000_samp_all");
    file->GetObject("dEta/h_rms_samp_HB", h_rms);
    file->GetObject("dEta/h_gaus_samp_HB", h_gaus);
    file->GetObject("dEta/h_eff_samp_HB", h_eff);
    makeCanvases(h_rms, h_gaus, h_eff,
		 "All sampled events in HB: E_{T}^{t} + E_{T}^{p} > 100 GeV, E_{T} > 20 GeV, E_{T}^{3rd} < 15 GeV",
		 "#Delta|#eta| cut",
		 "tuning_dEta_sumEt-100_Et-20_3rdEt-15_alpha-1000_samp_HB");
    file->GetObject("dEta/h_rms_samp_HE", h_rms);
    file->GetObject("dEta/h_gaus_samp_HE", h_gaus);
    file->GetObject("dEta/h_eff_samp_HE", h_eff);
    makeCanvases(h_rms, h_gaus, h_eff,
		 "All sampled events in HE: E_{T}^{t} + E_{T}^{p} > 100 GeV, E_{T} > 20 GeV, E_{T}^{3rd} < 15 GeV",
		 "#Delta|#eta| cut",
		 "tuning_dEta_sumEt-100_Et-20_3rdEt-15_alpha-1000_samp_HE");
    file->GetObject("dEta/h_rms_samp_all_norm", h_rms);
    file->GetObject("dEta/h_gaus_samp_all_norm", h_gaus);
    file->GetObject("dEta/h_eff_samp_all_norm", h_eff);
    makeCanvases(h_rms, h_gaus, h_eff,
		 "All sampled events, normalized: E_{T}^{t} + E_{T}^{p} > 100 GeV, E_{T} > 20 GeV, E_{T}^{3rd} < 15 GeV",
		 "#Delta|#eta| cut",
		 "tuning_dEta_sumEt-100_Et-20_3rdEt-15_alpha-1000_samp_all_norm");
    file->GetObject("dEta/h_rms_samp_HB_norm", h_rms);
    file->GetObject("dEta/h_gaus_samp_HB_norm", h_gaus);
    file->GetObject("dEta/h_eff_samp_HB_norm", h_eff);
    makeCanvases(h_rms, h_gaus, h_eff,
		 "All sampled events in HB, normalized: E_{T}^{t} + E_{T}^{p} > 100 GeV, E_{T} > 20 GeV, E_{T}^{3rd} < 15 GeV",
		 "#Delta|#eta| cut",
		 "tuning_dEta_sumEt-100_Et-20_3rdEt-15_alpha-1000_samp_HB_norm");
    file->GetObject("dEta/h_rms_samp_HE_norm", h_rms);
    file->GetObject("dEta/h_gaus_samp_HE_norm", h_gaus);
    file->GetObject("dEta/h_eff_samp_HE_norm", h_eff);
    makeCanvases(h_rms, h_gaus, h_eff,
		 "All sampled events in HE, normalized: E_{T}^{t} + E_{T}^{p} > 100 GeV, E_{T} > 20 GeV, E_{T}^{3rd} < 15 GeV",
		 "#Delta|#eta| cut",
		 "tuning_dEta_sumEt-100_Et-20_3rdEt-15_alpha-1000_samp_HE_norm");

    //////////////////////
    // sumEt selected
    //////////////////////

    file->GetObject("sumEt/h_rms_sel_all", h_rms);
    file->GetObject("sumEt/h_gaus_sel_all", h_gaus);
    file->GetObject("sumEt/h_eff_sel_all", h_eff);
    makeCanvases(h_rms, h_gaus, h_eff,
		 "Selected events: #Delta|#eta| < 0.5, E_{T} > 20 GeV, E_{T}^{3rd} < 15 GeV",
		 "E_{T}^{t} + E_{T}^{p} cut [GeV]",
		 "tuning_sumEt_dEta-0p5_Et-20_3rdEt-15_alpha-1000_sel_all");
    file->GetObject("sumEt/h_rms_sel_HB", h_rms);
    file->GetObject("sumEt/h_gaus_sel_HB", h_gaus);
    file->GetObject("sumEt/h_eff_sel_HB", h_eff);
    makeCanvases(h_rms, h_gaus, h_eff,
		 "Selected events in HB: #Delta|#eta| < 0.5, E_{T} > 20 GeV, E_{T}^{3rd} < 15 GeV",
		 "E_{T}^{t} + E_{T}^{p} cut [GeV]",
		 "tuning_sumEt_dEta-0p5_Et-20_3rdEt-15_alpha-1000_sel_HB");
    file->GetObject("sumEt/h_rms_sel_HE", h_rms);
    file->GetObject("sumEt/h_gaus_sel_HE", h_gaus);
    file->GetObject("sumEt/h_eff_sel_HE", h_eff);
    makeCanvases(h_rms, h_gaus, h_eff,
		 "Selected events in HE: #Delta|#eta| < 0.5, E_{T} > 20 GeV, E_{T}^{3rd} < 15 GeV",
		 "E_{T}^{t} + E_{T}^{p} cut [GeV]",
		 "tuning_sumEt_dEta-0p5_Et-20_3rdEt-15_alpha-1000_sel_HE");
    file->GetObject("sumEt/h_rms_sel_all_norm", h_rms);
    file->GetObject("sumEt/h_gaus_sel_all_norm", h_gaus);
    file->GetObject("sumEt/h_eff_sel_all_norm", h_eff);
    makeCanvases(h_rms, h_gaus, h_eff,
		 "Selected events, normalized: #Delta|#eta| < 0.5, E_{T} > 20 GeV, E_{T}^{3rd} < 15 GeV",
		 "E_{T}^{t} + E_{T}^{p} cut [GeV]",
		 "tuning_sumEt_dEta-0p5_Et-20_3rdEt-15_alpha-1000_sel_all_norm");
    file->GetObject("sumEt/h_rms_sel_HB_norm", h_rms);
    file->GetObject("sumEt/h_gaus_sel_HB_norm", h_gaus);
    file->GetObject("sumEt/h_eff_sel_HB_norm", h_eff);
    makeCanvases(h_rms, h_gaus, h_eff,
		 "Selected events in HB, normalized: #Delta|#eta| < 0.5, E_{T} > 20 GeV, E_{T}^{3rd} < 15 GeV",
		 "E_{T}^{t} + E_{T}^{p} cut [GeV]",
		 "tuning_sumEt_dEta-0p5_Et-20_3rdEt-15_alpha-1000_sel_HB_norm");
    file->GetObject("sumEt/h_rms_sel_HE_norm", h_rms);
    file->GetObject("sumEt/h_gaus_sel_HE_norm", h_gaus);
    file->GetObject("sumEt/h_eff_sel_HE_norm", h_eff);
    makeCanvases(h_rms, h_gaus, h_eff,
		 "Selected events in HE, normalized: #Delta|#eta| < 0.5, E_{T} > 20 GeV, E_{T}^{3rd} < 15 GeV",
		 "E_{T}^{t} + E_{T}^{p} cut [GeV]",
		 "tuning_sumEt_dEta-0p5_Et-20_3rdEt-15_alpha-1000_sel_HE_norm");

    //////////////////////
    // sumEt sampled
    //////////////////////

    file->GetObject("sumEt/h_rms_samp_all", h_rms);
    file->GetObject("sumEt/h_gaus_samp_all", h_gaus);
    file->GetObject("sumEt/h_eff_samp_all", h_eff);
    makeCanvases(h_rms, h_gaus, h_eff,
		 "All sampled events: #Delta|#eta| < 0.5, E_{T} > 20 GeV, E_{T}^{3rd} < 15 GeV",
		 "E_{T}^{t} + E_{T}^{p} cut [GeV]",
		 "tuning_sumEt_dEta-0p5_Et-20_3rdEt-15_alpha-1000_samp_all");
    file->GetObject("sumEt/h_rms_samp_HB", h_rms);
    file->GetObject("sumEt/h_gaus_samp_HB", h_gaus);
    file->GetObject("sumEt/h_eff_samp_HB", h_eff);
    makeCanvases(h_rms, h_gaus, h_eff,
		 "All sampled events in HB: #Delta|#eta| < 0.5, E_{T} > 20 GeV, E_{T}^{3rd} < 15 GeV",
		 "E_{T}^{t} + E_{T}^{p} cut [GeV]",
		 "tuning_sumEt_dEta-0p5_Et-20_3rdEt-15_alpha-1000_samp_HB");
    file->GetObject("sumEt/h_rms_samp_HE", h_rms);
    file->GetObject("sumEt/h_gaus_samp_HE", h_gaus);
    file->GetObject("sumEt/h_eff_samp_HE", h_eff);
    makeCanvases(h_rms, h_gaus, h_eff,
		 "All sampled events in HE: #Delta|#eta| < 0.5, E_{T} > 20 GeV, E_{T}^{3rd} < 15 GeV",
		 "E_{T}^{t} + E_{T}^{p} cut [GeV]",
		 "tuning_sumEt_dEta-0p5_Et-20_3rdEt-15_alpha-1000_samp_HE");
    file->GetObject("sumEt/h_rms_samp_all_norm", h_rms);
    file->GetObject("sumEt/h_gaus_samp_all_norm", h_gaus);
    file->GetObject("sumEt/h_eff_samp_all_norm", h_eff);
    makeCanvases(h_rms, h_gaus, h_eff,
		 "All sampled events, normalized: #Delta|#eta| < 0.5, E_{T} > 20 GeV, E_{T}^{3rd} < 15 GeV",
		 "E_{T}^{t} + E_{T}^{p} cut [GeV]",
		 "tuning_sumEt_dEta-0p5_Et-20_3rdEt-15_alpha-1000_samp_all_norm");
    file->GetObject("sumEt/h_rms_samp_HB_norm", h_rms);
    file->GetObject("sumEt/h_gaus_samp_HB_norm", h_gaus);
    file->GetObject("sumEt/h_eff_samp_HB_norm", h_eff);
    makeCanvases(h_rms, h_gaus, h_eff,
		 "All sampled events in HB, normalized: #Delta|#eta| < 0.5, E_{T} > 20 GeV, E_{T}^{3rd} < 15 GeV",
		 "E_{T}^{t} + E_{T}^{p} cut [GeV]",
		 "tuning_sumEt_dEta-0p5_Et-20_3rdEt-15_alpha-1000_samp_HB_norm");
    file->GetObject("sumEt/h_rms_samp_HE_norm", h_rms);
    file->GetObject("sumEt/h_gaus_samp_HE_norm", h_gaus);
    file->GetObject("sumEt/h_eff_samp_HE_norm", h_eff);
    makeCanvases(h_rms, h_gaus, h_eff,
		 "All sampled events in HE, normalized: #Delta|#eta| < 0.5, E_{T} > 20 GeV, E_{T}^{3rd} < 15 GeV",
		 "E_{T}^{t} + E_{T}^{p} cut [GeV]",
		 "tuning_sumEt_dEta-0p5_Et-20_3rdEt-15_alpha-1000_samp_HE_norm");

    //////////////////////
    // 3rdEt selected
    //////////////////////

    file->GetObject("thirdEt/h_rms_sel_all", h_rms);
    file->GetObject("thirdEt/h_gaus_sel_all", h_gaus);
    file->GetObject("thirdEt/h_eff_sel_all", h_eff);
    makeCanvases(h_rms, h_gaus, h_eff,
		 "Selected events: #Delta|#eta| < 0.5, E_{T}^{t} + E_{T}^{p} > 100 GeV, E_{T} > 20 GeV",
		 "E_{T}^{3rd} cut [GeV]",
		 "tuning_3rdEt_dEta-0p5_sumEt-100_Et-20_alpha-1000_sel_all");
    file->GetObject("thirdEt/h_rms_sel_HB", h_rms);
    file->GetObject("thirdEt/h_gaus_sel_HB", h_gaus);
    file->GetObject("thirdEt/h_eff_sel_HB", h_eff);
    makeCanvases(h_rms, h_gaus, h_eff,
		 "Selected events in HB: #Delta|#eta| < 0.5, E_{T}^{t} + E_{T}^{p} > 100 GeV, E_{T} > 20 GeV",
		 "E_{T}^{3rd} cut [GeV]",
		 "tuning_3rdEt_dEta-0p5_sumEt-100_Et-20_alpha-1000_sel_HB");
    file->GetObject("thirdEt/h_rms_sel_HE", h_rms);
    file->GetObject("thirdEt/h_gaus_sel_HE", h_gaus);
    file->GetObject("thirdEt/h_eff_sel_HE", h_eff);
    makeCanvases(h_rms, h_gaus, h_eff,
		 "Selected events in HE: #Delta|#eta| < 0.5, E_{T}^{t} + E_{T}^{p} > 100 GeV, E_{T} > 20 GeV",
		 "E_{T}^{3rd} cut [GeV]",
		 "tuning_3rdEt_dEta-0p5_sumEt-100_Et-20_alpha-1000_sel_HE");
    file->GetObject("thirdEt/h_rms_sel_all_norm", h_rms);
    file->GetObject("thirdEt/h_gaus_sel_all_norm", h_gaus);
    file->GetObject("thirdEt/h_eff_sel_all_norm", h_eff);
    makeCanvases(h_rms, h_gaus, h_eff,
		 "Selected events, normalized: #Delta|#eta| < 0.5, E_{T}^{t} + E_{T}^{p} > 100 GeV, E_{T} > 20 GeV",
		 "E_{T}^{3rd} cut [GeV]",
		 "tuning_3rdEt_dEta-0p5_sumEt-100_Et-20_alpha-1000_sel_all_norm");
    file->GetObject("thirdEt/h_rms_sel_HB_norm", h_rms);
    file->GetObject("thirdEt/h_gaus_sel_HB_norm", h_gaus);
    file->GetObject("thirdEt/h_eff_sel_HB_norm", h_eff);
    makeCanvases(h_rms, h_gaus, h_eff,
		 "Selected events in HB, normalized: #Delta|#eta| < 0.5, E_{T}^{t} + E_{T}^{p} > 100 GeV, E_{T} > 20 GeV",
		 "E_{T}^{3rd} cut [GeV]",
		 "tuning_3rdEt_dEta-0p5_sumEt-100_Et-20_alpha-1000_sel_HB_norm");
    file->GetObject("thirdEt/h_rms_sel_HE_norm", h_rms);
    file->GetObject("thirdEt/h_gaus_sel_HE_norm", h_gaus);
    file->GetObject("thirdEt/h_eff_sel_HE_norm", h_eff);
    makeCanvases(h_rms, h_gaus, h_eff,
		 "Selected events in HE, normalized: #Delta|#eta| < 0.5, E_{T}^{t} + E_{T}^{p} > 100 GeV, E_{T} > 20 GeV",
		 "E_{T}^{3rd} cut [GeV]",
		 "tuning_3rdEt_dEta-0p5_sumEt-100_Et-20_alpha-1000_sel_HE_norm");

    //////////////////////
    // 3rdEt sampled
    //////////////////////

    file->GetObject("thirdEt/h_rms_samp_all", h_rms);
    file->GetObject("thirdEt/h_gaus_samp_all", h_gaus);
    file->GetObject("thirdEt/h_eff_samp_all", h_eff);
    makeCanvases(h_rms, h_gaus, h_eff,
		 "All sampled events: #Delta|#eta| < 0.5, E_{T}^{t} + E_{T}^{p} > 100 GeV, E_{T} > 20 GeV",
		 "E_{T}^{3rd} cut [GeV]",
		 "tuning_3rdEt_dEta-0p5_sumEt-100_Et-20_alpha-1000_samp_all");
    file->GetObject("thirdEt/h_rms_samp_HB", h_rms);
    file->GetObject("thirdEt/h_gaus_samp_HB", h_gaus);
    file->GetObject("thirdEt/h_eff_samp_HB", h_eff);
    makeCanvases(h_rms, h_gaus, h_eff,
		 "All sampled events in HB: #Delta|#eta| < 0.5, E_{T}^{t} + E_{T}^{p} > 100 GeV, E_{T} > 20 GeV",
		 "E_{T}^{3rd} cut [GeV]",
		 "tuning_3rdEt_dEta-0p5_sumEt-100_Et-20_alpha-1000_samp_HB");
    file->GetObject("thirdEt/h_rms_samp_HE", h_rms);
    file->GetObject("thirdEt/h_gaus_samp_HE", h_gaus);
    file->GetObject("thirdEt/h_eff_samp_HE", h_eff);
    makeCanvases(h_rms, h_gaus, h_eff,
		 "All sampled events in HE: #Delta|#eta| < 0.5, E_{T}^{t} + E_{T}^{p} > 100 GeV, E_{T} > 20 GeV",
		 "E_{T}^{3rd} cut [GeV]",
		 "tuning_3rdEt_dEta-0p5_sumEt-100_Et-20_alpha-1000_samp_HE");
    file->GetObject("thirdEt/h_rms_samp_all_norm", h_rms);
    file->GetObject("thirdEt/h_gaus_samp_all_norm", h_gaus);
    file->GetObject("thirdEt/h_eff_samp_all_norm", h_eff);
    makeCanvases(h_rms, h_gaus, h_eff,
		 "All sampled events, normalized: #Delta|#eta| < 0.5, E_{T}^{t} + E_{T}^{p} > 100 GeV, E_{T} > 20 GeV",
		 "E_{T}^{3rd} cut [GeV]",
		 "tuning_3rdEt_dEta-0p5_sumEt-100_Et-20_alpha-1000_samp_all_norm");
    file->GetObject("thirdEt/h_rms_samp_HB_norm", h_rms);
    file->GetObject("thirdEt/h_gaus_samp_HB_norm", h_gaus);
    file->GetObject("thirdEt/h_eff_samp_HB_norm", h_eff);
    makeCanvases(h_rms, h_gaus, h_eff,
		 "All sampled events in HB, normalized: #Delta|#eta| < 0.5, E_{T}^{t} + E_{T}^{p} > 100 GeV, E_{T} > 20 GeV",
		 "E_{T}^{3rd} cut [GeV]",
		 "tuning_3rdEt_dEta-0p5_sumEt-100_Et-20_alpha-1000_samp_HB_norm");
    file->GetObject("thirdEt/h_rms_samp_HE_norm", h_rms);
    file->GetObject("thirdEt/h_gaus_samp_HE_norm", h_gaus);
    file->GetObject("thirdEt/h_eff_samp_HE_norm", h_eff);
    makeCanvases(h_rms, h_gaus, h_eff,
		 "All sampled events in HE, normalized: #Delta|#eta| < 0.5, E_{T}^{t} + E_{T}^{p} > 100 GeV, E_{T} > 20 GeV",
		 "E_{T}^{3rd} cut [GeV]",
		 "tuning_3rdEt_dEta-0p5_sumEt-100_Et-20_alpha-1000_samp_HE_norm");

    //////////////////////
    // alpha selected
    //////////////////////

    file->GetObject("alpha/h_rms_sel_all", h_rms);
    file->GetObject("alpha/h_gaus_sel_all", h_gaus);
    file->GetObject("alpha/h_eff_sel_all", h_eff);
    makeCanvases(h_rms, h_gaus, h_eff,
		 "Selected events: #Delta|#eta| < 0.5, E_{T}^{t} + E_{T}^{p} > 100 GeV, E_{T} > 20 GeV",
		 "#alpha cut",
		 "tuning_alpha_dEta-0p5_sumEt-100_Et-20_3rdEt-15_sel_all");
    file->GetObject("alpha/h_rms_sel_HB", h_rms);
    file->GetObject("alpha/h_gaus_sel_HB", h_gaus);
    file->GetObject("alpha/h_eff_sel_HB", h_eff);
    makeCanvases(h_rms, h_gaus, h_eff,
		 "Selected events in HB: #Delta|#eta| < 0.5, E_{T}^{t} + E_{T}^{p} > 100 GeV, E_{T} > 20 GeV",
		 "#alpha cut",
		 "tuning_alpha_dEta-0p5_sumEt-100_Et-20_3rdEt-15_sel_HB");
    file->GetObject("alpha/h_rms_sel_HE", h_rms);
    file->GetObject("alpha/h_gaus_sel_HE", h_gaus);
    file->GetObject("alpha/h_eff_sel_HE", h_eff);
    makeCanvases(h_rms, h_gaus, h_eff,
		 "Selected events in HE: #Delta|#eta| < 0.5, E_{T}^{t} + E_{T}^{p} > 100 GeV, E_{T} > 20 GeV",
		 "#alpha cut",
		 "tuning_alpha_dEta-0p5_sumEt-100_Et-20_3rdEt-15_sel_HE");
    file->GetObject("alpha/h_rms_sel_all_norm", h_rms);
    file->GetObject("alpha/h_gaus_sel_all_norm", h_gaus);
    file->GetObject("alpha/h_eff_sel_all_norm", h_eff);
    makeCanvases(h_rms, h_gaus, h_eff,
		 "Selected events, normalized: #Delta|#eta| < 0.5, E_{T}^{t} + E_{T}^{p} > 100 GeV, E_{T} > 20 GeV",
		 "#alpha cut",
		 "tuning_alpha_dEta-0p5_sumEt-100_Et-20_3rdEt-15_sel_all_norm");
    file->GetObject("alpha/h_rms_sel_HB_norm", h_rms);
    file->GetObject("alpha/h_gaus_sel_HB_norm", h_gaus);
    file->GetObject("alpha/h_eff_sel_HB_norm", h_eff);
    makeCanvases(h_rms, h_gaus, h_eff,
		 "Selected events in HB, normalized: #Delta|#eta| < 0.5, E_{T}^{t} + E_{T}^{p} > 100 GeV, E_{T} > 20 GeV",
		 "#alpha cut",
		 "tuning_alpha_dEta-0p5_sumEt-100_Et-20_3rdEt-15_sel_HB_norm");
    file->GetObject("alpha/h_rms_sel_HE_norm", h_rms);
    file->GetObject("alpha/h_gaus_sel_HE_norm", h_gaus);
    file->GetObject("alpha/h_eff_sel_HE_norm", h_eff);
    makeCanvases(h_rms, h_gaus, h_eff,
		 "Selected events in HE, normalized: #Delta|#eta| < 0.5, E_{T}^{t} + E_{T}^{p} > 100 GeV, E_{T} > 20 GeV",
		 "#alpha cut",
		 "tuning_alpha_dEta-0p5_sumEt-100_Et-20_3rdEt-15_sel_HE_norm");

    //////////////////////
    // alpha sampled
    //////////////////////

    file->GetObject("alpha/h_rms_samp_all", h_rms);
    file->GetObject("alpha/h_gaus_samp_all", h_gaus);
    file->GetObject("alpha/h_eff_samp_all", h_eff);
    makeCanvases(h_rms, h_gaus, h_eff,
		 "All sampled events: #Delta|#eta| < 0.5, E_{T}^{t} + E_{T}^{p} > 100 GeV, E_{T} > 20 GeV",
		 "#alpha cut",
		 "tuning_alpha_dEta-0p5_sumEt-100_Et-20_3rdEt-15_samp_all");
    file->GetObject("alpha/h_rms_samp_HB", h_rms);
    file->GetObject("alpha/h_gaus_samp_HB", h_gaus);
    file->GetObject("alpha/h_eff_samp_HB", h_eff);
    makeCanvases(h_rms, h_gaus, h_eff,
		 "All sampled events in HB: #Delta|#eta| < 0.5, E_{T}^{t} + E_{T}^{p} > 100 GeV, E_{T} > 20 GeV",
		 "#alpha cut",
		 "tuning_alpha_dEta-0p5_sumEt-100_Et-20_3rdEt-15_samp_HB");
    file->GetObject("alpha/h_rms_samp_HE", h_rms);
    file->GetObject("alpha/h_gaus_samp_HE", h_gaus);
    file->GetObject("alpha/h_eff_samp_HE", h_eff);
    makeCanvases(h_rms, h_gaus, h_eff,
		 "All sampled events in HE: #Delta|#eta| < 0.5, E_{T}^{t} + E_{T}^{p} > 100 GeV, E_{T} > 20 GeV",
		 "#alpha cut",
		 "tuning_alpha_dEta-0p5_sumEt-100_Et-20_3rdEt-15_samp_HE");
    file->GetObject("alpha/h_rms_samp_all_norm", h_rms);
    file->GetObject("alpha/h_gaus_samp_all_norm", h_gaus);
    file->GetObject("alpha/h_eff_samp_all_norm", h_eff);
    makeCanvases(h_rms, h_gaus, h_eff,
		 "All sampled events, normalized: #Delta|#eta| < 0.5, E_{T}^{t} + E_{T}^{p} > 100 GeV, E_{T} > 20 GeV",
		 "#alpha cut",
		 "tuning_alpha_dEta-0p5_sumEt-100_Et-20_3rdEt-15_samp_all_norm");
    file->GetObject("alpha/h_rms_samp_HB_norm", h_rms);
    file->GetObject("alpha/h_gaus_samp_HB_norm", h_gaus);
    file->GetObject("alpha/h_eff_samp_HB_norm", h_eff);
    makeCanvases(h_rms, h_gaus, h_eff,
		 "All sampled events in HB, normalized: #Delta|#eta| < 0.5, E_{T}^{t} + E_{T}^{p} > 100 GeV, E_{T} > 20 GeV",
		 "#alpha cut",
		 "tuning_alpha_dEta-0p5_sumEt-100_Et-20_3rdEt-15_samp_HB_norm");
    file->GetObject("alpha/h_rms_samp_HE_norm", h_rms);
    file->GetObject("alpha/h_gaus_samp_HE_norm", h_gaus);
    file->GetObject("alpha/h_eff_samp_HE_norm", h_eff);
    makeCanvases(h_rms, h_gaus, h_eff,
		 "All sampled events in HE, normalized: #Delta|#eta| < 0.5, E_{T}^{t} + E_{T}^{p} > 100 GeV, E_{T} > 20 GeV",
		 "#alpha cut",
		 "tuning_alpha_dEta-0p5_sumEt-100_Et-20_3rdEt-15_samp_HE_norm");

    return;
}

void makeCanvases(TH1D *h_eff, TH1D *h_gaus, TH1D *h_rms, TString title,
		  TString x_label, TString out_name)
{
    TCanvas *c1 = new TCanvas("c1", "c1", 800, 600);
    c1->cd();
    gStyle->SetOptStat(0);

    if (h_rms->GetMinimum() < h_eff->GetMinimum())
	h_eff->SetMinimum(h_rms->GetMinimum() - 0.05);
    if (h_gaus->GetMinimum() < h_eff->GetMinimum())
	h_eff->SetMinimum(h_gaus->GetMinimum() - 0.05);
    if (h_rms->GetMaximum() > h_eff->GetMaximum())
	h_eff->SetMaximum(h_rms->GetMaximum() + 0.05);
    if (h_gaus->GetMaximum() > h_eff->GetMaximum())
	h_eff->SetMaximum(h_gaus->GetMaximum() + 0.05);

    h_rms->SetMarkerStyle(20);
    h_gaus->SetMarkerStyle(20);
    h_eff->SetMarkerStyle(20);

    h_rms->SetMarkerColor(3);
    h_gaus->SetMarkerColor(2);
    h_eff->SetMarkerColor(1);

    h_eff->SetTitle(title);
    h_eff->GetXaxis()->SetTitle(x_label);
    h_eff->GetYaxis()->SetTitle("energy resolution improvement");

    h_eff->Draw("p");
    h_rms->Draw("p same");
    h_gaus->Draw("p same");

    if (h_eff->GetMinimum() < 0.0 && h_eff->GetMaximum() > 0.0) {
	double xlow = h_eff->GetXaxis()->GetBinLowEdge(1);
	int xbins = h_eff->GetXaxis()->GetNbins();
	double xup = h_eff->GetXaxis()->GetBinLowEdge(xbins+1);
	TLine *line = new TLine(xlow, 0.0, xup, 0.0);
	line->SetLineStyle(2);
	line->SetLineColor(12);
	line->Draw();
    }

    TLegend *leg = new TLegend(0.6, 0.15, 0.89, 0.3);
    leg->SetFillColor(0);
    leg->SetLineColor(0);
    leg->AddEntry(h_eff,"effective #sigma","p");
    leg->AddEntry(h_gaus,"gaussian fit #sigma","p");
    leg->AddEntry(h_rms,"RMS","p");
    leg->Draw();

    c1->SaveAs("/uscms_data/d1/dgsheffi/HCal/corrections/sampling/Tuning/plots/"
	       + out_name + ".pdf");

    delete c1;
    return;
}
