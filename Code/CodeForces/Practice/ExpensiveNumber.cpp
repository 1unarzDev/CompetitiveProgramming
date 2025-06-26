#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>

#define ll long long

using namespace std;

int main() {
    vector<int> o;
    int t, r, d;
    ll n;
    cin >> t;
    
    for(int i = 0; i < t; i++){
        cin >> n;
        r = 0;

        while(n % 10 == 0){
            n /= 10;
            r++;
        }
        
        if(n >= 10){
            d = 2;
            while(n % (ll)pow(10, d) == n % 10){
                d++;
            }
            r += floor(log10(n) + 1) - d + 1;
        }

        o.push_back(r);
    }
    
    for(int x : o){
        cout << x << endl;
    }

    return 0;
}