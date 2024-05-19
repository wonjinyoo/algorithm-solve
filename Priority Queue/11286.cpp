// [11286] 절댓값 힙
// 우선순위 큐 : 비교 구조체 작성 -> 정렬과 비슷하지만 부등호 방향이 반대가 된다

#include <iostream>
#include <queue>
using namespace std;

// 비교 구조체 작성
struct cmp {
	bool operator()(int a, int b) {
		if (abs(a) != abs(b)) {
			return abs(a) > abs(b);
		}
		else return a > b;
	}
};

void absoluteHeap(int x, priority_queue<int, vector<int>, cmp> &pq) {
	// x가 0이 아니라면 큐에 넣어주기
	if (x) {
		pq.push(x);
	}

	// x가 0이라면 절댓값이 가장 작은 값 출력 & 제거
	else {
		// 배열이 비어있으면 0 출력
		if (pq.empty()) {
			cout << "0\n";
			return;
		}
		cout << pq.top() << '\n';
		pq.pop();
	}
}

int main() {
	int n, x;
	cin >> n;

	priority_queue<int, vector<int>, cmp> pq;

	while (n--) {
		cin >> x;
		absoluteHeap(x, pq);
	}

	return 0;
}