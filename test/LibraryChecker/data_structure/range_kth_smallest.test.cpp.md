---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/wavelet_matrix.hpp
    title: Wavelet Matrix
  - icon: ':heavy_check_mark:'
    path: template/template.hpp
    title: template/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/range_kth_smallest
    links:
    - https://judge.yosupo.jp/problem/range_kth_smallest
  bundledCode: "#line 1 \"test/LibraryChecker/data_structure/range_kth_smallest.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/range_kth_smallest\"\n\n#line\
    \ 1 \"template/template.hpp\"\n#include<bits/stdc++.h>\nusing namespace std;\n\
    #define ll long long\n#define ull unsigned long long\n#define db double\n#define\
    \ pii pair<int,int>\n#define pli pair<ll,int>\n#define pil pair<int,ll>\n#define\
    \ pll pair<ll,ll>\n#define ti3 tuple<int,int,int>\n#define int128 __int128_t\n\
    #define pii128 pair<int128,int128>\nconst int inf = 1 << 30;\nconst ll linf =\
    \ (ll)4e18 + 10;\nconst db EPS = 1e-10;\nconst db pi = acos(-1);\ntemplate<class\
    \ T> bool chmin(T& x, T y){\n    if(x > y) {\n        x = y;\n        return true;\n\
    \    } else return false;\n}\ntemplate<class T> bool chmax(T& x, T y){\n    if(x\
    \ < y) {\n        x = y;\n        return true;\n    } else return false;\n}\n\n\
    // overload macro\n#define CAT( A, B ) A ## B\n#define SELECT( NAME, NUM ) CAT(\
    \ NAME, NUM )\n\n#define GET_COUNT( _1, _2, _3, _4, _5, _6 /* ad nauseam */, COUNT,\
    \ ... ) COUNT\n#define VA_SIZE( ... ) GET_COUNT( __VA_ARGS__, 6, 5, 4, 3, 2, 1\
    \ )\n\n#define VA_SELECT( NAME, ... ) SELECT( NAME, VA_SIZE(__VA_ARGS__) )(__VA_ARGS__)\n\
    \n// rep(overload)\n#define rep( ... ) VA_SELECT(rep, __VA_ARGS__)\n#define rep2(i,\
    \ n) for (int i = 0; i < int(n); i++)\n#define rep3(i, a, b) for (int i = a; i\
    \ < int(b); i++)\n#define rep4(i, a, b, c) for (int i = a; i < int(b); i += c)\n\
    \n// repll(overload)\n#define repll( ... ) VA_SELECT(repll, __VA_ARGS__)\n#define\
    \ repll2(i, n) for (ll i = 0; i < (ll)(n); i++)\n#define repll3(i, a, b) for (ll\
    \ i = a; i < (ll)(b); i++)\n#define repll4(i, a, b, c) for (ll i = a; i < (ll)(b);\
    \ i += c)\n\n// rrep(overload)\n#define rrep( ... ) VA_SELECT(rrep, __VA_ARGS__)\
    \    \n#define rrep2(i, n) for (int i = n - 1; i >= 0; i--)\n#define rrep3(i,\
    \ a, b) for (int i = b - 1; i >= a; i--)\n#define rrep4(i, a, b, c) for (int i\
    \ = b - 1; i >= a; i -= c)\n\n// rrepll(overload)\n#define rrepll( ... ) VA_SELECT(rrepll,\
    \ __VA_ARGS__)\n#define rrepll2(i, n) for (ll i = (ll)(n) - 1; i >= 0ll; i--)\n\
    #define rrepll3(i, a, b) for (ll i = b - 1; i >= (ll)(a); i--)\n#define rrepll4(i,\
    \ a, b, c) for (ll i = b - 1; i >= (ll)(a); i -= c)\n\n// for_earh\n#define fore(e,\
    \ v) for (auto&& e : v)\n\n// vector\n#define all(v) v.begin(), v.end()\n#define\
    \ rall(v) v.rbegin(), v.rend()\n#line 1 \"data_structure/wavelet_matrix.hpp\"\n\
    struct bit_vector {\n    int n;\n    const int w = 64;\n    vector<uint64_t> b;\n\
    \    vector<int> cnt;\n    bit_vector(int _n = 0) : n(_n), b(_n / w + 1), cnt(_n\
    \ / w + 1) {}\n\n    int access(int i) {\n        return b[i / w] >> (i % w) &\
    \ 1;\n    }\n\n    void set(int i) {\n        b[i / w] |= 1ll << (i % w);\n  \
    \  }\n\n    void build() {\n        for (int i = 1; i < (int)cnt.size(); i++)\
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
    \ kth_max(l, r, cnt);\n    }\n};\n#line 5 \"test/LibraryChecker/data_structure/range_kth_smallest.test.cpp\"\
    \n\nint N, Q;\nint main() {\n    cin.tie(nullptr);\n    ios_base::sync_with_stdio(false);\n\
    \    cout << fixed << setprecision(20);\n    cin >> N >> Q;\n    vector<int> A(N);\n\
    \    rep (i, N) cin >> A[i];\n    wavelet_matrix wm(A);\n    rep (i, Q) {\n  \
    \      int l, r, x;\n        cin >> l >> r >> x;\n        cout << wm.kth_max(l,\
    \ r, r - l - x - 1) << '\\n';\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/range_kth_smallest\"\n\n\
    #include \"../../../template/template.hpp\"\n#include \"../../../data_structure/wavelet_matrix.hpp\"\
    \n\nint N, Q;\nint main() {\n    cin.tie(nullptr);\n    ios_base::sync_with_stdio(false);\n\
    \    cout << fixed << setprecision(20);\n    cin >> N >> Q;\n    vector<int> A(N);\n\
    \    rep (i, N) cin >> A[i];\n    wavelet_matrix wm(A);\n    rep (i, Q) {\n  \
    \      int l, r, x;\n        cin >> l >> r >> x;\n        cout << wm.kth_max(l,\
    \ r, r - l - x - 1) << '\\n';\n    }\n}"
  dependsOn:
  - template/template.hpp
  - data_structure/wavelet_matrix.hpp
  isVerificationFile: true
  path: test/LibraryChecker/data_structure/range_kth_smallest.test.cpp
  requiredBy: []
  timestamp: '2024-05-07 03:31:27+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/LibraryChecker/data_structure/range_kth_smallest.test.cpp
layout: document
redirect_from:
- /verify/test/LibraryChecker/data_structure/range_kth_smallest.test.cpp
- /verify/test/LibraryChecker/data_structure/range_kth_smallest.test.cpp.html
title: test/LibraryChecker/data_structure/range_kth_smallest.test.cpp
---
