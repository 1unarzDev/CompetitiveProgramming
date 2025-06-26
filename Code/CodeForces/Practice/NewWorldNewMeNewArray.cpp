#include <bits/stdc++.h>
using namespace std;

// the element at any index can be replaced from [-p, p] 
int main(){
    int t;
    cin >> t;
    for(int i = 0; i < t; i++){
        int n, k, p, v;
        cin >> n >> k >> p;
        v = abs(ceil((double)k / p));
        cout << (v < n ? v : -1) << endl;
    }
    return 0;
}