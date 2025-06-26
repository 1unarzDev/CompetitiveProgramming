#include <bits/stdc++.h>
using namespace std;

// Aliases
using ll = long long;
using ld = long double;
using ull = unsigned long long;

// Constants
constexpr ll MOD = 1e9 + 7;
constexpr ld EPS = 1e-9;
constexpr ll INF = 2e18;

// Macros
#define F first
#define S second
#define int long long
#define pb push_back
#define fastio ios_base::sync_with_stdio(false); cin.tie(0)
#define endl "\n"

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
ostream& operator<<(ostream &ostream, const pair<T1, T2> &p) { return (ostream << p.first << " " << p.second); }
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

void solve(){
    int n, e, s, m;
    cin >> n;
    s = m = 0;
    for(int i = 0; i < n; i++){
        cin >> e; 
        s += e;
        if((int)powf(s, 0.5) == powf(s, 0.5) && (int)powf(s, 0.5) % 2 == 1) m++;
    }
    cout << m << endl;
}

int32_t main() {
    fastio;

    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
} 