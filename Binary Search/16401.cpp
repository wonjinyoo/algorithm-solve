// ** [16401] 과자 나눠주기
// 최대길이인지 확인하는 게 중요, 이분탐색 범위 중요
// 뭘 이분탐색해야 할지도 잘 생각!

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 과자 길이가 len일때 몇 명에게 나눠줄 수 있는가
int cntNum(int len, vector<int> &snack) {
	int cnt = 0;
	for (int i = snack.size() - 1; i >= 0; i--) {
		if (snack[i] < len) {
			break;
		}
		// 몫 계산함으로써 최대 몇 명인지 계산시키는 거!!
		cnt += (snack[i] / len);
	}
	return cnt;
}

// 초기에 가능한 과자 길이 = 1~가장 긴 과자

// 최대길이를 찾는 것임!
int upperSearch(int left, int right, int m, vector<int> &snack) {
	// 과자 길이로 이분탐색
	while (left <= right) {
		int mid = (left + right) / 2;
		// 과자 길이가 mid 일때 cnt 명에게 나눠줄 수 있음
		int cnt = cntNum(mid, snack);

		// m명보다 '더' 나눠줄 수 있으면 -> 과자길이를 늘려야
		if (cnt >= m) {
			left = mid + 1;
		}
		else right = mid - 1;
	}
	return left - 1;
}

int main() {
	int m, n;
	cin >> m >> n;
	vector<int> snack(n, 0);
	for (int i = 0; i < n; i++) {
		cin >> snack[i];
	}

	sort(snack.begin(), snack.end());

	cout << upperSearch(1, snack[n - 1], m, snack);
	return 0;
}