template<class F>
struct dinic {
    struct edge {
        int to;
        F cap;
        int rev;
        edge(){}
        edge(int to, F cap, int rev) : to(to), cap(cap), rev(rev) {}
    };

    vector<vector<edge>> g;
    vector<int> level;
    vector<int> iter;
    
    dinic(int v) : g(v), level(v), iter(v) {}
 
    void add_edge(int from, int to, F cap) {
        g[from].push_back({to, cap, (int)g[to].size()});
        g[to].push_back({from, 0, (int)g[from].size() - 1});
    }
 
    void bfs(int s) {
        fill(level.begin(), level.end(), -1);
        queue<int> que;
        level[s] = 0;
        que.push(s);
        while (!que.empty()) {
            int v = que.front();
            que.pop();
            for (auto& e : g[v]) {
                if (e.cap > 0 && level[e.to] < 0) {
                    level[e.to] = level[v] + 1;
                    que.push(e.to);
                }
            }
        }
    }
 
    F dfs(int v, int t, F f) {
        if (v == t) return f;
        for (int &i = iter[v]; i < (int)g[v].size(); i++) {
            edge &e = g[v][i];
            if (e.cap > 0 && level[v] < level[e.to]) {
                int d = dfs(e.to, t, min(f, e.cap));
                if (d > 0) {
                    e.cap -= d;
                    g[e.to][e.rev].cap += d;
                    return d;
                }
            }
        }
        return 0;
    }
 
    F max_flow(int s, int t) {
        F flow = 0;
        while(true) {
            bfs(s);
            if (level[t] < 0) return flow;
            fill(iter.begin(), iter.end(), 0);
            F f;
            while ((f = dfs(s, t, inf)) > 0) {
                flow += f;
            }
        }
        return flow;
    }

    vector<vector<edge>> get_g() {
        return g;
    }
};