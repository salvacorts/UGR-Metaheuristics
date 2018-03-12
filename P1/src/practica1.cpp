#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "greedy.hpp"
#include "localSearch.hpp"

using namespace std;

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


    if (argc != 3) {
        cerr << "[!] Missing parameter" << endl;
        cout << "Usage: " << argv[0] << " <input_file> <output_file>" << endl;
        return 1;
    }

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
    };

    for (auto& solver : solvers) {
        cout << solver.first << endl;
        cout << solver.second->Solve() << endl << endl;
    }

    return 0;
}
