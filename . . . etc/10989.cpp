// [10989] 수 정렬하기 3
// 처음엔 map으로 이용하여 순회시켜서 출력하는 방식으로 썼는데 (백준에 제출기록 ㅇ)
// 그냥 평범하게 벡터 쓰는 게 더 메모리, 시간 면에서 효율적!
// (맨! 처음에 이차원벡터로 잘못;; 써서.. map 사용함)

#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, x;
	cin >> n;

	vector<int> num(10001, 0);

	while (n--) {
		cin >> x;
		num[x]++;
	}

	for (int i = 1; i < 10001; i++) {
		while (num[i] > 0) {
			cout << i << '\n';
			num[i]--;
		}
	}

	return 0;
}