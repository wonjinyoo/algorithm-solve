// ** [11053] 가장 긴 증가하는 부분 수열
// 다이내믹 프로그래밍, 다시 볼 필요가 있음!

#include <iostream>
#include <vector>
using namespace std;

int dynamicP(int n, vector<int> &array) {
	vector<int> dp(n + 1, 1);
	int ans = 1;

	for (int i = 2; i <= n; i++) {
		for (int j = 1; j < i; j++) {
			if (array[i] > array[j]) {
				// dp 자체를 갱신해주자 max 이용해서
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
		ans = max(ans, dp[i]);
	}

	return ans;

}

int main() {
	int n;
	cin >> n;
	
	vector<int> array(n + 1, 0);

	for (int i = 1; i <= n; i++) {
		cin >> array[i];
	}

	cout << dynamicP(n, array);

	return 0;
}