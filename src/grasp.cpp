#include "grasp.hpp"
#include <random>
#include <algorithm>
#include <climits>

Solution RandomizedGreedy::Solve() {
   vector<pair<int, int> > partialSolution;  // {(u1, l1), ..., (un, ln)}
   bool unitAsigned[frequencies.size()] = {false};
   bool locaAsigned[frequencies.size()] = {false};

   auto randInRange = [](int min, int max) {
      return min + (rand() % (max - min - 1));
   };

   auto pairCmp = [](pair<int, int>& a, pair<int, int>& b) {
      return a.second < b.second;
   };

   auto pairCmpBound = [](int val, pair<int, int> p) {
      return val <= p.second;
   };


   // Sort both candidates lists. O(nlogn)
   sort(this->clDistances.begin(), this->clDistances.end(), pairCmp);
   sort(this->clFrequencies.begin(), this->clFrequencies.end(), pairCmp);

   // th = d_min - alpha · (d_max – d_min)   Higher is better
   int frequenciesThreshold = floor(this->clFrequencies.begin()->second - this->alpha * (this->clFrequencies.rbegin()->second - this->clFrequencies.begin()->second));
   
   // th = d_max - alpha · (d_max – d_min)   Less is better
   int distancesThreshold = floor(this->clDistances.rbegin()->second - this->alpha * (this->clDistances.rbegin()->second - this->clDistances.begin()->second));
   
   // find upper bound index for frequencies threshold
   auto ubFreq = upper_bound(this->clFrequencies.begin(), this->clFrequencies.end(), frequenciesThreshold, pairCmpBound);
   auto ubDist = upper_bound(this->clDistances.begin(), this->clDistances.end(), distancesThreshold, pairCmpBound);

   int frequenciesThresholdIndex = ubFreq - clFrequencies.begin();
   int distancesThresholdIndex = ubDist - clDistances.begin();

   // Select two diferent items in each candidates lists
   int urnd1 = randInRange(frequenciesThresholdIndex, clFrequencies.size());
   int lrnd1 = randInRange(0, distancesThresholdIndex);
   int urnd2, lrnd2;

   do {
      urnd2 = randInRange(frequenciesThresholdIndex, clFrequencies.size());
   } while (urnd2 == urnd1);

   do {
      lrnd2 = randInRange(0, distancesThresholdIndex);
   } while (lrnd2 == lrnd1);


   // Add random selected to the partial solution and blacklist them
   partialSolution.push_back(make_pair(this->clFrequencies[urnd1].first, this->clDistances[lrnd1].first));
   partialSolution.push_back(make_pair(this->clFrequencies[urnd2].first, this->clDistances[lrnd2].first));
   unitAsigned[this->clFrequencies[urnd1].first] = locaAsigned[this->clDistances[lrnd1].first] = true;
   unitAsigned[this->clFrequencies[urnd2].first] = locaAsigned[this->clDistances[lrnd2].first] = true;


   //// STEP 2 ////
   // For the rest of pairs in the solution
   for (int i = 2; i < frequencies.size(); i++) {
      int bestCost = INT_MAX;
      pair<int, int> bestPair;

      // iterate through all units and locations (skiping them which already are inside partial solution)
      for (int u = 0; u < frequencies.size(); u++) {
         if (unitAsigned[u]) continue;

         for (int l = 0; l < distances.size(); l++) {
            if (locaAsigned[l]) continue;

            // Calc the relative cost of adding this pair to the partial solution
            int cost = 0;
            for (int j = 0; j < partialSolution.size(); j++) {
               cost += frequencies[u][partialSolution[j].first] * distances[l][partialSolution[j].second];
            }

            if (cost < bestCost) {
               bestCost = cost;
               bestPair = make_pair(u, l);
            }
         }
      }

      // Add the best combination of unit and location to the partial solution. Blacklist them
      partialSolution.push_back(bestPair);
      unitAsigned[bestPair.first] = locaAsigned[bestPair.second] = true;
   }


   // Build a real Solution from the partial solution
   Solution solution(partialSolution.size());

   for (int i = 0; i < partialSolution.size(); i++) {
      int unit = partialSolution[i].first;
      int location = partialSolution[i].second;

      solution.solutionRep[unit] = location;
   }

   solution.CalcCost(distances, frequencies);

   return solution;
}

Solution GRASP::Solve() {
   Solution* bestSolution = NULL;
   Solution* lsSolution = NULL;
   int evaluations = 0;

   for (int i = 0; i < this->maxIterations; i++) {
      Solution greedySolution = this->randomGreedy->Solve();
      lsSolution = this->LocalSearch->GenerateBestNeighbour(greedySolution, evaluations, this->maxLocalSearchEvals);

      if (lsSolution != NULL && (bestSolution == NULL || lsSolution->score < bestSolution->score)) {
         bestSolution = lsSolution;
      }
   }

   return *bestSolution;
}