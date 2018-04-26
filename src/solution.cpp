#include "solution.hpp"

Solution::Solution(int n) {
   this->n = n;
   this->score = -1;
   this->solutionRep.resize(n);
}

Solution::Solution(const Solution& copy) {
   this->n = copy.n;
   this->score = copy.score;
   this->solutionRep = copy.solutionRep;
}

bool Solution::isValid() {
   bool matched[this->n] = {false};

   for (int i = 0; i < solutionRep.size(); i++) {
      int num = solutionRep[i];

      if (matched[num]) return false;

      matched[num] = true;
   }

   return true;
}

Solution Solution::GenerateRandomSolution(vector<vector<int> >& distances, vector<vector<int> >& frequencies) {
   int n = distances.size();
   bool assigned[n] = {false};
   Solution solution(n);

   for (int i = 0; i < solution.solutionRep.size(); i++) {
      int rndLoc;

      do {
         rndLoc = rand() % n;
      } while (assigned[rndLoc]);
      
      solution.solutionRep[i] = rndLoc;
      assigned[rndLoc] = true;
   }

   solution.CalcCost(distances, frequencies);

   return solution;
}

int Solution::CalcCost(vector<vector<int> >& distances, vector<vector<int> >& frequencies) {
   int unitIndex, locIndex, locNeighbough;
   int cost = 0;

   for(int i = 0; i < this->n; i++) {
      locIndex = this->solutionRep[i];
      unitIndex = i;

      for (int j = 0; j < this->n; j++) {
         if (unitIndex == j) continue;

         locNeighbough = this->solutionRep[j];
         cost += frequencies[unitIndex][j] * distances[locIndex][locNeighbough];
      }
   }

   this->score = cost;
   
   return cost;
}

int Solution::CalcRelativeCost(vector<vector<int> >& distances, vector<vector<int> >& frequencies, const Solution& orig, int r, int s) {
   int movementCost = 0;

   // Calc movement cost which is C(a') - C(a)
   for (int k = 0; k < n; k++) {
      if (k == r || k == s) continue;

      movementCost += frequencies[r][k]*(distances[orig.solutionRep[s]][orig.solutionRep[k]] - distances[orig.solutionRep[r]][orig.solutionRep[k]])
                         +  frequencies[s][k]*(distances[orig.solutionRep[r]][orig.solutionRep[k]] - distances[orig.solutionRep[s]][orig.solutionRep[k]])
                         +  frequencies[k][r]*(distances[orig.solutionRep[k]][orig.solutionRep[s]] - distances[orig.solutionRep[k]][orig.solutionRep[r]])  
                         +  frequencies[k][s]*(distances[orig.solutionRep[k]][orig.solutionRep[r]] - distances[orig.solutionRep[k]][orig.solutionRep[s]]);
   }

   // If movement cost is negative score will decrease.
   this->score += movementCost;

   return movementCost;
}


ostream& operator<<(std::ostream& os, const Solution& sol) {
   os << sol.n << " " << sol.score << endl;

   for (auto& i : sol.solutionRep) {
      os << i << " ";
   }

   return os;
}
