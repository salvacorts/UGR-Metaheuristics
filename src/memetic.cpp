#include "memetic.hpp"

Solution MemeticAlg::Solve() {
   Population population = CreateRandomPopulation();
   pair<int, Solution> evaluateResult = Evaluate(population);
   this->bestSolution = new Solution(evaluateResult.second);
   int blExecN = this->blProb * population.size();
   int generations = 0;

   while (this->evals <= this->maxIters ) {
      Population newPopulation = Select(population);
      newPopulation = Cross(newPopulation);
      newPopulation = Mutate(newPopulation);
      population = Replace(population, newPopulation);
      generations++;

      // Execute local search
      if (generations == this->blRate) {
         generations = 0;

         // TODO: Add if execute on best
         if (this->applyOnBest) {

         }

         for (int i = 0; i < blExecN; i++) {
            Solution* blSolution = this->localSearch->GenerateBestNeighbour(population[i]);
            
            if (blSolution != NULL) population[i] = *blSolution;
         }
      }

      evaluateResult = Evaluate(population);

      if (evaluateResult.second.score < this->bestSolution->score) {
         this->bestSolution = new Solution(evaluateResult.second);
      }
   }

   return *this->bestSolution;
}