#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>

using namespace std;

int main() {
    vector<bool> o;
    int t, e;
    cin >> t;

    for(int i = 0; i < t; i++){
        cin >> e;
        o.push_back(e % 2 != 0);
    }
    
    for(int i = 0; i < t; i++){
        cout << (o[i] ? "YES" : "NO") << endl;
    }

    return 0;
}