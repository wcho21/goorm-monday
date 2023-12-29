#include <algorithm>
#include <iostream>

using namespace std;

typedef long long ll;

constexpr int MAX_EVENTS = int(1e5+1);

int eventCounts[MAX_EVENTS];

void solve() {
  int numEvents, numUsers;
  cin >> numEvents >> numUsers;

  // 횟수 카운트
  for (int i = 0; i < numUsers; ++i) {
    int numEventsOfUser;
    cin >> numEventsOfUser;

    for (int i = 0; i < numEventsOfUser; ++i) {
      int event;
      cin >> event;
      eventCounts[event]++;
    }
  }

  // 가장 많이 일어난 이벤트를 큰 번호부터 출력
  int maxCount = *max_element(begin(eventCounts), end(eventCounts));
  for (int i = numEvents; i >= 1; --i) {
    if (eventCounts[i] != maxCount) {
      continue;
    }

    cout << i << " ";
  }
  cout << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  solve();
}
