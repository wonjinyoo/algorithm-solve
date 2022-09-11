// [2606] 바이러스 (advanced ver.)
// dfs 

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// 스택이용 dfs (깊이 우선)
int dfs(int n, vector<vector<int>>& arr) {
	int cnt = 0;
	stack<int> stck;
	vector<bool> visited(n+1, false);

	// 1에서 시작하는 거니까
	visited[1] = true;
	stck.push(1);
	
	while (!stck.empty()) {
		int curr = stck.top();
		stck.pop();

		for (auto i : arr[curr]) {
			if (visited[i]) continue;

			visited[i] = true;
			stck.push(i);
			cnt++;
		}
	}

	// 1은 제외
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
	
	cout << dfs(n, arr);
	return 0;
}