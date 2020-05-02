#include <iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<unordered_set>
using namespace std;
/*

abc

优化，在末尾判断加不加入
*/

unordered_set<string> result;
void swap(int pos, int i, string& s) {
    int tmp = s[pos];
    s[pos] = s[i];
    s[i] = tmp;
}

void dfs(string& s, int pos, string& path, unordered_set<string>& result) {
    if (path.length() == s.length()) {
        result.insert(path);
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
    if (s == "") cout << 0;
    string path;
    dfs(s, 0, path, result);
    cout << result.size();
}

