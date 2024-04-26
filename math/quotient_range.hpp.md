---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/LibraryChecker/math/enumerate_quotients.test.cpp
    title: test/LibraryChecker/math/enumerate_quotients.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"math/quotient_range.hpp\"\ntemplate<class T>\nvector<tuple<T,\
    \ T, T>> quotient_range(T n){\n    vector<T> qs;\n    T i = 0;\n    for(i = 1;\
    \ i * i <= n; i++){\n        qs.emplace_back(i);\n    }\n    i--;\n    if (n /\
    \ i == i) i--;\n    for (; i >= 1; i--) {\n        qs.emplace_back(n / i);\n \
    \   }\n\n    vector<tuple<T, T, T>> res = {{1, 1, n}};\n    for (int i = 0; i\
    \ + 1 < (int)qs.size(); i++) {\n        res.emplace_back(qs[i] + 1, qs[i + 1],\
    \ n / qs[i + 1]);\n    }\n    return res;\n}\n"
  code: "template<class T>\nvector<tuple<T, T, T>> quotient_range(T n){\n    vector<T>\
    \ qs;\n    T i = 0;\n    for(i = 1; i * i <= n; i++){\n        qs.emplace_back(i);\n\
    \    }\n    i--;\n    if (n / i == i) i--;\n    for (; i >= 1; i--) {\n      \
    \  qs.emplace_back(n / i);\n    }\n\n    vector<tuple<T, T, T>> res = {{1, 1,\
    \ n}};\n    for (int i = 0; i + 1 < (int)qs.size(); i++) {\n        res.emplace_back(qs[i]\
    \ + 1, qs[i + 1], n / qs[i + 1]);\n    }\n    return res;\n}"
  dependsOn: []
  isVerificationFile: false
  path: math/quotient_range.hpp
  requiredBy: []
  timestamp: '2024-04-27 00:23:02+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/LibraryChecker/math/enumerate_quotients.test.cpp
documentation_of: math/quotient_range.hpp
layout: document
redirect_from:
- /library/math/quotient_range.hpp
- /library/math/quotient_range.hpp.html
title: math/quotient_range.hpp
---
