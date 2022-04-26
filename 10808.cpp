#include <iostream>
#include <string>
using namespace std;
string S;
int cnt[26];
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> S;
	for (char c : S) {
		cnt[c - 'a']++;
	}
	for (int x : cnt) {
		cout << x << " ";
	}
	return 0;
}