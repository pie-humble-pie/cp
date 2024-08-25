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

vector<int> a;

const int MAX = 1e9;


int num_points(int b, int dist){
    auto en = upper_bound(a.begin(), a.end(), b + dist);
    auto st = upper_bound(a.begin(), a.end(), b - dist - 1);
    if(st != a.end() && en != a.end())
        return en - st;
    if(st != a.end())
        return en - st;
    return 0;
}

int distance(int b, int k){
    int lo = 0;
    int hi = MAX;
    int mid = 0;

    while(lo < hi){
        mid = lo + ((hi - lo) >> 1);
        if(num_points(b, mid) >= k) hi = mid;
        else lo = mid + 1;
    }
    if(num_points(b, lo) >= k) return lo;
    return -1;
}


void solve(){
    int n, q, b, k;
    cin >> n >> q;
    
    a.assign(n, 0);
    for(int i = 0;i < n; i++) cin >> a[i];

    sort(a.begin(), a.end());

    for(int i = 0;i < q; i++){
        cin >> b >> k;
        cout << distance(b, k) << endl;
    }

}

int main() {
    solve();
    return 0;
}