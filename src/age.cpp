#include "age.hpp"
#include <climits>

Population AGE::Select(const Population& originalP) {
   Population newP(2);

   for (int i = 0; i < newP.size(); i++) {
      int rnd1 = rand() % originalP.size();
      int rnd2 = rand() % originalP.size();

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

Population AGE::Replace(const Population& originalP, Population& toReplaceP) {
   Population newP = originalP;
   int worst_score, worst_index;
   int best_score, best_index;
   worst_score = worst_index = 0;
   best_score = INT_MAX;

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

      for (int i = 0; i < toReplaceP.size(); i++) {
         if (toReplaceP[i].score == -1) {
            toReplaceP[i].CalcCost(distances, frequencies);
            this->evals++;
         }

         if (best_score > toReplaceP[i].score) {
            best_score =  toReplaceP[i].score;
            best_index = i;
         }
      }

      newP[worst_index] = Solution(toReplaceP[best_index]);
   }

   return newP;
}