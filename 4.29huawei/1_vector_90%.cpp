#include <iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
/*

abc

优化，在末尾判断加不加入
*/

vector<string> result;
void swap(int pos, int i, string& s) {
    int tmp = s[pos];
    s[pos] = s[i];
    s[i] = tmp;
}

void dfs(string& s, int pos, string& path, vector<string>& result) {
    if (path.size() == s.length()) {
        result.push_back(path);
        return;
    }
    for (int i = pos; i < s.length(); i++) {
        swap(pos, i, s);
        path += s[pos];
        dfs(s, pos + 1, path, result);
        swap(pos, i, s);
        path.pop_back();

    }
}
int main() {
    string  s; cin >> s;
    string path;
    dfs(s, 0, path, result);
    sort(result.begin(), result.end());
    result.erase(unique(result.begin(), result.end()), result.end());
    cout << result.size();
}

