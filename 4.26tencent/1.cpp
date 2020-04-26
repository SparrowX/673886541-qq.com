#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<sstream>
#include<queue>
using namespace std;
/*

2
7
PUSH 1
PUSH 2
TOP
POP
TOP
POP
POP
5
PUSH 1
PUSH 2
SIZE
POP
SIZE

*/
int main() {
    int t, q;
    cin >> t;
    while (t--) {
        cin >> q;
        getchar();
        queue<int> queue;
        while (q--) {
            string s;
            getline(cin,s);
            stringstream ss(s);
            string oper; int num;
            ss >> oper >> num;
            
            if (oper == "PUSH") {
                queue.push(num);
            }
            else if (oper == "POP") {
                if (queue.empty()) cout << -1 << endl;
                else queue.pop();
            }
            else if (oper == "TOP") {
                if (queue.empty()) cout << -1 << endl;
                else cout << queue.front() << endl;
            }
            else if (oper == "SIZE") {
                cout << queue.size() << endl;
            }
            else if (oper == "CLEAR") {
                while (!queue.empty()) queue.pop();
            }
        }
    }
    return 0;
}
