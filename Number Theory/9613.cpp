#include <iostream>
#include <vector>

using namespace std;

// 유클리드 호제법 (최대공약수)
int gcd(int a, int b) {
	int x = max(a, b);
	int y = min(a, b);

	while (y) {
		x %= y;
		swap(x, y);
	}

	return x;
}

int main() {
	int t, n;

	cin >> t;
	while (t--) {
		// 범위 초과 주의
		long long sum = 0;
		cin >> n;
		
		vector<int> num(n, 0);
		for (int i = 0; i < n; i++) {
			cin >> num[i];
		}

		for (int i = 0; i < n - 1; i++) {
			for (int j = i + 1; j < n; j++) {
				sum += gcd(num[i], num[j]);
			}
		}
		cout << sum << '\n';
	}
	
	return 0;
}