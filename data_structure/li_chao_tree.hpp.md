---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/LibraryChecker/data_structure/line_add_get_min.test.cpp
    title: test/LibraryChecker/data_structure/line_add_get_min.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/LibraryChecker/data_structure/segment_add_get_min.test.cpp
    title: test/LibraryChecker/data_structure/segment_add_get_min.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"data_structure/li_chao_tree.hpp\"\ntemplate<class T, T e,\
    \ int NODES = 30000000>\nstruct dynamic_li_chao_tree {\n    struct Line {\n  \
    \      T a, b;\n        Line (T _a = e, T _b = e) : a(_a), b(_b) {};\n       \
    \ T get_val (T x) {\n            return (a == e ? e : a * x + b);\n        }\n\
    \    };\n\n    struct Node {\n        inline static int node_count = 0;\n    \
    \    inline static Node* pool;\n        Line x;\n        Node *l, *r;\n      \
    \  Node () : x(), l(nullptr), r(nullptr) {}\n\n        void *operator new(size_t)\
    \ {\n            return pool + node_count++;\n        }\n    };\n\n    T x_min,\
    \ x_max;\n    Node *root;\n\n    dynamic_li_chao_tree (T _x_min, T _x_max) : x_min(_x_min),\
    \ x_max(_x_max), root(nullptr) {\n        Node::pool = new Node[NODES];\n    \
    \    root = new Node();\n    }\n\n    void add_line (T a, T b) {\n        add_seg({a,\
    \ b}, x_min, x_max, root, x_min, x_max);\n    }\n\n    void add_seg (T a, T b,\
    \ T l, T r) {\n        add_seg({a, b}, l, r, root, x_min, x_max);\n    }\n   \
    \ \n    T get_min (T i) {\n        return get_min(i, root, x_min, x_max);\n  \
    \  }\n\nprivate:\n    void add_seg (Line x, T a, T b, Node *node, T l, T r) {\n\
    \        if (b <= l || r <= a) return;\n        if (a <= l && r <= b) {\n    \
    \        if (node->x.get_val(l) >= x.get_val(l) && node->x.get_val(r - 1) >= x.get_val(r\
    \ - 1)) {\n                node->x = x;\n                return;\n           \
    \ }\n            if (node->x.get_val(l) <= x.get_val(l) && node->x.get_val(r -\
    \ 1) <= x.get_val(r - 1)) {\n                return;\n            }\n        }\n\
    \        if (node->l == nullptr) node->l = new Node();\n        if (node->r ==\
    \ nullptr) node->r = new Node();\n        add_seg(x, a, b, node->l, l, (l + r)\
    \ / 2);\n        add_seg(x, a, b, node->r, (l + r) / 2, r);\n    }\n\n    T get_min\
    \ (T i, Node *node, T l, T r) {\n        if (i < l || r <= i) return e;\n    \
    \    if (i <= l && r <= i + 1) return node->x.get_val(i);\n        T ret = (node->x.a\
    \ != e ? node->x.get_val(i) : e);\n        if (node->l != nullptr) ret = min(ret,\
    \ get_min(i, node->l, l, (l + r) / 2));\n        if (node->r != nullptr) ret =\
    \ min(ret, get_min(i, node->r, (l + r) / 2, r));\n        return ret;\n    }\n\
    };\n"
  code: "template<class T, T e, int NODES = 30000000>\nstruct dynamic_li_chao_tree\
    \ {\n    struct Line {\n        T a, b;\n        Line (T _a = e, T _b = e) : a(_a),\
    \ b(_b) {};\n        T get_val (T x) {\n            return (a == e ? e : a * x\
    \ + b);\n        }\n    };\n\n    struct Node {\n        inline static int node_count\
    \ = 0;\n        inline static Node* pool;\n        Line x;\n        Node *l, *r;\n\
    \        Node () : x(), l(nullptr), r(nullptr) {}\n\n        void *operator new(size_t)\
    \ {\n            return pool + node_count++;\n        }\n    };\n\n    T x_min,\
    \ x_max;\n    Node *root;\n\n    dynamic_li_chao_tree (T _x_min, T _x_max) : x_min(_x_min),\
    \ x_max(_x_max), root(nullptr) {\n        Node::pool = new Node[NODES];\n    \
    \    root = new Node();\n    }\n\n    void add_line (T a, T b) {\n        add_seg({a,\
    \ b}, x_min, x_max, root, x_min, x_max);\n    }\n\n    void add_seg (T a, T b,\
    \ T l, T r) {\n        add_seg({a, b}, l, r, root, x_min, x_max);\n    }\n   \
    \ \n    T get_min (T i) {\n        return get_min(i, root, x_min, x_max);\n  \
    \  }\n\nprivate:\n    void add_seg (Line x, T a, T b, Node *node, T l, T r) {\n\
    \        if (b <= l || r <= a) return;\n        if (a <= l && r <= b) {\n    \
    \        if (node->x.get_val(l) >= x.get_val(l) && node->x.get_val(r - 1) >= x.get_val(r\
    \ - 1)) {\n                node->x = x;\n                return;\n           \
    \ }\n            if (node->x.get_val(l) <= x.get_val(l) && node->x.get_val(r -\
    \ 1) <= x.get_val(r - 1)) {\n                return;\n            }\n        }\n\
    \        if (node->l == nullptr) node->l = new Node();\n        if (node->r ==\
    \ nullptr) node->r = new Node();\n        add_seg(x, a, b, node->l, l, (l + r)\
    \ / 2);\n        add_seg(x, a, b, node->r, (l + r) / 2, r);\n    }\n\n    T get_min\
    \ (T i, Node *node, T l, T r) {\n        if (i < l || r <= i) return e;\n    \
    \    if (i <= l && r <= i + 1) return node->x.get_val(i);\n        T ret = (node->x.a\
    \ != e ? node->x.get_val(i) : e);\n        if (node->l != nullptr) ret = min(ret,\
    \ get_min(i, node->l, l, (l + r) / 2));\n        if (node->r != nullptr) ret =\
    \ min(ret, get_min(i, node->r, (l + r) / 2, r));\n        return ret;\n    }\n\
    };"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/li_chao_tree.hpp
  requiredBy: []
  timestamp: '2024-05-02 19:46:37+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/LibraryChecker/data_structure/segment_add_get_min.test.cpp
  - test/LibraryChecker/data_structure/line_add_get_min.test.cpp
documentation_of: data_structure/li_chao_tree.hpp
layout: document
title: Li Chao Tree
---

## 参考にしたサイト

- [Li Chao Treeのメモ](https://smijake3.hatenablog.com/entry/2018/06/16/144548)
- [Dynamic-Li-Chao-Tree - Luzhiled's Library](https://ei1333.github.io/library/structure/convex-hull-trick/dynamic-li-chao-tree.hpp.html)