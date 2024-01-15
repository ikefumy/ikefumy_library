#include "undirected_graph.hpp"

struct lowlink : undirected_graph {
protected:
    bool built = false;
    vector<int> ord, low, aps;
    vector<vector<int>> bridge;

public:
    lowlink (int _n) : undirected_graph(_n), ord(_n), low(_n), aps(_n), bridge(_n) {}

    void dfs(int v, int p, int& cnt) {
        ord[v] = low[v] = cnt++;
        int count_son = 0, p_idx = -1;
        for (int i = 0; i < (int)g[v].size(); i++) {
            int u = g[v][i];
            if (ord[u]) {
                if (u != p) low[v] = min(low[v], ord[u]);
                if (u == p) p_idx = i;
            } else {
                count_son++;
                dfs(u, v, cnt);
                bridge[v][i] = ord[v] < low[u];
                low[v] = min(low[v], low[u]);
                aps[v] |= ord[v] <= low[u];
            }
        }


        if (p == -1) aps[v] = count_son >= 2;
        else bridge[v][p_idx] = ord[p] < low[v];
    }

    void build() {
        built = true;
        for (int i = 0; i < n; i++) bridge[i].resize(g[i].size());
        for (int i = 0; i < n; i++) {
            if (ord[i]) continue;
            int cnt = 1;
            dfs(i, -1, cnt);
        }
    }

    bool is_aps(int v) {
        assert(built);
        assert(0 <= v && v < n);
        return aps[v];
    }

    bool is_bridge(int v, int i) {
        assert(built);
        assert(0 <= v && v < n);
        assert(0 <= i && i < (int)bridge[v].size());
        return bridge[v][i];
    }
};