#include <iostream>
#include <string>
#include <stack>
using namespace std;
int N, ans = 0;
string S;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	while (N--) {
		cin >> S;
		
		stack<char> st;
		for (int i = 0; i < S.size(); i++) {
			if (st.empty()) { 
				st.push(S[i]); 
				continue;
			}

			if (S[i] == st.top()) {
				st.pop();
			}
			else {
				st.push(S[i]);
			}
		}
		
		if (st.empty()) ans++;
	}
	cout << ans;
	return 0;
}