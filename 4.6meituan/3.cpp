#include<bits/stdc++.h>
using namespace std;

/*
10 3

8

*/
int main() {
    int n, k;
    cin >> n >> k;
    /*
        for (int i = k; i < n; i++) {
        //i是第一天修的bug， 第二天 i/ k
        int remain = n;
        int tmp_i = i;
        while (tmp_i) {
            remain -= tmp_i;
            tmp_i /= k;
        }
        if (remain == 0) { cout << i; return 0; }
    }
    */

    for (int i = k; i < n; i++) {
        //i是第一天修的bug， 第二天 i/ k
        int remain = n;
        int tmp_i = i;
        int exp = 0;
        int tmp_n = n;
        while (tmp_n > 0) { tmp_n /= k; exp++; };
        int exp_ = log(tmp_n);
        int sum = i * (1 - pow((1 / double(k)), exp)) / (1 - 1/double(k));
        if(sum >= n) { cout << i+1; return 0; }
    }
    return 0;
}
