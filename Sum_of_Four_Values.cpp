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
constexpr ll MAXN = 1e5 + 5;

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
#define fastio ios_base::sync_with_stdio(false); cin.tie(0)
#define endl "\n"
#define sz(x) ((ll)(x).size())

// i/o
void setupio() {
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
}

// benchmark
class Timer {
    public:
        Timer() {
            set_resolution<chrono::microseconds>();
        }     

        Timer& nanoseconds() { 
            set_resolution<chrono::nanoseconds>();
            return *this;
        }

        Timer& microseconds() {
            set_resolution<chrono::microseconds>();
            return *this;
        }

        Timer& milliseconds() {
            set_resolution<chrono::milliseconds>();
            return *this;
        }

        Timer& seconds() {
            set_resolution<chrono::seconds>();
            return *this;
        }

        void start() {
            m_StartTp = chrono::high_resolution_clock::now();    
        }
        
        void stop() {
            m_EndTp = chrono::high_resolution_clock::now();
        }

        ll time() const {
            return getTime();
        }

    private:
        chrono::time_point<chrono::high_resolution_clock> m_StartTp, m_EndTp;
        function<ll()> getTime;
    
        template<typename DurationType>
        Timer& set_resolution() {
            getTime = [this]() -> ll {
                auto start = chrono::time_point_cast<DurationType>(m_StartTp).time_since_epoch().count();
                auto end = chrono::time_point_cast<DurationType>(m_EndTp).time_since_epoch().count();
                return end - start;
            };
            return *this;
        }
};

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
istream& operator>>(istream &istream, pair<T1, T2> &p) { return (istream >> p.F >> p.S); }
template <typename T> // cin >> vector<T>
istream& operator>>(istream &istream, vector<T> &v) { for(auto &it : v) istream >> it; return istream; }
template <typename T, size_t N> // cin >> array<T>
istream& operator>>(istream &istream, array<T, N> &v) { for(auto &it : v) istream >> it; return istream; }

template<typename T1, typename T2> // cout << pair<T1, T2>
ostream& operator<<(ostream &ostream, const pair<T1, T2> &p) { return (ostream << p.F << " " << p.S); }
template<typename T> // cout << vector<T>
ostream& operator<<(ostream &ostream, const vector<T> &c) { for (auto &it : c) ostream << it << " "; return ostream; }
template<typename T, size_t N> // cout << array<T>
ostream& operator<<(ostream &ostream, const array<T, N> &c) { for (auto &it : c) ostream << it << " "; return ostream; }

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

vector<char> sieve(ll n) {
    vector<char> is_prime(n + 1, true);
    is_prime[0] = is_prime[1] = false;
    ll t = sqrt(n);
    for (ll i = 2; i <= t; i++) {
        if (is_prime[i]) {
            for (ll j = i * i; j <= n; j += i) {
                is_prime[j] = false;
            }
        }
    }
    return is_prime;
}

vll primes(ll n) {
    vll lp(n + 1);
    vll pr;
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

template <typename T>
vll sort_indices(const vector<T> &v) {
    vll idx(v.size());
    iota(all(idx), 0);
    
    stable_sort(all(idx),
                [&v](ll i1, ll i2) {return v[i1] < v[i2];});
    
    return idx;
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

struct sp {
    int s, a, b;

    // use 1 indexing
    sp(vll &v, int _a, int _b){
        s = v[_a] + v[_b];        
        a = ++_a;
        b = ++_b;
    }
    
    bool operator==(const sp& o){
        return a == o.a || b == o.b || a == o.b || b == o.a;
    }
    
    bool operator!=(const sp& o){
        return !(*this == o);
    }
};
ostream& operator<<(ostream &os, const sp &v) { return (os << v.a << " " << v.b); }

// o(n^2) generate all sum pairs
// o(n^2logn^2) sort all sum pairs
// o(n^2) find two pairs that sum to the goal
int32_t main() {
    fastio;
    setupio();
    
    bool f;
    int n, x, p, b; cin >> n >> x;
    vll a(n); cin >> a;
    vector<sp> s;

    for(int i = 0; i < n; ++i){
        for(int j = i + 1; j < n; ++j){
            s.eb(a, i, j);
        }
    }
    
    sort(all(s), [](sp &a, sp &b){
        return a.s < b.s;
    });

    f = false;
    p = sz(s) - 1;
    for(int i = 0; i < sz(s); ++i){
        b = p;
        while(p > i && s[i].s + s[p].s >= x){
            if(s[i].s + s[p].s == x){
                if(s[i] != s[p]){
                    cout << s[i] << " " << s[p];
                    return 0;
                }
                else f = true;
            }
            --p;
        }
        if(i != sz(s) - 1 && s[i].s == s[i + 1].s && f){
            p = b;
            f = false;
        }
    }
    cout << "IMPOSSIBLE";
    return 0;
} 