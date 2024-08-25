//https://codeforces.com/contest/1931/problem/E
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

vector<string> a;
const ll MAX = 1e18;

ll get_leading_zeros(string& s){
    int n = s.length();
    ll ans = 0;
    for(int i = n-1;i >= 0; i--){
        if(s[i] != '0') break;
        ans++;
    }
    return ans;
}

void solve(){
    ll n, m;
    cin >> n >> m;
    
    a.assign(n, "");
    vector<ll> zeros;
    ll total = 0;
    ll sub = 0;

    for(auto &u : a){
        cin >> u;
        total += u.length();
        zeros.push_back(get_leading_zeros(u));
    }

    sort(zeros.begin(), zeros.end(), greater<ll>());

    for(int i = 0;i < zeros.size(); i++){
        if(i % 2 == 0) sub += zeros[i];
    }
    ll ans = total - sub;
    string winner = (ans <= m) ? "Anna" : "Sasha";
    cout << winner << endl; 
}



int main() {
    int t;
    cin >> t;
    for(int i = 0;i < t; i++){
        solve();
    }
}

