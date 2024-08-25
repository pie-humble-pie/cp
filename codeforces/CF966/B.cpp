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
const ll MAX = 1e18;

bool solve(){
    ll n;
    cin >> n;
    a.assign(n, 0);
    for(int i = 0;i < n; i++) cin >> a[i];
    unordered_set<int> pos;
    vector<bool> vis(n+2, false);
    vis[a[0]] = true;

    if(a[0] - 1 > 0) pos.insert(a[0] - 1);
    if(a[0] + 1 <= n) pos.insert(a[0] + 1);

    for(int i = 1;i < n; i++){
        int x = a[i];
        if(pos.count(x)){
            vis[x] = true;
            if(x - 1 > 0 && !vis[x - 1]) pos.insert(x - 1);
            if(x + 1 <= n && !vis[x + 1]) pos.insert(x + 1);
        }
        else{
            return false;
        }
    }
    return true;
}



int main() {
    int t;
    cin >> t;
    for(int i = 0;i < t; i++){
        if(solve())
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}

