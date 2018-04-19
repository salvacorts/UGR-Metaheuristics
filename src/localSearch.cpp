#include "localSearch.hpp"
#include <vector>
#include <utility>
#include <climits>
#include <cstdlib>

using namespace std;

Solution* LocalSearchSolver::GenerateBestNeighbour(Solution& fatherSolution) {
   // Size is (n*(n-1))/2
   int n = fatherSolution.n;

   for (int r = 0; r < n/2; r++) {
      for (int s = r+1; s < n; s++) {
         Solution* neighbour = new Solution(fatherSolution);

         int tmp = neighbour->solutionRep[r];                    // t <- A(r)
         neighbour->solutionRep[r] = neighbour->solutionRep[s];   // A(r) <- A(s)
         neighbour->solutionRep[s] = tmp;                        // A(s) <- t

         int movementCost = neighbour->CalcRelativeCost(this->distances, this->frequencies, fatherSolution, r, s);

         // If the diference is negative, then the cost of the neighbour is lower
         if (movementCost < 0) return neighbour; 
      }
   }

   return NULL;
}

Solution LocalSearchSolver::Solve() {
   Solution finalSolution = Solution::GenerateRandomSolution(this->distances, this->frequencies);
   Solution* nextBestSolution;

   do {
      nextBestSolution = GenerateBestNeighbour(finalSolution);

      if (nextBestSolution != NULL) finalSolution = *nextBestSolution;

   } while(nextBestSolution != NULL);

   finalSolution.CalcCost(this->distances, this->frequencies);
   return finalSolution;
}