#include "solver.hpp"
#include "localSearch.hpp"
#include <vector>
#include <set>

#ifndef MSS__H
#define MSS__H

class MultiStartSearch : public Solver {
protected:
   LocalSearchSolver* localSearch;
   int maxLocalSearchEvals;
   int maxIterations;

   Solution Mutate(const Solution& originalSolution);

public:
   MultiStartSearch(vector<vector<int> >& distances, vector<vector<int> >& frequencies, int maxIterations, int maxLocalSearchEvals)
   : Solver(distances, frequencies) {
      this->localSearch = new LocalSearchSolverDLB(distances, frequencies);
      this->maxLocalSearchEvals = maxLocalSearchEvals;
      this->maxIterations = maxIterations;
   }

   Solution Solve() override;
};

#endif