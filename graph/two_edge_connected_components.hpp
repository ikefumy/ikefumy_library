#include "lowlink.hpp"

struct two_edge_connected_components : lowlink {
    vector<int> idx;
    vector<vector<int>> components;
    undirected_graph ng;
    two_edge_connected_components(int _n) : lowlink(_n), idx(_n, -1) {}

    void dfs(int v) {
        for (int i = 0; i < (int)g[v].size(); i++) {
            int u =g[v][i];
            if (bridge[v][i] || idx[u] != -1) continue;
            idx[u] = idx[v];
            dfs(u);
        }
    }

    void build() {
        int nn = 0;
        lowlink::build();
        for (int v = 0; v < n; v++) {
            if (idx[v] != -1) continue;
            idx[v] = nn++;
            dfs(v);
        }

        components.resize(nn);
        for (int v = 0; v < n; v++) {
            components[idx[v]].push_back(v);
        }
    }

    vector<vector<int>> get_components() {
        return components;
    }

    int get_idx(int v) {
        assert(built);
        return idx[v];
    }
};