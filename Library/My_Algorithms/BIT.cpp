template<typename T>
struct BIT{
    vector<T> fenwick;
    int N;
    BIT(){};
    BIT(int _N) {
        N = _N;
        fenwick = vector<T>(N + 1, 0);
    }
    void update(int x, T val) {
        for (; x <= N; x += x & (-x)) fenwick[x] += val;
    }
 
    T query(int x) {
        T res = 0;
        for (; x; x -= x & (-x)) res += fenwick[x];
        return res;
    }
 
    T get(int L, int R) {
        return query(R) - query(L - 1);
    }
};
//USO: 
/*
declaracion:  BIT<int> f(n);
actualizar: f.update(i+1,x);
*/
