#include <iostream>
#include <algorithm> // reverse ÇÔ¼ö
#include <string>
using namespace std;
string S1, S2;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> S1;
	S2 = S1;
	reverse(S2.begin(), S2.end());
	if (S1 == S2) cout << 1;
	else cout << 0;
	return 0;
}