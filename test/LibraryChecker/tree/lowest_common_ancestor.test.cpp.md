---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/home/runner/.local/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/home/runner/.local/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/home/runner/.local/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/home/runner/.local/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/home/runner/.local/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../graph/undirected.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/lca\"\n\n#include \"../../../template/template.hpp\"\
    \n#include \"../../../tree/lowest_common_ancestor.hpp\"\n\nint N, Q, p, u, v;\n\
    int main() {\n    cin.tie(nullptr);\n    ios_base::sync_with_stdio(false);\n \
    \   cout << fixed << setprecision(20);\n    cin >> N >> Q;\n    lowest_common_ancestor\
    \ lca(N);\n    rep (i, 1, N) {\n        cin >> p;\n        lca.add_edge(i, p);\n\
    \    }\n\n    lca.build();\n    rep (i, Q) {\n        cin >> u >> v;\n       \
    \ cout << lca.get_lca(u, v) << '\\n';\n    }\n}"
  dependsOn: []
  isVerificationFile: true
  path: test/LibraryChecker/tree/lowest_common_ancestor.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/LibraryChecker/tree/lowest_common_ancestor.test.cpp
layout: document
redirect_from:
- /verify/test/LibraryChecker/tree/lowest_common_ancestor.test.cpp
- /verify/test/LibraryChecker/tree/lowest_common_ancestor.test.cpp.html
title: test/LibraryChecker/tree/lowest_common_ancestor.test.cpp
---
