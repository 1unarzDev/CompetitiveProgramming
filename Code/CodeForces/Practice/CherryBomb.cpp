#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int main()
{
    vector<int> results; 
    int n;
    cin >> n;
    
    for(int i = 0; i < n; i++){
        int m, k, e;
        cin >> m >> k;
        int max = -1;
        int min = k + 1;
        bool has = false;
        bool works = true;
        int comp = -1;
        vector<int> a, b; 

        for(int j = 0; j < m; j++){
            cin >> e;
            a.push_back(e); 
            if(e > max) max = e;
            if(e < min) min = e;
        }

        for(int j = 0; j < m; j++){
            cin >> e;
            b.push_back(e); 
            
            if(e != -1){
                has = true;
                if(comp == -1) comp = a[j] + e;
            }
        }

        if(!has) results.push_back(min + k - max + 1);
        else{          
            for(int j = 0; j < m; j++){
                if(b[j] == -1){
                    if(a[j] + k < comp || a[j] > comp) works = false;
                }
                else{
                    if(a[j] + b[j] != comp) works = false;
                }
                if(!works) break;
            }
            results.push_back(works);
        }
    }
    for(int i = 0; i < n; i++) cout << results[i] << "\n";
    return 0;
}