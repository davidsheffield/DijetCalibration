#ifndef _DIJETCALIBRATION_RESPCORRALGOS_GETRESPCORR_H_
#define _DIJETCALIBRATION_RESPCORRALGOS_GETRESPCORR_H_

#include <vector>
#include <iostream>

#include "TFile.h"
#include "TChain.h"
#include "TH1D.h"
#include "TH2D.h"
//#include "TSystem.h"
//#include "TROOT.h"
#include "TMath.h"

#include "DijetCalibration/RespCorrAlgos/interface/DijetRespCorrDatum.h"
#include "DijetCalibration/RespCorrAlgos/interface/DijetRespCorrData.h"
#include "DijetCalibration/RespCorrAlgos/interface/DijetTree.h"

double getNeutralPUCorr(double, int, double, bool);
TH1D* LogXTH1D(const char* name, const char* title, Int_t nbinsx, Double_t xlow,
	       Double_t xup);
TH2D* LogXLogYTH2D(const char*, const char*, Int_t, Double_t, Double_t,
		   Int_t, Double_t, Double_t);

#endif
