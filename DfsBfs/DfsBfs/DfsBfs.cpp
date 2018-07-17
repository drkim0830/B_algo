/* DFS와 BFS 문제 (1260 번)
입력 :
첫째 줄에 정점의 개수 N(1 ≤ N ≤ 1,000), 간선의 개수 M(1 ≤ M ≤ 10,000), 탐색을 시작할 정점의 번호 V가 주어진다. 
다음 M개의 줄에는 간선이 연결하는 두 정점의 번호가 주어진다. 
한 간선이 여러 번 주어질 수도 있는데, 간선이 하나만 있는 것으로 생각하면 된다. 
입력으로 주어지는 간선은 양방향이다.
ex)
4 5 1
1 2
1 3
1 4
2 4
3 4

출력:
첫째 줄에 DFS를 수행한 결과를, 그 다음 줄에는 BFS를 수행한 결과를 출력한다. V부터 방문된 점을 순서대로 출력하면 된다.
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