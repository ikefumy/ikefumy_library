#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define db double
#define pii pair<int,int>
#define pli pair<ll,int>
#define pil pair<int,ll>
#define pll pair<ll,ll>
#define ti3 tuple<int,int,int>
#define int128 __int128_t
#define pii128 pair<int128,int128>
const int inf = 1 << 30;
const ll linf = 1e18;
const db EPS = 1e-10;
const db pi = acos(-1);
template<class T> bool chmin(T& x, T y){
    if(x > y) {
        x = y;
        return true;
    } else return false;
}
template<class T> bool chmax(T& x, T y){
    if(x < y) {
        x = y;
        return true;
    } else return false;
}

// overload macro
#define CAT( A, B ) A ## B
#define SELECT( NAME, NUM ) CAT( NAME, NUM )

#define GET_COUNT( _1, _2, _3, _4, _5, _6 /* ad nauseam */, COUNT, ... ) COUNT
#define VA_SIZE( ... ) GET_COUNT( __VA_ARGS__, 6, 5, 4, 3, 2, 1 )

#define VA_SELECT( NAME, ... ) SELECT( NAME, VA_SIZE(__VA_ARGS__) )(__VA_ARGS__)

// rep(overload)
#define rep( ... ) VA_SELECT(rep, __VA_ARGS__)
#define rep2(i, n) for (int i = 0; i < int(n); i++)
#define rep3(i, a, b) for (int i = a; i < int(b); i++)
#define rep4(i, a, b, c) for (int i = a; i < int(b); i += c)

// repll(overload)
#define repll( ... ) VA_SELECT(repll, __VA_ARGS__)
#define repll2(i, n) for (ll i = 0; i < (ll)(n); i++)
#define repll3(i, a, b) for (ll i = a; i < (ll)(b); i++)
#define repll4(i, a, b, c) for (ll i = a; i < (ll)(b); i += c)

// rrep(overload)
#define rrep( ... ) VA_SELECT(rrep, __VA_ARGS__)    
#define rrep2(i, n) for (int i = n - 1; i >= 0; i--)
#define rrep3(i, a, b) for (int i = b - 1; i >= a; i--)
#define rrep4(i, a, b, c) for (int i = b - 1; i >= a; i -= c)

// rrepll(overload)
#define rrepll( ... ) VA_SELECT(rrepll, __VA_ARGS__)
#define rrepll2(i, n) for (ll i = (ll)(n) - 1; i >= 0ll; i--)
#define rrepll3(i, a, b) for (ll i = b - 1; i >= (ll)(a); i--)
#define rrepll4(i, a, b, c) for (ll i = b - 1; i >= (ll)(a); i -= c)

// for_earh
#define fore(e, v) for (auto&& e : v)

// vector
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()