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

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int t, n;
    cin >> t;
    while(t--){
      cin >> n;
      vi a(n + 1);
      vector<bool> p(n + 1, false);
      for(int i = 1; i <= n; ++i){
        cin >> a[i];
        p[a[i]] = true;
      }
      
      // everything ultimately ends in a cycle, but some have tails (MULTIPLE TAILS ARE POSSIBLE)
      // if we just count the total cycles, we get the max (or nodes with no parents)
      // if we count the number of cycles without tails we get the min - 1 (unless there are no tails)
      // edge case: if a cycle is 2 long, we don't count it
      // floyd's algorithm to count cycles, but we mark nodes to optimize

      vector<bool> m(n + 1, false);
      int open = 0, closed = 0;
      for(int i = 1; i <= n; ++i){
        if(!p[i]){
          vector<bool> p(n + 1, false); // track current checks
          bool f = true; // prevent double detections from multiple tails
          int fast = i, slow = i; 
          do {
            if(m[fast] && !p[fast]) f = false;
            m[fast] = true; 
            p[fast] = true;
            fast = a[fast];

            if(m[fast] && !p[fast]) f = false;
            m[fast] = true; 
            p[fast] = true;
            fast = a[fast];

            slow = a[slow];
          } while (fast != slow);
          if(f) ++open;
        }      
      }
      
      for(int i = 1; i <= n; ++i){
        if(!m[i]){
          int fast = i, slow = i, c = 0;
          do {
            m[fast] = true; 
            fast = a[fast];
            m[fast] = true; 
            fast = a[fast];
            slow = a[slow];
            ++c;
          } while (fast != slow);

          if(c > 2) ++closed;
          else ++open;
        }
      }
      
      // cout << open << " " << closed << " ";
      cout << (open == 0 ? closed : closed + 1) << " " << open + closed << "\n";
    }

    return 0;
} 
