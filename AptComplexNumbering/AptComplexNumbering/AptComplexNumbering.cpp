#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<string>
#include<algorithm>
#include<cstdio>

using namespace std;

int** apt_map;
int** check;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int map_size;
int ans[25 * 25];


void input_data(int map_size);
void dfs(int x, int y, int cnt);

int main() {
	
	scanf("%d", &map_size);

	apt_map = new int* [map_size];
	check = new int*[map_size];

	for (int i = 0; i < map_size; ++i) {
		apt_map[i] = new int [map_size]();
		check[i] = new int [map_size]();
	}

	// input_data
	input_data(map_size);
	
	//ConnectedComponent + dfs
	int cnt = 0;
	for (int i = 0; i < map_size; i++) {
		for (int j = 0; j < map_size; j++) {
			if (apt_map[i][j] == 1 && check[i][j] == 0) {
				dfs(i, j, ++cnt);
			}
		}
	}

	printf("%d\n", cnt);
	for (int i = 0; i < map_size; i++) {
		for (int j = 0; j < map_size; j++) {
			ans[check[i][j]] += 1;
		}
	}
	sort(ans + 1, ans + cnt + 1);
	for (int i = 1; i <= cnt; i++) {
		printf("%d\n", ans[i]);
	}

	return 0;
}

void input_data(int map_size) {
	// input_data
	for (int i = 0; i < map_size; i++) {
		for (int j = 0; j < map_size; j++) {
			scanf("%1d", &apt_map[i][j]);
		}
	}
}

void dfs(int x, int y, int cnt) {
	check[x][y] = cnt;

	for (int k = 0; k<4; k++) {
		int nx = x + dx[k];
		int ny = y + dy[k];
		if (0 <= nx && nx < map_size && 0 <= ny && ny < map_size) {
			if (apt_map[nx][ny] == 1 && check[nx][ny] == 0) {
				dfs(nx, ny, cnt);
			}
		}
	}
}