---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/LibraryChecker/data_structure/union_find.test.cpp
    title: test/LibraryChecker/data_structure/union_find.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"data_structure/union_find.hpp\"\nstruct union_find {\n \
    \   int n;\n    vector<int> par, rnk, wt;\n\n    union_find(int _n) : n(_n), par(_n),\
    \ rnk(_n), wt(_n, 1) {\n        iota(par.begin(), par.end(), 0);\n    }\n\n  \
    \  void set_wt(int v, int w) {\n        wt[v] = w;\n    }\n\n    int find(int\
    \ v) {\n        return par[v] == v ? v : par[v] = find(par[v]);\n    }\n\n   \
    \ bool same(int u, int v) {\n        return find(u) == find(v);\n    }\n\n   \
    \ void unite(int u, int v) {\n        u = find(u), v = find(v);\n        if (u\
    \ == v) return;\n        if (rnk[u] < rnk[v]) swap(u, v);\n        rnk[u] += rnk[u]\
    \ == rnk[v];\n        par[v] = par[u];\n        wt[u] += wt[v];\n    }\n\n   \
    \ int get_wt(int v) {\n        return wt[find(v)];\n    }\n};\n"
  code: "struct union_find {\n    int n;\n    vector<int> par, rnk, wt;\n\n    union_find(int\
    \ _n) : n(_n), par(_n), rnk(_n), wt(_n, 1) {\n        iota(par.begin(), par.end(),\
    \ 0);\n    }\n\n    void set_wt(int v, int w) {\n        wt[v] = w;\n    }\n\n\
    \    int find(int v) {\n        return par[v] == v ? v : par[v] = find(par[v]);\n\
    \    }\n\n    bool same(int u, int v) {\n        return find(u) == find(v);\n\
    \    }\n\n    void unite(int u, int v) {\n        u = find(u), v = find(v);\n\
    \        if (u == v) return;\n        if (rnk[u] < rnk[v]) swap(u, v);\n     \
    \   rnk[u] += rnk[u] == rnk[v];\n        par[v] = par[u];\n        wt[u] += wt[v];\n\
    \    }\n\n    int get_wt(int v) {\n        return wt[find(v)];\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/union_find.hpp
  requiredBy: []
  timestamp: '2024-05-03 21:39:46+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/LibraryChecker/data_structure/union_find.test.cpp
documentation_of: data_structure/union_find.hpp
layout: document
title: Union Find
---
## 概要
Union Findです。重みがついています。0-indexedです。

## 使い方
- `set_wt(v, w)` : $v$の重みを$w$に変更する。一番最初にやらないとバグる。
- `find(v)` : $v$の所属する集合の代表となる頂点を返す。
- `same(u, v)` : $u$と$v$が同じ集合に所属してるなら`true`、所属していないなら`false`を返す。
- `unite(u, v)` : $u$の所属する集合と$v$の所属する集合を合体させる。
- `get_wt(v)` : $v$の所属する集合の重み（集合内の重みの和）を返す。

## 計算量
- そのうち書きます。だいたい対数か定数です。