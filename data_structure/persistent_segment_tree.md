---
title: 永続セグ木
documentation_of: ./persistent_segment_tree.hpp
---
## 定義の仕方

## 使い方
- `update(int i, T x, int id)`
    - $id$番目に生成されたセグ木において、$i$番目の要素を$x$に変更したセグ木を生成し、戻り値として生成したセグ木の$id$を返す。
    - $id$を指定しなかったとき、最新のセグ木を基に生成する。
- `prod(int a, int b, int id)`
    - $id$番目に生成されたセグ木において、$i$番目の要素を`x[i]`と表したとき、`op(x[a],x[a+1],...,x[b-1])`を返す。
    - $id$を指定しなかったとき、最新のセグ木から取得する。

## 計算量
- `update(int i, int x, int id)` : $\mathrm{O}(\log{n})$
- `prod(int i, int x, int id)` : $\mathrm{O}(\log{n})$

## 参考にしたサイト

- [永続セグメント木 - Nyaan's Library](https://nyaannyaan.github.io/library/segment-tree/persistent-segment-tree.hpp.html)
- [木構造の実装テクニック #競技プログラミング](https://qiita.com/tubo28/items/f058582e457f6870a800)