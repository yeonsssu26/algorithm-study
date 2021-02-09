#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
	string words;
	getline(cin, words); // ���鵵 �Է¹���

	stack<char> reverse_stack; // ������ �ٲ� ���ڵ��� ����

	bool tag = false;
	for (int i = 0; words.length(); i++) {

		// < > �±� ó��
		if (words[i] == '<') {
			while (!reverse_stack.empty()) {
				cout << reverse_stack.top(); // ���
				reverse_stack.pop(); // pop
			}
			cout << words[i];
			tag = true;
		}
		else if (words[i] == '>') {
			cout << words[i];
			tag = false;
		}

		// < ������ ������ �״�� ���
		else if (tag) cout << words[i];

		// > �ٱ����̰� ������ ���� ��쿡�� stack pop
		else if (!tag && words[i] == ' ') {
			while (!reverse_stack.empty()) {
				cout << reverse_stack.top();
				reverse_stack.pop();
			}
			cout << " ";
		}

		// �±� �ٱ����� reverse
		else reverse_stack.push(words[i]);

	}
	return 0;
}