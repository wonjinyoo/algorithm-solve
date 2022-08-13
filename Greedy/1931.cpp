// [1931] 회의실 배정
// 그리디 알고리즘 (우선순위 큐 사용 ver.)

#include <iostream>
#include <queue>
using namespace std;

typedef pair<int, int> ci;

// 우선순위 큐의 비교함수 작성은 반대라는 거!
struct cmp {
	bool operator()(ci& a, ci& b) {
		if (a.second != b.second) {
			return a.second > b.second;
		}
		// 빨리 시작하는 순서대로
		return a.first > b.first;
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	ci time;
	priority_queue<ci, vector<ci>, cmp> pq;
	
	cin >> n;
	while (n--) {
		cin >> time.first >> time.second;
		pq.push(time);
	}

	// 약간 번거롭다..
	int cnt = 1;
	int a = pq.top().first;
	int b = pq.top().second;

	pq.pop();

	while (!pq.empty()) {
		if (pq.top().first >= b) {
			cnt++;
			a = pq.top().first;
			b = pq.top().second;
			pq.pop();
		}
		else pq.pop();
	}

	cout << cnt;
	return 0;
}