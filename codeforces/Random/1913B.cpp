#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
typedef long long int ll;

using namespace std;

vector<ll> a;
const ll MAX = 1e18;
ll lcm(ll x, ll y){
    return (x * y) / gcd(x, y);
}

ll sum(ll x){
    return (x * (x + 1)) >> 1;
}

void solve(){
    ll n, x, y;
    cin >> n >> x >> y;
    int a = n / x;
    int b = n / y;
    int c = n / lcm(x, y);
    a -= c;
    b -= c;
    cout << sum(n) - sum(n - a) - sum(b) << endl;

    return;
}



int main() {
    int t;
    cin >> t;
    for(int i = 0;i < t; i++){
        solve();
    }
}


