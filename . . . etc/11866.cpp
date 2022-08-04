// [11866] 요세푸스 문제 0

#include <iostream>
#include <deque>
using namespace std;

void Josephus(int n, int k) {
	// 덱 초기화
	deque<int> deq;
	for (int i = 1; i <= n; i++) {
		deq.push_back(i);
	}

	cout << "<";

	int cnt = 0;

	while (!deq.empty()) {
		int x = deq.front();
		if (!deq.empty()) {
			deq.pop_front();
		}		
		cnt++;
		
		if (cnt == k) {
			if (deq.empty()) {
				cout << x << ">";
			}
			else {
				cout << x << ", ";
				cnt = 0;
				continue;
			}
		}
		else deq.push_back(x);
	}
}

int main() {
	// 총 사람 수 n, 제거할 번호 k
	int n, k;
	cin >> n >> k;
	Josephus(n, k);
	return 0;
}