#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
	string input_data, m;
	stack<int> left, right;
	int i;
	string command;
	char temp;

	getline(cin,input_data);
	for (i = 0; i < input_data.size(); i++) {
		left.push(input_data[i]);
	}
	getline(cin, m);
	int n = stoi(m);
	for (i = 0; i < n; i++) {
		getline(cin,command);
		if (command == "L") {
			if (left.size() != 0) {
				temp = left.top();
				right.push(temp);
				left.pop();
			}
		}
		if (command == "D") {
			if (right.size() != 0) {
				temp = right.top();
				left.push(temp);
				right.pop();
			}
		}
		if (command == "B") {
			if(left.size() != 0)
				left.pop();
		}
		if (command[0] == 'P') {
			temp = command[2];
			left.push(temp);
		}
	}
	int left_size = left.size();
	for (i = 0; i < left_size; i++) {
		temp = left.top();
		right.push(temp);
		left.pop();
	}
	int right_size = right.size();
	for (i = 0; i < right_size; i++) {
		temp = right.top();
		cout << temp;
		right.pop();
	}
	return 0;
}