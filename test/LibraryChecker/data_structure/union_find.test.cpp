#define PROBLEM "https://judge.yosupo.jp/problem/unionfind"

#include "../../../template/template.hpp"
#include "../../../data_structure/union_find.hpp"

int N, Q;
int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    cin >> N >> Q;
    union_find uf(N);
    rep (i, Q) {
        int t, u, v;
        cin >> t >> u >> v;
        if (t) cout << uf.same(u, v) << '\n';
        else uf.unite(u, v);
    }
}