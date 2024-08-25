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

vector<ll> a;
vector<string> b;
const ll MAX = 1e18;

void solve(){
    ll n, m;
    cin >> n;
    a.assign(n, 0);
    for(int i = 0;i < n; i++) cin >> a[i];
    cin >> m;
    b.assign(m, "");
    for(int i = 0;i < m; i++) cin >> b[i];

    unordered_set<ll> ua(a.begin(), a.end());

    for(int i = 0;i < m; i++){
        if(n != b[i].size()){
            cout << "NO" << endl;
            continue;
        }
        unordered_set<ll> ub(b[i].begin(), b[i].end());
        set<pair<ll, char>> s;
        for(int j = 0;j < n; j++){
            s.insert({a[j], b[i][j]});
        }
        if(ua.size() == ub.size() && s.size() == ua.size()){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }
    return;
}



int main() {
    int t;
    cin >> t;
    for(int i = 0;i < t; i++){
        solve();
    }
}

