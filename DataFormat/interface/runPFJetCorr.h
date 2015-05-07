#ifndef _HCALCLOSURETEST_DATAFORMAT_RUNPFJETCORR_H_
#define _HCALCLOSURETEST_DATAFORMAT_RUNPFJETCORR_H_

#include <vector>
#include <iostream>

#include "TFile.h"
#include "TChain.h"
#include "TH1D.h"
#include "TH2D.h"
//#include "TSystem.h"
//#include "TROOT.h"
#include "TMath.h"

#include "HcalClosureTest/DataFormat/src/DijetRespCorrData.cc"

double getNeutralPUCorr(double, int, double, bool);
TH1D* LogXTH1D(const char* name, const char* title, Int_t nbinsx, Double_t xlow,
	       Double_t xup);

#endif
