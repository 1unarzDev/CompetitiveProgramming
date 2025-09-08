#include <bits/stdc++.h>
using namespace std;

// aliases
using ll = long long;
using ld = long double;
using ull = unsigned long long;
using pll = pair<ll, ll>;
using vll = vector<ll>;
using vpll = vector<pll>;
using sll = set<ll>;
using mll = map<ll, ll>;

// constants
constexpr ll MOD = 1e9 + 7;
constexpr ll MOD2 = 998244353;
constexpr ld EPS = 1e-9;
constexpr ll INF = 2e18;
constexpr ll MAXN = 1e7;

// macros
#define F first
#define S second
#define int long long
#define pb push_back
#define ppb pop_back
#define eb emplace_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define endl "\n"
#define sz(x) ((ll)(x).size())
#define fastio ios_base::sync_with_stdio(false); cin.tie(0)
#define setupio(r, w) freopen(r, "r", stdin); freopen(w, "w", stdout);

// hacks
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15; // prime closest to integral part of (sqrt(5)-1)/2 multiplied by 2^32
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
template <typename T1, typename T2> // integer key random hash
using safe_map = unordered_map<T1, T2, custom_hash>;
#define unordered_map safe_map

// operator overloads
template <typename T1, typename T2> // cin >> pair<T1, T2>
istream& operator>>(istream &is, pair<T1, T2> &p) { return (is >> p.F >> p.S); }
template <typename T> // cin >> vector<T>
istream& operator>>(istream &is, vector<T> &v) { for(auto &it : v) is >> it; return is; }
template <typename T, size_t N> // cin >> array<T>
istream& operator>>(istream &is, array<T, N> &a) { for(auto &it : a) is >> it; return is; }

template<typename T1, typename T2> // cout << pair<T1, T2>
ostream& operator<<(ostream &os, const pair<T1, T2> &p) { return (os << p.F << " " << p.S); }
template<typename T> // cout << vector<T>
ostream& operator<<(ostream &os, const vector<T> &v) { for (auto &it : v) os << it << " "; return os; }
template<typename T, size_t N> // cout << array<T>
ostream& operator<<(ostream &os, const array<T, N> &a) { for (auto &it : a) os << it << " "; return os; }

// utility functions
ll binpower(ll base, ll e, ll mod) {
    ll result = 1;
    base %= mod;
    while (e) {
        if (e & 1)
            result = (__int128)result * base % mod;
        base = (__int128)base * base % mod;
        e >>= 1;
    }
    return result;
}

bool check_composite(ll n, ll a, ll d, ll s) {
    ll x = binpower(a, d, n);
    if (x == 1 || x == n - 1)
        return false;
    for (ll r = 1; r < s; r++) {
        x = (__int128)x * x % n;
        if (x == n - 1)
            return false;
    }
    return true;
}

bool miller_rabin(ll n) {
    if (n < 2)
        return false;

    ll r = 0;
    ll d = n - 1;
    while ((d & 1) == 0) {
        d >>= 1;
        r++;
    }
 
    // deterministic for long long max val
    for (ll a : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}) {
        if (n == a)
            return true;
        if (check_composite(n, a, d, r))
            return false;
    }
    return true;
}

vll sieve(ll n) {
    vector<char> is_prime(n + 1, true);
    vll primes;
    is_prime[0] = is_prime[1] = false;
    ll t = sqrt(n);
    for (ll i = 2; i <= n; ++i) {
        if (is_prime[i]) {
            primes.pb(i);
            for (ll j = i * i; j <= n; j += i) {
                is_prime[j] = false;
            }
        }
    }
    return primes;
}

vll primes(ll n) {
    vll lp(n + 1);
    vll pr;
    pr.reserve(n / log(n));
    for (ll i = 2; i <= n; ++i){
        if(lp[i] == 0){
            lp[i] = i;
            pr.pb(i);
        }
        for(ll j = 0; i * pr[j] <= n; ++j){
            lp[i * pr[j]] = pr[j];
            if (pr[j] == lp[i]){
                break;
            }
        }
    }
    return pr;
}

ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }
ll gcd(const vll &v) {
    return accumulate(all(v), v[0], [](ll a, ll b) {
        return gcd(a, b);
    });
}
ll lcm(const vll &v) {
    return accumulate(all(v), 1LL, [](ll a, ll b) {
        return lcm(a, b);
    });
}

template <typename Map>
auto min_key(const Map& mp) -> decltype(mp.begin()->F) {
    return std::min_element(mp.begin(), mp.end(),
        [](const auto& a, const auto& b) {
            return a.S < b.S;
        })->F;
}

template <typename Map>
auto max_key(const Map& mp) -> decltype(mp.begin()->first) {
    return std::max_element(mp.begin(), mp.end(),
        [](const auto& a, const auto& b) {
            return a.second < b.second;
        })->F;
}

template <typename T>
vll sort_indices(const vector<T> &v) {
    vll idx(v.size());
    iota(all(idx), 0);
    
    stable_sort(all(idx),
                [&v](ll i1, ll i2) {return v[i1] < v[i2];});
    
    return idx;
}

int32_t main() {
    fastio;
 
    ll tt, c, m;
    cin >> tt;
    vll n(tt);
    cin >> n;
    m = 0;
    for(int i = 0; i < tt; ++i) m = max(m, n[i]);
    vll pr = sieve(m);
 
    for(int i = 0; i < tt; ++i){
        c = 0;
        for(int j = 0; j < pr.size() && pr[j] <= n[i]; ++j){
            c += n[i] / pr[j];
        }
        cout << c << endl;
    }
 
    return 0;
} 