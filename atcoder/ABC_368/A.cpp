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
void solve(){
    ll n, k;
    cin >> n >> k;
    a.assign(n, 0);

    for(int i = 0;i < n; i++) cin >> a[i];

    for(int i = n - k; i < n; i++) cout << a[i] << " ";
    for(int i = 0;i < n - k; i++) cout << a[i] << " ";

    cout << endl;
}



int main() {
    solve();
}

