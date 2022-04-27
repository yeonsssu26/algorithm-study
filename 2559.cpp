#include <iostream>
#include <algorithm>
#define MAX 100000
using namespace std;
int N, K, num, ans = -1e9; // ans를 최솟값으로 초기화할 때 주의할 것
int psum[MAX+1];
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> K;
	for (int n = 1; n <= N; n++) {
		cin >> num;
		psum[n] = psum[n - 1] + num; // 누적합
	}
	for (int i = K; i <= N; i++) {
		ans = max(ans, psum[i] - psum[i - K]); // 부분합
	}
	cout << ans;
	return 0;
}