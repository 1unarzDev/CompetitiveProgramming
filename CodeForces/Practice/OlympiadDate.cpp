#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <string>

using namespace std;

int main() {
    string s;
    vector<int> o;
    int t, n, w, v;
    char e;
    cin >> t;

    for(int i = 0; i < t; i++){
        s = "01032025";
        w = 0;
        cin >> n;
        
        for(int j = 0; j < n; j++){
            cin >> e;  
            v = s.find(e);
            if(v != -1) s.erase(v, 1);
            if(s.length() == 0 && w == 0) w = j + 1;
        }
        
        o.push_back(w);
    }
    
    for(int x : o){
        cout << x << endl;
    }

    return 0;
}