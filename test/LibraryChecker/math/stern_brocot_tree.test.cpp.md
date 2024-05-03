---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/stern_brocot_tree.hpp
    title: math/stern_brocot_tree.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/stern_brocot_tree
    links:
    - https://judge.yosupo.jp/problem/stern_brocot_tree
  bundledCode: "#line 1 \"test/LibraryChecker/math/stern_brocot_tree.test.cpp\"\n\
    #define PROBLEM \"https://judge.yosupo.jp/problem/stern_brocot_tree\"\n\n#line\
    \ 1 \"template/template.hpp\"\n#include<bits/stdc++.h>\nusing namespace std;\n\
    #define ll long long\n#define ull unsigned long long\n#define db double\n#define\
    \ pii pair<int,int>\n#define pli pair<ll,int>\n#define pil pair<int,ll>\n#define\
    \ pll pair<ll,ll>\n#define ti3 tuple<int,int,int>\n#define int128 __int128_t\n\
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
    \ rall(v) v.rbegin(), v.rend()\n#line 1 \"math/stern_brocot_tree.hpp\"\ntemplate<class\
    \ T>\nstruct SBT_node {\n    T p, q, r, s;\n};\n\ntemplate<class T>\nstruct stern_brocot_tree\
    \ {\n    static SBT_node<T> child(SBT_node<T> node, bool isleft, T depth) {\n\
    \        if (isleft) return {node.p, node.q, node.p * depth + node.r, node.q *\
    \ depth + node.s};\n        else return {node.p + node.r * depth, node.q + node.s\
    \ * depth, node.r, node.s};\n    }\n\n    static vector<T> encode_path(T p, T\
    \ q) {\n        vector<T> a;\n        do {\n            a.emplace_back(p / q);\n\
    \            p %= q;\n            swap(p, q);\n        } while (q);\n        a[a.size()\
    \ - 1]--;\n        return a;\n    }\n\n    static SBT_node<T> decode_path(vector<T>\
    \ a) {\n        SBT_node<T> ret(0, 1, 1, 0);\n        bool isleft = false;\n \
    \       for (int i = 0; i < (int)a.size(); i++) {\n            ret = child(ret,\
    \ isleft, a[i]);\n            isleft = !isleft;\n        }\n        return ret;\n\
    \    }\n\n    static SBT_node<T> lca(T a, T b, T c, T d) {\n        auto x = encode_path(a,\
    \ b);\n        auto y = encode_path(c, d);\n        vector<T> z;\n        for\
    \ (int i = 0; i < (int)min(x.size(), y.size()); i++) {\n            z.emplace_back(min(x[i],\
    \ y[i]));\n            if (x[i] != y[i]) break;\n        }\n        return decode_path(z);\n\
    \    }\n\n    static SBT_node<T> ancestor(T k, T a, T b) {\n        auto x = encode_path(a,\
    \ b);\n        vector<T> y;\n        for (int i = 0; i < (int)x.size(); i++) {\n\
    \            if (k == 0) continue;\n            T mn = min(k, x[i]);\n       \
    \     y.push_back(mn);\n            k -= mn;\n        }\n        if (k) return\
    \ {0, 0, 0, 0};\n        else return decode_path(y);\n    }\n\n    static SBT_node<T>\
    \ range(T p, T q) {\n        return decode_path(encode_path(p, q));\n    }\n};\n\
    #line 5 \"test/LibraryChecker/math/stern_brocot_tree.test.cpp\"\n\nll k, a, b,\
    \ c, d;\nint main() {\n    cin.tie(nullptr);\n    ios_base::sync_with_stdio(false);\n\
    \    cout << fixed << setprecision(20);\n    int T;\n    cin >> T;\n    while\
    \ (T--) {\n        string S;\n        cin >> S;\n        char s = S[0];\n    \
    \    if (s == 'E') {\n            cin >> a >> b;\n            auto x = stern_brocot_tree<ll>::encode_path(a,\
    \ b);\n            k = x.size() - (x[0] == 0);\n            cout << k;\n     \
    \       bool isleft = true;\n            fore (u, x) {\n                isleft\
    \ = !isleft;\n                if (u == 0) continue;\n                cout << '\
    \ ' << (isleft ? 'L' : 'R') << ' ' << u;\n            }\n            cout << '\\\
    n';\n        } else if (s == 'D') {\n            cin >> k;\n            vector<ll>\
    \ x;\n            rep (i, k) {\n                char lr;\n                int\
    \ u;\n                cin >> lr >> u;\n                if (i == 0 && lr == 'L')\
    \ x.emplace_back(0);\n                x.emplace_back(u);\n            }\n    \
    \        auto [p, q, r, s] = stern_brocot_tree<ll>::decode_path(x);\n        \
    \    cout << p + r << ' ' << q + s << '\\n';\n        } else if (s == 'L') {\n\
    \            cin >> a >> b >> c >> d;\n            auto [p, q, r, s] = stern_brocot_tree<ll>::lca(a,\
    \ b, c, d);\n            cout << p + r << ' ' << q + s << '\\n';\n        } else\
    \ if (s == 'A') {\n            cin >> k >> a >> b;\n            auto [p, q, r,\
    \ s] = stern_brocot_tree<ll>::ancestor(k, a, b);\n            if (max({p, q, r,\
    \ s}) == 0) cout << -1 << '\\n';\n            else cout << p + r << ' ' << q +\
    \ s << '\\n';\n        } else if (s == 'R') {\n            cin >> a >> b;\n  \
    \          auto [f, g, h, k] = stern_brocot_tree<ll>::range(a, b);\n         \
    \   cout << f << ' ' << g << ' ' << h << ' ' << k << '\\n';\n        }\n    }\n\
    }\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/stern_brocot_tree\"\n\n\
    #include \"../../../template/template.hpp\"\n#include \"../../../math/stern_brocot_tree.hpp\"\
    \n\nll k, a, b, c, d;\nint main() {\n    cin.tie(nullptr);\n    ios_base::sync_with_stdio(false);\n\
    \    cout << fixed << setprecision(20);\n    int T;\n    cin >> T;\n    while\
    \ (T--) {\n        string S;\n        cin >> S;\n        char s = S[0];\n    \
    \    if (s == 'E') {\n            cin >> a >> b;\n            auto x = stern_brocot_tree<ll>::encode_path(a,\
    \ b);\n            k = x.size() - (x[0] == 0);\n            cout << k;\n     \
    \       bool isleft = true;\n            fore (u, x) {\n                isleft\
    \ = !isleft;\n                if (u == 0) continue;\n                cout << '\
    \ ' << (isleft ? 'L' : 'R') << ' ' << u;\n            }\n            cout << '\\\
    n';\n        } else if (s == 'D') {\n            cin >> k;\n            vector<ll>\
    \ x;\n            rep (i, k) {\n                char lr;\n                int\
    \ u;\n                cin >> lr >> u;\n                if (i == 0 && lr == 'L')\
    \ x.emplace_back(0);\n                x.emplace_back(u);\n            }\n    \
    \        auto [p, q, r, s] = stern_brocot_tree<ll>::decode_path(x);\n        \
    \    cout << p + r << ' ' << q + s << '\\n';\n        } else if (s == 'L') {\n\
    \            cin >> a >> b >> c >> d;\n            auto [p, q, r, s] = stern_brocot_tree<ll>::lca(a,\
    \ b, c, d);\n            cout << p + r << ' ' << q + s << '\\n';\n        } else\
    \ if (s == 'A') {\n            cin >> k >> a >> b;\n            auto [p, q, r,\
    \ s] = stern_brocot_tree<ll>::ancestor(k, a, b);\n            if (max({p, q, r,\
    \ s}) == 0) cout << -1 << '\\n';\n            else cout << p + r << ' ' << q +\
    \ s << '\\n';\n        } else if (s == 'R') {\n            cin >> a >> b;\n  \
    \          auto [f, g, h, k] = stern_brocot_tree<ll>::range(a, b);\n         \
    \   cout << f << ' ' << g << ' ' << h << ' ' << k << '\\n';\n        }\n    }\n\
    }"
  dependsOn:
  - template/template.hpp
  - math/stern_brocot_tree.hpp
  isVerificationFile: true
  path: test/LibraryChecker/math/stern_brocot_tree.test.cpp
  requiredBy: []
  timestamp: '2024-05-03 21:18:36+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/LibraryChecker/math/stern_brocot_tree.test.cpp
layout: document
redirect_from:
- /verify/test/LibraryChecker/math/stern_brocot_tree.test.cpp
- /verify/test/LibraryChecker/math/stern_brocot_tree.test.cpp.html
title: test/LibraryChecker/math/stern_brocot_tree.test.cpp
---
