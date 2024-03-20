template <typename T>
V<int> argsort(const V<T> &A) {
  V<int> ids(sz(A));
  iota(all(ids), 0);
  sort(all(ids),
       [&](int i, int j) { return (A[i] == A[j] ? i < j : A[i] < A[j]); });
  return ids;
}
template <typename T>
V<T> rearrange(const V<T> &A, const V<int> &I) {
  V<T> B(sz(I));
  forn(i, sz(I)) B[i] = A[I[i]];
  return B;
}
//use: 
//auto I=argsort(v);
//v=rearrange(v,I);
