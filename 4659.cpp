#include <iostream>
#include <string>
#include <cstring>
using namespace std;
string s;
int alpha[26];
int cnt_cns, cnt_vwl; // ����, ���� ����
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

			// ������ 3�� Ȥ�� ������ 3�� �������� ���� �� �ȴ�.
			if (IsVowel(idx)) { cnt_cns = 0; cnt_vwl++; }
			else { cnt_cns++; cnt_vwl = 0; }
			if (cnt_cns == 3 || cnt_vwl == 3) flag = false;

			// ���� ���ڰ� ���������� �ι� ���� �ȵǳ�, ee �� oo�� ����Ѵ�.
			if (i == 0) continue;
			if ((s[i - 1] == s[i]) && (idx != 4 && idx != 14)) flag = false;
		}

		// ����(a,e,i,o,u) �ϳ��� �ݵ�� �����Ͽ��� �Ѵ�.
		if (!alpha[0] && !alpha[4] && !alpha[8] && !alpha[14] && !alpha[20]) flag = false;

		cout << "<" << s << ">";
		if (flag) cout << " is acceptable." << "\n";
		else cout << " is not acceptable." << "\n";
	}
	return 0;
}