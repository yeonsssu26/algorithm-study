/*
[선행지식]
지수법칙 : a^(n+m) = a^n * a^m
모듈러 성질 : (a*b)%c = (a%c * b%c)%c
*/

#include <iostream>
using namespace std;
long long A, B, C;

long long calc(long long _A, long long _B) { // 재귀
	if (_B == 1) return _A % C;

	long long _C = calc(_A, _B / 2); // 재귀 함수로 지수 _B를 절반으로 계속 나눠서
	_C = (_C * _C) % C;
	if (_B & 1) return (_C * A) % C;
	else return _C;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> A >> B >> C;
	cout << calc(A, B);
	return 0;
}