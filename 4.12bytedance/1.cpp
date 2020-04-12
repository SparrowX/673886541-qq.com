#include<bits/stdc++.h>
using namespace std;

/*
2
6
3 7 1 4 1 2
3 7 3 6 3 2
5
1 1 1 1 1
1 2 1 3 1
*/
bool go(const vector<int>& array1, const vector<int>& array2, const int& n) {
    vector<int> diff(n);
    int diff_ = 0;
    int flag = 0;
    for (int i = 0; i < n; i++) {
        diff[i] = array1[i] - array2[i];
        if (diff[i] != 0) {
            if (!flag) {
                flag = 1;
                diff_ = diff[i];
            }
            else if (diff[i] != diff_) return false;
            else if (diff[i] != diff[i - 1]) return false;
        }
    }
    return true;
}
int main() {
    int t; cin >> t;

    while (t--) {
        int n; cin >> n;
        vector<int> array1(n);
        vector<int> array2(n);
        for (int i = 0; i < n; i++) {
            cin>>array1[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> array2[i];
        }
        if (go(array1, array2, n)) cout << "YES"<<endl;
        else cout << "NO"<<endl;
    }
}
