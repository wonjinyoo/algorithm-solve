## 이분탐색
``` c++
int upperSearch(int left, int right, int target, vector<int> &v)  {
  while (left <= right){
    int mid = (left + right) / 2;
   
   // 조건에 따라 left를 이동시킬지, right를 이동시킬지 판단하는 것도 중요
    if (condition) {
      left = mid + 1;
    }
    else right = mid - 1;
  }
}
```
- 위의 형태처럼, left와 right를 지정하고 그에 따라 mid를 정함으로써 이분탐색 (효율성 측면에서 좋음)
- 최대 OO를 구하라 -> OO를 이분탐색하자 (:star: 탐색할 OO의 범위를 알맞게 설정하는 것 중요!)
