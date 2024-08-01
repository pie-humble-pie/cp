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


bool isValid(int x, int y, int R, int C, vector<vector<char>>& g){
    return (x >= 0 && y >= 0 && x < R && y < C && (g[x][y] != '#'));
}

void solve(){
    int R, C;
    int sx, sy;
    cin >> R >> C;
    cin >> sx >> sy;
    string X;
    vector<vector<char>> g(R, vector<char>(C, '.'));
    
    for(int i = 0;i < R; i++){
        for(int j = 0;j < C; j++){
            cin >> g[i][j];
        }
    }

    cin >> X;
    int x = sx;
    int y = sy;
    vector<int> dx = {-1, 1, 0, 0};
    vector<int> dy = {0, 0, -1, 1};
    unordered_map<char, int> val;
    val['L'] = 0;
    val['R'] = 1;
    val['U'] = 2;
    val['D'] = 3;

    for(auto ch : X){
        int nx = x + dx[val[ch]];
        int ny = y + dy[val[ch]];
        if(isValid(nx, ny, R, C, g)){
            x = nx;
            y = ny;
        }
    }

    cout << x << " " << y;
}

int main() {

    solve();
    return 0;
}

