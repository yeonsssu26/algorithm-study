// string to int vs int to string
#include <iostream>
#include <map>
#include <string>
using namespace std;
int N, M;
string S, Q;
map<int, string> m1;
map<string, int> m2;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;

	m1[0] = ""; m2[""] = 0;
	for (int n = 1; n <= N; n++) {
		cin >> S; // �̸�
		m1[n] = S;
		m2[S] = n;
	}
	for (int m = 1; m <= M; m++) {
		cin >> Q; // ����

		// atoi�� �ش��ϴ� ���ڿ��� ���ڸ� ���ڸ� ��ȯ�Ѵ�.
		// ���� �ش��ϴ� ���ڿ��� ���ڰ� �ƴ϶�� 0�� ��ȯ�Ѵ�.
		int idx = atoi(Q.c_str());
		if (idx == 0) { // �Է� : �̸� -> ��� : ����
			cout << m2[Q] << "\n";
		}
		else { // �Է� : ���� -> ��� : �̸�
			cout << m1[idx] << "\n";
		}
	}
	return 0;
}