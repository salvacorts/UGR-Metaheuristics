#include "solver.hpp"

class GreedySolver : public Solver {
public:
   GreedySolver(vector<vector<int> >& distances, vector<vector<int> >& frequencies)
   : Solver(distances, frequencies){}

   void Solve() final;
};