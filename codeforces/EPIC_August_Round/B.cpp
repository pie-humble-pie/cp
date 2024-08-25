#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

void solve() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        
        vector<int> a(n), b(n);
        unordered_map<int, int> a_pos, b_pos;
        
        // Reading Alice's permutation and storing positions
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            a_pos[a[i]] = i;
        }
        
        // Reading Bob's permutation and storing positions
        for (int i = 0; i < n; ++i) {
            cin >> b[i];
            b_pos[b[i]] = i;
        }
        
        int alice_last = n, bob_last = n;
        
        // Find the minimal position in Bob's permutation where Alice's element can end up
        for (int i = 0; i < n; ++i) {
            alice_last = min(alice_last, b_pos[a[i]]);
        }
        
        // Find the minimal position in Alice's permutation where Bob's element can end up
        for (int i = 0; i < n; ++i) {
            bob_last = min(bob_last, a_pos[b[i]]);
        }
        
        // Determine the winner
        if (alice_last < bob_last) {
            cout << "Alice" << endl;
        } else {
            cout << "Bob" << endl;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}
