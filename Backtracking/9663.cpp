//  ! 중요 ! <백트래킹> [9663] N-Queen


#include <iostream>
#include <vector>
using namespace std;

// 백트래킹의 특징
// 전역변수 사용, 재귀함수 사용! (그러나 다른 알고리즘에서는 웬만하면 X)
int n, ans = 0;

// 세로(열), 좌하향 대각선, 우하향 대각선 체크배열
vector<bool> Check_col, Check_left, Check_right;


// 재귀함수
// 작성 시 -> 간단하게 조건에 맞을 때 이렇게 하면 되겠다! 싶게 적어주고
// 다음 턴 재귀함수 호출하고 다시 원상복구 시켜놓는 코드 작성하기
void NQueen(int cnt) {
	if (cnt == n) {
		ans++;
		return;
	}

	for (int i = 0; i < n; i++) {
		// 이미 세로, 대각선에 놓을 수 없다고 표시가 되어 있으면 continue
		if (Check_col[i] || Check_left[cnt+i] || Check_right[i - cnt+n]) {
			continue;
		}
		
		// 놓을 수 있는 경우라면
		// 세로, 대각선을 true로 바꾸어줌 (즉, 채워진 상태라고)
		Check_col[i] = true;
		Check_left[cnt + i] = true;
		Check_right[i- cnt + n] = true;

		// 이후 다음 차례(cnt+1) 재귀함수 호출
		NQueen(cnt + 1);

		// 상태 원래대로 돌려놓기
		Check_col[i] = false;
		Check_left[cnt + i] = false;
		Check_right[i - cnt + n] = false;
		// 끝!
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	// 입력 및 벡터 할당
	cin >> n;
	Check_col.assign(n, false);
	Check_left.assign(2*n, false);
	Check_right.assign(2*n, false);
	

	// 함수 호출
	NQueen(0);

	cout << ans;
	return 0;
}