#include "localSearch.hpp"
#include <vector>
#include <utility>
#include <climits>
#include <cstdlib>

using namespace std;

Solution* LocalSearchSolver::GenerateBestNeighbour(const Solution& fatherSolution, int& evalsCounter, int maxNeighbourEvals) {
   // Size is (n*(n-1))/2
   int n = fatherSolution.n;
   int evals = 0;

   for (int r = 0; r < n/2 && evals != maxNeighbourEvals; r++) {
      for (int s = r+1; s < n; s++) {
         Solution neighbour = fatherSolution;

         int tmp = neighbour.solutionRep[r];                    // t <- A(r)
         neighbour.solutionRep[r] = neighbour.solutionRep[s];   // A(r) <- A(s)
         neighbour.solutionRep[s] = tmp;                        // A(s) <- t

         int movementCost = neighbour.CalcRelativeCost(this->distances, this->frequencies, fatherSolution, r, s);
         
         if (evals++ == maxNeighbourEvals) break;

         // If the diference is negative, then the cost of the neighbour is lower
         if (movementCost < 0) return new Solution(neighbour); 
      }
   }

   evalsCounter = evals;
   return NULL;
}

Solution LocalSearchSolver::Solve(Solution initialSolution) {
   Solution finalSolution = initialSolution;
   Solution* nextBestSolution;
   bool countevals = true;
   int evals = 0;

   if (this->maxEvals == -1) countevals = false;

   do {
      nextBestSolution = GenerateBestNeighbour(finalSolution, evals, this->maxEvals);

      if (nextBestSolution != NULL) finalSolution = *nextBestSolution;

      if (countevals && evals == this->maxEvals) break;
      
   } while(nextBestSolution != NULL);

   finalSolution.CalcCost(this->distances, this->frequencies);
   delete nextBestSolution;

   return finalSolution;
}

Solution LocalSearchSolver::Solve() {
   Solution initialSolution = Solution::GenerateRandomSolution(this->distances, this->frequencies);
   Solution finalSolution = Solve(initialSolution);

   return finalSolution;
}

Solution* LocalSearchSolverDLB::GenerateBestNeighbour(const Solution& fatherSolution, int& evalsCounter, int maxNeighbourEvals) {
   // Size is (n*(n-1))/2
   int n = fatherSolution.n;
   int evals = 0;

   for (int r = 0; r < n && evals != maxNeighbourEvals; r++) {
      for (int s = 0; s < n && !this->dlbMask[r]; s++) {
         Solution neighbour = Solution(fatherSolution);

         int tmp = neighbour.solutionRep[r];                    // t <- A(r)
         neighbour.solutionRep[r] = neighbour.solutionRep[s];   // A(r) <- A(s)
         neighbour.solutionRep[s] = tmp;                        // A(s) <- t

         int movementCost = neighbour.CalcRelativeCost(this->distances, this->frequencies, fatherSolution, r, s);
         
         if (evals++ == maxNeighbourEvals) break;

         // If the diference is negative, then the cost of the neighbour is lower
         if (movementCost < 0) {
            this->dlbMask[r] = this->dlbMask[s] = false;            
            return new Solution(neighbour);
         } 
      }

      // If it hasnt returned yet, this movement is not good. Blacklist it
      dlbMask[r] = true;
   }

   evalsCounter = evals;
   return NULL;
}