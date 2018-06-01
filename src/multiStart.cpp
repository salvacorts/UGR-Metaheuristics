#include "multiStart.hpp"

Solution MultiStartSearch::Solve() {
   Solution* bestSolution = NULL;

   for (int i = 0; i < this->maxIterations; i++) {
      Solution randomSolution = Solution::GenerateRandomSolution(distances, frequencies);
      Solution lsSolution = this->localSearch->Solve(randomSolution);

      if (bestSolution == NULL || lsSolution.score < bestSolution->score) {
         delete bestSolution;
         bestSolution = new Solution(lsSolution);
      }
   }

   bestSolution->CalcCost(distances, frequencies);
   return *bestSolution;
}