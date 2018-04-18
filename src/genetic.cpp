#include "genetic.hpp"
#include <climits>

GeneticAlg::Population GeneticAlg::CreateRandomPopulation() {
   Population population(this->populationSize);
   
   for (auto cromosome : population) {
      cromosome = Solution::GenerateRandomSolution(this->distances, this->frequencies);
   }

   return population;
}

pair<int, Solution> GeneticAlg::Evaluate(Population population) {
   int bestScore = INT_MAX;
   Solution bestSolution;

   for (auto cromosome : population) {
      if (cromosome.score == -1) cromosome.CalcCost(this->distances, this->frequencies);

      if (cromosome.score < bestScore) {
         bestScore = cromosome.score;
         bestSolution = cromosome;
      }
   }

   return make_pair(bestScore, bestSolution);
}

Solution GeneticAlg::Solve() {
   Population population = CreateRandomPopulation();
   pair<int, Solution> evaluateResult = Evaluate(population);

   for (int i = 0; i < this->maxIters; i++) {
      Population newPopulation = Select(population);
      newPopulation = Cross(newPopulation);
      newPopulation = Mutate(newPopulation);

      population = Replace(newPopulation);
      evaluateResult = Evaluate(population);
   }

   return evaluateResult.second;
}