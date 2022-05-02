#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#define MAX 100
using namespace std;
int M, N, K, cnt = 1;
int graph[MAX + 1][MAX + 1];
int dr[4] = { 1, -1, 0, 0 };
int dc[4] = { 0, 0, 1, -1 };
vector<int> ans;

int DFS(int r, int c) {
	graph[r][c] = -1;
	int cnt = 1;
	for (int i = 0; i < 4; i++) {
		int nr = r + dr[i], nc = c + dc[i];
		if (nr < 0 || nc < 0 || nr >= M || nc >= N) continue;
		if (graph[nr][nc] == -1) continue;
		cnt += DFS(nr, nc);
	}
	return cnt;
}

int main() {
	cin >> M >> N >> K;
	while (K--) {
		int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
		for (int c = x1; c < x2; c++) {
			for (int r = y1; r < y2; r++) {
				graph[r][c] = -1;
			}
		}
	}

	for (int r = 0; r < M; r++) {
		for (int c = 0; c < N; c++) {
			if (graph[r][c] != -1) {
				ans.push_back(DFS(r, c));
			}
		}
	}

	sort(ans.begin(), ans.end());
	cout << ans.size() << "\n";
	for (int elem : ans) cout << elem << " ";
	return 0;
}