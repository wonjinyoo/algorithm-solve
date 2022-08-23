// [10025] 게으른 백곰 (advanced ver.)
// 슬라이딩 윈도우, 문제 조건을 놓치지 말자..
// +) 항상 DEF만큼 끝까지 탐색하는 것이 아니라 끝나는 포인트를 저장해서 거기까지만 탐색하도록

#include <iostream>
#include <vector>
using namespace std;

const int DEF = 1e6 + 1;
typedef long long ll;

// 윈도우 크기 = k*2
ll iceCount(int left, int right, int target, int end, vector<int>& bucket) {
	ll maximum = 0, sum = 0;

	// 초기값 설정
	for (int i = 0; i <= target * 2; i++) {
		maximum += bucket[i];
	}

	sum = maximum;

	while (right <= end) {
		sum = sum - bucket[left++] + bucket[++right];
		maximum = max(maximum, sum);
	}

	return maximum;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, k, a, b, end = 0;
	cin >> n >> k;

	// ! 문제 조건을 잘 읽자 !!!!!!!
	if (k > 5e5) {
		k = 5e5;
	}

	// 위치에 따른 얼음의 개수
	vector<int> bucket(DEF, 0);

	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		bucket[b] = a;
		// 무조건 끝까지 탐색하는 게 아니라 원소 있는 데까지 탐색하기 위해 마지막 포인트 저장
		end = max(end, b);
	}

	cout << iceCount(0, k * 2, k, end, bucket);
	return 0;
}