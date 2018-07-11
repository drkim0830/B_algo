#include<iostream>
#include<string>

using namespace std;

/*
top-down
*/
int memo[1001];
int twobyn(int n) {
	if (n <= 2) {
		return n;
	}
	else {
		if (memo[n] > 0) {
			return memo[n];
		}
		memo[n] = (twobyn(n - 1) + twobyn(n - 2))%10007;
		return memo[n];
	}

}

int main() {
	int n, i, output;	// , dp[1001];
	cin >> n;
	/*
	bottom-up
	dp[1] = 1;
	dp[2] = 2;

	for (i = 3; i <= n; i++) {
		dp[i] = (dp[i - 1] + dp[i - 2]) % 10007;
	output = dp[n];
	}
	*/
	output = twobyn(n);
	cout << output;

	return 0;
}