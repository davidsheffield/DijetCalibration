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

process.dijetcalibration.rootHistFilename = cms.string('dijet_balance_ntuple.root')
process.dijetcalibration.doGenJets = cms.bool(False)
process.dijetcalibration.pfJetCollName = cms.string('DiJetsProd:ak4PFJetsCHS')
process.dijetcalibration.pfJetCorrName = cms.string('ak4PFCHSL1FastL2L3')
process.dijetcalibration.hbheRecHitName = cms.string('DiJetsProd:hbhereco')
process.dijetcalibration.hfRecHitName = cms.string('DiJetsProd:hfreco')
process.dijetcalibration.hoRecHitName = cms.string('DiJetsProd:horeco')
process.dijetcalibration.pvCollName = cms.string('DiJetsProd:offlinePrimaryVertices')

process.source = cms.Source("PoolSource", fileNames = cms.untracked.vstring())

process.maxEvents = cms.untracked.PSet( input = cms.untracked.int32(-1) )
process.MessageLogger.cerr.FwkReport.reportEvery=cms.untracked.int32(100)
process.options = cms.untracked.PSet( wantSummary = cms.untracked.bool(True) )
process.options = cms.untracked.PSet(
    SkipEvent = cms.untracked.vstring('ProductNotFound'))

process.p = cms.Path(process.dijetcalibration)
