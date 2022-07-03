#include <iostream>
#include <map>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while (t--) {
		int n;
		string name, type;

		map<string, int> fashion;

		cin >> n;
		while (n--) {
			cin >> name >> type;
			// map에서의 int value = 0으로 초기화되어있으므로 1 더해주는 연산하면 됨
			fashion[type]++;
		}

		int cnt = 0;

		int mult = 1;
		for (auto it : fashion) {
			// 입는 경우 + 1 (안 입는 경우!)
			mult *= (it.second + 1);
		}
		// 모두 다 안 입는 경우의 수 1을 빼주기
		cout << mult - 1 << '\n';
	}

	return 0;
}