#include "DijetCalibration/RespCorrAlgos/interface/DijetRespCorrDatum.h"

#include "TMinuit.h"
#include "TMath.h"
#include "TH1D.h"
#include "TH2D.h"

#include <iostream>
#include <sstream>
#include <cassert>
#include <cmath>

#ifndef _DIJETCALIBRATION_RESPCORRALGOS_DIJETRESPCORRDATUM_CC_
#define _DIJETCALIBRATION_RESPCORRALGOS_DIJETRESPCORRDATUM_CC_
ClassImp(DijetRespCorrDatum)
#endif

DijetRespCorrDatum::DijetRespCorrDatum() {
    fTagEta=fProbeEta=fTagEcalE=fProbeEcalE=0.0;
}

DijetRespCorrDatum::~DijetRespCorrDatum() {}

Double_t DijetRespCorrDatum::GetWeight(void) const
{
    return fWeight;
}

Double_t DijetRespCorrDatum::GetTagEta(void) const
{
    return fTagEta;
}

Double_t DijetRespCorrDatum::GetTagPhi(void) const
{
    return fTagPhi;
}

Double_t DijetRespCorrDatum::GetTagHcalE(Int_t ieta)
{
    Double_t v=fTagHcalE[ieta];
    return v;
}

void DijetRespCorrDatum::GetTagHcalE(std::map<Int_t, Double_t>& m) const
{
    m=fTagHcalE;
    return;
}

Double_t DijetRespCorrDatum::GetTagEcalE(void) const
{
    return fTagEcalE;
}

Double_t DijetRespCorrDatum::GetTagGenE() const
{
    return fTagGenE;
}

Double_t DijetRespCorrDatum::GetProbeEta(void) const
{
    return fProbeEta;
}

Double_t DijetRespCorrDatum::GetProbePhi(void) const
{
    return fProbePhi;
}

Double_t DijetRespCorrDatum::GetProbeHcalE(Int_t ieta)
{
    Double_t v=fProbeHcalE[ieta];
    return v;
}

void DijetRespCorrDatum::GetProbeHcalE(std::map<Int_t, Double_t>& m) const
{
    m=fProbeHcalE;
    return;
}

Double_t DijetRespCorrDatum::GetProbeEcalE(void) const
{
    return fProbeEcalE;
}

Double_t DijetRespCorrDatum::GetProbeGenE() const
{
    return fProbeGenE;
}

Double_t DijetRespCorrDatum::GetThirdJetPx(void) const
{
    return fThirdJetPx;
}

Double_t DijetRespCorrDatum::GetThirdJetPy(void) const
{
    return fThirdJetPy;
}

Int_t DijetRespCorrDatum::GetCandTrackN(void) const
{
    return fCandTrackN;
}

void DijetRespCorrDatum::SetWeight(Double_t v)
{
    fWeight = v;
    return;
}

void DijetRespCorrDatum::SetTagEta(Double_t v)
{
    fTagEta = v;
    return;
}

void DijetRespCorrDatum::SetTagPhi(Double_t v)
{
    fTagPhi = v;
    return;
}

void DijetRespCorrDatum::SetTagHcalE(Double_t v, Int_t ieta)
{
    assert(ieta <= MAXIETA && ieta >= -MAXIETA && ieta != 0);
    fTagHcalE[ieta] = v;
    return;
}

void DijetRespCorrDatum::AddTagHcalE(Double_t v, Int_t ieta)
{
    assert(ieta <= MAXIETA && ieta >= -MAXIETA && ieta != 0);
    fTagHcalE[ieta] += v;
    return;
}

void DijetRespCorrDatum::SetTagEcalE(Double_t v)
{
    fTagEcalE = v;
    return;
}

void DijetRespCorrDatum::SetTagGenE(Double_t v)
{
    fTagGenE = v;
    return;
}

void DijetRespCorrDatum::SetProbeEta(Double_t v)
{
    fProbeEta = v;
    return;
}

void DijetRespCorrDatum::SetProbePhi(Double_t v)
{
    fProbePhi = v;
    return;
}

void DijetRespCorrDatum::SetProbeHcalE(Double_t v, Int_t ieta)
{
    assert(ieta <= MAXIETA && ieta >= -MAXIETA && ieta != 0);
    fProbeHcalE[ieta] = v;
    return;
}

void DijetRespCorrDatum::AddProbeHcalE(Double_t v, Int_t ieta)
{
    assert(ieta <= MAXIETA && ieta >= -MAXIETA && ieta != 0);
    fProbeHcalE[ieta] += v;
    return;
}

void DijetRespCorrDatum::SetProbeEcalE(Double_t v)
{
    fProbeEcalE = v;
    return;
}

void DijetRespCorrDatum::SetProbeGenE(Double_t v)
{
    fProbeGenE = v;
    return;
}

void DijetRespCorrDatum::SetThirdJetPx(Double_t v)
{
    fThirdJetPx = v;
    return;
}

void DijetRespCorrDatum::SetThirdJetPy(Double_t v)
{
    fThirdJetPy = v;
    return;
}

void DijetRespCorrDatum::SetCandTrackN(Int_t v)
{
    fCandTrackN = v;
    return;
}

void DijetRespCorrDatum::AddCandTrackP(Double_t v)
{
    fCandTrackP.push_back(v);
    return;
}

void DijetRespCorrDatum::AddCandTrackEcalE(Double_t v)
{
    fCandTrackEcalE.push_back(v);
    return;
}

void DijetRespCorrDatum::AddCandTrackHcalE(std::map<Int_t, Double_t> v)
{
  fCandTrackHcalE.push_back(v);
  return;
}

void DijetRespCorrDatum::GetTagEnergies(const TArrayD& respcorr, Double_t& ecal,
					Double_t& hcal, Double_t& hf) const
{
    ecal=GetTagEcalE();
    hcal=0.0;
    hf=0.0;

    std::map<Int_t,Double_t> tagmap;
    GetTagHcalE(tagmap);
    for (std::map<Int_t, Double_t>::const_iterator mapit=tagmap.begin();
	 mapit!=tagmap.end(); ++mapit) {
	int ieta = mapit->first;
	double energy = mapit->second;
	int index = ieta + MAXIETA;
	if (std::abs(ieta) > 29)
	    hf += respcorr[index]*energy;
	else
	    hcal += respcorr[index]*energy;
    }
    return;
}

void DijetRespCorrDatum::GetProbeEnergies(const TArrayD& respcorr,
					  Double_t& ecal, Double_t& hcal,
					  Double_t& hf) const
{
    // calculate the ecal, hcal, and HF energy
    // scale the hcal and hf energy by the response corrections
    ecal = GetProbeEcalE();
    hcal = 0.0;
    hf = 0.0;

    std::map<Int_t,Double_t> probemap;
    GetProbeHcalE(probemap);
    for (std::map<Int_t, Double_t>::const_iterator mapit=probemap.begin();
	 mapit!=probemap.end(); ++mapit) {
	int ieta = mapit->first;
	double energy = mapit->second;
	int index = ieta + MAXIETA;
	if(std::abs(ieta) > 29)
	    hf += respcorr[index]*energy;
	else
	    hcal += respcorr[index]*energy;
    }
    return;
}

void DijetRespCorrDatum::GetTrackVariables(const TArrayD& respcorr,
					   const Int_t index_,
					   Double_t& TrackP_, Double_t& EcalE_,
					   Double_t& HcalE_) const
{
    TrackP_ = fCandTrackP[index_];
    EcalE_ = fCandTrackEcalE[index_];

    std::map<Int_t,Double_t> candmap = fCandTrackHcalE[index_];
    for (std::map<Int_t, Double_t>::const_iterator mapit=candmap.begin();
	 mapit!=candmap.end(); ++mapit) {
	int ieta=mapit->first;
	double energy=mapit->second;
	int index=ieta+MAXIETA;
	HcalE_ += respcorr[index]*energy;
    }
    return;
}
