i64 n,m; 
V<V<pair<i64,i64>>> G;
V<i64> d,p;
V<bool> vis;
template<typename T>
    void Dijkstra(T s,T t){
        d[s]=0;
        priority_queue<T,V<T>,greater<T>> q;
        q.push({0,s});
        while(!q.empty()){
            T v=q.top().S;
            T d_v=q.top().F;
            q.pop();
            vis[v]=1;
            if(d_v!=d[v]) continue;
            for(auto u:G[v]){
                T to=u.F,len=u.S;
                if(d[v]+len<d[to]){
                    d[to]=d[v]+len;
                    q.push({d[to],to});
                    p[to]=v;
                }
            }
        }
    }

