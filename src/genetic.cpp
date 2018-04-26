#include "genetic.hpp"
#include <algorithm>
#include <climits>

GeneticAlg::Population GeneticAlg::CreateRandomPopulation() {
   Population population(this->populationSize);
   
   for (auto& cromosome : population) {
      cromosome = Solution::GenerateRandomSolution(this->distances, this->frequencies);
   }

   return population;
}

GeneticAlg::Population GeneticAlg::CopyPopulation(const Population& p) {
   Population newP(p.size());

   for (int i = 0; i < p.size(); i++) {
      newP[i] = p[i];
   }

   return newP;
}

pair<int, Solution> GeneticAlg::Evaluate(Population& population) {
   int bestScore = INT_MAX;
   Solution bestSolution;

   for (auto& cromosome : population) {
      if (cromosome.score == -1) {
         cromosome.CalcCost(this->distances, this->frequencies);
         this->evals++;
      } 

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

   while (this->evals <= this->maxIters ) {
      Population newPopulation = Select(population);
      newPopulation = Cross(newPopulation);
      newPopulation = Mutate(newPopulation);

      population = Replace(newPopulation);
      evaluateResult = Evaluate(population);

      if (this->bestSolution == NULL || evaluateResult.second.score < this->bestSolution->score) {
         this->bestSolution = new Solution(evaluateResult.second);
      }
   }

   return *this->bestSolution;
}