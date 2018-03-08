#include <vector>
#include <iostream>

using namespace std;

class Solver {
protected:
   int n;
   int score;
   vector<int> solutionRep;
   vector<vector<int> > distances;
   vector<vector<int> > frequencies;

public:
   Solver(vector<vector<int> >& distances, vector<vector<int> >& frequencies);
   ~Solver();
   void WriteSolutionToStream(ostream& out);
   int GetSolutionCost();
   virtual void Solve() = 0;
};