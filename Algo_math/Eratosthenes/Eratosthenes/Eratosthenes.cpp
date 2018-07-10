#include<iostream>
#include<algorithm>

using namespace std;

int main() {
	int n;
	int p[100];
	int pn = 0;
	bool c[101] = { false };

	cin >> n;
	
	for (int i = 2; i <= n; i++) {
		if (c[i] == false) {
			p[pn++] = i;
			for (int j = i*i; j <= n; j += i) {
				c[j] = true;
			}
		}
	}
	for (int i = 0; i < 100; i++) {
		if (p[i] < 0) {
			continue;
		}
		cout << p[i] << " ";
	}


	return 0;
}