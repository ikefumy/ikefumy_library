---
title: Segment Tree
documentation_of: ./segment_tree.hpp
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