// [10025] 게으른 백곰
// 슬라이딩 윈도우, 문제 조건을 놓치지 말자...

#include <iostream>
#include <vector>
using namespace std;

const int DEF = 1e6 + 1;
typedef long long ll;

// 윈도우 크기 = k*2
ll iceCount(int left, int right, int target, vector<int>& bucket) {
	ll max = 0, sum = 0;

	// 초기값 설정
	for (int i = 0; i <= target * 2; i++) {
		max += bucket[i];
	}

	sum = max;

	while (right < bucket.size() - 1) {
		sum = sum - bucket[left++] + bucket[++right];
		if (sum > max) {
			max = sum;
		}
	}

	return max;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, k, a, b;
	cin >> n >> k;

	if (k > 5e5) {
		k = 5e5;
	}

	// 위치에 따른 얼음의 개수
	vector<int> bucket(DEF, 0);

	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		bucket[b] = a;
	}

	cout << iceCount(0, k * 2, k, bucket);
	return 0;
}