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

using namespace std;

#define iset indexed_set
#define ll long long int
#define ull unsigned long long int
#define f first
#define sec second
#define rep(i, st, end) for(ll i = st; i < end; i++)
const ll mod = 1e9 + 7;
using ii = pair<ll,ll>;

map<char,ll> mp;
string s;
vector<vector<ll>> dp;
ll rec(ll level, ll ch) {
	if(level < 0) {
		return 0;
	}

	if(dp[level][ch] != -1) return dp[level][ch];

	ll val = mp[s[level]], ans = 0;
	if((val+1)%3 != ch) {
		ans = max(ans,rec(level-1,(val+1)%3)+1);
	}
	if(val != ch) {
		ans = max(ans,rec(level-1,val));
	}
	return dp[level][ch] = ans;
}
void solve()
{
	ll n; cin>>n;
	cin>>s;
	dp.resize(n+1);
	rep(i,0,n+1) {
		dp[i].assign(3,-1);
	}

	if(n == 1) {
		cout<<"1";
		return;
	}

	ll ans = max(rec(n-2,mp[s[n-1]]),rec(n-2,(mp[s[n-1]]+1)%3)+1);
	cout<<ans;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    mp['R'] = 0; mp['P'] = 1; mp['S'] = 2;
    //int t; cin>>t; while(t--)
    solve();
    return 0;
}