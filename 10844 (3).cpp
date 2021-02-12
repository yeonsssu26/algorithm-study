// 윈도우 슬라이딩 알고리즘
#include <iostream>
#define MOD 1000000000
using namespace std;
int main() {
	int n, ans = 9; cin >> n;
	int window[2][12] = { 0, };

	for (int j = 2; j < 11; j++) {
		window[1][j] = 1;
	}

	for (int i = 2; i <= n; i++) {
		ans = 0;
		for (int j = 1; j < 11; j++) {
			window[i % 2][j] = (window[(i - 1) % 2][j - 1] + window[(i - 1) % 2][j + 1]) % MOD;
			ans = (ans + window[i % 2][j]) % MOD;
		}
	}

	cout << ans;
	return 0;
}