---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/LibraryChecker/math/stern_brocot_tree.test.cpp
    title: test/LibraryChecker/math/stern_brocot_tree.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"math/stern_brocot_tree.hpp\"\ntemplate<class T>\nstruct\
    \ SBT_node {\n    T p, q, r, s;\n};\n\ntemplate<class T>\nstruct stern_brocot_tree\
    \ {\n    static SBT_node<T> child(SBT_node<T> node, bool isleft, T depth) {\n\
    \        if (isleft) return {node.p, node.q, node.p * depth + node.r, node.q *\
    \ depth + node.s};\n        else return {node.p + node.r * depth, node.q + node.s\
    \ * depth, node.r, node.s};\n    }\n\n    static vector<T> encode_path(T p, T\
    \ q) {\n        vector<T> a;\n        do {\n            a.emplace_back(p / q);\n\
    \            p %= q;\n            swap(p, q);\n        } while (q);\n        a[a.size()\
    \ - 1]--;\n        return a;\n    }\n\n    static SBT_node<T> decode_path(vector<T>\
    \ a) {\n        SBT_node<T> ret(0, 1, 1, 0);\n        bool isleft = false;\n \
    \       for (int i = 0; i < (int)a.size(); i++) {\n            ret = child(ret,\
    \ isleft, a[i]);\n            isleft = !isleft;\n        }\n        return ret;\n\
    \    }\n\n    static SBT_node<T> lca(T a, T b, T c, T d) {\n        auto x = encode_path(a,\
    \ b);\n        auto y = encode_path(c, d);\n        vector<T> z;\n        for\
    \ (int i = 0; i < (int)min(x.size(), y.size()); i++) {\n            z.emplace_back(min(x[i],\
    \ y[i]));\n            if (x[i] != y[i]) break;\n        }\n        return decode_path(z);\n\
    \    }\n\n    static SBT_node<T> ancestor(T k, T a, T b) {\n        auto x = encode_path(a,\
    \ b);\n        vector<T> y;\n        for (int i = 0; i < (int)x.size(); i++) {\n\
    \            if (k == 0) continue;\n            T mn = min(k, x[i]);\n       \
    \     y.push_back(mn);\n            k -= mn;\n        }\n        if (k) return\
    \ {0, 0, 0, 0};\n        else return decode_path(y);\n    }\n\n    static SBT_node<T>\
    \ range(T p, T q) {\n        return decode_path(encode_path(p, q));\n    }\n};\n"
  code: "template<class T>\nstruct SBT_node {\n    T p, q, r, s;\n};\n\ntemplate<class\
    \ T>\nstruct stern_brocot_tree {\n    static SBT_node<T> child(SBT_node<T> node,\
    \ bool isleft, T depth) {\n        if (isleft) return {node.p, node.q, node.p\
    \ * depth + node.r, node.q * depth + node.s};\n        else return {node.p + node.r\
    \ * depth, node.q + node.s * depth, node.r, node.s};\n    }\n\n    static vector<T>\
    \ encode_path(T p, T q) {\n        vector<T> a;\n        do {\n            a.emplace_back(p\
    \ / q);\n            p %= q;\n            swap(p, q);\n        } while (q);\n\
    \        a[a.size() - 1]--;\n        return a;\n    }\n\n    static SBT_node<T>\
    \ decode_path(vector<T> a) {\n        SBT_node<T> ret(0, 1, 1, 0);\n        bool\
    \ isleft = false;\n        for (int i = 0; i < (int)a.size(); i++) {\n       \
    \     ret = child(ret, isleft, a[i]);\n            isleft = !isleft;\n       \
    \ }\n        return ret;\n    }\n\n    static SBT_node<T> lca(T a, T b, T c, T\
    \ d) {\n        auto x = encode_path(a, b);\n        auto y = encode_path(c, d);\n\
    \        vector<T> z;\n        for (int i = 0; i < (int)min(x.size(), y.size());\
    \ i++) {\n            z.emplace_back(min(x[i], y[i]));\n            if (x[i] !=\
    \ y[i]) break;\n        }\n        return decode_path(z);\n    }\n\n    static\
    \ SBT_node<T> ancestor(T k, T a, T b) {\n        auto x = encode_path(a, b);\n\
    \        vector<T> y;\n        for (int i = 0; i < (int)x.size(); i++) {\n   \
    \         if (k == 0) continue;\n            T mn = min(k, x[i]);\n          \
    \  y.push_back(mn);\n            k -= mn;\n        }\n        if (k) return {0,\
    \ 0, 0, 0};\n        else return decode_path(y);\n    }\n\n    static SBT_node<T>\
    \ range(T p, T q) {\n        return decode_path(encode_path(p, q));\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: math/stern_brocot_tree.hpp
  requiredBy: []
  timestamp: '2024-04-27 04:27:49+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/LibraryChecker/math/stern_brocot_tree.test.cpp
documentation_of: math/stern_brocot_tree.hpp
layout: document
redirect_from:
- /library/math/stern_brocot_tree.hpp
- /library/math/stern_brocot_tree.hpp.html
title: math/stern_brocot_tree.hpp
---
