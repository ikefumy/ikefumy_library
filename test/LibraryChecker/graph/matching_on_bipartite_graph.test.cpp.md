---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/bipartite_graph_matching.hpp
    title: "\u4E8C\u90E8\u30DE\u30C3\u30C1\u30F3\u30B0"
  - icon: ':heavy_check_mark:'
    path: graph/dinic.hpp
    title: graph/dinic.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/bipartitematching
    links:
    - https://judge.yosupo.jp/problem/bipartitematching
  bundledCode: "#line 1 \"test/LibraryChecker/graph/matching_on_bipartite_graph.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/bipartitematching\"\n\n#line\
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
    \ rall(v) v.rbegin(), v.rend()\n#line 1 \"graph/dinic.hpp\"\ntemplate<class F>\n\
    struct dinic {\n    struct edge {\n        int to;\n        F cap;\n        int\
    \ rev;\n        edge(){}\n        edge(int to, F cap, int rev) : to(to), cap(cap),\
    \ rev(rev) {}\n    };\n\n    vector<vector<edge>> g;\n    vector<int> level;\n\
    \    vector<int> iter;\n    \n    dinic(int v) : g(v), level(v), iter(v) {}\n\
    \ \n    void add_edge(int from, int to, F cap) {\n        g[from].push_back({to,\
    \ cap, (int)g[to].size()});\n        g[to].push_back({from, 0, (int)g[from].size()\
    \ - 1});\n    }\n \n    void bfs(int s) {\n        fill(level.begin(), level.end(),\
    \ -1);\n        queue<int> que;\n        level[s] = 0;\n        que.push(s);\n\
    \        while (!que.empty()) {\n            int v = que.front();\n          \
    \  que.pop();\n            for (auto& e : g[v]) {\n                if (e.cap >\
    \ 0 && level[e.to] < 0) {\n                    level[e.to] = level[v] + 1;\n \
    \                   que.push(e.to);\n                }\n            }\n      \
    \  }\n    }\n \n    F dfs(int v, int t, F f) {\n        if (v == t) return f;\n\
    \        for (int &i = iter[v]; i < (int)g[v].size(); i++) {\n            edge\
    \ &e = g[v][i];\n            if (e.cap > 0 && level[v] < level[e.to]) {\n    \
    \            int d = dfs(e.to, t, min(f, e.cap));\n                if (d > 0)\
    \ {\n                    e.cap -= d;\n                    g[e.to][e.rev].cap +=\
    \ d;\n                    return d;\n                }\n            }\n      \
    \  }\n        return 0;\n    }\n \n    F max_flow(int s, int t) {\n        F flow\
    \ = 0;\n        while(true) {\n            bfs(s);\n            if (level[t] <\
    \ 0) return flow;\n            fill(iter.begin(), iter.end(), 0);\n          \
    \  F f;\n            while ((f = dfs(s, t, inf)) > 0) {\n                flow\
    \ += f;\n            }\n        }\n        return flow;\n    }\n\n    vector<vector<edge>>\
    \ get_g() {\n        return g;\n    }\n};\n#line 2 \"graph/bipartite_graph_matching.hpp\"\
    \n\nstruct bipartite_graph_matching {\n    int L, R;\n    vector<int> mxl, mxr;\n\
    \    dinic<int> f;\n    bipartite_graph_matching (int l, int r) : L(l), R(r),\
    \ mxl(l, 1), mxr(r, 1), f(l + r + 2) {};\n\n    void add_edge(int u, int v) {\n\
    \        f.add_edge(u, L + v, 1);\n    }\n\n    void set_cap(bool isL, int v,\
    \ int cap) {\n        if (isL) mxl[v] = cap;\n        else mxr[L + v] = cap;\n\
    \    }\n\n    vector<pair<int, int>> matching() {\n        for (int i = 0; i <\
    \ L; i++) {\n            f.add_edge(L + R, i, mxl[i]);\n        }\n        for\
    \ (int i = 0; i < R; i++) {\n            f.add_edge(L + i, L + R + 1, mxr[i]);\n\
    \        }\n        f.max_flow(L + R, L + R + 1);\n\n        auto g = f.get_g();\n\
    \        vector<pair<int, int>> ret;\n        for (int i = 0; i < L; i++) {\n\
    \            for (auto [v, cap, _] : g[i]) {\n                if (cap == 0 &&\
    \ v < L + R) ret.emplace_back(i, v - L);\n            }\n        }\n        return\
    \ ret;\n    }\n};\n#line 5 \"test/LibraryChecker/graph/matching_on_bipartite_graph.test.cpp\"\
    \n\nint L, R, M;\nint main() {\n    cin.tie(nullptr);\n    ios_base::sync_with_stdio(false);\n\
    \    cout << fixed << setprecision(20);\n    cin >> L >> R >> M;\n    bipartite_graph_matching\
    \ bgm(L, R);\n    rep (i, M) {\n        int u, v;\n        cin >> u >> v;\n  \
    \      bgm.add_edge(u, v);\n    }\n\n    auto ans = bgm.matching();\n    cout\
    \ << ans.size() << '\\n';\n    for (auto [l, r] : ans) {\n        cout << l <<\
    \ ' ' << r << '\\n';\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/bipartitematching\"\n\n\
    #include \"../../../template/template.hpp\"\n#include \"../../../graph/bipartite_graph_matching.hpp\"\
    \n\nint L, R, M;\nint main() {\n    cin.tie(nullptr);\n    ios_base::sync_with_stdio(false);\n\
    \    cout << fixed << setprecision(20);\n    cin >> L >> R >> M;\n    bipartite_graph_matching\
    \ bgm(L, R);\n    rep (i, M) {\n        int u, v;\n        cin >> u >> v;\n  \
    \      bgm.add_edge(u, v);\n    }\n\n    auto ans = bgm.matching();\n    cout\
    \ << ans.size() << '\\n';\n    for (auto [l, r] : ans) {\n        cout << l <<\
    \ ' ' << r << '\\n';\n    }\n}"
  dependsOn:
  - template/template.hpp
  - graph/bipartite_graph_matching.hpp
  - graph/dinic.hpp
  isVerificationFile: true
  path: test/LibraryChecker/graph/matching_on_bipartite_graph.test.cpp
  requiredBy: []
  timestamp: '2024-05-06 21:59:55+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/LibraryChecker/graph/matching_on_bipartite_graph.test.cpp
layout: document
redirect_from:
- /verify/test/LibraryChecker/graph/matching_on_bipartite_graph.test.cpp
- /verify/test/LibraryChecker/graph/matching_on_bipartite_graph.test.cpp.html
title: test/LibraryChecker/graph/matching_on_bipartite_graph.test.cpp
---
