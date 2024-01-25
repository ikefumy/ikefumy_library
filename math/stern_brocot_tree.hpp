namespace stern_brocot_tree {
    template<class T>
    struct SBT_node {
        T p, q, r, s;
    };

    template<class T>
    SBT_node<T> child(SBT_node<T> node, bool isleft, T depth) {
        if (isleft) return {node.p, node.q, node.p * depth + node.r, node.q * depth + node.s};
        else return {node.p + node.r * depth, node.q + node.s * depth, node.r, node.s};
    }

    template<class T>
    vector<T> encode_path(T p, T q) {
        vector<T> a;
        do {
            a.emplace_back(p / q);
            p %= q;
            swap(p, q);
        } while (q);
        a[a.size() - 1]--;
        return a;
    }

    template<class T>
    SBT_node<T> decode_path(vector<T> a) {
        SBT_node<T> ret(0, 1, 1, 0);
        bool isleft = false;
        for (int i = 0; i < (int)a.size(); i++) {
            ret = child(ret, isleft, a[i]);
            isleft = !isleft;
        }
        return ret;
    }

    template<class T>
    SBT_node<T> lca(T a, T b, T c, T d) {
        auto x = encode_path(a, b);
        auto y = encode_path(c, d);
        vector<T> z;
        for (int i = 0; i < (int)min(x.size(), y.size()); i++) {
            z.emplace_back(min(x[i], y[i]));
            if (x[i] != y[i]) break;
        }
        return decode_path(z);
    }

    template<class T>
    SBT_node<T> ancestor(T k, T a, T b) {
        auto x = encode_path(a, b);
        vector<T> y;
        for (int i = 0; i < (int)x.size(); i++) {
            if (k == 0) continue;
            T mn = min(k, x[i]);
            y.push_back(mn);
            k -= mn;
        }
        if (k) return {0, 0, 0, 0};
        else return decode_path(y);
    }

    template<class T>
    SBT_node<T> range(T p, T q) {
        return decode_path(encode_path(p, q));
    }
}