#include <algorithm>
#include <iostream>

using namespace std;

typedef long long ll;

constexpr int MAX_NUM_CARDS = 8;
constexpr ll MAX_NUMBER = ll(1e16);

ll cards[MAX_NUM_CARDS];

// 주어진 카드로 숫자를 만드는 함수
ll makeNumber(int numCards) {
  ll number = cards[0];

  for (int i = 1; i < numCards; ++i) {
    ll prevOnes = cards[i-1] % 10;
    ll nextTens = cards[i] / 10;

    // 이전 일이 자리와 다음 십의 자리가 겹칠 때, 그대로 겹쳐서 만들기
    if (prevOnes == nextTens) {
      ll nextOnes = cards[i] % 10;
      number = (number * 10) + nextOnes;
      continue;
    }

    // 겹치지 않고 만들기
    number = (number * 100) + cards[i];
  }

  return number;
}

void solve() {
  int numCards;
  cin >> numCards;
  for (int i = 0; i < numCards; ++i) {
    cin >> cards[i];
  }

  ll minNumber = MAX_NUMBER;

  // 모든 퍼뮤테이션에 중에 최소값을 구함
  sort(cards, cards+numCards);
  do {
    minNumber = min(minNumber, makeNumber(numCards));
  } while (next_permutation(cards, cards+numCards));

  cout << minNumber << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  solve();
}
