---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/directed_graph.hpp
    title: graph/directed_graph.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/LibraryChecker/strongly_connected_components.test.cpp
    title: test/LibraryChecker/strongly_connected_components.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"graph/directed_graph.hpp\"\nstruct directed_graph {\n  \
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
    \ }\n};\n"
  code: "#include \"directed_graph.hpp\"\n\nstruct strongly_connected_components :\
    \ directed_graph {\nprivate:\n    bool built = false;\n    int tp;\n    vector<int>\
    \ used, vs, cmp;\n\npublic:\n    strongly_connected_components (int n) : directed_graph(n),\
    \ used(n), cmp(n) {}\n\n    void dfs(int v) {\n        used[v] = true;\n     \
    \   for (auto u : g[v]) {\n            if (!used[u]) dfs(u);\n        }\n    \
    \    vs.emplace_back(v);\n    }\n\n    void rdfs(int v, int k) {\n        used[v]\
    \ = true;\n        cmp[v] = k;\n        for (auto u : rg[v]) {\n            if\
    \ (!used[u]) rdfs(u, k);\n        }\n    }\n\n    int build() {\n        fill(used.begin(),\
    \ used.end(), 0);\n        for (int i = 0; i < n; i++) {\n            if (!used[i])\
    \ dfs(i);\n        }\n        fill(used.begin(), used.end(), 0);\n        tp =\
    \ 0;\n        for (int i = n - 1; i >= 0; i--) {\n            if (!used[vs[i]])\
    \ rdfs(vs[i], tp++);\n        }\n        \n        built = true;\n        return\
    \ tp;\n    }\n\n    int get_cmp(int v) {\n        assert(built);\n        return\
    \ cmp[v];\n    }\n\n    int get_tp() {\n        assert(built);\n        return\
    \ tp;\n    }\n};"
  dependsOn:
  - graph/directed_graph.hpp
  isVerificationFile: false
  path: graph/strongly_connected_components.hpp
  requiredBy: []
  timestamp: '2024-01-17 10:43:12+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/LibraryChecker/strongly_connected_components.test.cpp
documentation_of: graph/strongly_connected_components.hpp
layout: document
redirect_from:
- /library/graph/strongly_connected_components.hpp
- /library/graph/strongly_connected_components.hpp.html
title: graph/strongly_connected_components.hpp
---
