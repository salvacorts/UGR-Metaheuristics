#include "solver.hpp"
#include <vector>

#ifndef LOCALSEARCH_H
#define LOCALSEARCH_H

class LocalSearchSolver : public Solver {
private:
   Solution GenerateRandomSolution();
   Solution* GenerateBestNeighbour(Solution& fatherSolution);

public:
   LocalSearchSolver(vector<vector<int> >& distances, vector<vector<int> >& frequencies)
   : Solver(distances, frequencies){}

   Solution Solve() final;
};

#endif