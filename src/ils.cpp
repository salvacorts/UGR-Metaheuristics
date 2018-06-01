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
   Solution initialsolution = this->localSearch->Solve();
   Solution bestSolution = initialsolution;

   for (int i = 1; i < this->maxIterations; i++) {
      Solution mutatedSolution = Mutate(bestSolution);
      Solution lsSolution = this->localSearch->Solve(mutatedSolution);

      if (lsSolution.score < bestSolution.score) {
         bestSolution = lsSolution;
      }
   }

   bestSolution.CalcCost(distances, frequencies);
   return bestSolution;
}


Solution ILS_SA::Solve() {
   Solution initialsolution = this->simAnealing->Solve();
   Solution bestSolution = initialsolution;

   for (int i = 1; i < this->maxIterations; i++) {
      Solution mutatedSolution = Mutate(bestSolution);
      Solution lsSolution = this->simAnealing->Solve(mutatedSolution);

      if (lsSolution.score < bestSolution.score) {
         bestSolution = lsSolution;
      }
   }

   bestSolution.CalcCost(distances, frequencies);
   return bestSolution;
}