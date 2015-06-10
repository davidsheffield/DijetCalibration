DijetCalibration/Analyzers
==========================

Code to create ntuples suitable for calibration with the dijet balance method.

The dataset must be RECO (RECO, GEN-SIM-RECO, GEN-SIMRECODEBUG, and FEVT all work). AOD does not contain the necessary PF block information. When using GenJets, the dataset must contain SIM information.

Creating ntuples
----------------

The configuration file to use in CRAB is `DijetCalibration/Analyzers/python/DiJetNtuplizer_cfg.py`.

To run a test, place the RECO files you would like to run over in `DijetCalibration/Analyzers/test/files.list`. Run the test with

```
cmsRun DijetCalibration/Analyzers/test/testDiJetNtuplizer_cfg.py
```

Customization
-------------

Change the name of the output file with

```process.dijetcalibration.rootHistFilename = cms.string('yourFileName.root')```

When running over data, set

```
process.dijetcalibration.doGenJets  = cms.bool(False)
```

Event selection can be modified in a similar way.