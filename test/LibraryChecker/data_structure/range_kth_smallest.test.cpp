#define PROBLEM "https://judge.yosupo.jp/problem/range_kth_smallest"

#include "../../../template/template.hpp"
#include "../../../data_structure/wavelet_matrix.hpp"

int N, Q;
int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    cin >> N >> Q;
    vector<int> A(N);
    rep (i, N) cin >> A[i];
    wavelet_matrix wm(A);
    rep (i, Q) {
        int l, r, x;
        cin >> l >> r >> x;
        cout << wm.kth_max(l, r, r - l - x - 1) << '\n';
    }
}