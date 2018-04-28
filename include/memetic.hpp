#include "agg.hpp"
#include "localSearch.hpp"

#ifndef MEMETIC_H
#define MEMETIC_H

class MemeticAlg : public AGG {
protected:
   LocalSearchSolver* localSearch;
   bool applyOnBest;
   double blProb;
   int blRate;

public:
   MemeticAlg(vector<vector<int> >& distances, vector<vector<int> >& frequencies, int populationSize, double pCross, 
               double pMutate, int maxIters, int blRate, double blProb, int maxNeighbourEvals, bool applyOnBest=false)
   : AGG(distances, frequencies, populationSize, pCross, pMutate, maxIters) {
        this->localSearch = new LocalSearchSolver(distances, frequencies, maxNeighbourEvals);
        this->applyOnBest = applyOnBest;
        this->blProb = blProb;
        this->blRate = blRate;
   }

   Solution Solve() override;
};

#endif