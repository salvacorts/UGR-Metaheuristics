#include "solver.hpp"

#ifndef SIM_ANEALING__H
#define SIM_ANEALING__H

enum CoolingTechnique {Cauchy, Proportional};

class SimulatedAnnealing : public Solver {
private:
   double CauchyCooling(double originalTemperature);
   double ProportionalCooling(double originalTemperature);

protected:
   CoolingTechnique coolingTechnique;
   int finalTemp;
   int maxEvals;
   int maxSuccess;
   int maxNeighbours;
   double acceptProb;
   double alpha;
   double beta;
   double mu;

   double CalculateInitialTemperature(Solution& initialSolution);
   double ApplyCooling(double originalTemperature);
   Solution RandomNeighbour(Solution& originalSolution);
   bool MetroposilAcceptCriteria(double scoreDifference, double temperature);

public:
   SimulatedAnnealing(vector<vector<int> >& distances, vector<vector<int> >& frequencies, int maxNeighbours, double maxSuccess, double finalTemp, double acceptProb, double mu, CoolingTechnique ct, int maxEvals=-1, double alpha=0.99)
   : Solver(distances, frequencies){
      this->maxNeighbours = maxNeighbours * distances.size();
      this->maxSuccess = maxSuccess * this->maxNeighbours;
      this->acceptProb = acceptProb;
      this->coolingTechnique = ct;
      this->finalTemp = finalTemp;
      this->maxEvals = maxEvals;
      this->alpha = alpha;
      this->mu = mu;

   }

   Solution Solve(Solution initialSolution);
   Solution Solve() override;
};

#endif