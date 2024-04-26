#include "../graph/undirected_graph.hpp"

struct lowest_common_ancestor : undirected_graph {
    bool built = false;
    int logn = 0, s, B, logB = 0;
    vector<int> euler_tour, depth, in, out, log_table, diff;
    vector<vector<int>> sparse_table;
    vector<vector<vector<int>>> table_lookup;
    lowest_common_ancestor(int _n) : undirected_graph(_n), depth(_n), in(_n), out(_n) {
        while ((1 << logn) <= 2 * n - 1) logn++;
        s = max(1, logn / 2);
        B = (2 * n - 2) / s + 1;
        while ((1 << logB) <= B) logB++;

        diff = vector(B, 0);
        log_table = vector(B, 0);
        sparse_table = vector(B, vector<int>(logB, -1));
        table_lookup = vector(1 << (s - 1), vector(s, vector<int>(s, -1)));
        // table_loopupの構築
        for (int i = 0; i < 1 << (s - 1); i++) {
            for (int l = 0; l < s; l++) {
                int ans = l, mn = 0, val = 0;
                for (int r = l; r < s; r++) {
                    table_lookup[i][l][r] = ans;
                    val += ((i >> r & 1) ? 1 : -1);
                    if (val < mn) {
                        mn = val;
                        ans = r + 1;
                    }
                }
            }
        }
    }

    void dfs(int v, int p) {
        in[v] = euler_tour.size();
        euler_tour.emplace_back(v);
        for (auto&& u : g[v]) {
            if (u == p) continue;
            depth[u] = depth[v] + 1;
            dfs(u, v);
            euler_tour.emplace_back(v);
        }
        out[v] = euler_tour.size() - 1;
    }

    int get_min(const int& u, const int& v) {
        if (u == -1) return v;
        else if (v == -1) return u;
        else return depth[u] < depth[v] ? u : v;
    }

    void build() {
        built = true;
        dfs(0, -1);

        // table_lookup用の配列
        for (int i = 0; i < 2 * n - 2; i++) {
            if (i / s != (i + 1) / s) continue;
            if (depth[euler_tour[i]] < depth[euler_tour[i + 1]]) {
                diff[i / s] |= 1 << (i % s);
            }
        }

        // sparse tableの構築
        for (int i = 0; i < 2 * n - 1; i++) {
            int b = i / s;
            sparse_table[b][0] = get_min(sparse_table[b][0], euler_tour[i]);
        }
        for (int j = 1; j < logB; j++) {
            for (int i = 1 << j; i < min(1 << (j + 1), B); i++) {
                log_table[i] = j;
            }
            for (int i = 0; i < B; i++) {
                if (i + (1 << (j - 1)) >= B) break;
                int v1 = sparse_table[i][j - 1];
                int v2 = sparse_table[i + (1 << (j - 1))][j - 1];
                sparse_table[i][j] = get_min(sparse_table[i][j - 1], sparse_table[i + (1 << (j - 1))][j - 1]);
            }
        }
    }

    int get_lca(int u, int v) {
        assert(built);
        if (in[u] > in[v]) swap(u, v);
        int ret = 0;
        int bu = in[u] / s, bv = in[v] / s;
        if (bu == bv) {
            ret = euler_tour[bu * s + table_lookup[diff[bu]][in[u] % s][in[v] % s]];
        } else {
            ret = get_min(euler_tour[bu * s + table_lookup[diff[bu]][in[u] % s][s - 1]], euler_tour[bv * s + table_lookup[diff[bv]][0][in[v] % s]]);
            if (bv - 1 - bu > 0) {
                int len = bv - 1 - bu;
                ret = get_min(ret, sparse_table[bu + 1][log_table[len]]);
                ret = get_min(ret, sparse_table[bv - (1 << log_table[len])][log_table[len]]);
            }
        }
        return ret;
    }
};