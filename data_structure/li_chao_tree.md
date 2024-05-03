---
title: Li Chao Tree
documentation_of: ./li_chao_tree.hpp
---

## 定義の仕方
```cpp
dynamic_li_chao_tree<T,e,NODES> dlct(int x_min, int x_max);
```
型`T`で、最大値が`e`とした、区間が$\[x_{min}, {x_max})$のLi Chao Treeを作る。`NODES`でメモリプールの大きさを決める。メモリプールのサイズが十分でない時、エラーがはかれる（多分Runtime Error）。そういう時は`NODES`の値を増やすか、構造体`Nodes`内の`new`のオーバーロードを丸ごとコメントアウトするとよい。コメントアウトした場合は速度が落ちる。

## 使い方
- `void add_line(T a, T b)`
    - $y=ax+b$を追加する。
- `void add_seg(T a,T b,T l,T r)`
    - $y=ax+b(l\leq x < r)$　を追加する。
- `T get_min(T i)`
    - $x=i$と交わる直線/線分の$y$座標の最小値を返す。

## 計算量
- `add_line(T a, T b)` : $\mathrm{O}(\log{(x_{max} - x_{min})})$
- `add_seg(T a, T b, T l, T r)` : $\mathrm{O}(\log{(x_{max} - x_{min}) \log{(b - a)}})$
## 参考にしたサイト

- [Li Chao Treeのメモ](https://smijake3.hatenablog.com/entry/2018/06/16/144548)
- [Dynamic-Li-Chao-Tree - Luzhiled's Library](https://ei1333.github.io/library/structure/convex-hull-trick/dynamic-li-chao-tree.hpp.html)