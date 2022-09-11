// [12891] DNA 비밀번호
// 슬라이딩 윈도우

#include <iostream>
#include <vector>
using namespace std;

int availablePwd(int s, int p, int a, int c, int g, int t, vector<char> &pwd) {
	int ans = 0;

	int cnt_a = 0, cnt_c = 0, cnt_g = 0, cnt_t = 0;
	// 초기값 설정
	for (int i = 0; i < p; i++) {
		switch (pwd[i]) {
			case 'A':
				cnt_a++;
				break;
			case 'C':
				cnt_c++;
				break;
			case 'G':
				cnt_g++;
				break;
			case 'T':
				cnt_t++;
				break;
		}
	}

	if (cnt_a >= a && cnt_c >= c && cnt_g >= g && cnt_t >= t) ans++;

	// 슬라이딩 윈도우
	int left = 1;
	int right = p;

	while (right < s) {
		// 1. left 하나 이전값 빼주고
		switch (pwd[left - 1]) {
		case 'A':
			cnt_a--;
			break;
		case 'C':
			cnt_c--;
			break;
		case 'G':
			cnt_g--;
			break;
		case 'T':
			cnt_t--;
			break;
		}

		// 2. 하나 넘어간 right값 더해주기
		switch (pwd[right]) {
		case 'A':
			cnt_a++;
			break;
		case 'C':
			cnt_c++;
			break;
		case 'G':
			cnt_g++;
			break;
		case 'T':
			cnt_t++;
			break;
		}

		if (cnt_a >= a && cnt_c >= c && cnt_g >= g && cnt_t >= t) ans++;

		left++;
		right++;
	}
	
	return ans;
}

int main() {
	int s, p;
	int a, c, g, t;
	cin >> s >> p;

	vector<char> pwd(s, ' ');

	// 입력
	for (int i = 0; i < s; i++) {
		cin >> pwd[i];
	}

	cin >> a >> c >> g >> t;
	cout << availablePwd(s, p, a, c, g, t, pwd);
	return 0;
}