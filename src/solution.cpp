#include "solution.hpp"

Solution::Solution(int n) {
   this->score = -1;
   this->n = n;
   this->solutionRep.resize(n);
}

Solution::Solution(const Solution& copy) {
   this->n = copy.n;
   this->score = copy.score;
   this->solutionRep = copy.solutionRep;
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

ostream& operator<<(std::ostream& os, const Solution& sol) {
   os << sol.n << " " << sol.score << endl;

   for (auto& i : sol.solutionRep) {
      os << i << " ";
   }

   return os;
}
