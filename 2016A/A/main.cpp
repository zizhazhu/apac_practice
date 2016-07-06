#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("A-large-practice.in");
ofstream fout("A-large-practice.out");

int Solve(unsigned long long k) {
    int flag = 0;
    while (k) {
        if (k == 1 || k == 2) {
            return flag;
        }
        if (((k - 1) & k) == 0) {
            return flag;
        }
        unsigned long long t = k, n = 0;
        while (t) {
            t >>= 1;
            n++;
        }
        k = (1ull << n) - k;
        flag = !flag;
    }
    return flag;
}

int main() {
    int n;
    fin >> n;
    for (int i = 1; i <= n; i++) {
        unsigned long long t;
        fin >> t;
        fout << "Case #" << i << ": " << Solve(t) << endl;
    }
    return 0;
}