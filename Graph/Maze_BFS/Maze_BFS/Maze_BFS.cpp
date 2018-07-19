#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<queue>
#include<utility>

using namespace std;

int** maze;
int** check;
int dx[] = { 0,1,0,-1 };
int dy[] = { 1,0,-1,0 };
int cnt = 1;
int n, m;

void input_data(int n, int m);
void bfs(int x, int y, int cnt);

int main() {
	scanf("%d %d", &n, &m);

	maze = new int*[n];
	check = new int*[n];

	for (int i = 0; i < n; ++i) {
		maze[i] = new int[m]();
		check[i] = new int[m]();
	}

	input_data(n, m);

	bfs(0, 0, cnt);

	cout << check[n - 1][m - 1];


	return 0;
}

void input_data(int n, int m) {
	// input_data
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%1d", &maze[i][j]);
		}
	}
}

void bfs(int x, int y, int cnt) {
	queue<pair<int, int>> q;
	q.push(make_pair(0, 0));
	check[0][0] = cnt;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int k = 0; k<4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (0 <= nx && nx < n && 0 <= ny && ny < m) {
				if (maze[nx][ny] == 1 && check[nx][ny] == 0) {
					q.push(make_pair(nx, ny));
					check[nx][ny] = check[x][y] + 1;
				}
			}
		}
	}
}