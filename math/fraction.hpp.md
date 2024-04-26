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
  bundledCode: "#line 1 \"math/fraction.hpp\"\ntemplate<class T>\nstruct fraction\
    \ {\n    T num, den;\n    fraction(T _num = 0, T _den = 0) : num(_num), den(_den)\
    \ {\n        if (den < 0) {\n            num *= -1;\n            den *= -1;\n\
    \        }\n    }\n    constexpr fraction operator+ (const fraction& rhs) const\
    \ noexcept {\n        return fraction(*this) += rhs;\n    }\n    constexpr fraction\
    \ operator- (const fraction& rhs) const noexcept {\n        return fraction(*this)\
    \ -= rhs;\n    }\n    constexpr fraction operator* (const fraction& rhs) const\
    \ noexcept {\n        return fraction(*this) *= rhs;\n    }\n    constexpr fraction\
    \ operator/ (const fraction& rhs) const noexcept {\n        return fraction(*this)\
    \ /= rhs;\n    }\n\n    constexpr fraction& operator += (const fraction& rhs)\
    \ noexcept {\n        num = num * rhs.den + den * rhs.num;\n        den = den\
    \ * rhs.den;\n        return *this;\n    }\n    constexpr fraction& operator -=\
    \ (const fraction& rhs) noexcept {\n        num = num * rhs.den - den * rhs.num;\n\
    \        den = den * rhs.den;\n        return *this;\n    }\n    constexpr fraction&\
    \ operator *= (const fraction& rhs) noexcept {\n        num *= rhs.num;\n    \
    \    den *= rhs.den;\n        return *this;\n    }\n    constexpr fraction& operator\
    \ /= (fraction rhs) noexcept {\n        num *= rhs.den;\n        den *= rhs.num;\n\
    \        return *this;\n    }\n\n    constexpr friend bool operator < (const fraction&\
    \ lhs, const fraction& rhs) noexcept {\n        return lhs.num * rhs.den < rhs.num\
    \ * lhs.den;\n    }\n    constexpr friend bool operator > (const fraction& lhs,\
    \ const fraction& rhs) noexcept {\n        return lhs.num * rhs.den > rhs.num\
    \ * lhs.den;\n    }\n    constexpr friend bool operator <= (const fraction& lhs,\
    \ const fraction& rhs) noexcept {\n        return lhs.num * rhs.den <= rhs.num\
    \ * lhs.den;\n    }\n    constexpr friend bool operator >= (const fraction& lhs,\
    \ const fraction& rhs) noexcept {\n        return lhs.num * rhs.den >= rhs.num\
    \ * lhs.den;\n    }\n\n    friend ostream &operator << (ostream& lhs, const fraction&\
    \ rhs) {\n        lhs << (long long)rhs.num << '/' << (long long)rhs.den;\n  \
    \      return lhs;\n    }\n\n    void reduction() {\n        T g = gcd(num, den);\n\
    \        num /= g, den /= g;\n    }\n};\n"
  code: "template<class T>\nstruct fraction {\n    T num, den;\n    fraction(T _num\
    \ = 0, T _den = 0) : num(_num), den(_den) {\n        if (den < 0) {\n        \
    \    num *= -1;\n            den *= -1;\n        }\n    }\n    constexpr fraction\
    \ operator+ (const fraction& rhs) const noexcept {\n        return fraction(*this)\
    \ += rhs;\n    }\n    constexpr fraction operator- (const fraction& rhs) const\
    \ noexcept {\n        return fraction(*this) -= rhs;\n    }\n    constexpr fraction\
    \ operator* (const fraction& rhs) const noexcept {\n        return fraction(*this)\
    \ *= rhs;\n    }\n    constexpr fraction operator/ (const fraction& rhs) const\
    \ noexcept {\n        return fraction(*this) /= rhs;\n    }\n\n    constexpr fraction&\
    \ operator += (const fraction& rhs) noexcept {\n        num = num * rhs.den +\
    \ den * rhs.num;\n        den = den * rhs.den;\n        return *this;\n    }\n\
    \    constexpr fraction& operator -= (const fraction& rhs) noexcept {\n      \
    \  num = num * rhs.den - den * rhs.num;\n        den = den * rhs.den;\n      \
    \  return *this;\n    }\n    constexpr fraction& operator *= (const fraction&\
    \ rhs) noexcept {\n        num *= rhs.num;\n        den *= rhs.den;\n        return\
    \ *this;\n    }\n    constexpr fraction& operator /= (fraction rhs) noexcept {\n\
    \        num *= rhs.den;\n        den *= rhs.num;\n        return *this;\n   \
    \ }\n\n    constexpr friend bool operator < (const fraction& lhs, const fraction&\
    \ rhs) noexcept {\n        return lhs.num * rhs.den < rhs.num * lhs.den;\n   \
    \ }\n    constexpr friend bool operator > (const fraction& lhs, const fraction&\
    \ rhs) noexcept {\n        return lhs.num * rhs.den > rhs.num * lhs.den;\n   \
    \ }\n    constexpr friend bool operator <= (const fraction& lhs, const fraction&\
    \ rhs) noexcept {\n        return lhs.num * rhs.den <= rhs.num * lhs.den;\n  \
    \  }\n    constexpr friend bool operator >= (const fraction& lhs, const fraction&\
    \ rhs) noexcept {\n        return lhs.num * rhs.den >= rhs.num * lhs.den;\n  \
    \  }\n\n    friend ostream &operator << (ostream& lhs, const fraction& rhs) {\n\
    \        lhs << (long long)rhs.num << '/' << (long long)rhs.den;\n        return\
    \ lhs;\n    }\n\n    void reduction() {\n        T g = gcd(num, den);\n      \
    \  num /= g, den /= g;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: math/fraction.hpp
  requiredBy: []
  timestamp: '2024-04-27 05:43:46+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/fraction.hpp
layout: document
redirect_from:
- /library/math/fraction.hpp
- /library/math/fraction.hpp.html
title: math/fraction.hpp
---
