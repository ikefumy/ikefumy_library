---
title: Wavelet Matrix
documentation_of: ./wavelet_matrix.hpp
---

## 概要
重みのないWavelet Matrix。数列$a$を入力としていろいろできる。全部0-indexed。

## 使い方
- `T access(int x)`
    - `a[x]`を返す。
- `T kth_min(int l, int r, int k)`
    - `a[l:r]`のうち、$k$番目に小さい値を返す。
- `T kth_max(int l, int r, int k)`
    - `a[l:r]`のうち、$k$番目に大きい値を返す。
- `T count_lt_k(int l, int r, T k)`
    - `a[l:r]`のうち、$k$より大きい要素の個数を返す。
- `T count_k(int l, int r, T k)`
    - `a[l:r]`のうち、$k$と同じ値の要素の個数を返す。
- `T count_gt_k(int l, int r, T k)`
    - `a[l:r]`のうち$k$より小さい要素の個数を返す。
- `T range_freq(int l, int r, T lower, T upper)`
    - `a[l:r]`のうち、$lower$以上$upper$未満の要素の個数を返す。
- `T next_value(int l, int r, T k)`
    - `a[l:r]`のうち、$k$以上の最小の数を返す。
- `T prev_value(int l, int r, T k)`
    - `a[l:r]`のうち、$k$未満の最大の数を返す。

## 計算量
数列$a$の最大値を$A$とする。
- `T access(int x)` : $\mathrm{O}(\log{A})$
- `T kth_min(int l, int r, int k)` : $\mathrm{O}(\log{A})$
- `T kth_max(int l, int r, int k)` : $\mathrm{O}(\log{A})$
- `T count_lt_k(int l, int r, T k)` : $\mathrm{O}(\log{A})$
- `T count_k(int l, int r, T k)` : $\mathrm{O}(\log{A})$
- `T count_gt_k(int l, int r, T k)` : $\mathrm{O}(\log{A})$
- `T range_freq(int lint r, T lower, T upper)` : $\mathrm{O}(\log{A})$
- `T next_value(int l, int r, T k)` : $\mathrm{O}(\log{A})$
- `T prev_value(int l, int r, T k)` : $\mathrm{O}(\log{A})$