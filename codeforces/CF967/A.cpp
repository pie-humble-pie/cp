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
    unordered_map<ll, ll> mp;
    for(int i = 0;i < n; i++){
        cin >> a[i];
        mp[a[i]]++;
    }
    ll maxc = 0;
    for(auto [k, v] : mp){
        maxc = max(maxc, v);
    }
    cout << n - maxc << endl; 
}



int main() {
    int t;
    cin >> t;
    for(int i = 0;i < t; i++){
        solve();
    }
}

