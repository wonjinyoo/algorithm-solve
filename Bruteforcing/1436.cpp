#include <iostream>
#include <string>
using namespace std;

const int MAX = 1e9;

int director(int n) {
	int cnt = 0;
	for (int i = 666; i <= MAX; i++) {
		string str = to_string(i);
		// 666 포함안하는 경우 continue
		if (str.find("666") == str.npos) continue;
		cnt++;
		if (cnt == n) return i;
	}
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n;
	cin >> n;
	cout << director(n);
	return 0;
}