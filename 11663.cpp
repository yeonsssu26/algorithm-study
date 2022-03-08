#include <iostream>
#include <algorithm>
#define MAX 100000
using namespace std;
int N, M;
long long arr[MAX + 1];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> N >> M;
	for (int n = 0; n < N; n++) {
		cin >> arr[n];
	}
	sort(arr, arr + N);

	while (M--) {
		long long X, Y; cin >> X >> Y;
		long long start = 0, end = N - 1, ans1 = 0, ans2 = 0;
		while (start <= end) {
			long long mid = (start + end) / 2;
			if (X <= arr[mid]) {
				//ans1 = mid;
				end = mid - 1;
			}
			else {
				start = mid + 1;
			}
		}
		ans1 = start;
		start = 0; end = N - 1;
		while (start <= end) {
			long long mid = (start + end) / 2;
			if (arr[mid] <= Y) {
				//ans2 = mid;
				start = mid + 1;
			}
			else {
				end = mid - 1;
			}
		}
		ans2 = end;
		cout << ans2 - ans1 + 1 << "\n";
		//cout << "ans1 : " << ans1 << "\t" << "ans2 : " << ans2 << endl;
	}
	return 0;
}