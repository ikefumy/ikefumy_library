---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: data_structure/BIT_on_wavelet_matrix.hpp
    title: BIT on Wavelet Matrix
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/LibraryChecker/data_structure/point_add_rectangle_sum_BIT_WM.test.cpp
    title: test/LibraryChecker/data_structure/point_add_rectangle_sum_BIT_WM.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"data_structure/binary_indexed_tree.hpp\"\ntemplate<class\
    \ T>\nstruct binary_indexed_tree {\n    int N;\n    vector<T> bit;\n    binary_indexed_tree\
    \ (int n = 0) : N(n), bit(n + 1, 0) {}\n    T sum(int i){\n        T s = 0;\n\
    \        while(i > 0){\n            s += bit[i];\n            i -= i & -i;\n \
    \       }\n        return s;\n    }\n\n    void add(int i, T x){\n        i++;\n\
    \        while(i <= N){\n            bit[i] += x;\n            i += i & -i;\n\
    \        }\n    }\n    T sum(int l, int r){\n        return sum(r) - sum(l);\n\
    \    }\n};\n"
  code: "template<class T>\nstruct binary_indexed_tree {\n    int N;\n    vector<T>\
    \ bit;\n    binary_indexed_tree (int n = 0) : N(n), bit(n + 1, 0) {}\n    T sum(int\
    \ i){\n        T s = 0;\n        while(i > 0){\n            s += bit[i];\n   \
    \         i -= i & -i;\n        }\n        return s;\n    }\n\n    void add(int\
    \ i, T x){\n        i++;\n        while(i <= N){\n            bit[i] += x;\n \
    \           i += i & -i;\n        }\n    }\n    T sum(int l, int r){\n       \
    \ return sum(r) - sum(l);\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/binary_indexed_tree.hpp
  requiredBy:
  - data_structure/BIT_on_wavelet_matrix.hpp
  timestamp: '2024-05-07 03:31:27+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/LibraryChecker/data_structure/point_add_rectangle_sum_BIT_WM.test.cpp
documentation_of: data_structure/binary_indexed_tree.hpp
layout: document
title: Binary Indexed Tree
---

## 概要
Binary Indexed Tree。0-indexd、開区間になるように調整してる。