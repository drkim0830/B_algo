#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<vector>

using namespace std;

int color[20001];
vector<vector<int>> vec(20001);

void input_edge(int edge) {
	for (int i = 0; i < edge; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		vec[u].push_back(v);
		vec[v].push_back(u);
	}
}

void dfs(int vertex, int color_num) {
	color[vertex] = color_num;
	for (int i = 0; i< vec[vertex].size(); i++) {
		int next = vec[vertex][i];
		if (color[next] == 0) {
			dfs(next, 3 - color_num);
		}
	}
}

int main() {
	int k;

	scanf("%d", &k);
	while (k--) {
		int vertex, edge;
		scanf("%d %d", &vertex, &edge);
		for (int i = 0; i <= vertex; i++) {
			vec[i].clear();
			color[i] = 0;
		}
		input_edge(edge);
		for (int i = 1; i <= vertex; i++) {
			if (color[i] == 0) {
				dfs(i, 1);
			}
		}
		bool ans = true;
		for (int i = 1; i <= vertex; i++) {
			for (int k = 0; k< vec[i].size(); k++) {
				int j = vec[i][k];
				if (color[i] == color[j]) {
					ans = false;
				}
			}
		}

		if (ans == true)	cout << "YES" << "\n";
		else if(ans ==false)	cout << "NO" << "\n";
	}

	return 0;
}