#include "localSearch.hpp"
#include <vector>
#include <utility>
#include <climits>
#include <cstdlib>

using namespace std;

Solution LocalSearchSolver::GenerateRandomSolution() {
   int n = this->distances.size();
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

   solution.CalcCost(this->distances, this->frequencies);

   return solution;
}

Solution* LocalSearchSolver::GenerateBestNeighbour(Solution& fatherSolution) {
   // Size is (n*(n-1))/2
   int n = fatherSolution.n;
   int neighbourSize = (n * (n - 1)) / 2;

   for (int i = 0; i < n/2; i++) {
      for (int j = i+1; j < n; j++) {
         Solution* neighbour = new Solution(fatherSolution);

         int tmp = neighbour->solutionRep[i];
         neighbour->solutionRep[i] = neighbour->solutionRep[j];
         neighbour->solutionRep[j] = tmp;
         neighbour->CalcCost(this->distances, this->frequencies);

         if (neighbour->score < fatherSolution.score) return neighbour;
      }
   }

   return NULL;
}

Solution LocalSearchSolver::Solve() {
   Solution finalSolution = GenerateRandomSolution();
   Solution* nextBestSolution;

   do {
      nextBestSolution = GenerateBestNeighbour(finalSolution);

      if (nextBestSolution != NULL) finalSolution = *nextBestSolution;

   } while(nextBestSolution != NULL);

   return finalSolution;
}