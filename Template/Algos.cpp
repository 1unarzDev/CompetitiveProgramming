#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <iostream>
#include <string>
#include <cmath>
#include <chrono>

using namespace std;

// aliases
using ll = long long;
using ld = long double;
using ull = unsigned long long;
using pll = pair<ll, ll>;
using vll = vector<ll>;
using vpll = vector<pll>;
using sll = set<ll>;
using mll = map<ll, ll>;

// constants
constexpr ll MOD = 1e9 + 7;
constexpr ll MOD2 = 998244353;
constexpr ld EPS = 1e-9;
constexpr ll INF = 2e18;
constexpr ll MAXN = 1e5 + 5;

// macros
#define F first
#define S second
#define int long long
#define pb push_back
#define ppb pop_back
#define eb emplace_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

float fisqrt(float n) {
    float y = n;
    float x2 = n * 0.5F;
    int32_t i;

    memcpy(&i, &y, sizeof(float));
    i = 0x5f3759df - (i >> 1);
    memcpy(&y, &i, sizeof(float));

    y *= 1.5F - (x2 * y * y);
    y *= 1.5F - (x2 * y * y);

    return y;
}