---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/undirected_graph.hpp
    title: graph/undirected_graph.hpp
  - icon: ':heavy_check_mark:'
    path: template/template.hpp
    title: template/template.hpp
  - icon: ':heavy_check_mark:'
    path: tree/lowest_common_ancestor.hpp
    title: tree/lowest_common_ancestor.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/lca
    links:
    - https://judge.yosupo.jp/problem/lca
  bundledCode: "#line 1 \"test/LibraryChecker/tree/lowest_common_ancestor.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/lca\"\n\n#line 1 \"template/template.hpp\"\
    \n#include<bits/stdc++.h>\nusing namespace std;\n#define ll long long\n#define\
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
    \ v.rend()\n#line 1 \"graph/undirected_graph.hpp\"\nstruct undirected_graph {\n\
    public:\n    int n;\n    vector<vector<int>> g;\n\n    undirected_graph(int _n\
    \ = 0) : n(_n), g(_n) {}\n    void add_edge(int u, int v) {\n        assert(0\
    \ <= u && u < n);\n        assert(0 <= v && v < n);\n        g[u].push_back(v);\n\
    \        g[v].push_back(u);\n    }\n};\n#line 2 \"tree/lowest_common_ancestor.hpp\"\
    \n\nstruct lowest_common_ancestor : undirected_graph {\n    bool built = false;\n\
    \    int logn = 0, s, B, logB = 0;\n    vector<int> euler_tour, depth, in, out,\
    \ log_table, diff;\n    vector<vector<int>> sparse_table;\n    vector<vector<vector<int>>>\
    \ table_lookup;\n    lowest_common_ancestor(int _n) : undirected_graph(_n), depth(_n),\
    \ in(_n), out(_n) {\n        while ((1 << logn) <= 2 * n - 1) logn++;\n      \
    \  s = max(1, logn / 2);\n        B = (2 * n - 2) / s + 1;\n        while ((1\
    \ << logB) <= B) logB++;\n\n        diff = vector(B, 0);\n        log_table =\
    \ vector(B, 0);\n        sparse_table = vector(B, vector<int>(logB, -1));\n  \
    \      table_lookup = vector(1 << (s - 1), vector(s, vector<int>(s, -1)));\n \
    \       // table_loopup\u306E\u69CB\u7BC9\n        for (int i = 0; i < 1 << (s\
    \ - 1); i++) {\n            for (int l = 0; l < s; l++) {\n                int\
    \ ans = l, mn = 0, val = 0;\n                for (int r = l; r < s; r++) {\n \
    \                   table_lookup[i][l][r] = ans;\n                    val += ((i\
    \ >> r & 1) ? 1 : -1);\n                    if (val < mn) {\n                \
    \        mn = val;\n                        ans = r + 1;\n                   \
    \ }\n                }\n            }\n        }\n    }\n\n    void dfs(int v,\
    \ int p) {\n        in[v] = euler_tour.size();\n        euler_tour.emplace_back(v);\n\
    \        for (auto&& u : g[v]) {\n            if (u == p) continue;\n        \
    \    depth[u] = depth[v] + 1;\n            dfs(u, v);\n            euler_tour.emplace_back(v);\n\
    \        }\n        out[v] = euler_tour.size() - 1;\n    }\n\n    int get_min(const\
    \ int& u, const int& v) {\n        if (u == -1) return v;\n        else if (v\
    \ == -1) return u;\n        else return depth[u] < depth[v] ? u : v;\n    }\n\n\
    \    void build() {\n        built = true;\n        dfs(0, -1);\n\n        //\
    \ table_lookup\u7528\u306E\u914D\u5217\n        for (int i = 0; i < 2 * n - 2;\
    \ i++) {\n            if (i / s != (i + 1) / s) continue;\n            if (depth[euler_tour[i]]\
    \ < depth[euler_tour[i + 1]]) {\n                diff[i / s] |= 1 << (i % s);\n\
    \            }\n        }\n\n        // sparse table\u306E\u69CB\u7BC9\n     \
    \   for (int i = 0; i < 2 * n - 1; i++) {\n            int b = i / s;\n      \
    \      sparse_table[b][0] = get_min(sparse_table[b][0], euler_tour[i]);\n    \
    \    }\n        for (int j = 1; j < logB; j++) {\n            for (int i = 1 <<\
    \ j; i < min(1 << (j + 1), B); i++) {\n                log_table[i] = j;\n   \
    \         }\n            for (int i = 0; i < B; i++) {\n                if (i\
    \ + (1 << (j - 1)) >= B) break;\n                int v1 = sparse_table[i][j -\
    \ 1];\n                int v2 = sparse_table[i + (1 << (j - 1))][j - 1];\n   \
    \             sparse_table[i][j] = get_min(sparse_table[i][j - 1], sparse_table[i\
    \ + (1 << (j - 1))][j - 1]);\n            }\n        }\n    }\n\n    int get_lca(int\
    \ u, int v) {\n        assert(built);\n        if (in[u] > in[v]) swap(u, v);\n\
    \        int ret = 0;\n        int bu = in[u] / s, bv = in[v] / s;\n        if\
    \ (bu == bv) {\n            ret = euler_tour[bu * s + table_lookup[diff[bu]][in[u]\
    \ % s][in[v] % s]];\n        } else {\n            ret = get_min(euler_tour[bu\
    \ * s + table_lookup[diff[bu]][in[u] % s][s - 1]], euler_tour[bv * s + table_lookup[diff[bv]][0][in[v]\
    \ % s]]);\n            if (bv - 1 - bu > 0) {\n                int len = bv -\
    \ 1 - bu;\n                ret = get_min(ret, sparse_table[bu + 1][log_table[len]]);\n\
    \                ret = get_min(ret, sparse_table[bv - (1 << log_table[len])][log_table[len]]);\n\
    \            }\n        }\n        return ret;\n    }\n};\n#line 5 \"test/LibraryChecker/tree/lowest_common_ancestor.test.cpp\"\
    \n\nint N, Q, p, u, v;\nint main() {\n    cin.tie(nullptr);\n    ios_base::sync_with_stdio(false);\n\
    \    cout << fixed << setprecision(20);\n    cin >> N >> Q;\n    lowest_common_ancestor\
    \ lca(N);\n    rep (i, 1, N) {\n        cin >> p;\n        lca.add_edge(i, p);\n\
    \    }\n\n    lca.build();\n    rep (i, Q) {\n        cin >> u >> v;\n       \
    \ cout << lca.get_lca(u, v) << '\\n';\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/lca\"\n\n#include \"../../../template/template.hpp\"\
    \n#include \"../../../tree/lowest_common_ancestor.hpp\"\n\nint N, Q, p, u, v;\n\
    int main() {\n    cin.tie(nullptr);\n    ios_base::sync_with_stdio(false);\n \
    \   cout << fixed << setprecision(20);\n    cin >> N >> Q;\n    lowest_common_ancestor\
    \ lca(N);\n    rep (i, 1, N) {\n        cin >> p;\n        lca.add_edge(i, p);\n\
    \    }\n\n    lca.build();\n    rep (i, Q) {\n        cin >> u >> v;\n       \
    \ cout << lca.get_lca(u, v) << '\\n';\n    }\n}"
  dependsOn:
  - template/template.hpp
  - tree/lowest_common_ancestor.hpp
  - graph/undirected_graph.hpp
  isVerificationFile: true
  path: test/LibraryChecker/tree/lowest_common_ancestor.test.cpp
  requiredBy: []
  timestamp: '2024-05-03 21:18:36+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/LibraryChecker/tree/lowest_common_ancestor.test.cpp
layout: document
redirect_from:
- /verify/test/LibraryChecker/tree/lowest_common_ancestor.test.cpp
- /verify/test/LibraryChecker/tree/lowest_common_ancestor.test.cpp.html
title: test/LibraryChecker/tree/lowest_common_ancestor.test.cpp
---
