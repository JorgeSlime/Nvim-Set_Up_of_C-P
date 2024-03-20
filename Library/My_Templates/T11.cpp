/*
 Author: Jorge_Slime
                Created: 
                Time: 
...
*/
//C++11... solve line -> 67
#include <bits/stdc++.h>

using namespace std;

#define LN                                                           '\n'
#define sz(x)                                              (int) x.size()
#define all(x)                                           begin(x), end(x)
#define rall(x)                                        rbegin(x), rend(x)

#define forn(i, n)                            for (auto i = 0; i <n; i++)
#define for1(i, n)                           for (auto i = 1; i <=n; i++)
#define loop(a,b,c)                            for(auto a = b; a <c; a++)
#define in(v)                                      for(auto &i:v) cin>>i;
#define ou(v)                                for(auto &i:v) cout<<i<<" ";
#define mem(a, h)                               memset(a, (h), sizeof(a))

#define pb                                                      push_back
#define eb                                                   emplace_back
#define F                                                           first
#define S                                                          second
#define V                                                          vector
/*==========================================================================================*/
typedef                                                     long long ll;
typedef                                           unsigned long long ull;
typedef                                                        double dd;
typedef                                                 pair<int,int> ii;
typedef                                                   vector<ii> vii;
typedef                                                   vector<int> vi;
typedef                                                   vector<ll> vil;
/*==========================================================================================*/
//Short funcions
template <typename T> inline T max_(T a, T b) { return (a > b) ? a : b;}
template <typename T> inline T min_(T a, T b) { return (a < b) ? a : b;}
template <typename T> inline T abs_(T x) { return (x < 0) ? -x : x;}
template <typename T> inline T mcm_(T a,T b){return a*b/__gcd(a,b);}


/*==========================================================================================*/
//Constants
constexpr int dx[]={-1, 0, 1, 0},dy[]={0, 1, 0, -1};
constexpr int inf=INT32_MAX;
constexpr ll INF=INT64_MAX; //0x3f3f3f3f3f3f3f3f;
constexpr int MOD=1000000007;
constexpr int MOD99=998244353;
/*==========================================================================================*/

// ===============SOLUTION======================================

inline void XD();

int main(){
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);
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

