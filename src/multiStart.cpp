#include "multiStart.hpp"

Solution MultiStartSearch::Solve() {
   Solution* bestSolution = NULL;
   int evaluations = 0;

   for (int i = 0; i < this->maxIterations; i++) {
      Solution randomSolution = Solution::GenerateRandomSolution(distances, frequencies);

      if (bestSolution == NULL) bestSolution = new Solution(randomSolution);

      Solution* lsSolution = this->localSearch->GenerateBestNeighbour(randomSolution, evaluations, this->maxLocalSearchEvals);

      if (lsSolution != NULL && lsSolution->score < bestSolution->score) {
         delete bestSolution;
         bestSolution = new Solution(*lsSolution);
         cout << bestSolution->score << endl;
      }
   }

   bestSolution->CalcCost(distances, frequencies);
   return *bestSolution;
}