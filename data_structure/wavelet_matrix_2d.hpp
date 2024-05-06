template<class T, T(* op)(T, T), T(* e)()>
struct segment_tree {
    int N;
    vector<T> node;

    segment_tree(int n = 0) {
        N = 1;
        while(N < n) N *= 2;
        node.resize(N * 2 - 1, e());
    }

    void update (int i, T x) {
        i += N - 1;
        node[i] = x;
        while (i > 0) {
            i = (i - 1) / 2;
            node[i] = op(node[i * 2 + 1], node[i * 2 + 2]);
        }
    }

    void add (int i, T x) {
        update(i, op(node[i + N - 1], x));
    }

    T get_val (int a, int b, int k = 0, int l = 0, int r = -1) {
        if (r == -1) r = N;
        if (b <= l || r <= a) return e();
        if (a <= l && r <= b) return node[k];

        T vl = get_val(a, b, k * 2 + 1, l, (l + r) / 2);
        T vr = get_val(a, b, k * 2 + 2, (l + r) / 2, r);
        return op(vl, vr);
    }
};


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

template<class T, T(* op)(T, T), T(* e)()>
struct wavelet_matrix_2d {
    int lg;
    vector<bit_vector> bv;
    vector<int> zeros;
    vector<segment_tree<T, op, e>> st;
    vector<T> ys;
    vector<pair<T, T>> xys;

    wavelet_matrix_2d() {}

    void add_point(T x, T y) {
        ys.push_back(y);
        xys.push_back({x, y});
    }

    void build() {
        sort(ys.begin(), ys.end());
        sort(xys.begin(), xys.end());
        ys.erase(unique(ys.begin(), ys.end()), ys.end());
        xys.erase(unique(xys.begin(), xys.end()), xys.end());
        
        T mx = 1;
        for (auto u : ys) mx = max(mx, u);
        lg = log2(mx) + 1;
        bv = vector(lg, bit_vector(xys.size()));
        zeros.resize(lg);
        st.resize(lg, segment_tree<T, op, e>(xys.size()));

        vector<T> crt(xys.size()), nxt(xys.size());
        for (int i = 0; i < (int)xys.size(); i++) {
            crt[i] = lower_bound(ys.begin(), ys.end(), xys[i].second) - ys.begin();
        }
        for (int i = lg - 1; i >= 0; i--) {
            int ones = crt.size() - 1;
            for (int j = 0; j < crt.size(); j++) {
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

    void add(T x, T y, T val) {
        auto it = lower_bound(xys.begin(), xys.end(), pair<T, T>{x, y}) - xys.begin();
        y = lower_bound(ys.begin(), ys.end(), y) - ys.begin();
        for (int i = lg - 1; i >= 0; i--) {
            int it0 = bv[i].rank0(it);
            if (y >> i & 1) {
                it += zeros[i] - it0;
            } else {
                it = it0;
            }
            st[i].add(it, val);
        }
    }

    int idx(T i) {
        return lower_bound(xys.begin(), xys.end(), pair<T, T>{i, i}, [&](pair<T, T> a, pair<T, T> b) {
            return a.first < b.second;
        }) - xys.begin();
    }

    T get_sum(T l, T r, T upper) {
        T ret = 0;
        l = idx(l), r = idx(r);
        upper = lower_bound(ys.begin(), ys.end(), upper) - ys.begin();
        for (int i = lg - 1; i >= 0; i--) {
            int l0 = bv[i].rank0(l), r0 = bv[i].rank0(r);
            if (upper >> i & 1) {
                ret += st[i].get_val(l0, r0);
                l += zeros[i] - l0;
                r += zeros[i] - r0;
            } else {
                l = l0;
                r = r0;
            }
        }
        return ret;
    }

    T get_sum(T l, T r, T d, T u) {
        return get_sum(l, r, u) - get_sum(l, r, d); 
    }
};