//table:
//decalration -> autp cnt=cnt_table<type>(v,n);
template<typename A ,typename T>
V<A> cnt_table(V<T>&v,int n,bool ok=1){
    V<T> c(ok?n+1:n);
    for(auto &&x:v){
        if(!ok) x--;
        c[x]++;
    }
    return c;
}
//declaration -> auto cnt=cnt_table(s);
template<typename A>
V<A> cnt_table(string&s,int n=26,bool ok=1){
    // 0 mayus 1 minus
    V<A> c(n,0);
    for(auto &&x:s){
        ok ? c[x-'a']++ : c[x-'A']++;
    }
    return c;
}
