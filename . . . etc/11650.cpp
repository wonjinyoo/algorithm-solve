// [11650] 좌표 정렬하기

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int, int> ci;

bool cmp(ci& p1, ci& p2) {
	if (p1.first != p2.first) {
		return p1.first < p2.first;
	}
	else return p1.second < p2.second;
}

int main() {
	int n;
	cin >> n;
	
	vector<ci> point(n);
	for (int i = 0; i < n; i++) {
		cin >> point[i].first >> point[i].second;
	}

	sort(point.begin(), point.end(), cmp);

	for (int i = 0; i < n; i++) {
		cout << point[i].first << ' ' << point[i].second << '\n';
	}
	return 0;
}