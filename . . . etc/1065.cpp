#include <iostream>

using namespace std;

int numCheck(int n) {
	int cnt = 0;

	for (int i = 1; i <= n; i++) {
		
		if (i < 100) {
			cnt++; 
			continue;
		}
		
		int a = i % 10;
		int b = (i / 10) % 10; 
		int c = i / 100; 

		if ((c - b) == (b - a)) {
			cnt++;
		}

	}
	return cnt;
}

int main() {
	int n;
	cin >> n;
	cout << numCheck(n);
	return 0;
}