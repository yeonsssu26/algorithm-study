#include <iostream>
#include <algorithm>
using namespace std;

int GCD(int num1, int num2) {
	int big = max(num1, num2);
	int small = min(num1, num2);

	// 유클리드 호제법
	if (small == 0) return big;
	else return GCD(small, big % small);
}

int LCM(int num1, int num2, int gcd) {
	return num1 * num2 / gcd;
}

int main() {
	int testcase; cin >> testcase;
	for (int i = 0; i < testcase; i++) {
		int num1, num2; cin >> num1 >> num2;
		int gcd = GCD(num1, num2);
		int lcm = LCM(num1, num2, gcd);
		cout << lcm << "\n";
	}
	return 0;
}