template<typename T> 
struct DSU{
  vector<T>p;
  DSU(T n) : p(n, -1) {}
  T findParent(T v) {
    if (p[v] == -1) return v;
    return p[v] = findParent(p[v]);
  }
  bool join(T a,T b) {
    a = findParent(a);
    b = findParent(b);
    if (a == b) return false;
    p[a] = b;
    return true;
  }
};

/* //USO  
DECLARACION: DSU<int> comp(n); su declaracion debe ser de dos char minimo 
*/
