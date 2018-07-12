#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<algorithm>
#include<string>
#include<vector>

using namespace std;

struct Person {
	int age;
	string name;
};

bool cmp(const Person &u, const Person &v) {
	return u.age < v.age;
}

int main() {
	int n, age;
	string name;

	scanf("%d", &n);
	vector<Person> person(n);
	
	for(int i = 0; i < n; i++){
		cin >> person[i].age >> person[i].name;
	}
	
	stable_sort(person.begin(), person.end(), cmp);

	for (int i = 0; i< n; i++) {
		cout << person[i].age << " " << person[i].name << "\n";
	}

	return 0;
}