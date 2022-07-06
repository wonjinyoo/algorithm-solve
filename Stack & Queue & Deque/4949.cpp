#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	string str;
	while (getline(cin, str)) {
		if (str[0] == '.') break;

		stack<char> stck;

		for (auto it : str) {
			if (it == ')') {
				if (!stck.empty() && stck.top() == '(') {
					stck.pop();
				}
				else stck.push(')');
			}

			if (it == ']') {
				if (!stck.empty() && stck.top() == '[') {
					stck.pop();
				}
				else stck.push(']');
			}

			if (it == '(') {
				stck.push('(');
			}
			if (it == '[') {
				stck.push('[');
			}
		}

		if (stck.empty()) {
			cout << "yes\n";
		}
		else cout << "no\n";

		while (!stck.empty()) {
			stck.pop();
		}
	}
	
	
	return 0;
}