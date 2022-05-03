#include <iostream>
#define MAX 20
using namespace std;
int N, M, J, curr, ans = 0;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M >> J;
	int left = 1;
	int right = left + M - 1;
	for (int j = 0; j < J; j++) {
		cin >> curr;
		if (left > curr) {
			ans += left - curr;
			left = curr;
			right = left + M - 1;
		}
		else if (right < curr) {
			ans += curr - right;
			right = curr;
			left = right - M + 1;
		}
	}
	cout << ans;
	return 0;
}