#include "solver.hpp"
#include <vector>

#ifndef LOCALSEARCH_H
#define LOCALSEARCH_H

class LocalSearchSolver : public Solver {
protected:
   Solution GenerateRandomSolution();
   virtual Solution* GenerateBestNeighbour(Solution& fatherSolution);

public:
   LocalSearchSolver(vector<vector<int> >& distances, vector<vector<int> >& frequencies)
   : Solver(distances, frequencies){}

   Solution Solve();
};

#endif