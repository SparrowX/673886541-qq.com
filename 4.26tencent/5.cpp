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
4
10 1
10 2
10 3
10 4
*/
int find(int low, int high, int node) {
    if (low > high) return low;
    int mid = (high + low) / 2;
    if (pow(2, mid) < node) {
        find(mid + 1, high, node);
    }
    else if(pow(2, mid) == node){
        return mid;
    }
    else {
        find(low, mid - 1, node);
    }
}
int main() {
    int n; cin >> n;
    while (n--) {
        int node, father_layer;
        cin >> node >> father_layer;
        int layer = 1;
        int pow2 = 2;
        int node_accum = pow2 - 1;
        int high = 61; int low = 1;
        layer = find(low, high, node);
       //while (node > node_accum) {
       //     pow2 *= 2; layer++;
       //     node_accum = pow2 - 1;
       // }
        int dis = layer - father_layer;
        if (dis <= 0) {
            cout << -1 << endl;
            continue;
        }
        int father = node;
        father /= pow(2, dis);
        cout << father << endl;

    }
    return 0;
}
