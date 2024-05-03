---
title: Union Find
documentation_of: ./union_find.hpp
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