// ref : https://sw-ko.tistory.com/88

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, cnt;
int arr[26][26];
bool visited[26][26] = { false, };
int dx[4] = { -1, 1,0,0};
int dy[4] = {0,0,-1,1};
vector<int> ans;

void dfs(int x, int y);

int main() {
	// input
	cin >> n;

	string line;
	for (int i = 0; i < n; i++) {
		cin >> line;
		for (int j = 0; j < n; j++) {
			arr[i][j] = line[j] - 48;
		}
	}

	// dfs
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] == 1 && visited[i][j] == false) {
				cnt = 0;
				dfs(i, j);
				ans.push_back(cnt);
			}
		}
	}

	// result
	sort(ans.begin(), ans.end());
	cout << ans.size() << endl;

	if (ans.size() == 0) {
		cout << 0;
	}
	else {
		for (int i = 0; i < ans.size(); i++) {
			cout << ans[i] << endl;
		}
	}
	return 0;
}

void dfs(int x, int y) {
	cnt++;
	visited[x][y] = true;

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || nx > n || ny < 0 || ny > n) {
			continue;
		}
		if (arr[nx][ny] == 1 && visited[nx][ny] == false) {
			dfs(nx, ny);
		}
	}
}