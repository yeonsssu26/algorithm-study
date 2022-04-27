#include <iostream>
#include <string>
using namespace std;
int N;
int alpha[26];
string S, ans = "";
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int n = 0; n < N; n++) {
		cin >> S;
		alpha[S[0] - 'a']++;
	}
	for (int i = 0; i < 26; i++) {
		if (alpha[i] >= 5) {
			ans += 'a' + i; // string에 아스키코드 더하면 => 아스키코드(숫자)가 문자로 변환되어서 더해짐
		}
	}
	if (ans.size() == 0) cout << "PREDAJA";
	else cout << ans;
	return 0;
}