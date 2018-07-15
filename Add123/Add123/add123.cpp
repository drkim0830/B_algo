#include<iostream>
#include<string>

using namespace std;

int dp[11];

int add123(int n) {
	if (n < 3) {
		dp[n] = n;
		return dp[n];
	}
	if (n == 3) {
		dp[n] = 4;
		return dp[n];
	}
	if (dp[n] > 0)
		return dp[n];
	dp[n] = add123(n - 1) + add123(n - 2) + add123(n - 3);
	return dp[n];
}

int main() {
	int num, n, result;

	cin >> num;

	for (int i = 0; i < num; i++) {
		cin >> n;
		result = add123(n);
		cout << result << "\n";
	}

	return 0;
}