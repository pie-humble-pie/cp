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


vector<ll> a, b;

bool canEat(ll k, ll x, ll y){
    ll sumA = a[k-1];
    ll sumB = b[k-1];
    return (sumA > x) or (sumB > y);
}


void solve(){
    ll n, x, y;
    cin >> n >> x >> y;
    
    a.assign(n,0);
    b.assign(n,0);

    for(int i = 0;i < n; i++) cin >> a[i];
    for(int i = 0;i < n; i++) cin >> b[i];

    sort(a.begin(), a.end(), greater<ll>());
    sort(b.begin(), b.end(), greater<ll>());
    for(int i = 0;i < n; i++) a[i] = (i > 0) ? a[i-1] + a[i] : a[i];
    for(int i = 0;i < n; i++) b[i] = (i > 0) ? b[i-1] + b[i] : b[i];

    //binary search on ans

    int lo = 1;
    int hi = n;
    int mid = 0;

    while(lo < hi){
        mid = (lo + hi) >> 1; //overflow?
        if(canEat(mid, x, y)){
            hi = mid;
        }
        else{
            lo = mid + 1;
        }
    }
    if(canEat(lo, x, y)){
        cout << lo;
        return;
    }
    if(canEat(mid, x, y)){
    cout << mid;
    return;
    }
    cout << n;
    return;
}

int main() {

    solve();
    return 0;
}

