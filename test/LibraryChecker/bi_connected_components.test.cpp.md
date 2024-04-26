---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/bi_connected_components.hpp
    title: graph/bi_connected_components.hpp
  - icon: ':heavy_check_mark:'
    path: graph/lowlink.hpp
    title: graph/lowlink.hpp
  - icon: ':heavy_check_mark:'
    path: graph/undirected_graph.hpp
    title: graph/undirected_graph.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/biconnected_components
    links:
    - https://judge.yosupo.jp/problem/biconnected_components
  bundledCode: "#line 1 \"test/LibraryChecker/bi_connected_components.test.cpp\"\n\
    #define PROBLEM \"https://judge.yosupo.jp/problem/biconnected_components\"\n\n\
    #line 1 \"template/template.hpp\"\n#include<bits/stdc++.h>\nusing namespace std;\n\
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
    \ rall(v) v.rbegin(), v.rend()\n#line 1 \"graph/undirected_graph.hpp\"\nstruct\
    \ undirected_graph {\npublic:\n    int n;\n    vector<vector<int>> g;\n\n    undirected_graph(int\
    \ _n = 0) : n(_n), g(_n) {}\n    void add_edge(int u, int v) {\n        assert(0\
    \ <= u && u < n);\n        assert(0 <= v && v < n);\n        g[u].push_back(v);\n\
    \        g[v].push_back(u);\n    }\n};\n#line 2 \"graph/lowlink.hpp\"\n\nstruct\
    \ lowlink : undirected_graph {\nprotected:\n    bool built = false;\n    vector<int>\
    \ ord, low, aps;\n    vector<vector<int>> bridge;\n\npublic:\n    lowlink (int\
    \ _n) : undirected_graph(_n), ord(_n), low(_n), aps(_n), bridge(_n) {}\n\n   \
    \ void dfs(int v, int p, int& cnt) {\n        ord[v] = low[v] = cnt++;\n     \
    \   int count_son = 0, p_idx = -1;\n        for (int i = 0; i < (int)g[v].size();\
    \ i++) {\n            int u = g[v][i];\n            if (ord[u]) {\n          \
    \      if (u != p) low[v] = min(low[v], ord[u]);\n                if (u == p)\
    \ p_idx = i;\n            } else {\n                count_son++;\n           \
    \     dfs(u, v, cnt);\n                bridge[v][i] = ord[v] < low[u];\n     \
    \           low[v] = min(low[v], low[u]);\n                aps[v] |= ord[v] <=\
    \ low[u];\n            }\n        }\n\n\n        if (p == -1) aps[v] = count_son\
    \ >= 2;\n        else bridge[v][p_idx] = ord[p] < low[v];\n    }\n\n    void build()\
    \ {\n        built = true;\n        for (int i = 0; i < n; i++) bridge[i].resize(g[i].size());\n\
    \        for (int i = 0; i < n; i++) {\n            if (ord[i]) continue;\n  \
    \          int cnt = 1;\n            dfs(i, -1, cnt);\n        }\n    }\n\n  \
    \  bool is_aps(int v) {\n        assert(built);\n        assert(0 <= v && v <\
    \ n);\n        return aps[v];\n    }\n\n    bool is_bridge(int v, int i) {\n \
    \       assert(built);\n        assert(0 <= v && v < n);\n        assert(0 <=\
    \ i && i < (int)bridge[v].size());\n        return bridge[v][i];\n    }\n};\n\
    #line 2 \"graph/bi_connected_components.hpp\"\n\nstruct bi_connected_components\
    \ : lowlink {\n    vector<vector<int>> comps;\n    vector<int> used, visited;\n\
    \    vector<pair<int, int>> tmp;\n    bi_connected_components(int _n) : lowlink(_n),\
    \ used(_n), visited(_n) {}\n\n    void dfs(int v, int p) {\n        visited[v]\
    \ = true;\n        for (auto&& u : g[v]) {\n            if (u == p) continue;\n\
    \            if (!visited[u] || ord[u] < ord[v]) tmp.emplace_back(min(u, v), max(u,\
    \ v));\n            if (!visited[u]) {\n                dfs(u, v);\n         \
    \       if (low[u] >= ord[v]) {\n                    comps.emplace_back();\n \
    \                   while (!tmp.empty()) {\n                        auto [a, b]\
    \ = tmp.back();\n                        tmp.pop_back();\n                   \
    \     if (!used[a]) comps.back().emplace_back(a), used[a] = true;\n          \
    \              if (!used[b]) comps.back().emplace_back(b), used[b] = true;\n \
    \                       if (a == min(u, v) && b == max(u, v)) break;\n       \
    \             }\n                    for (auto elem : comps.back()) used[elem]\
    \ = false;\n                }\n            }\n        }\n    }\n\n    void build()\
    \ {\n        lowlink::build();\n        for (int v = 0; v < n; v++) {\n      \
    \      if (visited[v]) continue;\n            dfs(v, -1);\n        }\n\n     \
    \   for (auto comp : comps) {\n            for (auto v : comp) {\n           \
    \     used[v] = true;\n            }\n        }\n\n        for (int v = 0; v<\
    \ n; v++) {\n            if (used[v]) continue;\n            comps.push_back({v});\n\
    \        }\n    }\n\n    vector<vector<int>> get_comps() {\n        assert(built);\n\
    \        return comps;\n    }\n};\n#line 5 \"test/LibraryChecker/bi_connected_components.test.cpp\"\
    \n\nint N, M;\nint main() {\n    cin.tie(nullptr);\n    ios_base::sync_with_stdio(false);\n\
    \    cout << fixed << setprecision(20);\n    cin >> N >> M;\n    bi_connected_components\
    \ g(N);\n    rep (i, M) {\n        int a, b;\n        cin >> a >> b;\n       \
    \ g.add_edge(a, b);\n    }\n\n    g.build();\n    auto cs = g.get_comps();\n\n\
    \    cout << cs.size() << '\\n';\n    for (auto&& c : cs) {\n        cout << c.size();\n\
    \        for (auto&& u : c) cout << ' ' << u;\n        cout << '\\n';\n    }\n\
    }\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/biconnected_components\"\
    \n\n#include \"../../template/template.hpp\"\n#include \"../../graph/bi_connected_components.hpp\"\
    \n\nint N, M;\nint main() {\n    cin.tie(nullptr);\n    ios_base::sync_with_stdio(false);\n\
    \    cout << fixed << setprecision(20);\n    cin >> N >> M;\n    bi_connected_components\
    \ g(N);\n    rep (i, M) {\n        int a, b;\n        cin >> a >> b;\n       \
    \ g.add_edge(a, b);\n    }\n\n    g.build();\n    auto cs = g.get_comps();\n\n\
    \    cout << cs.size() << '\\n';\n    for (auto&& c : cs) {\n        cout << c.size();\n\
    \        for (auto&& u : c) cout << ' ' << u;\n        cout << '\\n';\n    }\n\
    }"
  dependsOn:
  - template/template.hpp
  - graph/bi_connected_components.hpp
  - graph/lowlink.hpp
  - graph/undirected_graph.hpp
  isVerificationFile: true
  path: test/LibraryChecker/bi_connected_components.test.cpp
  requiredBy: []
  timestamp: '2024-04-26 18:28:59+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/LibraryChecker/bi_connected_components.test.cpp
layout: document
redirect_from:
- /verify/test/LibraryChecker/bi_connected_components.test.cpp
- /verify/test/LibraryChecker/bi_connected_components.test.cpp.html
title: test/LibraryChecker/bi_connected_components.test.cpp
---
