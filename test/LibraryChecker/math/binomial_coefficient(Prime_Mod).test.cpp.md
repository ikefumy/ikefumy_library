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
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/binomial_coefficient_prime_mod\"\
    \n\n#include \"../../template/template.hpp\"\n#include \"../../math/modint.hpp\"\
    \n#include \"../../math/comb_perm.hpp\"\n\nint T, m;\nint main() {\n    cin.tie(nullptr);\n\
    \    ios_base::sync_with_stdio(false);\n    cout << fixed << setprecision(20);\n\
    \    cin >>T >> m;\n    mint::modulo = m;\n\n    comb_perm cp(min(m - 1, 10000000));\n\
    \    rep (i, T) {\n        int n, k;\n        cin >> n >> k;\n        mint ans\
    \ = 1;\n        while (n > 0 || k > 0) {\n            ans *= cp.comb(n % m, k\
    \ % m);\n            n /= m, k /= m;\n        }\n        cout << ans << '\\n';\n\
    \    }\n}\n"
  dependsOn: []
  isVerificationFile: true
  path: test/LibraryChecker/math/binomial_coefficient(Prime_Mod).test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/LibraryChecker/math/binomial_coefficient(Prime_Mod).test.cpp
layout: document
redirect_from:
- /verify/test/LibraryChecker/math/binomial_coefficient(Prime_Mod).test.cpp
- /verify/test/LibraryChecker/math/binomial_coefficient(Prime_Mod).test.cpp.html
title: test/LibraryChecker/math/binomial_coefficient(Prime_Mod).test.cpp
---
