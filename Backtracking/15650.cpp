// <백트래킹> [15650] N과 M (2)

#include <iostream>
#include <vector>
using namespace std;

int n, m;
// 숫자를 체크해줄 필요 X -> 반복문 통해 무조건 더 큰 수부터 확인하도록 했으므로
// vector<bool> num_check(9);
// 값 넣고 출력할 배열
vector<int> num(8);

void NandM(int cnt, int start) {
	if (cnt == m) {
		for (int i = 0; i < m; i++) {
			cout << num[i] << ' ';
		}
		cout << '\n';
		return;
	}

	// 모든 숫자에 대해 확인해야
	for (int i = start; i <= n; i++) {
		// 체크할 필요 없이 (겹치는 경우 X) 그냥 바로 num에 값을 넣어주면 된다	
		num[cnt] = i;
		NandM(cnt + 1, i + 1);
		
	}

}

int main() {
	// 1~n까지의 수 중에서 m개의 수 뽑기 (수열)
	cin >> n >> m;
	NandM(0, 1);
	return 0;
}