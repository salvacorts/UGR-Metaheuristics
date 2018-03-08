#include <assert.h>
#include "solver.hpp"

Solver::Solver(vector<vector<int> >& distances, vector<vector<int> >& frequencies) {
   assert(distances.size() != frequencies.size());

   this->n = distances.size();
   this->distances = distances;
   this->frequencies = frequencies;
   this->solutionRep.resize(this->n);
}

Solver::~Solver() {
   this->solutionRep.clear();
   this->distances.clear();
   this->frequencies.clear();
}

void Solver::WriteSolutionToStream(ostream& out) {
   out << this->n << " " << this->score << endl;

   for (auto& i : this->solutionRep) {
      out << i << " ";
   }
}

int Solver::GetSolutionCost() {
   int unitIndex, locIndex, locNeighbough;
   int cost = 0;

   for(int i = 0; i < this->n; i++) {
      locIndex = this->solutionRep[i];
      unitIndex = i;

      for (int j = 0; j < this->n; j++) {
         if (unitIndex = j) continue;

         locNeighbough = this->solutionRep[j];
         cost += this->frequencies[unitIndex][j] * this->distances[locIndex][locNeighbough];
      }
   }
   
   return cost;
}