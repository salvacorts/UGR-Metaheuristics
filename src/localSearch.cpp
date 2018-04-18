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
         int movementCost = 0;

         // Calc movement cost which is C(a') - C(a)
         for (int k = 0; k < n; k++) {
            if (k == r || k == s) continue;

            movementCost += this->frequencies[r][k]*(this->distances[fatherSolution.solutionRep[s]][fatherSolution.solutionRep[k]] - this->distances[fatherSolution.solutionRep[r]][fatherSolution.solutionRep[k]])
                         +  this->frequencies[s][k]*(this->distances[fatherSolution.solutionRep[r]][fatherSolution.solutionRep[k]] - this->distances[fatherSolution.solutionRep[s]][fatherSolution.solutionRep[k]])
                         +  this->frequencies[k][r]*(this->distances[fatherSolution.solutionRep[k]][fatherSolution.solutionRep[s]] - this->distances[fatherSolution.solutionRep[k]][fatherSolution.solutionRep[r]])  
                         +  this->frequencies[k][s]*(this->distances[fatherSolution.solutionRep[k]][fatherSolution.solutionRep[r]] - this->distances[fatherSolution.solutionRep[k]][fatherSolution.solutionRep[s]]);
         }

         // If the diference is negative, then the cost of the neighbour is lower
         if (movementCost < 0) {
            Solution* neighbour = new Solution(fatherSolution);

            int tmp = neighbour->solutionRep[r];                     // t <- A(r)
            neighbour->solutionRep[r] = neighbour->solutionRep[s];   // A(r) <- A(s)
            neighbour->solutionRep[s] = tmp;                         // A(s) <- t

            return neighbour;
         } 
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