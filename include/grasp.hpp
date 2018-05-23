#include "solver.hpp"
#include <vector>
#include <set>

#ifndef GRASP__H
#define GRASP__H

class RandomizedGreedy : public  Solver {
protected:
   struct PairComparer {
      inline bool operator()(pair<int, int>& a, pair<int, int>& b) {
         return a.second < b.second;
      }
   };

   multiset<pair<int, int>, PairComparer> clFrequencies;
   multiset<pair<int, int>, PairComparer> clDistances;
   multiset<pair<int, int>, PairComparer > rclFrequencies;
   multiset<pair<int, int>, PairComparer > rclDistances;  
   double alpha; 
   

public:

   RandomizedGreedy(vector<vector<int> >& distances, vector<vector<int> >& frequencies, double alpha)
   : Solver(distances, frequencies) {
      this->alpha = alpha;

      // Calc potentials
      for (int i = 0; i < frequencies.size(); ++i) {
         int fi = 0, di = 0;

         for (int j = 0; j < frequencies.size(); ++j) {
            fi += this->frequencies[i][j];
            di += this->distances[i][j];
         }

         this->clFrequencies.insert(make_pair(i, fi));
         this->clDistances.insert(make_pair(i, fi));
      } 
   }

   Solution Solve() override;
};

class GRASP : public Solver {
protected:
   RandomizedGreedy* rndGreedy;

public:
   GRASP(vector<vector<int> >& distances, vector<vector<int> >& frequencies, double alpha)
   : Solver(distances, frequencies) {
      this->rndGreedy = new RandomizedGreedy(distances, frequencies, alpha);
   }

   Solution Solve() override;
};

#endif