struct segtree { 
    int n;
    vector<long long>sum;
    vector<long long> present;
    void init(int nn) {
        sum.clear();
        present.clear();
        n = nn;
        int size = 1;
        while (size < n) {
            size *= 2;
        }
        sum.resize(size * 2);
        present.resize(size * 2);
    }
 
    void update(int i, int sl, int sr, int pos, long long diff) {
        if (sl <= pos && pos <= sr) {
            if (sl == sr) {
                sum[i] = diff;
                present[i] = sum[i] > 0;
            } else {
                int mid = (sl + sr) / 2;
                update(i * 2 + 1, sl, mid, pos, diff);
                update(i * 2 + 2, mid + 1, sr, pos, diff);
                sum[i] = sum[i * 2 + 1] + sum[i * 2 + 2];
                present[i] = present[i * 2 + 1] + present[i * 2 + 2];
            }
        }
    }
 
    void update(int pos, i64 diff) {
        update(0, 0, n - 1, pos, diff);
    }
 
    pair<long,long> query(int i, int sl, int sr, int l, int r) {
        if (l <= sl && sr <= r) {
            return {sum[i], present[i]};
        } else if(sr < l || r < sl) {
            return {0, 0};
        } else {
            int mid = (sl + sr) / 2;
            auto a = query(i * 2 + 1, sl, mid, l, r);
            auto b = query(i * 2 + 2, mid + 1, sr, l, r);
            return {a.F + b.F, a.S + b.S};
        }
    }
 
    long long query(int l, int r) {
        return query(0, 0, n - 1, l, r).F;
    }
};

