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

int gcd(int a, int b){
    if(a == 0) return 0;
    if(b == 0) return 0;
    if(a == b) return a;
    if(a > b)
        return gcd(b, a - b);
    return gcd(a, b - a);
}

int main() {
    int t, n;
    cin >> t;
    for(int i = 0;i < t; i++){
        cin >> n;
        vector<int> arr;
        arr.assign(n, 1);
        for(int x = 1; x <= n; x++){
            if(x == 1) continue;
            for(int y = x - 1;y < n;y += x){
                int g = gcd(x, arr[y]);
                arr[y] = arr[y] * (x / g);
            }
        }

        for(int x : arr) cout << x << " ";
        cout << endl;
    }
    return 0;
}

