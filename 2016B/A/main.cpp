#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <set>
#include <c++/queue>

using namespace std;

const int MAX = 2000000;

ifstream fin("A-small-practice.in");
ofstream fout("A-small-practice.out");

struct pNode {
    int no;
    int p;
    pNode(int ino, int ip) : no(ino), p(ip) {}
    bool operator<(const pNode &b) const {
        return p > b.p;
    }
};

void Dijkstra(int s, map<int, map<int, int>> &graph) {
    set<int> S;
    priority_queue<pNode> Q;
    S.insert(s);
    for (auto &next : graph[s]) {
        pNode n(next.first, next.second);
        Q.push(n);
    }
    while (!Q.empty()) {
        pNode now = Q.top();
        Q.pop();
        if (S.count(now.no)) {
            continue;
        }
        S.insert(now.no);
        for (auto &next : graph[now.no]) {
            pNode v(next.first, now.p + next.second);
            Q.push(v);
        }
        graph[s][now.no] = now.p;
    }
}

vector<int> Solve() {
    vector<int> result;
    int n, m, K;
    fin >> n >> m >> K;
    n++;
    map<int, map<int, int>> graph;
    for (int i = 0; i < m; i++) {
        int from, to;
        fin >> from >> to;
        for (int j = 0; j < 24; j++) {
            int t;
            fin >> t;
            graph[from * 24 + j][to * 24 + (j + t) % 24] = t;
            graph[to * 24 + j][from * 24 + (j + t) % 24] = t;
        }
    }
    for (int i = 0; i < 24; i++) {
        Dijkstra(24 + i, graph);
    }
    for (int i = 0; i < K; i++) {
        int d, s;
        fin >> d >> s;
        int Min = MAX;
        for (int j = 0; j < 24; j++) {
            if (graph[24 + s].find(24 * d + j) != graph[24+s].end() && Min > graph[24+s][24*d+j]) {
                Min = graph[24 + s][24 * d + j];
            }
        }
        if (Min == MAX) {
            result.push_back(-1);
        } else {
            result.push_back(Min);
        }
    }
    return result;
}

int main() {
    int Case;
    fin >> Case;
    for (int i = 1; i <= Case; i++) {
        fout << "Case #" << i << ":";
        vector<int> r = Solve();
        for (auto &p : r) {
            fout << ' ' << p;
        }
        fout << endl;
    }
    return 0;
}