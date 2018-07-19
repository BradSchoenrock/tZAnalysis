#include "TLorentzVector.h"
#include <cmath>

namespace TopPolarization{

  // note that the order matters since we are modifying TLorentzVectors
  // W helicity
  double WHelicity(TLorentzVector lepton,TLorentzVector wBoson,TLorentzVector topQuark ){
    lepton.Boost(-wBoson.BoostVector());
    wBoson.Boost(-topQuark.BoostVector());
    double WHel=lepton.Vect().Dot(wBoson.Vect());
    WHel=WHel / (lepton.Vect().Mag()*wBoson.Vect().Mag());
    return WHel;
  }
  
  // top quark polarization in the helicity basis
  double TopPolHelBasis(TLorentzVector lepton,TLorentzVector CMframe, TLorentzVector topQuark ){
    //CMframe = four vector of the CM frame;
    lepton.Boost(-CMframe.BoostVector());
    topQuark.Boost(-CMframe.BoostVector());
    lepton.Boost(-topQuark.BoostVector()); // need to boost lepton twice
    double cosHel=(topQuark.Vect()).Dot(lepton.Vect());
    cosHel=cosHel / ((topQuark.Vect()).Mag()*(lepton.Vect()).Mag());
    return cosHel;
  }


  // top quark polarization in the optimal basis (also called beamline basis)
  double TopPolOptimalBasis(TLorentzVector lepton,TLorentzVector tlSpec,TLorentzVector topQuark){
    //tlSpec=four-vector of the leading untagged jet;
    lepton.Boost(-topQuark.BoostVector());
    tlSpec.Boost(-topQuark.BoostVector());
    double cosOpt=lepton.Vect().Dot(tlSpec.Vect());
    cosOpt=cosOpt / ((tlSpec.Vect()).Mag()*(lepton.Vect()).Mag());
    return cosOpt;
  }
  
}
