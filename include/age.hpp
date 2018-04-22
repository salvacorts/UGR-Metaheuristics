#include "genetic.hpp"

#ifndef AGE_H
#define AGE_H

class AGE : public GeneticAlg {
private:
   virtual Population Select(Population originalP);
   virtual Population Cross(Population originalP);
   virtual Population Mutate(Population originalP);
   virtual Population Replace(Population originalP, Population newP);

public:
   AGE(vector<vector<int> >& distances, vector<vector<int> >& frequencies, int populationSize,  double pCross, double pMutate, int maxIters)
   : GeneticAlg(distances, frequencies, populationSize, pCross, pMutate, maxIters){}
};

#endif