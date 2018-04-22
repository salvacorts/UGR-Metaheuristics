#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <chrono>
#include "greedy.hpp"
#include "localSearch.hpp"
#include "localSearchDLB.hpp"
#include "genetic.hpp"
#include "agg.hpp"
#include "age.hpp"

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
    Solution solution;
    string line;
    int n;

    if (argc < 2) {
        cerr << "[!] Missing parameter" << endl;
        cout << "Usage: " << argv[0] << " <input_file> <seed>" << endl;
        cout << "\tNote: <seed> is optional" << endl;
        return 1;
    }

    // Initialize seed from parameter
    if (argc == 3) srand(atoi(argv[2]));
    else srand(7);

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
        make_pair("AGG OX", new AGG(distances, frequencies, 50, 0.7, 0.001, 50000))
    };

    for (auto& solver : solvers) {
        auto start = high_resolution_clock::now();
        Solution solution = solver.second->Solve();
        auto finish = high_resolution_clock::now();
        duration<double> elapsed = finish - start;

        cout << solver.first << "\t\tElapsed: " << elapsed.count() << " s" << endl;
        cout << solution << endl;
        cout << "Valid: " << solution.isValid() << endl << endl;
    }

    return 0;
}
