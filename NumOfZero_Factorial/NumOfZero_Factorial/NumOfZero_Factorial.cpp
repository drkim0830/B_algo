#define _CRT_SECURE_NO_WARNINGS

#include<iostream>

using namespace std;

int num_zero_factorial(int n) {
	int ans = 0;

	for (int i = 1; i <= n; i++) {
		if ((i % 5) == 0) {
			ans++;
		}
		if ((i % 25) == 0) {
			ans++;
		}
		if ((i % 125) == 0) {
			ans++;
		}
	}
	return ans;
}

int main() {
	int n, ans;

	scanf("%d", &n);

	ans = num_zero_factorial(n);

	cout << ans;

	return 0;
}