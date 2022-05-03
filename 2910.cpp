// https://gdlovehush.tistory.com/452
#include <iostream>
#include <vector>
#include <map> // key�� �ߺ��� ������� ����
#include <algorithm>
using namespace std;
int N, C, num;
map<int, int> idx;	// {����, �ش� ���ڰ� ó�� ��Ÿ�� �ε���}
map<int, int> freq; // {����, �ش� ���ڰ� ��Ÿ�� ��}
vector<pair<int, int>> v;

bool Compare(pair<int, int>a, pair<int, int>b) {
	if (a.first == b.first) { // �ι�° ���� (�ε��� ��������)
		return idx[a.second] < idx[b.second];
	}
	return a.first > b.first; // ù��° ���� (�� ��������)
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> C;
	for (int n = 0; n < N; n++) {
		cin >> num;

		// num�� �󵵸� 1 ������Ų��
		freq[num]++;

		// num�� ó�� ���Դٸ�, �ش� �ε����� �����Ѵ�
		if (idx[num] == 0) {
			idx[num] = n + 1;
		}
	}

	// freq {����, ��} -> {��, ����}�� �ٲ㼭 ���Ϳ� ����
	for (auto x : freq) {
		//v.push_back({ x.second, x.first });	// ������� �ٸ����
		v.emplace_back(x.second, x.first);		// ������� �ٸ����
	}

	// �󵵸� �������� �����ϵ�, �ε��� ���� ����Ͽ� �����ϵ��� cmp �Լ� ����
	sort(v.begin(), v.end(), Compare);

	for (int i = 0; i < v.size(); i++) {
		for (int j = 0; j < v[i].first; j++) { // ������ ��(v[i].first)��ŭ ���� ���
			cout << v[i].second << " ";
		}
	}
	return 0;
}