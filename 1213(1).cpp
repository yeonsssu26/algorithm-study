#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string S, ans = "", rev = "";
int alpha[26];
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> S;
	for (int i = 0; i < S.size(); i++) {
		alpha[S[i] - 'A']++;
	}
	int flag = 0; // flag : 0 or 1 => ok
	string mid = "";
	for (int i = 0; i < 26; i++) {
		if (alpha[i] % 2 != 0) {
			flag++;
			mid = 'A' + i;
		}
	}
	if (flag > 1) {
		cout << "I'm Sorry Hansoo";
	}
	else {
		for (int i = 0; i < 26; i++) {
			if (alpha[i] != 0) {
				for (int j = 0; j < alpha[i] / 2; j++) {
					ans += char('A' + i);
				}
			}
		}
		rev = ans;
		reverse(rev.begin(), rev.end());

		if (flag == 1) {
			ans += mid;
		}

		ans += rev;
		cout << ans;
	}
	return 0;
}