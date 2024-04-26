template<class T, T e, int NODES = 30000000>
struct dynamic_li_chao_tree {
    struct Line {
        T a, b;
        Line (T _a = e, T _b = e) : a(_a), b(_b) {};
        T get_val (T x) {
            return (a == e ? e : a * x + b);
        }
    };

    struct Node {
        inline static int node_count = 0;
        inline static Node* pool;
        Line x;
        Node *l, *r;
        Node () : x(), l(nullptr), r(nullptr) {}

        void *operator new(size_t) {
            return pool + node_count++;
        }
    };

    T x_min, x_max;
    Node *root;

    dynamic_li_chao_tree (T _x_min, T _x_max) : x_min(_x_min), x_max(_x_max), root(nullptr) {
        Node::pool = new Node[NODES];
        root = new Node();
    }

    void add_line (T a, T b) {
        add_seg({a, b}, x_min, x_max, root, x_min, x_max);
    }

    void add_seg (T a, T b, T l, T r) {
        add_seg({a, b}, l, r, root, x_min, x_max);
    }
    
    T get_min (T i) {
        return get_min(i, root, x_min, x_max);
    }

private:
    void add_seg (Line x, T a, T b, Node *node, T l, T r) {
        if (b <= l || r <= a) return;
        if (a <= l && r <= b) {
            if (node->x.get_val(l) >= x.get_val(l) && node->x.get_val(r - 1) >= x.get_val(r - 1)) {
                node->x = x;
                return;
            }
            if (node->x.get_val(l) <= x.get_val(l) && node->x.get_val(r - 1) <= x.get_val(r - 1)) {
                return;
            }
        }
        if (node->l == nullptr) node->l = new Node();
        if (node->r == nullptr) node->r = new Node();
        add_seg(x, a, b, node->l, l, (l + r) / 2);
        add_seg(x, a, b, node->r, (l + r) / 2, r);
    }

    T get_min (T i, Node *node, T l, T r) {
        if (i < l || r <= i) return e;
        if (i <= l && r <= i + 1) return node->x.get_val(i);
        T ret = (node->x.a != e ? node->x.get_val(i) : e);
        if (node->l != nullptr) ret = min(ret, get_min(i, node->l, l, (l + r) / 2));
        if (node->r != nullptr) ret = min(ret, get_min(i, node->r, (l + r) / 2, r));
        return ret;
    }
};