#include "solver.hpp"
#include <vector>

#ifndef LOCALSEARCH_H
#define LOCALSEARCH_H

class LocalSearchSolver : public Solver {
public:
   LocalSearchSolver(vector<vector<int> >& distances, vector<vector<int> >& frequencies)
   : Solver(distances, frequencies){}

   virtual Solution* GenerateBestNeighbour(const Solution& fatherSolution, int& evalsCounter, int maxNeighbourEvals=-1);
   Solution Solve() override;
};

class LocalSearchSolverDLB : public LocalSearchSolver {
private:
   bool *dlbMask;

public:
   LocalSearchSolverDLB(vector<vector<int> >& distances, vector<vector<int> >& frequencies) 
   : LocalSearchSolver(distances, frequencies) {
      this->dlbMask = new bool[distances.size()];

      for (int i = 0; i < distances.size(); i++) this->dlbMask[i] = false;
   }

   Solution* GenerateBestNeighbour(const Solution& fatherSolution, int& evalsCounter, int maxNeighbourEvals=-1) override;
};

#endif