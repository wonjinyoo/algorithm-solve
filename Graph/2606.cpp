// [2606] 바이러스
// 왠지 야매(?)로 맞은 느낌..

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// 감염된 컴퓨터 번호 넣는 용도
vector<int> res;
vector<bool> visited;

void virus(int n, int curr, vector<vector<int>> &arr) {
	if (curr == n + 1) {
		return;
	}

	for (int i = 0; i < arr[curr].size(); i++) {
		if (visited[arr[curr][i]]) continue;
		
		res.push_back(arr[curr][i]);
		visited[arr[curr][i]] = true;
		virus(n, arr[curr][i], arr);
	}
}

int main() {
	int n, k, a, b;
	cin >> n >> k;
	
	vector<vector<int>> arr(n + 1, vector<int>(n + 1, 0));
	visited.assign(n + 1, false);

	while (k--) {
		cin >> a >> b;
		// 인접리스트 형태로 구현
		arr[a].push_back(b);
		arr[b].push_back(a);
	}
	
	visited[1] = true;
	virus(n, 1, arr);
	
	cout << res.size() - 1;
	return 0;
}