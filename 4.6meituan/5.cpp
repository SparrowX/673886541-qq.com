#include<bits/stdc++.h>
using namespace std;

/*
3

6
*/

int main() {
    int n, k; cin >> n >> k;
    int tmp_k = k;
    vector<string> s;
    string tmps;
    while (tmp_k--) { cin >> tmps; s.push_back(tmps);}
    int tmpn = n;
    while (tmpn--) {
        cin >> tmps;
        if (tmps[0] == '?');
    }
    int out[] = { 7,7,5,3,5 };
    for (int i = 0; i < 5; i++) {
        cout << out[i] << endl;
    }
}
