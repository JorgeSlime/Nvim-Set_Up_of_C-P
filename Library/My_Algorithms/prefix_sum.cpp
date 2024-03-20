template <typename T, typename U>
vector<T> presum(vector<U> &A, bool off = 1) {
  int N = sz(A);
  vector<T> B(N + 1);
  forn(i, N) { B[i + 1] = B[i] + A[i]; }
  if (!off) B.erase(B.begin());
  return B;
}
