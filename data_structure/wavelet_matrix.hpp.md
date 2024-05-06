---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AOJ/1549.test.cpp
    title: test/AOJ/1549.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/LibraryChecker/data_structure/range_kth_smallest.test.cpp
    title: test/LibraryChecker/data_structure/range_kth_smallest.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/LibraryChecker/data_structure/static_range_frequency.test.cpp
    title: test/LibraryChecker/data_structure/static_range_frequency.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"data_structure/wavelet_matrix.hpp\"\nstruct bit_vector {\n\
    \    int n;\n    const int w = 64;\n    vector<uint64_t> b;\n    vector<int> cnt;\n\
    \    bit_vector(int _n = 0) : n(_n), b(_n / w + 1), cnt(_n / w + 1) {}\n\n   \
    \ int access(int i) {\n        return b[i / w] >> (i % w) & 1;\n    }\n\n    void\
    \ set(int i) {\n        b[i / w] |= 1ll << (i % w);\n    }\n\n    void build()\
    \ {\n        for (int i = 1; i < (int)cnt.size(); i++) {\n            cnt[i] =\
    \ cnt[i - 1] + popcount(b[i - 1]);\n        }\n    }\n\n    int rank0(int i) {\n\
    \        return i - rank1(i);\n    }\n\n    int rank1(int i) {\n        return\
    \ cnt[i / w] + popcount(b[i / w] & ((1ull << (i % w)) - 1));\n    }\n};\n\ntemplate<class\
    \ T>\nstruct wavelet_matrix {\n    int lg;\n    vector<bit_vector> bv;\n    vector<int>\
    \ zeros;\n\n    wavelet_matrix(vector<T> a) {\n        for (auto u : a) lg = max(lg,\
    \ u);\n        lg = log2(lg) + 1;\n        bv = vector(lg, bit_vector(a.size()));\n\
    \        zeros.resize(lg);\n        vector<T> crt = a, nxt(a.size());\n      \
    \  for (int i = lg - 1; i >= 0; i--) {\n            int ones = a.size() - 1;\n\
    \            for (int j = 0; j < a.size(); j++) {\n                if (crt[j]\
    \ >> i & 1) {\n                    bv[i].set(j);\n                    nxt[ones--]\
    \ = crt[j];\n                } else {\n                    nxt[zeros[i]++] = crt[j];\n\
    \                }\n            }\n            bv[i].build();\n            reverse(nxt.begin()\
    \ + ones + 1, nxt.end());\n            swap(crt, nxt);\n        }\n    }\n\n \
    \   T access(int x) {\n        T ret = 0;\n        for (int i = lg - 1; i >= 0;\
    \ i--) {\n            if (bv[i].access(x)) {\n                ret |= (T)1 << i;\n\
    \                x = zeros[i] + bv[i].rank1(x);\n            } else {\n      \
    \          x = bv[i].rank0(x);\n            }\n        }\n        return ret;\n\
    \    }\n\n    T kth_min(int l, int r, int k) {\n        T ret = 0;\n        for\
    \ (int i = lg - 1; i >= 0; i--) {\n            int l0 = bv[i].rank0(l), r0 = bv[i].rank0(r);\n\
    \            if (k < r0 - l0) {\n                l = l0;\n                r =\
    \ r0;\n            } else {\n                k -= r0 - l0;\n                ret\
    \ |= (T)1 << i;\n                l += zeros[i] - l0;\n                r += zeros[i]\
    \ - r0;\n            }\n        }\n        return ret;\n    }\n\n    T kth_max(int\
    \ l, int r, int k) {\n        return kth_min(l, r, r - l - k - 1);\n    }\n\n\
    \    T count_lt_k(int l, int r, T k) {\n        int ret = 0;\n        for (int\
    \ i = lg - 1; i >= 0; i--) {\n            int l0 = bv[i].rank0(l), r0 = bv[i].rank0(r);\n\
    \            if (k >> i & 1) {\n                ret += r0 - l0;\n            \
    \    l += zeros[i] - l0;\n                r += zeros[i] - r0;\n            } else\
    \ {\n                l = l0;\n                r = r0;\n            }\n       \
    \ }\n        return ret;\n    }\n\n    T count_k(int l, int r, T k) {\n      \
    \  for (int i = lg - 1; i >= 0; i--) {\n            int l0 = bv[i].rank0(l), r0\
    \ = bv[i].rank0(r);\n            if (k >> i & 1) {\n                l += zeros[i]\
    \ - l0;\n                r += zeros[i] - r0;\n            } else {\n         \
    \       l = l0;\n                r = r0;\n            }\n        }\n        return\
    \ r - l;\n    }\n\n    T count_gt_k(int l, int r, T k) {\n        int ret = 0;\n\
    \        for (int i = lg - 1; i >= 0; i--) {\n            int l0 = bv[i].rank0(l),\
    \ r0 = bv[i].rank0(r);\n            if (k >> i & 1) {\n                l += zeros[i]\
    \ - l0;\n                r += zeros[i] - r0;\n            } else {\n         \
    \       ret += r - l - r0 + l0;\n                l = l0;\n                r =\
    \ r0;\n            }\n        }\n        return ret;\n    }\n\n    T range_freq(int\
    \ l, int r, T lower, T upper) {\n        return count_lt_k(l, r, upper) - count_lt_k(l,\
    \ r, lower);\n    }\n\n    T next_value(int l, int r, T k) {\n        int cnt\
    \ = count_lt_k(l, r, k);\n        if (r - l == cnt) return -1;\n        else return\
    \ kth_min(l, r, cnt);\n    }\n\n    T prev_value(int l, int r, T k) {\n      \
    \  int cnt = count_gt_k(l, r, k);\n        if (r - l == cnt) return -1;\n    \
    \    else return kth_max(l, r, cnt);\n    }\n};\n"
  code: "struct bit_vector {\n    int n;\n    const int w = 64;\n    vector<uint64_t>\
    \ b;\n    vector<int> cnt;\n    bit_vector(int _n = 0) : n(_n), b(_n / w + 1),\
    \ cnt(_n / w + 1) {}\n\n    int access(int i) {\n        return b[i / w] >> (i\
    \ % w) & 1;\n    }\n\n    void set(int i) {\n        b[i / w] |= 1ll << (i % w);\n\
    \    }\n\n    void build() {\n        for (int i = 1; i < (int)cnt.size(); i++)\
    \ {\n            cnt[i] = cnt[i - 1] + popcount(b[i - 1]);\n        }\n    }\n\
    \n    int rank0(int i) {\n        return i - rank1(i);\n    }\n\n    int rank1(int\
    \ i) {\n        return cnt[i / w] + popcount(b[i / w] & ((1ull << (i % w)) - 1));\n\
    \    }\n};\n\ntemplate<class T>\nstruct wavelet_matrix {\n    int lg;\n    vector<bit_vector>\
    \ bv;\n    vector<int> zeros;\n\n    wavelet_matrix(vector<T> a) {\n        for\
    \ (auto u : a) lg = max(lg, u);\n        lg = log2(lg) + 1;\n        bv = vector(lg,\
    \ bit_vector(a.size()));\n        zeros.resize(lg);\n        vector<T> crt = a,\
    \ nxt(a.size());\n        for (int i = lg - 1; i >= 0; i--) {\n            int\
    \ ones = a.size() - 1;\n            for (int j = 0; j < a.size(); j++) {\n   \
    \             if (crt[j] >> i & 1) {\n                    bv[i].set(j);\n    \
    \                nxt[ones--] = crt[j];\n                } else {\n           \
    \         nxt[zeros[i]++] = crt[j];\n                }\n            }\n      \
    \      bv[i].build();\n            reverse(nxt.begin() + ones + 1, nxt.end());\n\
    \            swap(crt, nxt);\n        }\n    }\n\n    T access(int x) {\n    \
    \    T ret = 0;\n        for (int i = lg - 1; i >= 0; i--) {\n            if (bv[i].access(x))\
    \ {\n                ret |= (T)1 << i;\n                x = zeros[i] + bv[i].rank1(x);\n\
    \            } else {\n                x = bv[i].rank0(x);\n            }\n  \
    \      }\n        return ret;\n    }\n\n    T kth_min(int l, int r, int k) {\n\
    \        T ret = 0;\n        for (int i = lg - 1; i >= 0; i--) {\n           \
    \ int l0 = bv[i].rank0(l), r0 = bv[i].rank0(r);\n            if (k < r0 - l0)\
    \ {\n                l = l0;\n                r = r0;\n            } else {\n\
    \                k -= r0 - l0;\n                ret |= (T)1 << i;\n          \
    \      l += zeros[i] - l0;\n                r += zeros[i] - r0;\n            }\n\
    \        }\n        return ret;\n    }\n\n    T kth_max(int l, int r, int k) {\n\
    \        return kth_min(l, r, r - l - k - 1);\n    }\n\n    T count_lt_k(int l,\
    \ int r, T k) {\n        int ret = 0;\n        for (int i = lg - 1; i >= 0; i--)\
    \ {\n            int l0 = bv[i].rank0(l), r0 = bv[i].rank0(r);\n            if\
    \ (k >> i & 1) {\n                ret += r0 - l0;\n                l += zeros[i]\
    \ - l0;\n                r += zeros[i] - r0;\n            } else {\n         \
    \       l = l0;\n                r = r0;\n            }\n        }\n        return\
    \ ret;\n    }\n\n    T count_k(int l, int r, T k) {\n        for (int i = lg -\
    \ 1; i >= 0; i--) {\n            int l0 = bv[i].rank0(l), r0 = bv[i].rank0(r);\n\
    \            if (k >> i & 1) {\n                l += zeros[i] - l0;\n        \
    \        r += zeros[i] - r0;\n            } else {\n                l = l0;\n\
    \                r = r0;\n            }\n        }\n        return r - l;\n  \
    \  }\n\n    T count_gt_k(int l, int r, T k) {\n        int ret = 0;\n        for\
    \ (int i = lg - 1; i >= 0; i--) {\n            int l0 = bv[i].rank0(l), r0 = bv[i].rank0(r);\n\
    \            if (k >> i & 1) {\n                l += zeros[i] - l0;\n        \
    \        r += zeros[i] - r0;\n            } else {\n                ret += r -\
    \ l - r0 + l0;\n                l = l0;\n                r = r0;\n           \
    \ }\n        }\n        return ret;\n    }\n\n    T range_freq(int l, int r, T\
    \ lower, T upper) {\n        return count_lt_k(l, r, upper) - count_lt_k(l, r,\
    \ lower);\n    }\n\n    T next_value(int l, int r, T k) {\n        int cnt = count_lt_k(l,\
    \ r, k);\n        if (r - l == cnt) return -1;\n        else return kth_min(l,\
    \ r, cnt);\n    }\n\n    T prev_value(int l, int r, T k) {\n        int cnt =\
    \ count_gt_k(l, r, k);\n        if (r - l == cnt) return -1;\n        else return\
    \ kth_max(l, r, cnt);\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/wavelet_matrix.hpp
  requiredBy: []
  timestamp: '2024-05-06 21:59:55+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/LibraryChecker/data_structure/range_kth_smallest.test.cpp
  - test/LibraryChecker/data_structure/static_range_frequency.test.cpp
  - test/AOJ/1549.test.cpp
documentation_of: data_structure/wavelet_matrix.hpp
layout: document
title: Wavelet Matrix
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