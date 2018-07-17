/* DFS�� BFS ���� (1260 ��)
�Է� :
ù° �ٿ� ������ ���� N(1 �� N �� 1,000), ������ ���� M(1 �� M �� 10,000), Ž���� ������ ������ ��ȣ V�� �־�����. 
���� M���� �ٿ��� ������ �����ϴ� �� ������ ��ȣ�� �־�����. 
�� ������ ���� �� �־��� ���� �ִµ�, ������ �ϳ��� �ִ� ������ �����ϸ� �ȴ�. 
�Է����� �־����� ������ ������̴�.
ex)
4 5 1
1 2
1 3
1 4
2 4
3 4

���:
ù° �ٿ� DFS�� ������ �����, �� ���� �ٿ��� BFS�� ������ ����� ����Ѵ�. V���� �湮�� ���� ������� ����ϸ� �ȴ�.
ex)
1 2 4 3
1 2 3 4
*/

#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<vector>
#include<cstring>
#include<queue>
#include<algorithm>

using namespace std;

bool check[1001] = { false };

vector<vector<int>> input_edge(vector<vector<int>> vec, int edge) {
	for (int i = 0; i < edge; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		vec[u].push_back(v);
		vec[v].push_back(u);
	}

	return vec;
}

void dfs(vector<vector<int>> vec, int vertex) {
	check[vertex] = true;
	printf("%d ", vertex);
	for (int i = 0; i < vec[vertex].size(); i++) {
		if (check[vec[vertex][i]] == false) {
			dfs(vec, vec[vertex][i]);
		}
	}	
}

void bfs(vector<vector<int>> vec, int vertex) {
	queue<int> q;
	q.push(vertex);
	check[vertex] = true;
	while (!q.empty()) {
		int front = q.front();
		q.pop();
		printf("%d ", front);

		for (int i = 0; i < vec[front].size(); i++) {
			int next = vec[front][i];
			if (check[next] == false) {
				check[next] = true;
				q.push(next);
			}
		}
	}
}

int main() {
	int node, edge, first_vertex;
	scanf("%d %d %d", &node, &edge, &first_vertex);
	//using vector - linked list
	vector<vector<int>> vec(node+1);

	vec = input_edge(vec, edge);

	for (int i = 1; i <= node; i++) {
		sort(vec[i].begin(), vec[i].end());
	}

	dfs(vec, first_vertex);
	printf("\n");
	memset(check, false, 1001);
	bfs(vec, first_vertex);

	return 0;
}