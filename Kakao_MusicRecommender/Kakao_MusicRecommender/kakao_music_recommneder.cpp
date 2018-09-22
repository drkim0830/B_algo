#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>

using namespace std;

int parent[100001];
int singer[100001];

vector<int> vec[100001];

void calc_recommend(long t, int p, long s);

int main() {
	int n, k;
	long j;
	scanf("%d %d %ld", &n, &k, &j);
	
	//input Parent Number
	for (int i = 2; i <= n; i++) {
		int p_num;
		scanf("%d", &p_num);
		parent[i] = p_num;
		vec[p_num].push_back(i);
	}
	
	//input Singer Number
	for (int i = 1; i <= n; i++) {
		int s_num;
		scanf("%d", &s_num);
		parent[i] = s_num;
	}

	//input algo_data
	while (k--) {
		int p;
		long t, s;
		scanf("%ld %d %ld", &t, &p, &s);
		calc_recommend(t, p, s);

	}
	return 0;
}

void calc_recommend(long t, int p, long s) {
	
}