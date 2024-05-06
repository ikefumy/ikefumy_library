---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/binary_indexed_tree.hpp
    title: Binary Indexed Tree
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/LibraryChecker/data_structure/point_add_rectangle_sum_BIT_WM.test.cpp
    title: test/LibraryChecker/data_structure/point_add_rectangle_sum_BIT_WM.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"data_structure/binary_indexed_tree.hpp\"\ntemplate<class\
    \ T>\nstruct binary_indexed_tree {\n    int N;\n    vector<T> bit;\n    binary_indexed_tree\
    \ (int n = 0) : N(n), bit(n + 1, 0) {}\n    T sum(int i){\n        T s = 0;\n\
    \        while(i > 0){\n            s += bit[i];\n            i -= i & -i;\n \
    \       }\n        return s;\n    }\n\n    void add(int i, T x){\n        i++;\n\
    \        while(i <= N){\n            bit[i] += x;\n            i += i & -i;\n\
    \        }\n    }\n    T sum(int l, int r){\n        return sum(r) - sum(l);\n\
    \    }\n};\n#line 2 \"data_structure/BIT_on_wavelet_matrix.hpp\"\n\nstruct bit_vector\
    \ {\n    int n;\n    const int w = 64;\n    vector<uint64_t> b;\n    vector<int>\
    \ cnt;\n    bit_vector(int _n = 0) : n(_n), b(_n / w + 1), cnt(_n / w + 1) {}\n\
    \n    int access(int i) {\n        return b[i / w] >> (i % w) & 1;\n    }\n\n\
    \    void set(int i) {\n        b[i / w] |= 1ll << (i % w);\n    }\n\n    void\
    \ build() {\n        for (int i = 1; i < (int)cnt.size(); i++) {\n           \
    \ cnt[i] = cnt[i - 1] + popcount(b[i - 1]);\n        }\n    }\n\n    int rank0(int\
    \ i) {\n        return i - rank1(i);\n    }\n\n    int rank1(int i) {\n      \
    \  return cnt[i / w] + popcount(b[i / w] & ((1ull << (i % w)) - 1));\n    }\n\
    };\n\ntemplate<class T>\nstruct wavelet_matrix_2d {\n    int lg;\n    vector<bit_vector>\
    \ bv;\n    vector<int> zeros;\n    vector<binary_indexed_tree<T>> bit;\n    vector<T>\
    \ ys;\n    vector<pair<T, T>> xys;\n\n    wavelet_matrix_2d() {}\n\n    void add_point(T\
    \ x, T y) {\n        ys.push_back(y);\n        xys.push_back({x, y});\n    }\n\
    \n    void build() {\n        sort(ys.begin(), ys.end());\n        sort(xys.begin(),\
    \ xys.end());\n        ys.erase(unique(ys.begin(), ys.end()), ys.end());\n   \
    \     xys.erase(unique(xys.begin(), xys.end()), xys.end());\n        \n      \
    \  T mx = 1;\n        for (auto u : ys) mx = max(mx, u);\n        lg = log2(mx)\
    \ + 1;\n        bv = vector(lg, bit_vector(xys.size()));\n        zeros.resize(lg);\n\
    \        bit.resize(lg, binary_indexed_tree<T>(xys.size()));\n\n        vector<T>\
    \ crt(xys.size()), nxt(xys.size());\n        for (int i = 0; i < (int)xys.size();\
    \ i++) {\n            crt[i] = lower_bound(ys.begin(), ys.end(), xys[i].second)\
    \ - ys.begin();\n        }\n        for (int i = lg - 1; i >= 0; i--) {\n    \
    \        int ones = crt.size() - 1;\n            for (int j = 0; j < (int)crt.size();\
    \ j++) {\n                if (crt[j] >> i & 1) {\n                    bv[i].set(j);\n\
    \                    nxt[ones--] = crt[j];\n                } else {\n       \
    \             nxt[zeros[i]++] = crt[j];\n                }\n            }\n  \
    \          bv[i].build();\n            reverse(nxt.begin() + ones + 1, nxt.end());\n\
    \            swap(crt, nxt);\n        }\n    }\n\n    void add(T x, T y, T val)\
    \ {\n        auto it = lower_bound(xys.begin(), xys.end(), pair<T, T>{x, y}) -\
    \ xys.begin();\n        y = lower_bound(ys.begin(), ys.end(), y) - ys.begin();\n\
    \        for (int i = lg - 1; i >= 0; i--) {\n            int it0 = bv[i].rank0(it);\n\
    \            if (y >> i & 1) {\n                it += zeros[i] - it0;\n      \
    \      } else {\n                it = it0;\n            }\n            bit[i].add(it,\
    \ val);\n        }\n    }\n\n    int idx(T i) {\n        return lower_bound(xys.begin(),\
    \ xys.end(), pair<T, T>{i, i}, [&](pair<T, T> a, pair<T, T> b) {\n           \
    \ return a.first < b.second;\n        }) - xys.begin();\n    }\n\n    T get_sum(T\
    \ l, T r, T upper) {\n        T ret = 0;\n        l = idx(l), r = idx(r);\n  \
    \      upper = lower_bound(ys.begin(), ys.end(), upper) - ys.begin();\n      \
    \  for (int i = lg - 1; i >= 0; i--) {\n            int l0 = bv[i].rank0(l), r0\
    \ = bv[i].rank0(r);\n            if (upper >> i & 1) {\n                ret +=\
    \ bit[i].sum(l0, r0);\n                l += zeros[i] - l0;\n                r\
    \ += zeros[i] - r0;\n            } else {\n                l = l0;\n         \
    \       r = r0;\n            }\n        }\n        return ret;\n    }\n\n    T\
    \ get_sum(T l, T r, T lower, T upper) {\n        return get_sum(l, r, upper) -\
    \ get_sum(l, r, lower);\n    }\n};\n"
  code: "#include \"./binary_indexed_tree.hpp\"\n\nstruct bit_vector {\n    int n;\n\
    \    const int w = 64;\n    vector<uint64_t> b;\n    vector<int> cnt;\n    bit_vector(int\
    \ _n = 0) : n(_n), b(_n / w + 1), cnt(_n / w + 1) {}\n\n    int access(int i)\
    \ {\n        return b[i / w] >> (i % w) & 1;\n    }\n\n    void set(int i) {\n\
    \        b[i / w] |= 1ll << (i % w);\n    }\n\n    void build() {\n        for\
    \ (int i = 1; i < (int)cnt.size(); i++) {\n            cnt[i] = cnt[i - 1] + popcount(b[i\
    \ - 1]);\n        }\n    }\n\n    int rank0(int i) {\n        return i - rank1(i);\n\
    \    }\n\n    int rank1(int i) {\n        return cnt[i / w] + popcount(b[i / w]\
    \ & ((1ull << (i % w)) - 1));\n    }\n};\n\ntemplate<class T>\nstruct wavelet_matrix_2d\
    \ {\n    int lg;\n    vector<bit_vector> bv;\n    vector<int> zeros;\n    vector<binary_indexed_tree<T>>\
    \ bit;\n    vector<T> ys;\n    vector<pair<T, T>> xys;\n\n    wavelet_matrix_2d()\
    \ {}\n\n    void add_point(T x, T y) {\n        ys.push_back(y);\n        xys.push_back({x,\
    \ y});\n    }\n\n    void build() {\n        sort(ys.begin(), ys.end());\n   \
    \     sort(xys.begin(), xys.end());\n        ys.erase(unique(ys.begin(), ys.end()),\
    \ ys.end());\n        xys.erase(unique(xys.begin(), xys.end()), xys.end());\n\
    \        \n        T mx = 1;\n        for (auto u : ys) mx = max(mx, u);\n   \
    \     lg = log2(mx) + 1;\n        bv = vector(lg, bit_vector(xys.size()));\n \
    \       zeros.resize(lg);\n        bit.resize(lg, binary_indexed_tree<T>(xys.size()));\n\
    \n        vector<T> crt(xys.size()), nxt(xys.size());\n        for (int i = 0;\
    \ i < (int)xys.size(); i++) {\n            crt[i] = lower_bound(ys.begin(), ys.end(),\
    \ xys[i].second) - ys.begin();\n        }\n        for (int i = lg - 1; i >= 0;\
    \ i--) {\n            int ones = crt.size() - 1;\n            for (int j = 0;\
    \ j < (int)crt.size(); j++) {\n                if (crt[j] >> i & 1) {\n      \
    \              bv[i].set(j);\n                    nxt[ones--] = crt[j];\n    \
    \            } else {\n                    nxt[zeros[i]++] = crt[j];\n       \
    \         }\n            }\n            bv[i].build();\n            reverse(nxt.begin()\
    \ + ones + 1, nxt.end());\n            swap(crt, nxt);\n        }\n    }\n\n \
    \   void add(T x, T y, T val) {\n        auto it = lower_bound(xys.begin(), xys.end(),\
    \ pair<T, T>{x, y}) - xys.begin();\n        y = lower_bound(ys.begin(), ys.end(),\
    \ y) - ys.begin();\n        for (int i = lg - 1; i >= 0; i--) {\n            int\
    \ it0 = bv[i].rank0(it);\n            if (y >> i & 1) {\n                it +=\
    \ zeros[i] - it0;\n            } else {\n                it = it0;\n         \
    \   }\n            bit[i].add(it, val);\n        }\n    }\n\n    int idx(T i)\
    \ {\n        return lower_bound(xys.begin(), xys.end(), pair<T, T>{i, i}, [&](pair<T,\
    \ T> a, pair<T, T> b) {\n            return a.first < b.second;\n        }) -\
    \ xys.begin();\n    }\n\n    T get_sum(T l, T r, T upper) {\n        T ret = 0;\n\
    \        l = idx(l), r = idx(r);\n        upper = lower_bound(ys.begin(), ys.end(),\
    \ upper) - ys.begin();\n        for (int i = lg - 1; i >= 0; i--) {\n        \
    \    int l0 = bv[i].rank0(l), r0 = bv[i].rank0(r);\n            if (upper >> i\
    \ & 1) {\n                ret += bit[i].sum(l0, r0);\n                l += zeros[i]\
    \ - l0;\n                r += zeros[i] - r0;\n            } else {\n         \
    \       l = l0;\n                r = r0;\n            }\n        }\n        return\
    \ ret;\n    }\n\n    T get_sum(T l, T r, T lower, T upper) {\n        return get_sum(l,\
    \ r, upper) - get_sum(l, r, lower);\n    }\n};"
  dependsOn:
  - data_structure/binary_indexed_tree.hpp
  isVerificationFile: false
  path: data_structure/BIT_on_wavelet_matrix.hpp
  requiredBy: []
  timestamp: '2024-05-07 03:31:27+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/LibraryChecker/data_structure/point_add_rectangle_sum_BIT_WM.test.cpp
documentation_of: data_structure/BIT_on_wavelet_matrix.hpp
layout: document
title: BIT on Wavelet Matrix
---

矩形で加算クエリしか来ないならこっちの方が良い。