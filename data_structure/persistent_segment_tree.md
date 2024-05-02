---
title: 永続セグ木
documentation_of: ./persistent_segment_tree.hpp
---

## 使い方
- `update(i, x, id)` : $id$番目に生成されたセグ木において、$i$番目の要素を$x$し、戻り値として生成したセグ木の$id$を返す。$id$を指定しなかったとき、最新のセグ木を基に生成する。
- `prod(a, b, id)` : $id$番目に生成されたセグ木において、$i$番目の要素を$x[i]$と表したとき、$op(x[a],x[a+1],...,x[b-1])$を返す。

## 参考にしたサイト

- [永続セグメント木 - Nyaan's Library](https://nyaannyaan.github.io/library/segment-tree/persistent-segment-tree.hpp.html)
- [木構造の実装テクニック #競技プログラミング](https://qiita.com/tubo28/items/f058582e457f6870a800)