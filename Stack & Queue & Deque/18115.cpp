#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

// switch-case문 : break!!!!!!!

deque<int> cardgame(vector<int> func, int n) {
	deque<int> res;
	
	for (int i = 0; i < n; i++) {
		switch (func[i]) {
		case 1: {
			res.push_front(i + 1);
			break;
		}

		case 2: {
			if (!res.empty()) {
				int x = res.front();
				res.pop_front();
				res.push_front(i + 1);
				res.push_front(x);
			}
			else res.push_front(i + 1);
			break;
		}
		
		case 3: {
			res.push_back(i + 1);
			break;
		}
		}
	}

	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n;
	cin >> n;

	vector<int> func(n, 0);

	for (int i = 0; i < n; i++) {
		cin >> func[i];
	}

	// 역으로 생각해야하는 문제, 그러므로 벡터 뒤집어줘야하고 & algorithm 헤더
	reverse(func.begin(), func.end());

	deque<int> ans = cardgame(func, n);

	while (!ans.empty()) {
		cout << ans.front() << ' ';
		ans.pop_front();
	}

	return 0;
}