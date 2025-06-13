#include <bits/stdc++.h>
using namespace std;

int main() {
    int t, n;

    cin >> t;
    for(int i = 0; i < t; i++){
        cin >> n;
        if(n < 5) cout << -1 << endl;
        else{
            for(int j = 2; j <= n; j += 2){
                if(j != 4){
                    cout << j << " ";
                }
            }
            cout << "4 " << "5 ";
            for(int j = 1; j <= n; j += 2){
                if(j != 5){
                    cout << j << " ";
                }
            }
            cout << endl;
        }
    }
    
    return 0;
}