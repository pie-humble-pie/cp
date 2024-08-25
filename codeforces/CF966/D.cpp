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
#include <unordered_map>
typedef long long int ll;

using namespace std;

vector<ll> a;
vector<ll> ps;
string s;
queue<ll> l;
queue<ll> r;
const ll MAX = 1e18;

void precompute(ll n){
    for(int i = 1;i <= n; i++)
        ps[i] = ps[i-1] + a[i];

    for(int i = 0;i < n; i++)
        if(s[i] == 'L') l.push(i + 1);

    for(int i = n-1;i >= 0; i--)
        if(s[i] == 'R') r.push(i + 1);
}

ll sum(ll l, ll r){
    return ps[r] - ps[l - 1];
}

void solve(){
    ll n;
    cin >> n;
    a.assign(n+1, 0);
    ps.assign(n+1, 0);

    while(!l.empty()) l.pop();
    while(!r.empty()) r.pop();

    for(int i = 1;i <= n; i++) cin >> a[i];
    
    cin >> s;
    //cout << s;
    
    precompute(n);

    ll ans = 0;
    while(!l.empty() && !r.empty()){
        ll st = l.front();
        l.pop();
        ll en = r.front();
        r.pop();
        //cout << st << " " << en << endl;
        if(en > st){
            ans += sum(st, en);
        }
        else break;
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

