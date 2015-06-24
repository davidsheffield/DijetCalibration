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
