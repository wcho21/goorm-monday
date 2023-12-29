#include <iostream>
#include <queue>
#include <vector>

using namespace std;

typedef long long ll;

constexpr int MAX_NUM_ISLANDS = int(1e4+1);

vector<int> bridges[MAX_NUM_ISLANDS];
bool visited[MAX_NUM_ISLANDS];

void solve() {
  int numIslands, numBridges, startIsland;
  cin >> numIslands >> numBridges >> startIsland;

  for (int i = 0; i < numBridges; ++i) {
    int source, dest;
    cin >> source >> dest;

    bridges[source].push_back(dest);
  }

  visited[startIsland] = true;

  queue<pair<int, int>> bfsQueue;
  bfsQueue.push({ startIsland, 0 }); // 섬, 거리

  while (!bfsQueue.empty()) {
    auto [island, distance] = bfsQueue.front();
    bfsQueue.pop();

    // 방문하지 않은 다음 섬은 큐에 대기
    for (int neighbor : bridges[island]) {
      if (neighbor == startIsland) { // 사이클 발견 시
        cout << distance+1 << '\n';
        return;
      }
      if (visited[neighbor]) {
        continue;
      }

      visited[neighbor] = true;
      bfsQueue.push({ neighbor, distance+1 });
    }
  }

  cout << -1 << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  solve();
}

