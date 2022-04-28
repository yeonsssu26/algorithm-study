#include <iostream>
#include <string>
using namespace std;
int N;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	while (scanf("%d", &N) != EOF) {
		int res = 1, ans = 1;
		while (true) {
			if (res % N == 0) {
				cout << ans << "\n";
				break;
			}
			else {
				res = (res * 10) + 1;
				res %= N;
				ans++;
			}
		}
	}
	return 0;
}