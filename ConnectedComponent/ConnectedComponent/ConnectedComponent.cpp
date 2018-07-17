#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<vector>

using namespace std;

vector<vector<int>> vec(1001);
bool check[1001] = { false };
int cnt = 0;

void input_edge(int edge) {
	for (int i = 0; i < edge; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		vec[u].push_back(v);
		vec[v].push_back(u);
	}
}

void dfs(int vertex) {
	check[vertex] = true;
	for (int i = 0; i < vec[vertex].size(); i++) {
		if (check[vec[vertex][i]] == false) {
			dfs(vec[vertex][i]);
		}
	}
}

void checkConnectedComponent(int node) {
	for (int i = 1; i <= node; i++) {
		if (check[i] == false) {
			dfs(i);
			cnt++;
		}
	}
}

int main() {
	int node, edge;
	
	scanf("%d %d", &node, &edge);

	input_edge(edge);
	checkConnectedComponent(node);
	cout << cnt;


	return 0;
}