/*
 Author: Jorge_Slime
                Created: 
                Time: 
...
*/
// template for c++17 Onwars | SOLVE_LINE-> 180
#if !defined(ENABLE_DEBUG) && !defined(__clang__)
#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx2,bmi2") // ._. It does not work in Arch Linux :')
#endif

#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

#define LN                                                               '\n'
#define sz(x)                                                  (int) x.size()
#define all(x)                                               begin(x), end(x)
#define rall(x)                                            rbegin(x), rend(x)
#define in(v)                                           forn(i,sz(v)) cin>>i;
#define ou(v)                                  forn(i,sz(v)) cout<<v[i]<<" ";
#define DBG(x)                                                           (#x)
#define mem(a, h)                                   memset(a, (h), sizeof(a))
#define pb                                                          push_back
#define eb                                                       emplace_back
#define F                                                               first
#define S                                                              second
#define MIN(v)                                           *min_element(all(v))
#define MAX(v)                                           *max_element(all(v))
#define LB(c, x)              distance((c).begin(), lower_bound(all(c), (x)))
#define UB(c, x)              distance((c).begin(), upper_bound(all(c), (x)))
#define UNIQUE(x) \
            sort(all(x)), x.erase(unique(all(x)), x.end()), x.shrink_to_fit()
#define                                  FOR1(a) for (auto _ = 0; _ < a; ++_)
#define                               FOR2(i, a) for (auto i = 0; i < a; ++i)
#define                            FOR3(i, a, b) for (auto i = a; i < b; ++i)
#define                      FOR4(i, a, b, c) for (auto i = a; i < b; i+=(c))
#define                           FOR1_R(a) for (auto i = (a)-1; i >= 0; --i)
#define                        FOR2_R(i, a) for (auto i = (a)-1; i >= 0; --i)
#define                     FOR3_R(i, a, b) for (auto i = (b)-1; i >= a; --i)
#define                                       overload4(a, b, c, d, e, ...) e
#define                                          overload3(a, b, c, d, ...) d
#define forn(...) overload4(__VA_ARGS__, FOR4, FOR3, FOR2, FOR1)(__VA_ARGS__)
#define rfor(...) overload3(__VA_ARGS__, FOR3_R, FOR2_R, FOR1_R)(__VA_ARGS__)
#define INT(...) \
  int __VA_ARGS__; \
  rd(__VA_ARGS__)
#define LL(...) \
  ll __VA_ARGS__; \
  rd(__VA_ARGS__)
#define vec(type, name, size) \
  vector<type> name(size);    \
  cin>>v;                     \
  sort(all(v));
/*==========================================================================================*/
template<typename T>  using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename T>                       using  pq = priority_queue<T>;
template<typename T>  using pqg = priority_queue<T,vector<T>,greater<T>>;
template<typename T>                       using             V=vector<T>;
template<typename AA,typename BB>          using UM=unordered_map<AA,BB>;
template<typename T>                       using     US=unordered_set<T>;
template<typename AA,typename BB>          using            M=map<AA,BB>;
template<typename AA,typename BB>          using           P=pair<AA,BB>;
using                                                  uint=unsigned int;
using                                                       ll=long long;
using                                             ull=unsigned long long;
using                                                          dd=double;
using                                                    ldd=long double;
using                                                      i128=__int128;
using                                                    f128=__float128;
using                                             u128=unsigned __int128;
/*==========================================================================================*/
//Short funcions
template <typename T> inline T max_(T a, T b) { return (a > b) ? a : b;}
template <typename T> inline T min_(T a, T b) { return (a < b) ? a : b;}
template <typename T> inline T abs_(T x) { return (x < 0) ? -x : x;}
template <typename T> inline T mcm_(T a,T b){return a*b/__gcd(a,b);}
// cin->vector
template <typename T>
istream &operator>>(istream &is, vector<T> &v) {
  for (T &in : v) is >> in;
  return is;
}
// cin->vector(pair)
template <typename T>
istream &operator>>(istream &is, vector<pair<T, T>> &v) {
  for (auto &in : v) is >> in.first >> in.second;
  return is;
}
template <class T, class S>
inline bool chmax(T &a, const S &b) {
  return (a < b ? a = b, 1 : 0);
}
template <class T, class S>
inline bool chmin(T &a, const S &b) {
  return (a > b ? a = b, 1 : 0);
}
//#if __cplusplus >= 201703L
// -> C++17 Onwars... 
template <class... T>
void rd(T &...a) {
  (cin>> ... >> a);
}
//Generate ramdomic numbers c++17 onwers
//inline mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//#endif
// DEGUGGER PREMIUM XD 
template <class Head, class... Tail>
inline void deb(Head &&head, Tail &&...tail) {
    cerr << "DBG: " << head;
    if constexpr (sizeof...(tail) == 0) {
        cerr << '\n';
    } else {
        cerr << ' ';
        deb(forward<Tail>(tail)...);
    }
}
template<typename T> inline void deb(V<T>&v){ cerr<<DBG(v)<<"-> ";for(auto&&i:v) cerr<<i<<" ";cerr<<LN;}
template<typename T> inline void deb(V<T>&v,int n){ cerr<<DBG(v)<<"-> ";forn(i,n) cerr<<v[i]<<" ";cerr<<LN;}
template<typename T> inline void deb(T v[],int n){ cerr<<DBG(v)<<"-> ";forn(i,n) cerr<<v[i]<<" ";cerr<<LN;}
//simple print 
template <class Head, class... Tail>
inline void print(Head &&head, Tail &&...tail) {
    cout << head;
    if constexpr (sizeof...(tail) == 0) {
        cout << '\n';
    } else {
        cout << ' ';
        print(forward<Tail>(tail)...);
    }
}
//print Vector
template<typename T> inline void print(V<T>&v){ ou(v);; cout<<LN;}
template<typename T> inline void print(V<T>&v,int n){forn(i,n) cout<<v[i]<<" ";cout<<LN;}
template<typename T> inline void print(T v[],int n){forn(i,n) cout<<v[i]<<" ";cout<<LN;}
inline void YES(bool t = 1) { cout<<(t ? "YES" : "NO")<<LN; }
inline void NO(bool t = 1) { YES(!t); }
inline void Yes(bool t = 1) { cout<<(t ? "Yes" : "No")<<LN; }
inline void No(bool t = 1) { Yes(!t); }
inline void yes(bool t = 1) { cout<<(t ? "yes" : "no")<<LN; }
inline void no(bool t = 1) { yes(!t); }
/*==========================================================================================*/
//Constants
const int dx[]={-1, 0, 1, 0},dy[]={0, 1, 0, -1};
const int MOD=1000000007;
const int MOD99=998244353;
template <class T> constexpr T INF = 0;
template <> constexpr int INF<int> = 1'000'000'000;
template <> constexpr ll INF<ll> = ll(INF<int>) * INF<int> * 2;
template <> constexpr ull INF<ull> = INF<ll>;
template <> constexpr i128 INF<i128> = i128(INF<ll>) * INF<ll>;
template <> constexpr double INF<double> = INF<ll>;
template <> constexpr long double INF<long double> = INF<ll>;
/*==========================================================================================*/

// ===============SOLUTION======================================
inline void XD();

auto main()->signed{//turbo_PA;
   cin.tie(nullptr)->sync_with_stdio(false);
   cin.exceptions(std::ios::failbit | std::ios::badbit);
   cout.tie(nullptr)->sync_with_stdio(false);
   XD();
   return 0;
} 

void solve(){

}

inline void XD(){
    ll TT=1;
    //cin>>TT;
    //ll TestCase(0);
    for(;TT--;){
        //TestCase++;
        //cout<<"Case #"<<TestCase<<":"<<LN;
        solve();
    }
}
/*
   -"No bajes tus sueños a la altura de tus capacidades aparentes, sino haz que
     estas se eleven hasta llegar a la altura de tus sueños."
   -"Todo mundo quiere ir al cielo pero nadie quiere morir."
   -"Tarde o temprano la disciplina supera al talento."
   -"Get A Life!!!!!"
*/
