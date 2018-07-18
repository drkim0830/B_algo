#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<vector>
#include<string>
#include<cmath>

using namespace std;
vector<int> vec;
int cnt;
bool dfs(int node);

int main() {
	int a, p;
	string s;

	scanf("%d %d", &a, &p);
	s = to_string(a);
	vec.push_back(a);
	
	while (1) {
		int sum= 0, temp;
		for (int i = 0; i < s.size(); i++) {
			temp = (int)s[i] - 48;
			sum += pow(temp, p);
		}
		if (dfs(sum)) {
			vec.push_back(sum);
		}
		else {
			break;
		}
		s = to_string(vec.back());
	}

	cout << cnt;

	return 0;
}

bool dfs(int node) {
	for (int i = 0; i < vec.size(); i++) {
		if (vec[i] == node) {
			cnt = i;
			return false;
		}
	}
	return true;
}