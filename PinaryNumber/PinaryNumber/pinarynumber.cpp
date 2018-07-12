#include<iostream>
#include<string>

using namespace std;

long long dp[101];

long long pinary(long long n) {
	if (n <= 2) {
		dp[1] = 1;
		dp[2] = 1;
		return dp[n];
	}
	else {
		if (dp[n] > 0) {
			return dp[n];
		}
		dp[n] = pinary(n - 2) + pinary(n - 1);
		return dp[n];
	}
}

int main() {
	long long num, output;

	cin >> num;
	output = pinary(num);
	cout << output;

	return 0;
}