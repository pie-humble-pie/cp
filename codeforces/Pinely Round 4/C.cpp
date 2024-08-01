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
const ll MAX = 40;

void solve(){
    ll n, x;
    cin >> n;
    set<ll> s1, s2;
    vector<int> record;
    bool ok = false;
    for(int i = 0;i < n; i++){
        cin >> x;
        s1.insert(x);
    }
    if((s1.size()) == 1 && (*s1.begin() == 0)) ok = true;

    ll maxTry = MAX;
    
    while(!ok && (maxTry > 0)){
        ll lo = *s1.begin();
        ll hi = *s1.rbegin();
        ll mid = lo + ((hi - lo) >> 1);
        //cout << 40 - maxTry + 1 << " " << lo << " " << hi << " " << mid << endl;
        record.push_back(mid); 
        for(auto e : s1){
            s2.insert(abs(mid - e));
        }
        if((s2.size() == 1) && (*s2.begin() == 0)) ok = true;
        s1.clear();
        s1 = s2;
        s2.clear();
        maxTry--;
    }

    if((s1.size()) == 1 && (*s1.begin() == 0)) ok = true;
    
    if(ok){
        cout << MAX - maxTry << endl;
        for(auto op : record) cout << op << " ";
    }
    else{
        cout << -1;
    }
    cout << endl;


}



int main() {

    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}

