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


//typedef block
typedef long long int ll;
#define pb push_back

//define block
#define ff first
#define ss second
#define pii pair<ll,ll>
#define vi vector<ll>
#define vii vector<pair<ll,ll>>

using namespace std;

int main() {
    int t, n;
    cin >> t;
    for(int tt = 0;tt < t; tt++){
        cin >> n;
        bool ok = false;
        vector<vector<ll>> a(3, vector<ll>(n, 0));
        vector<vector<ll>> p(3, vector<ll>(n, 0));
        for(int i = 0;i < 3; i++){
            for(int j = 0;j < n;j++){
                cin >> a[i][j];
                p[i][j] = (j > 0) ? p[i][j-1] + a[i][j] : a[i][j];
                //cout << p[i][j] << " ";
            }
            //cout << endl;
        }

        vector<pair<int, int>> ans;
        vector<int> players({0, 1, 2});
        do {
        int x, y, check;
        x = y = check = 0;
        int a = players[0];
        int b = players[1];
        int c = players[2];
        ll sum = 0;
        ll k = (p[0][n-1] % 3 == 0) ? p[0][n-1]/3 : (p[0][n-1]/3) + 1;
        ans.assign(3, {0, 0});
        //cout << a << b << c << endl;

        while(x < n){
            sum = p[a][x];
            if(sum >= k){
                ans[a] = make_pair(1, x + 1);
                //cout << sum << " " << x << endl;
                check |= (1 << a);
                break;
           }
           x++;
        }
        //cout << 1 << " " << x;
        y = x++;
        
        while(y < n){
                sum = p[b][y] - p[b][x - 1];
                if(sum >= k){
                    ans[b] = make_pair(x + 1, y + 1);
                    check |= 1 << b;
                    break;
                }
                y++;
            }
        y++;
        sum = p[c][n-1] - p[c][y - 1];
        if(sum >= k){
            ans[c] = make_pair(y + 1, n);
            check |= 1 << c;
        }
        //cout << check << endl;
        if(check  == ((1 << 3) - 1)){
            ok = true;
            break;
        }
    }
    while(next_permutation(players.begin(), players.end()));

    if(ok){
            for(auto p : ans) cout << p.first << " " << p.second << " ";
            cout << endl;
    }
    else cout << -1 << endl;

    }
    
    return 0;
}
