#include <iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
/*
保证从前到后每一位是最大的
AC!!!
bacaa
1

acaa


bacaa
2

aaa


acaba
1

aaba


abcba
1

abba

*/


int main() {
        string s; int a;
        cin >> s >> a;
        while (a) {
            for (int i = 0; i < s.length(); i++) {
                if (s[i] > s[i + 1]) 
                { s.erase(s.begin()+i); a--; break; 
                
                }
            }
        }
        cout << s;





}

