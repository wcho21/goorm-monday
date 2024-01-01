#include <iostream>

using namespace std;

typedef long long ll;

constexpr int MAX_NUM_MARBLES = 201;
constexpr int MAX_ROUNDS = 1001;
constexpr ll MOD = (int)(1e8+7);

ll cache[MAX_NUM_MARBLES][MAX_ROUNDS];
bool cached[MAX_NUM_MARBLES][MAX_ROUNDS];

ll getNumWaysCached(int goormMarbles, int opponentMarbles, int lastRound, int currentRound);

ll getNumWays(int goormMarbles, int opponentMarbles, int lastRound, int currentRound) {
  // 한 쪽이 떨어지면 한 가지 경우로 셈
  if (goormMarbles == 0 || opponentMarbles == 0) {
    return 1;
  }
  // 라운드가 끝나면 없는 경우로 셈
  if (currentRound > lastRound) {
    return 0;
  }

  // 다음 라운드의 모든 경우의 수를 합하여 리턴
  int nextRound = currentRound + 1;

  ll ways = 0;
  ways += getNumWaysCached(goormMarbles, opponentMarbles, lastRound, nextRound); // 무승부
  ways += getNumWaysCached(goormMarbles-1, opponentMarbles+1, lastRound, nextRound); // 패배
  ways += getNumWaysCached(goormMarbles+1, opponentMarbles-1, lastRound, nextRound); // 승리
  ways %= MOD;

  return ways;
}

// 캐시가 없으면 만들고 결과를 리턴하는 함수
ll getNumWaysCached(int goormMarbles, int opponentMarbles, int lastRound, int currentRound) {
  if (!cached[goormMarbles][currentRound]) {
    int numWays = getNumWays(goormMarbles, opponentMarbles, lastRound, currentRound);
    cache[goormMarbles][currentRound] = numWays;
    cached[goormMarbles][currentRound] = true;
  }

  return cache[goormMarbles][currentRound];
}

void solve() {
  int goormMarbles, opponentMarbles, lastRound;
  cin >> goormMarbles >> opponentMarbles >> lastRound;

  ll ways = getNumWaysCached(goormMarbles, opponentMarbles, lastRound, 1);
  cout << ways << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  solve();
}
