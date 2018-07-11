#include<iostream>
#include<string>

using namespace std;

int dp[1000001];

int isDevideTwo(int n) {
	int num;
	num = n % 2;
	if (num == 0) {
		return 1;
	}
	else
		return 0;
}

int isDevideThree(int n) {
	int num;
	num = n % 3;
	if (num == 0) {
		return 1;
	}
	else
		return 0;
}

int main(){
	int num, i;

	cin >> num;
	dp[1] = 0;

	for (i = 2; i <= num; i++) {
		dp[i] = dp[i - 1] + 1;
		if (isDevideThree(i) == 1 && dp[i - 1] >= dp[i / 3]) {
			dp[i] = dp[i / 3] + 1;
		}
		else if (isDevideTwo(i) == 1 && dp[i - 1] >= dp[i / 2]) {
			dp[i] = dp[i / 2] + 1;
		}
		/*
		if (isDevideThree(i) == 0 && isDevideTwo(i) == 0) {
			dp[i] = dp[i - 1] + 1;
		}
		else if (isDevideThree(i) == 1 && dp[i - 1] < dp[i / 3]) {
			dp[i] = dp[i - 1] + 1;
		}
		else if (isDevideTwo(i) == 1 && dp[i - 1] < dp[i / 2]) {
			dp[i] = dp[i - 1] + 1;
		}
		else if (isDevideThree(i) == 1 && dp[i - 1] >= dp[i / 3]) {
			dp[i] = dp[i / 3] + 1;
		}
		else if (isDevideTwo(i) == 1 && dp[i - 1] >= dp[i / 2]) {
			dp[i] = dp[i / 2] + 1;
		}
		else if (isDevideThree(i) == 1 && isDevideTwo(i) == 1){
			if (dp[i / 2] < dp[i / 3]) {
				dp[i] = dp[i / 2] + 1;
			}
			else {
				dp[i] = dp[i / 3] + 1;
			}
		}
		*/
	}
	cout << dp[num];

	return 0;
}