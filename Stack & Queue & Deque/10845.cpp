#include <iostream>
#include <queue>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n, a;
	string func;
	queue<int> q;
	
	cin >> n;

	while (n--) {
		cin >> func;
		if (func == "push") {
			cin >> a;
			q.push(a);
		}
		else if (func == "pop") {
			if (q.empty()) cout << "-1\n";
			else {
				cout << q.front() << '\n';
				q.pop();
			}
		}
		else if (func == "size") {
			cout << q.size() << '\n';
		}
		else if (func == "empty") {
			if (q.empty()) cout << "1\n";
			else cout << "0\n";
		}
		else if (func == "front") {
			if (q.empty()) cout << "-1\n";
			else cout << q.front() << '\n';
		}
		else if (func == "back") {
			if (q.empty()) cout << "-1\n";
			else cout << q.back() << '\n';
		}
	}
	return 0;
}