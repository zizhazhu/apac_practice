#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

ifstream fin("B-small-practice.in");
ofstream fout("B-small-practice.out");

long long Solve() {
    int N;
    fin >> N;
    long long left = 0, right = 1000000000000001;
    for (int i = 0; i < N; i++) {
        long long percentage, file;
        long long tleft, tright;
        fin >> percentage >> file;
        if (file == 0 && percentage == 0) {
            continue;
        }
        if (percentage == 100) {
            left = right = file;
            continue;
        }
        tleft = 100 * file / (percentage + 1) + 1;
        if (percentage != 0) {
            tright = 100 * file / percentage;
        } else {
            tright = 1000000000000001;
        }
        if (tleft > left) {
            left = tleft;
        }
        if (tright < right) {
            right = tright;
        }
    }
    if (right == left) {
        return right;
    } else {
        return -1;
    }
}

int main() {
    int Case;
    fin >> Case;
    for (int i = 1; i <= Case; i++) {
        fout << "Case #" << i << ":" << " ";
        fout << Solve() << endl;
    }
    return 0;
}
