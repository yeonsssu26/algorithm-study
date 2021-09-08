// �ߺ����� �����ϴ� ���� (ex. 1,7,9,9)
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void DFS(int level, int n, int r, vector<int> numbers, vector<int> orders) {
	if (level == r) {
		for (int i = 0; i < r; i++)
			cout << orders[i] << " ";
		cout << "\n";
		return;
	}

	int tmp = 0;									// tmp�� ���� ��
	for (int i = 0; i < n; i++) {
		if (tmp != numbers[i]) {
			tmp = numbers.at(i); orders.push_back(tmp);
			DFS(level + 1, n, r, numbers, orders);
			orders.pop_back();
		}
	}

	/*for (int i = 0; i < n; i++) {					// tmp�� ���� �� (tmp�� ���� ���� ���ϸ� �����ϱ� ����)
		orders.push_back(numbers.at(i));
		DFS(level + 1, n, r, numbers, orders);
		orders.pop_back();
	}*/
}

int main() {
	int n, r; cin >> n >> r;

	vector<int> numbers;	// �־��� ����ī�� (input)
	for (int i = 0; i < n; i++) {
		int tmp; cin >> tmp; numbers.push_back(tmp);
	}

	vector<int> orders;		// �ߺ����� (output)
	sort(numbers.begin(), numbers.end());

	DFS(0, n, r, numbers, orders);

	return 0;
}