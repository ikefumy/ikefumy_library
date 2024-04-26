---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/undirected_graph.hpp
    title: graph/undirected_graph.hpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: graph/bi_connected_components.hpp
    title: graph/bi_connected_components.hpp
  - icon: ':heavy_check_mark:'
    path: graph/two_edge_connected_components.hpp
    title: graph/two_edge_connected_components.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/LibraryChecker/graph/bi_connected_components.test.cpp
    title: test/LibraryChecker/graph/bi_connected_components.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/LibraryChecker/graph/two_edge_connected_components.test.cpp
    title: test/LibraryChecker/graph/two_edge_connected_components.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"graph/undirected_graph.hpp\"\nstruct undirected_graph {\n\
    public:\n    int n;\n    vector<vector<int>> g;\n\n    undirected_graph(int _n\
    \ = 0) : n(_n), g(_n) {}\n    void add_edge(int u, int v) {\n        assert(0\
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
    \ i && i < (int)bridge[v].size());\n        return bridge[v][i];\n    }\n};\n"
  code: "#include \"undirected_graph.hpp\"\n\nstruct lowlink : undirected_graph {\n\
    protected:\n    bool built = false;\n    vector<int> ord, low, aps;\n    vector<vector<int>>\
    \ bridge;\n\npublic:\n    lowlink (int _n) : undirected_graph(_n), ord(_n), low(_n),\
    \ aps(_n), bridge(_n) {}\n\n    void dfs(int v, int p, int& cnt) {\n        ord[v]\
    \ = low[v] = cnt++;\n        int count_son = 0, p_idx = -1;\n        for (int\
    \ i = 0; i < (int)g[v].size(); i++) {\n            int u = g[v][i];\n        \
    \    if (ord[u]) {\n                if (u != p) low[v] = min(low[v], ord[u]);\n\
    \                if (u == p) p_idx = i;\n            } else {\n              \
    \  count_son++;\n                dfs(u, v, cnt);\n                bridge[v][i]\
    \ = ord[v] < low[u];\n                low[v] = min(low[v], low[u]);\n        \
    \        aps[v] |= ord[v] <= low[u];\n            }\n        }\n\n\n        if\
    \ (p == -1) aps[v] = count_son >= 2;\n        else bridge[v][p_idx] = ord[p] <\
    \ low[v];\n    }\n\n    void build() {\n        built = true;\n        for (int\
    \ i = 0; i < n; i++) bridge[i].resize(g[i].size());\n        for (int i = 0; i\
    \ < n; i++) {\n            if (ord[i]) continue;\n            int cnt = 1;\n \
    \           dfs(i, -1, cnt);\n        }\n    }\n\n    bool is_aps(int v) {\n \
    \       assert(built);\n        assert(0 <= v && v < n);\n        return aps[v];\n\
    \    }\n\n    bool is_bridge(int v, int i) {\n        assert(built);\n       \
    \ assert(0 <= v && v < n);\n        assert(0 <= i && i < (int)bridge[v].size());\n\
    \        return bridge[v][i];\n    }\n};"
  dependsOn:
  - graph/undirected_graph.hpp
  isVerificationFile: false
  path: graph/lowlink.hpp
  requiredBy:
  - graph/bi_connected_components.hpp
  - graph/two_edge_connected_components.hpp
  timestamp: '2024-04-27 04:38:59+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/LibraryChecker/graph/bi_connected_components.test.cpp
  - test/LibraryChecker/graph/two_edge_connected_components.test.cpp
documentation_of: graph/lowlink.hpp
layout: document
redirect_from:
- /library/graph/lowlink.hpp
- /library/graph/lowlink.hpp.html
title: graph/lowlink.hpp
---
