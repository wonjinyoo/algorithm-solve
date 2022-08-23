// [2531] 회전 초밥

#include <iostream>
#include <vector>
using namespace std;

int maxSushi(int n, int d, int k, int c, int left, int right, vector<int> &belt) {
	vector<bool> sushi_cnt(d+1, false);
	int maximum = 0;
	int cnt = 0;

	// 근데 if문이랑 for문이 많아서 그닥 좋은 풀이 같지는 않음
	while (left < n) {
		sushi_cnt[c] = true;
		if (left > right) {
			for (int i = left; i < n; i++) {
				sushi_cnt[belt[i]] = true;
			}

			for (int i = 0; i <= right; i++) {
				sushi_cnt[belt[i]] = true;
			}
		}
		
		else {
			for (int i = left; i <= right; i++) {
				sushi_cnt[belt[i]] = true;
			}
		}

		for (int i = 1; i <= d; i++) {
			if (sushi_cnt[i]) {
				cnt++;
			}
		}

		maximum = max(maximum, cnt);

		left++;
		right++;
		cnt = 0;

		// false로 지정을 안 해주고 계속 clear만 해줘서 에러가 났었음..ㅠ
		sushi_cnt.assign(d+1, false);

		if (right == n) {
			right = 0;
		}
	}
	return maximum;
}

int main() {
	// 접시 개수, 초밥 가짓수, 연속해서 몇 접시, 쿠폰 번호
	int n, d, k, c;
	cin >> n >> d >> k >> c;

	vector<int> belt(n, 0);
	
	for (int i = 0; i < n; i++) {
		cin >> belt[i];
	}

	cout << maxSushi(n, d, k, c, 0, k - 1, belt);

	return 0;
}