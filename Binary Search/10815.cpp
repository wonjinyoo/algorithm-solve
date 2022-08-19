// [10815] 숫자 카드
// 이분 탐색 문제인데 왜 이렇게 오래 걸렸지...? -> 벡터 선언하고 입력 받으면서 값 넣는 과정에서..

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int cardSearch(int left, int right, int x, vector<int>& v) {
	while (left <= right) {
		int mid = (left + right) / 2;
		if (x == v[mid]) {
			return 1;
		}

		else if (x > v[mid]) {
			left = mid + 1;
		}

		else if (x < v[mid]) {
			right = mid - 1;
		}
	}

	return 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n, m, x;
	cin >> n;
	
	// 카드 초기화
	vector<int> v(n, 0);
	
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	// 정렬
	sort(v.begin(), v.end());

	cin >> m;
	while (m--) {
		cin >> x;
		cout << cardSearch(0, n - 1, x, v) << ' ';
	}
	return 0;
}