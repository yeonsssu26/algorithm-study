#include <iostream>
#include <algorithm>
using namespace std;
int A, B, C, ans = 0, max_end = 0;
int arr[101];
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> A >> B >> C;
	for (int i = 0; i < 3; i++) {
		int s, e; cin >> s >> e;
		max_end = max(max_end, e);
		for (int j = s; j < e; j++) {
			arr[j]++;
		}
	}

	for (int i = 1; i < max_end; i++) {
		if (arr[i] == 1) {
			ans += A;
		}
		else if (arr[i] == 2) {
			ans += B * 2;
		}
		else if (arr[i] == 3) {
			ans += C * 3;
		}
	}
	cout << ans;
	return 0;
}