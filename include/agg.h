#include "genetico.hpp"

#ifndef AGG_H
#define AGG_H

class AGG : public AlgortimoGenetico {
public:
   AGG(vector<vector<int> >& distances, vector<vector<int> >& frequencies)
   : Solver(distances, frequencies){}

   Solution Solve();
};

#endif