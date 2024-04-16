---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/LibraryChecker/binomial_coefficient(Prime_Mod).test.cpp
    title: test/LibraryChecker/binomial_coefficient(Prime_Mod).test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"math/modint.hpp\"\nstruct mint {\n    static inline long\
    \ long modulo;\n    static void set_mod(long long m) {\n        modulo = m;\n\
    \    }\n\n    long long num;\n    mint (long long a = 0) : num((a % modulo + modulo)\
    \ % modulo) {}\n\n    mint operator+ (const mint& rhs) const noexcept {\n    \
    \    return mint(*this) += rhs;\n    }\n    mint operator- (const mint& rhs) const\
    \ noexcept {\n        return mint(*this) -= rhs;\n    }\n    mint operator* (const\
    \ mint& rhs) const noexcept {\n        return mint(*this) *= rhs;\n    }\n   \
    \ mint operator/ (const mint& rhs) const noexcept {\n        return mint(*this)\
    \ /= rhs;\n    }\n\n    mint& operator += (const mint& rhs) noexcept {\n     \
    \   num = (num + rhs.num) % modulo;\n        return *this;\n    }\n    mint& operator\
    \ -= (const mint& rhs) noexcept {\n        num = (num - rhs.num + modulo) % modulo;\n\
    \        return *this;\n    }\n    mint& operator *= (const mint& rhs) noexcept\
    \ {\n        num = num * rhs.num % modulo;\n        return *this;\n    }\n   \
    \ mint& operator /= (mint rhs) noexcept {\n        assert(rhs.num != 0);\n   \
    \     long long y = modulo - 2;\n        while (y > 0) {\n            if (y &\
    \ 1) *this *= rhs;\n            rhs *= rhs;\n            y /= 2;\n        }\n\
    \        return *this;\n    }\n\n    mint& operator++ () noexcept {\n        *this\
    \ += (mint)1;\n        return *this;\n    }\n    mint operator++ (int) noexcept\
    \ {\n        mint tmp = *this;\n        ++*this;\n        return tmp;\n    }\n\
    \    mint& operator-- () noexcept {\n        *this -= (mint)1;\n        return\
    \ *this;\n    }\n    mint operator-- (int) noexcept {\n        mint tmp = *this;\n\
    \        --*this;\n        return tmp;\n    }\n\n    friend ostream &operator\
    \ << (ostream& lhs, const mint& rhs) {\n        lhs << rhs.num;\n        return\
    \ lhs;\n    }\n    \n    friend istream &operator >> (istream& lhs, mint& rhs)\
    \ {\n        lhs >> rhs.num;\n        rhs.num = (rhs.num % modulo + modulo) %\
    \ modulo;\n        return lhs;\n    }\n};\n\nmint modpow(mint x, long long y)\
    \ {\n    if (y == 0) return 1;\n    return modpow(x * x, y / 2) * (y & 1 ? x :\
    \ 1);\n}\n"
  code: "struct mint {\n    static inline long long modulo;\n    static void set_mod(long\
    \ long m) {\n        modulo = m;\n    }\n\n    long long num;\n    mint (long\
    \ long a = 0) : num((a % modulo + modulo) % modulo) {}\n\n    mint operator+ (const\
    \ mint& rhs) const noexcept {\n        return mint(*this) += rhs;\n    }\n   \
    \ mint operator- (const mint& rhs) const noexcept {\n        return mint(*this)\
    \ -= rhs;\n    }\n    mint operator* (const mint& rhs) const noexcept {\n    \
    \    return mint(*this) *= rhs;\n    }\n    mint operator/ (const mint& rhs) const\
    \ noexcept {\n        return mint(*this) /= rhs;\n    }\n\n    mint& operator\
    \ += (const mint& rhs) noexcept {\n        num = (num + rhs.num) % modulo;\n \
    \       return *this;\n    }\n    mint& operator -= (const mint& rhs) noexcept\
    \ {\n        num = (num - rhs.num + modulo) % modulo;\n        return *this;\n\
    \    }\n    mint& operator *= (const mint& rhs) noexcept {\n        num = num\
    \ * rhs.num % modulo;\n        return *this;\n    }\n    mint& operator /= (mint\
    \ rhs) noexcept {\n        assert(rhs.num != 0);\n        long long y = modulo\
    \ - 2;\n        while (y > 0) {\n            if (y & 1) *this *= rhs;\n      \
    \      rhs *= rhs;\n            y /= 2;\n        }\n        return *this;\n  \
    \  }\n\n    mint& operator++ () noexcept {\n        *this += (mint)1;\n      \
    \  return *this;\n    }\n    mint operator++ (int) noexcept {\n        mint tmp\
    \ = *this;\n        ++*this;\n        return tmp;\n    }\n    mint& operator--\
    \ () noexcept {\n        *this -= (mint)1;\n        return *this;\n    }\n   \
    \ mint operator-- (int) noexcept {\n        mint tmp = *this;\n        --*this;\n\
    \        return tmp;\n    }\n\n    friend ostream &operator << (ostream& lhs,\
    \ const mint& rhs) {\n        lhs << rhs.num;\n        return lhs;\n    }\n  \
    \  \n    friend istream &operator >> (istream& lhs, mint& rhs) {\n        lhs\
    \ >> rhs.num;\n        rhs.num = (rhs.num % modulo + modulo) % modulo;\n     \
    \   return lhs;\n    }\n};\n\nmint modpow(mint x, long long y) {\n    if (y ==\
    \ 0) return 1;\n    return modpow(x * x, y / 2) * (y & 1 ? x : 1);\n}"
  dependsOn: []
  isVerificationFile: false
  path: math/modint.hpp
  requiredBy: []
  timestamp: '2024-04-17 03:06:36+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/LibraryChecker/binomial_coefficient(Prime_Mod).test.cpp
documentation_of: math/modint.hpp
layout: document
redirect_from:
- /library/math/modint.hpp
- /library/math/modint.hpp.html
title: math/modint.hpp
---
