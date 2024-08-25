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
    ll n; 
    cin >> n;
    if(!(n & 1)){
        cout << -1 << endl;
        return;
    }
    deque<ll> d;
    for(int i = 1;i <= n; i++){
        ll x = n - i + 1;
        if(i & 1){
            d.push_back(x);
        }
        else{
            d.push_front(x);
        }
    }
    while(!d.empty()){
        cout << d.front() << " ";
        d.pop_front();
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
