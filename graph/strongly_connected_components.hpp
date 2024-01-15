#include "directed_graph.hpp"

struct strongly_connected_components : directed_graph {
private:
    bool built = false;
    int tp;
    vector<int> used, vs, cmp;

public:
    strongly_connected_components (int n) : directed_graph(n), used(n), cmp(n) {}

    void dfs(int v) {
        used[v] = true;
        for (auto u : g[v]) {
            if (!used[u]) dfs(u);
        }
        vs.emplace_back(v);
    }

    void rdfs(int v, int k) {
        used[v] = true;
        cmp[v] = k;
        for (auto u : rg[v]) {
            if (!used[u]) rdfs(u, k);
        }
    }

    int build() {
        fill(used.begin(), used.end(), 0);
        for (int i = 0; i < n; i++) {
            if (!used[i]) dfs(i);
        }
        fill(used.begin(), used.end(), 0);
        tp = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (!used[vs[i]]) rdfs(vs[i], tp++);
        }
        
        built = true;
        return tp;
    }

    int get_cmp(int v) {
        assert(built);
        return cmp[v];
    }

    int get_tp() {
        assert(built);
        return tp;
    }
};