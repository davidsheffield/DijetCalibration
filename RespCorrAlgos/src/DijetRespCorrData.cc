#include "DijetCalibration/RespCorrAlgos/interface/DijetRespCorrData.h"

#include "TMinuit.h"
#include "TMath.h"
#include "TH1D.h"
#include "TH2D.h"

#include <iostream>
#include <sstream>
#include <cassert>
#include <cmath>

ClassImp(DijetRespCorrData)

DijetRespCorrData::DijetRespCorrData()
{
    fData.clear();
    fPrintLevel=5;
    fParStep=0.10;
    fParMin=0.0;
    fParMax=0.0;
    fEcalRes=0.07;
    fHcalRes=1.15;
    fHfRes=1.35;

    fDoCandTrackEnergyDiff=false;

    h_balance = new TH1D("h_balance", "", 1, 0.0, 1.0);
    h_Eratio_vs_Eta = new TH2D("h_Eratio_vs_Eta", "", 1, 0.0, 1.0, 1, 0.0, 1.0);
    h_balance_term_vs_weight = new TH2D("h_balance_term_vs_weight", "",
					1, 0.0, 1.0, 1, 0.0, 1.0);
    h_Et = new TH1D("h_Et", "", 1, 0.0, 1.0);
    h_Eta = new TH1D("h_Eta", "", 1, 0.0, 1.0);
    h_Phi = new TH1D("h_Phi", "", 1, 0.0, 1.0);
    h_dEta = new TH1D("h_dEta", "", 1, 0.0, 1.0);
    h_dPhi = new TH1D("h_dPhi", "", 1, 0.0, 1.0);
    h_Et2_over_Et1 = new TH1D("h_Et2_over_Et1", "", 1, 0.0, 1.0);
}

DijetRespCorrData::~DijetRespCorrData() {}

void DijetRespCorrData::push_back(const DijetRespCorrDatum& d)
{
    fData.push_back(d);
    return;
}

const DijetRespCorrDatum& DijetRespCorrData::GetAt(Int_t i) const
{
    return fData[i];
}

Int_t DijetRespCorrData::GetSize(void) const
{
    return fData.size();
}

void DijetRespCorrData::SetResolution(Double_t v)
{
    fResolution = v;
    return;
}

void DijetRespCorrData::SetResolution(TH1D* v)
{
    TFitResultPtr balance_fit = v->Fit("gaus","S");
    fResolution = balance_fit->Parameter(2);
    return;
}

Double_t DijetRespCorrData::GetResolution() const
{
    return fResolution;
}

void DijetRespCorrData::SetPlotBalance(const TString name, const TString label,
				       const Int_t nbinsx, const Double_t xlow,
				       const Double_t xup)
{
    delete h_balance;
    h_balance = new TH1D(name, label, nbinsx, xlow, xup);
    return;
}

void DijetRespCorrData::SetPlotEratiovsEta(const TString name,
					   const TString label,
					   const Int_t nbinsx,
					   const Double_t xlow,
					   const Double_t xup,
					   const Int_t nbinsy,
					   const Double_t ylow,
					   const Double_t yup)
{
    delete h_Eratio_vs_Eta;
    h_Eratio_vs_Eta = new TH2D(name, label, nbinsx, xlow, xup,
			       nbinsy, ylow, yup);
    return;
}

void DijetRespCorrData::SetPlotEt(const TString name, const TString label,
				  const Int_t nbinsx, const Double_t xlow,
				  const Double_t xup)
{
    delete h_Et;
    h_Et = new TH1D(name, label, nbinsx, xlow, xup);
    return;
}

void DijetRespCorrData::SetPlotEta(const TString name, const TString label,
				   const Int_t nbinsx, const Double_t xlow,
				   const Double_t xup)
{
    delete h_Eta;
    h_Eta = new TH1D(name, label, nbinsx, xlow, xup);
    return;
}

void DijetRespCorrData::SetPlotPhi(const TString name, const TString label,
				   const Int_t nbinsx, const Double_t xlow,
				   const Double_t xup)
{
    delete h_Phi;
    h_Phi = new TH1D(name, label, nbinsx, xlow, xup);
    return;
}

void DijetRespCorrData::SetPlotDEta(const TString name, const TString label,
				    const Int_t nbinsx, const Double_t xlow,
				    const Double_t xup)
{
    delete h_dEta;
    h_dEta = new TH1D(name, label, nbinsx, xlow, xup);
    return;
}

void DijetRespCorrData::SetPlotDPhi(const TString name, const TString label,
				    const Int_t nbinsx, const Double_t xlow,
				    const Double_t xup)
{
    delete h_dPhi;
    h_dPhi = new TH1D(name, label, nbinsx, xlow, xup);
    return;
}

void DijetRespCorrData::SetPlotEt2overEt1(const TString name,
					  const TString label,
					  const Int_t nbinsx,
					  const Double_t xlow,
					  const Double_t xup)
{
    delete h_Et2_over_Et1;
    h_Et2_over_Et1 = new TH1D(name, label, nbinsx, xlow, xup);
    return;
}

TH1D* DijetRespCorrData::GetPlotBalance()
{
    return static_cast<TH1D*>(h_balance->Clone());
}

TH2D* DijetRespCorrData::GetPlotEratiovsEta()
{
    return static_cast<TH2D*>(h_Eratio_vs_Eta->Clone());
}

TH1D* DijetRespCorrData::GetPlotEt()
{
    return static_cast<TH1D*>(h_Et->Clone());
}

TH1D* DijetRespCorrData::GetPlotEta()
{
    return static_cast<TH1D*>(h_Eta->Clone());
}

TH1D* DijetRespCorrData::GetPlotPhi()
{
    return static_cast<TH1D*>(h_Phi->Clone());
}

TH1D* DijetRespCorrData::GetPlotDEta()
{
    return static_cast<TH1D*>(h_dEta->Clone());
}

TH1D* DijetRespCorrData::GetPlotDPhi()
{
    return static_cast<TH1D*>(h_dPhi->Clone());
}

TH1D* DijetRespCorrData::GetPlotEt2overEt1()
{
    return static_cast<TH1D*>(h_Et2_over_Et1->Clone());
}

void DijetRespCorrData::GetPlots(TH1D *h_respcorr)
{
    Double_t array[NUMTOWERS];
    for(int i=0; i<NUMTOWERS; ++i){
	array[i] = h_respcorr->GetBinContent(i+1);
    }
    TArrayD respcorr;
    respcorr.Set(NUMTOWERS, array);

    h_balance->GetXaxis()->SetTitle("dijet balance");
    h_Eratio_vs_Eta->GetXaxis()->SetTitle("PFJet #eta");
    h_Eratio_vs_Eta->GetYaxis()->SetTitle("E_{reco}/E_{gen}");
    h_balance_term_vs_weight->GetXaxis()->SetTitle("w");
    h_balance_term_vs_weight->GetYaxis()->SetTitle("B^{2}/(#DeltaB)^{2}");

    for (std::vector<DijetRespCorrDatum>::const_iterator it=fData.begin();
	 it!=fData.end(); ++it) {
	h_Eta->Fill(it->GetTagEta(), it->GetWeight());
	h_Eta->Fill(it->GetProbeEta(), it->GetWeight());
	h_Phi->Fill(it->GetTagPhi(), it->GetWeight());
	h_Phi->Fill(it->GetProbePhi(), it->GetWeight());
	h_dEta->Fill(fabs(fabs(it->GetTagEta()) - fabs(it->GetProbeEta())),
		     it->GetWeight());
	double dphi = fabs(it->GetTagPhi() - it->GetProbePhi());
	if (dphi > 3.1415)
	    dphi = 6.2832 - dphi;
	h_dPhi->Fill(dphi, it->GetWeight());

	Double_t te, th, thf;
	Double_t pe, ph, phf;
	it->GetTagEnergies(respcorr, te, th, thf);
	it->GetProbeEnergies(respcorr, pe, ph, phf);

	// calculate the resolution and balance in E_T, not E
	Double_t tet=(te+th+thf)/std::cosh(it->GetTagEta());
	Double_t pet=(pe+ph+phf)/std::cosh(it->GetProbeEta());
	h_Et->Fill(tet, it->GetWeight());
	h_Et->Fill(pet, it->GetWeight());
	if (tet > pet)
	    h_Et2_over_Et1->Fill(pet/tet);
	else
	    h_Et2_over_Et1->Fill(tet/pet);

	// correct the tag/probe E_T's for the "third jet"
	Double_t tpx = tet*std::cos(it->GetTagPhi());
	Double_t tpy = tet*std::sin(it->GetTagPhi());
	Double_t ppx = pet*std::cos(it->GetProbePhi());
	Double_t ppy = pet*std::sin(it->GetProbePhi());

	tpx += 0.5*it->GetThirdJetPx();
	tpy += 0.5*it->GetThirdJetPy();
	ppx += 0.5*it->GetThirdJetPx();
	ppy += 0.5*it->GetThirdJetPy();

	Double_t tetcorr = std::sqrt(tpx*tpx + tpy*tpy);
	Double_t petcorr = std::sqrt(ppx*ppx + ppy*ppy);

	Double_t B = 2.0*(tetcorr - petcorr)/(tetcorr + petcorr);
	h_balance->Fill(B, it->GetWeight());

	Double_t tag_Eratio = (te + th + thf)/it->GetTagGenE();
	Double_t probe_Eratio = (pe + ph + phf)/it->GetProbeGenE();
	h_Eratio_vs_Eta->Fill(it->GetTagEta(), tag_Eratio, it->GetWeight());
	h_Eratio_vs_Eta->Fill(it->GetProbeEta(), probe_Eratio, it->GetWeight());

	h_balance_term_vs_weight->Fill(it->GetWeight(),
				       B*B/(fResolution*fResolution));
    }

    return;
}

Double_t DijetRespCorrData::GetLikelihoodDistance(const TArrayD& respcorr) const
{
    Double_t total=0.0;

    if (GetDoCandTrackEnergyDiff()) {
	// loop over each jet pair
	for (std::vector<DijetRespCorrDatum>::const_iterator it=fData.begin();
	     it!=fData.end(); ++it) {

	    // calculate the balance and resolution for each jet pair
	    Double_t B, dB;
	    GetBalance(*it, respcorr, B, dB);

	    // this is the total likelihood
	    total += 0.5*(std::log(dB*dB)+B*B/dB/dB);
	    for (Int_t iCandTrack=0; iCandTrack<(*it).GetCandTrackN();
		 ++iCandTrack){
		// Calculate the difference in energy between rechits and tracks
		Double_t Ediff, dEdiff;
		GetTrackEnergyDiff(*it, iCandTrack, respcorr, Ediff, dEdiff);
		total += 0.5*(std::log(dEdiff*dEdiff)
			      + Ediff*Ediff/dEdiff/dEdiff);
	    }
	}
    } else {
	// loop over each jet pair
	for (std::vector<DijetRespCorrDatum>::const_iterator it=fData.begin();
	     it!=fData.end(); ++it) {

	    // calculate the balance and resolution for each jet pair
	    Double_t B, dB;
	    GetBalance(*it, respcorr, B, dB);

	    // this is the total likelihood
	    total += 0.5*(std::log(dB*dB)+B*B/dB/dB);
	}
    }
    return total;
}

TH1D* DijetRespCorrData::doFit(const char* name, const char* title)
{
    TArrayD respcorr, respcorre;
    doFit(respcorr, respcorre);
    TH1D* h = new TH1D(name, title, NUMTOWERS, -MAXIETA - 0.5, MAXIETA + 0.5);
    for (int i=1; i<=NUMTOWERS; ++i) {
	h->SetBinContent(i, respcorr[i-1]);
	h->SetBinError(i, respcorre[i-1]);
    }

    return h;
}

void DijetRespCorrData::doFit(TArrayD& respcorr, TArrayD& respcorre)
{
    // setup the initial response corrections
    const int maxIetaFixed = 1;//20;
    Double_t array[NUMTOWERS] = { 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0 };

    TArrayD respCorrInit;
    respCorrInit.Set(NUMTOWERS, array);

    // set the number of parameters to be the number of towers
    TMinuit *gMinuit = new TMinuit(NUMTOWERS);
    gMinuit->SetPrintLevel(fPrintLevel);
    //std::cout << "========================= " << gMinuit->GetMaxIterations() << std::endl;
    //gMinuit->SetMaxIterations(1000);
    gMinuit->SetErrorDef(0.5); // for a log likelihood
    gMinuit->SetFCN(FCN);
    gMinuit->SetObjectFit(this);

    // define the parameters
    for (int i=0; i<respCorrInit.GetSize(); ++i) {
	int ieta = -MAXIETA + i;
	std::ostringstream oss;
	oss << "Tower ieta: " << ieta;
	gMinuit->DefineParameter(i, oss.str().c_str(), respCorrInit[i],
				 fParStep, fParMin, fParMax);
	if(ieta>=-maxIetaFixed && ieta<=maxIetaFixed) gMinuit->FixParameter(i);

	// override the HF
	/*if(ieta<=-30 || ieta>=30) {
	  gMinuit->DefineParameter(i, oss.str().c_str(), 1.0, fParStep, fParMin, fParMax);
	  //gMinuit->DefineParameter(i, oss.str().c_str(), 1.3, fParStep, fParMin, fParMax);
	  gMinuit->FixParameter(i);
	  }*/
    }

    //gMinuit->Command("SET STR 2");

    // Minimize
    gMinuit->Migrad();

    // get the results
    TArrayD results(NUMTOWERS);
    TArrayD errors(NUMTOWERS);
    for (int i=0; i<results.GetSize(); ++i) {
	Double_t val, error;
	gMinuit->GetParameter(i, val, error);
	results[i]=val;
	errors[i]=error;
    }
    respcorr=results;
    respcorre=errors;

    return;
}

void DijetRespCorrData::GetBalance(const DijetRespCorrDatum& datum,
				   const TArrayD& respcorr, Double_t& balance_,
				   Double_t& resolution_) const
{
    Double_t te, th, thf;
    Double_t pe, ph, phf;
    datum.GetTagEnergies(respcorr, te, th, thf);
    datum.GetProbeEnergies(respcorr, pe, ph, phf);

    // calculate the resolution and balance in E_T, not E
    Double_t tet=(te+th+thf)/std::cosh(datum.GetTagEta());
    Double_t pet=(pe+ph+phf)/std::cosh(datum.GetProbeEta());

    // correct the tag/probe E_T's for the "third jet"
    Double_t tpx = tet*std::cos(datum.GetTagPhi());
    Double_t tpy = tet*std::sin(datum.GetTagPhi());
    Double_t ppx = pet*std::cos(datum.GetProbePhi());
    Double_t ppy = pet*std::sin(datum.GetProbePhi());

    tpx += 0.5*datum.GetThirdJetPx();
    tpy += 0.5*datum.GetThirdJetPy();
    ppx += 0.5*datum.GetThirdJetPx();
    ppy += 0.5*datum.GetThirdJetPy();

    Double_t tetcorr = std::sqrt(tpx*tpx + tpy*tpy);
    Double_t petcorr = std::sqrt(ppx*ppx + ppy*ppy);

    balance_ = 2.0*(tetcorr-petcorr)/(tetcorr+petcorr);
    resolution_ = fResolution/sqrt(datum.GetWeight());
    return;
}

void DijetRespCorrData::GetTrackEnergyDiff(const DijetRespCorrDatum& datum,
					   const Int_t index,
					   const TArrayD& respcorr,
					   Double_t& Ediff_,
					   Double_t& dEdiff_) const
{
    Double_t TrackP, EcalE, HcalE;
    datum.GetTrackVariables(respcorr, index, TrackP, EcalE, HcalE);

                   // sqrt(p^2 + m_pion^2)
    Double_t TrackE = sqrt(TrackP*TrackP + 0.019479835145232396);

    Ediff_ = fabs(TrackE - EcalE - HcalE);
    dEdiff_ = 1.0;
    return;
}

void DijetRespCorrData::FCN(Int_t &npar, Double_t*, Double_t &f, Double_t *par,
			    Int_t)
{
    // get the relevant data
    const DijetRespCorrData* data =
	dynamic_cast<const DijetRespCorrData*>(gMinuit->GetObjectFit());
    TArrayD respcorr;
    respcorr.Set(NUMTOWERS, par);
    f = data->GetLikelihoodDistance(respcorr);

    return;
}
