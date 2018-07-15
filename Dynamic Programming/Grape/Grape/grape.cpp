#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<string>
#include <algorithm>  

using namespace std;

int dp[10001];

int main() {
	int n, arr[10001];

	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &arr[i]);
	}
	dp[1] = arr[1];
	dp[2] = arr[1] + arr[2];
	for (int i = 3; i <= n; i++) {
		dp[i] = dp[i - 1];
		if (dp[i] < dp[i - 2] + arr[i]) {
			dp[i] = dp[i - 2] + arr[i];
		}
		if (dp[i] < dp[i - 3] + arr[i] + arr[i - 1]) {
			dp[i] = dp[i - 3] + arr[i] + arr[i - 1];
		}
	}

	printf("%d", dp[n]);

	return 0;
}