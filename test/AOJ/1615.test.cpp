#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/1615"

#include "../../template/template.hpp"
#include "../../graph/dinic.hpp"
#include "../../graph/max_flow_lb.hpp"

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int n, m;
    while (true) {
        cin >> n >> m;
        if (n == 0) break;
        vector<int> u(m), v(m);
        rep (i, m) cin >> u[i] >> v[i], u[i]--, v[i]--;
        int amn = 0, amx = inf;
        int mn = 0;
        rep (mx, 1, n + 1) {
            while (mn <= mx) {
                max_flow_lb<int> mfl(n + m + 2);
                int s = n + m, t = n + m + 1;
                rep (i, n) {
                    mfl.add_edge(m + i, t, mn, mx);
                }
                rep (i, m) {
                    mfl.add_edge(s, i, 0, 1);
                    mfl.add_edge(i, m + u[i], 0, 1);
                    mfl.add_edge(i, m + v[i], 0, 1);
                }
                if (mfl.max_flow(s, t) == m && mx - mn <= amx - amn) {
                    amx = mx, amn = mn;
                    mn++;
                } else {
                    break;
                }
            }
        }
        cout << amn << ' ' << amx << '\n';
    }
}