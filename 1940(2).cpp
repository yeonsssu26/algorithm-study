#include <iostream>
#include <algorithm>
using namespace std;
int N, M, ans = 0;
int arr[150001];
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	for (int n = 0; n < N; n++) {
		cin >> arr[n];
	}
	sort(arr, arr + N);
	if (M > 200000) cout << 0 << "\n";
	else {
		for (int i = 0; i < N; i++) {
			for (int j = i + 1; j < N; j++) {
				if (arr[i] + arr[j] == M) ans += 1;
			}
		}
		cout << ans << "\n";
	}
	return 0;
}