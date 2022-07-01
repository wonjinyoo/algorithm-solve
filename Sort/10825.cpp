#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 구조체로 설정
struct student {
	string name;
	int kor, eng, math;
};

// 정렬을 위한 비교함수
bool comp(student &s1, student &s2) {
	if (s1.kor != s2.kor) {
		return s1.kor > s2.kor;
	}
	if (s1.eng != s2.eng) {
		return s1.eng < s2.eng;
	}
	if (s1.math != s2.math) {
		return s1.math > s2.math;
	}
	else return s1.name < s2.name;
}

int main() {
	int n;
	cin >> n;
	vector<student> st(n);
	
	for (int i = 0; i < n; i++) {
		cin >> st[i].name >> st[i].kor >> st[i].eng >> st[i].math;
	}

	// 정렬
	sort(st.begin(), st.end(), comp);

	for (int i = 0; i < n; i++) {
		cout << st[i].name << '\n';
	}
	return 0;
}