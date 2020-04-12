#include<bits/stdc++.h>
using namespace std;

/*
5
3 5 13 9 12

1
100

4
99 5 100 68 
最终数组单调
*/
int global_cnt = 0;
void makeItIncrease(vector<int>& array, int& n) {
    int max_index = 0;
    for (int i = 0; i < n; i++) {
        if (array[i] >= array[max_index]) max_index = i;
    }
    if (max_index != n - 1) {
        global_cnt++;
        int first, second;
        if (max_index == 0) {
            second = array[max_index + 1];
            first = array[max_index] - second;
        }
        else {
            first = array[max_index - 1];
            second = array[max_index] - first;
        }
        array.erase(array.begin() + max_index);
        array.insert(array.begin() + max_index, { first,second });
        int n = array.size();
        makeItIncrease(array, n);
    }
    else return;
}

void makeItIncrease2(vector<int>& array, int& n) {
    int max_index = 0;
    for (int i = 1; i < n; i++) {
        if (array[i] < array[i - 1]) {
            max_index = i - 1;
            global_cnt++;
            int first, second;
            if (max_index == 0) {
                second = array[max_index + 1];
                first = array[max_index] - second;
            }
            else {
                first = array[max_index - 1];
                second = array[max_index] - first;
            }
            array.erase(array.begin() + max_index);
            array.insert(array.begin() + max_index, { first,second });
            int n = array.size();
            makeItIncrease2(array, n);
        }
    }
}
int main() {
    int n; cin >> n;
    vector<int> array(n);
    for (int i = 0; i < n; i++) {
        cin >> array[i];
    }
    makeItIncrease2(array, n);
    cout << global_cnt;
}
