---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/comb_perm.hpp
    title: math/comb_perm.hpp
  - icon: ':heavy_check_mark:'
    path: math/modint.hpp
    title: math/modint.hpp
  - icon: ':question:'
    path: template/template.hpp
    title: template/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/binomial_coefficient_prime_mod
    links:
    - https://judge.yosupo.jp/problem/binomial_coefficient_prime_mod
  bundledCode: "#line 1 \"test/LibraryChecker/math/binomial_coefficient(Prime_Mod).test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/binomial_coefficient_prime_mod\"\
    \n\n#line 1 \"template/template.hpp\"\n#include<bits/stdc++.h>\nusing namespace\
    \ std;\n#define ll long long\n#define ull unsigned long long\n#define db double\n\
    #define pii pair<int,int>\n#define pli pair<ll,int>\n#define pil pair<int,ll>\n\
    #define pll pair<ll,ll>\n#define ti3 tuple<int,int,int>\n#define int128 __int128_t\n\
    #define pii128 pair<int128,int128>\nconst int inf = 1 << 30;\nconst ll linf =\
    \ (ll)4e18 + 10;\nconst db EPS = 1e-10;\nconst db pi = acos(-1);\ntemplate<class\
    \ T> bool chmin(T& x, T y){\n    if(x > y) {\n        x = y;\n        return true;\n\
    \    } else return false;\n}\ntemplate<class T> bool chmax(T& x, T y){\n    if(x\
    \ < y) {\n        x = y;\n        return true;\n    } else return false;\n}\n\n\
    // overload macro\n#define CAT( A, B ) A ## B\n#define SELECT( NAME, NUM ) CAT(\
    \ NAME, NUM )\n\n#define GET_COUNT( _1, _2, _3, _4, _5, _6 /* ad nauseam */, COUNT,\
    \ ... ) COUNT\n#define VA_SIZE( ... ) GET_COUNT( __VA_ARGS__, 6, 5, 4, 3, 2, 1\
    \ )\n\n#define VA_SELECT( NAME, ... ) SELECT( NAME, VA_SIZE(__VA_ARGS__) )(__VA_ARGS__)\n\
    \n// rep(overload)\n#define rep( ... ) VA_SELECT(rep, __VA_ARGS__)\n#define rep2(i,\
    \ n) for (int i = 0; i < int(n); i++)\n#define rep3(i, a, b) for (int i = a; i\
    \ < int(b); i++)\n#define rep4(i, a, b, c) for (int i = a; i < int(b); i += c)\n\
    \n// repll(overload)\n#define repll( ... ) VA_SELECT(repll, __VA_ARGS__)\n#define\
    \ repll2(i, n) for (ll i = 0; i < (ll)(n); i++)\n#define repll3(i, a, b) for (ll\
    \ i = a; i < (ll)(b); i++)\n#define repll4(i, a, b, c) for (ll i = a; i < (ll)(b);\
    \ i += c)\n\n// rrep(overload)\n#define rrep( ... ) VA_SELECT(rrep, __VA_ARGS__)\
    \    \n#define rrep2(i, n) for (int i = n - 1; i >= 0; i--)\n#define rrep3(i,\
    \ a, b) for (int i = b - 1; i >= a; i--)\n#define rrep4(i, a, b, c) for (int i\
    \ = b - 1; i >= a; i -= c)\n\n// rrepll(overload)\n#define rrepll( ... ) VA_SELECT(rrepll,\
    \ __VA_ARGS__)\n#define rrepll2(i, n) for (ll i = (ll)(n) - 1; i >= 0ll; i--)\n\
    #define rrepll3(i, a, b) for (ll i = b - 1; i >= (ll)(a); i--)\n#define rrepll4(i,\
    \ a, b, c) for (ll i = b - 1; i >= (ll)(a); i -= c)\n\n// for_earh\n#define fore(e,\
    \ v) for (auto&& e : v)\n\n// vector\n#define all(v) v.begin(), v.end()\n#define\
    \ rall(v) v.rbegin(), v.rend()\n#line 1 \"math/modint.hpp\"\nstruct mint {\n \
    \   static inline long long modulo;\n    static void set_mod(long long m) {\n\
    \        modulo = m;\n    }\n\n    long long num;\n    mint (long long a = 0)\
    \ : num((a % modulo + modulo) % modulo) {}\n\n    mint operator+ (const mint&\
    \ rhs) const noexcept {\n        return mint(*this) += rhs;\n    }\n    mint operator-\
    \ (const mint& rhs) const noexcept {\n        return mint(*this) -= rhs;\n   \
    \ }\n    mint operator* (const mint& rhs) const noexcept {\n        return mint(*this)\
    \ *= rhs;\n    }\n    mint operator/ (const mint& rhs) const noexcept {\n    \
    \    return mint(*this) /= rhs;\n    }\n\n    mint& operator += (const mint& rhs)\
    \ noexcept {\n        num = (num + rhs.num) % modulo;\n        return *this;\n\
    \    }\n    mint& operator -= (const mint& rhs) noexcept {\n        num = (num\
    \ - rhs.num + modulo) % modulo;\n        return *this;\n    }\n    mint& operator\
    \ *= (const mint& rhs) noexcept {\n        num = num * rhs.num % modulo;\n   \
    \     return *this;\n    }\n    mint& operator /= (mint rhs) noexcept {\n    \
    \    assert(rhs.num != 0);\n        long long y = modulo - 2;\n        while (y\
    \ > 0) {\n            if (y & 1) *this *= rhs;\n            rhs *= rhs;\n    \
    \        y /= 2;\n        }\n        return *this;\n    }\n\n    mint& operator++\
    \ () noexcept {\n        *this += (mint)1;\n        return *this;\n    }\n   \
    \ mint operator++ (int) noexcept {\n        mint tmp = *this;\n        ++*this;\n\
    \        return tmp;\n    }\n    mint& operator-- () noexcept {\n        *this\
    \ -= (mint)1;\n        return *this;\n    }\n    mint operator-- (int) noexcept\
    \ {\n        mint tmp = *this;\n        --*this;\n        return tmp;\n    }\n\
    \n    friend ostream &operator << (ostream& lhs, const mint& rhs) {\n        lhs\
    \ << rhs.num;\n        return lhs;\n    }\n    \n    friend istream &operator\
    \ >> (istream& lhs, mint& rhs) {\n        lhs >> rhs.num;\n        rhs.num = (rhs.num\
    \ % modulo + modulo) % modulo;\n        return lhs;\n    }\n};\n\nmint modpow(mint\
    \ x, long long y) {\n    if (y == 0) return 1;\n    return modpow(x * x, y / 2)\
    \ * (y & 1 ? x : 1);\n}\n#line 1 \"math/comb_perm.hpp\"\nstruct comb_perm{\n \
    \   int n;\n    vector<mint> fac;\n    vector<mint> ifac;\n\n    comb_perm(int\
    \ _n): n(_n), fac(_n + 1), ifac(_n + 1){\n        fac[0] = ifac[0] = 1;\n    \
    \    for(int i = 1; i <= n; i++){\n            fac[i] = fac[i - 1] * i;\n    \
    \    }\n        ifac[n] = (mint)1 / fac[n];\n        for (int i = n - 1; i >=\
    \ 1; i--) {\n            ifac[i] = ifac[i + 1] * (i + 1);\n        }\n    }\n\n\
    \    mint comb(int p, int r){\n        return (p < r ? 0 : fac[p] * ifac[r] *\
    \ ifac[p - r]);\n    }\n\n    mint perm(int p, int r){\n        return (p < r\
    \ ? 0 : fac[p] * ifac[p - r]);\n    }\n};\n#line 6 \"test/LibraryChecker/math/binomial_coefficient(Prime_Mod).test.cpp\"\
    \n\nint T, m;\nint main() {\n    cin.tie(nullptr);\n    ios_base::sync_with_stdio(false);\n\
    \    cout << fixed << setprecision(20);\n    cin >>T >> m;\n    mint::modulo =\
    \ m;\n\n    comb_perm cp(min(m - 1, 10000000));\n    rep (i, T) {\n        int\
    \ n, k;\n        cin >> n >> k;\n        mint ans = 1;\n        while (n > 0 ||\
    \ k > 0) {\n            ans *= cp.comb(n % m, k % m);\n            n /= m, k /=\
    \ m;\n        }\n        cout << ans << '\\n';\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/binomial_coefficient_prime_mod\"\
    \n\n#include \"../../../template/template.hpp\"\n#include \"../../../math/modint.hpp\"\
    \n#include \"../../../math/comb_perm.hpp\"\n\nint T, m;\nint main() {\n    cin.tie(nullptr);\n\
    \    ios_base::sync_with_stdio(false);\n    cout << fixed << setprecision(20);\n\
    \    cin >>T >> m;\n    mint::modulo = m;\n\n    comb_perm cp(min(m - 1, 10000000));\n\
    \    rep (i, T) {\n        int n, k;\n        cin >> n >> k;\n        mint ans\
    \ = 1;\n        while (n > 0 || k > 0) {\n            ans *= cp.comb(n % m, k\
    \ % m);\n            n /= m, k /= m;\n        }\n        cout << ans << '\\n';\n\
    \    }\n}\n"
  dependsOn:
  - template/template.hpp
  - math/modint.hpp
  - math/comb_perm.hpp
  isVerificationFile: true
  path: test/LibraryChecker/math/binomial_coefficient(Prime_Mod).test.cpp
  requiredBy: []
  timestamp: '2024-04-27 04:38:59+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/LibraryChecker/math/binomial_coefficient(Prime_Mod).test.cpp
layout: document
redirect_from:
- /verify/test/LibraryChecker/math/binomial_coefficient(Prime_Mod).test.cpp
- /verify/test/LibraryChecker/math/binomial_coefficient(Prime_Mod).test.cpp.html
title: test/LibraryChecker/math/binomial_coefficient(Prime_Mod).test.cpp
---
