#include <iostream>
#include <cmath>
using namespace std;
int main() {
	double a, b, c; cin >> a >> b >> c;			// �밢��(����), ����(����), �ʺ�(����)
	double x = sqrt(a * a / (b * b + c * c));	// x : ����
	cout << int(b * x) << " " << int(c * x);
	return 0;
}