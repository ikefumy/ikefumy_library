#define PROBLEM "https://judge.yosupo.jp/problem/biconnected_components"

#include "../../template/template.hpp"
#include "../../graph/bi_connected_components.hpp"

int N, M;
int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    cin >> N >> M;
    bi_connected_components g(N);
    rep (i, M) {
        int a, b;
        cin >> a >> b;
        g.add_edge(a, b);
    }

    g.build();
    auto cs = g.get_comps();

    cout << cs.size() << '\n';
    for (auto&& c : cs) {
        cout << c.size();
        for (auto&& u : c) cout << ' ' << u;
        cout << '\n';
    }
}