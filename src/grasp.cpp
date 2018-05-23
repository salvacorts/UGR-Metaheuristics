#include "grasp.hpp"
#include <random>

Solution RandomizedGreedy::Solve() {
   // th = d_max - alpha · (d_max – d_min)   Less is better
   double distancesThreshold = this->clDistances.rbegin()->second - this->alpha * (this->clDistances.rbegin()->second - this->clDistances.begin()->second);
   
   // th = d_min - alpha · (d_max – d_min)   Higher is better
   double frequenciesThreshold = this->clDistances.begin()->second - this->alpha * (this->clDistances.rbegin()->second - this->clDistances.begin()->second);

   Solution partialSolution(this->distances.size());
   auto randInRange = [](int min, int max) {
      return min + (rand() % (max - min - 1));
   };

   // Select two diferent items
   int urnd1 = randInRange(frequenciesThreshold, clFrequencies.size());
   int lrnd1 = randInRange(0, frequenciesThreshold);


}