#include "solver.hpp"

#ifndef GREEDY_H
#define GREEDY_H

class GreedySolver : public Solver {
public:
   GreedySolver(vector<vector<int> >& distances, vector<vector<int> >& frequencies)
   : Solver(distances, frequencies){}

   Solution Solve();
};

#endif