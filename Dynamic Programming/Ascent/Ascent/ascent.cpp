#include <iostream>

using namespace std;

int dp[1001][10];

int main() {
	int num;
	int mod = 10007;
	cin >> num;

	for (int i = 0; i <= 9; i++) {
		dp[1][i] = 1;
	}
	for (int i = 2; i <= num; i++) {
		for (int j = 0; j <= 9; j++) {
			for (int k = 0; k <= j; k++) {
				dp[i][j] += dp[i - 1][k];
				dp[i][j] %= mod;
			}
		}
	}
	long long ans = 0;
	for (int i = 0; i <= 9; i++) {
		ans += dp[num][i];
	}
	ans %= mod;

	cout << ans;

	return 0;
}