#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/1549"

#include "../../template/template.hpp"
#include "../../data_structure/wavelet_matrix.hpp"

int N, Q;
int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    cin >> N;
    vector<int> A(N);
    rep (i, N) cin >> A[i], A[i] += 1000000;
    A.push_back(2000000);
    wavelet_matrix wm(A);
    cin >> Q;
    rep (i, Q) {
        int l, r, x;
        cin >> l >> r >> x;
        r++;
        x += 1000000;
        int ans = inf;
        int pre = wm.prev_value(l, r, x);
        if (pre > 0) chmin(ans, x - pre);
        int nxt = wm.next_value(l, r, x);
        if (nxt > 0) chmin(ans, nxt - x);
        cout << ans << '\n';
    }
}