#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
using namespace std;

ifstream fin("A-large-practice.in");
ofstream fout("A-large-practice.out");

struct entry {
    string name;
    int score;
    entry(string iname, int iscore) : name(iname), score(iscore) {}
    bool operator<(const entry &b) const {
        if (score == b.score) {
            return name.compare(b.name) < 0;
        }
        return score > b.score;
    }
};

vector<entry> Solve() {
    int P, N, M;
    fin >> P;
    vector<int> scores(P);
    map<string, priority_queue<int>> tables;
    for (int i = 0; i < P; i++) {
        fin >> scores[i];
    }
    fin >> N;
    for (int i = 0; i < N; i++) {
        int w;
        fin >> w;
        for (int j = 0; j < P; j++) {
            string name;
            fin >> name;
            tables[name].push(w * scores[j]);
        }
    }
    fin >> M;
    vector<entry> rank;
    for (auto& each : tables) {
        string name = each.first;
        int sum = 0;
        for (int i = 0; i < M && !each.second.empty(); i++) {
            sum += each.second.top();
            each.second.pop();
        }
        rank.push_back(entry(name, sum));
    }
    sort(rank.begin(), rank.end());
    return rank;
}

int main() {
    int Case;
    fin >> Case;
    for (int i = 1; i <= Case; i++) {
        fout << "Case #" << i << ":" << endl;
        vector<entry> result = Solve();
        int j = 0, acc = 1;
        int last = -1;
        for (auto& each : result) {
            if (each.score == last) {
                acc++;
            } else {
                last = each.score;
                j += acc;
                acc = 1;
            }
            fout << j << ": " << each.name << endl;
        }
    }
    return 0;
}
