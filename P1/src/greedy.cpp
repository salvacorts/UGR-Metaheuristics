#include "greedy.hpp"
#include <vector>
#include <utility>
#include <climits>

using namespace std;

Solution GreedySolver::Solve() {
   Solution solution(this->distances.size());
   vector<bool> unitAssigned(solution.n, false);
   vector<bool> locAssigned(solution.n, false);
   vector<int> distPotential(solution.n);
   vector<int> freqPotential(solution.n);
   pair<int, int> bestFi;
   pair<int, int> bestDi;
   int fi, di, ui, li;

   // Calc potentials
   for (int i = 0; i < solution.n; ++i) {
      fi = di = 0;

      for (int j = 0; j < solution.n; ++j) {
         fi += this->frequencies[i][j];
         di += this->distances[i][j];
      }

      distPotential[i] = di;
      freqPotential[i] = fi;
   }

   // For each assignation
   for (int i = 0; i < solution.n; ++i) {
      // Select unit with higher fi which is not in unitAssigned
      // Select location with lower di which is not in locAssigned
      bestFi = make_pair(INT_MIN, 0);  // (fi, ui)
      bestDi = make_pair(INT_MAX, 0);  // (di, li)
      for (int j = 0; j < solution.n; j++) {
         fi = freqPotential[j];
         di = distPotential[j];

         // If its better and not assigned
         if (fi > bestFi.first && !unitAssigned[j]) bestFi = make_pair(fi, j);
         if (di < bestDi.first && !locAssigned[j]) bestDi = make_pair(di, j);
      }

      solution.solutionRep[bestFi.second] = bestDi.second;
      unitAssigned[bestFi.second] = true;
      locAssigned[bestDi.second] = true;
   }

   // Calc cost
   solution.score = solution.GetCost(this->distances, this->frequencies);

   return solution;
}