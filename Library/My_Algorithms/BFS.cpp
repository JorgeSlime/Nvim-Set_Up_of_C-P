int n,m; 
V<V<int>> G;
V<int> d,p;
V<bool> vis;
template<typename T>
    void bfs(T s){
        deque<T> q;
        q.eb(s);
        vis[s]=1;
        p[s]=-1;
        while(!q.empty()){
            T v=q.front();
            q.pop_front();
            for(auto u:G[v]){
                if(!vis[u]){
                    vis[u]=1;
                    d[u]=d[v]+1;
                    p[u]=v;
                    q.eb(u);
                }
            }
        }
    }
/*
    //imprimir el camino mas corto
    int s,f; cin>>s>>f;
    s--,f--;
    bfs(s);
    vi a;
    for(int i=f;i!=-1;i=p[i]) a.push_back(i);
    for(int i=sz(a)-1;~i;--i) cout<<a[i]<<" ";
*/
