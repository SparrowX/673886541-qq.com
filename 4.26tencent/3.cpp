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

3
1 3 2
3 2 1
1

3
3 2 1
5 4 3
1
*/
void swap(vector<int>&a, vector<int>& b, int i) {
    swap(a[i - 1], b[i]);
    swap(a[i], b[i-1]);
}
int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    int cnt = 0;
    for (int i = 1; i < n; i++) {
        if (a[i] < a[i - 1]) {
            int min_i1 = 99999, min_i = 99999;
            if (i + 1 < n && b[i + 1] <= b[i] && b[i + 1] >= a[i - 1]) 
            {     
                    min_i1 = b[i + 1];
            }
            if (b[i] <= b[i - 1]) {

                min_i = b[i - 1];
            }
            else {
                cout << -1;
                return 0;
            }
            if (min_i1 < min_i) {
                swap(a, b, i + 1);
                cnt++;
            }
            else {
                swap(a, b, i); cnt++;
            }
        }
    }

    cout << cnt;
    return 0;
}
