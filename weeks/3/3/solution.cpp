#include <iostream>
#include <queue>
#include <vector>

using namespace std;

typedef long long ll;

constexpr int MAX_NUM_ISLANDS = int(1e3+1);

vector<int> bridges[MAX_NUM_ISLANDS];
bool visited[MAX_NUM_ISLANDS];

void walk(int distanceLimit, int destIsland) {
  queue<pair<int, int>> bfsQueue;
  bfsQueue.push({1, 0}); // island, distance

  while (!bfsQueue.empty()) {
    auto [island, distance] = bfsQueue.front();
    bfsQueue.pop();

    // 주어진 거리를 넘기면 스킵
    if (distance >= distanceLimit) {
      continue;
    }

    // 방문한 적 없는 다음 섬들을 큐에 대기
    for (int nextIsland : bridges[island]) {
      // 목적지 섬에 도착하면 가능하다고 리턴
      if (nextIsland == destIsland) {
        cout << "YES" << '\n';
        return;
      }

      if (visited[nextIsland]) {
        continue;
      }
      visited[nextIsland] = true;

      bfsQueue.push({ nextIsland, distance + 1});
    }
  }

  // 목적지 섬에 도달할 수 없으면 불가능하다고 리턴
  cout << "NO" << '\n';
}

void solve() {
  int numIslands, numBridges, distanceLimit;
  cin >> numIslands >> numBridges >> distanceLimit;

  for (int i = 0; i < numBridges; ++i) {
    int island1, island2;
    cin >> island1 >> island2;
    bridges[island1].push_back(island2);
    bridges[island2].push_back(island1);
  }

  int destIsland = numIslands;

  visited[1] = true;

  walk(distanceLimit, destIsland);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  solve();
}
