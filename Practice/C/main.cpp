#include <fstream>
#include <iostream>
using namespace std;

ifstream fin("C-large-practice.in");

double Solve() {
    double r;
    int n, x, k;
    double a, b, c;
    fin >> n >> x >> k >> a >> b >> c;
    a /= 100;
    b /= 100;
    c /= 100;
    double one[8] = {1, 0, a, b + c, a, b + c, c, a + b};
    double f[8] = {1, 0, a, b + c, a, b + c, c, a + b};
    for (int i = 1; i < n; i++) {
        double g[8];
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                for (int l = 0; l < 2; l++) {
                    g[j*4+k*2+l] = f[j*4+k*2+0] * one[k*2+l] + f[j*4+k*2+1] * one[4+k*2+l];
                }
            }
        }
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                for (int l = 0; l < 2; l++) {
                    int no = j * 4 + k * 2 + l;
                    f[no] = g[no];
                }
            }
        }
    }
    int tx = x, tk = k;
    int mi = 1;
    while (tx || tk) {
        int p = tx & 1, q = tk & 1;
        r += f[p*4+q*2+1] * mi;
        mi <<= 1;
        tx >>= 1;
        tk >>= 1;
    }
    return r;
}

int main() {
    FILE *fp = fopen("output.txt", "w");
    int n;
    fin >> n;
    for (int Case = 1; Case <= n; Case++) {
        double temp = Solve();
        fprintf(fp, "Case #%d: %.10lf\n", Case, temp);
    }
    fclose(fp);
    return 0;
}
