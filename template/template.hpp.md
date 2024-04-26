---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AOJ/1615.test.cpp
    title: test/AOJ/1615.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/LibraryChecker/data_structure/line_add_get_min.test.cpp
    title: test/LibraryChecker/data_structure/line_add_get_min.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/LibraryChecker/data_structure/segment_add_get_min.test.cpp
    title: test/LibraryChecker/data_structure/segment_add_get_min.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/LibraryChecker/data_structure/union_find.test.cpp
    title: test/LibraryChecker/data_structure/union_find.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/LibraryChecker/graph/bi_connected_components.test.cpp
    title: test/LibraryChecker/graph/bi_connected_components.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/LibraryChecker/graph/matching_on_bipartite_graph.test.cpp
    title: test/LibraryChecker/graph/matching_on_bipartite_graph.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/LibraryChecker/graph/strongly_connected_components.test.cpp
    title: test/LibraryChecker/graph/strongly_connected_components.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/LibraryChecker/graph/two_edge_connected_components.test.cpp
    title: test/LibraryChecker/graph/two_edge_connected_components.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/LibraryChecker/math/binomial_coefficient(Prime_Mod).test.cpp
    title: test/LibraryChecker/math/binomial_coefficient(Prime_Mod).test.cpp
  - icon: ':heavy_check_mark:'
    path: test/LibraryChecker/math/enumerate_quotients.test.cpp
    title: test/LibraryChecker/math/enumerate_quotients.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/LibraryChecker/math/stern_brocot_tree.test.cpp
    title: test/LibraryChecker/math/stern_brocot_tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/LibraryChecker/tree/lowest_common_ancestor.test.cpp
    title: test/LibraryChecker/tree/lowest_common_ancestor.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"template/template.hpp\"\n#include<bits/stdc++.h>\nusing\
    \ namespace std;\n#define ll long long\n#define ull unsigned long long\n#define\
    \ db double\n#define pii pair<int,int>\n#define pli pair<ll,int>\n#define pil\
    \ pair<int,ll>\n#define pll pair<ll,ll>\n#define ti3 tuple<int,int,int>\n#define\
    \ int128 __int128_t\n#define pii128 pair<int128,int128>\nconst int inf = 1 <<\
    \ 30;\nconst ll linf = (ll)4e18 + 10;\nconst db EPS = 1e-10;\nconst db pi = acos(-1);\n\
    template<class T> bool chmin(T& x, T y){\n    if(x > y) {\n        x = y;\n  \
    \      return true;\n    } else return false;\n}\ntemplate<class T> bool chmax(T&\
    \ x, T y){\n    if(x < y) {\n        x = y;\n        return true;\n    } else\
    \ return false;\n}\n\n// overload macro\n#define CAT( A, B ) A ## B\n#define SELECT(\
    \ NAME, NUM ) CAT( NAME, NUM )\n\n#define GET_COUNT( _1, _2, _3, _4, _5, _6 /*\
    \ ad nauseam */, COUNT, ... ) COUNT\n#define VA_SIZE( ... ) GET_COUNT( __VA_ARGS__,\
    \ 6, 5, 4, 3, 2, 1 )\n\n#define VA_SELECT( NAME, ... ) SELECT( NAME, VA_SIZE(__VA_ARGS__)\
    \ )(__VA_ARGS__)\n\n// rep(overload)\n#define rep( ... ) VA_SELECT(rep, __VA_ARGS__)\n\
    #define rep2(i, n) for (int i = 0; i < int(n); i++)\n#define rep3(i, a, b) for\
    \ (int i = a; i < int(b); i++)\n#define rep4(i, a, b, c) for (int i = a; i < int(b);\
    \ i += c)\n\n// repll(overload)\n#define repll( ... ) VA_SELECT(repll, __VA_ARGS__)\n\
    #define repll2(i, n) for (ll i = 0; i < (ll)(n); i++)\n#define repll3(i, a, b)\
    \ for (ll i = a; i < (ll)(b); i++)\n#define repll4(i, a, b, c) for (ll i = a;\
    \ i < (ll)(b); i += c)\n\n// rrep(overload)\n#define rrep( ... ) VA_SELECT(rrep,\
    \ __VA_ARGS__)    \n#define rrep2(i, n) for (int i = n - 1; i >= 0; i--)\n#define\
    \ rrep3(i, a, b) for (int i = b - 1; i >= a; i--)\n#define rrep4(i, a, b, c) for\
    \ (int i = b - 1; i >= a; i -= c)\n\n// rrepll(overload)\n#define rrepll( ...\
    \ ) VA_SELECT(rrepll, __VA_ARGS__)\n#define rrepll2(i, n) for (ll i = (ll)(n)\
    \ - 1; i >= 0ll; i--)\n#define rrepll3(i, a, b) for (ll i = b - 1; i >= (ll)(a);\
    \ i--)\n#define rrepll4(i, a, b, c) for (ll i = b - 1; i >= (ll)(a); i -= c)\n\
    \n// for_earh\n#define fore(e, v) for (auto&& e : v)\n\n// vector\n#define all(v)\
    \ v.begin(), v.end()\n#define rall(v) v.rbegin(), v.rend()\n"
  code: "#include<bits/stdc++.h>\nusing namespace std;\n#define ll long long\n#define\
    \ ull unsigned long long\n#define db double\n#define pii pair<int,int>\n#define\
    \ pli pair<ll,int>\n#define pil pair<int,ll>\n#define pll pair<ll,ll>\n#define\
    \ ti3 tuple<int,int,int>\n#define int128 __int128_t\n#define pii128 pair<int128,int128>\n\
    const int inf = 1 << 30;\nconst ll linf = (ll)4e18 + 10;\nconst db EPS = 1e-10;\n\
    const db pi = acos(-1);\ntemplate<class T> bool chmin(T& x, T y){\n    if(x >\
    \ y) {\n        x = y;\n        return true;\n    } else return false;\n}\ntemplate<class\
    \ T> bool chmax(T& x, T y){\n    if(x < y) {\n        x = y;\n        return true;\n\
    \    } else return false;\n}\n\n// overload macro\n#define CAT( A, B ) A ## B\n\
    #define SELECT( NAME, NUM ) CAT( NAME, NUM )\n\n#define GET_COUNT( _1, _2, _3,\
    \ _4, _5, _6 /* ad nauseam */, COUNT, ... ) COUNT\n#define VA_SIZE( ... ) GET_COUNT(\
    \ __VA_ARGS__, 6, 5, 4, 3, 2, 1 )\n\n#define VA_SELECT( NAME, ... ) SELECT( NAME,\
    \ VA_SIZE(__VA_ARGS__) )(__VA_ARGS__)\n\n// rep(overload)\n#define rep( ... )\
    \ VA_SELECT(rep, __VA_ARGS__)\n#define rep2(i, n) for (int i = 0; i < int(n);\
    \ i++)\n#define rep3(i, a, b) for (int i = a; i < int(b); i++)\n#define rep4(i,\
    \ a, b, c) for (int i = a; i < int(b); i += c)\n\n// repll(overload)\n#define\
    \ repll( ... ) VA_SELECT(repll, __VA_ARGS__)\n#define repll2(i, n) for (ll i =\
    \ 0; i < (ll)(n); i++)\n#define repll3(i, a, b) for (ll i = a; i < (ll)(b); i++)\n\
    #define repll4(i, a, b, c) for (ll i = a; i < (ll)(b); i += c)\n\n// rrep(overload)\n\
    #define rrep( ... ) VA_SELECT(rrep, __VA_ARGS__)    \n#define rrep2(i, n) for\
    \ (int i = n - 1; i >= 0; i--)\n#define rrep3(i, a, b) for (int i = b - 1; i >=\
    \ a; i--)\n#define rrep4(i, a, b, c) for (int i = b - 1; i >= a; i -= c)\n\n//\
    \ rrepll(overload)\n#define rrepll( ... ) VA_SELECT(rrepll, __VA_ARGS__)\n#define\
    \ rrepll2(i, n) for (ll i = (ll)(n) - 1; i >= 0ll; i--)\n#define rrepll3(i, a,\
    \ b) for (ll i = b - 1; i >= (ll)(a); i--)\n#define rrepll4(i, a, b, c) for (ll\
    \ i = b - 1; i >= (ll)(a); i -= c)\n\n// for_earh\n#define fore(e, v) for (auto&&\
    \ e : v)\n\n// vector\n#define all(v) v.begin(), v.end()\n#define rall(v) v.rbegin(),\
    \ v.rend()"
  dependsOn: []
  isVerificationFile: false
  path: template/template.hpp
  requiredBy: []
  timestamp: '2024-04-27 05:43:46+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/LibraryChecker/graph/matching_on_bipartite_graph.test.cpp
  - test/LibraryChecker/graph/strongly_connected_components.test.cpp
  - test/LibraryChecker/graph/bi_connected_components.test.cpp
  - test/LibraryChecker/graph/two_edge_connected_components.test.cpp
  - test/LibraryChecker/data_structure/segment_add_get_min.test.cpp
  - test/LibraryChecker/data_structure/union_find.test.cpp
  - test/LibraryChecker/data_structure/line_add_get_min.test.cpp
  - test/LibraryChecker/math/enumerate_quotients.test.cpp
  - test/LibraryChecker/math/stern_brocot_tree.test.cpp
  - test/LibraryChecker/math/binomial_coefficient(Prime_Mod).test.cpp
  - test/LibraryChecker/tree/lowest_common_ancestor.test.cpp
  - test/AOJ/1615.test.cpp
documentation_of: template/template.hpp
layout: document
redirect_from:
- /library/template/template.hpp
- /library/template/template.hpp.html
title: template/template.hpp
---
