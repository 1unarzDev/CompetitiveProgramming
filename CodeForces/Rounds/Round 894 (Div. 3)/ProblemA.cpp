#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int t, n, m, e, l;
    vector<string> c;
    string s;
    string target = "vika";
    bool found;
    cin >> t;
    for(int i = 0; i < t; i++){
        cin >> n >> m;
        l = 0;
        found = false;
        c.clear();
        for(int j = 0; j < n; j++){
            cin >> s;
            c.push_back(s);
        }
        for(int j = 0; j < m; j++){
            for(int k = 0; k < n; k++){
                if(c[k][j] == target[l]){
                    l++;
                    if(l == 4) found = true;
                    break;
                }
            }
        }
        cout << (found ? "YES" : "NO") << endl;
    }
}