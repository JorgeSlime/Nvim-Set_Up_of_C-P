template<typename T,typename GT>
pair<V<T>,V<int>> Dijkstra(V<V<pair<GT,GT>>>& G,int s){
    auto N=sz(G);
    V<T> dist(N,INF<T>);
    V<int> par(N,-1);
    priority_queue<pair<T,int>,V<pair<T,int>>, greater<pair<T,int>>> q;
    dist[s]=0;
    q.emplace(0,s);
    while(!q.empty()){
        auto[dv,v]=q.top();
        q.pop();
        if(dv>dist[v]) continue;
        for(auto u:G[v]){
            auto [to,cost]=u;
            if(dist[v]+cost<dist[to]){
                dist[to]=dist[v]+cost;
                par[to]=v;
                q.emplace(dist[to],to);
            }
        }      
    }
    return{dist,par};
} 
V<int> camino(vector<int> &p,int t){
    V<int> v={t};
    while (p[v.back()] != -1) v.pb(p[v.back()]);
    reverse(all(v));
    return v;
}
//declaracion:
//auto [dist,par]=Dijkstra<type>(G,1);
//if(dist[n]==INF) -1
//auto ans=camino(p,n);
