#include <iostream>
#include <vector>
using namespace std;

const int MAX = 1e6;

vector<bool> is_prime;

// 에라토스테네스의 체
void prime(int m, int n) {
	is_prime.assign(MAX + 1, true);

	is_prime[0] = is_prime[1] = false;

	// 소수 초기화
	for (int i = 2; i * i <= MAX; i++) {
		if (!is_prime[i]) continue;
		for (int j = i * 2; j <= MAX; j += i) {
			if (!is_prime[j]) continue;
			is_prime[j] = false;
		}
	}

	for (int i = m; i <= n; i++) {
		if (is_prime[i]) {
			cout << i << '\n';
		}
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int m, n;
	cin >> m >> n;
	
	prime(m, n);

	return 0;
}