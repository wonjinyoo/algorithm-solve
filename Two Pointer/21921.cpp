// [21921] 블로그
// 슬라이딩 윈도우, 누적 합

#include <iostream>
#include <vector>
using namespace std;

int main() {
	int x, n, max;
	cin >> x >> n;
	vector<int> visitor(x, 0);
	vector<int> sum(x - n + 1, 0);

	for (int i = 0; i < x; i++) {
		cin >> visitor[i];
	}

	// 초기값 설정
	for (int i = 0; i < n; i++) {
		sum[0] += visitor[i];
	}

	max = sum[0];
	int cnt = 1;

	for (int i = 1; i < x - n + 1; i++) {
		sum[i] = sum[i - 1] - visitor[i - 1] + visitor[i + n - 1];
		if (sum[i] > max) {
			max = sum[i];
			cnt = 1;
		}
		else if (sum[i] == max) {
			cnt++;
		}
	}

	if (max == 0) {
		cout << "SAD";
	}
	else cout << max << '\n' << cnt;

	return 0;
}