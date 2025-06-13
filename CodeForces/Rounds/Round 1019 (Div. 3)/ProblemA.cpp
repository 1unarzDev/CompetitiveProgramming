#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ll t, n, e, s;
    set<ll> h;
    cin >> t;
    for(int i = 0; i < t; i++){
        s = 0;
        h.clear();
        cin >> n;
        for(int j = 0; j < n; j++){
            cin >> e;
            if(h.find(e) == h.end()){
                h.insert(e);
                s++;                
            }
        }
        cout << s << endl;
    }
}