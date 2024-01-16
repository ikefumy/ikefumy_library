---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/directed_graph.hpp
    title: graph/directed_graph.hpp
  - icon: ':heavy_check_mark:'
    path: graph/strongly_connected_components.hpp
    title: graph/strongly_connected_components.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/scc
    links:
    - https://judge.yosupo.jp/problem/scc
  bundledCode: "#line 1 \"test/LibraryChecker/strongly_connected_components.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/scc\"\n\n#line 1 \"template/template.hpp\"\
    \n#include<bits/stdc++.h>\nusing namespace std;\n#define ll long long\n#define\
    \ ull unsigned long long\n#define db double\n#define pii pair<int,int>\n#define\
    \ pli pair<ll,int>\n#define pil pair<int,ll>\n#define pll pair<ll,ll>\n#define\
    \ ti3 tuple<int,int,int>\n#define int128 __int128_t\n#define pii128 pair<int128,int128>\n\
    const int inf = 1 << 30;\nconst ll linf = 1e18;\nconst db EPS = 1e-10;\nconst\
    \ db pi = acos(-1);\ntemplate<class T> bool chmin(T& x, T y){\n    if(x > y) {\n\
    \        x = y;\n        return true;\n    } else return false;\n}\ntemplate<class\
    \ T> bool chmax(T& x, T y){\n    if(x < y) {\n        x = y;\n        return true;\n\
    \    } else return false;\n}\n\n// overload macro\n#define CAT( A, B ) A ## B\n\
    #define SELECT( NAME, NUM ) CAT( NAME, NUM )\n\n#define GET_COUNT( _1, _2, _3,\
    \ _4, _5, _6 /* ad nauseam */, COUNT, ... ) COUNT\n#define VA_SIZE( ... ) GET_COUNT(\
    \ __VA_ARGS__, 6, 5, 4, 3, 2, 1 )\n\n#define VA_SELECT( NAME, ... ) SELECT( NAME,\
    \ VA_SIZE(__VA_ARGS__) )(__VA_ARGS__)\n\n// rep(overload)\n#define rep( ... )\
    \ VA_SELECT(rep, __VA_ARGS__)\n#define rep2(i, n) for (int i = 0; i < int(n);\
    \ i++)\n#define rep3(i, a, b) for (int i = a; i < int(b); i++)\n#define rep4(i,\
    \ a, b, c) for (int i = a; i < int(b); i += c)\n\n// repll(overload)\n#define\
    \ repll( ... ) VA_SELECT(repll, __VA_ARGS__)\n#define repll2(i, n) for (ll i =\
    \ 0; i < (ll)(n); i++)\n#define repll3(i, a, b) for (ll i = a; i < (ll)(b); i++)\n\
    #define repll4(i, a, b, c) for (ll i = a; i < (ll)(b); i += c)\n\n// rrep(overload)\n\
    #define rrep( ... ) VA_SELECT(rrep, __VA_ARGS__)    \n#define rrep2(i, n) for\
    \ (int i = n - 1; i >= 0; i--)\n#define rrep3(i, a, b) for (int i = b - 1; i >=\
    \ a; i--)\n#define rrep4(i, a, b, c) for (int i = b - 1; i >= a; i -= c)\n\n//\
    \ rrepll(overload)\n#define rrepll( ... ) VA_SELECT(rrepll, __VA_ARGS__)\n#define\
    \ rrepll2(i, n) for (ll i = (ll)(n) - 1; i >= 0ll; i--)\n#define rrepll3(i, a,\
    \ b) for (ll i = b - 1; i >= (ll)(a); i--)\n#define rrepll4(i, a, b, c) for (ll\
    \ i = b - 1; i >= (ll)(a); i -= c)\n\n// for_earh\n#define fore(e, v) for (auto&&\
    \ e : v)\n\n// vector\n#define all(v) v.begin(), v.end()\n#define rall(v) v.rbegin(),\
    \ v.rend()\n#line 1 \"graph/directed_graph.hpp\"\nstruct directed_graph {\n  \
    \  int n;\n    vector<vector<int>> g, rg;\n    directed_graph(int _n) : n(_n),\
    \ g(_n), rg(_n) {}\n    void add_edge(int from, int to) {\n        assert(0 <=\
    \ from && from < n);\n        assert(0 <= to && to < n);\n        g[from].emplace_back(to);\n\
    \        rg[to].emplace_back(from);\n    }\n};\n#line 2 \"graph/strongly_connected_components.hpp\"\
    \n\nstruct strongly_connected_components : directed_graph {\nprivate:\n    bool\
    \ built = false;\n    int tp;\n    vector<int> used, vs, cmp;\n\npublic:\n   \
    \ strongly_connected_components (int n) : directed_graph(n), used(n), cmp(n) {}\n\
    \n    void dfs(int v) {\n        used[v] = true;\n        for (auto u : g[v])\
    \ {\n            if (!used[u]) dfs(u);\n        }\n        vs.emplace_back(v);\n\
    \    }\n\n    void rdfs(int v, int k) {\n        used[v] = true;\n        cmp[v]\
    \ = k;\n        for (auto u : rg[v]) {\n            if (!used[u]) rdfs(u, k);\n\
    \        }\n    }\n\n    int build() {\n        fill(used.begin(), used.end(),\
    \ 0);\n        for (int i = 0; i < n; i++) {\n            if (!used[i]) dfs(i);\n\
    \        }\n        fill(used.begin(), used.end(), 0);\n        tp = 0;\n    \
    \    for (int i = n - 1; i >= 0; i--) {\n            if (!used[vs[i]]) rdfs(vs[i],\
    \ tp++);\n        }\n        \n        built = true;\n        return tp;\n   \
    \ }\n\n    int get_cmp(int v) {\n        assert(built);\n        return cmp[v];\n\
    \    }\n\n    int get_tp() {\n        assert(built);\n        return tp;\n   \
    \ }\n};\n#line 5 \"test/LibraryChecker/strongly_connected_components.test.cpp\"\
    \n\nint N, M;\nvector<int> cs[500010];\nint main() {\n    cin.tie(nullptr);\n\
    \    ios_base::sync_with_stdio(false);\n    cout << fixed << setprecision(20);\n\
    \    cin >> N >> M;\n    strongly_connected_components g(N);\n    rep (i, M) {\n\
    \        int a, b;\n        cin >> a >> b;\n        g.add_edge(a, b);\n    }\n\
    \n    int tp = g.build();\n    rep (i, N) {\n        cs[g.get_cmp(i)].emplace_back(i);\n\
    \    }\n\n    cout << tp << '\\n';\n    rep (i, tp) {\n        cout << cs[i].size();\n\
    \        for (auto&& u : cs[i]) cout << ' ' << u;\n        cout << '\\n';\n  \
    \  } \n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/scc\"\n\n#include \"../../template/template.hpp\"\
    \n#include \"../../graph/strongly_connected_components.hpp\"\n\nint N, M;\nvector<int>\
    \ cs[500010];\nint main() {\n    cin.tie(nullptr);\n    ios_base::sync_with_stdio(false);\n\
    \    cout << fixed << setprecision(20);\n    cin >> N >> M;\n    strongly_connected_components\
    \ g(N);\n    rep (i, M) {\n        int a, b;\n        cin >> a >> b;\n       \
    \ g.add_edge(a, b);\n    }\n\n    int tp = g.build();\n    rep (i, N) {\n    \
    \    cs[g.get_cmp(i)].emplace_back(i);\n    }\n\n    cout << tp << '\\n';\n  \
    \  rep (i, tp) {\n        cout << cs[i].size();\n        for (auto&& u : cs[i])\
    \ cout << ' ' << u;\n        cout << '\\n';\n    } \n}"
  dependsOn:
  - template/template.hpp
  - graph/strongly_connected_components.hpp
  - graph/directed_graph.hpp
  isVerificationFile: true
  path: test/LibraryChecker/strongly_connected_components.test.cpp
  requiredBy: []
  timestamp: '2024-01-16 15:25:47+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/LibraryChecker/strongly_connected_components.test.cpp
layout: document
redirect_from:
- /verify/test/LibraryChecker/strongly_connected_components.test.cpp
- /verify/test/LibraryChecker/strongly_connected_components.test.cpp.html
title: test/LibraryChecker/strongly_connected_components.test.cpp
---
