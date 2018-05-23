#include "ils.hpp"
#include <cmath>
#include <algorithm>


Solution ILS::Mutate(const Solution& originalSolution) {
   int sliceSize = ceil(this->mutationSublistSize * originalSolution.n);
   int start = rand() % (int)(originalSolution.n - sliceSize - 1);
   int end = start + sliceSize;
   Solution mutatedSolution = originalSolution;

   random_shuffle(mutatedSolution.solutionRep.begin()+start, mutatedSolution.solutionRep.begin()+end);
   mutatedSolution.CalcCost(distances, frequencies);

   return mutatedSolution;
}

Solution ILS::Solve() {
   int evaluations = 0;
   Solution initialsolution = Solution::GenerateRandomSolution(distances, frequencies);
   Solution* bestSolution = this->localSearch->GenerateBestNeighbour(initialsolution, evaluations, this->maxLocalSearchEvals);

   if (bestSolution == NULL) bestSolution = &initialsolution;

   for (int i = 1; i < this->maxIterations; i++) {
      Solution mutatedSolution = Mutate(*bestSolution);
      Solution* lsSolution = this->localSearch->GenerateBestNeighbour(mutatedSolution, evaluations, this->maxLocalSearchEvals);

      if (lsSolution != NULL && lsSolution->score < bestSolution->score) {
         delete bestSolution;
         bestSolution = new Solution(*lsSolution);
      }
   }

   bestSolution->CalcCost(distances, frequencies);
   return *bestSolution;
}