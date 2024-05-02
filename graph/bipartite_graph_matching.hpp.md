---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/dinic.hpp
    title: graph/dinic.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/LibraryChecker/graph/matching_on_bipartite_graph.test.cpp
    title: test/LibraryChecker/graph/matching_on_bipartite_graph.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"graph/dinic.hpp\"\ntemplate<class F>\nstruct dinic {\n \
    \   struct edge {\n        int to;\n        F cap;\n        int rev;\n       \
    \ edge(){}\n        edge(int to, F cap, int rev) : to(to), cap(cap), rev(rev)\
    \ {}\n    };\n\n    vector<vector<edge>> g;\n    vector<int> level;\n    vector<int>\
    \ iter;\n    \n    dinic(int v) : g(v), level(v), iter(v) {}\n \n    void add_edge(int\
    \ from, int to, F cap) {\n        g[from].push_back({to, cap, (int)g[to].size()});\n\
    \        g[to].push_back({from, 0, (int)g[from].size() - 1});\n    }\n \n    void\
    \ bfs(int s) {\n        fill(level.begin(), level.end(), -1);\n        queue<int>\
    \ que;\n        level[s] = 0;\n        que.push(s);\n        while (!que.empty())\
    \ {\n            int v = que.front();\n            que.pop();\n            for\
    \ (auto& e : g[v]) {\n                if (e.cap > 0 && level[e.to] < 0) {\n  \
    \                  level[e.to] = level[v] + 1;\n                    que.push(e.to);\n\
    \                }\n            }\n        }\n    }\n \n    F dfs(int v, int t,\
    \ F f) {\n        if (v == t) return f;\n        for (int &i = iter[v]; i < (int)g[v].size();\
    \ i++) {\n            edge &e = g[v][i];\n            if (e.cap > 0 && level[v]\
    \ < level[e.to]) {\n                int d = dfs(e.to, t, min(f, e.cap));\n   \
    \             if (d > 0) {\n                    e.cap -= d;\n                \
    \    g[e.to][e.rev].cap += d;\n                    return d;\n               \
    \ }\n            }\n        }\n        return 0;\n    }\n \n    F max_flow(int\
    \ s, int t) {\n        F flow = 0;\n        while(true) {\n            bfs(s);\n\
    \            if (level[t] < 0) return flow;\n            fill(iter.begin(), iter.end(),\
    \ 0);\n            F f;\n            while ((f = dfs(s, t, inf)) > 0) {\n    \
    \            flow += f;\n            }\n        }\n        return flow;\n    }\n\
    \n    vector<vector<edge>> get_g() {\n        return g;\n    }\n};\n#line 2 \"\
    graph/bipartite_graph_matching.hpp\"\n\nstruct bipartite_graph_matching {\n  \
    \  int L, R;\n    vector<int> mxl, mxr;\n    dinic<int> f;\n    bipartite_graph_matching\
    \ (int l, int r) : L(l), R(r), mxl(l, 1), mxr(r, 1), f(l + r + 2) {};\n\n    void\
    \ add_edge(int u, int v) {\n        f.add_edge(u, L + v, 1);\n    }\n\n    void\
    \ set_cap(bool isL, int v, int cap) {\n        if (isL) mxl[v] = cap;\n      \
    \  else mxr[L + v] = cap;\n    }\n\n    vector<pair<int, int>> matching() {\n\
    \        for (int i = 0; i < L; i++) {\n            f.add_edge(L + R, i, mxl[i]);\n\
    \        }\n        for (int i = 0; i < R; i++) {\n            f.add_edge(L +\
    \ i, L + R + 1, mxr[i]);\n        }\n        f.max_flow(L + R, L + R + 1);\n\n\
    \        auto g = f.get_g();\n        vector<pair<int, int>> ret;\n        for\
    \ (int i = 0; i < L; i++) {\n            for (auto [v, cap, _] : g[i]) {\n   \
    \             if (cap == 0 && v < L + R) ret.emplace_back(i, v - L);\n       \
    \     }\n        }\n        return ret;\n    }\n};\n"
  code: "#include \"dinic.hpp\"\n\nstruct bipartite_graph_matching {\n    int L, R;\n\
    \    vector<int> mxl, mxr;\n    dinic<int> f;\n    bipartite_graph_matching (int\
    \ l, int r) : L(l), R(r), mxl(l, 1), mxr(r, 1), f(l + r + 2) {};\n\n    void add_edge(int\
    \ u, int v) {\n        f.add_edge(u, L + v, 1);\n    }\n\n    void set_cap(bool\
    \ isL, int v, int cap) {\n        if (isL) mxl[v] = cap;\n        else mxr[L +\
    \ v] = cap;\n    }\n\n    vector<pair<int, int>> matching() {\n        for (int\
    \ i = 0; i < L; i++) {\n            f.add_edge(L + R, i, mxl[i]);\n        }\n\
    \        for (int i = 0; i < R; i++) {\n            f.add_edge(L + i, L + R +\
    \ 1, mxr[i]);\n        }\n        f.max_flow(L + R, L + R + 1);\n\n        auto\
    \ g = f.get_g();\n        vector<pair<int, int>> ret;\n        for (int i = 0;\
    \ i < L; i++) {\n            for (auto [v, cap, _] : g[i]) {\n               \
    \ if (cap == 0 && v < L + R) ret.emplace_back(i, v - L);\n            }\n    \
    \    }\n        return ret;\n    }\n};"
  dependsOn:
  - graph/dinic.hpp
  isVerificationFile: false
  path: graph/bipartite_graph_matching.hpp
  requiredBy: []
  timestamp: '2024-05-02 17:04:51+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/LibraryChecker/graph/matching_on_bipartite_graph.test.cpp
documentation_of: graph/bipartite_graph_matching.hpp
layout: document
redirect_from:
- /library/graph/bipartite_graph_matching.hpp
- /library/graph/bipartite_graph_matching.hpp.html
title: graph/bipartite_graph_matching.hpp
---
