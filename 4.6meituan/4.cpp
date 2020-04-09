#include<bits/stdc++.h>
using namespace std;

/*
3

6
*/
int ans = 0;
vector<int> path;
int vis[4] = { 0 };
void dfs(int i, int depth, int& step) {
    if (i < 0 || i > 3 || vis[i] == 1) return;
    if (depth == step)
    {
        if (i == 0)
            ans++;
        return;
    }
    for (int k = 0; k < 4; k++) {
        path.push_back(i);
        if (k != i) dfs(k, depth + 1, step);
        path.pop_back();
    }

}
int main() {
    int matrix[4][4];
    int step; cin >> step;
    dfs(0, 0, step);
    cout << ans;
    return 0;
}
