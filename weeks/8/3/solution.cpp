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

    if (numSticks < 2) {
      continue;
    }

    if (aside != EMPTY) {
      ll rectangleArea = len * aside;
      areaSum += rectangleArea;

      aside = EMPTY;
      numSticks -= 2;
    }

    if (numSticks >= 4) {
      ll numSquares = numSticks / 4;
      ll squareAreas = len * len;
      areaSum += squareAreas * numSquares;

      numSticks -= numSquares * 4;
    }

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
