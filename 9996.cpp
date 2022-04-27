#include <iostream>
#include <string>
using namespace std;
int N, star_idx = 0;
string pattern, file_name, pre, suf;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> pattern;

	star_idx = pattern.find("*");
	pre = pattern.substr(0, star_idx);
	suf = pattern.substr(star_idx + 1); // sub_idx + 1부터 끝까지
	
	for (int n = 0; n < N; n++) {
		cin >> file_name;
		if (pre.size() + suf.size() > file_name.size()) { 
			cout << "NE" << "\n";
		}
		else {
			if (pre == file_name.substr(0, pre.size()) && suf == file_name.substr(file_name.size() - suf.size())) { // 앞과 뒤가 일치하는지
				cout << "DA" << "\n";
			}
			else {
				cout << "NE" << "\n";
			}
		}
	}
	return 0;
}