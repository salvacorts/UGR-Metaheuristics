#include "solver.hpp"
#include <utility>

#ifndef GENETIC__H
#define GENETIC__H

class GeneticAlg : public Solver {
private:
   double crossProb;
   double mutationProb;
   int populationSize;
   int maxIters;

protected:
   typedef vector<Solution> Population;

   Population CreateRandomPopulation();
   pair<int, Solution> Evaluate(Population population);   

   virtual Population Select(Population originalP);
   virtual Population Cross(Population originalP);
   virtual Population Mutate(Population originalP);
   virtual Population Replace(Population originalP);

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