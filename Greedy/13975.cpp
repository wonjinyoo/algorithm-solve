// [13975] 파일 합치기 3
// 그리디 알고리즘 & 허프만 코딩 + 우선순위 큐
// int -> ll 처럼 크기 조심!

#include <iostream>
#include <queue>
using namespace std;

typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int t, k;
	ll size;
	cin >> t;
	
	while (t--) {
		cin >> k;
		priority_queue<ll, vector<ll>, greater<ll>> file;
		for (int i = 0; i < k; i++) {
			cin >> size;
			file.push(size);
		}
		
		ll res = 0;

		// 허프만 코딩
		while (!file.empty()) {
			ll a = file.top();
			file.pop();
			if (file.empty()) {
				break;
			}
			a += file.top();
			file.pop();
			res += a;
			file.push(a);
		}
		cout << res << '\n';
	}
	return 0;
}