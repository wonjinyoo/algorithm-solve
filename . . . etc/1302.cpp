// [1302] 베스트셀러
// map을 value값을 기준으로 정렬하고 싶을 때 -> 벡터로 옮겨서 정렬!

#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<string, int> ci;

bool cmp(ci &a, ci &b) {
	if (a.second != b.second) {
		return a.second > b.second;
	}

	return a.first < b.first;
}

int main() {
	int n;
	// 제목, 팔린 개수
	map<string, int> book;
	
	cin >> n;
	string title;
	while (n--) {
		cin >> title;
		book[title]++;
	}

	// map을 벡터로 옮기기
	vector<ci> v(book.begin(), book.end());

	sort(v.begin(), v.end(), cmp);

	cout << v[0].first;

	return 0;
}