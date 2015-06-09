#ifndef _DIJETCALIBRATION_RESPCORRALGOS_DIJETRESPCORRDATUM_H_
#define _DIJETCALIBRATION_RESPCORRALGOS_DIJETRESPCORRDATUM_H_

//
// DijetRespCorrDatum.h
//
//    description: Object which contains data relevant to dijet response corrections
//
//

#include "TObject.h"
#include "Rtypes.h"
#include "TArrayD.h"
#include "TFitResult.h"

#include <map>
#include <vector>

//
// forward declarations
//

class TH1D;
class TH2D;

//
// numerical constants
//

const int MAXIETA = 41;
const int NUMTOWERS = 83;

//
// class definitions
//

// container class for a dijet event
// includes the resolution, tag/probe hcal et, and tag/probe ecal et
class DijetRespCorrDatum : public TObject
{
public:
    DijetRespCorrDatum();
    ~DijetRespCorrDatum();

    Double_t GetWeight(void) const;
    Double_t GetTagEta(void) const;
    Double_t GetTagPhi(void) const;
    Double_t GetTagHcalE(Int_t ieta);
    void     GetTagHcalE(std::map<Int_t, Double_t>&) const;
    Double_t GetTagEcalE(void) const;
    Double_t GetTagGenE() const;
    Double_t GetProbeEta(void) const;
    Double_t GetProbePhi(void) const;
    Double_t GetProbeHcalE(Int_t ieta);
    void     GetProbeHcalE(std::map<Int_t, Double_t>&) const;
    Double_t GetProbeEcalE(void) const;
    Double_t GetProbeGenE() const;
    Double_t GetThirdJetPx(void) const;
    Double_t GetThirdJetPy(void) const;
    Int_t    GetCandTrackN(void) const;

    void SetWeight(Double_t);
    void SetTagEta(Double_t);
    void SetTagPhi(Double_t);
    void SetTagHcalE(Double_t, Int_t ieta);
    void AddTagHcalE(Double_t, Int_t ieta);
    void SetTagEcalE(Double_t);
    void SetTagGenE(Double_t);
    void SetProbeEta(Double_t);
    void SetProbePhi(Double_t);
    void SetProbeHcalE(Double_t, Int_t ieta);
    void AddProbeHcalE(Double_t, Int_t ieta);
    void SetProbeEcalE(Double_t);
    void SetProbeGenE(Double_t);
    void SetThirdJetPx(Double_t);
    void SetThirdJetPy(Double_t);
    void SetCandTrackN(Int_t);
    void AddCandTrackP(Double_t);
    void AddCandTrackEcalE(Double_t);
    void AddCandTrackHcalE(std::map<Int_t, Double_t>);

    // calculate the ecal, hcal, and HF energy in the tag and probe jets
    // scale the hcal and hf energy by the response corrections
    void GetTagEnergies(const TArrayD& respcorr, Double_t& ecal, Double_t& hcal,
			Double_t& hf) const;
    void GetProbeEnergies(const TArrayD& respcorr, Double_t& ecal,
			  Double_t& hcal, Double_t& hf) const;
    // Calculate the candidate track momentum, ecal energy, and hcal energy
    // scale the hcal energy by the response corrections
    void GetTrackVariables(const TArrayD& respcorr, const Int_t index_,
			   Double_t& TrackP_, Double_t& EcalE_,
			   Double_t& HcalE_) const;

private:
    // event weight
    Double_t fWeight;

    // tag jet info
    Double_t fTagEta, fTagPhi;
    std::map<Int_t, Double_t> fTagHcalE;
    Double_t fTagEcalE;
    Double_t fTagGenE;

    // probe jet info
    Double_t fProbeEta, fProbePhi;
    std::map<Int_t, Double_t> fProbeHcalE;
    Double_t fProbeEcalE;
    Double_t fProbeGenE;

    // third jet info
    Double_t fThirdJetPx, fThirdJetPy;

    // Track energy comparison info
    Int_t fCandTrackN;
    std::vector<Double_t> fCandTrackP, fCandTrackEcalE;
    std::vector<std::map<Int_t, Double_t> > fCandTrackHcalE;

    ClassDef(DijetRespCorrDatum, 1);
};
#endif
