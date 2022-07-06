#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 비교함수
bool cmp(string& s1, string& s2) {
	int sum1 = 0, sum2 = 0;

	for (int i = 0; i < s1.size(); i++) {
		if (isdigit(s1[i])) {
			// 문자 -> 숫자 변환 방법 (atoi 말고도)
			int k = s1[i] - '0';
			sum1 += k;
		}
	}

	for (int i = 0; i < s2.size(); i++) {
		if (isdigit(s2[i])) {
			int k = s2[i] - '0';
			sum2 += k;
		}
	}

	if (s1.size() != s2.size()) {
		return s1.size() < s2.size();
	}
	if (sum1 != sum2) {
		return sum1 < sum2;
	}
	else return s1 < s2;
}


int main() {
	int n;

	cin >> n;

	vector<string> serial(n, "");

	for (int i = 0; i < n; i++) {
		cin >> serial[i];
	}

	sort(serial.begin(), serial.end(), cmp);

	for (auto it = serial.begin(); it != serial.end(); it++) {
		cout << *it << '\n';
	}
	return 0;
}