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

void solve(){
    ll n, p;
    cin >> n >> p;
    a.assign(n, 0);
    b.assign(n, 0);
    for(int i = 0;i < n; i++) cin >> a[i];
    for(int i = 0;i < n; i++) cin >> b[i];
    auto cmp = [&](const pair<ll, ll> &l, const pair<ll,ll> &r) {
        if(l.first == r.first){
            return l.second > r.second;
        }
        return l.first < r.first;
    };
    
    multiset<pair<ll, ll>, decltype(cmp)> s(cmp);

    for(int i = 0;i < n; i++) s.insert({b[i], a[i]});
    s.insert({p, n - 1});
    ll ans = 0;
    ll cnt = 0;
    ans += p;
    cnt = 1;
    for(auto p : s){
        if(cnt == n) break;
        ll cost = p.first;
        ll num = p.second;
        if(cnt + num <= n){
            ans += cost * num;
            cnt += num;
        }
        else{
            num = n - cnt;
            ans += cost * num;
            cnt += num;
        }
        if(cnt == n) break;       
    }

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

