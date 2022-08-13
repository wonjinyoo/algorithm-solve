// [13975] 파일 합치기 3 (수정 ver.)
// 그리디 알고리즘 & 허프만 코딩

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

		// 허프만 코딩 (수정 ver.)
		while (file.size() > 1) {
			ll a = file.top();
			file.pop();
			ll b = file.top();
			file.pop();
			res += a + b;
			file.push(a + b);
		}
		cout << res << '\n';
	}
	return 0;
}