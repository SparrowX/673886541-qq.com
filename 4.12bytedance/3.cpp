#include<bits/stdc++.h>
using namespace std;

/*
3 4
50 100 200
99 199 200 300

3 8
50 100 200
49 49 50 99 199 200 300 1000

1 4
100
99 199 200 300
*/

int main() {
    int n, m; cin >> n >> m;
    set<int> coupon;
    vector<int> commodity(m);
    //vector<int> lower(m);
    //vector<int> upper(m);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int tmp; cin >> tmp;
        coupon.insert(tmp);
    }
    /*
       for (int i = 0; i < m; i++) {
        int tmp; cin >> tmp;
        //commodity[i] = tmp;
        int zhekou = 0;
        for (auto u : coupon) {
            if (u <= tmp) zhekou = u;
            else break;
        }
        ans += tmp - zhekou;
    }
    */
    for (int i = 0; i < m; i++) {
        int tmp; cin >> tmp;
        commodity[i] = tmp;
    }
    sort(commodity.begin(), commodity.end());
    auto it = coupon.begin();
    for (auto& num : commodity) {
        int zhekou = 0;
        while (it != coupon.end() && *it < num) it++;
        if (it == coupon.end()) it--;
        if ( *it > num) it--;
        if (it != coupon.end()) zhekou = *it;
        ans += num - zhekou;
    }
    cout << ans << endl;
    

}
