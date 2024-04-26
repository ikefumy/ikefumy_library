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
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/stern_brocot_tree\"\n\n\
    #include \"../../template/template.hpp\"\n#include \"../../math/stern_brocot_tree.hpp\"\
    \n\nll k, a, b, c, d;\nint main() {\n    cin.tie(nullptr);\n    ios_base::sync_with_stdio(false);\n\
    \    cout << fixed << setprecision(20);\n    int T;\n    cin >> T;\n    while\
    \ (T--) {\n        string S;\n        cin >> S;\n        char s = S[0];\n    \
    \    if (s == 'E') {\n            cin >> a >> b;\n            auto x = stern_brocot_tree<ll>::encode_path(a,\
    \ b);\n            k = x.size() - (x[0] == 0);\n            cout << k;\n     \
    \       bool isleft = true;\n            fore (u, x) {\n                isleft\
    \ = !isleft;\n                if (u == 0) continue;\n                cout << '\
    \ ' << (isleft ? 'L' : 'R') << ' ' << u;\n            }\n            cout << '\\\
    n';\n        } else if (s == 'D') {\n            cin >> k;\n            vector<ll>\
    \ x;\n            rep (i, k) {\n                char lr;\n                int\
    \ u;\n                cin >> lr >> u;\n                if (i == 0 && lr == 'L')\
    \ x.emplace_back(0);\n                x.emplace_back(u);\n            }\n    \
    \        auto [p, q, r, s] = stern_brocot_tree<ll>::decode_path(x);\n        \
    \    cout << p + r << ' ' << q + s << '\\n';\n        } else if (s == 'L') {\n\
    \            cin >> a >> b >> c >> d;\n            auto [p, q, r, s] = stern_brocot_tree<ll>::lca(a,\
    \ b, c, d);\n            cout << p + r << ' ' << q + s << '\\n';\n        } else\
    \ if (s == 'A') {\n            cin >> k >> a >> b;\n            auto [p, q, r,\
    \ s] = stern_brocot_tree<ll>::ancestor(k, a, b);\n            if (max({p, q, r,\
    \ s}) == 0) cout << -1 << '\\n';\n            else cout << p + r << ' ' << q +\
    \ s << '\\n';\n        } else if (s == 'R') {\n            cin >> a >> b;\n  \
    \          auto [f, g, h, k] = stern_brocot_tree<ll>::range(a, b);\n         \
    \   cout << f << ' ' << g << ' ' << h << ' ' << k << '\\n';\n        }\n    }\n\
    }"
  dependsOn: []
  isVerificationFile: true
  path: test/LibraryChecker/math/stern_brocot_tree.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/LibraryChecker/math/stern_brocot_tree.test.cpp
layout: document
redirect_from:
- /verify/test/LibraryChecker/math/stern_brocot_tree.test.cpp
- /verify/test/LibraryChecker/math/stern_brocot_tree.test.cpp.html
title: test/LibraryChecker/math/stern_brocot_tree.test.cpp
---
