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

    ll MOD = 1e9 + 7;
    vector<vector<ll>> dp;
    vector<vector<int>> valid;

    void debug_(vector<int>& a){
        for(auto e : a) cout << e << " ";
        cout << endl;
    }

    void getAllValidSequences(vector<int>& curr, vector<int>& bricks, int w) {
        for (int i = 0; i < bricks.size(); i++) {
            int sum = 0;
            if (curr.size() > 0)
                sum = curr[curr.size() - 1];
            sum += bricks[i];
            curr.push_back(sum);
            if (sum < w)
                getAllValidSequences(curr, bricks, w);
            else if (sum == w)
                valid.push_back(curr);
            curr.pop_back();
        }
    }

    bool check(vector<int> a, vector<int> b) {
        bool ok = true;
        for (int i = 0; i < a.size() - 1; i++) {
            for (int j = 0; j < b.size() - 1; j++) {
                if (a[i] == b[j]) {
                    return false;
                }
            }
        }
        return true;
    }


    ll getWays(int i, int j){
        if(i == 1) return 1;
        if(dp[i][j] != -1) return dp[i][j];
        ll ans = 0;
        for(int k = 0;k < valid.size(); k++){
            if(j != k && check(valid[j], valid[k])){
                ans += getWays(i - 1, k) % MOD;
                ans %= MOD;
            }
        }
        return dp[i][j] = ans;
    }

    int buildWall(int height, int width, vector<int>& bricks) {
        vector<int> curr = vector<int>();
        getAllValidSequences(curr, bricks, width);
        int n = height;
        int m = valid.size();
        dp.assign(n + 1, vector<ll>(m + 1, -1));
        ll ans = 0;
        for(int j = 0;j < m; j++){
            ans += getWays(n, j) % MOD;
            ans %= MOD;
        }
        return ans;
    }
int main() {
    auto bricks = vector<int>({1, 2});
    cout << buildWall(1, 3, bricks);

}

