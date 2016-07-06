#include <iostream>
#include <fstream>
#include <vector>
#include <set>

using namespace std;

const int MAX = 2000000;

ifstream fin("C-small-practice.in");
ofstream fout("C-small-practice.out");

set<int> Solve() {
    set<int> ine;
    int n, m;
    fin >> n >> m;
    for (int i = 0; i < m; i++) {
        ine.insert(i);
    }
    vector<vector<int>> Graph(n, vector<int>(n, MAX));
    vector<int[3]> inf(m);
    for (int i = 0; i < n; i++) {
        Graph[i][i] = 0;
    }
    for (int i = 0; i < m; i++) {
        int u, v, c;
        fin >> u >> v >> c;
        inf[i][0] = u, inf[i][1] = v, inf[i][2] = c;
        if (c < Graph[u][v]) {
            Graph[u][v] = c;
            Graph[v][u] = c;
        }
    }
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (Graph[i][j] > Graph[i][k] + Graph[k][j]) {
                    Graph[i][j] = Graph[i][k] + Graph[k][j];
                }
            }
        }
    }
    for (int i = 0; i < m; i++) {
        int u = inf[i][0], v = inf[i][1], c = inf[i][2];
        if (Graph[u][v] == c) {
            ine.erase(i);
        }
    }
    return ine;
}

int main() {
    int n;
    fin >> n;
    for (int i = 1; i <= n; i++) {
        fout << "Case #" << i << ":" << endl;
        set<int> r = Solve();
        for (auto& p : r) {
            fout << p << endl;
        }
    }
    return 0;
}
