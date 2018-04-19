#include "agg.hpp"
#include <cstdlib>
#include <algorithm>

// Binary tounament
GeneticAlg::Population AGG::Select(Population originalP) {
   Population newP(originalP.size());

   for (int i = 0; i < newP.size(); i++) {
      int rnd1 = rand() % newP.size();
      int rnd2 = rand() % newP.size();

      Solution* s1 = &originalP[rnd1];
      Solution* s2 = &originalP[rnd2];

      if (s1->score == -1) s1->CalcCost(this->distances, this->frequencies);
      if (s2->score == -1) s2->CalcCost(this->distances, this->frequencies);

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
   Population newP(originalP); // a copy of the original

   // We will cross the first crossNumber pairs
   for (int i = 0; i < crossNumber; i+=2) {
      Solution* s1 = &originalP[i];
      Solution* s2 = &originalP[i+1];
      Solution son(s1->n);

      // Aquellas posiciones que contengan el mismo valor en 
      // ambos padres se mantienen en el hijo.
      // Las asignaciones restantes se seleccionan en un orden
      // aleatorio para completar el hijo
      bool equals[s1->n] = {false};
      vector<int> nonEquals;
      
      // Check which gens are equals and which are not
      for (int j = 0; j < s1->n; j++) {
         if (s1->solutionRep[j] = s2->solutionRep[j]) {
            equals[j] = true;
            son.solutionRep[j] = s1->solutionRep[j];
         } else {
            nonEquals.push_back(s1->solutionRep[j]);
         }
      }

      // Shuffle nonEquals vector and put each value on son where
      // parents values werent equal
      random_shuffle(nonEquals.begin(), nonEquals.end());
      for (int j, k = 0; j < son.n; j++) {
         if (!equals[j]) {
            son.solutionRep[j] = nonEquals[k];
            k++;
         }
      }

      // TODO: Is it right????? maybe we should create another son with other random nonEquals
      newP[i] = son;
      newP[i+1] = son;  
   }

   return newP;
}

GeneticAlg::Population AGG::Mutate(Population originalP) {
   Population newP(originalP);
   int mutationNumber = this->mutationProb * newP.size() * newP[0].n;

   // We will mutate the first mutationNumber cromosomes
   for (int i = 0; i < mutationNumber; i++) {
      int rnd1 = rand() % newP.size();
      int rnd2 = rand() % newP.size();

      Solution originalSolution(newP[i]); // Make a copy to CalcRelativeCost
      
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

}