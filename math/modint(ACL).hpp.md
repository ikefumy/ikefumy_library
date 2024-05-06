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
  bundledCode: "#line 1 \"math/modint(ACL).hpp\"\nusing mint = modint998244353;\n\n\
    ostream &operator << (ostream& lhs, const mint& rhs) {\n    lhs << rhs.val();\n\
    \    return lhs;\n}\n\nistream &operator >> (istream& lhs, mint& rhs) {\n    long\
    \ long a;\n    lhs >> a;\n    rhs += a;\n    return lhs;\n}\n"
  code: "using mint = modint998244353;\n\nostream &operator << (ostream& lhs, const\
    \ mint& rhs) {\n    lhs << rhs.val();\n    return lhs;\n}\n\nistream &operator\
    \ >> (istream& lhs, mint& rhs) {\n    long long a;\n    lhs >> a;\n    rhs +=\
    \ a;\n    return lhs;\n}"
  dependsOn: []
  isVerificationFile: false
  path: math/modint(ACL).hpp
  requiredBy: []
  timestamp: '2024-05-07 00:38:36+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/modint(ACL).hpp
layout: document
redirect_from:
- /library/math/modint(ACL).hpp
- /library/math/modint(ACL).hpp.html
title: math/modint(ACL).hpp
---
