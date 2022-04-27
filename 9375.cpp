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
			cin >> val >> key; // val값은 입력받지만 map에 저장하지는 않음
			m[key]++; // key값이 같으면 val_length 증가
		}
		long long ans = 1; // 경우의 수는 결과값이 클 수 있기 때문에 long long으로 선언하는 것이 좋음
		for (auto x : m) {
			ans *= ((long long)x.second + 1);
		}
		ans--; // 아무것도 없는 경우의 수 제외
		cout << ans << "\n";
	}
	return 0;
}