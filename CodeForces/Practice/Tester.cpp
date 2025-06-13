#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <set>

using namespace std;

int main(){
    set<int> primes = {1, 2, 3, 5, 7, 11, 13};
    cout << *prev(primes.end());
    return 0;
}