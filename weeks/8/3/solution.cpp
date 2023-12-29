#include <iostream>

using namespace std;

typedef long long ll;

constexpr ll EMPTY = -1;
constexpr ll MAX_STICK_LEN = (ll)(1e6+1);

ll lengthCounts[MAX_STICK_LEN];

void solve() {
  ll numSticks;
  cin >> numSticks;

  for (ll i = 0; i < numSticks; ++i) {
    ll len;
    cin >> len;
    lengthCounts[len]++;
  }

  ll areaSum = 0;
  ll aside = EMPTY;
  for (ll len = MAX_STICK_LEN-1; len >= 0; --len) {
    ll numSticks = lengthCounts[len];

    // 두 개 미만이면 볼 필요 없음
    if (numSticks < 2) {
      continue;
    }

    // 옆에 둔 막대기가 있으면 먼저 직사각형 만들기
    if (aside != EMPTY) {
      ll rectangleArea = len * aside;
      areaSum += rectangleArea;

      aside = EMPTY;
      numSticks -= 2;
    }

    // 정사각형 만들기
    if (numSticks >= 4) {
      ll numSquares = numSticks / 4;
      ll squareAreas = len * len;
      areaSum += squareAreas * numSquares;

      numSticks -= numSquares * 4;
    }

    // 남는 막대기 옆에 두기
    if (numSticks >= 2) {
      numSticks -= 2;
      aside = len;
    }
  }

  cout << areaSum << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  solve();
}
