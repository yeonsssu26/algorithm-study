// DFS : 시간초과

#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
#define MAX 100
using namespace std;

int N, M;
string arr[MAX + 1][MAX + 1];
bool visited[MAX + 1][MAX + 1];
int dist[MAX + 1][MAX + 1]; // 시작점으로부터의 거리 표시
queue<pair<int, int>> q;
int dy[4] = { 1, 0, -1, 0 };
int dx[4] = { 0, 1, 0, -1 };

void BFS(int y, int x) { // y : 행, x : 열
	visited[y][x] = true;
	q.push(make_pair(y, x));

	while (!q.empty()) {
		int y = q.front().first, x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i], nx = x + dx[i];
		
			if (0 <= ny && ny <= N - 1 && 0 <= nx && nx <= M - 1) {
				if (!visited[ny][nx] && arr[ny][nx] == "1") {
					dist[ny][nx] = dist[y][x] + 1;
					visited[ny][nx] = true;
					q.push(make_pair(ny, nx));
				}
			}
		}
	}
}

int main() {
	cin >> N >> M;
	for (int n = 0; n < N; n++) {
		string row; cin >> row;
		for (int m = 0; m < M; m++) {
			arr[n][m] = row[m];
		}
	}
	BFS(0, 0);
	cout << dist[N - 1][M - 1] + 1;
	return 0;
}