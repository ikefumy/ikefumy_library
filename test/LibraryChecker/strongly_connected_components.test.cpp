#define PROBLEM "https://judge.yosupo.jp/problem/scc"

#include "../../template/template.hpp"
#include "../../graph/strongly_connected_components.hpp"

int N, M;
vector<int> cs[500010];
int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    cin >> N >> M;
    strongly_connected_components g(N);
    rep (i, M) {
        int a, b;
        cin >> a >> b;
        g.add_edge(a, b);
    }

    int tp = g.build();
    rep (i, N) {
        cs[g.get_cmp(i)].emplace_back(i);
    }

    cout << tp << '\n';
    rep (i, tp) {
        cout << cs[i].size();
        for (auto&& u : cs[i]) cout << ' ' << u;
        cout << '\n';
    } 
}