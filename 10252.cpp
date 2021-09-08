#include <iostream>
#include <stack>
using namespace std;

void solve() {
	int m, n; cin >> m >> n;
	stack<int> I, J;
	cout << 1 << "\n";
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (i == 0) {
				cout << "(" << i << "," << j << ")" << "\n";
			}
			else {
				if (j == 0) {
					I.push(i); J.push(j);
				}
				else {
					if (i % 2 == 0) {
						cout << "(" << i << "," << j << ")" << "\n";
					}
					else {
						cout << "(" << i << "," << n - j << ")" << "\n";
					}
				}
			}
		}
	}
	while (!I.empty() && !J.empty()) {
		cout << "(" << I.top() << "," << J.top() <<")" << "\n"; 
		I.pop(); J.pop();
	}
}

int main() {
	int T; cin >> T;
	while (T--) {
		solve();
	}
	return 0;
}