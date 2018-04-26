#include "agg.hpp"
#include <cmath>
#include <cstdlib>
#include <algorithm>

// TODO: Si no tengo ordenada la poblacion, y estoy haciendo
// que crucen y muten los primeros, puede que los mejores se queden abajo?

// Binary tounament
GeneticAlg::Population AGG::Select(Population originalP) {
   Population newP(originalP.size());

   for (int i = 0; i < newP.size(); i++) {
      int rnd1 = rand() % newP.size();
      int rnd2 = rand() % newP.size();

      Solution* s1 = &originalP[rnd1];
      Solution* s2 = &originalP[rnd2];

      if (s1->score == -1) {
         s1->CalcCost(this->distances, this->frequencies);
         this->evals++;
      } 

      if (s2->score == -1) {
         s2->CalcCost(this->distances, this->frequencies);
         this->evals++;
      } 
      
      if (s1->score <= s2->score) {
         newP[i] = *s1;
      } else {
         newP[i] = *s2;
      }
   }

   return newP;
}

GeneticAlg::Population AGG::Cross(Population originalP) {
   // n vez de generar un aleatorio u en [0,1] para cada pareja
   // y cruzarla si u <= Pc , se estima a priori el número
   // de cruces a hacer en cada generación (esperanza matemática)
   int crossNumber = this->crossProb * (originalP.size());
   Population newP = originalP; // a copy of the original

   // We will cross the first crossNumber pairs
   for (int i = 0; i < crossNumber; i+=2) {
      Solution* s1 = &originalP[i];
      Solution* s2 = &originalP[i+1];
      Solution son1(s1->n);
      Solution son2(s1->n);

      // We will change the solutions
      son1.score = son2.score = -1;

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

      // TODO: Is it right????? maybe we should create another son with other random nonEquals
      newP[i] = son1;
      newP[i+1] = son2;
   }
   return newP;
}

GeneticAlg::Population AGG::Mutate(Population originalP) {
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

GeneticAlg::Population AGG::Replace(Population originalP) {   
   Population newP = originalP;
   int worst_score, worst_index;
   worst_score = worst_index = 0;

   // Keep the best solution in the poblation
   if (this->bestSolution != NULL) {

      for (int i = 0; i < newP.size(); i++) {
         if (newP[i].score == -1) {
            newP[i].CalcCost(distances, frequencies);
            this->evals++;
         }

         if (worst_score < newP[i].score) {
            worst_score = newP[i].score;
            worst_index = i;
         }
      }

      newP[worst_index] = *(this->bestSolution);
   }

   return newP;
}

GeneticAlg::Population AGG_PMX::Cross(Population originalP) {   
   int crossNumber = this->crossProb * (originalP.size());
   double step = originalP[0].n / 3;
   int start = floor(step);
   int end = floor(step) + ceil(step);
   Population newP = originalP; // a copy of the original

   for (int i = 0; i < crossNumber; i+=2) {
      Solution son1(originalP[i]);
      Solution son2(originalP[i+1]);
      
      // We will change the solutions
      son1.score = son2.score = -1;

      // Swap central position of sons
      for(int j = start; j < end; j++) {
         
         // Find the son2[j] in son1 and change it by son1[j]
         for (int k = 0; k < son1.n; k++) {
            if (k == start) { // We wont change center
               k = end;
               continue;
            }  

            if (son1.solutionRep[k] == son2.solutionRep[j]) {
               son1.solutionRep[k] = son1.solutionRep[j];
            }
         }

         // Find the son1[j] in son2 and change it by son2[j]
         for (int k = 0; k < son2.n; k++) {
            if (k == start) {
               k = end;
               continue;
            }

            if (son2.solutionRep[k] == son1.solutionRep[j]) {
               son2.solutionRep[k] = son2.solutionRep[j];
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
