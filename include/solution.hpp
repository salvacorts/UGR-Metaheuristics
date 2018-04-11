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
   int CalcCost(vector<vector<int> >& distances, vector<vector<int> >& frequencies);
   friend ostream& operator<<(std::ostream& os, const Solution& sol);
};

ostream& operator<<(std::ostream& os, const Solution& sol);

#endif

