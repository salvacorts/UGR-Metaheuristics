#include "genetic.hpp"

#ifndef AGG_H
#define AGG_H

class AGG : public GeneticAlg {
private:
   Population Select(Population originalP);
   Population Cross(Population originalP);
   Population Mutate(Population originalP);
   Population Replace(Population originalP);

public:
   AGG(vector<vector<int> >& distances, vector<vector<int> >& frequencies, int populationSize, int pCross, int pMutate, int maxIters)
   : GeneticAlg(distances, frequencies, populationSize, pCross, pMutate, maxIters){}
};

#endif

// TODO: Implement other Cross with PMX order