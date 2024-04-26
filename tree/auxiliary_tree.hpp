#include "lowest_common_ancestor.hpp"

struct auxiliary_tree : lowest_common_ancestor {
    vector<int> used;
    auxiliary_tree(int _n) : lowest_common_ancestor(_n), used(_n) {}
    void build() {
        lowest_common_ancestor::build();
    }

    pair<vector<vector<int>>, vector<int>> get_at(vector<int> v) {
        sort(v.begin(), v.end(), [&](int a, int b) {
            return in[a] < in[b];
        });
        
        for (auto u : v) used[u] = true;
        for (int i = 1; i < (int)v.size(); i++) {
            int lca = get_lca(v[i - 1], v[i]);
            if (!used[lca]) {
                used[lca] = true;
                v.emplace_back(lca);
            }
        }

        sort(v.begin(), v.end(), [&](int a, int b) {
            return in[a] < in[b];
        });

        vector<vector<int>> ret(v.size());
        stack<int> rem;
        for (int i = 0; i < (int)v.size(); i++) {
            used[v[i]] = false;
            while (!rem.empty() && out[v[rem.top()]] < in[v[i]]) rem.pop();
            if (!rem.empty()) {
                int a = rem.top(), b = i;
                ret[a].push_back(b);
                ret[b].push_back(a);
            }
            rem.push(i);
        }

        return {ret, v};
    }
};