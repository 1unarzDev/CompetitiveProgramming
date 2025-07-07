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
constexpr ll MAX_N = 1e5 + 5;

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

// i/o
void setupIO() {
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
istream& operator>>(istream &istream, pair<T1, T2> &p) { return (istream >> p.first >> p.second); }
template <typename T> // cin >> vector<T>
istream& operator>>(istream &istream, vector<T> &v) {
    for(auto &it : v)
        cin >> it;
    return istream;
}

template<typename T1, typename T2> // cout << pair<T1, T2>
ostream& operator<<(ostream &ostream, const pair<T1, T2> &p) { return (ostream << p.F << " " << p.S); }
template<typename T> // cout << vector<T>
ostream& operator<<(ostream &ostream, const vector<T> &c) { for (auto &it : c) cout << it << " "; return ostream; }
template<typename T> // cout << vector<vector<T>>
ostream& operator<<(ostream &ostream, const vector<vector<T>> &c) {
    for (auto &row : c) {
        for (auto &elem : row)
            ostream << elem << " ";
        ostream << endl;
    }
    return ostream;
}

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

int32_t main() {
    fastio;
    setupIO();

    int n, s;
    cin >> n;
    s = (n * n) - (2 * n) + 1; // (n - 1)^2;
    
    // n = 100
    // i = 2
    // j = 6
    // k = 2
    // for all i^j <= n
    // subtract k elements where i^(j*k) < n
    // here since 2^6 = 64 and 6x<=100 x<=16 2/3, subtract 16
 
    // need to account for cases where 2 already covers
    // 4, 8, 16, 32, etc. but 4 also tries to get 16,
    // but you still need to remove larger values that
    // aren't in range of it
    // 2^4x 4x<=100 x=25, subtract 24
    // 4^2x 2x<=100 x=50 subtract 50 I guess subtract the difference

    // 8^2x and 2^6x case, need to account for all fractional roots
    // subtract 49 and 15, 15 will be duplicates

    // to counteract duplicate removals, just iterate 
    // through all powers and add the calculated value

    // numbers composed of non-perfect powers
    // (perfect meaning k^x where k and x are integers)
    // as opposed to something like 2^2 * 3 = 4 * 3 = 12
    // and hence can't be expressed as any k^x, will not
    // have any duplicates
    
    // currently missing all cases for i^2 > n, but
    // pairs of numbers that can be expressed as powers
    // of the same base like 2^2 and 2^3 or 4 and 8
    // or 3^3 and 3^4 or 81 and 243
    // there should be less than (j-1)^2 combinations
    // and duplicates can be counted by possibly just extending
    // the max power you raise the base to
    // n = 14, check 4 and 8, 2^14 max is 8^4, but since
    // you can take the power multiply by 3/2 or j/any 2<x<j
    // to find extra duplicates this is to say for all y * j
    // if y * j = x * z it is a duplicate 2^(y * j) = 2^(x * z)
    // like 8^6 = 4^9, y * j > i

    for(int i = 2; i * i <= n; ++i){
        // max i^j < n
        // solve for j
        // floor(log(i, n)) = floor(log2(n)/log2(i))

        int j = floor(log2(n)/log2(i));
        cout << i << " " << j << " ";
        while (j >= 2) {
            int r = n / j - 1; // subtract 1 for case where you are taking it to the power of 1
            cout << r << " ";
            // if i^j * i^j <= n it should be ignored since it will be handled later
            if(pow(i, 2 * j) > n) s -= r;
            --j;
        }
        cout << endl;
    }
    cout << s << endl;

    // known working o(n^2) overflowing trash solution for small value testing
    unordered_set<int> f;
    for(int i = 2; i <= n; ++i){
        ll x = i;
        for(int j = 2; j <= n; ++j){
            x *= i;
            f.insert(x);
        }
    }
    cout << f.size();

    return 0;
} 