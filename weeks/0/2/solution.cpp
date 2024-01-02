#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

constexpr int MAX_NUM_PEOPLE = 200001;

int cards[MAX_NUM_PEOPLE];
bool visited[MAX_NUM_PEOPLE];
vector<int> friends[MAX_NUM_PEOPLE];
vector<int> groupCards, groupPeople;

// DFS로 그룹 사람들의 번호와 카드를 모으는 함수
void collectGroup(int person) {
  groupCards.push_back(cards[person]);
  groupPeople.push_back(person);

  for (int next : friends[person]) {
    if (visited[next]) {
      continue;
    }
    visited[next] = true;

    collectGroup(next);
  }
}

void solve() {
  int numPeople, numFriends; // N, M
  cin >> numPeople >> numFriends;

  for (int i = 1; i <= numPeople; ++i) {
    cin >> cards[i];
  }

  for (int i = 0; i < numFriends; ++i) {
    int p1, p2;
    cin >> p1 >> p2;
    friends[p1].push_back(p2);
    friends[p2].push_back(p1);
  }

  ll unhappiness = 0;
  for (int i = 1; i <= numPeople; ++i) {
    if (visited[i]) {
      continue;
    }
    visited[i] = true;

    // 각 그룹마다 번호와 카드를 모아서 정렬
    groupCards.clear();
    groupPeople.clear();

    collectGroup(i);

    sort(groupCards.begin(), groupCards.end());
    sort(groupPeople.begin(), groupPeople.end());

    // 불만족도를 계산하여 더함
    for (int j = 0; j < int(groupCards.size()); ++j) {
      unhappiness += abs(groupCards[j] - groupPeople[j]);
    }
  }

  cout << unhappiness << '\n';
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  solve();
}
