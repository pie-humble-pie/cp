//https://codeforces.com/problemset/problem/1915/F
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

vector<pair<ll, ll>> arr;
set<pair<ll, ll>> s;
const ll MAX = 1e18;


void solve(){
    ll n;
    cin >> n;
    arr.clear();
    s.clear();

    for(int i = 0;i < n; i++){
        ll a, b;
        cin >> a >> b;
        arr.push_back({a, b});
    }

    sort(arr.begin(), arr.end());
    for(int i = 1;i < n; i++){
        s.insert({arr[i].second, arr[i].first});
    }

    for(int i = 0;i < n; i++){
        auto curr = arr[i];
        ll greets = s.
    }




}



int main() {
    int t;
    cin >> t;
    for(int i = 0;i < t; i++){
        solve();
    }
}
