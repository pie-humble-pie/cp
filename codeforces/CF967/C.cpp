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
vector<bool> vis;
set<pair<ll, ll>> edges;
 
void print(set<pair<ll, ll>> v){
    cout << "! ";
    for(auto p : v) cout << p.first << " " << p.second << " ";
    cout << endl;
}

ll query(ll u, ll v){
    cout << "? " << u << " " << v << endl;
    cout.flush();
    ll result;
    cin >> result;
    return result;
}
 
const ll MAX = 1e18;
 
void solve(){
    cin >> n;
    vis.assign(n + 1, false);
    edges.clear();
    vis[1] = true;
    for(ll i = 2; i <= n; i++){
        ll a = 1;
        ll b = 1;
        while(vis[b]) b++;
        if(b > n) break;
        while(1){
            ll x = query(a, b);
            if(x == a || x == b){
                edges.insert({a, b});
                vis[b] = 1;
                break;
            }
            if(vis[x]){
                a = x;
            }
            else{
                b = x;
            }
            vis[x] = true;
        }
    }

    print(edges);
    cout.flush();

    return;
}
 
 
 
int main() {
    int t;
    cin >> t;
    for(int i = 0;i < t; i++){
        solve();
    }
}
