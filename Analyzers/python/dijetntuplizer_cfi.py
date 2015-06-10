import FWCore.ParameterSet.Config as cms

dijetcalibration = cms.EDAnalyzer(
    'DiJetNtuplizer',
    pfJetCollName       = cms.string('ak4PFJetsCHS'),
    pfJetCorrName       = cms.string('ak4PFCHSL2L3'),
    genJetCollName      = cms.string('ak4GenJets'),
    genParticleCollName = cms.string('genParticles'),
    genEventInfoName    = cms.string('generator'),
    hbheRecHitName      = cms.string('hbhereco'),
    hfRecHitName        = cms.string('hfreco'),
    hoRecHitName        = cms.string('horeco'),
    pvCollName          = cms.string('offlinePrimaryVertices'),
    rootHistFilename    = cms.string('dijettree.root'),
    maxDeltaEta         = cms.double(1.5),
    minTagJetEta        = cms.double(0.0),
    maxTagJetEta        = cms.double(5.0),
    minSumJetEt         = cms.double(50.0),
    minJetEt            = cms.double(20.0),
    maxThirdJetEt       = cms.double(100.0),
    maxJetEMF           = cms.double(0.9),
    doGenJets           = cms.bool(True),
    debug               = cms.untracked.bool(False)
    )
