// <백트래킹> [15649] N과 M (1)

#include <iostream>
#include <vector>
using namespace std;

int n, m;
// 인덱스의 숫자가 배열에 포함되는지 체크
vector<bool> num_check(9);
// 값 넣고 출력할 배열
vector<int> num(8);

void NandM(int cnt) {
	if (cnt == m) {
		for (int i = 0; i < m; i++) {
			cout << num[i] << ' ';
		}
		cout << '\n';
		return;
	}

	// 모든 숫자에 대해 확인해야
	for (int i = 1; i <= n; i++) {
		if (!num_check[i]) {
			num[cnt] = i;
			num_check[i] = true;
			NandM(cnt + 1);
			num_check[i] = false;
		}
	}

}

int main() {
	// 1~n까지의 수 중에서 m개의 수 뽑기 (수열)
	cin >> n >> m;
	NandM(0);
	return 0;
}