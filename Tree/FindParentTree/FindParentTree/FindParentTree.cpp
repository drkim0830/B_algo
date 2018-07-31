#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>

using namespace std;

void dfs(int i);

vector<vector<int>> vec(100001);

int parent[100001] = { 0 };
bool check[100001] = { false };

int main() {
	int n;
	scanf("%d", &n);

	for (int i = 1; i < n; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		vec[a].push_back(b);
		vec[b].push_back(a);
	}

	dfs(1);
	
	for (int i = 2; i <= n; i++) {
		cout << parent[i] << "\n";
	}

	return 0;
}

void dfs(int i) {
	check[i] = true;
	for (int j = 0; j < vec[i].size(); j++) {
		if (check[vec[i][j]] == false) {
			parent[vec[i][j]] = i;
			dfs(vec[i][j]);
		}
	}
}

/*
void input_data(int a, int b);

int parent[100001] = { 0 };
bool check[100001] = { false };

int main() {
	int n;
	scanf("%d", &n);
	check[1] = true;

	for (int i = 1; i < n; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		input_data(a, b);
	}

	for (int i = 2; i <= n; i++) {
		cout << parent[i] << "\n";
	}

	return 0;
}

void input_data(int a, int b) {
	if (check[a] == true) {
		parent[b] = a;
		check[b] = true;
	}
	else if (check[b] == true) {
		parent[a] = b;
		check[a] = true;
	}
	else if (check[a] == false && check[b] == false) {
		parent[b] = a;
		check[b] = true;
	}
}
*/