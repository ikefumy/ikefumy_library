template<class T, T(* op)(T, T), T(* e)()>
struct segment_tree {
    int N;
    vector<T> node;

    segment_tree(int n = 0) {
        N = 1;
        while(N < n) N *= 2;
        node.resize(N * 2 - 1, e());
    }

    void set (int i, T x) {
        i += N - 1;
        node[i] = x;
        while (i > 0) {
            i = (i - 1) / 2;
            node[i] = op(node[i * 2 + 1], node[i * 2 + 2]);
        }
    }

    void update (int i, T x) {
        set (i, op(node[i + N - 1], x));
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