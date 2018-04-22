#include "genetic.hpp"

#ifndef AGG_H
#define AGG_H

class AGG : public GeneticAlg {
private:
   virtual Population Select(Population originalP);
   virtual Population Cross(Population originalP);
   virtual Population Mutate(Population originalP);
   virtual Population Replace(Population originalP, Population newP);

public:
   AGG(vector<vector<int> >& distances, vector<vector<int> >& frequencies, int populationSize, double pCross, double pMutate, int maxIters)
   : GeneticAlg(distances, frequencies, populationSize, pCross, pMutate, maxIters){}
};

#endif

// TODO: Implement other Cross with PMX order