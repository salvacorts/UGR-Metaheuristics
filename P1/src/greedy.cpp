#include "greedy.hpp"
#include <vector>
#include <utility>
#include <climits>

using namespace std;

void GreedySolver::Solve() {
   vector<bool> unitAssigned(this->n, false);
   vector<bool> locAssigned(this->n, false);
   vector<int> distPotential(this->score);
   vector<int> freqPotential(this->n);
   pair<int, int> bestFi;
   pair<int, int> bestDi;
   int fi, di, ui, li;

   // Calc potentials
   for (int i = 0; i < this->n; ++i) {
      fi = di = 0;

      for (int j = 0; j < this->n; ++j) {
         fi += this->frequencies[i][j];
         di += this->distances[i][j];
      }

      distPotential[i] = di;
      freqPotential[i] = fi;
   }

   // For each assignation
   for (int i = 0; i < this->n; ++i) {
      // Select unit with higher fi which is not in unitAssigned
      // Select location with lower di which is not in locAssigned
      bestFi = make_pair(INT_MIN, 0);
      bestDi = make_pair(INT_MAX, 0);
      for (int j = 0; j < this->n; j++) {
         fi = freqPotential[i];
         di = distPotential[i];

         // If its better and not assigned
         if (fi > bestFi.first && !unitAssigned[i]) bestFi = make_pair(fi, i);
         if (di < bestDi.first && !locAssigned[i]) bestDi = make_pair(di, i);
      }

      this->solutionRep[bestFi.second] = bestDi.second;
      unitAssigned[bestFi.second] = true;
      locAssigned[bestDi.second] = true;
   }

   // Calc cost
   this->score = this->GetSolutionCost();
}