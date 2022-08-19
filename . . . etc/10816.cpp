// [10816] 숫자 카드 2
// 맵으로 풀기 -> 메모리 사용 많고, 시간이 오래 걸림

#include <iostream>
#include <map>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, x, m;
	cin >> n;
	map<int, int> num;
	
	while (n--) {
		cin >> x;
		num[x]++;
	}

	cin >> m;
	while (m--) {
		cin >> x;
		cout << num[x] << ' ';
	}

	return 0;
}