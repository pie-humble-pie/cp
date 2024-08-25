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


ll addT(ll health, ll T){
    ll ans = 0;
    ll F = health / 5;
    ll H = health % 5;
    ans += F*3LL;
    
    if(H == 0) return T + ans;

    if(T % 3 == 0){ // 1 1 3
        ans += (H <= 2) ? H : 3;
    }
    else if(T % 3 == 1){ // 1 3 1
        ans += (H <= 1) ? H : 2;
    }
    else{ // 3 1 1 
        ans += (H <= 3) ? 1 : ((H == 4) ? 2 : 3);
    }
    return T + ans;
}
void solve(){
    ll n;
    cin >> n;
    a.assign(n, 0);
    for(int i = 0;i < n; i++) cin >> a[i];
    
    ll prev = 0;
    ll curr = 0;
    for(int i = 0;i < n; i++) {
        curr = addT(a[i], prev);
        prev = curr;
        //cout << curr << endl;
    }

    cout << curr << endl;

}



int main() {
    solve();
}

