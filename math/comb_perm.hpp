struct comb_perm{
    int n;
    vector<mint> fac;
    vector<mint> ifac;

    comb_perm(int _n): n(_n), fac(_n + 1), ifac(_n + 1){
        fac[0] = ifac[0] = 1;
        for(int i = 1; i <= n; i++){
            fac[i] = fac[i - 1] * i;
        }
        ifac[n] = (mint)1 / fac[n];
        for (int i = n - 1; i >= 1; i--) {
            ifac[i] = ifac[i + 1] * (i + 1);
        }
    }

    mint comb(int p, int r){
        return (p < r ? 0 : fac[p] * ifac[r] * ifac[p - r]);
    }

    mint perm(int p, int r){
        return (p < r ? 0 : fac[p] * ifac[p - r]);
    }
};