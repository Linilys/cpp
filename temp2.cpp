#include <iostream>
#include <vector>
#include <tuple>
#include <string>

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

/* for input */
#define iin(...) auto [__VA_ARGS__]=[](){int __VA_ARGS__;(cin>>...>>__VA_ARGS__);return tuple{__VA_ARGS__};}()
#define lin(...) auto [__VA_ARGS__]=[](){long long __VA_ARGS__;(cin>>...>>__VA_ARGS__);return tuple{__VA_ARGS__};}()
#define din(...) auto [__VA_ARGS__]=[](){double __VA_ARGS__;(cin>>...>>__VA_ARGS__);return tuple{__VA_ARGS__};}()
#define sin(...) auto [__VA_ARGS__]=[](){string __VA_ARGS__;(cin>>...>>__VA_ARGS__);return tuple{__VA_ARGS__};}()
#define chin(...) auto [__VA_ARGS__]=[](){char __VA_ARGS__;(cin >>...>>__VA_ARGS__);return tuple{__VA_ARGS__};}()
/* roop */
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(n) for (int i = 0; i < (n); ++i)
#define rep3(i, a, b) for (int i = a; i <= (b); ++i)
#define rrep(i,n) for(int i = (n)-1; i >= 0; i--)
#define rrep1(n) for(int i = (n)-1; i >= 0; i--)
#define rrep3(i,a,b) for(int i = (b)-1; i >= (a); i--)
/* macro */
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define ssort(v) sort(all(v))
#define lsort(v) sort(all(v), greater<>())
#define pb push_back
#define eb emplace_back
#define len(x) ((int)(x).size())
#define str string

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
inline ll gcd(ll a, ll b) {return (b == 0) ? a : gcd(b, a % b);}
inline ll lcm(ll a, ll b) {return (a / gcd(a, b)) * b;}
// template<class T> auto min(const T& a){ return *min_element(all(a)); }
// template<class T> auto max(const T& a){ return *max_element(all(a)); }

/* for debugs */
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

/****  Library  Here  *******************************************/



/****************************************************************/

int solve() {
    
    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
