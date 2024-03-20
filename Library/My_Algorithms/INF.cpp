using ll= long long;
using ull=unsigned long long;
template <class T> constexpr T INF = 0;
template <> constexpr int INF<int> = 1'000'000'000;
template <> constexpr ll INF<ll> = ll(INF<int>) * INF<int> * 2;
template <> constexpr ull INF<ull> = INF<ll>;
template <> constexpr double INF<double> = INF<ll>;
template <> constexpr long double INF<long double> = INF<ll>;
