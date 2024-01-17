template<class T>
vector<tuple<T, T, T>> quotient_range(T n){
    vector<T> qs;
    T i = 0;
    for(i = 1; i * i <= n; i++){
        qs.emplace_back(i);
    }
    i--;
    if (n / i == i) i--;
    for (; i >= 1; i--) {
        qs.emplace_back(n / i);
    }

    vector<tuple<T, T, T>> res = {{1, 1, n}};
    for (int i = 0; i + 1 < (int)qs.size(); i++) {
        res.emplace_back(qs[i] + 1, qs[i + 1], n / qs[i + 1]);
    }
    return res;
}