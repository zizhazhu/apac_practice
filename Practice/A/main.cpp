#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

ifstream fin("A-large.in");
ofstream fout("A-large.out");

unsigned int point(char a, char b, char c) {
    if (a == b && a == c) {
        return 1;
    }
    if (a == b || a == c || b == c) {
        return 2;
    }
    return 3;
}

unsigned int Solve(string word) {
    int len = word.length();
    unsigned int result = 1;
    if (len == 1) {
        return result;
    }
    if (word[0] != word[1]) {
        result *= 2u;
    }
    for (int i = 1; i < len - 1; i++) {
        result *= point(word[i-1], word[i], word[i+1]);
        result %= 1000000007u;
    }
    if (word[len-2] != word[len-1]) {
        result *= 2u;
        result %= 1000000007u;
    }
    return result;
}

int main() {
    int n;
    fin >> n;
    for (int Case = 1; Case <= n; Case++) {
        string word;
        fin >> word;
        fout << "Case #" << Case << ": " << Solve(word) << endl;
    }
    return 0;
}