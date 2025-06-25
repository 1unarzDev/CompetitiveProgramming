#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int t, n, k, z, o, m;
    string s;
    cin >> t;
    for(int i = 0; i < t; i++){
        cin >> n >> k >> s;
        z = count(s.begin(), s.end(), '0');
        o = n - z;
        m = z / 2 + o / 2;
        cout << (k <= z / 2 + o / 2 && k >= (max(z, o) - n / 2) && (k - (max(z, o) - n / 2)) % 2 == 0 ? "YES" : "NO") << endl;
    }
    return 0;
}