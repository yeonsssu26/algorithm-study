#include <iostream>
#include <vector>
#include <numeric>
using namespace std;
int N, M, sum, ans = 0;
int arr[15001];
vector<int> v; // 조합 저장

// combination은 4개 이상 고를 때 쓰자
// 2개는 2중 for문, 3개는 3중 for문 쓰는 것을 추천
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