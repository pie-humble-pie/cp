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
const ll MAX = 1e18;

ll distance2(ll x1, ll y1, ll x2, ll y2){
    return (x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2);
}

ll dot_product(ll x1, ll y1, ll x2, ll y2){
    return x1 * x2 + y1 * y2;
}

bool is_accute(ll x1, ll y1, ll x2, ll y2){
    if((x1 == 0 && y1 == 0) || (x2 == 0 && y2 == 0)) return false;
    return dot_product(x1, y1, x2, y2) >= 0;
}

void solve(){
    ll n;
    cin >> n;
    vector<ll> x(n, 0);
    vector<ll> y(n, 0);

    for(int i = 0;i < n; i++){
        cin >> x[i] >> y[i];
    }

    ll xs, ys, xt, yt;
    cin >> xs >> ys >> xt >> yt;
    ll d = distance2(xs, ys, xt, yt);
    bool ok = true;
    for(int i = 0;i < n; i++){
        ll ds = distance2(x[i], y[i], xs, ys);
        ll dt = distance2(x[i], y[i], xt, yt);
        if(min(ds, dt) > d)
            continue;
        if(ds < dt && is_accute(xs - x[i], ys - y[i], xt - x[i], yt - y[i]))
            continue;
        
        ok = false;
        break;
    }
    if(ok){
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
    }
}



int main() {
    int t;
    cin >> t;
    for(int i = 0;i < t; i++){
        solve();
    }
}

