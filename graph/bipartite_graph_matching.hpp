#include "dinic.hpp"

struct bipartite_graph_matching {
    int L, R;
    vector<int> mxl, mxr;
    Dinic<int> f;
    bipartite_graph_matching (int l, int r) : L(l), R(r), mxl(l, 1), mxr(r, 1), f(l + r + 2) {};

    void add_edge(int u, int v) {
        f.add_edge(u, L + v, 1);
    }

    void set_cap(bool isL, int v, int cap) {
        if (isL) mxl[v] = cap;
        else mxr[L + v] = cap;
    }

    vector<pair<int, int>> matching() {
        for (int i = 0; i < L; i++) {
            f.add_edge(L + R, i, mxl[i]);
        }
        for (int i = 0; i < R; i++) {
            f.add_edge(L + i, L + R + 1, mxr[i]);
        }
        f.max_flow(L + R, L + R + 1);

        auto g = f.get_g();
        vector<pair<int, int>> ret;
        for (int i = 0; i < L; i++) {
            for (auto [v, cap, _] : g[i]) {
                if (cap == 0 && v < L + R) ret.emplace_back(i, v - L);
            }
        }
        return ret;
    }
};