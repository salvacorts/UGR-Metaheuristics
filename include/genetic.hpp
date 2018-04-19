#include "solver.hpp"
#include <utility>

#ifndef GENETIC__H
#define GENETIC__H

class GeneticAlg : public Solver {
protected:
   typedef vector<Solution> Population;

   double crossProb;
   double mutationProb;
   int populationSize;
   int maxIters;

   virtual Population Select(Population originalP) = 0;
   virtual Population Cross(Population originalP) = 0;
   virtual Population Mutate(Population originalP) = 0;
   virtual Population Replace(Population originalP) = 0;

   Population CreateRandomPopulation();
   pair<int, Solution> Evaluate(Population population);   

public:
   GeneticAlg(vector<vector<int> >& distances, vector<vector<int> >& frequencies, int populationSize, int pCross, int pMutate, int maxIters)
   : Solver(distances, frequencies) {
      this->populationSize = populationSize;
      this->mutationProb = pMutate;
      this->crossProb = pCross;
      this->maxIters = maxIters;
   }

   Solution Solve();
};

#endif