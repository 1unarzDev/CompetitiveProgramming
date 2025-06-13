#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int t, n, e, m;
    cin >> t;
    for(int i = 0; i < t; i++){
        cin >> n;
        m = INT32_MIN;
        vector<int> v;
        for(int j = 0; j < n; j++){
            cin >> e;
            if(e > m) m = e;
            v.push_back(e);
        }

        if(m != n){
            cout << "NO" << endl;
            continue;
        }

        vector<int> f(n + 1, 0);
        for(int j = 0; j < n; j++){
            f[v[j]]++;
        }

        vector<int> h(n);
        int c = 0;
        for(int j = n; j >= 1; j--){
            c += f[j];
            h[j - 1] = c;
        }

        bool b = true;
        for(int j = 0; j < n; j++){
            if(h[j] != v[j]){
                b = false;
                break;
            }
        }

        cout << (b ? "YES" : "NO") << endl;
    }
}