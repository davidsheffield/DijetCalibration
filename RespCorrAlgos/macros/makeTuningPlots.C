//
// makeTuningPlots.C
//
// author: David G. Sheffield (Rutgers)
//

void makeTuningPlots()
{
    TString input = "/uscms_data/d1/dgsheffi/HCal/corrections/sampling/Tuning/tuning_histograms.root";
    TFile *file = new TFile(input, "READ");

    TH1D *h_rms_sel_all = 0;
    TH1D *h_gaus_sel_all = 0;
    TH1D *h_eff_sel_all = 0;
    file->GetObject("dEta/h_rms_sel_all", h_rms_sel_all);
    file->GetObject("dEta/h_gaus_sel_all", h_gaus_sel_all);
    file->GetObject("dEta/h_eff_sel_all", h_eff_sel_all);

    TCanvas *c1 = new TCanvas("c1", "c1", 800, 600);
    c1->cd();
    gStyle->SetOptStat(0);

    ////////////////////////////////////
    if (h_rms_sel_all->GetMinimum() < h_eff_sel_all->GetMinimum())
	h_eff_sel_all->SetMinimum(h_rms_sel_all->GetMinimum() - 0.05);
    if (h_gaus_sel_all->GetMinimum() < h_eff_sel_all->GetMinimum())
	h_eff_sel_all->SetMinimum(h_gaus_sel_all->GetMinimum() - 0.05);
    if (h_rms_sel_all->GetMaximum() > h_eff_sel_all->GetMaximum())
	h_eff_sel_all->SetMaximum(h_rms_sel_all->GetMaximum() + 0.05);
    if (h_gaus_sel_all->GetMaximum() > h_eff_sel_all->GetMaximum())
	h_eff_sel_all->SetMaximum(h_gaus_sel_all->GetMaximum() + 0.05);

    h_rms_sel_all->SetMarkerStyle(20);
    h_gaus_sel_all->SetMarkerStyle(20);
    h_eff_sel_all->SetMarkerStyle(20);

    h_rms_sel_all->SetMarkerColor(3);
    h_gaus_sel_all->SetMarkerColor(2);
    h_eff_sel_all->SetMarkerColor(1);

    h_eff_sel_all->SetTitle("Selected events: E_{T}^{t} + E_{T}^{p} > 100 GeV, E_{T} > 20 GeV, E_{T}^{3rd} < 15 GeV");
    h_eff_sel_all->GetXaxis()->SetTitle("#Delta|#eta| cut");
    h_eff_sel_all->GetYaxis()->SetTitle("energy resolution improvement");

    h_eff_sel_all->Draw("p");
    h_rms_sel_all->Draw("p same");
    h_gaus_sel_all->Draw("p same");

    if (h_eff_sel_all->GetMinimum() < 0.0) {
	double xlow = h_eff_sel_all->GetXaxis()->GetBinLowEdge(1);
	int xbins = h_eff_sel_all->GetXaxis()->GetNbins();
	double xup = h_eff_sel_all->GetXaxis()->GetBinLowEdge(xbins+1);
	TLine *line = new TLine(xlow, 0.0, xup, 0.0);
	line->SetLineStyle(2);
	line->SetLineColor(12);
	line->Draw();
    }

    TLegend *leg = new TLegend(0.6, 0.15, 0.89, 0.3);
    leg->SetFillColor(0);
    leg->SetLineColor(0);
    leg->AddEntry(h_eff_sel_all,"effective #sigma","p");
    leg->AddEntry(h_gaus_sel_all,"gaussian fit #sigma","p");
    leg->AddEntry(h_rms_sel_all,"RMS","p");
    leg->Draw();

    return;
}
