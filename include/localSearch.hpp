#include "solver.hpp"
#include <vector>

#ifndef LOCALSEARCH_H
#define LOCALSEARCH_H

class LocalSearchSolver : public Solver {
protected:
   int maxNeighbourEvals;


public:
   LocalSearchSolver(vector<vector<int> >& distances, vector<vector<int> >& frequencies, int maxNeighbourEvals=-1)
   : Solver(distances, frequencies){
      this->maxNeighbourEvals = maxNeighbourEvals;
   }

   virtual Solution* GenerateBestNeighbour(Solution& fatherSolution);
   Solution Solve() override;
};

class LocalSearchSolverDLB : public LocalSearchSolver {
private:
   bool *dlbMask;

protected:
   Solution* GenerateBestNeighbour(Solution& fatherSolution) override;

public:
   LocalSearchSolverDLB(vector<vector<int> >& distances, vector<vector<int> >& frequencies, int maxNeighbourEvals=-1) 
   : LocalSearchSolver(distances, frequencies, maxNeighbourEvals) {
      this->dlbMask = new bool[distances.size()];

      for (int i = 0; i < distances.size(); i++) this->dlbMask[i] = false;
   }
};

#endif