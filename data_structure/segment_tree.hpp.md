---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: data_structure/segment_tree_on_wavelet_matrix.hpp
    title: Segment Tree on Wavelet Matrix
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/LibraryChecker/data_structure/point_add_rectangle_sum_SegTree_WM.test.cpp
    title: test/LibraryChecker/data_structure/point_add_rectangle_sum_SegTree_WM.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"data_structure/segment_tree.hpp\"\ntemplate<class T, T(*\
    \ op)(T, T), T(* e)()>\nstruct segment_tree {\n    int N;\n    vector<T> node;\n\
    \n    segment_tree(int n = 0) {\n        N = 1;\n        while(N < n) N *= 2;\n\
    \        node.resize(N * 2 - 1, e());\n    }\n\n    void set (int i, T x) {\n\
    \        i += N - 1;\n        node[i] = x;\n        while (i > 0) {\n        \
    \    i = (i - 1) / 2;\n            node[i] = op(node[i * 2 + 1], node[i * 2 +\
    \ 2]);\n        }\n    }\n\n    void update (int i, T x) {\n        set (i, op(node[i\
    \ + N - 1], x));\n    }\n\n    T get_val (int a, int b, int k = 0, int l = 0,\
    \ int r = -1) {\n        if (r == -1) r = N;\n        if (b <= l || r <= a) return\
    \ e();\n        if (a <= l && r <= b) return node[k];\n\n        T vl = get_val(a,\
    \ b, k * 2 + 1, l, (l + r) / 2);\n        T vr = get_val(a, b, k * 2 + 2, (l +\
    \ r) / 2, r);\n        return op(vl, vr);\n    }\n};\n"
  code: "template<class T, T(* op)(T, T), T(* e)()>\nstruct segment_tree {\n    int\
    \ N;\n    vector<T> node;\n\n    segment_tree(int n = 0) {\n        N = 1;\n \
    \       while(N < n) N *= 2;\n        node.resize(N * 2 - 1, e());\n    }\n\n\
    \    void set (int i, T x) {\n        i += N - 1;\n        node[i] = x;\n    \
    \    while (i > 0) {\n            i = (i - 1) / 2;\n            node[i] = op(node[i\
    \ * 2 + 1], node[i * 2 + 2]);\n        }\n    }\n\n    void update (int i, T x)\
    \ {\n        set (i, op(node[i + N - 1], x));\n    }\n\n    T get_val (int a,\
    \ int b, int k = 0, int l = 0, int r = -1) {\n        if (r == -1) r = N;\n  \
    \      if (b <= l || r <= a) return e();\n        if (a <= l && r <= b) return\
    \ node[k];\n\n        T vl = get_val(a, b, k * 2 + 1, l, (l + r) / 2);\n     \
    \   T vr = get_val(a, b, k * 2 + 2, (l + r) / 2, r);\n        return op(vl, vr);\n\
    \    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/segment_tree.hpp
  requiredBy:
  - data_structure/segment_tree_on_wavelet_matrix.hpp
  timestamp: '2024-05-07 03:31:27+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/LibraryChecker/data_structure/point_add_rectangle_sum_SegTree_WM.test.cpp
documentation_of: data_structure/segment_tree.hpp
layout: document
title: Segment Tree
---

## 概要
セグ木

## 使い方
セグ木の基となっている数列を$a$とする。
- `set(int i, T x)`
    - $a_i=x$に変更する。
- `set(int i, T x)`
    - $a_i=op(a_i,x)$に更新する。
- `get_val(int l, int r)`
    - $op(a_l,a_{l+1},...,a_{r_1})$を返す。