// 최소거리 -> BFS
#include <iostream>
#include <string>
#include <queue>
#include <algorithm>
#define MAX 100
using namespace std;
int N, M, ans = 1e9, res = 0;
char map[MAX+1][MAX+1];
bool visited[MAX + 1][MAX + 1];
int dist[MAX + 1][MAX + 1];
int dr[4] = { -1,1,0,0 };
int dc[4] = { 0,0,-1,1 };

void BFS(int _r, int _c) {
	queue <pair<int, int>> q; // (r,c)
	q.push({_r, _c});

	while (!q.empty()) {
		int r = q.front().first, c = q.front().second;
		q.pop();
		visited[r][c] = true;

		for (int i = 0; i < 4; i++) {
			int nr = r + dr[i], nc = c + dc[i];
			if (nr < 0 || N <= nr || nc < 0 || M <= nc) continue;
			if (visited[nr][nc]) continue;
			
			if (map[nr][nc] == '1') {
				q.push({ nr, nc });
				dist[nr][nc] = dist[r][c] + 1;
				visited[nr][nc] = true;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	for (int r = 0; r < N; r++) {
		string row; cin >> row;
		for (int c = 0; c < M; c++) {
			map[r][c] = row[c];
			dist[r][c] = row[c] - '0';
		}
	}
	BFS(0, 0);
	cout << dist[N-1][M-1];
	return 0;
}