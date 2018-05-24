#include "solver.hpp"
#include "localSearch.hpp"
#include <vector>

#ifndef ILS__H
#define ILS__H

class ILS : public Solver {
protected:
   LocalSearchSolver* localSearch;
   double mutationSublistSize;
   int maxIterations;

   Solution Mutate(const Solution& originalSolution);

public:
   ILS(vector<vector<int> >& distances, vector<vector<int> >& frequencies, double mutationSublistSize, int maxIterations, int maxLocalSearchEvals)
   : Solver(distances, frequencies) {
      this->localSearch = new LocalSearchSolverDLB(distances, frequencies, maxLocalSearchEvals);
      this->mutationSublistSize = mutationSublistSize; 
      this->maxIterations = maxIterations;
   }

   Solution Solve() override;
};

#endif