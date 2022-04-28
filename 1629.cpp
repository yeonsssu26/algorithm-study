/*
[��������]
������Ģ : a^(n+m) = a^n * a^m
��ⷯ ���� : (a*b)%c = (a%c * b%c)%c
*/

#include <iostream>
using namespace std;
long long A, B, C;

long long calc(long long _A, long long _B) { // ���
	if (_B == 1) return _A % C;

	long long _C = calc(_A, _B / 2); // ��� �Լ��� ���� _B�� �������� ��� ������
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