#include "solver.hpp"
#include "localSearch.hpp"
#include <vector>

#ifndef MSS__H
#define MSS__H

class MultiStartSearch : public Solver {
protected:
   LocalSearchSolver* localSearch;
   int maxIterations;
   
public:
   MultiStartSearch(vector<vector<int> >& distances, vector<vector<int> >& frequencies, int maxIterations, int maxLocalSearchEvals)
   : Solver(distances, frequencies) {
      this->localSearch = new LocalSearchSolverDLB(distances, frequencies, maxLocalSearchEvals);
      this->maxIterations = maxIterations;
   }

   Solution Solve() override;
};

#endif