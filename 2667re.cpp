#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
#define MAX 25
using namespace std;

int N;
int dy[4] = {1, 0, -1, 0};
int dx[4] = {0, 1, 0, -1};
bool visited[MAX + 1][MAX + 1];
queue<pair<int, int>> q;
string map[MAX + 1][MAX + 1];
vector<int> answers;

int BFS(int y, int x, int cnt) { // y : За, x : ї­
	q.push(make_pair(y, x));
	visited[y][x] = true;

	while (!q.empty()) {
		int y = q.front().first, x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i], nx = x + dx[i];
			if (0 <= ny && ny <= N - 1 && 0 <= nx && nx <= N - 1) {
				if (!visited[ny][nx] && map[ny][nx] == "1") {
					cnt++;
					q.push(make_pair(ny, nx));
					visited[ny][nx] = true;
				}

			}
		}
	}
	return cnt;
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		string row; cin >> row;
		for (int j = 0; j < N; j++) {
			map[i][j] = row[j];
		}
	}
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] == "1" && !visited[i][j]) {
				int res = BFS(i, j, 1);
				if (res != 0) {
					answers.push_back(res);
				}
			}
		}
	}

	sort(answers.begin(), answers.end());
	cout << answers.size() << "\n";
	for (int i = 0; i < answers.size(); i++) {
		cout << answers[i] << "\n";
	}
	return 0;
}