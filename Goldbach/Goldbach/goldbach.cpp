#define _CRT_SECURE_NO_WARNINGS

#include<algorithm>
#include<iostream>
#include<string>

using namespace std;

string output(int n, int a, int b) {
	cout << n << " = " << a << " + " << b << "\n";
}

int main() {
	int n=1, a, b;

	while (n != 0) {
		scanf("%d", &n);


		output(n, a, b);
	}


	return 0;
}