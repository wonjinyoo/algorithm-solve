#include <iostream>
#include <vector>

using namespace std;

const int MAX = 5e6;

vector<int> isPrime() {
	vector<int> prime(MAX + 1, 0);
	
	// isPrime값이 0이면 0,1이거나 소수이도록 설정
	for (int i = 2; i * i <= MAX; i++) {
		if (prime[i] != 0) continue;

		for (int j = i * i; j <= MAX; j += i) {
			if (prime[j] == 0) prime[j] = i;
		}
	}

	return prime;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, x;
	cin >> n;

	// 얘의 위치!! 반복문 안에 넣으면 계속 함수 연산이 되니까
	// 시간 초과가 날 수밖에 없었지...
	// 초기화한 소인수를 저장한 벡터는 한 번만 계산하면 된다 !! 
	vector<int> ans = isPrime();

	for (int i = 0; i < n; i++) {
		cin >> x;
		
		while (ans[x] != 0) {
			cout << ans[x] << ' ';
			x /= ans[x];
		}
		cout << x << '\n';
	}


	return 0;
}