/// EL ALGOTIRMO KMP TE DEVUELVE LAS POSICIONES INICIALES DONDE APARECE EL PATRON 
/// EJEMPLO.- S=saippuakauppias
///           P=pp
///           -> pp aparece en la pos 3 y 10


template <typename T>
vector<int> kmp_table(int n, const T &s) {
  vector<int> p(n, 0);
  int k = 0;
  for (int i = 1; i < n; i++) {
    while (k > 0 && !(s[i] == s[k])) {
      k = p[k - 1];
    }
    if (s[i] == s[k]) {
      k++;
    }
    p[i] = k;
  }
  return p;
}
 
template <typename T>
vector<int> kmp_table(const T &s) {
  return kmp_table((long long) s.size(), s);
}
template <typename T>
vector<int> kmp_search(int n, const T &s, int m, const T &w, const vector<int> &p) {
  assert(n >= 1 && (int) p.size() == n);
  vector<int> res;
  int k = 0;
  for (int i = 0; i < m; i++) {
    while (k > 0 && (k == n || !(w[i] == s[k]))) {
      k = p[k - 1];
    }
    if (w[i] == s[k]) {
      k++;
    }
    if (k == n) {
      res.push_back(i - n + 1);
    }
  }
  return res;
  // returns 0-indexed positions of occurrences of s in w
}
template <typename T>
vector<int> kmp_search(const T &p, const T &s, const vector<int> &tp) {
  return kmp_search((int) p.size(), p, (int) s.size(), s, tp);
}
 
//EJEMPLO DE USO 
void solve(){
    string s,p; cin>>s>>p; 
    vector<int> v=kmp_table(p); //se crea tabla del patron 
    vector<int> ss=kmp_search(p,s,v); // patron,cadena,tabla del patron.
    cout<<(sz(ss))<<LN;

}



