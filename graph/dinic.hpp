template<class T>
struct Dinic {
    struct edge {
        int to, rev;
        T cap;
        edge(){}
        edge(int to, T cap, int rev) : to(to), cap(cap), rev(rev) {}
    };

    vector<vector<edge>> g;
    vector<int> level;
    vector<int> iter;
    
    Dinic(int v) : g(v), level(v), iter(v) {}
 
    void add_edge(int from, int to, ll cap) {
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
 
    T dfs(int v, int t, T f) {
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
 
    T max_flow(int s, int t) {
        T flow = 0;
        while(true) {
            bfs(s);
            if (level[t] < 0) return flow;
            fill(iter.begin(), iter.end(), 0);
            T f;
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