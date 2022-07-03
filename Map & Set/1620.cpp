#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n, m;
	string name, input;

	map<string, int> pok_by_name;
	map<int, string> pok_by_num;

	// 포켓몬 개수 (1~n), 문제 개수 m
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		cin >> name;
		pok_by_name[name] = i;
		pok_by_num[i] = name;
	}

	while (m--) {
		cin >> input;
		if (isdigit(input[0])) {
			// string to int -> string 헤더 필요
			cout << pok_by_num[stoi(input)] << '\n';
		}
		else cout << pok_by_name[input] << '\n';
	}

	return 0;
}