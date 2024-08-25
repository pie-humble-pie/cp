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
    ll n, k;
    cin >> n >> k;
    a.assign(n, 0);
    unordered_map<int, int> mp;
    for(int i = 0;i < n; i++){
        cin >> a[i];
        a[i] %= k;
        mp[a[i]]++;
    }

    ll mn = *min_element(a.begin(), a.end());
    if(mn == 0){
        cout << 0 << endl;
        return;
    }
    ll mx = *max_element(a.begin(), a.end());
    ll ans = MAX;
    if(k == 4){
        if(mp[2] > 1)
            ans = min(ans, 0LL);
        if(mp[2] > 0 && mp[1] > 0)
            ans = min(ans, 1LL);
        if(mp[1] > 1)
            ans = min(ans, 2LL);
    }

    ans = min(ans, k - mx);
    cout << ans << endl;
    return;   
}



int main() {
    int t;
    cin >> t;
    for(int i = 0;i < t; i++){
        solve();
    }
}

