#include "TLorentzVector.h"
#include <cmath>
#include "TMatrixD.h"
#include "TMatrixDEigen.h"

namespace AngularVariables{
  
  double ht(vector<TLorentzVector> jet,vector<TLorentzVector> lepton)
  {
    double ht=0;
    for(unsigned int i=0;i<jet.size();i++)
      ht+=jet.at(i).Pt();
    for(unsigned int i=0;i<lepton.size();i++)
      ht+=lepton.at(i).Pt();
    return ht;
  }

  double h(vector<TLorentzVector> jet,vector<TLorentzVector> lepton)
  {
    double h=0;
    for(unsigned int i=0;i<jet.size();i++)
      h+=jet.at(i).E();
    for(unsigned int i=0;i<lepton.size();i++)
      h+=lepton.at(i).E();
    return h;
  }

  double centrality(double ht, double h)
  {
    return ht/h; 
  }
   
  //returns an vector[3] with aplanarity at 0 and sphericity at 1 and circularity at 2
  vector<double> aplan_spher(vector<TLorentzVector> jets, vector<TLorentzVector> lep, TLorentzVector met)
  {
    double pxpx = 0.0;
    double pxpy = 0.0;
    double pxpz = 0.0;
    double pypx = 0.0;
    double pypy = 0.0;
    double pypz = 0.0;
    double pzpx = 0.0;
    double pzpy = 0.0;
    double pzpz = 0.0;
    double pxpxpypypzpz = 0.0;
    
    for (unsigned int i =0; i != jets.size(); i++)
      {
	double px = jets[i].Px();
	double py = jets[i].Py();
	double pz = jets[i].Pz();
	pxpx += px*px;
	pxpy += px*py;
	pxpz += px*pz;
	pypx += py*px;
	pypy += py*py;
	pypz += py*pz;
	pzpx += pz*px;
	pzpy += pz*py;
	pzpz += pz*pz;
	pxpxpypypzpz +=(px*px+py*py+pz*pz);
      }

     for (unsigned int i =0; i != lep.size(); i++)
      {
	double pxl = lep[i].Px();
	double pyl = lep[i].Py();
	double pzl = lep[i].Pz();
	pxpx += pxl*pxl;
	pxpy += pxl*pyl;
	pxpz += pxl*pzl;
	pypx += pyl*pxl;
	pypy += pyl*pyl;
	pypz += pyl*pzl;
	pzpx += pzl*pxl;
	pzpy += pzl*pyl;
	pzpz += pzl*pzl;
	pxpxpypypzpz +=(pxl*pxl+pyl*pyl+pzl*pzl);
      }
     
    double pxm = met.Px();
    double pym = met.Py();
    double pzm = met.Pz();
    pxpx += pxm*pxm;
    pxpy += pxm*pym;
    pxpz += pxm*pzm;
    pypx += pym*pxm;
    pypy += pym*pym;
    pypz += pym*pzm;
    pzpx += pzm*pxm;
    pzpy += pzm*pym;
    pzpz += pzm*pzm;
    pxpxpypypzpz +=(pxm*pxm+pym*pym+pzm*pzm);
    
    // Array of momentum tensor elements
    double A[9]= { pxpx/pxpxpypypzpz, pxpy/pxpxpypypzpz, pxpz/pxpxpypypzpz, pypx/pxpxpypypzpz,
		   pypy/pxpxpypypzpz, pypz/pxpxpypypzpz, pzpx/pxpxpypypzpz, pzpy/pxpxpypypzpz, pzpz/pxpxpypypzpz};
    
    //Calculate sphericity eignevalues
    TMatrixD M(3,3);
    M.SetMatrixArray(A);
    TMatrixDEigen V(M);
    TMatrixD Eval = V.GetEigenValues();
    double e1 = TMatrixDRow(Eval,0)(0);
    double e2 = TMatrixDRow(Eval,1)(1);
    double e3 = TMatrixDRow(Eval,2)(2);
    std::vector<double> evalvector;
    evalvector.push_back(e1);
    evalvector.push_back(e2);
    evalvector.push_back(e3);
    sort (evalvector.begin(), evalvector.end()); // Q3 >= Q2 >= Q1 >=0
    //double check = TMatrixDRow(Eval,0)(1) + TMatrixDRow(Eval,0)(2) + TMatrixDRow(Eval,1)(0) + TMatrixDRow(Eval,1)(2) + TMatrixDRow(Eval,2)(0) + TMatrixDRow(Eval,2)(1);
    //if (check != 0.0) {double err = -1; return err;}
    
    //cout<<"1"<<evalvector.at(0) <<"2"<<evalvector.at(1) <<"3"<<evalvector.at(2) << '\n';
    
    double sphericity = 1.5*(evalvector.at(1)+evalvector.at(0));
    double aplanarity = 1.5*evalvector.at(2);
    double circularity=2*evalvector.at(1)/(evalvector.at(2)+evalvector.at(1));
       
    vector<double> ans;
    ans.push_back(aplanarity);
    ans.push_back(sphericity);
    ans.push_back(circularity);

    return ans;
  }
}
  /*
  double helicitycos(TLorentzVector tempT,TLorentzVector tempW,TLorentzVector tempL,TLorentzVector tempCM)
  {
       
    tempT.Boost(-tempCM.BoostVector());
    tempL.Boost(-tempCM.BoostVector());
    tempL.Boost(-tempT.BoostVector());
    
    double cosinej = 0;
    
    cosinej = tempT.Vect().Dot(tempL.Vect());
    cosinej = cosinej/(tempT.Vect().Mag()*tempL.Vect().Mag());
    
    TLorentzVector tempLhelicity = tempL;
    TLorentzVector tempWhelicity = tempW;
    TLorentzVector tempThelicity = tempT;
    
    tempLhelicity.Boost(-tempWhelicity.BoostVector());
    tempWhelicity.Boost(-tempThelicity.BoostVector());
    
    helicitycos = tempLhelicity.Vect().Dot(tempWhelicity.Vect());
    helicitycos = helicitycos / (tempLhelicity.Vect().Mag()*tempWhelicity.Vect().Mag());
    return helicitycos;
  }
  */

  /* these have not been tested... 
  double ht(vector<TLorentzVector> jets, vector<TLorentzVector> leptons, TLorentzVector met)
  {
    double tempht = 0;
    for(unsigned int i = 0;i<jets.size();i++){
      tempht+=(jets.at(i)).Pt();
    }
    tempht+=lep.Pt();
    tempht+=met.Pt();
    
    return tempht;
  }
  
  double h(vector<TLorentzVector> jets, vector<TLorentzVector> leptons, TLorentzVector met)
  {
    double temph = 0;
    for(unsigned int i = 0;i<jets.size();i++){
      temph+=(jets.at(i)).E();
    }
    temph+=lep.E();
    temph+=met.E();

    return h;
  }
  */







