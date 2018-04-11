#include "solver.hpp"

#ifndef GENETICO__H
#define GENETICO__H

class AlgortimoGenetico : public Solver {
private:
   double probabilidadCruce;
   double probabilidadMutacion;

public:
   AlgortimoGenetico(vector<vector<int> >& distances, vector<vector<int> >& frequencies, int pCruce, int pMutar)
   : Solver(distances, frequencies) {
      this->probabilidadMutacion = pMutar;
      this->probabilidadCruce = pCruce;
   }

   Solution Solve();

protected:
   vector<Solution> Cruza(vector<Solution> poblacionOriginal);
};

#endif