#include <iostream>
#include <cmath>
using namespace std;
int main() {
	double a, b, c; cin >> a >> b >> c;			// 대각선(길이), 높이(비율), 너비(비율)
	double x = sqrt(a * a / (b * b + c * c));	// x : 비율
	cout << int(b * x) << " " << int(c * x);
	return 0;
}