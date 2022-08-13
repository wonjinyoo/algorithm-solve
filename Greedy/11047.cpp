// [11047] 동전 0
// 그리디 알고리즘

#include <iostream>
#include <queue>
using namespace std;

int main() {
	int n, k, p;
	cin >> n >> k;
	
	// 최대 힙
	priority_queue<int> pq;

	for (int i = 0; i < n; i++) {
		cin >> p;
		pq.push(p);
	}
	int ans = 0;
	while (k > 0) {
		if (pq.top() > k) {
			pq.pop(); 
			continue;
		}
		int x = pq.top();
		int money = k / x;
		ans += money;
		k -= money * x;
	}
	cout << ans;
	return 0;
}