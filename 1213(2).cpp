#include <iostream>
#include <string>
using namespace std;
string S, ans = "";
int cnt[128]; // �ƽ�Ű�ڵ� �̿�
int flag = 0;
char mid;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> S;
	
	for (char c : S) {
		cnt[c]++;
	}

	for (int i = 'Z'; i >= 'A'; i--) {
		if (cnt[i]) { // 0�� �ƴϸ�
			if (cnt[i] & 1) { // Ȧ���̸�
							  // �ش� ���ڿ� 1�� ��Ʈ�������� �� => Ȧ���̸� 1, ¦���̸� 0
				mid = char(i);
				flag++;
				cnt[i]--;
			}

			if (flag == 2) break; // �Ӹ������ ���� �� ����

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