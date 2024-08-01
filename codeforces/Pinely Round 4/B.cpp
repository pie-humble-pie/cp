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


void solve(){
    int n;
    cin >> n;
    b.assign(n-1,0);
    a.clear();
    for(int i = 0;i < n-1; i++) cin >> b[i];
    
    a.push_back(b[0]);
    bool ok = true;
    for(int i = 1;i < n - 1; i++){
        int curr = b[i] | b[i-1];
        if((a[i-1] & curr) != b[i-1]){
            ok = false;
            break;
        }
        a.push_back(curr);
    }
    a.push_back(b[n-2]);
    if(ok){
        for(int i = 0;i < n; i++) cout << a[i] << " ";
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

