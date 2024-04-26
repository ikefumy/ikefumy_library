---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: graph/bipartite_graph_matching.hpp
    title: graph/bipartite_graph_matching.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AOJ/1615.test.cpp
    title: test/AOJ/1615.test.cpp
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
    \n    vector<vector<edge>> get_g() {\n        return g;\n    }\n};\n"
  code: "template<class F>\nstruct dinic {\n    struct edge {\n        int to;\n \
    \       F cap;\n        int rev;\n        edge(){}\n        edge(int to, F cap,\
    \ int rev) : to(to), cap(cap), rev(rev) {}\n    };\n\n    vector<vector<edge>>\
    \ g;\n    vector<int> level;\n    vector<int> iter;\n    \n    dinic(int v) :\
    \ g(v), level(v), iter(v) {}\n \n    void add_edge(int from, int to, F cap) {\n\
    \        g[from].push_back({to, cap, (int)g[to].size()});\n        g[to].push_back({from,\
    \ 0, (int)g[from].size() - 1});\n    }\n \n    void bfs(int s) {\n        fill(level.begin(),\
    \ level.end(), -1);\n        queue<int> que;\n        level[s] = 0;\n        que.push(s);\n\
    \        while (!que.empty()) {\n            int v = que.front();\n          \
    \  que.pop();\n            for (auto& e : g[v]) {\n                if (e.cap >\
    \ 0 && level[e.to] < 0) {\n                    level[e.to] = level[v] + 1;\n \
    \                   que.push(e.to);\n                }\n            }\n      \
    \  }\n    }\n \n    F dfs(int v, int t, F f) {\n        if (v == t) return f;\n\
    \        for (int &i = iter[v]; i < (int)g[v].size(); i++) {\n            edge\
    \ &e = g[v][i];\n            if (e.cap > 0 && level[v] < level[e.to]) {\n    \
    \            int d = dfs(e.to, t, min(f, e.cap));\n                if (d > 0)\
    \ {\n                    e.cap -= d;\n                    g[e.to][e.rev].cap +=\
    \ d;\n                    return d;\n                }\n            }\n      \
    \  }\n        return 0;\n    }\n \n    F max_flow(int s, int t) {\n        F flow\
    \ = 0;\n        while(true) {\n            bfs(s);\n            if (level[t] <\
    \ 0) return flow;\n            fill(iter.begin(), iter.end(), 0);\n          \
    \  F f;\n            while ((f = dfs(s, t, inf)) > 0) {\n                flow\
    \ += f;\n            }\n        }\n        return flow;\n    }\n\n    vector<vector<edge>>\
    \ get_g() {\n        return g;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: graph/dinic.hpp
  requiredBy:
  - graph/bipartite_graph_matching.hpp
  timestamp: '2024-04-27 05:43:46+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/LibraryChecker/graph/matching_on_bipartite_graph.test.cpp
  - test/AOJ/1615.test.cpp
documentation_of: graph/dinic.hpp
layout: document
redirect_from:
- /library/graph/dinic.hpp
- /library/graph/dinic.hpp.html
title: graph/dinic.hpp
---
