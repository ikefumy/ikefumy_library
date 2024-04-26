---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/lowlink.hpp
    title: graph/lowlink.hpp
  - icon: ':heavy_check_mark:'
    path: graph/undirected_graph.hpp
    title: graph/undirected_graph.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/LibraryChecker/graph/bi_connected_components.test.cpp
    title: test/LibraryChecker/graph/bi_connected_components.test.cpp
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
    \        return comps;\n    }\n};\n"
  code: "#include \"lowlink.hpp\"\n\nstruct bi_connected_components : lowlink {\n\
    \    vector<vector<int>> comps;\n    vector<int> used, visited;\n    vector<pair<int,\
    \ int>> tmp;\n    bi_connected_components(int _n) : lowlink(_n), used(_n), visited(_n)\
    \ {}\n\n    void dfs(int v, int p) {\n        visited[v] = true;\n        for\
    \ (auto&& u : g[v]) {\n            if (u == p) continue;\n            if (!visited[u]\
    \ || ord[u] < ord[v]) tmp.emplace_back(min(u, v), max(u, v));\n            if\
    \ (!visited[u]) {\n                dfs(u, v);\n                if (low[u] >= ord[v])\
    \ {\n                    comps.emplace_back();\n                    while (!tmp.empty())\
    \ {\n                        auto [a, b] = tmp.back();\n                     \
    \   tmp.pop_back();\n                        if (!used[a]) comps.back().emplace_back(a),\
    \ used[a] = true;\n                        if (!used[b]) comps.back().emplace_back(b),\
    \ used[b] = true;\n                        if (a == min(u, v) && b == max(u, v))\
    \ break;\n                    }\n                    for (auto elem : comps.back())\
    \ used[elem] = false;\n                }\n            }\n        }\n    }\n\n\
    \    void build() {\n        lowlink::build();\n        for (int v = 0; v < n;\
    \ v++) {\n            if (visited[v]) continue;\n            dfs(v, -1);\n   \
    \     }\n\n        for (auto comp : comps) {\n            for (auto v : comp)\
    \ {\n                used[v] = true;\n            }\n        }\n\n        for\
    \ (int v = 0; v< n; v++) {\n            if (used[v]) continue;\n            comps.push_back({v});\n\
    \        }\n    }\n\n    vector<vector<int>> get_comps() {\n        assert(built);\n\
    \        return comps;\n    }\n};"
  dependsOn:
  - graph/lowlink.hpp
  - graph/undirected_graph.hpp
  isVerificationFile: false
  path: graph/bi_connected_components.hpp
  requiredBy: []
  timestamp: '2024-04-27 04:52:48+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/LibraryChecker/graph/bi_connected_components.test.cpp
documentation_of: graph/bi_connected_components.hpp
layout: document
redirect_from:
- /library/graph/bi_connected_components.hpp
- /library/graph/bi_connected_components.hpp.html
title: graph/bi_connected_components.hpp
---
