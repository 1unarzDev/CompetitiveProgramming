#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int t, e;
    cin >> t;
    for(int i = 0; i < t; i++){
        cin >> e;
        double root = sqrt(e);
        if(root == floor(root)) cout << (int)root / 2 << " " << (int)root - (int)root / 2 << endl;
        else cout << -1 << endl;
    }
    return 0;
}