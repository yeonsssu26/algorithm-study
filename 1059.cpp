#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int L; cin >> L;
	vector<int> v(L);
	for (int i = 0; i < L; i++) {
		cin >> v[i];
	}
	sort(v.begin(), v.end());

	bool is_same = false;
	int n; cin >> n;
	for (int i = 0; i < L; i++) {
		if(v[i] == n){
			is_same = true;
			break;
		}
	}

	if (is_same) {
		cout << 0;
	}
	else {
		int start = 0, end = 0;
		for (int i = 0; i < L; i++) {
			if (v[i] > n) {
				start = v[i - 1];
				end = v[i];
				break;
			}
		}

		int ans = 0;
		for (int i = start + 1; i < end; i++) {
			for (int j = i + 1; j < end; j++) {
				if (i <= n && n <= j) {
					ans++;
				}
			}
		}
		cout << ans;
	}
	return 0;
}