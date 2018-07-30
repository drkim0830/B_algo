#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

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