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
			if (x != graph[r][c]) { // 다른 숫자를 발견하면
				len /= 2; // 길이를 반 줄인다
				res += "("; // 쪼개질 때 시작을 "("로 감싼다
				res += quard(_r, _c, len);
				res += quard(_r, _c + len, len);
				res += quard(_r + len, _c, len);
				res += quard(_r + len, _c + len, len);
				res += ")"; // 쪼개질 때 끝을 ")"으로 감싼다
				return res;
			}
		}
	}

	return string(1,x); // 모든 숫자가 같다면
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