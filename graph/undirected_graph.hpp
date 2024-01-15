struct undirected_graph {
public:
    int n;
    vector<vector<int>> g;

    undirected_graph(int _n = 0) : n(_n), g(_n) {}
    void add_edge(int u, int v) {
        assert(0 <= u && u < n);
        assert(0 <= v && v < n);
        g[u].push_back(v);
        g[v].push_back(u);
    }
};