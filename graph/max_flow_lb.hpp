template<class F>
struct max_flow_lb {
    dinic<F> f;
    int S, T;
    F sum_lb;

    max_flow_lb (int n) : f(n + 2), S(n), T(n + 1), sum_lb(0) {}

    void add_edge(int u, int v, int lb, int ub) {
        assert(0 <= lb && lb <= ub);
        if (ub == 0) return;
        f.add_edge(u, v, ub - lb);
        if (lb == 0) return;
        sum_lb += lb;
        f.add_edge(S, v, lb);
        f.add_edge(u, T, lb);
    }

    F max_flow(int s, int t) {
        F a = f.max_flow(S, T);
        F b = f.max_flow(s, T);
        F c = f.max_flow(S, t);
        F d = f.max_flow(s, t);
        return (a + b == sum_lb && a + c == sum_lb) ? b + d : -1;
    }
};