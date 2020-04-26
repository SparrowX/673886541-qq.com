#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<sstream>
#include<queue>
#include<cmath>
#include<cstdio>
using namespace std;
/*

2
4
0 0
0 1
1 0
1 1
2 2
2 3
3 2
3 3
4
0 0
0 0
0 0
0 0
0 0
0 0
0 0
0 0

*/
int main() {
    int total;
    cin >> total;
    while (total--) {
        int n; cin >> n;
        vector<pair<int, int>> a;
        vector<pair<int, int>> b;
        double min_dis = 99999999;
        for (int i = 0; i < n; i++) {
            int x, y; cin >> x >> y;
            a.push_back({ x,y });
        }
        bool flag = 0;
        for (int i = 0; i < n; i++) {
            int x, y; cin >> x >> y;
            if (flag != 1) {
                for (int j = 0; j < n; j++) {
                    double dis = sqrt(
                        pow((x - a[j].first), 2) +
                        pow((y - a[j].second), 2)
                        );
                    min_dis = min(min_dis, dis);
                    if ((min_dis - 0.0) < 1e-7) flag = 1;
                }
            }
        }
        printf("%.3f\n", min_dis);
    }
    return 0;
}
