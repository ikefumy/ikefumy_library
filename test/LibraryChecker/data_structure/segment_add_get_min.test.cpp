#define PROBLEM "https://judge.yosupo.jp/problem/segment_add_get_min"

#include "../../template/template.hpp"
#include "../../data_structure/li_chao_tree.hpp"

ll N, Q, q, l, r, a, b, p;
int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    cin >> N >> Q;
    dynamic_li_chao_tree<ll, linf> dlct(-inf, inf);
    rep (i, N) {
        cin >> l >> r >> a >> b;
        dlct.add_seg(a, b, l, r);
    }

    rep (_, Q) {
        cin >> q;
        if (q) {
            cin >> p;
            ll ans = dlct.get_min(p);
            if (ans == linf) cout << "INFINITY\n";
            else cout << ans << '\n';
        } else {
            cin >> l >> r >> a >> b;
            dlct.add_seg(a, b, l, r);
        }
    }
}