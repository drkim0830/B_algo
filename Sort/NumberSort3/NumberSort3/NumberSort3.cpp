#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main() {
	int n, input_data;
	scanf("%d", &n);
	int arr[10001] = { 0 };

	for (int i = 0; i < n; i++) {
		scanf("%d", &input_data);
		arr[input_data]++;
	}
	for (int i = 1; i <= 10000; i++) {
		if (arr[i] > 0) {
			for (int j = 1; j <= arr[i]; j++) {
				cout << i << "\n";
			}
		}
	}

	return 0;
}