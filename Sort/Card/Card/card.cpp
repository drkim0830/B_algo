#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main() {
	int n, ans_cnt, cnt;
	long long num, ans;

	scanf("%d", &n);
	vector<long long> v;
	while (n--) {
		scanf("%lld", &num);
		v.push_back(num);
	}
	sort(v.begin(), v.end());

	ans = v[0];
	ans_cnt = 1;
	cnt = 1;
	for (int i = 1; i < v.size(); i++) {
		if (v[i] == v[i - 1]) {
			cnt++;
		}
		else {
			cnt = 1;
		}
		if (ans_cnt < cnt) {
			ans_cnt = cnt;
			ans = v[i];
		}
	}
	cout << ans;

	return 0;
}