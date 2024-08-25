//https://codeforces.com/problemset/problem/1909/B
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

void solve(){
    ll n;
    cin >> n;
    a.assign(n, 0);
    ll cnt = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        cnt += 1 - (a[i] & 1);
    }

    ll x = 2;
    while(x <= MAX){
        bool ok = true;
        ll rem  = a[0] % x;
        for(int i = 0;i < n; i++){
            ok = ok && ((a[i] % x) == rem);
        }
        if(ok){
            x = x << 1;
        }
        else break;
    }
    cout << x << endl;
}



int main() {
    int t;
    cin >> t;
    for(int i = 0;i < t; i++){
        solve();
    }
}

