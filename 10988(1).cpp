#include <iostream>
#include <string>
using namespace std;
string S;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> S;
	int len = S.size();
	int mid = len / 2;
	bool flag = true;
	for (int i = 0; i < mid; i++) {
		if (S[i] != S[len - i - 1]) {
			flag = false;
		}
	}

	if (flag) {
		cout << 1;
	}
	else {
		cout << 0;
	}
	return 0;
}