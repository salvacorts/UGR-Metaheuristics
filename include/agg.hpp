#include "genetic.hpp"

#ifndef AGG_H
#define AGG_H

class AGG : public GeneticAlg {
protected:
   Population Select(Population originalP) override;
   Population Cross(Population originalP) override;
   Population Mutate(Population originalP) override;
   Population Replace(Population originalP) override;

public:
   AGG(vector<vector<int> >& distances, vector<vector<int> >& frequencies, int populationSize, double pCross, double pMutate, int maxIters)
   : GeneticAlg(distances, frequencies, populationSize, pCross, pMutate, maxIters){}
};


class AGG_PMX : public AGG {
protected:
   Population Cross(Population originalP) override;
public:
   AGG_PMX(vector<vector<int> >& distances, vector<vector<int> >& frequencies, int populationSize, double pCross, double pMutate, int maxIters)
   : AGG(distances, frequencies, populationSize, pCross, pMutate, maxIters){}
};

#endif