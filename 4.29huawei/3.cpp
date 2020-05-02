#include <iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;

/*
从城市1走到城市N

例：从1到6， 1 -> 3 -> 5 ->4 -> 6 路径长度11


5
6
7
1 2 2 4
2 4 3 3
3 4 2 4
1 3 4 1
4 6 2 1
3 5 2 0
5 4 3 2


*/
struct node {
	int dest;
	int length;
	int cost;
};

int nearest_length = 100000000;
int flag = 0;
void dfs(vector<vector<node>>& city, int cur, int target, int length, int coins) {
	if (cur == target) {
		if (length < nearest_length) nearest_length = length;
		flag = 1;
		return;
	}

	vector<node> neighbours = city[cur];
	for (node& neighbor : neighbours) {
		if(coins >= neighbor.cost) dfs(city, neighbor.dest, target, length + neighbor.length, coins - neighbor.cost);
	}
}
int main() {
	int k, n, r;
	cin >> k >> n >> r;
	vector<vector<node>> city(n+1);
	for (int i = 0; i < r; i++) {
		int source, dest, length, cost;
		cin>> source>>dest>>length>>cost;
		city[source].push_back({ dest,length,cost });
	}
	dfs(city, 1, n, 0, k);
	if (flag) cout << nearest_length;
	else cout << -1;
}

