#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <set>

using namespace std;

bool isPrime(int n) {
    if(n <= 1) return false;
    if(n <= 3) return true;

    if(n % 2 == 0 || n % 3 == 0) return false;

    for(int i = 5; i * i <= n; i += 6)
        if(n % i == 0 || n % (i + 2) == 0) return false;

    return true;
}

int main(){
    vector<bool> solutions;
    int n, m, e;

    cin >> n;
        
    for(int i = 0; i < n; i++){
        cin >> e >> m;

        if(m > 1 && e > 1) solutions.push_back(false);
        else if(e == 1){
            for(int j = 1; j < m; j++){
                e += pow(10, j);
            }
            solutions.push_back(isPrime(e));
        }
        else solutions.push_back(isPrime(e));
    }

    for(int i = 0; i < n; i++){
        cout << (solutions[i] ? "YES" : "NO") << endl;    
    }

    return 0;
}