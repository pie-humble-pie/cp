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
    ll a, b, xk, yk, xq, yq;

    cin >> a >> b >> xk >> yk >> xq >> yq;

    vector<ll> dx = {a, a, -a, -a, b, b, -b, -b};
    vector<ll> dy = {b, -b, b, -b, a, -a, a, -a};
    set<pair<ll,ll>> king, queen;

    for(int i = 0;i < 8; i++){
        king.insert({xk + dx[i], yk + dy[i]});
        queen.insert({xq + dx[i], yq + dy[i]});
    }
    ll ans = 0;
    for(auto p : king){
        if(queen.count(p)) ans++;
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

