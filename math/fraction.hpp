template<class T>
struct fraction {
    T num, den;
    fraction(T _num = 0, T _den = 0) : num(_num), den(_den) {
        if (den < 0) {
            num *= -1;
            den *= -1;
        }
    }
    constexpr fraction operator+ (const fraction& rhs) const noexcept {
        return fraction(*this) += rhs;
    }
    constexpr fraction operator- (const fraction& rhs) const noexcept {
        return fraction(*this) -= rhs;
    }
    constexpr fraction operator* (const fraction& rhs) const noexcept {
        return fraction(*this) *= rhs;
    }
    constexpr fraction operator/ (const fraction& rhs) const noexcept {
        return fraction(*this) /= rhs;
    }

    constexpr fraction& operator += (const fraction& rhs) noexcept {
        num = num * rhs.den + den * rhs.num;
        den = den * rhs.den;
        return *this;
    }
    constexpr fraction& operator -= (const fraction& rhs) noexcept {
        num = num * rhs.den - den * rhs.num;
        den = den * rhs.den;
        return *this;
    }
    constexpr fraction& operator *= (const fraction& rhs) noexcept {
        num *= rhs.num;
        den *= rhs.den;
        return *this;
    }
    constexpr fraction& operator /= (fraction rhs) noexcept {
        num *= rhs.den;
        den *= rhs.num;
        return *this;
    }

    constexpr friend bool operator < (const fraction& lhs, const fraction& rhs) noexcept {
        return lhs.num * rhs.den < rhs.num * lhs.den;
    }
    constexpr friend bool operator > (const fraction& lhs, const fraction& rhs) noexcept {
        return lhs.num * rhs.den > rhs.num * lhs.den;
    }
    constexpr friend bool operator <= (const fraction& lhs, const fraction& rhs) noexcept {
        return lhs.num * rhs.den <= rhs.num * lhs.den;
    }
    constexpr friend bool operator >= (const fraction& lhs, const fraction& rhs) noexcept {
        return lhs.num * rhs.den >= rhs.num * lhs.den;
    }

    friend ostream &operator << (ostream& lhs, const fraction& rhs) {
        lhs << (long long)rhs.num << '/' << (long long)rhs.den;
        return lhs;
    }

    void reduction() {
        T g = gcd(num, den);
        num /= g, den /= g;
    }
};