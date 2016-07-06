#include <iostream>
#include <fstream>
#include <c++/cmath>

using namespace std;

ifstream fin("B-large-practice.in");
ofstream fout("B-large-practice.out");

int Solve() {
    int n, m;
    int dimen[1000];
    double logdimen[1001];
    fin >> n >> m;
    for (int i = 0; i < n; i++) {
        fin >> dimen[i];
    }
    logdimen[0] = 0;
    for (int i = 1; i <= n; i++) {
        logdimen[i] = logdimen[i-1] + log(dimen[i-1]);
    }
    int a, b;
    fout.precision(10);
    for (int i = 0; i < m; i++) {
        fin >> a >> b;
        fout << exp((logdimen[b+1] - logdimen[a]) / (b - a + 1)) << endl;
    }
}

int main() {
    int n;
    fin >> n;
    for (int i = 1; i <= n; i++) {
        fout << "Case #" << i << ":" << endl;
        Solve();
    }
    return 0;
}