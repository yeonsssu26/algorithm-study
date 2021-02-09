#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
	string words;
	getline(cin, words); // 공백도 입력받음

	stack<char> reverse_stack; // 순서를 바꿀 문자들을 저장

	bool tag = false;
	for (int i = 0; words.length(); i++) {

		// < > 태그 처리
		if (words[i] == '<') {
			while (!reverse_stack.empty()) {
				cout << reverse_stack.top(); // 출력
				reverse_stack.pop(); // pop
			}
			cout << words[i];
			tag = true;
		}
		else if (words[i] == '>') {
			cout << words[i];
			tag = false;
		}

		// < 안쪽은 무조건 그대로 출력
		else if (tag) cout << words[i];

		// > 바깥쪽이고 공백을 만난 경우에는 stack pop
		else if (!tag && words[i] == ' ') {
			while (!reverse_stack.empty()) {
				cout << reverse_stack.top();
				reverse_stack.pop();
			}
			cout << " ";
		}

		// 태그 바깥쪽은 reverse
		else reverse_stack.push(words[i]);

	}
	return 0;
}