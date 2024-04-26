#define PROBLEM "https://judge.yosupo.jp/problem/bipartitematching"

#include "../../../template/template.hpp"
#include "../../../graph/bipartite_graph_matching.hpp"

int L, R, M;
int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    cin >> L >> R >> M;
    bipartite_graph_matching bgm(L, R);
    rep (i, M) {
        int u, v;
        cin >> u >> v;
        bgm.add_edge(u, v);
    }

    auto ans = bgm.matching();
    cout << ans.size() << '\n';
    for (auto [l, r] : ans) {
        cout << l << ' ' << r << '\n';
    }
}