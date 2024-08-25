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
vector<pair<ll, ll>> a;


void solve(){
    ll n;
    cin >> n;
    a.clear();
    for(int i = 0;i < n; i++){
        ll x;
        cin >> x;
        a.push_back({x, i});
    }
    sort(a.begin(), a.end(), greater<pair<ll,ll>>());
    cout << a[1].second + 1 << endl;
}



int main() {
    solve();
}

