---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AOJ/1615.test.cpp
    title: test/AOJ/1615.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"graph/max_flow_lb.hpp\"\ntemplate<class F>\nstruct max_flow_lb\
    \ {\n    Dinic<F> f;\n    int S, T;\n    F sum_lb;\n\n    max_flow_lb (int n)\
    \ : f(n + 2), S(n), T(n + 1), sum_lb(0) {}\n\n    void add_edge(int u, int v,\
    \ int lb, int ub) {\n        assert(0 <= lb && lb <= ub);\n        if (ub == 0)\
    \ return;\n        f.add_edge(u, v, ub - lb);\n        if (lb == 0) return;\n\
    \        sum_lb += lb;\n        f.add_edge(S, v, lb);\n        f.add_edge(u, T,\
    \ lb);\n    }\n\n    F max_flow(int s, int t) {\n        F a = f.max_flow(S, T);\n\
    \        F b = f.max_flow(s, T);\n        F c = f.max_flow(S, t);\n        F d\
    \ = f.max_flow(s, t);\n        return (a + b == sum_lb && a + c == sum_lb) ? b\
    \ + d : -1;\n    }\n};\n"
  code: "template<class F>\nstruct max_flow_lb {\n    Dinic<F> f;\n    int S, T;\n\
    \    F sum_lb;\n\n    max_flow_lb (int n) : f(n + 2), S(n), T(n + 1), sum_lb(0)\
    \ {}\n\n    void add_edge(int u, int v, int lb, int ub) {\n        assert(0 <=\
    \ lb && lb <= ub);\n        if (ub == 0) return;\n        f.add_edge(u, v, ub\
    \ - lb);\n        if (lb == 0) return;\n        sum_lb += lb;\n        f.add_edge(S,\
    \ v, lb);\n        f.add_edge(u, T, lb);\n    }\n\n    F max_flow(int s, int t)\
    \ {\n        F a = f.max_flow(S, T);\n        F b = f.max_flow(s, T);\n      \
    \  F c = f.max_flow(S, t);\n        F d = f.max_flow(s, t);\n        return (a\
    \ + b == sum_lb && a + c == sum_lb) ? b + d : -1;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: graph/max_flow_lb.hpp
  requiredBy: []
  timestamp: '2024-04-27 00:51:07+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/AOJ/1615.test.cpp
documentation_of: graph/max_flow_lb.hpp
layout: document
redirect_from:
- /library/graph/max_flow_lb.hpp
- /library/graph/max_flow_lb.hpp.html
title: graph/max_flow_lb.hpp
---
