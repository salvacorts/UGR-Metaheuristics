#include "localSearch.hpp"
#include <vector>
#include <utility>
#include <climits>
#include <cstdlib>

using namespace std;

Solution LocalSearchSolver::GenerateBestNeighbour(const Solution& fatherSolution) {
   // Size is (n*(n-1))/2
   int n = fatherSolution.n;

   for (int r = 0; r < n/2; r++) {
      for (int s = r+1; s < n; s++) {
         Solution neighbour = fatherSolution;

         int tmp = neighbour.solutionRep[r];                    // t <- A(r)
         neighbour.solutionRep[r] = neighbour.solutionRep[s];   // A(r) <- A(s)
         neighbour.solutionRep[s] = tmp;                        // A(s) <- t

         int movementCost = neighbour.CalcRelativeCost(this->distances, this->frequencies, fatherSolution, r, s);

         // If the diference is negative, then the cost of the neighbour is lower
         if (movementCost < 0) return neighbour; 
      }
   }

   return Solution();
}

Solution LocalSearchSolver::Solve() {
   Solution finalSolution = Solution::GenerateRandomSolution(this->distances, this->frequencies);
   Solution nextBestSolution;
   int evals = 0;

   do {
      nextBestSolution = GenerateBestNeighbour(finalSolution);
      evals++;

      if (nextBestSolution.n != 0) finalSolution = nextBestSolution;

   } while(nextBestSolution.n != 0 || evals == this->maxNeighbourEvals);

   finalSolution.CalcCost(this->distances, this->frequencies);

   return finalSolution;
}

Solution LocalSearchSolverDLB::GenerateBestNeighbour(const Solution& fatherSolution) {
   // Size is (n*(n-1))/2
   int n = fatherSolution.n;

   for (int r = 0; r < n; r++) {
      for (int s = 0; s < n && !this->dlbMask[r]; s++) {
         Solution neighbour = Solution(fatherSolution);

         int tmp = neighbour.solutionRep[r];                    // t <- A(r)
         neighbour.solutionRep[r] = neighbour.solutionRep[s];   // A(r) <- A(s)
         neighbour.solutionRep[s] = tmp;                        // A(s) <- t

         int movementCost = neighbour.CalcRelativeCost(this->distances, this->frequencies, fatherSolution, r, s);

         // If the diference is negative, then the cost of the neighbour is lower
         if (movementCost < 0) {
            this->dlbMask[r] = this->dlbMask[s] = false;            
            return neighbour;
         } 
      }

      // If it hasnt returned yet, this movement is not good. Blacklist it
      dlbMask[r] = true;
   }

   return Solution();
}