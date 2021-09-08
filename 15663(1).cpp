#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
vector<int> numbers;					// ����ī�� (input)
vector<int> orders;						// �湮���� (output)
vector<bool> check;						// ���� level���� ������ ���� ���� �ʰ� �Ѵ�

void DFS(int level) {
	if (level == m) {
		for (int i = 0; i < m; i++)
			cout << orders[i] << " ";
		cout << "\n"; return;
	}

	bool visited[10001] = { false, };	// �湮����
	for (int i = 0; i < n; i++) {
		if (!visited[numbers[i]] && !check[i]) {
			check[i] = true;
			visited[numbers[i]] = true;
			orders.push_back(numbers[i]);

			DFS(level + 1);

			orders.pop_back();
			check[i] = false;
		}
	}
}

int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		int tmp; cin >> tmp; numbers.push_back(tmp);	// input numbers
		check.push_back(false);							// init visited
	}
	sort(numbers.begin(), numbers.end());

	DFS(0);

	return 0;
}