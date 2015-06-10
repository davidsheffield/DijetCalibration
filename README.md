DijetCalibration
================

Code to calibrate CMS's HCAL in eta using dijet balance. Created by David G. Sheffield (Rutgers) based on https://github.com/johnpaulchou/usercode/tree/master/HcalClosureTest by J. P. Chou (Brown)

Runs in CMSSW_7_4_1_patch1.

Subpackages
-----------

* **Analyzers** Create an ntuple from a RECO dataset.
* **RespCorrAlgos** Produce response corrections and plots from ntuples.
* **Rereco** Rereco data with response corrections.

Setup
-----

To setup your environment and get this repository

```
cmsrel CMSSW_7_4_1_patch1
cd CMSSW_7_4_1_patch1/src/
cmsenv
git clone https://github.com/davidsheffield/DijetCalibration.git
scram b
```
