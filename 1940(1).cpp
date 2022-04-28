#include <iostream>
#include <vector>
#include <numeric>
using namespace std;
int N, M, sum, ans = 0;
int arr[15001];
vector<int> v; // ���� ����

// combination�� 4�� �̻� �� �� ����
// 2���� 2�� for��, 3���� 3�� for�� ���� ���� ��õ
void combi(int start) {
	if (v.size() == 2) {
		sum = accumulate(v.begin(), v.end(), 0);
		if (sum == M) ans++;
		return;
	}

	for (int i = start; i < N; i++) {
		v.push_back(arr[i]);
		combi(i + 1);
		v.pop_back();
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	for (int n = 0; n < N; n++) {
		cin >> arr[n];
	}
	combi(0);
	cout << ans;
	return 0;
}