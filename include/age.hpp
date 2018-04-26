#include "genetic.hpp"

#ifndef AGE_H
#define AGE_H

class AGE : public GeneticAlg {
private:
   Population Select(Population originalP) override;
   Population Cross(Population originalP) override;
   Population Mutate(Population originalP) override;
   Population Replace(Population originalP) override;

public:
   AGE(vector<vector<int> >& distances, vector<vector<int> >& frequencies, int populationSize,  double pCross, double pMutate, int maxIters)
   : GeneticAlg(distances, frequencies, populationSize, pCross, pMutate, maxIters){}
};

#endif