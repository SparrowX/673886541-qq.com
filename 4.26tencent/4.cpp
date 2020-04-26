#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<sstream>
#include<queue>
#include<cmath>
#include<cstdio>
#include<stack>
using namespace std;
/*
6
add 1
add 2
add 3
peek
poll
peek6
add 1
add 2
add 3
peek
poll
peek
*/

int main() {
    int n; cin >> n;
    //queue<int> q;
    getchar();
    stack<int> a;
    stack<int> b;
    while (n--) {
        string s;
        getline(cin, s);
        stringstream iss(s);
        string op; int num;
        iss >> op >> num;
        if (op == "add") {
            a.push(num);
        }
        else if (op == "peek") {
            if(!b.empty()) cout << b.top() << endl;
            else {
                while (!a.empty()) {
                    b.push(a.top());
                    a.pop();
                }
                cout << b.top() << endl;
            }
        }
        else if (op == "poll") {
            if (!b.empty()) b.pop();
            else {
                while (!a.empty()) {
                    b.push(a.top());
                    a.pop();
                }
                b.pop();
            }
        }
    }
    return 0;
}
