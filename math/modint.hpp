struct mint {
    static inline long long modulo;
    static void set_mod(long long m) {
        modulo = m;
    }

    long long num;
    mint (long long a = 0) : num((a % modulo + modulo) % modulo) {}

    mint operator+ (const mint& rhs) const noexcept {
        return mint(*this) += rhs;
    }
    mint operator- (const mint& rhs) const noexcept {
        return mint(*this) -= rhs;
    }
    mint operator* (const mint& rhs) const noexcept {
        return mint(*this) *= rhs;
    }
    mint operator/ (const mint& rhs) const noexcept {
        return mint(*this) /= rhs;
    }

    mint& operator += (const mint& rhs) noexcept {
        num = (num + rhs.num) % modulo;
        return *this;
    }
    mint& operator -= (const mint& rhs) noexcept {
        num = (num - rhs.num + modulo) % modulo;
        return *this;
    }
    mint& operator *= (const mint& rhs) noexcept {
        num = num * rhs.num % modulo;
        return *this;
    }
    mint& operator /= (mint rhs) noexcept {
        assert(rhs.num != 0);
        long long y = modulo - 2;
        while (y > 0) {
            if (y & 1) *this *= rhs;
            rhs *= rhs;
            y /= 2;
        }
        return *this;
    }

    mint& operator++ () noexcept {
        *this += (mint)1;
        return *this;
    }
    mint operator++ (int) noexcept {
        mint tmp = *this;
        ++*this;
        return tmp;
    }
    mint& operator-- () noexcept {
        *this -= (mint)1;
        return *this;
    }
    mint operator-- (int) noexcept {
        mint tmp = *this;
        --*this;
        return tmp;
    }

    friend ostream &operator << (ostream& lhs, const mint& rhs) {
        lhs << rhs.num;
        return lhs;
    }
    
    friend istream &operator >> (istream& lhs, mint& rhs) {
        lhs >> rhs.num;
        rhs.num = (rhs.num % modulo + modulo) % modulo;
        return lhs;
    }
};

mint modpow(mint x, ll y) {
    if (y == 0) return 1;
    return modpow(x * x, y / 2) * (y & 1 ? x : 1);
}