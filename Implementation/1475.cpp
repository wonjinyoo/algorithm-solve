#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int roomNumber(string str) {
	vector<int> num(10, 0);
	// 0~9 몇 개인지 체크
	for (int i = 0; i < str.size(); i++) {
		num[str[i] - '0']++;
	}

	// 6, 9의 개수 6으로 몰아넣어서 정리
	int x = (num[6] + num[9] + 1) / 2;
	num[6] = x;
	num[9] = 0;

	sort(num.begin(), num.end());

	return num[9];
}


int main() {
	string str;
	cin >> str;

	cout << roomNumber(str);
	return 0;
}