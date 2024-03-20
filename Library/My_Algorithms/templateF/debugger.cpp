#define DBG(x) (#x)
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

