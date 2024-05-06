struct bit_vector {
    int n;
    const int w = 64;
    vector<uint64_t> b;
    vector<int> cnt;
    bit_vector(int _n = 0) : n(_n), b(_n / w + 1), cnt(_n / w + 1) {}

    int access(int i) {
        return b[i / w] >> (i % w) & 1;
    }

    void set(int i) {
        b[i / w] |= 1ll << (i % w);
    }

    void build() {
        for (int i = 1; i < (int)cnt.size(); i++) {
            cnt[i] = cnt[i - 1] + popcount(b[i - 1]);
        }
    }

    int rank0(int i) {
        return i - rank1(i);
    }

    int rank1(int i) {
        return cnt[i / w] + popcount(b[i / w] & ((1ull << (i % w)) - 1));
    }
};

template<class T>
struct wavelet_matrix {
    int lg;
    vector<bit_vector> bv;
    vector<int> zeros;

    wavelet_matrix(vector<T> a) {
        for (auto u : a) lg = max(lg, u);
        lg = log2(lg) + 1;
        bv = vector(lg, bit_vector(a.size()));
        zeros.resize(lg);
        vector<T> crt = a, nxt(a.size());
        for (int i = lg - 1; i >= 0; i--) {
            int ones = a.size() - 1;
            for (int j = 0; j < a.size(); j++) {
                if (crt[j] >> i & 1) {
                    bv[i].set(j);
                    nxt[ones--] = crt[j];
                } else {
                    nxt[zeros[i]++] = crt[j];
                }
            }
            bv[i].build();
            reverse(nxt.begin() + ones + 1, nxt.end());
            swap(crt, nxt);
        }
    }

    T access(int x) {
        T ret = 0;
        for (int i = lg - 1; i >= 0; i--) {
            if (bv[i].access(x)) {
                ret |= (T)1 << i;
                x = zeros[i] + bv[i].rank1(x);
            } else {
                x = bv[i].rank0(x);
            }
        }
        return ret;
    }

    T kth_min(int l, int r, int k) {
        T ret = 0;
        for (int i = lg - 1; i >= 0; i--) {
            int l0 = bv[i].rank0(l), r0 = bv[i].rank0(r);
            if (k < r0 - l0) {
                l = l0;
                r = r0;
            } else {
                k -= r0 - l0;
                ret |= (T)1 << i;
                l += zeros[i] - l0;
                r += zeros[i] - r0;
            }
        }
        return ret;
    }

    T kth_max(int l, int r, int k) {
        return kth_min(l, r, r - l - k - 1);
    }

    T count_lt_k(int l, int r, T k) {
        int ret = 0;
        for (int i = lg - 1; i >= 0; i--) {
            int l0 = bv[i].rank0(l), r0 = bv[i].rank0(r);
            if (k >> i & 1) {
                ret += r0 - l0;
                l += zeros[i] - l0;
                r += zeros[i] - r0;
            } else {
                l = l0;
                r = r0;
            }
        }
        return ret;
    }

    T count_k(int l, int r, T k) {
        for (int i = lg - 1; i >= 0; i--) {
            int l0 = bv[i].rank0(l), r0 = bv[i].rank0(r);
            if (k >> i & 1) {
                l += zeros[i] - l0;
                r += zeros[i] - r0;
            } else {
                l = l0;
                r = r0;
            }
        }
        return r - l;
    }

    T count_gt_k(int l, int r, T k) {
        int ret = 0;
        for (int i = lg - 1; i >= 0; i--) {
            int l0 = bv[i].rank0(l), r0 = bv[i].rank0(r);
            if (k >> i & 1) {
                l += zeros[i] - l0;
                r += zeros[i] - r0;
            } else {
                ret += r - l - r0 + l0;
                l = l0;
                r = r0;
            }
        }
        return ret;
    }

    T range_freq(int l, int r, T lower, T upper) {
        return count_lt_k(l, r, upper) - count_lt_k(l, r, lower);
    }

    T next_value(int l, int r, T k) {
        int cnt = count_lt_k(l, r, k);
        if (r - l == cnt) return -1;
        else return kth_min(l, r, cnt);
    }

    T prev_value(int l, int r, T k) {
        int cnt = count_gt_k(l, r, k);
        if (r - l == cnt) return -1;
        else return kth_max(l, r, cnt);
    }
};