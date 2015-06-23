#ifndef _DIJETCALIBRATION_RESPCORRALGOS_GETPLOTS_H_
#define _DIJETCALIBRATION_RESPCORRALGOS_GETPLOTS_H_

#include <vector>
#include <iostream>

#include "TFile.h"
#include "TChain.h"
#include "TH1D.h"
#include "TH2D.h"
#include "TMath.h"

#include "DijetCalibration/RespCorrAlgos/interface/DijetRespCorrDatum.h"
#include "DijetCalibration/RespCorrAlgos/interface/DijetRespCorrData.h"
#include "DijetCalibration/RespCorrAlgos/interface/DijetTree.h"
#include "DijetCalibration/RespCorrAlgos/test/Sigma.C"

double getGaussianSigma(TH1D*);

#endif
