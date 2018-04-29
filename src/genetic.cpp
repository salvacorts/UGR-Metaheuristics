#include "genetic.hpp"
#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdlib>

Population GeneticAlg::CreateRandomPopulation() {
   Population population(this->populationSize);
   
   for (auto& cromosome : population) {
      cromosome = Solution::GenerateRandomSolution(this->distances, this->frequencies);
   }

   return population;
}

Population GeneticAlg::CopyPopulation(const Population& p) {
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
   this->bestSolution = new Solution(evaluateResult.second);

   while (this->evals <= this->maxIters ) {
      Population newPopulation = Select(population);
      newPopulation = Cross(newPopulation);
      newPopulation = Mutate(newPopulation);
      population = Replace(population, newPopulation);
      evaluateResult = Evaluate(population);

      if (evaluateResult.second.score < this->bestSolution->score) {
         delete this->bestSolution;
         this->bestSolution = new Solution(evaluateResult.second);
      }
   }

   return *this->bestSolution;
}

Population GeneticAlg::Mutate(const Population& originalP) {
   Population newP = originalP;
   int mutationNumber = this->mutationProb * newP.size() * newP[0].n;
   int start = rand() % newP.size();

   // We will mutate the first mutationNumber cromosomes starting from start
   for (int i = start; i < mutationNumber; i = (i+1) % newP.size()) {
      int rnd1 = rand() % newP[0].n;
      int rnd2 = rand() % newP[0].n;

      // We need it for CalcRerlativeCost
      if (newP[i].score == -1) {
         newP[i].CalcCost(this->distances, this->frequencies);
         this->evals++;
      }

      Solution originalSolution = newP[i]; // Make a copy to CalcRelativeCost
      
      // Swap gens
      int tmp = newP[i].solutionRep[rnd1];
      newP[i].solutionRep[rnd1] = newP[i].solutionRep[rnd2];
      newP[i].solutionRep[rnd2] = tmp;

      // Calc relative cost of mutated solution
      newP[i].CalcRelativeCost(this->distances, this->frequencies, originalSolution, rnd1, rnd2);
   }

   return newP;
}

Population GeneticAlg::Cross(const Population& originalP) {
   // n vez de generar un aleatorio u en [0,1] para cada pareja
   // y cruzarla si u <= Pc , se estima a priori el número
   // de cruces a hacer en cada generación (esperanza matemática)
   int crossNumber = crossProb * (originalP.size());
   Population newP = originalP; // a copy of the original

   // We will cross the first crossNumber pairs
   for (int i = 0; i < crossNumber; i+=2) {
      const Solution s1 = originalP[i];
      const Solution s2 = originalP[i+1];
      Solution son1(s1.n);
      Solution son2(s1.n);

      // Aquellas posiciones que contengan el mismo valor en 
      // ambos padres se mantienen en el hijo.
      // Las asignaciones restantes se seleccionan en un orden
      // aleatorio para completar el hijo
      bool equals[s1.n] = {false};
      vector<int> nonEquals;
      
      // Check which gens are equals and which are not
      for (int j = 0; j < s1.n; j++) {
         if (s1.solutionRep[j] == s2.solutionRep[j]) {
            son1.solutionRep[j] = s1.solutionRep[j];
            son2.solutionRep[j] = s1.solutionRep[j];
            equals[j] = true;
         } else {
            nonEquals.push_back(s1.solutionRep[j]);
         }
      }

      // Shuffle nonEquals vector and put each value on son where
      // parents values werent equal
      random_shuffle(nonEquals.begin(), nonEquals.end());
      for (int j = 0, k = 0; j < son1.n; j++) {
         if (!equals[j]) {
            son1.solutionRep[j] = nonEquals[k];
            son2.solutionRep[j] = nonEquals[nonEquals.size()-1-k];
            k++;
         }
      }

      newP[i] = son1;
      newP[i+1] = son2;
   }
   
   return newP;
}

Population CrossOX(const Population& originalP, double crossProb) {
   // n vez de generar un aleatorio u en [0,1] para cada pareja
   // y cruzarla si u <= Pc , se estima a priori el número
   // de cruces a hacer en cada generación (esperanza matemática)
   int crossNumber = crossProb * (originalP.size());
   Population newP = originalP; // a copy of the original

   // We will cross the first crossNumber pairs
   for (int i = 0; i < crossNumber; i+=2) {
      const Solution* s1 = &originalP[i];
      const Solution* s2 = &originalP[i+1];
      Solution son1(s1->n);
      Solution son2(s1->n);

      // Aquellas posiciones que contengan el mismo valor en 
      // ambos padres se mantienen en el hijo.
      // Las asignaciones restantes se seleccionan en un orden
      // aleatorio para completar el hijo
      bool equals[s1->n] = {false};
      vector<int> nonEquals;
      
      // Check which gens are equals and which are not
      for (int j = 0; j < s1->n; j++) {
         if (s1->solutionRep[j] == s2->solutionRep[j]) {
            son1.solutionRep[j] = s1->solutionRep[j];
            son2.solutionRep[j] = s1->solutionRep[j];
            equals[j] = true;
         } else {
            nonEquals.push_back(s1->solutionRep[j]);
         }
      }

      // Shuffle nonEquals vector and put each value on son where
      // parents values werent equal
      random_shuffle(nonEquals.begin(), nonEquals.end());
      for (int j = 0, k = 0; j < son1.n; j++) {
         if (!equals[j]) {
            son1.solutionRep[j] = nonEquals[k];
            son2.solutionRep[j] = nonEquals[nonEquals.size()-1-k];
            k++;
         }
      }

      newP[i] = son1;
      newP[i+1] = son2;
   }

   return newP;
}

Population CrossPMX(const Population& originalP, double crossProb) {   
   int crossNumber = crossProb * (originalP.size());
   Population newP = originalP; // a copy of the original
   double step = originalP[0].n / 3;
   int start = floor(step);
   int end = floor(step) + ceil(step);

   for (int i = 0; i < crossNumber; i+=2) {
      Solution son1 = originalP[i];
      Solution son2 = originalP[i+1];
      
      // We will change the solutions
      son1.score = son2.score = -1;

      // Swap central position of sons
      for(int j = start; j <= end; j++) {
         
         // Find the son2[j] in son1 and change it by son1[j]
         for (int k = 0; k < son1.n; k++) {
            if (k == start) { // We wont change center
               k = end;
               continue;
            }  

            if (son1.solutionRep[k] == originalP[i+1].solutionRep[j]) {
               son1.solutionRep[k] = originalP[i].solutionRep[j];
               break;
            }
         }

         // Find the son1[j] in son2 and change it by son2[j]
         for (int k = 0; k < son2.n; k++) {
            if (k == start) {
               k = end;
               continue;
            }

            if (son2.solutionRep[k] == originalP[i].solutionRep[j]) {
               son2.solutionRep[k] = originalP[i+1].solutionRep[j];
               break;
            }
         }

         // Swap them
         int tmp = son1.solutionRep[j];
         son1.solutionRep[j] = son2.solutionRep[j];
         son2.solutionRep[j] = tmp;
      }

      newP[i] = son1;
      newP[i+1] = son2;
   }

   return newP;
}