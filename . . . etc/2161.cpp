// [2161] 카드1

#include <iostream>
#include <deque>

using namespace std;

void cardGame(int n) {
	// 카드 초기화
	deque<int> deq;
	for (int i = 1; i <= n; i++) {
		deq.push_back(i);
	}

	while (!deq.empty()) {
		cout << deq.front() << ' ';
		deq.pop_front();
		if (deq.empty()) {
			break;
		}
		int a = deq.front();
		deq.pop_front();
		deq.push_back(a);
	}
}

int main() {
	int n;
	cin >> n;
	cardGame(n);
	return 0;
}