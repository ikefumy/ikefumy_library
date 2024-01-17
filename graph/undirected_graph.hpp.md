---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: graph/bi_connected_components.hpp
    title: graph/bi_connected_components.hpp
  - icon: ':heavy_check_mark:'
    path: graph/lowlink.hpp
    title: graph/lowlink.hpp
  - icon: ':heavy_check_mark:'
    path: graph/two_edge_connected_components.hpp
    title: graph/two_edge_connected_components.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/LibraryChecker/bi_connected_components.test.cpp
    title: test/LibraryChecker/bi_connected_components.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/LibraryChecker/two_edge_connected_components.test.cpp
    title: test/LibraryChecker/two_edge_connected_components.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"graph/undirected_graph.hpp\"\nstruct undirected_graph {\n\
    public:\n    int n;\n    vector<vector<int>> g;\n\n    undirected_graph(int _n\
    \ = 0) : n(_n), g(_n) {}\n    void add_edge(int u, int v) {\n        assert(0\
    \ <= u && u < n);\n        assert(0 <= v && v < n);\n        g[u].push_back(v);\n\
    \        g[v].push_back(u);\n    }\n};\n"
  code: "struct undirected_graph {\npublic:\n    int n;\n    vector<vector<int>> g;\n\
    \n    undirected_graph(int _n = 0) : n(_n), g(_n) {}\n    void add_edge(int u,\
    \ int v) {\n        assert(0 <= u && u < n);\n        assert(0 <= v && v < n);\n\
    \        g[u].push_back(v);\n        g[v].push_back(u);\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: graph/undirected_graph.hpp
  requiredBy:
  - graph/bi_connected_components.hpp
  - graph/lowlink.hpp
  - graph/two_edge_connected_components.hpp
  timestamp: '2024-01-17 10:48:17+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/LibraryChecker/two_edge_connected_components.test.cpp
  - test/LibraryChecker/bi_connected_components.test.cpp
documentation_of: graph/undirected_graph.hpp
layout: document
redirect_from:
- /library/graph/undirected_graph.hpp
- /library/graph/undirected_graph.hpp.html
title: graph/undirected_graph.hpp
---
