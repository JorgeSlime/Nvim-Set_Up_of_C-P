/*
 Author: Jorge_Slime
                Created: 
                Time: 
...
*/
// template for c++17 Onwars | SOLVE_LINE-> 376
#if !defined(ENABLE_DEBUG) && !defined(__clang__) // for more check this blog https://codeforces.com/blog/entry/96344
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
#define mem(a, h)                                   memset(a, (h), sizeof(a))
#define DBG(x)                                                           (#x)
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
#define                                  FOR1(a) for (auto _ = 0; _ < a; ++_) //for more check this blog -> https://trap.jp/post/1224/
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
  in(__VA_ARGS__)
#define LL(...) \
  ll __VA_ARGS__; \
  in(__VA_ARGS__)
#define vec(type, name, size) \
  vector<type> name(size);    \
  in(name);                   \
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
template <class T, class S>
inline bool chmax(T &a, const S &b) {
  return (a < b ? a = b, 1 : 0);
}
template <class T, class S>
inline bool chmin(T &a, const S &b) {
  return (a > b ? a = b, 1 : 0);
}

//Generate ramdomic numbers c++17 onwers
//inline mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//#endif
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
inline void print_(Head &&head, Tail &&...tail) {
    cout << head;
    if constexpr (sizeof...(tail) == 0) {
        cout << '\n';
    } else {
        cout << ' ';
        print_(forward<Tail>(tail)...);
    }
}
//print Vector or array
template<typename T> inline void print_(V<T>&v){ ou(v);; cout<<LN;}
template<typename T> inline void print_(V<T>&v,int n){forn(i,n) cout<<v[i]<<" ";cout<<LN;}
template<typename T> inline void print_(T v[],int n){forn(i,n) cout<<v[i]<<" ";cout<<LN;}
//fastIO ULTRA PREMIUM-> ONLY FILES ENTRY
namespace fastio {  //for more check this blog https://judge.yosupo.jp/submission/21623
static constexpr uint32_t SZ = 1 << 17;
char ibuf[SZ];
char obuf[SZ];
char out[100];
// pointer of ibuf, obuf
uint32_t pil = 0, pir = 0, por = 0;
struct Pre {
  char num[10000][4];
  constexpr Pre() : num() {
    for (int i = 0; i < 10000; i++) {
      int n = i;
      for (int j = 3; j >= 0; j--) {
        num[i][j] = n % 10 | '0';
        n /= 10;
      }
    }
  }
} constexpr pre;
 
inline void load() {
  memcpy(ibuf, ibuf + pil, pir - pil);
  pir = pir - pil + fread(ibuf + pir - pil, 1, SZ - pir + pil, stdin);
  pil = 0;
  if (pir < SZ) ibuf[pir++] = '\n';
}
inline void flush() {
  fwrite(obuf, 1, por, stdout);
  por = 0;
}
 
void rd(char &c) {
  do {
    if (pil + 1 > pir) load();
    c = ibuf[pil++];
  } while (isspace(c));
}
 
void rd(string &x) {
  x.clear();
  char c;
  do {
    if (pil + 1 > pir) load();
    c = ibuf[pil++];
  } while (isspace(c));
  do {
    x += c;
    if (pil == pir) load();
    c = ibuf[pil++];
  } while (!isspace(c));
}
 
template <typename T>
void rd_real(T &x) {
  string s;
  rd(s);
  x = stod(s);
}
 
template <typename T>
void rd_integer(T &x) {
  if (pil + 100 > pir) load();
  char c;
  do
    c = ibuf[pil++];
  while (c < '-');
  bool minus = 0;
  if constexpr (is_signed<T>::value || is_same_v<T, i128>) {
    if (c == '-') { minus = 1, c = ibuf[pil++]; }
  }
  x = 0;
  while ('0' <= c) { x = x * 10 + (c & 15), c = ibuf[pil++]; }
  if constexpr (is_signed<T>::value || is_same_v<T, i128>) {
    if (minus) x = -x;
  }
}
 
void rd(int &x) { rd_integer(x); }
void rd(ll &x) { rd_integer(x); }
void rd(i128 &x) { rd_integer(x); }
void rd(uint &x) { rd_integer(x); }
void rd(ull &x) { rd_integer(x); }
void rd(u128 &x) { rd_integer(x); }
void rd(double &x) { rd_real(x); }
void rd(long double &x) { rd_real(x); }
void rd(f128 &x) { rd_real(x); }
 
template <class T, class U>
void rd(pair<T, U> &p) {
  return rd(p.first), rd(p.second);
}
template <size_t N = 0, typename T>
void rd_tuple(T &t) {
  if constexpr (N < std::tuple_size<T>::value) {
    auto &x = std::get<N>(t);
    rd(x);
    rd_tuple<N + 1>(t);
  }
}
template <class... T>
void rd(tuple<T...> &tpl) {
  rd_tuple(tpl);
}
 
template <size_t N = 0, typename T>
void rd(array<T, N> &x) {
  for (auto &d: x) rd(d);
}
template <class T>
void rd(V<T> &x) {
  for (auto &d: x) rd(d);
}
 
void in() {}
template <class H, class... T>
void in(H &h, T &... t) {
  rd(h), in(t...);
}
 
void wt(const char c) {
  if (por == SZ) flush();
  obuf[por++] = c;
}
void wt(const string s) {
  for (char c: s) wt(c);
}
void wt(const char *s) {
  size_t len = strlen(s);
  for (size_t i = 0; i < len; i++) wt(s[i]);
}
 
template <typename T>
void wt_integer(T x) {
  if (por > SZ - 100) flush();
  if (x < 0) { obuf[por++] = '-', x = -x; }
  int outi;
  for (outi = 96; x >= 10000; outi -= 4) {
    memcpy(out + outi, pre.num[x % 10000], 4);
    x /= 10000;
  }
  if (x >= 1000) {
    memcpy(obuf + por, pre.num[x], 4);
    por += 4;
  } else if (x >= 100) {
    memcpy(obuf + por, pre.num[x] + 1, 3);
    por += 3;
  } else if (x >= 10) {
    int q = (x * 103) >> 10;
    obuf[por] = q | '0';
    obuf[por + 1] = (x - q * 10) | '0';
    por += 2;
  } else
    obuf[por++] = x | '0';
  memcpy(obuf + por, out + outi + 4, 96 - outi);
  por += 96 - outi;
}
template <typename T>
void wt_real(T x) {
  ostringstream oss;
  oss << fixed << setprecision(15) << double(x);
  string s = oss.str();
  wt(s);
}
 
inline void wt(int x) { wt_integer(x); }
inline void wt(ll x) { wt_integer(x); }
inline void wt(i128 x) { wt_integer(x); }
inline void wt(uint x) { wt_integer(x); }
inline void wt(ull x) { wt_integer(x); }
inline void wt(u128 x) { wt_integer(x); }
inline void wt(double x) { wt_real(x); }
inline void wt(long double x) { wt_real(x); }
inline void wt(f128 x) { wt_real(x); }
 
template <class T, class U>
void wt(const pair<T, U> val) {
  wt(val.first);
  wt(' ');
  wt(val.second);
}

template <size_t N = 0, typename T>
void wt_tuple(const T t) {
  if constexpr (N < std::tuple_size<T>::value) {
    if constexpr (N > 0) { wt(' '); }
    const auto x = std::get<N>(t);
    wt(x);
    wt_tuple<N + 1>(t);
  }
}
template <class... T>
void wt(tuple<T...> tpl) {
  wt_tuple(tpl);
}
template <class T, size_t S>
void wt(const array<T, S> val) {
  auto n = val.size();
  for (size_t i = 0; i < n; i++) {
    if (i) wt(' ');
    wt(val[i]);
  }
}
template <class T>
void wt(const vector<T> val) {
  auto n = val.size();
  for (size_t i = 0; i < n; i++) {
    if (i) wt(' ');
    wt(val[i]);
  }
}
void print() { wt('\n'); }
template <class Head, class... Tail>
void print(Head &&head, Tail &&... tail) {
  wt(head);
  if (sizeof...(Tail)) wt(' ');
  print(forward<Tail>(tail)...);
}
// gcc expansion. called automaticall after main.
void __attribute__((destructor)) _d() { flush(); }
} // namespace fastio
using fastio::in;
using fastio::print;
using fastio::flush;
//YES or NO
inline void YES(bool t = 1) { print(t ? "YES" : "NO"); }
inline void NO(bool t = 1) { YES(!t); }
inline void Yes(bool t = 1) { print(t ? "Yes" : "No"); }
inline void No(bool t = 1) { Yes(!t); }
inline void yes(bool t = 1) { print(t ? "yes" : "no"); }
inline void no(bool t = 1) { yes(!t); }
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
    //in(TT);
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

