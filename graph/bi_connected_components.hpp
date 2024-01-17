#include "lowlink.hpp"

struct bi_connected_components : lowlink {
    vector<vector<int>> comps;
    vector<int> used, visited;
    vector<pair<int, int>> tmp;
    bi_connected_components(int _n) : lowlink(_n), used(_n), visited(_n) {}

    void dfs(int v, int p) {
        visited[v] = true;
        for (auto&& u : g[v]) {
            if (u == p) continue;
            if (!visited[u] || ord[u] < ord[v]) tmp.emplace_back(min(u, v), max(u, v));
            if (!visited[u]) {
                dfs(u, v);
                if (low[u] >= ord[v]) {
                    comps.emplace_back();
                    while (!tmp.empty()) {
                        auto [a, b] = tmp.back();
                        tmp.pop_back();
                        if (!used[a]) comps.back().emplace_back(a), used[a] = true;
                        if (!used[b]) comps.back().emplace_back(b), used[b] = true;
                        if (a == min(u, v) && b == max(u, v)) break;
                    }
                    for (auto elem : comps.back()) used[elem] = false;
                }
            }
        }
    }

    void build() {
        lowlink::build();
        for (int v = 0; v < n; v++) {
            if (visited[v]) continue;
            dfs(v, -1);
        }

        for (auto comp : comps) {
            for (auto v : comp) {
                used[v] = true;
            }
        }

        for (int v = 0; v< n; v++) {
            if (used[v]) continue;
            comps.push_back({v});
        }
    }

    vector<vector<int>> get_comps() {
        assert(built);
        return comps;
    }
};