#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cmath>
#include <float.h>

using namespace std;

int prefer[501];

double calc_mean(int n, int k);
double calc_dispersion(int sp, int k, double mean);

int main() {
	int n, k;
	scanf("%d %d", &n, &k);

	for (int i = 0; i < n; i++) {
		long a;
		scanf("%ld", &a);
		prefer[i] = a;
	}
	
	double deviation = calc_mean(n, k);

	cout << deviation;


	return 0;
}

double calc_mean(int n, int k) {
	double min = DBL_MAX;
	double mean, dispersion, deviation;

	for (int i = 0; i < n; i++) {
		double sum = 0;
		for (int j = i; j < n; j++) {
			sum	+= prefer[j];
			if (((j - i)+1) >= k) {
				mean = sum / ((j-i)+1);
				dispersion = calc_dispersion(i, ((j - i) + 1), mean);
				deviation = sqrt(dispersion);
				if (min > deviation) {
					min = deviation;
				}
			}
		}
	}

	return min;
}

double calc_dispersion(int sp, int k, double mean) {
	double sum = 0;
	for (int i = sp; i < sp + k; i++) {
		sum += pow((prefer[i] - mean),2);
	}
	double dispersion = sum / k;

	return dispersion;
}