struct SparseTable {
    int n;
    vector<vector<int>> st;
    SparseTable(const vector<int>& arr) {
        n = arr.size();
        int logn = 32 - __builtin_clz(n);
        st.assign(n, vector<int>(logn));
        for (int i = 0; i < n; i++) {
            st[i][0] = arr[i];
        }
        for (int j = 1; (1 << j) <= n; j++) {
            for (int i = 0; i + (1 << j) <= n; i++) {
                st[i][j] = min(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
            }
        }
    }
    int query(int l, int r) {
        int j = 31 - __builtin_clz(r - l + 1);
        return min(st[l][j], st[r - (1 << j) + 1][j]);
    }
};
