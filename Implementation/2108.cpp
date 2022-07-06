#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>

using namespace std;

int average(vector<int> v, int n) {
    int sum = 0;

    for (auto it : v) {
        sum += it;
    }

    // 반올람(round) 함수 사용 주의!
    if (sum < 0) {
        return -round((double)(abs(sum)) / n);
    }

    else return round((double)sum / n);
}

int median(vector<int> v, int n) {
    return v[n / 2];
}

int freq(vector<int> v, int n) {
    map<int, int> num;
    vector<int> ans;

    for (int i = 0; i < n; i++) {
        num[v[i]]++;
    }

    int max = 0;

    for (auto it : num) {
        if (it.second > max) {
            ans.clear();
            ans.push_back(it.first);
            max = it.second;
        }
        else if (it.second == max) {
            ans.push_back(it.first);
        }
    }

    if (ans.size() >= 2) {
        sort(ans.begin(), ans.end());
        return ans[1];
    }

    return ans[0];
}

int range(vector<int> v, int n) {
    return v[n - 1] - v[0];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    vector<int> v(n, 0);

    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    cout << average(v, n) << '\n';
    cout << median(v, n) << '\n';
    cout << freq(v, n) << '\n';
    cout << range(v, n) << '\n';

    return 0;
}