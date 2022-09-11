// [7568] 덩치

#include <iostream>
#include <vector>
using namespace std;

typedef pair<int, int> ci;

int main() {
	int n;
	cin >> n;

	vector<ci> people(n, { 0,0 });
	vector<int> rank(n, 1);

	for (int i = 0; i < n; i++) {
		cin >> people[i].first >> people[i].second;
	}

	for (int i = 0; i < n; i++) {
		// *주의* 하나하나 다 비교해줘야함 즉 j = i + 1부터라고 쓰면 안됨
		for (int j = 0; j < n; j++) {
			if (i == j) continue;
			if (people[j].first > people[i].first && people[j].second > people[i].second) {
				rank[i]++;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		cout << rank[i] << ' ';
	}

	return 0;
}