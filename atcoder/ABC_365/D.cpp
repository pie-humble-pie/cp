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
ll n;
string s;
map<pair<ll, char>, ll> dp;
ll f(ll i, char c = '$'){
    if(i == n) return 0;
    auto curr = make_pair(i, c);
    if(dp.count(curr)) return dp.at(curr);
    ll ans = 0;
    if(s[i] == 'S'){
        if(c != 'R') {
            ans = max(ans, 1 + f(i+1, 'R'));
        }
        if(c != 'S')
            ans = max(ans, f(i+1, 'S'));
    }
    else if(s[i] == 'R'){
        if(c != 'P') 
            ans = max(ans, 1 + f(i+1, 'P'));
        
        if(c != 'R')
            ans = max(ans, f(i+1, 'R'));
    }
    else{
        if(c != 'S') 
            ans = max(ans, 1 + f(i+1, 'S'));
        
        if(c != 'P')
            ans = max(ans, f(i+1, 'P'));
    }
    return dp[curr] = ans;
}

void solve(){

    cin >> n;
    cin >> s;

    dp.clear();
    cout << f(0) << endl;
}



int main() {
    solve();
}


