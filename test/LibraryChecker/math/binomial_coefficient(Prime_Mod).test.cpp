#define PROBLEM "https://judge.yosupo.jp/problem/binomial_coefficient_prime_mod"

#include "../../template/template.hpp"
#include "../../math/modint.hpp"
#include "../../math/comb_perm.hpp"

int T, m;
int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    cin >>T >> m;
    mint::modulo = m;

    comb_perm cp(min(m - 1, 10000000));
    rep (i, T) {
        int n, k;
        cin >> n >> k;
        mint ans = 1;
        while (n > 0 || k > 0) {
            ans *= cp.comb(n % m, k % m);
            n /= m, k /= m;
        }
        cout << ans << '\n';
    }
}
