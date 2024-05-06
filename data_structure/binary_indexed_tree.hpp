template<class T>
struct binary_indexed_tree {
    int N;
    vector<T> bit;
    binary_indexed_tree (int n = 0) : N(n), bit(n + 1, 0) {}
    T sum(int i){
        T s = 0;
        while(i > 0){
            s += bit[i];
            i -= i & -i;
        }
        return s;
    }

    void add(int i, T x){
        i++;
        while(i <= N){
            bit[i] += x;
            i += i & -i;
        }
    }
    T sum(int l, int r){
        return sum(r) - sum(l);
    }
};