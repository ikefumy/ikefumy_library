---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/quotient_range.hpp
    title: math/quotient_range.hpp
  - icon: ':heavy_check_mark:'
    path: template/template.hpp
    title: template/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/enumerate_quotients
    links:
    - https://judge.yosupo.jp/problem/enumerate_quotients
  bundledCode: "#line 1 \"test/LibraryChecker/enumerate_quotients.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/enumerate_quotients\"\n\n#line 1 \"\
    template/template.hpp\"\n#include<bits/stdc++.h>\nusing namespace std;\n#define\
    \ ll long long\n#define ull unsigned long long\n#define db double\n#define pii\
    \ pair<int,int>\n#define pli pair<ll,int>\n#define pil pair<int,ll>\n#define pll\
    \ pair<ll,ll>\n#define ti3 tuple<int,int,int>\n#define int128 __int128_t\n#define\
    \ pii128 pair<int128,int128>\nconst int inf = 1 << 30;\nconst ll linf = 1e18;\n\
    const db EPS = 1e-10;\nconst db pi = acos(-1);\ntemplate<class T> bool chmin(T&\
    \ x, T y){\n    if(x > y) {\n        x = y;\n        return true;\n    } else\
    \ return false;\n}\ntemplate<class T> bool chmax(T& x, T y){\n    if(x < y) {\n\
    \        x = y;\n        return true;\n    } else return false;\n}\n\n// overload\
    \ macro\n#define CAT( A, B ) A ## B\n#define SELECT( NAME, NUM ) CAT( NAME, NUM\
    \ )\n\n#define GET_COUNT( _1, _2, _3, _4, _5, _6 /* ad nauseam */, COUNT, ...\
    \ ) COUNT\n#define VA_SIZE( ... ) GET_COUNT( __VA_ARGS__, 6, 5, 4, 3, 2, 1 )\n\
    \n#define VA_SELECT( NAME, ... ) SELECT( NAME, VA_SIZE(__VA_ARGS__) )(__VA_ARGS__)\n\
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
    \ rall(v) v.rbegin(), v.rend()\n#line 1 \"math/quotient_range.hpp\"\ntemplate<class\
    \ T>\nvector<tuple<T, T, T>> quotient_range(T n){\n    vector<T> qs;\n    T i\
    \ = 0;\n    for(i = 1; i * i <= n; i++){\n        qs.emplace_back(i);\n    }\n\
    \    i--;\n    if (n / i == i) i--;\n    for (; i >= 1; i--) {\n        qs.emplace_back(n\
    \ / i);\n    }\n\n    vector<tuple<T, T, T>> res = {{1, 1, n}};\n    for (int\
    \ i = 0; i + 1 < (int)qs.size(); i++) {\n        res.emplace_back(qs[i] + 1, qs[i\
    \ + 1], n / qs[i + 1]);\n    }\n    return res;\n}\n#line 5 \"test/LibraryChecker/enumerate_quotients.test.cpp\"\
    \n\nint main() {\n    cin.tie(nullptr);\n    ios_base::sync_with_stdio(false);\n\
    \    cout << fixed << setprecision(20);\n    ll n;\n    cin >> n;\n    auto qr\
    \ = quotient_range(n);\n    cout << qr.size() << '\\n';\n    reverse(all(qr));\n\
    \    for (auto [l, r, q] : qr) cout << q << ' ';\n    cout << '\\n';\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/enumerate_quotients\"\n\
    \n#include \"../../template/template.hpp\"\n#include \"../../math/quotient_range.hpp\"\
    \n\nint main() {\n    cin.tie(nullptr);\n    ios_base::sync_with_stdio(false);\n\
    \    cout << fixed << setprecision(20);\n    ll n;\n    cin >> n;\n    auto qr\
    \ = quotient_range(n);\n    cout << qr.size() << '\\n';\n    reverse(all(qr));\n\
    \    for (auto [l, r, q] : qr) cout << q << ' ';\n    cout << '\\n';\n}"
  dependsOn:
  - template/template.hpp
  - math/quotient_range.hpp
  isVerificationFile: true
  path: test/LibraryChecker/enumerate_quotients.test.cpp
  requiredBy: []
  timestamp: '2024-02-13 23:11:05+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/LibraryChecker/enumerate_quotients.test.cpp
layout: document
redirect_from:
- /verify/test/LibraryChecker/enumerate_quotients.test.cpp
- /verify/test/LibraryChecker/enumerate_quotients.test.cpp.html
title: test/LibraryChecker/enumerate_quotients.test.cpp
---
