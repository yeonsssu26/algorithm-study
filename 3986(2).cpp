#include <iostream>
#include <string>
#include <stack>
using namespace std;
int N, ans = 0;
string S;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	while (N--) {
		cin >> S;

		stack<char> stk;
		for (char c : S) {
			if (stk.size() && stk.top() == c) stk.pop();
			else stk.push(c);
		}

		if (stk.empty()) ans++;
	}
	cout << ans;
	return 0;
}