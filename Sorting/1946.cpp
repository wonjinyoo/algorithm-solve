#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int, int> ci;

// 연산 함수 따로 빼주기
int ans(int n, vector<ci> employee) {
	int cnt = 1;

	int k = employee[0].second;
	
	// 시간 초과 주의 !
	for (int i = 1; i < n; i++) {
		if (employee[i].second < k) {
			// 값 갱신해주면서 연산
			k = employee[i].second;
			cnt++;
		}
	}
	return cnt;
}

int main() {
	int t, n;

	cin >> t;
	
	while (t--) {
		cin >> n;
		vector<ci> employee(n, { 0,0 });

		for (int i = 0; i < n; i++) {
			cin >> employee[i].first >> employee[i].second;
		}

		// 서류 심사 성적 오름차순으로 정렬
		sort(employee.begin(), employee.end());

		cout << ans(n, employee) << '\n';
		}
	
	return 0;
}