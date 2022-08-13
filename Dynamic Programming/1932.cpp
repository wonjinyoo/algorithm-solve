// [1932] 정수 삼각형

#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<vector<int>> tri(n + 1, vector<int>(n+1, 0));
	
	// 값 입력
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			cin >> tri[i][j];
		}
	}

	// 값 저장하면서 연산
	vector<vector<int>> dp(n + 1, vector<int>(n+1, 0));
	dp[1][1] = tri[1][1];
	
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			if (j == 1) {
				dp[i][j] = tri[i][j] + dp[i - 1][j];
			}
			else if (j == i) {
				dp[i][j] = tri[i][i] + dp[i - 1][i - 1];
			}
			
			else {
				dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + tri[i][j];
			}
		}
	}

	// 최댓값 저장해줄 변수
	int max = 0;

	for (int i = 1; i <= n; i++) {
		if (dp[n][i] > max) {
			max = dp[n][i];
		}
	}

	cout << max;

	return 0;
}