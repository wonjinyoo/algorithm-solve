#include <iostream>
#include <deque>

using namespace std;

int card(int n) {
	deque<int> deq;
	
	// 덱 초기화
	for (int i = 1; i <= n; i++) {
		deq.push_back(i);
	}

	while (deq.size() != 1) {
		deq.pop_front();

		int x = deq.front();
		deq.pop_front();
		deq.push_back(x);
	}

	return deq.front();
}


int main() {
	int n;
	cin >> n;

	cout << card(n);
	return 0;
}