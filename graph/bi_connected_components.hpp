#include "lowlink.hpp"

struct bi_connected_components : lowlink {
    vector<vector<int>> components;
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
                    components.emplace_back();
                    while (!tmp.empty()) {
                        auto [a, b] = tmp.back();
                        tmp.pop_back();
                        if (!used[a]) components.back().emplace_back(a), used[a] = true;
                        if (!used[b]) components.back().emplace_back(b), used[b] = true;
                        if (a == min(u, v) && b == max(u, v)) break;
                    }
                    for (auto elem : components.back()) used[elem] = false;
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

        for (auto c : components) {
            for (auto v : c) {
                used[v] = true;
            }
        }

        for (int v = 0; v< n; v++) {
            if (used[v]) continue;
            components.push_back({v});
        }
    }

    vector<vector<int>> get_components() {
        assert(built);
        return components;
    }
};