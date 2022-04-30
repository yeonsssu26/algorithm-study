#include <iostream>
#include <queue>
#include <tuple>
#define MAX 100
#define _CRT_SECURE_NO_WARNINGS
using namespace std;
int N, M, r, c;
int map[MAX + 1][MAX + 1], visited[MAX + 1][MAX + 1];
int dr[4] = { -1,1,0,0 };
int dc[4] = { 0,0,-1,1 };

void BFS(int _r, int _c) {
	queue<pair<int, int>> q;
	q.push({ _r,_c });
	visited[_r][_c] = 1;
	while (!q.empty()) {
		tie(r, c) = q.front(); q.pop();
		for (int i = 0; i < 4; i++) {
			int nr = r + dr[i], nc = c + dc[i];
			if (nr < 0 || nc < 0 || nr >= N || nc >= M || map[nr][nc] == 0) continue;
			if (visited[nr][nc]) continue;
			visited[nr][nc] = visited[r][c] + 1;
			q.push({ nr, nc });
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	scanf("%d %d", &N, &M);
	for (int r = 0; r < N; r++) {
		for (int c = 0; c < M; c++) {
			scanf("%1d", &map[r][c]); // https://yoonwould.tistory.com/18
		}
	}
	BFS(0, 0);
	printf("%d", visited[N - 1][M - 1]);
	return 0;
}