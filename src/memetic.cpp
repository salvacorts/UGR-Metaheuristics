#include "memetic.hpp"
#include <algorithm>
#include <list>
#include <cmath>

Solution MemeticAlg::Solve() {
   Population population = CreateRandomPopulation();
   Solution evaluateResult = Evaluate(population);
   this->bestSolution = new Solution(evaluateResult);
   int blExecN = ceil(this->blProb * population.size());
   int generations = 0;

   while (this->evals <= this->maxEvals ) {
      Population newPopulation = Select(population);
      newPopulation = Cross(newPopulation);
      newPopulation = Mutate(newPopulation);
      population = Replace(population, newPopulation);
      generations++;

      // Execute local search
      if (generations == this->blRate) {
         generations = 0;

         if (this->applyOnBest) {

            auto lessCmp = [this](Solution& a, Solution& b) {
               if (a.score == -1) {
                  a.CalcCost(distances, frequencies);
                  this->evals++;
               } 

               if (b.score == -1) {
                  b.CalcCost(distances, frequencies);
                  this->evals++;
               } 

               return a.score < b.score;
            };

            list<pair<int, Solution> > blApplied;
            Population copy = population;

            sort(copy.begin(), copy.end(), lessCmp);

            for (int i = 0, j = 0; i < blExecN && j < copy.size(); i++) {
               int evals = 0;
               Solution* blSolution = this->localSearch->GenerateBestNeighbour(copy[j], evals, this->maxNeighbourEvals);
               this->evals += evals;
               
               // If no better neighbour, exit
               if (blSolution == NULL) continue;

               int appliedTo = copy[j].score;
               pair<int, Solution> aux = make_pair(appliedTo, *blSolution);
               blApplied.push_front(aux);
               delete blSolution;

               // Find next different best solution
               while (j < copy.size() && copy[j].score == appliedTo) {
                  j++;
               }
            }

            // Search for items from blApplied in population and replace
            for (int i = 0; i < population.size() && !blApplied.empty(); i++) {
               for (auto it = blApplied.begin(); it != blApplied.end(); it++) {
                  if (population[i].score == it->first) {
                     population[i] = it->second;
                     blApplied.erase(it);
                     break;
                  }
               }
            }

         } else {
            for (int i = 0; i < blExecN; i++) {
               int evals = 0;
               Solution* blSolution = this->localSearch->GenerateBestNeighbour(population[i], evals, this->maxNeighbourEvals);
               
               if (blSolution != NULL) population[i] = *blSolution;

               this->evals += evals;
               delete blSolution;
            }
         }
      }

      evaluateResult = Evaluate(population);

      if (evaluateResult.score < this->bestSolution->score) {
         delete this->bestSolution;
         this->bestSolution = new Solution(evaluateResult);
      }
   }

   return *this->bestSolution;
}