#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<queue>
#include<utility>

using namespace std;

//int island[100][100] = {};
//int map[100][100] = {};
//int dist[100][100] = {};
int** map;
int** island;
int** dist;

int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int map_size;
int cnt = 0; //Num of Island

void input_data(int map_size);
void ConnectedComponent_dfs(int map_size);
void dfs(int x, int y, int cnt);
int bfs(int cnt);

int main() {

	scanf("%d", &map_size);

	map = new int*[map_size];
	island = new int*[map_size];
	dist = new int*[map_size];

	for (int i = 0; i < map_size; ++i) {
		map[i] = new int[map_size]();
		island[i] = new int[map_size]();
		dist[i] = new int[map_size]();
	}

	//input map
	input_data(map_size);

	//ConnectedComponent + dfs
	ConnectedComponent_dfs(map_size);
	
	//how many stones need to build bridge for seperated island (using bfs)
	int min = bfs(cnt);

	printf("%d\n", min);
	
	return 0;
}

void input_data(int map_size) {
	// input_data
	for (int i = 0; i < map_size; i++) {
		for (int j = 0; j < map_size; j++) {
			scanf("%d", &map[i][j]);
		}
	}
}

void ConnectedComponent_dfs(int map_size) {
	for (int i = 0; i < map_size; i++) {
		for (int j = 0; j < map_size; j++) {
			if (map[i][j] == 1 && island[i][j] == 0) {
				dfs(i, j, ++cnt);
			}
		}
	}
}

void dfs(int x, int y, int cnt) {
	island[x][y] = cnt;

	for (int k = 0; k<4; k++) {
		int nx = x + dx[k];
		int ny = y + dy[k];
		if (0 <= nx && nx < map_size && 0 <= ny && ny < map_size) {
			if (map[nx][ny] == 1 && island[nx][ny] == 0) {
				dfs(nx, ny, cnt);
			}
		}
	}
}

int bfs(int cnt) {
	int min = -1;
	for (int l = 1; l <= cnt; l++) {
		queue<pair<int, int>> q;
		for (int i = 0; i < map_size; i++) {
			for (int j = 0; j < map_size; j++) {
				dist[i][j] = -1;
				if (island[i][j] == l) {
					q.push(make_pair(i, j));
					dist[i][j] = 0;
				}
			}
		}
		while (!q.empty()) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();
			for (int k = 0; k < 4; k++) {
				int nx = x + dx[k];
				int ny = y + dy[k];
				if (0 <= nx && nx < map_size && 0 <= ny && ny < map_size) {
					if (dist[nx][ny] == -1) {
						dist[nx][ny] = dist[x][y] + 1;
						q.push(make_pair(nx, ny));
					}
				}
			}
		}
		for (int i = 0; i < map_size; i++) {
			for (int j = 0; j < map_size; j++) {
				if (map[i][j] == 1 && island[i][j] != l) {
					if (min == -1 || dist[i][j] - 1 < min) {
						min = dist[i][j] - 1;
					}
				}
			}
		}
	}
	return min;
}