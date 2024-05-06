---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/segment_tree.hpp
    title: Segment Tree
  - icon: ':heavy_check_mark:'
    path: data_structure/segment_tree_on_wavelet_matrix.hpp
    title: Segment Tree on Wavelet Matrix
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
    PROBLEM: https://judge.yosupo.jp/problem/point_add_rectangle_sum
    links:
    - https://judge.yosupo.jp/problem/point_add_rectangle_sum
  bundledCode: "#line 1 \"test/LibraryChecker/data_structure/point_add_rectangle_sum_SegTree_WM.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_rectangle_sum\"\n\
    \n#line 1 \"template/template.hpp\"\n#include<bits/stdc++.h>\nusing namespace\
    \ std;\n#define ll long long\n#define ull unsigned long long\n#define db double\n\
    #define pii pair<int,int>\n#define pli pair<ll,int>\n#define pil pair<int,ll>\n\
    #define pll pair<ll,ll>\n#define ti3 tuple<int,int,int>\n#define int128 __int128_t\n\
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
    \ rall(v) v.rbegin(), v.rend()\n#line 1 \"data_structure/segment_tree.hpp\"\n\
    template<class T, T(* op)(T, T), T(* e)()>\nstruct segment_tree {\n    int N;\n\
    \    vector<T> node;\n\n    segment_tree(int n = 0) {\n        N = 1;\n      \
    \  while(N < n) N *= 2;\n        node.resize(N * 2 - 1, e());\n    }\n\n    void\
    \ set (int i, T x) {\n        i += N - 1;\n        node[i] = x;\n        while\
    \ (i > 0) {\n            i = (i - 1) / 2;\n            node[i] = op(node[i * 2\
    \ + 1], node[i * 2 + 2]);\n        }\n    }\n\n    void update (int i, T x) {\n\
    \        set (i, op(node[i + N - 1], x));\n    }\n\n    T get_val (int a, int\
    \ b, int k = 0, int l = 0, int r = -1) {\n        if (r == -1) r = N;\n      \
    \  if (b <= l || r <= a) return e();\n        if (a <= l && r <= b) return node[k];\n\
    \n        T vl = get_val(a, b, k * 2 + 1, l, (l + r) / 2);\n        T vr = get_val(a,\
    \ b, k * 2 + 2, (l + r) / 2, r);\n        return op(vl, vr);\n    }\n};\n#line\
    \ 2 \"data_structure/segment_tree_on_wavelet_matrix.hpp\"\n\nstruct bit_vector\
    \ {\n    int n;\n    const int w = 64;\n    vector<uint64_t> b;\n    vector<int>\
    \ cnt;\n    bit_vector(int _n = 0) : n(_n), b(_n / w + 1), cnt(_n / w + 1) {}\n\
    \n    int access(int i) {\n        return b[i / w] >> (i % w) & 1;\n    }\n\n\
    \    void set(int i) {\n        b[i / w] |= 1ll << (i % w);\n    }\n\n    void\
    \ build() {\n        for (int i = 1; i < (int)cnt.size(); i++) {\n           \
    \ cnt[i] = cnt[i - 1] + popcount(b[i - 1]);\n        }\n    }\n\n    int rank0(int\
    \ i) {\n        return i - rank1(i);\n    }\n\n    int rank1(int i) {\n      \
    \  return cnt[i / w] + popcount(b[i / w] & ((1ull << (i % w)) - 1));\n    }\n\
    };\n\ntemplate<class T, T(* op)(T, T), T(* e)()>\nstruct wavelet_matrix_2d {\n\
    \    int lg;\n    vector<bit_vector> bv;\n    vector<int> zeros;\n    vector<segment_tree<T,\
    \ op, e>> st;\n    vector<T> ys;\n    vector<pair<T, T>> xys;\n\n    wavelet_matrix_2d()\
    \ {}\n\n    void add_point(T x, T y) {\n        ys.push_back(y);\n        xys.push_back({x,\
    \ y});\n    }\n\n    void build() {\n        sort(ys.begin(), ys.end());\n   \
    \     sort(xys.begin(), xys.end());\n        ys.erase(unique(ys.begin(), ys.end()),\
    \ ys.end());\n        xys.erase(unique(xys.begin(), xys.end()), xys.end());\n\
    \        \n        T mx = 1;\n        for (auto u : ys) mx = max(mx, u);\n   \
    \     lg = log2(mx) + 1;\n        bv = vector(lg, bit_vector(xys.size()));\n \
    \       zeros.resize(lg);\n        st.resize(lg, segment_tree<T, op, e>(xys.size()));\n\
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
    \   }\n            st[i].update(it, val);\n        }\n    }\n\n    int idx(T i)\
    \ {\n        return lower_bound(xys.begin(), xys.end(), pair<T, T>{i, i}, [&](pair<T,\
    \ T> a, pair<T, T> b) {\n            return a.first < b.second;\n        }) -\
    \ xys.begin();\n    }\n\n    T get_sum(T l, T r, T upper) {\n        T ret = 0;\n\
    \        l = idx(l), r = idx(r);\n        upper = lower_bound(ys.begin(), ys.end(),\
    \ upper) - ys.begin();\n        for (int i = lg - 1; i >= 0; i--) {\n        \
    \    int l0 = bv[i].rank0(l), r0 = bv[i].rank0(r);\n            if (upper >> i\
    \ & 1) {\n                ret += st[i].get_val(l0, r0);\n                l +=\
    \ zeros[i] - l0;\n                r += zeros[i] - r0;\n            } else {\n\
    \                l = l0;\n                r = r0;\n            }\n        }\n\
    \        return ret;\n    }\n};\n#line 5 \"test/LibraryChecker/data_structure/point_add_rectangle_sum_SegTree_WM.test.cpp\"\
    \n\nusing T = long long;\n\nT op(T a, T b) {\n    return a + b;\n}\n\nT e() {\n\
    \    return 0;\n}\n\nint N, Q, x[100010], y[100010], w[100010], q[100010], l[100010],\
    \ d[100010], r[100010], u[100010];\nint main() {\n    cin.tie(nullptr);\n    ios_base::sync_with_stdio(false);\n\
    \    cout << fixed << setprecision(20);\n    wavelet_matrix_2d<T, op, e> wm;\n\
    \    cin >> N >> Q;\n    rep (i, N) {\n        cin >> x[i] >> y[i] >> w[i];\n\
    \        wm.add_point(x[i], y[i]);\n    }\n\n    rep (i, Q) {\n        cin >>\
    \ q[i];\n        if (q[i]) {\n            cin >> l[i] >> d[i] >> r[i] >> u[i];\n\
    \        } else {\n            cin >> l[i] >> d[i] >> r[i];\n            wm.add_point(l[i],\
    \ d[i]);\n        }\n    }\n\n    wm.build();\n    rep (i, N) {\n        wm.add(x[i],\
    \ y[i], w[i]);\n    }\n\n    rep (i, Q) {\n        if (q[i]) {\n            cout\
    \ << wm.get_sum(l[i], r[i], u[i]) - wm.get_sum(l[i], r[i], d[i]) << '\\n';\n \
    \       } else {\n            wm.add(l[i], d[i], r[i]);\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_rectangle_sum\"\
    \n\n#include \"../../../template/template.hpp\"\n#include \"../../../data_structure/segment_tree_on_wavelet_matrix.hpp\"\
    \n\nusing T = long long;\n\nT op(T a, T b) {\n    return a + b;\n}\n\nT e() {\n\
    \    return 0;\n}\n\nint N, Q, x[100010], y[100010], w[100010], q[100010], l[100010],\
    \ d[100010], r[100010], u[100010];\nint main() {\n    cin.tie(nullptr);\n    ios_base::sync_with_stdio(false);\n\
    \    cout << fixed << setprecision(20);\n    wavelet_matrix_2d<T, op, e> wm;\n\
    \    cin >> N >> Q;\n    rep (i, N) {\n        cin >> x[i] >> y[i] >> w[i];\n\
    \        wm.add_point(x[i], y[i]);\n    }\n\n    rep (i, Q) {\n        cin >>\
    \ q[i];\n        if (q[i]) {\n            cin >> l[i] >> d[i] >> r[i] >> u[i];\n\
    \        } else {\n            cin >> l[i] >> d[i] >> r[i];\n            wm.add_point(l[i],\
    \ d[i]);\n        }\n    }\n\n    wm.build();\n    rep (i, N) {\n        wm.add(x[i],\
    \ y[i], w[i]);\n    }\n\n    rep (i, Q) {\n        if (q[i]) {\n            cout\
    \ << wm.get_sum(l[i], r[i], u[i]) - wm.get_sum(l[i], r[i], d[i]) << '\\n';\n \
    \       } else {\n            wm.add(l[i], d[i], r[i]);\n        }\n    }\n}"
  dependsOn:
  - template/template.hpp
  - data_structure/segment_tree_on_wavelet_matrix.hpp
  - data_structure/segment_tree.hpp
  isVerificationFile: true
  path: test/LibraryChecker/data_structure/point_add_rectangle_sum_SegTree_WM.test.cpp
  requiredBy: []
  timestamp: '2024-05-07 03:31:27+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/LibraryChecker/data_structure/point_add_rectangle_sum_SegTree_WM.test.cpp
layout: document
redirect_from:
- /verify/test/LibraryChecker/data_structure/point_add_rectangle_sum_SegTree_WM.test.cpp
- /verify/test/LibraryChecker/data_structure/point_add_rectangle_sum_SegTree_WM.test.cpp.html
title: test/LibraryChecker/data_structure/point_add_rectangle_sum_SegTree_WM.test.cpp
---
