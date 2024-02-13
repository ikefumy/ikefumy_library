using mint = modint998244353;

ostream &operator << (ostream& lhs, const mint& rhs) {
    lhs << rhs.val();
    return lhs;
}

istream &operator >> (istream& lhs, mint& rhs) {
    long long a;
    lhs >> a;
    rhs += a;
    return lhs;
}