#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

/*
bool change = false;
for (int i=1; i<=n+1; i++) {
	change = false;
	for (int j=1; j<=n-i; j++) {
		if (a[j] > a[j+1]) {
		change = true;
		swap(a[j], a[j+1]);
		}
	}
	if (change == false) {
		break;
	}
}
cout << i << '\n';
*/

int main() {
	int n, input;
	scanf("%d", &n);
	vector<int> a(n+1);
	for (int i = 1; i < a.size(); i++) {
		scanf("%d", &input);
		a[i] = input;
	}
	bool change = false;
	for (int i = 1; i <= n + 1; i++) {
		change = false;
		for (int j = 1; j <= n - i; j++) {
			if (a[j] > a[j + 1]) {
				change = true;
				swap(a[j], a[j + 1]);
			}
		}
		if (change == false) {
			break;
		}
	}
	cout << i << '\n';


	return 0;
}