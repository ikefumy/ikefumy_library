template<int modulo>
struct modint {
    int num;
    constexpr modint(long long a = 0) : num(a % modulo + modulo) {
        if (num >= modulo) num -= modulo;
    }

    constexpr modint operator+ (const modint& rhs) const noexcept {
        return modint(*this) += rhs;
    }
    constexpr modint operator- (const modint& rhs) const noexcept {
        return modint(*this) -= rhs;
    }
    constexpr modint operator* (const modint& rhs) const noexcept {
        return modint(*this) *= rhs;
    }
    constexpr modint operator/ (const modint& rhs) const noexcept {
        return modint(*this) /= rhs;
    }

    constexpr modint& operator += (const modint& rhs) noexcept {
        num = num + rhs.num;
        if (num >= modulo) num -= modulo;
        return *this;
    }
    constexpr modint& operator -= (const modint& rhs) noexcept {
        num = num - rhs.num + modulo;
        if (num >= modulo) num -= modulo;
        return *this;
    }
    constexpr modint& operator *= (const modint& rhs) noexcept {
        num = 1ll * num * rhs.num % modulo;
        return *this;
    }
    constexpr modint& operator /= (modint rhs) noexcept {
        assert(rhs.num != 0);
        long long y = modulo - 2;
        while (y) {
            if (y & 1) *this *= rhs;
            rhs *= rhs;
            y /= 2;
        }
        return *this;
    }

    constexpr modint& operator++ () noexcept {
        *this += (modint)1;
        return *this;
    }
    constexpr modint operator++ (int) noexcept {
        modint tmp = *this;
        ++*this;
        return tmp;
    }
    constexpr modint& operator-- () noexcept {
        *this -= (modint)1;
        return *this;
    }
    constexpr modint operator-- (int) noexcept {
        modint tmp = *this;
        --*this;
        return tmp;
    }

    friend ostream &operator << (ostream& lhs, const modint& rhs) {
        lhs << rhs.num;
        return lhs;
    }
    
    friend istream &operator >> (istream& lhs, modint& rhs) {
        lhs >> rhs.num;
        rhs.num = rhs.num % modulo + modulo;
        if (rhs.num >= modulo) rhs.num -= modulo;
        return lhs;
    }
};

using mint = modint<998244353>;

mint modpow(mint x, long long y) {
    if (y == 0) return 1;
    return modpow(x * x, y / 2) * (y & 1 ? x : 1);
}