import FWCore.ParameterSet.Config as cms

process = cms.Process('ANALYSIS')

process.load('FWCore.MessageService.MessageLogger_cfi')

process.load('Configuration.StandardSequences.Services_cff')
process.load('Configuration.StandardSequences.FrontierConditions_GlobalTag_cff')
from Configuration.AlCa.autoCond import autoCond
process.load("Configuration.Geometry.GeometryIdeal_cff")
process.GlobalTag.globaltag=autoCond['startup']

#load the response corrections calculator
process.load('DijetCalibration.Analyzers.dijetntuplizer_cfi')
process.load('JetMETCorrections.Configuration.JetCorrectionProducers_cff')

import FWCore.ParameterSet.VarParsing as VarParsing
options = VarParsing.VarParsing ('analysis')
options.outputFile = 'ntuple.root'
options.maxEvents = -1
options.register('MC',
                 True, # default value
                 VarParsing.VarParsing.multiplicity.singleton,
                 VarParsing.VarParsing.varType.bool,
                 "Dataset is MC.")
options.parseArguments()

# run over files

process.dijetcalibration.rootHistFilename = cms.string(options.outputFile)
process.dijetcalibration.doGenJets = cms.bool(options.MC)

process.source = cms.Source("PoolSource", fileNames = cms.untracked.vstring(options.inputFiles))

process.maxEvents = cms.untracked.PSet(input = cms.untracked.int32(options.maxEvents))
process.MessageLogger.cerr.FwkReport.reportEvery=cms.untracked.int32(100)
process.options = cms.untracked.PSet( wantSummary = cms.untracked.bool(True) )

process.p = cms.Path(process.dijetcalibration)
