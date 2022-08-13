// [2579] 계단 오르기
// 다이내믹 프로그래밍 : 이전 결과 저장하면서 진행되도록 코드 작성
// 초기값 설정과 점화식 작성이 포인트!

#include <iostream>
#include <vector>
using namespace std;

int dynamicProgramming(int n, vector<int> &stairs) {
	vector<int> dp(n + 1, 0);
	dp[1] = stairs[1];
	dp[2] = stairs[1] + stairs[2];

	// 계단을 연속 3칸 밟지 않도록 하는 과정이 필요
	for (int i = 3; i <= n; i++) {
		dp[i] = max(dp[i - 2], dp[i - 3] + stairs[i - 1]) + stairs[i];
	}

	return dp[n];
}

int main() {
	int n;
	cin >> n;

	vector<int> stairs(n + 1, 0);

	for (int i = 1; i <= n; i++) {
		cin >> stairs[i];
	}

	cout << dynamicProgramming(n, stairs);
	return 0;
}