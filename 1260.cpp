#include <iostream>
#include <queue>
#define MAX 1000
using namespace std;

int N, M, V;
int graph[MAX + 1][MAX + 1];
bool visited[MAX + 1]; // DFS
queue<int> q; // BFS

void DFS(int curr) {
	cout << curr << " ";
	visited[curr] = true;
	for (int n = 1; n <= N; n++) {
		if (graph[curr][n] == 0 || visited[n]) {
			continue;
		}
		DFS(n);
	}
}
void BFS(int curr) {
	q.push(curr);
	visited[curr] = true;
	while (!q.empty()) {
		curr = q.front();
		cout << curr << " ";
		q.pop();

		for (int n = 1; n <= N; n++) {
			if (graph[curr][n] == 0 || visited[n]) {
				continue;
			}
			q.push(n);
			visited[n] = true;
		}
	}

}
int main() {
	cin >> N >> M >> V;
	for (int m = 1; m <= M; m++) {
		int x, y; cin >> x >> y;
		graph[x][y] = graph[y][x] = 1;
	}
	DFS(V); cout << endl;

	for (int i = 1; i <= N; i++) { // init
		visited[i] = false;
	}
	BFS(V);
	return 0;
}