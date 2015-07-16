#ifndef __PHOTON_TREE_H_
#define __PHOTON_TREE_H_

/*
Log:
Sep 10, 2011
Anil Singh: Empty template created. 
*/

#include <memory>
#include <string>
#include <iostream>
#include <vector>
#include "TTree.h"
#include "FWCore/Framework/interface/Event.h"
#include "DataFormats/Common/interface/Handle.h"
#include "DataFormats/PatCandidates/interface/Photon.h"
#include "DataFormats/Math/interface/LorentzVector.h"
#include "DelPanj/TreeMaker/interface/utils.h"
#include "DelPanj/TreeMaker/interface/baseTree.h"

using namespace std;
using namespace edm;

class photonTree : public baseTree{

 public:
  photonTree(std::string name, TTree* tree, const edm::ParameterSet& cfg);
  ~photonTree();
  void Fill(const edm::Event& iEvent);
  void SetBranches();
  void Clear();

 private:
  photonTree(){};
  bool usePFObjects_;
  edm::InputTag photonLabel_;
  edm::InputTag phoLooseIdMapToken_;
  edm::InputTag phoMediumIdMapToken_;
  edm::InputTag phoTightIdMapToken_;


  //variables which would become branches
  int nPho_;
  TClonesArray *photonP4_;

  std::vector<bool> isPassLoose;
  std::vector<bool> isPassMedium;
  std::vector<bool> isPassTight;


};

#endif

