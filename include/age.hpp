#include "genetic.hpp"

#ifndef AGE_H
#define AGE_H

class AGE : public GeneticAlg {
private:
   Population Select(Population originalP);
   Population Cross(Population originalP);
   Population Mutate(Population originalP);
   Population Replace(Population originalP);

public:
   AGE(vector<vector<int> >& distances, vector<vector<int> >& frequencies, int populationSize, int pCross, int pMutate, int maxIters)
   : GeneticAlg(distances, frequencies, populationSize, pCross, pMutate, maxIters){}
};

#endif