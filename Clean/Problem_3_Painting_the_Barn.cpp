// #define USACO
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
constexpr ll DIRA[9] = {-1, 1, -1, 0, 1, 1, 0, -1, -1};
constexpr ll DIRC[5] = {0, 1, 0, -1, 0};

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
void setupio() {
    #ifdef USACO
        freopen("paintbarn.in", "r", stdin);
        freopen("paintbarn.out", "w", stdout);
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

struct box {
    ll x1, y1, x2, y2;        
    
    box() : x1(0), y1(0), x2(0), y2(0) {}
    box(ll x1, ll y1, ll x2, ll y2) : x1(x1), y1(y1), x2(x2), y2(y2) {}
};
istream& operator>>(istream &istream, box &b) { return (istream >> b.x1 >> b.y1 >> b.x2 >> b.y2); }

class ps2 {
    public:
        ps2(const vector<vll>& a) {
            ll r = a.size(), c = a[0].size();
            p = vector<vll>(r, vll(c, 0));

            p[0][0] = a[0][0]; 
            for(ll i = 1; i < c; ++i) p[0][i] = p[0][i - 1] + a[0][i];
            for(ll i = 1; i < r; ++i) p[i][0] = p[i - 1][0] + a[i][0];
    
            for (ll i = 1; i < r; ++i) {
                for (ll j = 1; j < c; ++j) {
                    p[i][j] = p[i - 1][j] + p[i][j - 1] - p[i - 1][j - 1] + a[i][j];
                }
            }
        }

        ll sum(ll y1, ll x1, ll y2, ll x2) {
            ll r = p[y2][x2];
            if (y1 > 0) r -= p[y1 - 1][x2];
            if (x1 > 0) r -= p[y2][x1 - 1];
            if (y1 > 0 && x1 > 0) r += p[y1 - 1][x1 - 1];
            return r;
        }
        
    const vector<vll>& get() const {
        return p;
    }
    
    private:
        vector<vll> p;
};

class dps2 {
    public:
        dps2(ll rows, ll cols) {
            p = vector<vll>(rows, vll(cols, 0));
        }
    
        void add(ll x1, ll y1, ll x2, ll y2, ll v) {
            p[y1][x1] += v;
            if (y2 + 1 < p.size()) p[y2 + 1][x1] -= v;
            if (x2 + 1 < p[0].size()) p[y1][x2 + 1] -= v;
            if (y2 + 1 < p.size() && x2 + 1 < p[0].size()) 
                p[y2 + 1][x2 + 1] += v;
        }
    
        vector<vll> revert() {
            return ps2(p).get();
        }
    
    private:
        vector<vll> p;
};

int32_t main() {
    fastio;
    setupio();
    
    // get number of painted rectangles and desired coats
    int n, k; cin >> n >> k;

    // set appropriate size with buffer
    int mx, my, md;
    md = 201;
    vector<box> p(n); cin >> p;
    if(k == 1) mx = my = md; 
    else{
        mx = my = 0; 
        for(box& b : p) {
            if(b.x2 > mx) mx = b.x2;       
            if(b.y2 > my) my = b.y2; 
        }
        mx += 2;
        my += 2;
        mx = min(md, mx);
        my = min(md, my);
    }

    // 2d diff arr for paint coats
    dps2 f = dps2(my, mx);
    for(box& b : p) f.add(b.x1, b.y1, b.x2, b.y2, 1);
    vector<vll> w = f.revert();
    
    // convert to cost array of painting values
    for(int i = 0; i < my; ++i){
        for(int j = 0; j < mx; ++j){
            if(w[i][j] == k) w[i][j] = -1;
            else if(w[i][j] == k - 1) w[i][j] = 1;
            else w[i][j] = 0;
        }
    }

    // check if it is a valid index and value
    auto v1 = [&](int y, int x) {
        return y >= 0 && y < my && x >= 0 && x < mx && (w[y][x] == 1 || w[y][x] == -1);
    };

    // filter out strips with dimensions =1
    bool u, d, l, r, ul, ur, dl, dr;
    for (int i = 0; i < my; ++i) {
        for (int j = 0; j < mx; ++j) {
            u = v1(i - 1, j);
            ul = v1(i - 1, j - 1);
            ur = v1(i - 1, j + 1);
            d = v1(i + 1, j);
            dl = v1(i + 1, j - 1);
            dr = v1(i + 1, j + 1);
            l = v1(i, j - 1);
            r = v1(i, j + 1);
            
            if(!((u && ul && l) || (u && ur && r) || (d && dl && l) || (d && dr && r))) w[i][j] = 0;
        }
    }
    
    vector<vll> prc(mx, vll(my + 1, 0));
    for(int i = 0; i < mx; ++i){
        for(int j = 0; j < my; ++j){
            prc[i][j + 1] = prc[i][j] + w[j][i];
        }
    }

    // disjoint max submatrix by splitting along a vertical or horizontal line
    // iterate through all pairs of rows and calculate max positive difference between prefix sums
    int mxs, mns, mv, mh, si, ei, tsi, mr;
    vll pr(mx);
    vector<pair<int, box>> mfs(mx - 3), mbs(mx - 3), ws(my - 3);
    vector<pair<pair<int, box>, pair<int, box>>> mhs, mvs;
    for(int i1 = 0; i1 < my - 1; ++i1){
        for(int i2 = i1 + 1; i2 < my; ++i2){

            pr[0] = prc[0][i2] - prc[0][i1];
            for(int j = 1; j < mx; ++j){
                pr[j] = pr[j - 1] + prc[j][i2] - prc[j][i1];
            }
            
            // calculate optimal horizontal splits
            // by finding maximum submatrix for all pairs of rows
            // and checking all maxium pairs on either side of the split
            mxs = max(pr[1], 0LL);
            mns = pr[0];
            si = 0;
            ei = 1;
            mfs[0] = mp(mxs, box(si, i1, ei, i2));
            for(int j = 2; j < mx - 2; ++j){
                if(pr[j] - mns > mxs){
                    mxs = pr[j] - mns;
                    ei = j; 
                    si = tsi;
                }
                if(pr[j] < mns){
                    mns = pr[j];
                    tsi = j;
                }
                mfs[j - 1] = mp(mxs, box(si, i1, ei, i2));
            }

            mxs = max(pr[mx - 2], 0LL);
            mns = pr[mx - 1];
            si = mx - 1;
            ei = mx - 2;
            mbs[mx - 1] = mp(mxs, box(si, i1, ei, i2));
            for(int j = mx - 3; j >= 2; --j){
                if(pr[j] - mns > mxs){
                    mxs = pr[j] - mns;
                    ei = j; 
                    si = tsi;
                }
                if(pr[j] < mns){
                    mns = pr[j];
                    tsi = j;
                }
                mbs[j + 1] = mp(mxs, box(si, i1, ei, i2));
            }
            
            // iterate through max submatrices for all splits
            mr = 0;
            for(int j = 1; j < mx - 3; ++j){
                if(mfs[j].F + mbs[j].F > mfs[mr].F + mbs[mr].F){
                    mr = j;
                }
            }
            mhs.pb(mp(mfs[mr], mbs[mr]));
        }
    }

    // find optimal regions from vertical and horizontal splits
    int mmhs, mmvs;
    mmhs = mmvs = 0;
    for(int i = 0; i < mhs.size(); ++i){
        if(mhs[i].F.F + mhs[i].S.F > mhs[mmhs].F.F + mhs[mmhs].S.F){
            mmhs = i;
        }
    }
    for(int i = 0; i < mvs.size(); ++i){
        if(mvs[i].F.F + mvs[i].S.F > mvs[mmvs].F.F + mvs[mmvs].S.F){
            mmvs = i;
        }
    }

    // set optimal regions
    box pbb1, pbb2;
    if(mvs[mmvs].F.F + mvs[mmvs].S.F >= mhs[mmhs].F.F + mhs[mmhs].S.F){
        pbb1 = mvs[mmvs].F.S;
        pbb2 = mvs[mmvs].S.S;
    }
    else{
        pbb1 = mhs[mmhs].F.S;
        pbb2 = mhs[mmhs].S.S;
    }

    // paint over optimal regions
    for(int i = pbb1.x1; i <= pbb1.x2; ++i){
        for(int j = pbb1.y1; j <= pbb1.y2; ++j){
            w[i][j] = 1;
        }
    }

    for(int i = pbb2.x1; i <= pbb2.x2; ++i){
        for(int j = pbb2.y1; j <= pbb2.y2; ++j){
            w[i][j] = 1;
        }
    }

    // not necessary, but nice for visualization of painted squares
    for(int i = 0; i < my; ++i){
        for(int j = 0; j < mx; ++j){
            if(w[i][j] == -1) w[i][j] = 1;
            else w[i][j] = 0;
        }
    }
    
    // check if valid index and painted
    auto v2 = [&](int y, int x) {
        return y >= 0 && y < my && x >= 0 && x < mx && w[y][x] == 1;
    };
    
    // sum valid regions
    int s = 0;
    for (int i = 0; i < my; ++i) {
        for (int j = 0; j < mx; ++j) {
            u = v2(i - 1, j);
            ul = v2(i - 1, j - 1);
            ur = v2(i - 1, j + 1);
            d = v2(i + 1, j);
            dl = v2(i + 1, j - 1);
            dr = v2(i + 1, j + 1);
            l = v2(i, j - 1);
            r = v2(i, j + 1);
            
            if(!((u && ul && l) || (u && ur && r) || (d && dl && l) || (d && dr && r))) w[i][j] = 0;
            
            s += w[i][j];
        }
    }

    cout << w << endl;
    cout << s;

    return 0;
} 