#include <iostream>
#include <string>
#include <queue>

using namespace std;

void output_func(queue<int> output) {
	int i, output_size;

	cout << "<";
	output_size = output.size();
	for (i = 1; i <= output_size; i++) {
		if (i == output_size) {
			cout << output.front();
			output.pop();
		}
		else {
			cout << output.front() << ", ";
			output.pop();
		}
	}
	cout << ">";

}

int main() {
	int n, m, i, output_size;
	queue<int> jose_q, output;

	cin >> n >> m;

	for (i = 1; i <= n; i++) {
		jose_q.push(i);
	}

	while (n--) {
		for (i = 1; i <= m; i++) {
			if (i == m) {
				output.push(jose_q.front());
				jose_q.pop();
			}
			else {
				jose_q.push(jose_q.front());
				jose_q.pop();
			}
		}
	}
	
	output_func(output);

	return 0;
}