// **[2110] 공유기 설치

// 최대 OO를 구하라 -> OO의 범위를 설정해서 얘를 이분 탐색!
// 문제를 똑바로 읽자..
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 가장 인접한 공유기의 거리가 dist일때 세울 수 있는 공유기 개수
int cntC(int dist, vector<int> &house) {
	// 첫번째집은 무조건 설치
	int cnt = 1;
	// 지금 제일 가깝게 설치된 집
	int cur = house[0];

	for (int i = 1; i < house.size(); i++) {
		// 즉, dist가 제일 짧은 길이어야 함
		if (house[i] - cur >= dist) {
			cnt++;
			cur = house[i];
		}
	}
	return cnt;
}

// 공유기 사이의 '최대' 거리 
int upperSearch(int left, int right, int c, vector<int> &house) {
	while (left <= right) {
		int mid = (left + right) / 2;
		int cnt = cntC(mid, house);

		// 목표한 것보다 많이 세울 수 있으면 -> 거리를 늘리자
		if (cnt >= c) {
			left = mid + 1;
		}
		else right = mid - 1;
	}
	return left - 1;
}

int main() {
	int n, c;
	cin >> n >> c;
	vector<int> house(n, 0);
	for (int i = 0; i < n; i++) {
		cin >> house[i];
	}

	sort(house.begin(), house.end());
	// left, right 값은 거리의 최소인 1과 최대 거리인 (가장 끝집 - 가장 앞집)
	cout << upperSearch(1, house[n - 1] - house[0], c, house);
	return 0;
}