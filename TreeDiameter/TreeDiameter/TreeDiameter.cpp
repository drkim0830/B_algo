#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

void input_data(int n);
void bfs(int vertex);

vector<vector<pair<int, int>>> vec(10001);

int weight[10001];
bool check[10001];

int max_weight = 0;

int main() {
	int n, root = 1;
	scanf("%d", &n);
	
	input_data(n);

	bfs(1);
	for (int i = 1; i <= n; i++) {
		if (weight[i] > weight[root]) {
			root = i;
		}
	}
	
	bfs(root);
	for (int i = 1; i <= n; i++) {
		if (max_weight < weight[i]) {
			max_weight = weight[i];
		}
	}

	cout << max_weight;

	return 0;
}

void input_data(int n) {
	for (int i = 1; i < n; i++) {
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		vec[u].push_back(make_pair(v, w));
		vec[v].push_back(make_pair(u, w));
	}
}

void bfs(int vertex) {
	memset(weight, 0, sizeof(weight));
	memset(check, false, sizeof(check));
	queue<int> q;
	check[vertex] = true;
	q.push(vertex);
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		for (int i = 0; i < vec[x].size(); i++) {
			int next = vec[x][i].first;
			int temp_weight = vec[x][i].second;
			if (check[next] == false) {
				weight[next] = weight[x] + temp_weight;
				q.push(next);
				check[next] = true;
			}
		}
	}
}