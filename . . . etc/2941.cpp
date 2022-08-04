// [2941] 크로아티아 알파벳

#include <iostream>

using namespace std;

int main() {
	string str;
	cin >> str;

	string cro[8] = { "c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z=" };

	for (int i = 0; i < str.size(); i++) {
		for (int j = 0; j < 8; j++) {
			// 해당 되는 문자열을 찾으면 + 그 위치 활용해서 다른 문자로 replace
			if (str.find(cro[j]) == i) {
				str.replace(i, cro[j].size(), "!");
			}
		}
	}

	cout << str.size();
	return 0;
}