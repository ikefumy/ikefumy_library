---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/home/runner/.local/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/home/runner/.local/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/home/runner/.local/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/home/runner/.local/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: lowest_common_tree.hpp:\
    \ line -1: no such header\n"
  code: "#include \"lowest_common_tree.hpp\"\n\nstruct auxiliary_tree : lowest_common_ancestor\
    \ {\n    vector<int> used;\n    auxiliary_tree(int _n) : lowest_common_ancestor(_n),\
    \ used(_n) {}\n    void build() {\n        lowest_common_ancestor::build();\n\
    \    }\n\n    pair<vector<vector<int>>, vector<int>> get_at(vector<int> v) {\n\
    \        sort(v.begin(), v.end(), [&](int a, int b) {\n            return in[a]\
    \ < in[b];\n        });\n        \n        for (auto u : v) used[u] = true;\n\
    \        for (int i = 1; i < (int)v.size(); i++) {\n            int lca = get_lca(v[i\
    \ - 1], v[i]);\n            if (!used[lca]) {\n                used[lca] = true;\n\
    \                v.emplace_back(lca);\n            }\n        }\n\n        sort(v.begin(),\
    \ v.end(), [&](int a, int b) {\n            return in[a] < in[b];\n        });\n\
    \n        vector<vector<int>> ret(v.size());\n        stack<int> rem;\n      \
    \  for (int i = 0; i < (int)v.size(); i++) {\n            used[v[i]] = false;\n\
    \            while (!rem.empty() && out[v[rem.top()]] < in[v[i]]) rem.pop();\n\
    \            if (!rem.empty()) {\n                int a = rem.top(), b = i;\n\
    \                ret[a].push_back(b);\n                ret[b].push_back(a);\n\
    \            }\n            rem.push(i);\n        }\n\n        return {ret, v};\n\
    \    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: tree/auxiliary_tree.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: tree/auxiliary_tree.hpp
layout: document
redirect_from:
- /library/tree/auxiliary_tree.hpp
- /library/tree/auxiliary_tree.hpp.html
title: tree/auxiliary_tree.hpp
---
