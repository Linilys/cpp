#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <algorithm>
#include <functional>
#include <cmath>
#include <numeric>
#include <limits>
#include <iterator>
#include <cassert>
#include <stack>
#include <queue>
#include <deque>
#include <random>
#include <sstream>
#include <chrono>
#include <bitset>
#include <complex>
#include <stdexcept>
#include <set>
#include <map>
#include <regex>    // 正規表現

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
using umii = unordered_map<int, int>;
using usi = unordered_set<int>;

/* for input */
#define iin(...) auto [__VA_ARGS__]=[](){int __VA_ARGS__;(cin>>...>>__VA_ARGS__);return tuple{__VA_ARGS__};}()
#define lin(...) auto [__VA_ARGS__]=[](){long long __VA_ARGS__;(cin>>...>>__VA_ARGS__);return tuple{__VA_ARGS__};}()
#define din(...) auto [__VA_ARGS__]=[](){double __VA_ARGS__;(cin>>...>>__VA_ARGS__);return tuple{__VA_ARGS__};}()
#define sin(...) auto [__VA_ARGS__]=[](){string __VA_ARGS__;(cin>>...>>__VA_ARGS__);return tuple{__VA_ARGS__};}()
#define chin(...) auto [__VA_ARGS__]=[](){char __VA_ARGS__;(cin >>...>>__VA_ARGS__);return tuple{__VA_ARGS__};}()
#define lary(a, x) vector<long long> a(x); for (int i = 0; i < (x); ++i) cin >> a[i];
#define iary(a, x) vector<int> a(x); for (int i = 0; i < (x); ++i) cin >> a[i];
#define sary(a, x) vector<string> a(x); for (int i = 0; i < (x); ++i) cin >> a[i];
#define l2ary(a, r, c) vector<vector<long long>> a(r, vector<long long>(c)); \
                         for (int i = 0; i < (r); ++i) for (int j = 0; j < (c); ++j) cin >> a[i][j];
#define i2ary(a, r, c) vector<vector<int>> a(r, vector<int>(c)); \
                         for (int i = 0; i < (r); ++i) for (int j = 0; j < (c); ++j) cin >> a[i][j];
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
#define cp(a) cout << (a) << endl
#define yes(cond) cout << ((cond) ? "Yes" : "No") << endl
#define YES cout << "YES\n"
#define NO cout << "NO\n"
#define Yes cout << "Yes\n"
#define No cout << "No\n"

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

// template<class T> auto min(const T& a){ return *min_element(all(a)); }
// template<class T> auto max(const T& a){ return *max_element(all(a)); }

/* Math */
inline ll gcd(ll a, ll b) {return (b == 0) ? a : gcd(b, a % b);}
inline ll lcm(ll a, ll b) {return (a / gcd(a, b)) * b;}

ll mod_pow(ll base, ll exp, ll mod) {
    base = (base % mod + mod) % mod;
    ll result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) result = result * base % mod;
        base = base * base % mod;
        exp /= 2;
    }
    return result;
}

bool is_prime(int n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }
    return true;
}

vector<pair<int, int>> prime_factorize(int n) {
    vector<pair<int, int>> factors;
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            int count = 0;
            while (n % i == 0) {
                n /= i;
                ++count;
            }
            factors.emplace_back(i, count);
        }
    }
    if (n > 1) factors.emplace_back(n, 1);
    return factors;
}

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
