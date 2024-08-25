//https://codeforces.com/problemset/problem/1931/D
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
map<pair<ll, ll>, ll> cnt;
const ll MAX = 1e18;

void solve(){
    ll n, x, y;
    cin >> n >> x >> y;
    a.assign(n, 0);
    for(int i = 0;i < n; i++) cin >> a[i];
    cnt.clear();
    
    for(int i = 1;i < n; i++){
        int val1 = a[i] % y;
        int val2 = (((-1 * a[i]) % x) + x) % x;
        cnt[{val1, val2}]++;
    }

    ll ans = 0;

    for(int i = 0;i < n; i++){
        int en1 = a[i] % y;
        int en2 = (((-1 * a[i]) % x) + x) % x;
        int st1 = a[i] % y;
        int st2 = a[i] % x;
        if(i > 0){
            cnt[{en1, en2}]--;
            if(cnt.at({en1, en2}) == 0) cnt.erase({en1, en2});
        }
        ans += (cnt.count({st1, st2})) ? cnt.at({st1, st2}) : 0;
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

