#include "simAnealing.hpp"
#include <cmath>
#include <random>

double SimulatedAnnealing::CalculateInitialTemperature(Solution& initialSolution) {
   double initialTemperature;
   
   if (initialSolution.score == -1) {
      initialSolution.CalcCost(distances, frequencies);
   } 

   initialTemperature = (this->mu * initialSolution.score) / log(this->acceptProb);
   this->beta = (initialTemperature - finalTemp) / ((this->maxEvals/this->maxNeighbours) * initialTemperature * this->finalTemp);

   return initialTemperature;
}

bool SimulatedAnnealing::MetroposilAcceptCriteria(double scoreDifference, double temperature) {
   int rnd = ((double) rand() / RAND_MAX);

   if (rnd <= exp(scoreDifference / (temperature))) {   // TODO: Add k*T
      return true;
   }

   return false;
}

double SimulatedAnnealing::ProportionalCooling(double originalTemperature) {
   return this->alpha * originalTemperature;
}

double SimulatedAnnealing::CauchyCooling(double originalTemperature) {
   return originalTemperature / (1 + this->beta * originalTemperature);
}

double SimulatedAnnealing::ApplyCooling(double originalTemperature) {
   double temperature;

   switch (this->coolingTechnique) {
      case CoolingTechnique::Cauchy:
         temperature = this->CauchyCooling(originalTemperature);
         break;
      case CoolingTechnique::Proportional:
         temperature = this->ProportionalCooling(originalTemperature);
         break;
      default:
         temperature = this->ProportionalCooling(originalTemperature);
         break;
   }

   return temperature;
}

Solution SimulatedAnnealing::RandomNeighbour(Solution& originalSolution) {
   Solution neighbour = originalSolution;
   int r1, r2;

   r1 = rand() % originalSolution.n;

   do {
      r2 = rand() % originalSolution.n;
   } while (r1 == r2);

   int tmp = neighbour.solutionRep[r1];
   neighbour.solutionRep[r1] = neighbour.solutionRep[r2];
   neighbour.solutionRep[r2] = tmp;

   neighbour.CalcRelativeCost(distances, frequencies, originalSolution, r1, r2);

   return neighbour;
}

Solution SimulatedAnnealing::Solve(Solution initialSolution) {
   double temperature = CalculateInitialTemperature(initialSolution);
   Solution bestSolution = initialSolution;
   Solution solution = initialSolution;
   int successes, neighboursGenerated;
   int evals = 0;

   do {
      successes = neighboursGenerated = 0;

      while (neighboursGenerated < this->maxNeighbours && successes < this->maxSuccess) {
         Solution neighbour = RandomNeighbour(solution);
         neighboursGenerated++;
         evals++;

         if (neighbour.score < solution.score || MetroposilAcceptCriteria(neighbour.score - solution.score, temperature)) {
            solution = neighbour;
            successes++;

            if (solution.score < bestSolution.score) {
               bestSolution = solution;
            }
         }
      }

      temperature = ApplyCooling(temperature);

   } while (evals < this->maxEvals && successes > 0);

   return bestSolution;
}

Solution SimulatedAnnealing::Solve() {
   Solution initialSolution = Solution::GenerateRandomSolution(distances, frequencies);
   return Solve(initialSolution);
}