#define PROBLEM "https://judge.yosupo.jp/problem/stern_brocot_tree"

#include "../../template/template.hpp"
#include "../../math/stern_brocot_tree.hpp"

ll k, a, b, c, d;
int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int T;
    cin >> T;
    while (T--) {
        string S;
        cin >> S;
        char s = S[0];
        if (s == 'E') {
            cin >> a >> b;
            auto x = stern_brocot_tree<ll>::encode_path(a, b);
            k = x.size() - (x[0] == 0);
            cout << k;
            bool isleft = true;
            fore (u, x) {
                isleft = !isleft;
                if (u == 0) continue;
                cout << ' ' << (isleft ? 'L' : 'R') << ' ' << u;
            }
            cout << '\n';
        } else if (s == 'D') {
            cin >> k;
            vector<ll> x;
            rep (i, k) {
                char lr;
                int u;
                cin >> lr >> u;
                if (i == 0 && lr == 'L') x.emplace_back(0);
                x.emplace_back(u);
            }
            auto [p, q, r, s] = stern_brocot_tree<ll>::decode_path(x);
            cout << p + r << ' ' << q + s << '\n';
        } else if (s == 'L') {
            cin >> a >> b >> c >> d;
            auto [p, q, r, s] = stern_brocot_tree<ll>::lca(a, b, c, d);
            cout << p + r << ' ' << q + s << '\n';
        } else if (s == 'A') {
            cin >> k >> a >> b;
            auto [p, q, r, s] = stern_brocot_tree<ll>::ancestor(k, a, b);
            if (max({p, q, r, s}) == 0) cout << -1 << '\n';
            else cout << p + r << ' ' << q + s << '\n';
        } else if (s == 'R') {
            cin >> a >> b;
            auto [f, g, h, k] = stern_brocot_tree<ll>::range(a, b);
            cout << f << ' ' << g << ' ' << h << ' ' << k << '\n';
        }
    }
}