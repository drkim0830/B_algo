#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

void calc_award(int a, int b);

int award_2017[6] = { 500, 300, 200, 50, 30, 10 };
int score_2017[6] = { 1, 3, 6, 10, 15, 21 };
int award_2018[5] = { 512, 256, 128, 64, 32 };
int score_2018[5] = { 1, 3, 7, 15, 31 };

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int a, b;
		scanf("%d %d", &a, &b);
		calc_award(a, b);
	}

	return 0;
}

void calc_award(int a, int b) {
	int award = 0;
	for (int i = 0; i < 6; i++) {
		if (a == 0) {
			break;
		}
		if (a <= score_2017[i]) {
			award += award_2017[i];
			break;
		}
	}
	for (int i = 0; i < 5; i++) {
		if (b == 0) {
			break;
		}
		if (b <= score_2018[i]) {
			award += award_2018[i];
			break;
		}
	}

	cout << award * 10000 << "\n";
}