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
vector<vector<ll>> dp;

int rec(int i, int j){
    if(j < i) return 0;
    if(i == j) return a[i];
    if((j - i + 1) % 2 == 0) return 0;
    if(dp[i][j] != 0) return dp[i][j];
    int ans = 0;
    for(int k = i;k <= j; k++){
        ans = max(ans, max(rec(i,k-1), rec(k+2, j)));
    }
    return dp[i][j] = ans;
}
void solve(){
    int n;
    cin >> n;
    a.assign(n,0);
    dp.assign(n,vector<ll>(n,0));
    for(int i = 0;i < n; i++) cin >> a[i];
    cout << rec(0, n-1) << endl;
}



int main() {

    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}

