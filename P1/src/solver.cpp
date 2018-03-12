#include <assert.h>
#include "solver.hpp"

Solver::Solver(vector<vector<int> >& distances, vector<vector<int> >& frequencies) {
   this->distances = distances;
   this->frequencies = frequencies;
}