#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int t, n, e, p, s, o;
    bool w;
    cin >> t;
    for(int i = 0; i < t; i++){
        s = 1;
        w = false;
        cin >> n >> p;
        for(int j = 1; j < n; j++){
            cin >> e;
            if(e > p + 1){
                s++;
                w = false;
            }
            else if(w && e > o + 1){
                s++;
                w = false;
            }
            else if(!w){
                w = true;
                o = p;
            }
            p = e;
        }
        cout << s << endl;
    }
    return 0;
}