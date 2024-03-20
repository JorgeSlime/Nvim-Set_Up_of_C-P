    i32 n,m; cin>>n>>m; 
    V<V<i32>> G(n+1);
    V<bool> vis(n+1);
    V<i32> p(n+1),d(n+1);
    auto BFS=[&](i32 s)->void{
        queue<i32> q;
        q.push(s);
        vis[s]=1;
        p[s]=-1;
        while(!q.empty()){
            i32 v=q.front();
            q.pop();
            for(auto u:G[v]){
                if(!vis[u]){
                    vis[u]=1;
                    d[u]=d[v]+1;
                    p[u]=v;
                    q.push(u);
                }
            }
        }
    };

