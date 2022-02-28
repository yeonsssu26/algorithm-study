#include <iostream>
#include <map>
#include <vector>
#include <cmath>
#include <algorithm>
#define MAX 500000
using namespace std;

int N;
double sum = 0;
int arr[MAX + 1];
map<int, int> m;

bool compare(pair<int, int>& a, pair<int, int>& b) {
	return a.second > b.second;
}

int main() {
	cin >> N;
	for (int n = 0; n < N; n++) {
		cin >> arr[n];
		sum += arr[n];
		m[arr[n]] = 0;
	}

	// ������ (�Ҽ��� �Ʒ� ù°�ڸ����� �ݿø�)
	double avg = round((sum / N));
	if (avg == -0) {
		cout << 0 << endl;
	}
	else {
		cout << avg << endl;
	}

	// �߾Ӱ� (N�� Ȧ��)
	sort(arr, arr + N);
	cout << arr[N / 2] << endl;

	// �ֺ� (������ �� ��� �ι�°�� ���� �� ���
	if (N == 1) {
		cout << arr[0] << endl;
	}
	else {
		for (int n = 0; n < N; n++) {
			m[arr[n]]++;
		}
		//for (auto x : m) { // for check
		//	cout << x.first << ", " << x.second << endl;
		//}
		vector<pair<int, int>> v;
		for (auto& it : m) {
			v.push_back(it);
		}
		sort(v.begin(), v.end(), compare);
		//for (auto& it : v) { // for check
		//	cout << it.first << ", " << it.second << endl;
		//}
		if (v[0].second == v[1].second) {
			cout << v[1].first << endl;
		}
		else {
			cout << v[0].first << endl;
		}
	}

	// ����
	cout << arr[N - 1] - arr[0] << endl;
	return 0;
}