// [1931] 회의실 배정
// 그리디 알고리즘 (일반 배열 사용 ver.)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int, int> ci;

// 정렬
bool cmp(ci& a, ci& b) {
	if (a.second != b.second) {
		return a.second < b.second;
	}
	return a.first < b.first;
}

int main() {
	int n;
	cin >> n;

	vector<ci> v(n, {0, 0});
	for (int i = 0; i < n; i++) {
		cin >> v[i].first >> v[i].second;
	}

	sort(v.begin(), v.end(), cmp);

	int cnt = 1;
	int prev = v[0].second;

	// 그리디
	for (int i = 1; i < n; i++) {
		if (v[i].first >= prev) {
			cnt++;
			prev = v[i].second;
		}
	}

	cout << cnt;

	return 0;
}