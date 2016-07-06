#include <fstream>
#include <vector>
#include <unordered_map>
using namespace std;

ifstream fin("B-large.in");
ofstream fout("B-large.out");

long long Solve() {
    long long r = 0;
    int n, k;
    fin >> n >> k;
    vector<int> a(n), c(n);
    unordered_map<int, int> f;
    for (int i = 0; i < n; i++) {
        fin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        int t;
        fin >> t;
        for (int j = 0; j < n; j++) {
            f[t^a[j]]++;
        }
    }
    for (int i = 0; i < n; i++) {
        fin >> c[i];
    }
    for (int i = 0; i < n; i++) {
        int t;
        fin >> t;
        for (int j = 0; j < n; j++) {
            int p = t ^ c[j];
            int q = k ^ p;
            if (f.find(q) != f.end()) {
                r += (long long)f[q];
            }
        }
    }
    return r;
}

int main() {
    int n;
    fin >> n;
    for (int Case = 1; Case <= n; Case++) {
        fout << "Case #" << Case << ": " << Solve() << endl;
    }
    return 0;
}
