#include "genetico.hpp"

#ifndef AGE_H
#define AGE_H

class AGE : public AlgortimoGenetico {
public:
   AGE(vector<vector<int> >& distances, vector<vector<int> >& frequencies)
   : Solver(distances, frequencies){}

   Solution Solve();
};

#endif