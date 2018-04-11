#include "localSearch.hpp"
#include <vector>

#ifndef LOCALSEARCHDLB_H
#define LOCALSEARCHDLB_H

class LocalSearchSolverDLB : public LocalSearchSolver {
private:
   bool *dlbMask;

protected:
   Solution* GenerateBestNeighbour(Solution& fatherSolution) override;

public:
   LocalSearchSolverDLB(vector<vector<int> >& distances, vector<vector<int> >& frequencies) : LocalSearchSolver(distances, frequencies) {
      this->dlbMask = new bool[distances.size()];

      for (int i = 0; i < distances.size(); i++) this->dlbMask[i] = false;
   }
};

#endif