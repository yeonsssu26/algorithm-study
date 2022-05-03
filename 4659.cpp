#include <iostream>
#include <string>
#include <cstring>
using namespace std;
string s;
int alpha[26];
int cnt_cns, cnt_vwl; // 자음, 모음 개수
bool flag;

bool IsVowel(int idx) {
	return (idx == 0 || idx == 4 || idx == 8 || idx == 14 || idx == 20);
}

int main() {
	while (true) {
		cin >> s;
		if (s == "end") break;

		memset(alpha, 0, sizeof(alpha));
		cnt_cns = cnt_vwl = 0;
		flag = true;
		for (int i = 0; i < s.size(); i++) {
			int idx = s[i] - 'a';
			alpha[idx]++;

			// 모음이 3개 혹은 자음이 3개 연속으로 오면 안 된다.
			if (IsVowel(idx)) { cnt_cns = 0; cnt_vwl++; }
			else { cnt_cns++; cnt_vwl = 0; }
			if (cnt_cns == 3 || cnt_vwl == 3) flag = false;

			// 같은 글자가 연속적으로 두번 오면 안되나, ee 와 oo는 허용한다.
			if (i == 0) continue;
			if ((s[i - 1] == s[i]) && (idx != 4 && idx != 14)) flag = false;
		}

		// 모음(a,e,i,o,u) 하나를 반드시 포함하여야 한다.
		if (!alpha[0] && !alpha[4] && !alpha[8] && !alpha[14] && !alpha[20]) flag = false;

		cout << "<" << s << ">";
		if (flag) cout << " is acceptable." << "\n";
		else cout << " is not acceptable." << "\n";
	}
	return 0;
}