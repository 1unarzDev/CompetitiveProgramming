#include <bits/stdc++.h>
using namespace std;
using ll = long long;

/* my main logic is find the second smallest/biggest
 * x and y values with some sort of handling if it is
 * the same, then choose the one with the smallest area 
 */
int main(){
    int t, n;
    cin >> t;
    for(int i = 0; i < t; i++){
        cin >> n;
        vector<pair<int, int>> m(n);
        for(int i = 0; i < n; i++) {
            cin >> m[i].first >> m[i].second;
        }
        if(n == 1){
            cout << 1 << endl;
            continue;
        }
        int minc = LLONG_MAX;
        int minx = m[0].first, maxx = monsters[0].first;
        int miny = m[0].second, maxy = monsters[0].second;

        for(int j = 0; j < n; j++){
            minx = min(minx, monsters[i].first);
            maxx = max(minx, monsters[i].first);
            miny = min(minx, monsters[i].second);
            maxy = max(minx, monsters[i].second);
        }        
        
        for(int j = 0; j < n; j++){

        }
    }
    return 0;
}