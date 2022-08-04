// [10814] 나이순 정렬

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct j {
	int age;
	string name;
	int num;
};

bool cmp(j j1, j j2) {
	if (j1.age != j2.age) {
		return j1.age < j2.age;
	}
	return j1.num < j2.num;
}

int main() {
	int n, a;
	string na;

	cin >> n;
	
	vector<j> judges(n);
	for (int i = 0; i < n; i++) {
		cin >> a >> na;
		judges[i].name = na;
		judges[i].age = a;
		judges[i].num = i;
	}

	sort(judges.begin(), judges.end(), cmp);

	for (int i = 0; i < n; i++) {
		cout << judges[i].age << ' ' << judges[i].name << '\n';
	}
	return 0;
}