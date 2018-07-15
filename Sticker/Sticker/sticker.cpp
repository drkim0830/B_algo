#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<string>
#include <algorithm>  

using namespace std;

int dp[100001][3];

int main() {
	int t, n, ans, arr[100001][2];
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) {
			scanf("%d", &arr[i][0]);
		}
		for (int i = 1; i <= n; i++) {
			scanf("%d", &arr[i][1]);
		}
		for (int i = 1; i <= n; i++) {
			dp[i][0] = max(dp[i - 1][0], max(dp[i - 1][1], dp[i - 1][2]));
			dp[i][1] = max(dp[i - 1][0], dp[i - 1][2]) + arr[i][0];
			dp[i][2] = max(dp[i - 1][0], dp[i - 1][1]) + arr[i][1];
		}
		ans = 0;
		for (int i = 1; i <= n; i++) {
			ans = max(max(ans, dp[i][0]), max(dp[i][1], dp[i][2]));
		}
		printf("%d\n", ans);
	}

	return 0;
}