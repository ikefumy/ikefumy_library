---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: graph/strongly_connected_components.hpp
    title: graph/strongly_connected_components.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"graph/directed_graph.hpp\"\nstruct directed_graph {\n  \
    \  int n;\n    vector<vector<int>> g, rg;\n    directed_graph(int _n) : n(_n),\
    \ g(_n), rg(_n) {}\n    void add_edge(int from, int to) {\n        assert(0 <=\
    \ from && from < n);\n        assert(0 <= to && to < n);\n        g[from].emplace_back(to);\n\
    \        rg[to].emplace_back(from);\n    }\n};\n"
  code: "struct directed_graph {\n    int n;\n    vector<vector<int>> g, rg;\n   \
    \ directed_graph(int _n) : n(_n), g(_n), rg(_n) {}\n    void add_edge(int from,\
    \ int to) {\n        assert(0 <= from && from < n);\n        assert(0 <= to &&\
    \ to < n);\n        g[from].emplace_back(to);\n        rg[to].emplace_back(from);\n\
    \    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: graph/directed_graph.hpp
  requiredBy:
  - graph/strongly_connected_components.hpp
  timestamp: '2024-04-27 00:19:50+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/directed_graph.hpp
layout: document
redirect_from:
- /library/graph/directed_graph.hpp
- /library/graph/directed_graph.hpp.html
title: graph/directed_graph.hpp
---
