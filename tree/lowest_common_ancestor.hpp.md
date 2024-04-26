---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/undirected_graph.hpp
    title: graph/undirected_graph.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: tree/auxiliary_tree.hpp
    title: tree/auxiliary_tree.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/LibraryChecker/tree/lowest_common_ancestor.test.cpp
    title: test/LibraryChecker/tree/lowest_common_ancestor.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"graph/undirected_graph.hpp\"\nstruct undirected_graph {\n\
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
    \            }\n        }\n        return ret;\n    }\n};\n"
  code: "#include \"../graph/undirected_graph.hpp\"\n\nstruct lowest_common_ancestor\
    \ : undirected_graph {\n    bool built = false;\n    int logn = 0, s, B, logB\
    \ = 0;\n    vector<int> euler_tour, depth, in, out, log_table, diff;\n    vector<vector<int>>\
    \ sparse_table;\n    vector<vector<vector<int>>> table_lookup;\n    lowest_common_ancestor(int\
    \ _n) : undirected_graph(_n), depth(_n), in(_n), out(_n) {\n        while ((1\
    \ << logn) <= 2 * n - 1) logn++;\n        s = max(1, logn / 2);\n        B = (2\
    \ * n - 2) / s + 1;\n        while ((1 << logB) <= B) logB++;\n\n        diff\
    \ = vector(B, 0);\n        log_table = vector(B, 0);\n        sparse_table = vector(B,\
    \ vector<int>(logB, -1));\n        table_lookup = vector(1 << (s - 1), vector(s,\
    \ vector<int>(s, -1)));\n        // table_loopup\u306E\u69CB\u7BC9\n        for\
    \ (int i = 0; i < 1 << (s - 1); i++) {\n            for (int l = 0; l < s; l++)\
    \ {\n                int ans = l, mn = 0, val = 0;\n                for (int r\
    \ = l; r < s; r++) {\n                    table_lookup[i][l][r] = ans;\n     \
    \               val += ((i >> r & 1) ? 1 : -1);\n                    if (val <\
    \ mn) {\n                        mn = val;\n                        ans = r +\
    \ 1;\n                    }\n                }\n            }\n        }\n   \
    \ }\n\n    void dfs(int v, int p) {\n        in[v] = euler_tour.size();\n    \
    \    euler_tour.emplace_back(v);\n        for (auto&& u : g[v]) {\n          \
    \  if (u == p) continue;\n            depth[u] = depth[v] + 1;\n            dfs(u,\
    \ v);\n            euler_tour.emplace_back(v);\n        }\n        out[v] = euler_tour.size()\
    \ - 1;\n    }\n\n    int get_min(const int& u, const int& v) {\n        if (u\
    \ == -1) return v;\n        else if (v == -1) return u;\n        else return depth[u]\
    \ < depth[v] ? u : v;\n    }\n\n    void build() {\n        built = true;\n  \
    \      dfs(0, -1);\n\n        // table_lookup\u7528\u306E\u914D\u5217\n      \
    \  for (int i = 0; i < 2 * n - 2; i++) {\n            if (i / s != (i + 1) / s)\
    \ continue;\n            if (depth[euler_tour[i]] < depth[euler_tour[i + 1]])\
    \ {\n                diff[i / s] |= 1 << (i % s);\n            }\n        }\n\n\
    \        // sparse table\u306E\u69CB\u7BC9\n        for (int i = 0; i < 2 * n\
    \ - 1; i++) {\n            int b = i / s;\n            sparse_table[b][0] = get_min(sparse_table[b][0],\
    \ euler_tour[i]);\n        }\n        for (int j = 1; j < logB; j++) {\n     \
    \       for (int i = 1 << j; i < min(1 << (j + 1), B); i++) {\n              \
    \  log_table[i] = j;\n            }\n            for (int i = 0; i < B; i++) {\n\
    \                if (i + (1 << (j - 1)) >= B) break;\n                int v1 =\
    \ sparse_table[i][j - 1];\n                int v2 = sparse_table[i + (1 << (j\
    \ - 1))][j - 1];\n                sparse_table[i][j] = get_min(sparse_table[i][j\
    \ - 1], sparse_table[i + (1 << (j - 1))][j - 1]);\n            }\n        }\n\
    \    }\n\n    int get_lca(int u, int v) {\n        assert(built);\n        if\
    \ (in[u] > in[v]) swap(u, v);\n        int ret = 0;\n        int bu = in[u] /\
    \ s, bv = in[v] / s;\n        if (bu == bv) {\n            ret = euler_tour[bu\
    \ * s + table_lookup[diff[bu]][in[u] % s][in[v] % s]];\n        } else {\n   \
    \         ret = get_min(euler_tour[bu * s + table_lookup[diff[bu]][in[u] % s][s\
    \ - 1]], euler_tour[bv * s + table_lookup[diff[bv]][0][in[v] % s]]);\n       \
    \     if (bv - 1 - bu > 0) {\n                int len = bv - 1 - bu;\n       \
    \         ret = get_min(ret, sparse_table[bu + 1][log_table[len]]);\n        \
    \        ret = get_min(ret, sparse_table[bv - (1 << log_table[len])][log_table[len]]);\n\
    \            }\n        }\n        return ret;\n    }\n};"
  dependsOn:
  - graph/undirected_graph.hpp
  isVerificationFile: false
  path: tree/lowest_common_ancestor.hpp
  requiredBy:
  - tree/auxiliary_tree.hpp
  timestamp: '2024-04-27 04:27:49+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/LibraryChecker/tree/lowest_common_ancestor.test.cpp
documentation_of: tree/lowest_common_ancestor.hpp
layout: document
redirect_from:
- /library/tree/lowest_common_ancestor.hpp
- /library/tree/lowest_common_ancestor.hpp.html
title: tree/lowest_common_ancestor.hpp
---
