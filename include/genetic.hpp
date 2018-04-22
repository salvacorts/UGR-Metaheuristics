#include "solver.hpp"
#include <utility>

#ifndef GENETIC__H
#define GENETIC__H
class GeneticAlg : public Solver {
protected:
   typedef vector<Solution> Population;

   Solution* bestSolution;
   double crossProb;
   double mutationProb;
   int populationSize;
   int maxIters;
   int evals;

   virtual Population Select(Population originalP) = 0;
   virtual Population Cross(Population originalP) = 0;
   virtual Population Mutate(Population originalP) = 0;
   virtual Population Replace(Population originalP, Population newP) = 0;

   Population CreateRandomPopulation();
   Population CopyPopulation(const Population& p);
   pair<int, Solution> Evaluate(Population& population);   

public:
   GeneticAlg(vector<vector<int> >& distances, vector<vector<int> >& frequencies, int populationSize,  double pCross, double pMutate, int maxIters)
   : Solver(distances, frequencies) {
      this->populationSize = populationSize;
      this->mutationProb = pMutate;
      this->crossProb = pCross;
      this->maxIters = maxIters;
      this->bestSolution = NULL;
      this->evals = 0;
   }

   Solution Solve();
};

#endif