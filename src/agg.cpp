#include "agg.hpp"
#include <cmath>
#include <cstdlib>
#include <algorithm>

// TODO: Si no tengo ordenada la poblacion, y estoy haciendo
// que crucen y muten los primeros, puede que los mejores se queden abajo?

// Binary tounament
Population AGG::Select(const Population& originalP) {
   Population newP(originalP.size());

   for (int i = 0; i < newP.size(); i++) {
      int rnd1 = rand() % newP.size();
      int rnd2 = rand() % newP.size();

      Solution s1 = originalP[rnd1];
      Solution s2 = originalP[rnd2];

      if (s1.score == -1) {
         s1.CalcCost(this->distances, this->frequencies);
         this->evals++;
      } 

      if (s2.score == -1) {
         s2.CalcCost(this->distances, this->frequencies);
         this->evals++;
      } 
      
      if (s1.score <= s2.score) {
         newP[i] = s1;
      } else {
         newP[i] = s2;
      }
   }

   return newP;
}

Population AGG::Replace(const Population& originalP, Population& toReplaceP) {   
   Population newP = toReplaceP;
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


