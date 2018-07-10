#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

string convNegaTwo(long long num) {
	int mod;
	string ans;
	
	if (num == 0) {
		ans += to_string(0);
		return ans;
	}

	while (num != 1) {
		if (num > 0) {
			mod = num % -2;
			ans += to_string(mod);
			num /= -2;
		}
		else {
			if ((num % 2) != 0) {
				num *= -1;
				num += 2;
				mod = num % 2;
				ans += to_string(mod);
				num /= 2;
			}
			else {
				mod = num % 2;
				ans += to_string(mod);
				num /= -2;
			}
		}
	}
	ans += to_string(1);
	return ans;
}

int main() {
	long long num;
	string ans;

	scanf("%lld", &num);

	ans = convNegaTwo(num);
	reverse(ans.begin(), ans.end());

	cout << ans;

	return 0;
}