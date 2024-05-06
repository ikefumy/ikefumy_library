---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/li_chao_tree.hpp
    title: Li Chao Tree
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
    PROBLEM: https://judge.yosupo.jp/problem/segment_add_get_min
    links:
    - https://judge.yosupo.jp/problem/segment_add_get_min
  bundledCode: "#line 1 \"test/LibraryChecker/data_structure/segment_add_get_min.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/segment_add_get_min\"\n\n\
    #line 1 \"template/template.hpp\"\n#include<bits/stdc++.h>\nusing namespace std;\n\
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
    \ rall(v) v.rbegin(), v.rend()\n#line 1 \"data_structure/li_chao_tree.hpp\"\n\
    template<class T, T e, int NODES = 30000000>\nstruct dynamic_li_chao_tree {\n\
    \    struct Line {\n        T a, b;\n        Line (T _a = e, T _b = e) : a(_a),\
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
    };\n#line 5 \"test/LibraryChecker/data_structure/segment_add_get_min.test.cpp\"\
    \n\nll N, Q, q, l, r, a, b, p;\nint main() {\n    cin.tie(nullptr);\n    ios_base::sync_with_stdio(false);\n\
    \    cout << fixed << setprecision(20);\n    cin >> N >> Q;\n    dynamic_li_chao_tree<ll,\
    \ linf> dlct(-inf, inf);\n    rep (i, N) {\n        cin >> l >> r >> a >> b;\n\
    \        dlct.add_seg(a, b, l, r);\n    }\n\n    rep (_, Q) {\n        cin >>\
    \ q;\n        if (q) {\n            cin >> p;\n            ll ans = dlct.get_min(p);\n\
    \            if (ans == linf) cout << \"INFINITY\\n\";\n            else cout\
    \ << ans << '\\n';\n        } else {\n            cin >> l >> r >> a >> b;\n \
    \           dlct.add_seg(a, b, l, r);\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/segment_add_get_min\"\n\
    \n#include \"../../../template/template.hpp\"\n#include \"../../../data_structure/li_chao_tree.hpp\"\
    \n\nll N, Q, q, l, r, a, b, p;\nint main() {\n    cin.tie(nullptr);\n    ios_base::sync_with_stdio(false);\n\
    \    cout << fixed << setprecision(20);\n    cin >> N >> Q;\n    dynamic_li_chao_tree<ll,\
    \ linf> dlct(-inf, inf);\n    rep (i, N) {\n        cin >> l >> r >> a >> b;\n\
    \        dlct.add_seg(a, b, l, r);\n    }\n\n    rep (_, Q) {\n        cin >>\
    \ q;\n        if (q) {\n            cin >> p;\n            ll ans = dlct.get_min(p);\n\
    \            if (ans == linf) cout << \"INFINITY\\n\";\n            else cout\
    \ << ans << '\\n';\n        } else {\n            cin >> l >> r >> a >> b;\n \
    \           dlct.add_seg(a, b, l, r);\n        }\n    }\n}"
  dependsOn:
  - template/template.hpp
  - data_structure/li_chao_tree.hpp
  isVerificationFile: true
  path: test/LibraryChecker/data_structure/segment_add_get_min.test.cpp
  requiredBy: []
  timestamp: '2024-05-07 00:38:36+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/LibraryChecker/data_structure/segment_add_get_min.test.cpp
layout: document
redirect_from:
- /verify/test/LibraryChecker/data_structure/segment_add_get_min.test.cpp
- /verify/test/LibraryChecker/data_structure/segment_add_get_min.test.cpp.html
title: test/LibraryChecker/data_structure/segment_add_get_min.test.cpp
---
