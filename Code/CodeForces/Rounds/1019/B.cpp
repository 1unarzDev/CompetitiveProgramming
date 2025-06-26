#include <bits/stdc++.h>
#define ll long long
using namespace std;

// if the beginning is 1 you can automatically cut it down by 1 if there is a 0
int main(){
    int t, n, k, s;
    string e;
    cin >> t;
    for(int i = 0; i < t; i++){
        cin >> n;
        k = 0;
        s = n;
        cin.ignore();
        getline(cin, e);
        bitset<256> b(e); 
        cout << b.to_string() << endl;
        for(int i = n - 2; i >= 256 - n; i++){

        }
    }
    return 0;
}