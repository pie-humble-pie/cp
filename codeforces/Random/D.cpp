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
#include <unordered_set>
typedef long long int ll;

using namespace std;

vector<ll> a, b;
const ll INF = 1e18;

void solve(){
    ll n;
    cin >> n;
    a.assign(n, 0);
    for(int i = 0;i < n; i++) cin >> a[i];
    vector<pair<ll, ll>> s;
    s.push_back({a[0], 0});
    int len = 1;
    for (int i = 1; i < n; i++) {
        if (a[i] >= s.back().first) {
            s.push_back({a[i], i});
            len++;
        } else {
            int ind = lower_bound(s.begin(), s.end(), make_pair(a[i], i)) - s.begin();
            s[ind] = make_pair(a[i], i);
        }
    }
    vector<ll> t;
    unordered_set<ll> uset;
    for(int i = 0;i < len; i++){
        uset.insert(s[i].second);
    }
    ll ans = 0;
    for(int i = 0;i < n; i++){
        if(!uset.count(i)){
            if(t.size() > 0 && a[i] > a[t.back()]) ans++;
            t.push_back(i);
            cout << t.back();
        }
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

