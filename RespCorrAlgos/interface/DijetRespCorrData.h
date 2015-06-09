#ifndef _DIJETCALIBRATION_RESPCORRALGOS_DIJETRESPCORRDATA_H_
#define _DIJETCALIBRATION_RESPCORRALGOS_DIJETRESPCORRDATA_H_

//
// DijetRespCorrData.h
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

#include "DijetCalibration/RespCorrAlgos/interface/DijetRespCorrDatum.h"

//
// forward declarations
//

class TH1D;
class TH2D;

//
// class definitions
//

// vector of DijetRespCorrDatum
// uses ROOT style accessors, since ROOT doesn't like the STD
// provide a fitting tool to determine the response corrections
class DijetRespCorrData : public TObject
{
public:
    DijetRespCorrData();
    ~DijetRespCorrData();

    void push_back(const DijetRespCorrDatum&);
    const DijetRespCorrDatum& GetAt(Int_t) const;
    Int_t GetSize(void) const;

    // calculate the total distance between the tag and probe jets
    // given a set of response corrections
    Double_t GetLikelihoodDistance(const TArrayD& respcorr) const;

    // fit for the response corrections
    //  TArrayD doFit(const TArrayD& respCorrInit, Int_t maxIetaFixed);
    void doFit(TArrayD& respcorr, TArrayD& respcorre); // use default resp corrections
    TH1D* doFit(const char* name, const char* title);  // use default resp corrections

    // fitting parameters
    inline void SetPrintLevel(Int_t p) { fPrintLevel=p; }
    inline void SetParStep(Double_t p) { fParStep=p; }
    inline void SetParMin(Double_t p) { fParMin=p; }
    inline void SetParMax(Double_t p) { fParMax=p; }
    inline void SetEcalRes(Double_t p=0.07) { fEcalRes=p; }
    inline void SetHcalRes(Double_t p=1.15) { fHcalRes=p; }
    inline void SetHfRes(Double_t p=1.35) { fHfRes=p; }

    inline void SetDoCandTrackEnergyDiff(Bool_t p) { fDoCandTrackEnergyDiff=p; }
    inline Bool_t GetDoCandTrackEnergyDiff(void) const
    {
	return fDoCandTrackEnergyDiff;
    }

    void SetResolution(Double_t);
    void SetResolution(TH1D*);
    Double_t GetResolution() const;
    void GetPlots(TH1D*, TH1D*, TH2D*, TH2D*);

private:
    // calculate the balance parameter and its resolution for a given dijet pair
    void GetBalance(const DijetRespCorrDatum& datum, const TArrayD& respcorr,
		    Double_t& balance_, Double_t& resolution_) const;
    // Calculate the difference in energy between the hits and the candidate's track
    //void GetTrackEnergyDiff(const DijetRespCorrDatum& datum, const Int_t& index, const TArrayD& respcorr, Double_t& Ediff_, Double_t& dEdiff_) const;
    void GetTrackEnergyDiff(const DijetRespCorrDatum& datum, const Int_t index,
			    const TArrayD& respcorr, Double_t& Ediff_,
			    Double_t& dEdiff_) const;

    // actual data
    std::vector<DijetRespCorrDatum> fData;

    // this is where the magic happens
    static void FCN(Int_t &npar, Double_t *gin, Double_t &f, Double_t *par, Int_t flag);

    // fit parameters
    Int_t fPrintLevel;
    Double_t fParStep;
    Double_t fParMin;
    Double_t fParMax;
    Double_t fEcalRes, fHcalRes, fHfRes;

    Bool_t fDoCandTrackEnergyDiff;

    Double_t fResolution;

    ClassDef(DijetRespCorrData, 1);
};
#endif
