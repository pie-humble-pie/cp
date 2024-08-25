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



void solve(){
    ll x;
    cin >> x;
    if(x % 400 == 0) cout << 366 << endl;
    else if(x % 100 == 0) cout << 365 << endl;
    else if(x % 4 == 0) cout << 366 << endl;
    else cout << 365 << endl;
}



int main() {
    solve();
}

