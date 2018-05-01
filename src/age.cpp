#include "age.hpp"
#include <climits>
#include <set>

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

   auto iterLessCmp = [=](Population::iterator a, Population::iterator b) {
      return a->score < b->score;
   };

   auto worsts = set<Population::iterator, decltype(iterLessCmp)>(iterLessCmp);

   // search the worst of the original population
   for (auto it = newP.begin(); it != newP.end(); it++) {
      if (it->score == -1) {
         it->CalcCost(distances, frequencies);
         this->evals++;
      }

      if (worsts.empty() || it->score > (*worsts.begin())->score) {
         if (worsts.size() >= toReplaceP.size()) {
            worsts.erase(worsts.begin());
         }

         worsts.insert(it);
      }
   }

   // Replace the worst of the original by the sons if they are better
   for (int i = 0; i < toReplaceP.size(); i++) {
      if (toReplaceP[i].score == -1) {
         toReplaceP[i].CalcCost(distances, frequencies);
         this->evals++;
      }

      for (auto it = worsts.begin(); it != worsts.end(); it++) {
         if ((*it)->score > toReplaceP[i].score) {
            *(*it) = toReplaceP[i];
            worsts.erase(it);
         }
      }
   }

   return newP;
}