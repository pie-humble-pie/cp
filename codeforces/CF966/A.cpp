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
    ll n, m, k;
    cin >> n >> m >> k;
    ll w;
    cin >> w;
    vector<ll> s;
    for(ll i = 1;i <= n; i++){
        for(ll j = 1;j <= m; j++){
            ll x = min(k, min(n + 1 - k, min(i, n + 1 - i)));
            ll y = min(k, min(m + 1 - k, min(j, m + 1 - j)));
            s.push_back(x * y);
        }
    }
    ll ans = 0;
    a.assign(w, 0);
    for(ll i = 0;i < w; i++) cin >> a[i];
    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());
    sort(s.begin(), s.end());
    reverse(s.begin(), s.end());

    for(int cnt = 0;cnt < w; cnt++){
        //cout << s[cnt] << " " << a[cnt] << endl;
        ll times = s[cnt];
        ans += a[cnt] * times;
    }

    cout << ans << endl;

}



int main() {
    int t;
    cin >> t;
    for(int i = 0;i < t; i++){
        solve();
    }
}

