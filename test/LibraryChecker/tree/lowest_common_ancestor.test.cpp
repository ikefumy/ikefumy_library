#define PROBLEM "https://judge.yosupo.jp/problem/lca"

#include "../../../template/template.hpp"
#include "../../../tree/lowest_common_ancestor.hpp"

int N, Q, p, u, v;
int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    cin >> N >> Q;
    LCA lca(N);
    rep (i, 1, N) {
        cin >> p;
        lca.add_edge(i, p);
    }

    lca.build();
    rep (i, Q) {
        cin >> u >> v;
        cout << lca.get_lca(u, v) << '\n';
    }
}