// *중요* [7576] 토마토

// 1. 걸리는 '최소' 날짜 구하기 -> bfs 이용 : 자식 노드 즉 가까운 노드부터 탐색하므로
// 2. 방향벡터 활용법

#include <iostream>
#include <queue> // bfs 이용
using namespace std;

typedef pair<int, int> ci;

int bfs(int m, int n, int cnt, queue<ci>& tomato, vector<vector<int>>& arr) {
	// 리턴할 결과
	int t = 0;

	// 방향 설정 (상, 하, 좌, 우 4가지 경우의 수 만들기 위함)
	int dr[4] = { -1, +1, 0, 0 };
	int dc[4] = { 0, 0, -1, +1 };

	while (!tomato.empty()) {
		// 현재 front의 좌표값 기준 -> 즉 토마토가 있다고 판명된 곳의 상, 하, 좌, 우를 살피기 위함
		int r = tomato.front().first;
		int c = tomato.front().second;
		
		// arr에 걸리는 시간에 1씩 증가된 값을 저장할 것이므로 
		t = arr[r][c];
		tomato.pop();

		// 상, 하, 좌, 우 총 4번 확인
		for (int i = 0; i < 4; i++) {
			
			int new_r = r + dr[i];
			int new_c = c + dc[i];

			// 조건 주의 ! 좌표값이 범위 내에 있고, 익지 않은 곳을 익게 해야함 즉 값이 0이어야
			if (new_r >= 0 && new_r < n && new_c >= 0 && new_c < m && arr[new_r][new_c] == 0) {
				// 익게 했으므로 안 익은 토마토 개수를 하나 줄여준다
				cnt--;

				// arr값을 이전값 + 1로 갱신 -> 결과값 t에 활용
				arr[new_r][new_c]  = t + 1;

				// 새로운 좌표도 익었으므로 큐에 넣어줘서 이 좌표에 대해 상하좌우 봐줘야 함
				tomato.push({ new_r, new_c });
			}
		}
	}

	// cnt가 0이면 -> 안 익은 토마토가 0개임 -> 다 익게 했으므로 걸린시간을 리턴
	// cnt가 0이 아니라면 -> 다 익게 하지 못함 -> -1 리턴
	return (cnt == 0 ? t - 1 : -1);
}

int main() {
	int m, n, cnt = 0;
	cin >> m >> n;
	vector<vector<int>> arr(n, vector<int>(m, 0));
	
	// 토마토가 있는 좌표 저장하기 위한 큐 -> bfs에 활용
	queue<ci> tomato;

	// 입력
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 1) {
				tomato.push({ i,j });
			}
			else if (arr[i][j] == 0) {
				// 토마토가 익지 않은 곳 개수
				cnt++;
			}
		}
	}

	// 출력
	cout << bfs(m, n, cnt, tomato, arr);
	return 0;
}