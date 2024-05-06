#define PROBLEM "https://judge.yosupo.jp/problem/point_add_rectangle_sum"

#include "../../../template/template.hpp"
#include "../../../data_structure/BIT_on_wavelet_matrix.hpp"

using T = long long;

int N, Q, x[100010], y[100010], w[100010], q[100010], l[100010], d[100010], r[100010], u[100010];
int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    wavelet_matrix_2d<T> wm;
    cin >> N >> Q;
    rep (i, N) {
        cin >> x[i] >> y[i] >> w[i];
        wm.add_point(x[i], y[i]);
    }

    rep (i, Q) {
        cin >> q[i];
        if (q[i]) {
            cin >> l[i] >> d[i] >> r[i] >> u[i];
        } else {
            cin >> l[i] >> d[i] >> r[i];
            wm.add_point(l[i], d[i]);
        }
    }

    wm.build();
    rep (i, N) {
        wm.add(x[i], y[i], w[i]);
    }

    rep (i, Q) {
        if (q[i]) {
            cout << wm.get_sum(l[i], r[i], d[i], u[i]) << '\n';
        } else {
            wm.add(l[i], d[i], r[i]);
        }
    }
}