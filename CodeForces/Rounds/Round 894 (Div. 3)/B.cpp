#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int t, n, e, m, p;
    vector<int> s;
    cin >> t;
    for(int i = 0; i < t; i++){
        cin >> n >> p;
        m = n;
        s.clear();
        s.push_back(p);
        for(int j = 1; j < n; j++){
            cin >> e;
            if(p > e) m++;
            s.push_back(e);
            p = e;
        }
        cout << m << endl << s[0] << " ";
        for(int j = 1; j < n; j++){
            if(s[j] < s[j - 1]) cout << s[j] << " ";
            cout << s[j] << " ";
        }
        cout << endl;
    }
}