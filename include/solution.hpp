#include <vector>
#include <iostream>

using namespace std;


#ifndef SOLUTION_H
#define SOLUTION_H

class Solution {
public:
   int n;
   int score;
   vector<int> solutionRep;

   Solution(int n=0);
   Solution(const Solution& copy);
   int CalcCost(vector<vector<int> >& distances, vector<vector<int> >& frequencies);
   friend ostream& operator<<(std::ostream& os, const Solution& sol);

   static Solution GenerateRandomSolution(vector<vector<int> >& distances, vector<vector<int> >& frequencies);
};

ostream& operator<<(std::ostream& os, const Solution& sol);

#endif

