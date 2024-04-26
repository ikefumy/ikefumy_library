template<class T, T(* op)(T, T), T(* e)(), int NODES = 2700000>
struct persistent_segment_tree {
    struct Node {
        inline static int node_count = 0;
        inline static Node* pool;
        T val;
        Node *l, *r;

        Node () : val(e()), l(nullptr), r(nullptr) {}
        void *operator new(std::size_t) {
            return pool + node_count++;
        }
        inline static void delete_all() { Node::node_count = 0; }
    };

    int n;
    vector<Node *> roots;
    stack<Node *> nodes;
    stack<tuple<Node *, int, int>> rng;

    persistent_segment_tree(int _n) : n(1) {
        Node::pool = new Node[NODES];
        while (n < _n) n *= 2;
        roots.push_back(new Node());
        queue<tuple<Node *, int ,int>> que;
        que.push({roots[0], 0, n});
        while (!que.empty()) {
            auto [node, l, r] = que.front(); que.pop();
            if (r == l + 1) continue;
            node->l = new Node();
            node->r = new Node();
            que.push({node->l, l, (l + r) / 2});
            que.push({node->r, (l + r) / 2, r});
        }
    }

    int update(int i, T x, int id = -1) {
        if (id < 0) id = roots.size() - 1;
        Node *pre = roots[id];
        Node *crt = new Node();
        roots.push_back(crt);
        // 更新するnodeを探す
        int l = 0, r = n;
        while (l + 1 < r) {
            nodes.push(crt);
            if (i < (l + r) / 2) {
                crt->l = new Node();
                crt->r = pre->r;
                crt = crt->l;
                pre = pre->l;
                r = (l + r) / 2;
            } else {
                crt->l = pre->l;
                crt->r = new Node();
                crt = crt->r;
                pre = pre->r;
                l = (l + r) / 2;
            }
        }
        // 更新する
        crt->val = x;
        while (!nodes.empty()) {
            crt = nodes.top(); nodes.pop();
            crt->val = op(crt->l->val, crt->r->val);
        }
        return roots.size() - 1;
    }

    T prod(int a, int b, int id = -1) {
        if (id == -1) id = roots.size() - 1;
        int l = 0, r = n;
        rng.push({roots[id], l, r});
        T ret = e();
        while (!rng.empty()) {
            auto [node, l, r] = rng.top(); rng.pop();
            if (b <= l || r <= a) continue;
            if (a <= l && r <= b) {
                ret = op(ret, node->val);
            } else {
                rng.push({node->r, (l + r) / 2, r});
                rng.push({node->l, l, (l + r) / 2});
            }
        }
        return ret;
    }

    ~persistent_segment_tree() {
        delete[] Node::pool;
    }
};