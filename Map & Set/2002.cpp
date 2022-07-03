#include <iostream>
#include <map>
#include <vector>

using namespace std;

// 추월하는 것의 포인트 : 어떤 차와 그 뒤 차들의 나온 순서와, 들어간 순서를 보는 것
// 단순히 차의 전후 위치만 따지면 X
int chaseCheck(int n, vector<string> out, map<string, int> car) {
	int cnt = 0;

	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			if (car[out[i]] > car[out[j]]) {
				cnt++;
				break;
			}
		}
	}

	return cnt;
}

int main() {
	int n;
	string num, input;
	cin >> n;
	
	map<string, int> car;
	vector<string> out(n + 1, "");

	for (int i = 1; i <= n; i++) {
		cin >> num;
		car[num] = i;
	}

	for (int i = 1; i <= n; i++) {
		// 벡터 입력받을 때 주의! n+1개로 할당했기 때문에 push_back 하면 값이 제대로 안 들어간다
		cin >> out[i];
	}

	cout << chaseCheck(n, out, car);

	return 0;
}