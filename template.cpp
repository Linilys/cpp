// #pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
// #include <atcoder/all>
//#include <boost/multiprecision/cpp_int.hpp>
// using namespace atcoder;
// using mint=atcoder::modint998244353;
using namespace std;
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using vs = vector<string>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vvi = vector<vi>;
using vvl = vector<vl>;
using vpii = vector<pii>;
using vpll = vector<pll>;
using ui = uint64_t;

#define _CRT_SECURE_NO_WARNINGS

#define rep1(n) for (int i = 0; i < (n); ++i)
#define rep2(i, n) for (int i = 0; i < (n); ++i)
#define rep3(i, a, b) for (int i = a; i <= (b); ++i)
#define rrep1(n) for(int i=(n)-1;i>=0;i--)
#define rrep2(i,n) for(int i=(n)-1;i>=0;i--)
#define rrep3(i,a,b) for(int i=(b)-1;i>=(a);i--)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define ssort(v) sort(all(v))
#define lsort(v) reverse(all(v))
#define pb push_back
#define eb emplace_back
#define len(x) ll(x.size())
#define elif else if
#define jt bool judge = true
#define jf bool judge = false

#define l1(var) ll var; cin >> var
#define l2(a,b) ll a,b; cin >> a >> b
#define l3(a,b,c) ll a,b,c; cin >> a >> b >> c
#define l4(a,b,c,d) ll a,b,c,d; cin >> a >> b >> c >> d
#define l5(a,b,c,d,e) ll a,b,c,d,e; cin >> a >> b >> c >> d >> e
#define s1(var) string var; cin >> var
#define s2(a,b) string a,b; cin >> a >> b
#define s3(a,b,c) string a,b,c; cin >> a >> b >> c
#define s4(a,b,c,d) string a,b,c,d; cin >> a >> b >> c >> d
#define s5(a,b,c,d,e) string a,b,c,d,e; cin >> a >> b >> c >> d >> e
#define cp(a) cout << (a) << endl
#define yes(cond) cout << ((cond) ? "Yes" : "No") << endl
#define lary(arr,n) vl arr(n); for (int i=0;i<n;++i) cin>>arr[i]
#define iary(arr,n) vi arr(n); for (int i=0;i<n;++i) cin>>arr[i]
#define sary(arr,n) vs arr(n); for (int i=0;i<n;++i) cin>>arr[i]

const int dx4[4] = {1, 0, -1, 0};
const int dy4[4] = {0, 1, 0, -1};
const int dx8[8] = {1, 1, 0, -1, -1, -1, 0, 1};
const int dy8[8] = {0, 1, 1, 1, 0, -1, -1, -1};
vector<int> di{1, 0, -1, 0};
vector<int> dj{0, 1, 0, -1};

const int INF = 1e9 + 5;
const ll LINF = 1LL << 60;
const double EPS = 1e-9;
const int MOD = 1e9 + 7;

template<class T> bool chmax(T &a, const T &b){if(a < b){a = b; return 1; } return 0;}
template<class T> bool chmin(T &a, const T &b){if(a > b){a = b; return 1; } return 0;}
template<class T> auto min(const T& a){ return *min_element(all(a)); }
template<class T> auto max(const T& a){ return *max_element(all(a)); }
inline ll gcd(ll a, ll b) {return (b == 0) ? a : gcd(b, a % b);}
inline ll lcm(ll a, ll b) {return (a / gcd(a, b)) * b;}

vector<ll> fact(1, 1), inv_fact(1, 1);
void init_comb(int n, ll mod = MOD) {
    fact.resize(n + 1);
    inv_fact.resize(n + 1);
    for (int i=1;i<=n;++i) fact[i] = fact[i - 1] * i % mod;
    inv_fact[n] = mod_inv(fact[n], mod);
    for (int i = n - 1; i >= 0; --i) inv_fact[i] = inv_fact[i+1] *(i+1)%mod;
}

ll comb(int n,int k,ll mod=MOD){if(n<k||k<0)return 0; return fact[n]*inv_fact[k]%mod*inv_fact[n-k]%mod;}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
inline int rand_int(int l, int r) {return uniform_int_distribution<int>(l, r)(rng);}

#ifdef LOCAL
#define debug(x) cerr << #x << ": " << (x) << endl
#else
#define debug(x)
#endif

#ifdef LOCAL
template<typename T> void debug_vector(const vector<T>& v) {
    cerr << "[ ";
    for (const auto& x : v) cerr << x << " ";
    cerr << "]" << endl;
}
template<typename T, typename U> void debug_map(const map<T, U>& m) {
    cerr << "{ ";
    for (const auto& [key, val] : m) cerr << key << ": " << val << ", ";
    cerr << "}" << endl;
}
#define debug2d(v) for (const auto& row : (v)) debug_vector(row)
#endif

/****  Library  *******************************************/



/***********************************************************/

int solve() {
  
  return 0;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();
  return 0;
}

