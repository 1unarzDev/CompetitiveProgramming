#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

int main()
{
    vector<int> results; 
    int n;
    cin >> n;
    
    for(int i = 0; i < n; i++){
        int n, m, e, k;
        queue<int> a;

        cin >> n >> m;
        k = -1

        for(int j = 0; j < n; j++){
            cin >> e;
            a.push(e)
        }

        for(int j = 0; j < m; j++){
            cin >> e;
            if(a.front() >= e) a.pop();
            else if()
        }
    }

    for(int i = 0; i < n; i++) cout << results[i] << "\n";
    return 0;
}