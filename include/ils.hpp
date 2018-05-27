#include "solver.hpp"
#include "localSearch.hpp"
#include "simAnealing.hpp"
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

class ILS_SA : public ILS {
protected:
   SimulatedAnealing* simAnealing;
public:
   ILS_SA(vector<vector<int> >& distances, vector<vector<int> >& frequencies, double mutationSublistSize, 
            int maxIterations, int maxNeighbours, double maxSuccess, double finalTemp, double acceptProb, 
            double mu, CoolingTechnique ct, int maxEvals=-1, double alpha=0.99)
   : ILS(distances, frequencies, mutationSublistSize, maxIterations, 0) {
      this->simAnealing = new SimulatedAnealing(distances, frequencies, maxNeighbours, maxSuccess, finalTemp, acceptProb, mu, ct, maxEvals, alpha);
   }

   Solution Solve() override;
};

#endif