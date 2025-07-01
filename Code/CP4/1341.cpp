#define ANKERL_NANOBENCH_IMPLEMENT
#include "../../Utils/Nanobench.h"
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

// Debug
#define DEBUG
void debug() {
    #ifdef DEBUG
        freopen("/home/liam-bray/CompetitiveProgramming/Code/CP4/input.txt", "r", stdin);
        freopen("/home/liam-bray/CompetitiveProgramming/Code/CP4/output.txt", "w", stdout);
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
int binpower(int base, int e, int mod) {
    int result = 1;
    base %= mod;
    while (e) {
        if (e & 1)
            result = (__int128)result * base % mod;
        base = (__int128)base * base % mod;
        e >>= 1;
    }
    return result;
}

bool check_composite(int n, int a, int d, int s) {
    int x = binpower(a, d, n);
    if (x == 1 || x == n - 1)
        return false;
    for (int r = 1; r < s; r++) {
        x = (__int128)x * x % n;
        if (x == n - 1)
            return false;
    }
    return true;
}

bool miller_rabin(int n) {
    if (n < 2)
        return false;

    int r = 0;
    int d = n - 1;
    while ((d & 1) == 0) {
        d >>= 1;
        r++;
    }
 
    // deterministic for long long max val
    for (int a : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}) {
        if (n == a)
            return true;
        if (check_composite(n, a, d, r))
            return false;
    }
    return true;
}

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

void p2(int n){
    ld r = pow(10.0, n);
    cout << fixed << setprecision(n) << (ceil(acos(-1.0) * r) / r) << endl;
}

void p3(){
    map<int, string> d = {{0, "Sunday"}, 
                         {1, "Monday"},
                         {2, "Tuesday"},
                         {3, "Wednesday"},
                         {4, "Thursday"},
                         {5, "Friday"},
                         {6, "Saturday"}};

    vector<int32_t> in(6);
    cin >> in;

    tm time_in = { in[0], in[1], in[2], // second, minute, hour
        in[3], --in[4], in[5] - 1900 }; // 1-based day, 0-based month, year since 1900
    
    time_t time_temp = mktime(&time_in);
    
    const tm * time_out = localtime(&time_temp);
    
    cout << "Today is " << d[time_out->tm_wday] << "\n";
}

void p4(){
    sll s;
    int n;
    string in;
    cin.ignore();
    getline(cin, in);
    istringstream iss(in);
    while(iss >> n) s.insert(n);
    for(auto& i : s) cout << i << " ";
    cout << endl;
}

struct bday {
    int d;
    int m;
    int y;
};
void p5(int n){
    vector<bday> b(n);
    for(int i = 0; i < n; ++i){
        cin >> b[i].d >> b[i].m >> b[i].y;        
    }

    sort(all(b), [](const bday &a, const bday &b){
        if (a.y != b.y) return a.y < b.y;
        if (a.m != b.m) return a.m < b.m;
        return a.d < b.d;
    });

    for(const auto &i : b) cout << i.d << " " << i.m << " " << i.y << endl; 
}

void p6(int n, int f){
    vll v(n);
    cin >> v;
    auto itr = lower_bound(all(v), f);
    int i = distance(v.begin(), itr);
    if(i == n) i = -1;
    cout << i << endl;
}

void p11(){
    int n;
    for(int i = 0; i < 85; i++){
        cin >> n;
        cout << (miller_rabin(n) ? "YES" : "NO") << endl;
    }
}

int32_t main() {
    fastio;
    setupIO();

    p2(6);
    p3();
    p4();
    p5(8);
    p6(1e4, 74399);
    p11();

    return 0;
} 