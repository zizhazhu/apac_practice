#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>

using namespace std;

ifstream fin("B-large-practice.in");
ofstream fout("B-large-practice.out");

struct frac {
    long long nume;
    long long deno;
    long long gcd(long long a, long long b) {
        return a % b ? gcd(b, a % b) : b;
    }
    void reduc() {
        long long c = gcd(nume, deno);
        nume /= c;
        deno /= c;
    }
    frac(long long a, long long b) {
        nume = a;
        deno = b;
    }
    bool operator<(const frac& b) const {
        return (double)nume / (double)deno < (double)b.nume / (double)b.deno;
    }
};

void Solve() {
    int np, ne, nt, m;
    fin >> np >> ne >> nt;
    vector<long long> pedals(np), extras(ne), tires(nt);
    vector<frac> chain;
    multimap<frac, long long> tirechain;
    for (int i = 0; i < np; i++) {
        fin >> pedals[i];
    }
    for (int i = 0; i < ne; i++) {
        fin >> extras[i];
    }
    for (int i = 0; i < nt; i++) {
        fin >> tires[i];
    }
    for (int i = 0; i < np; i++) {
        for (int j = 0; j < ne; j++) {
            chain.push_back(frac(pedals[i], extras[j]));
        }
    }
    for (int i = 0; i < ne; i++) {
        for (int j = 0; j < nt; j++) {
            frac t(extras[i], tires[j]);
            t.reduc();
            tirechain.insert(make_pair(t, extras[i]));
        }
    }
    fin >> m;
    for (int i = 0; i < m; i++) {
        long long a, b;
        fin >> a >> b;
        frac f(a, b);
        f.reduc();
        bool flag = true;
        for (int j = 0; j < chain.size(); j++) {
            frac t(f.nume * chain[j].deno, f.deno * chain[j].nume);
            long long l = chain[j].deno;
            t.reduc();
            int n = tirechain.count(t);
            if (n > 0) {
                auto it = tirechain.find(t);
                for (int k = 0; k < n; k++, it++) {
                    if (l != it->second) {
                        fout << "Yes" << endl;
                        flag = false;
                        break;
                    }
                }
            }
            if (!flag) {
                break;
            }
        }
        if (flag) {
            fout << "No" << endl;
        }
    }
}

int main() {
    int Case;
    fin >> Case;
    for (int i = 1; i <= Case; i++) {
        fout << "Case #" << i << ":" << endl;
        Solve();
    }
    return 0;
}