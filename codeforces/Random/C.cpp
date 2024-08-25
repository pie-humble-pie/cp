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
    ll n;
    cin >> n;
    int m = (n * (n - 1)) >> 1;
    a.assign(m, 0);
    for(int i = 0;i < m; i++) cin >> a[i];
    
    sort(a.begin(), a.end());
    int idx = 0;
    vector<ll> ans;
    for(int i = 0;i < n - 1; i++){
        for(int j = i+1;j < n; j++){
            if(j == i+1) ans.push_back(a[idx]);
            idx++;
        }
    }
    ans.push_back(ans.back());

    for(int i = 0;i < n; i++){
        cout << ans[i] << " ";
    }
    cout << endl;
    return;
}



int main() {
    int t;
    cin >> t;
    for(int i = 0;i < t; i++){
        solve();
    }
}

