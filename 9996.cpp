#include <iostream>
#include <string>
using namespace std;
int N, star_idx = 0;
string pattern, file_name, pre, suf;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> pattern;

	star_idx = pattern.find("*");
	pre = pattern.substr(0, star_idx);
	suf = pattern.substr(star_idx + 1); // sub_idx + 1���� ������
	
	for (int n = 0; n < N; n++) {
		cin >> file_name;
		if (pre.size() + suf.size() > file_name.size()) { 
			cout << "NE" << "\n";
		}
		else {
			if (pre == file_name.substr(0, pre.size()) && suf == file_name.substr(file_name.size() - suf.size())) { // �հ� �ڰ� ��ġ�ϴ���
				cout << "DA" << "\n";
			}
			else {
				cout << "NE" << "\n";
			}
		}
	}
	return 0;
}