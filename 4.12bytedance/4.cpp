#include<bits/stdc++.h>
using namespace std;

/*
3
4
1 4 3 3
5
8 2 2 4 6
6
5 8 1 3 2 9
*/

int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> house(n);
        vector<int> ans(n);
        int max_idx = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> house[i];
            if (house[i] > house[max_idx]) max_idx = i;
        }
        for (int i = 0; i < n; i++)
        {
            if (i == max_idx) {
                ans[i] = n - 1;
                continue;
            }
            int ans_ = 0;
            int left = i - 1, right = i + 1;
            while (left >= 0 && house[left] <= house[i]) {
                ans_++;
                left--;
            }
            while (right <= n-1 && house[right] <= house[i]) {
                ans_++;
                right++;
            }
            ans[i] = ans_;
        }
        for (int i = 0; i < n; i++)
        {
            if(i != n - 1) cout << ans[i] << " ";
            else {
                cout << ans[i] << endl;
            }
        }

    }
    

}
