// DFS
#include <iostream>
#include <cstring>
#define MAX 50
using namespace std;
int T, M, N, K, ans;
int map[MAX + 1][MAX + 1];
int dr[4] = { 1,-1,0,0 };
int dc[4] = { 0,0,1,-1 };
bool visited[MAX + 1][MAX + 1];
void DFS(int r, int c) {
	visited[r][c] = true;
	for (int i = 0; i < 4; i++) {
		int nr = r + dr[i], nc = c + dc[i];
		if (nr < 0 || nc < 0 || nr >= N || nc >= M) continue;
		if (map[nr][nc] == 1 && !visited[nr][nc]) {
			DFS(nr, nc);
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> T;
	while (T--) {
		ans = 0;
		memset(visited, false, sizeof(visited));
		memset(map, 0, sizeof(map));

		cin >> M >> N >> K;
		for (int k = 0; k < K; k++) {
			int c, r; cin >> c >> r;
			map[r][c] = 1;
		}

		for (int r = 0; r < N; r++) {
			for (int c = 0; c < M; c++) {
				if (!visited[r][c] && map[r][c] == 1) {
					DFS(r, c);
					ans++;
				}
			}
		}
		cout << ans << "\n";
	}
	return 0;
}