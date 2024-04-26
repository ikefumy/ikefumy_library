#define PROBLEM "https://judge.yosupo.jp/problem/enumerate_quotients"

#include "../../../template/template.hpp"
#include "../../../math/quotient_range.hpp"

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    ll n;
    cin >> n;
    auto qr = quotient_range(n);
    cout << qr.size() << '\n';
    reverse(all(qr));
    for (auto [l, r, q] : qr) cout << q << ' ';
    cout << '\n';
}