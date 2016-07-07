#include <iostream>
#include <fstream>
#include <set>
using namespace std;

ifstream fin("C-large-practice.in");
ofstream fout("C-large-practice.out");

set<long long> Prime;

bool isgNumber(long long n) {
    int sum = 0;
    while (n) {
        sum += n % 10;
        n /= 10;
    }
    if (Prime.count(sum) || sum == 1) {
        return true;
    } else {
        return false;
    }
}

bool Solve(long long c) {
    if (isgNumber(c)) {
        return false;
    }
    set<long long> factor;
    long long t = c;
    for (long long p : Prime) {
        if (p * p > c) {
            if (t != 1) {
                factor.insert(t);
            }
            break;
        }
        if (t % p == 0) {
            factor.insert(p);
            while (t % p == 0) {
                t /= p;
            }
        }
    }
    for (long long p : factor) {
        long long tt = c;
        if (tt % p == 0) {
            while (tt % p == 0) {
                tt /= p;
            }
            if (!Solve(tt)) {
                return true;
            }
        }
    }
    return false;
}

void PrimeGen() {
    bool *init = new bool[40000000];
    init[1] = true;
    for (int i = 2; i * i <= 40000000; i++) {
        if (!init[i]) {
            for (int j = 2; i * j <= 40000000; j++) {
                init[i*j] = true;
            }
        }
    }
    for (int i = 1; i <= 40000000; i++) {
        if (!init[i]) {
            Prime.insert(i);
        }
    }
    delete init;
}

int main() {
    PrimeGen();
    int Case;
    fin >> Case;
    for (int i = 1; i <= Case; i++) {
        long long t;
        fout << "Case #" << i << ": ";
        fin >> t;
        if (Solve(t)) {
            fout << "Laurence" << endl;
        } else {
            fout << "Seymour" << endl;
        }
    }
    return 0;
}