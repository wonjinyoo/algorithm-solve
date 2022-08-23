// ** [1644] 소수의 연속합
// 투포인터 : 같은 방향으로 이동하는 포인터일 때의 초기 위치 설정, 제한 설정
// +) 에라토스테네스의 체

#include <iostream>
#include <vector>

using namespace std;

vector<bool> is_prime;

// 초기화
vector<int> prime_init(int n, vector<bool> is_prime) {
	// 투 포인터 진행할 배열
	vector<int> ans;
	// 0과 1은 소수 아님
	is_prime[0] = is_prime[1] = false;

	for (int i = 2; i * i <= n; i++) {
		if (!is_prime[i]) continue;
		for (int j = i * i; j <= n; j += i) {
			is_prime[j] = false;
		}
	}
	for (int i = 2; i <= n; i++) {
		if (is_prime[i]) {
			ans.push_back(i);
		}
	}
	ans.push_back(0);
	return ans;
}


int twoPointer(int left, int right, int target, vector<int>& v) {
	int sum = v[left];
	int cnt = 0;
	// right가 무한으로 오른쪽으로 가지 않게 제한을 걸어줘야
	int size = v.size() - 1;

	// left와 right는 같은 위치일 수 있다
	while (left <= right && right < size) {
		if (sum == target) {
			cnt++;
			sum -= v[left++];
			sum += v[++right];
		}
		else if (sum < target) {
			sum += v[++right];
		}
		else {
			sum -= v[left++];
		}
	}
	return cnt;
}

int main() {
	int n;
	cin >> n;

	// 에라토스테네스의 체 이용
	is_prime.assign(n + 1, true);
	vector<int> v = prime_init(n, is_prime);

	cout << twoPointer(0, 0, n, v);
	
	return 0;
}