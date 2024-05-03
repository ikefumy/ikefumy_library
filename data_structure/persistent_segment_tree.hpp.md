---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"data_structure/persistent_segment_tree.hpp\"\ntemplate<class\
    \ T, T(* op)(T, T), T(* e)(), int NODES = 2700000>\nstruct persistent_segment_tree\
    \ {\n    struct Node {\n        inline static int node_count = 0;\n        inline\
    \ static Node* pool;\n        T val;\n        Node *l, *r;\n\n        Node ()\
    \ : val(e()), l(nullptr), r(nullptr) {}\n        void *operator new(size_t) {\n\
    \            return pool + node_count++;\n        }\n        inline static void\
    \ delete_all() { Node::node_count = 0; }\n    };\n\n    int n;\n    vector<Node\
    \ *> roots;\n    stack<Node *> nodes;\n    stack<tuple<Node *, int, int>> rng;\n\
    \n    persistent_segment_tree(int _n) : n(1) {\n        Node::pool = new Node[NODES];\n\
    \        while (n < _n) n *= 2;\n        roots.push_back(new Node());\n      \
    \  queue<tuple<Node *, int ,int>> que;\n        que.push({roots[0], 0, n});\n\
    \        while (!que.empty()) {\n            auto [node, l, r] = que.front();\
    \ que.pop();\n            if (r == l + 1) continue;\n            node->l = new\
    \ Node();\n            node->r = new Node();\n            que.push({node->l, l,\
    \ (l + r) / 2});\n            que.push({node->r, (l + r) / 2, r});\n        }\n\
    \    }\n\n    int update(int i, T x, int id = -1) {\n        if (id < 0) id =\
    \ roots.size() - 1;\n        Node *pre = roots[id];\n        Node *crt = new Node();\n\
    \        roots.push_back(crt);\n        // \u66F4\u65B0\u3059\u308Bnode\u3092\u63A2\
    \u3059\n        int l = 0, r = n;\n        while (l + 1 < r) {\n            nodes.push(crt);\n\
    \            if (i < (l + r) / 2) {\n                crt->l = new Node();\n  \
    \              crt->r = pre->r;\n                crt = crt->l;\n             \
    \   pre = pre->l;\n                r = (l + r) / 2;\n            } else {\n  \
    \              crt->l = pre->l;\n                crt->r = new Node();\n      \
    \          crt = crt->r;\n                pre = pre->r;\n                l = (l\
    \ + r) / 2;\n            }\n        }\n        // \u66F4\u65B0\u3059\u308B\n \
    \       crt->val = x;\n        while (!nodes.empty()) {\n            crt = nodes.top();\
    \ nodes.pop();\n            crt->val = op(crt->l->val, crt->r->val);\n       \
    \ }\n        return roots.size() - 1;\n    }\n\n    T prod(int a, int b, int id\
    \ = -1) {\n        if (id == -1) id = roots.size() - 1;\n        int l = 0, r\
    \ = n;\n        rng.push({roots[id], l, r});\n        T ret = e();\n        while\
    \ (!rng.empty()) {\n            auto [node, l, r] = rng.top(); rng.pop();\n  \
    \          if (b <= l || r <= a) continue;\n            if (a <= l && r <= b)\
    \ {\n                ret = op(ret, node->val);\n            } else {\n       \
    \         rng.push({node->r, (l + r) / 2, r});\n                rng.push({node->l,\
    \ l, (l + r) / 2});\n            }\n        }\n        return ret;\n    }\n\n\
    \    ~persistent_segment_tree() {\n        delete[] Node::pool;\n    }\n};\n"
  code: "template<class T, T(* op)(T, T), T(* e)(), int NODES = 2700000>\nstruct persistent_segment_tree\
    \ {\n    struct Node {\n        inline static int node_count = 0;\n        inline\
    \ static Node* pool;\n        T val;\n        Node *l, *r;\n\n        Node ()\
    \ : val(e()), l(nullptr), r(nullptr) {}\n        void *operator new(size_t) {\n\
    \            return pool + node_count++;\n        }\n        inline static void\
    \ delete_all() { Node::node_count = 0; }\n    };\n\n    int n;\n    vector<Node\
    \ *> roots;\n    stack<Node *> nodes;\n    stack<tuple<Node *, int, int>> rng;\n\
    \n    persistent_segment_tree(int _n) : n(1) {\n        Node::pool = new Node[NODES];\n\
    \        while (n < _n) n *= 2;\n        roots.push_back(new Node());\n      \
    \  queue<tuple<Node *, int ,int>> que;\n        que.push({roots[0], 0, n});\n\
    \        while (!que.empty()) {\n            auto [node, l, r] = que.front();\
    \ que.pop();\n            if (r == l + 1) continue;\n            node->l = new\
    \ Node();\n            node->r = new Node();\n            que.push({node->l, l,\
    \ (l + r) / 2});\n            que.push({node->r, (l + r) / 2, r});\n        }\n\
    \    }\n\n    int update(int i, T x, int id = -1) {\n        if (id < 0) id =\
    \ roots.size() - 1;\n        Node *pre = roots[id];\n        Node *crt = new Node();\n\
    \        roots.push_back(crt);\n        // \u66F4\u65B0\u3059\u308Bnode\u3092\u63A2\
    \u3059\n        int l = 0, r = n;\n        while (l + 1 < r) {\n            nodes.push(crt);\n\
    \            if (i < (l + r) / 2) {\n                crt->l = new Node();\n  \
    \              crt->r = pre->r;\n                crt = crt->l;\n             \
    \   pre = pre->l;\n                r = (l + r) / 2;\n            } else {\n  \
    \              crt->l = pre->l;\n                crt->r = new Node();\n      \
    \          crt = crt->r;\n                pre = pre->r;\n                l = (l\
    \ + r) / 2;\n            }\n        }\n        // \u66F4\u65B0\u3059\u308B\n \
    \       crt->val = x;\n        while (!nodes.empty()) {\n            crt = nodes.top();\
    \ nodes.pop();\n            crt->val = op(crt->l->val, crt->r->val);\n       \
    \ }\n        return roots.size() - 1;\n    }\n\n    T prod(int a, int b, int id\
    \ = -1) {\n        if (id == -1) id = roots.size() - 1;\n        int l = 0, r\
    \ = n;\n        rng.push({roots[id], l, r});\n        T ret = e();\n        while\
    \ (!rng.empty()) {\n            auto [node, l, r] = rng.top(); rng.pop();\n  \
    \          if (b <= l || r <= a) continue;\n            if (a <= l && r <= b)\
    \ {\n                ret = op(ret, node->val);\n            } else {\n       \
    \         rng.push({node->r, (l + r) / 2, r});\n                rng.push({node->l,\
    \ l, (l + r) / 2});\n            }\n        }\n        return ret;\n    }\n\n\
    \    ~persistent_segment_tree() {\n        delete[] Node::pool;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/persistent_segment_tree.hpp
  requiredBy: []
  timestamp: '2024-05-03 21:18:36+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data_structure/persistent_segment_tree.hpp
layout: document
title: "\u6C38\u7D9A\u30BB\u30B0\u6728"
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