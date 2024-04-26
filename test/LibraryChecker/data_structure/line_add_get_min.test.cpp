#define PROBLEM "https://judge.yosupo.jp/problem/line_add_get_min"

#include "../../template/template.hpp"
#include "../../data_structure/li_chao_tree.hpp"

ll N, Q, q, a, b, p;
int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    cin >> N >> Q;
    dynamic_li_chao_tree<ll, linf, 2000000> dlct(-inf, inf);
    rep (i, N) {
        cin >> a >> b;
        dlct.add_line(a, b);
    }

    rep (_, Q) {
        cin >> q;
        if (q) {
            cin >> p;
            cout << dlct.get_min(p) << '\n';
        } else {
            cin >> a >> b;
            dlct.add_line(a, b);
        }
    }
}