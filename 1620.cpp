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
		cin >> S; // 이름
		m1[n] = S;
		m2[S] = n;
	}
	for (int m = 1; m <= M; m++) {
		cin >> Q; // 쿼리

		// atoi는 해당하는 문자열이 숫자면 숫자를 반환한다.
		// 만약 해당하는 문자열이 숫자가 아니라면 0을 반환한다.
		int idx = atoi(Q.c_str());
		if (idx == 0) { // 입력 : 이름 -> 출력 : 숫자
			cout << m2[Q] << "\n";
		}
		else { // 입력 : 숫자 -> 출력 : 이름
			cout << m1[idx] << "\n";
		}
	}
	return 0;
}