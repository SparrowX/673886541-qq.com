#include<bits/stdc++.h>
using namespace std;

/*
5
5 3 1 4 2
2 4 5 1 3

3
*/
int main() {
    int n; cin >> n;
    int cnt = 0;
    vector<int> vec1(n);
    vector<int> vec2(n);
    vector<int> dp(n); //dp表示，之后的所有人里最早出发的
    map<int, int> mp;
    for (int i = 0; i < n; i++) { 
        cin >> vec1[i]; 
        mp[vec1[i]] = i;
    }
    for (int i = 0; i < n; i++) cin >> vec2[i];
    //for (int i = 0; i < n; i++) {
   //     int tmp = vec2[i];
    //    if (i > mp[tmp]) cnt++;
   // }
    dp[n - 1] = mp[vec2[n-1]];
    for (int i = n - 2; i >= 0; i--) {
        int tmp = vec2[i+1];
        dp[i] = min(dp[i + 1], mp[tmp]);
    }
    for (int i = n-1; i >=0; i--) {
        int tmp = vec2[i];//如果该人晚于后面任意一个人（最早出发）出发，那么算一次超越
        if (mp[tmp] > dp[i]) cnt++;
    }

    cout << cnt;
    return 0;
}
