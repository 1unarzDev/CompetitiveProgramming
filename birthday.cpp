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

struct Tarjan {
    vector<vi> adj;
    vector<bool> visited;
    vi tin, low;
    int timer = 0;

    Tarjan(int n) {
        adj.resize(n);
        visited.assign(n, false);
        tin.assign(n, -1);
        low.assign(n, -1);
    }

    void add_edge(int u, int v) {
        adj[u].pb(v);
        adj[v].pb(u);
    }

    bool dfs(int v, int p = -1) {
        visited[v] = true;
        tin[v] = low[v] = timer++;
        bool ps = false;
        for (int to : adj[v]) {
            if (to == p && !ps){
              ps = true;
              continue;
            }
            if (visited[to]) {
                low[v] = min(low[v], tin[to]);
            } 
            else {
                if(dfs(to, v)) return true;
                low[v] = min(low[v], low[to]);
                if(low[to] > tin[v]) return true;
            }
        }
        return false;
    }
};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
      
    // find any bridges
    int p, c, a, b;
    while(cin >> p >> c){
      if(c == 0 && p == c) return 0;
    
      Tarjan tarjan(p);
      for(int i = 0; i < c; ++i){
        cin >> a >> b;
        tarjan.add_edge(a, b);
      }
      
      bool bridge = false;
      for(int i = 0; i < p; ++i){
        if(!tarjan.visited[i]) bridge = tarjan.dfs(i);
        if(bridge) break;
      }
      cout << (bridge ? "Yes": "No") << "\n";
    }
    
    return 0;
} 