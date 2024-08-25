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
const ll MAX = 1e9 + 7;


bool check(ll x, ll limit){

    ll sum = 0;
    for(auto y : a){
        sum += min(x, y);
    }
    return sum <= limit;
}

void solve(){
    ll n, limit;
    cin >> n >> limit;
    a.assign(n, 0);
    ll sum = 0;
    for(int i = 0;i < n; i++){
        cin >> a[i];
        sum += a[i];
    }

    if(sum <= limit){
        cout << "infinite" << endl;
        return;
    }

    ll lo = 0;
    ll hi = MAX;
    ll mid = 0;
    while(lo < hi){
        mid = lo + ((hi - lo + 1) >> 1);
        //cout << lo << " " << mid << " " << hi << endl;
        if(check(mid, limit)) lo = mid;
        else hi = mid - 1;
    }
    ll ans = 0;
    if(check(lo, limit)) ans = lo;
    if(check(mid, limit)) ans = mid;
    if(check(hi, limit)) ans = hi;
    cout << ans << endl;
}



int main() {
    solve();
}

