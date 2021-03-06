#include "solver.hpp"
#include <utility>

#ifndef GENETIC__H
#define GENETIC__H

typedef vector<Solution> Population;
Population CrossPMX(const Population& originalP, double crossProb);
Population CrossOX(const Population& originalP, double crossProb);

class GeneticAlg : public Solver {
protected:
   Solution* bestSolution;
   double crossProb;
   double mutationProb;
   int populationSize;
   int maxEvals;
   int evals;

   virtual Population Replace(const Population& originalP, Population& toReplaceP) = 0;
   virtual Population Select(const Population& originalP) = 0;
   virtual Population Mutate(const Population& originalP);
   virtual Population Cross(const Population& originalP);
   virtual Solution Evaluate(Population& population);   

   Population CreateRandomPopulation();

public:
   GeneticAlg(vector<vector<int> >& distances, vector<vector<int> >& frequencies, int populationSize,  double pCross, double pMutate, int maxEvals)
   : Solver(distances, frequencies) {
      this->populationSize = populationSize;
      this->mutationProb = pMutate;
      this->crossProb = pCross;
      this->maxEvals = maxEvals;
      this->bestSolution = NULL;
      this->evals = 0;
   }

   Solution Solve() override;
};

#endif