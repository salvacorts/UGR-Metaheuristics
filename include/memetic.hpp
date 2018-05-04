#include "agg.hpp"
#include "localSearch.hpp"

#ifndef MEMETIC_H
#define MEMETIC_H

class MemeticAlg : public AGG {
protected:
   LocalSearchSolverDLB* localSearch;
   bool applyOnBest;
   double blProb;
   int blRate;
   int maxNeighbourEvals;

public:
   MemeticAlg(vector<vector<int> >& distances, vector<vector<int> >& frequencies, int populationSize, double pCross, 
               double pMutate, int maxEvals, int blRate, double blProb, int maxNeighbourEvals, bool applyOnBest=false)
   : AGG(distances, frequencies, populationSize, pCross, pMutate, maxEvals) {
        this->localSearch = new LocalSearchSolverDLB(distances, frequencies);
        this->maxNeighbourEvals = maxNeighbourEvals;
        this->applyOnBest = applyOnBest;
        this->blProb = blProb;
        this->blRate = blRate;
   }

   Solution Solve() override;
};

#endif