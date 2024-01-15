struct directed_graph {
    int n;
    vector<vector<int>> g, rg;
    directed_graph(int _n) : n(_n), g(_n), rg(_n) {}
    void add_edge(int from, int to) {
        assert(0 <= from && from < n);
        assert(0 <= to && to < n);
        g[from].emplace_back(to);
        rg[to].emplace_back(from);
    }
};