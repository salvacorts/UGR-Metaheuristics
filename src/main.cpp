#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <chrono>
#include "greedy.hpp"
#include "localSearch.hpp"
#include "genetic.hpp"
#include "memetic.hpp"
#include "agg.hpp"
#include "age.hpp"
#include "grasp.hpp"
#include "ils.hpp"
#include "multiStart.hpp"
#include "simAnealing.hpp"

using namespace std;
using namespace std::chrono;

// Read Input file. Format:
// n
//
// n*n matrix
//
// n*n matrix
void ReadMatrixFromStream(istream &input, vector<vector<int> > &m1, vector<vector<int> > &m2) {
    string line;
    int n;
    input >> n;

    // Resize distances matrix
    m1.resize(n);
    for (auto& v : m1) {
        v.resize(n);
    }

    // Resize frequencies matrix
    m2.resize(n);
    for (auto& v : m2) {
        v.resize(n);
    }

    // read blank line
    getline(input, line);

    // Read Distance matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            input >> m1[i][j];
        }
    }

    // read blank line
    getline(input, line);

    // Read Frequencies matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            input >> m2[i][j];
        }
    }
}

void WriteMatrixToStream(ostream& out, vector<vector<int> >& m1, vector<vector<int> >& m2) {
    out << m1.size() << endl;

    // Read Distance matrix
    for (int i = 0; i < m1.size(); i++) {
      for (int j = 0; j < m1.size(); j++) {
         out << m1[i][j] << " ";
      }
      out << endl;
    }

    out << endl;

    // Read Frequencies matrix
    for (int i = 0; i < m2.size(); i++) {
      for (int j = 0; j < m2.size(); j++) {
         out << m2[i][j] << " ";
      }
      out << endl;
    }
}

int main(int argc, char const* argv[]) {
    vector<vector<int> > distances;
    vector<vector<int> > frequencies;
    string line;
    int n, seed;

    if (argc < 2) {
        cerr << "[!] Missing parameter" << endl;
        cout << "Usage: " << argv[0] << " <input_file> <seed>" << endl;
        cout << "\tNote: <seed> is optional" << endl;
        return 1;
    }

    // Initialize seed from parameter
    if (argc == 3) seed = atoi(argv[2]);
    else seed = 7;

    // Open input file
    ifstream inputFile(argv[1]);
    if (!inputFile.is_open()) {
        cerr << "[!] Cannot open " << argv[1] << endl;
        return 1;
    }

    ReadMatrixFromStream(inputFile, distances, frequencies);
    inputFile.close();

    vector<pair<string, Solver*> > solvers = {
        make_pair("Greedy", new GreedySolver(distances, frequencies)),

        make_pair("Local Search", new LocalSearchSolver(distances, frequencies)),
        make_pair("Local Search (Dont Look Bit)", new LocalSearchSolverDLB(distances, frequencies)),

        make_pair("AGG", new AGG(distances, frequencies, 50, 0.7, 0.001, 50000)),
        make_pair("AGG OX", new AGG_OX(distances, frequencies, 50, 0.7, 0.001, 50000)),
        make_pair("AGG PMX", new AGG_PMX(distances, frequencies, 50, 0.7, 0.001, 50000)),
        
        make_pair("AGE", new AGE(distances, frequencies, 50, 0.001, 50000)),
        make_pair("AGE OX", new AGE_OX(distances, frequencies, 50, 0.001, 50000)),
        make_pair("AGE PMX", new AGE_PMX(distances, frequencies, 50, 0.001, 50000)),

        make_pair("AM(10, 1)", new MemeticAlg(distances, frequencies, 10, 0.7, 0.001, 50000, 10, 1, 400)),
        make_pair("AM(10, 0.1)", new MemeticAlg(distances, frequencies, 10, 0.7, 0.001, 50000, 10, 0.1, 400)),
        make_pair("AM(10, 0.1mej)", new MemeticAlg(distances, frequencies, 10, 0.7, 0.001, 50000, 10, 0.1, 400, true)),

        make_pair("Simulated Anealing (Cauchy)", new SimulatedAnnealing(distances, frequencies, 10, 0.1, 10e-3, 0.3, 0.3, CoolingTechnique::Cauchy, 50000)),
        make_pair("Simulated Anealing (Proportional)", new SimulatedAnnealing(distances, frequencies, 10, 0.1, 10e-3, 0.3, 0.3, CoolingTechnique::Proportional, 50000)),
        
        make_pair("Randomized Greedy", new RandomizedGreedy(distances, frequencies, 0.3)),
        make_pair("GRASP", new GRASP(distances, frequencies, 0.3, 25, 50000)),
        make_pair("Basic Multistart search", new MultiStartSearch(distances, frequencies, 25, 50000)),

         make_pair("Reiterated Local Search (ILS)", new ILS(distances, frequencies, 0.25, 25, 50000)),
        make_pair("ILS ES (Cauchy)", new ILS_SA(distances, frequencies, 0.25, 50, 10, 0.1, 10e-3, 0.3, 0.3, CoolingTechnique::Cauchy, 50000)),
        make_pair("ILS ES (Proportional)", new ILS_SA(distances, frequencies, 0.25, 50, 10, 0.1, 10e-3, 0.3, 0.3, CoolingTechnique::Proportional, 50000)),
    };

    for (auto& solver : solvers) {
        srand(seed);
        auto start = high_resolution_clock::now();
        Solution solution = solver.second->Solve();
        auto finish = high_resolution_clock::now();
        duration<double> elapsed = finish - start;

        cout << solver.first << "\t\tElapsed: " << elapsed.count() << " s" << endl;

        if (solution.isValid()) {
            cout << solution << endl;
        } else {
            cout << "[!] Invalid Solution" << endl;
        }

        cout << endl;

    }

    return 0;
}
