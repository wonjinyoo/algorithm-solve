// [2606] 바이러스 (advanced ver.)
// bfs 

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// 큐 이용 bfs (너비 우선 탐색)
int bfs(int n, vector<vector<int>>& arr) {
	int cnt = 0;
	queue<int> q;
	vector<bool> visited(n + 1, false);

	// 1에서 시작이므로
	q.push(1);
	visited[1] = true;

	while (!q.empty()) {
		int curr = q.front();

		for (auto i : arr[curr]) {
			if (visited[i]) continue;

			visited[i] = true;
			q.push(i);
			cnt++;
		}
		q.pop();
	}
	
	// 1번 컴퓨터 제외해야
	return cnt - 1;
}

int main() {
	int n, k, a, b;
	cin >> n >> k;
	
	vector<vector<int>> arr(n + 1, vector<int>(n + 1, 0));

	while (k--) {
		cin >> a >> b;
		// 인접리스트 형태로 구현
		arr[a].push_back(b);
		arr[b].push_back(a);
	}
	
	cout << bfs(n, arr);
	return 0;
}