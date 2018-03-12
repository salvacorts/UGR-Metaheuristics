#include <vector>
#include <iostream>
#include "solution.hpp"

using namespace std;

#ifndef SOLVER_H
#define SOLVER_H

class Solver {
protected:
   vector<vector<int> > distances;
   vector<vector<int> > frequencies;

public:
   Solver(vector<vector<int> >& distances, vector<vector<int> >& frequencies);
   virtual Solution Solve() = 0;
};

#endif