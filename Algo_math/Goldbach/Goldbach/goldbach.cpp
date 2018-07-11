#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<string>

using namespace std;

bool c[1000001] = { false };

int* eratosthenes(int prime[], int n) {
	int pn = 0;
	for (int i = 2; i <= n; i++) {
		if (c[i] == false) {
			prime[pn++] = i;
			for (int j = i*2; j <= n; j += i) {
				c[j] = true;
			}
		}
	}
	return prime;
}

int* goldbach(int prime[], int n) {
	int a, b;
	int* result = new int[2];
	for (int i = 0; i < n; i++) {
		if (prime[i] < 0) {
			break;
		}
		a = prime[i];
		int temp = n - a;
		if (c[temp] == false) {
			result[0] = a;
			result[1] = temp;
			return result;
		}

		/* - 런타임 에러
		for (int j = i; j < n; j++) {
			if (prime[j] < 0) {
				break;
			}
			b = prime[j];
			if (n == (a + b)) {
				result[0] = a;
				result[1] = b;
				return result;
			}
		}
		*/
	}

	return result;
}

int main() {
	int n=1;
	int* result;

	int * prime = new int[1000000];
	prime = eratosthenes(prime, 1000000);
	while (1) {
		scanf("%d", &n);
		if (n == 0) {
			break;
		}
		
		result = goldbach(prime, n);
		
		if (result[0] > 0) {
			cout << n << " = " << result[0] << " + " << result[1] << "\n";
		}
		else {
			cout << "Goldbach's conjecture is wrong.\n";
		}
	}


	return 0;
}