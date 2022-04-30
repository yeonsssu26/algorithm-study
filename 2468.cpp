#include <iostream>
#include <algorithm>
#include <cstring>
#define MAX 100
using namespace std;
int N, max_h = -1, ans = 1, res; // ans = 1인 이유 : "아무 지역도 물에 잠기지 않을 수도 있다"는 조건 때문
int graph[MAX + 1][MAX + 1];
bool visited[MAX + 1][MAX + 1];
int dr[4] = { 1, -1, 0, 0 };
int dc[4] = { 0, 0, 1, -1 };

void DFS(int r, int c, int h) {
	visited[r][c] = true;
	for (int i = 0; i < 4; i++) {
		int nr = r + dr[i], nc = c + dc[i];
		if (nr < 0 || nc < 0 || nr >= N || nc >= N) continue;
		if (visited[nr][nc]) continue;
		if (graph[nr][nc] > h) DFS(nr, nc, h);
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int r = 0; r < N; r++) {
		for (int c = 0; c < N; c++) {
			cin >> graph[r][c];
			max_h = max(max_h, graph[r][c]);
		}
	}
	//cout << "max height : " << max_h << endl;
	//cout << "res" << "\t" << "ans" << endl;

	for (int h = 1; h <= max_h; h++) {
		res = 0;
		memset(visited, false, sizeof(visited));
		for (int r = 0; r < N; r++) {
			for (int c = 0; c < N; c++) {
				if (visited[r][c]) continue;
				if (graph[r][c] > h) {
					res++;
					DFS(r, c, h);
				}
			}
		}
		//cout << res << "\t" << ans << endl;
		ans = max(ans, res);
	}
	cout << ans;
	return 0;
}