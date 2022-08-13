// [1978] 소수 찾기

#include <iostream>
#include <vector>
using namespace std;

vector<bool> is_prime(1001, true);

void init_Prime() {
	is_prime[0] = is_prime[1] = false;

	for (int i = 2; i <= 31; i++) {
		if (!is_prime[i]) continue;
		for (int j = i * i; j <= 1000; j += i) {
			is_prime[j] = false;
		}
	}
}

int main() {
	int n, x;
	int cnt = 0;
	cin >> n;
	init_Prime();

	while (n--) {
		cin >> x;
		if (is_prime[x]) cnt++;
	}

	cout << cnt;
	return 0;
}