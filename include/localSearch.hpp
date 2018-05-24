#include "solver.hpp"
#include <vector>

#ifndef LOCALSEARCH_H
#define LOCALSEARCH_H

class LocalSearchSolver : public Solver {
protected:
   int maxEvals;
public:
   LocalSearchSolver(vector<vector<int> >& distances, vector<vector<int> >& frequencies, int maxEvals=-1)
   : Solver(distances, frequencies){
      this->maxEvals = maxEvals;
   }

   virtual Solution* GenerateBestNeighbour(const Solution& fatherSolution, int& evalsCounter, int maxNeighbourEvals=-1);
   Solution Solve(Solution initialSolution);
   Solution Solve() override;
};

class LocalSearchSolverDLB : public LocalSearchSolver {
private:
   bool *dlbMask;

public:
   LocalSearchSolverDLB(vector<vector<int> >& distances, vector<vector<int> >& frequencies, int maxEvals=-1) 
   : LocalSearchSolver(distances, frequencies, maxEvals) {
      this->dlbMask = new bool[distances.size()];

      for (int i = 0; i < distances.size(); i++) this->dlbMask[i] = false;
   }

   Solution* GenerateBestNeighbour(const Solution& fatherSolution, int& evalsCounter, int maxNeighbourEvals=-1) override;
};

#endif