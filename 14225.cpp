#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, num;
vector<int> numbers;
vector<int> vc;
vector<int> counts;

void DFS(int depth); // �κм����� ����� ���� ã�´�
int MIN(); // �κм����� ������ ���� �� ���� ���� ���� �ڿ����� ã�´�

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> num; numbers.push_back(num);
	}

	if (n == 1) {
		if (num == 1) {
			cout << 2;
		}
		else {
			cout << 1;
		}
	}
	else {
		for (m = 1; m <= n; m++) {
			DFS(0);
			vc.clear();
		}

		cout << MIN();
	}
	return 0;
}

void DFS(int depth) {
	if (vc.size() == m) {
		int sum = 0;
		for (auto i : vc) sum += i;
		counts.push_back(sum);
	}

	for (int i = depth; i < n; i++) {
		vc.push_back(numbers[i]);
		DFS(i + 1);
		vc.pop_back();
	}
}

int MIN() {
	sort(counts.begin(), counts.end());

	if (counts[0] > 1) return 1;
	else {
		for (int i = 0; i < counts.size() - 1; i++) { // return���� ����̾�� ��
			if (i == counts.size() - 2) {
				if (counts[i + 1] - counts[i] <= 1) {
					if (counts[i + 1] <= 0) return 1;
					else return counts[i + 1] + 1;
				}
				else return counts[i] + 1;
			}
			else {
				if (counts[i + 1] - counts[i] > 1) {
					if (counts[i + 1] <= 0) continue;
					else return counts[i] + 1;
				}
			}
		}
	}
}