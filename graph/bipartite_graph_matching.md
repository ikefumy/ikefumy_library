---
title: 二部マッチング
documentation_of: ./bipartite_graph_matching.hpp
---

## 使い方
- `void add_edge(int u, int v)`
    - L側の頂点$u$とR側の頂点$v$を結ぶ。
- `set_cap(bool isL, int v, int cap)`
    - `isL`が`true`のとき、L側の頂点$v$のマッチングさせる回数の上限を$cap$に変更する。
- `vector<pair<int, int>> matching()`
    - マッチングを行い、マッチングが成立した辺のリストを返す。