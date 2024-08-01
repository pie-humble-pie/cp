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
const int INF = 1e9 + 5;
vector<vector<int>> dp;
vector<int> a[3];

int solve(int i, int n, int mask){
    //base case
    if(i == n)
        return 0;
    if(mask == ((1 << 3) - 1))
        return 0;
    if(dp[i][mask] != -1) return dp[i][mask];
    int ans = 0;
    for(int j = 0;j < 3; j++){
        if(mask & (1 << j)) continue;
        ans = max(ans, a[j][i] + solve(i + 1, n, mask | (1 << j)));
    }
    ans = max(ans, solve(i + 1, n, mask));
    return dp[i][mask] = ans;
}

int main() {
    int t, n;
    cin >> t;
    for(int tcase = 0;tcase < t; tcase++){
        cin >> n;
        for(int i = 0;i < 3; i++){
            a[i].assign(n, 0);
            for(int idx = 0;idx < n; idx++){
                cin >> a[i][idx];
                //cout << a[i][idx] << " ";
            }
            //cout << endl;
        }
 
        dp.assign(n, vector<int>(8, -1));
        cout << solve(0, n, 0) << endl;
    }
    return 0;
}

