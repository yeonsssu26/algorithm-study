#include <iostream>
#include <string>
#include <map>
using namespace std;
int T, N;
string val, key;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> T;
	while (T--) {
		cin >> N;
		map<string, int> m; // key, val_length
		for (int n = 0; n < N; n++) {
			cin >> val >> key; // val���� �Է¹����� map�� ���������� ����
			m[key]++; // key���� ������ val_length ����
		}
		long long ans = 1; // ����� ���� ������� Ŭ �� �ֱ� ������ long long���� �����ϴ� ���� ����
		for (auto x : m) {
			ans *= ((long long)x.second + 1);
		}
		ans--; // �ƹ��͵� ���� ����� �� ����
		cout << ans << "\n";
	}
	return 0;
}