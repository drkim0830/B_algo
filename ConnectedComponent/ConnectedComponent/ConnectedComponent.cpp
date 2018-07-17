#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<vector>
#include<queue>

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
/*
using DFS

void dfs(int vertex) {
	check[vertex] = true;
	for (int i = 0; i < vec[vertex].size(); i++) {
		if (check[vec[vertex][i]] == false) {
			dfs(vec[vertex][i]);
		}
	}
}
*/

void bfs(int vertex) {
	queue<int> q;
	q.push(vertex);
	check[vertex] = true;
	while (!q.empty()) {
		int front = q.front();
		q.pop();
		//printf("%d ", front);

		for (int i = 0; i < vec[front].size(); i++) {
			int next = vec[front][i];
			if (check[next] == false) {
				check[next] = true;
				q.push(next);
			}
		}
	}
}
void checkConnectedComponent(int node) {
	for (int i = 1; i <= node; i++) {
		if (check[i] == false) {
			//dfs(i);
			bfs(i);
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