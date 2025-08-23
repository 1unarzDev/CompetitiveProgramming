#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using pll = pair<ll, ll>;
using vll = vector<ll>;
using mll = map<ll, ll>;
using vi = vector<int>;
using mi = map<int, int>;
using pi = pair<int, int>;
constexpr ll INF = 2e18;
constexpr ll MAXN = 1e5 + 5;
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) ((int)(x).size())

// reconstruct all groups and choose any two roads
// each group to combine them after
int main() {
    ios_base::sync_with_stdio(0) cin.tie(0)

    int n, m, a, b;
    cin >> n >> m;
    mi c;
    mi k;
    int g = 0;
    vi cc;

    for(int i = 0; i < m; ++i){
        cin >> a >> b;

        if(c.find(a) != c.end() && c.find(b) != c.end()){
        }
        else if(c.find(a) != c.end()){
            c[b] = g;
        }
        else if (c.find(b) != c.end()){
            c[a] = g;
        }
        else{
            c[a] = g;
            c[b] = g;
            ++g;
            mi[g] = a;
        }
    }
    
    return 0;
} 