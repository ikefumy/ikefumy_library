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
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../../template/template.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/biconnected_components\"\
    \n\n#include \"../../template/template.hpp\"\n#include \"../../graph/bi_connected_components.hpp\"\
    \n\nint N, M;\nint main() {\n    cin.tie(nullptr);\n    ios_base::sync_with_stdio(false);\n\
    \    cout << fixed << setprecision(20);\n    cin >> N >> M;\n    bi_connected_components\
    \ g(N);\n    rep (i, M) {\n        int a, b;\n        cin >> a >> b;\n       \
    \ g.add_edge(a, b);\n    }\n\n    g.build();\n    auto cs = g.get_comps();\n\n\
    \    cout << cs.size() << '\\n';\n    for (auto&& c : cs) {\n        cout << c.size();\n\
    \        for (auto&& u : c) cout << ' ' << u;\n        cout << '\\n';\n    }\n\
    }"
  dependsOn: []
  isVerificationFile: true
  path: test/LibraryChecker/graph/bi_connected_components.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/LibraryChecker/graph/bi_connected_components.test.cpp
layout: document
redirect_from:
- /verify/test/LibraryChecker/graph/bi_connected_components.test.cpp
- /verify/test/LibraryChecker/graph/bi_connected_components.test.cpp.html
title: test/LibraryChecker/graph/bi_connected_components.test.cpp
---
