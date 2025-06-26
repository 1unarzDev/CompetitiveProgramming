#include <bits/stdc++.h>
using namespace std;

// Aliases
using ll = long long;
using ld = long double;
using ull = unsigned long long;
using pll = pair<ll, ll>;
using vll = vector<ll>;
using vpll = vector<pll>;
using sll = set<ll>;
using mll = map<ll, ll>;

// Constants
constexpr ll MOD = 1e9 + 7;
constexpr ll MOD2 = 998244353;
constexpr ld EPS = 1e-9;
constexpr ll INF = 2e18;
constexpr ll MAX_N = 1e5 + 5;

// Macros
#define F first
#define S second
#define int long long
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define fastio ios_base::sync_with_stdio(false); cin.tie(0)
#define endl "\n"

// I/O
#define LOCAL
void setupIO() {
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
}

// Hacks
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
template <typename T1, typename T2> // Integer key random hash
using safe_map = unordered_map<T1, T2, custom_hash>;
#define unordered_map safe_map

// Operator overloads
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

// Utility functions
vector<bool> sieve(int n) {
    vector<bool> is_prime(n + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= n; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= n; j += i) {
                is_prime[j] = false;
            }
        }
    }
    return is_prime;
}
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }

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

    int f = 0;
    bool w;
    string s;
    set<vll> k, h;
    while(cin >> s){
        w = (s == "#####");
        vll t(5, (w ? 1 : 0));
        for(int i = 0; i < 6; ++i){
            cin >> s;
            for(int j = 0; j < 5; ++j){
                if(s[j] == '#') t[j]++;
            }                
        }
        if(w) k.insert(t);
        else h.insert(t);
    }
    for(auto i : k){
        for(auto j : h){
            w = true;
            for(int k = 0; k < 5; ++k){
                if(i[k] + j[k] > 7) w = false;
            }
            if(w) ++f;
        }
    }
    cout << f;
} 