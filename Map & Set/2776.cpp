#include <iostream>
#include <unordered_set>

using namespace std;

// 변수, set 등 선언 위치 주의! 각 테스트케이스마다 수첩1의 내용은 바뀌어야지..
// unordered_set ==> O(1), 반면에 set ==> O(log n)

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;

	cin >> t;

	while (t--) {
		int n, m, a;
		
		// 선언위치 주의
		unordered_set<int> note1;

		cin >> n;
		while (n--) {
			cin >> a;
			// 중복없이 저장
			note1.insert(a);
		}

		cin >> m;

		while (m--) {
			cin >> a;
			// 반복자 설정 = note1에 a가 있니?
			auto it = note1.find(a);
			
			// 없을 경우
			if (it == note1.end()) {
				cout << "0\n";
			}
			else cout << "1\n";
		}
	}
	return 0;
}