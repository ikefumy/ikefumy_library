struct union_find {
    int n;
    vector<int> par, rnk, wt;

    union_find(int _n) : n(_n), par(_n), rnk(_n), wt(_n, 1) {
        iota(par.begin(), par.end(), 0);
    }

    void set_wt(int v, int w) {
        wt[v] = w;
    }

    int find(int v) {
        return par[v] == v ? v : par[v] = find(par[v]);
    }

    bool same(int u, int v) {
        return find(u) == find(v);
    }

    void unite(int u, int v) {
        u = find(u), v = find(v);
        if (u == v) return;
        if (rnk[u] < rnk[v]) swap(u, v);
        rnk[u] += rnk[u] == rnk[v];
        par[v] = par[u];
        wt[u] += wt[v];
    }

    int get_wt(int v) {
        return wt[find(v)];
    }
};