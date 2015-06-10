DijetCalibration/RespCorrAlgos
==============================

Code for getting response corrections for the HCAL using the dijet balance method and for making plots.

Getting response corrections
----------------------------

The code in `DijetCalibration/RespCorrAlgos/bin/getRespCorr.cc` generates an executable that will extract the information from the nutples made in `DijetCalibration/Analyzers` and finds the response corrections along with other plots. Run the executable with

```
CMSSW_7_4_1_patch1/bin/slc6_amd64_gcc491/getRespCorr isMC maxDeltaEta minSumJetEt minJetEt maxThirdJetEt [debug]
```

where `isMC` is `0` for data and `1` for MC and `debug` is optional. For example,

```
CMSSW_7_4_1_patch1/bin/slc6_amd64_gcc491/getRespCorr 1 0.5 100 25 15
```

Code
----

* `DijetCalibration/RespCorrAlgos/src/DijetRespCorrDatum.cc` stores a dijet event.
* `DijetCalibration/RespCorrAlgos/src/DijetRespCorrData.cc` is a vector of `DijetRespCorrDatum` with methods to get response corrections and make plots.
* `DijetCalibration/RespCorrAlgos/src/DijetTree.cc` is a class that will run over an ntuple and store the contents in an `DijetRespCorrData`.
* `DijetCalibration/RespCorrAlgos/test/Sigma.C` approximates the width of a histogram.