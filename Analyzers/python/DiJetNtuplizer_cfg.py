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

# run over files

process.calcrespcorrdijets.rootHistFilename = cms.string('dijet_balance_ntuple.root')
#process.calcrespcorrdijets.doCaloJets = cms.bool(False)
#process.calcrespcorrdijets.doPFJets = cms.bool(False)
#process.calcrespcorrdijets.doGenJets = cms.bool(False)
#process.calcrespcorrdijets.debug = cms.untracked.bool(True)
#process.calcrespcorrdijets.maxDeltaEta = cms.double(1.5)
#process.calcrespcorrdijets.minJetEt = cms.double(20.0)
#process.calcrespcorrdijets.minSumJetEt = cms.double(50.0)
#process.calcrespcorrdijets.maxThirdJetEt = cms.double(100.0)

process.source = cms.Source("PoolSource", fileNames = cms.untracked.vstring())

process.maxEvents = cms.untracked.PSet( input = cms.untracked.int32(-1) )
process.MessageLogger.cerr.FwkReport.reportEvery=cms.untracked.int32(100)
process.options = cms.untracked.PSet( wantSummary = cms.untracked.bool(True) )

process.p = cms.Path(process.calcrespcorrdijets)
