#include <iostream>
#include <algorithm>
#define MAX 100000
using namespace std;
int N, K, num, ans = -1e9; // ans�� �ּڰ����� �ʱ�ȭ�� �� ������ ��
int psum[MAX+1];
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> K;
	for (int n = 1; n <= N; n++) {
		cin >> num;
		psum[n] = psum[n - 1] + num; // ������
	}
	for (int i = K; i <= N; i++) {
		ans = max(ans, psum[i] - psum[i - K]); // �κ���
	}
	cout << ans;
	return 0;
}