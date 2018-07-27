#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<vector>
#include<string>

using namespace std;

vector<vector<string>> vec(26);
string preorder_ans = "";
string inorder_ans = "";
string postorder_ans = "";

void input_data(int node);
void preorder(int node, int i);
void inorder(int node, int i);
void postorder(int node, int i);


int main() {
	int node;

	scanf("%d", &node);

	input_data(node);

	preorder(node, 0);
	inorder(node, 0);
	postorder(node, 0);

	cout << preorder_ans << "\n";
	cout << inorder_ans << "\n";
	cout << postorder_ans << "\n";

	return 0;
}

void input_data(int node) {
	for (int i = 0; i < node; i++) {
		string input_a, input_b, input_c;
		cin >> input_a >> input_b >> input_c;
		int a = (int)input_a[0] - 65;
		vec[a].push_back(input_b);
		vec[a].push_back(input_c);
	}
}

void preorder(int node, int i) {
	preorder_ans += char(i + 65);
	if (vec[i][0] != ".") {
		int base = (int)vec[i][0][0] - 65;
		preorder(node, base);
	}
	if (vec[i][1] != ".") {
		int base = (int)vec[i][1][0] - 65;
		preorder(node, base);
	}
}

void inorder(int node, int i) {
	if (vec[i][0] != ".") {
		int base = (int)vec[i][0][0] - 65;
		inorder(node, base);
	}

	inorder_ans += char(i + 65);

	if (vec[i][1] != ".") {
		int base = (int)vec[i][1][0] - 65;
		inorder(node, base);
	}
}

void postorder(int node, int i) {
	if (vec[i][0] != ".") {
		int base = (int)vec[i][0][0] - 65;
		postorder(node, base);
	}
	if (vec[i][1] != ".") {
		int base = (int)vec[i][1][0] - 65;
		postorder(node, base);
	}
	postorder_ans += char(i + 65);
}
