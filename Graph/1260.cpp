// [1260] DFS와 BFS
// 그래프 탐색 기초

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<bool> dfs_visited;
vector<int> order;

// 스택 개념 이용 (top에서 먼저 계속 탐색)
void dfs(int n, int v, vector<vector<bool>> &arr) {
	if (dfs_visited[v]) {
		return;
	}

	dfs_visited[v] = true;
	order.push_back(v);

	for (int i = 1; i <= n; i++) {
		// 스택 겸
		if (arr[v][i]) {
			dfs(n, i, arr);
		}
	}

}

// 큐 (먼저 들어온 것, 즉 자식들 먼저 탐색)
vector<int> bfs(int n, int v, vector<vector<bool>>& arr) {
	vector<bool> bfs_visited(n + 1, false);
	vector<int> ans;
	queue<int> q;

	q.push(v);
	bfs_visited[v] = true;

	while (!q.empty()) {
		int x = q.front();
		for (int i = 1; i <= n; i++) {
			if (arr[x][i] && !bfs_visited[i]) {
				q.push(i);
				bfs_visited[i] = true;
			}
		}
		ans.push_back(x);
		q.pop();
	}

	return ans;
}

int main() {
	int n, m, v, a, b;
	cin >> n >> m >> v;

	vector<vector<bool>> arr(n + 1, vector<bool>(n+1, false));
	dfs_visited.assign(n + 1, false);

	while (m--) {
		cin >> a >> b;
		// 양방향, 인접행렬
		arr[a][b] = true;
		arr[b][a] = true;
	}

	dfs(n, v, arr);
	for (auto i : order) {
		cout << i << ' ';
	}
	cout << '\n';

	for (auto i : bfs(n, v, arr)) {
		cout << i << ' ';
	}
	return 0;
}