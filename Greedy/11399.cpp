// [11399] ATM
// 그리디

#include <iostream>
#include <queue>
using namespace std;

int minTime(priority_queue<int, vector<int>, greater<int>> pq) {
	int ans = pq.top();
	int prev = pq.top();
	pq.pop();

	while (!pq.empty()) {
		prev += pq.top();
		ans += prev;
		
		pq.pop();
	}

	return ans;
}

int main() {
	int n, t;
	cin >> n;

	// 최소 힙
	priority_queue<int, vector<int>, greater<int>> pq;
	for (int i = 0; i < n; i++) {
		cin >> t;
		pq.push(t);
	}

	cout << minTime(pq);

	return 0;
}