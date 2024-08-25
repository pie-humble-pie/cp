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


bool check(vector<ll> &arr){
    ll cnt = 0;
    for(auto e : arr) cnt = (e > 0) ? cnt + 1 : cnt;
    return cnt > 1;
}

void solve(){
    ll n;
    cin >> n;
    a.assign(n, 0);
    for(int i = 0;i < n; i++) cin >> a[i];
    ll ans = 0;
    while(check(a)){
        sort(a.begin(), a.end(), greater<ll>());
        a[0]--;
        a[1]--;
        ans++;
    }
    cout << ans << endl;

}



int main() {
    solve();
}

