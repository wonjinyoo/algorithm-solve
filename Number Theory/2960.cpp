#include <iostream>
#include <vector>
using namespace std;

int primeCnt(int n, int k) {
	int cnt = 0;

	// 소수이면 true, 아니면 false
	vector<bool> num(n + 1, true);

	// 소수 아님 초기화
	num[0] = num[1] = false;

	// 2부터 지워나가는 거 체크해야
	for (int i = 2; i <= n; i++) {
		// 소수가 아니면 앞으로 돌아가서 계속 반복
		if (!num[i]) continue;
		
		// 수가 소수이면 뒷 숫자들 다 지워나가기
		for (int j = i; j <= n; j += i) {
			if (!num[j]) continue;
			
			num[j] = false;
		
			if (++cnt == k) return j;
		}
	}

	return 1;
}

int main() {
	int n, k;

	cin >> n >> k;
	cout << primeCnt(n, k);
	return 0;
}