#include <iostream>
#include <string>
#define MAX 64
using namespace std;
int N;
char graph[MAX + 1][MAX + 1];

string quard(int _r, int _c, int len) {
	if (len == 1) return string(1, graph[_r][_c]);
	
	char x = graph[_r][_c];
	string res = "";
	for (int r = _r; r < _r + len; r++) {
		for (int c = _c; c < _c + len; c++) {
			if (x != graph[r][c]) { // �ٸ� ���ڸ� �߰��ϸ�
				len /= 2; // ���̸� �� ���δ�
				res += "("; // �ɰ��� �� ������ "("�� ���Ѵ�
				res += quard(_r, _c, len);
				res += quard(_r, _c + len, len);
				res += quard(_r + len, _c, len);
				res += quard(_r + len, _c + len, len);
				res += ")"; // �ɰ��� �� ���� ")"���� ���Ѵ�
				return res;
			}
		}
	}

	return string(1,x); // ��� ���ڰ� ���ٸ�
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int r = 0; r < N; r++) {
		string row; cin >> row;
		for (int c = 0; c < N; c++) {
			graph[r][c] = row[c];
		}
	}
	cout << quard(0, 0, N);
	return 0;
}