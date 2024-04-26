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
  bundledCode: "#line 1 \"math/comb_perm.hpp\"\nstruct comb_perm{\n    int n;\n  \
    \  vector<mint> fac;\n    vector<mint> ifac;\n\n    comb_perm(int _n): n(_n),\
    \ fac(_n + 1), ifac(_n + 1){\n        fac[0] = ifac[0] = 1;\n        for(int i\
    \ = 1; i <= n; i++){\n            fac[i] = fac[i - 1] * i;\n        }\n      \
    \  ifac[n] = (mint)1 / fac[n];\n        for (int i = n - 1; i >= 1; i--) {\n \
    \           ifac[i] = ifac[i + 1] * (i + 1);\n        }\n    }\n\n    mint comb(int\
    \ p, int r){\n        return (p < r ? 0 : fac[p] * ifac[r] * ifac[p - r]);\n \
    \   }\n\n    mint perm(int p, int r){\n        return (p < r ? 0 : fac[p] * ifac[p\
    \ - r]);\n    }\n};\n"
  code: "struct comb_perm{\n    int n;\n    vector<mint> fac;\n    vector<mint> ifac;\n\
    \n    comb_perm(int _n): n(_n), fac(_n + 1), ifac(_n + 1){\n        fac[0] = ifac[0]\
    \ = 1;\n        for(int i = 1; i <= n; i++){\n            fac[i] = fac[i - 1]\
    \ * i;\n        }\n        ifac[n] = (mint)1 / fac[n];\n        for (int i = n\
    \ - 1; i >= 1; i--) {\n            ifac[i] = ifac[i + 1] * (i + 1);\n        }\n\
    \    }\n\n    mint comb(int p, int r){\n        return (p < r ? 0 : fac[p] * ifac[r]\
    \ * ifac[p - r]);\n    }\n\n    mint perm(int p, int r){\n        return (p <\
    \ r ? 0 : fac[p] * ifac[p - r]);\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: math/comb_perm.hpp
  requiredBy: []
  timestamp: '2024-04-27 00:19:50+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/comb_perm.hpp
layout: document
redirect_from:
- /library/math/comb_perm.hpp
- /library/math/comb_perm.hpp.html
title: math/comb_perm.hpp
---