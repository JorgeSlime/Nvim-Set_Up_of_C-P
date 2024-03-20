bool *vis;
vector<int> prime{};
void criba(int n) {
    vis = new bool[n+1]();
    vis[0] = vis[1] = 1;
    for(int i = 2; i <= n; i++) {
        if (!vis[i]) prime.emplace_back(i);
        for(int p: prime) {
            if (i*p > n) break;
            vis[i*p] = 1;
            if (i%p == 0) break;
        }
    }
}
