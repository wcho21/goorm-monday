#include <iostream>
#include <vector>

using namespace std;

constexpr int ANT = 1;
constexpr int APHID = 2;

vector<pair<int, int>> ants;
vector<pair<int, int>> aphids;

int getManhattanDistance(int x1, int y1, int x2, int y2) {
  return abs(x1 - x2) + abs(y1 - y2);
}

void solve() {
  int side, reachableDistance;
  cin >> side >> reachableDistance;

  // 개미와 진딧물 좌표를 읽어서 배열에 담음
  for (int y = 0; y < side; ++y) {
    for (int x = 0; x < side; ++x) {
      int read;
      cin >> read;

      if (read == ANT) {
        ants.push_back({ y, x });
        continue;
      }
      if (read == APHID) {
        aphids.push_back({ y, x });
        continue;
      }
    }
  }

  // 각 개미마다 진딧물에 닿을 수 있는지 세기
  int numFeedable = 0;
  for (auto [antY, antX] : ants) {
    for (auto [aphidY, aphidX] : aphids) {
      // 닿을 수 있는 진딧물이 하나라도 있다면 다음 개미로 스킵
      int distance = getManhattanDistance(antX, antY, aphidX, aphidY);
      if (distance <= reachableDistance) {
        numFeedable++;
        break;
      }
    }
  }
  cout << numFeedable << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  solve();
}
