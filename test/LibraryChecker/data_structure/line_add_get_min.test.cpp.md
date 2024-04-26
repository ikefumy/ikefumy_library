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
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/line_add_get_min\"\n\n\
    #include \"../../template/template.hpp\"\n#include \"../../data_structure/li_chao_tree.hpp\"\
    \n\nll N, Q, q, a, b, p;\nint main() {\n    cin.tie(nullptr);\n    ios_base::sync_with_stdio(false);\n\
    \    cout << fixed << setprecision(20);\n    cin >> N >> Q;\n    dynamic_li_chao_tree<ll,\
    \ linf, 2000000> dlct(-inf, inf);\n    rep (i, N) {\n        cin >> a >> b;\n\
    \        dlct.add_line(a, b);\n    }\n\n    rep (_, Q) {\n        cin >> q;\n\
    \        if (q) {\n            cin >> p;\n            cout << dlct.get_min(p)\
    \ << '\\n';\n        } else {\n            cin >> a >> b;\n            dlct.add_line(a,\
    \ b);\n        }\n    }\n}"
  dependsOn: []
  isVerificationFile: true
  path: test/LibraryChecker/data_structure/line_add_get_min.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/LibraryChecker/data_structure/line_add_get_min.test.cpp
layout: document
redirect_from:
- /verify/test/LibraryChecker/data_structure/line_add_get_min.test.cpp
- /verify/test/LibraryChecker/data_structure/line_add_get_min.test.cpp.html
title: test/LibraryChecker/data_structure/line_add_get_min.test.cpp
---