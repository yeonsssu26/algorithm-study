#include <iostream>
#include <string>
using namespace std;
string S, ans = "";
int cnt[128]; // 아스키코드 이용
int flag = 0;
char mid;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> S;
	
	for (char c : S) {
		cnt[c]++;
	}

	for (int i = 'Z'; i >= 'A'; i--) {
		if (cnt[i]) { // 0이 아니면
			if (cnt[i] & 1) { // 홀수이면
							  // 해당 숫자와 1을 비트연산으로 비교 => 홀수이면 1, 짝수이면 0
				mid = char(i);
				flag++;
				cnt[i]--;
			}

			if (flag == 2) break; // 팰린드롬을 만들 수 없음

			for (int j = 0; j < cnt[i]; j += 2) {
				ans = char(i) + ans;
				ans += char(i);
			}
		}
	}

	if (mid) {
		ans.insert(ans.begin() + ans.size() / 2, mid);
	}

	if (flag == 2) cout << "I'm Sorry Hansoo";
	else cout << ans;
	return 0;
}