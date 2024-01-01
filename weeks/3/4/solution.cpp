#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

constexpr int NULL_NODE = 0;
constexpr int MAX_NUM_TANKS = int(1e3+1);

bool visited[MAX_NUM_TANKS];
bool cycleDetected;
vector<int> path;
vector<int> channels[MAX_NUM_TANKS];

void walk(int tank, int prevTank) {
  if (cycleDetected) {
    return;
  }

  if (visited[tank]) {
    return;
  }
  visited[tank] = true;

  // 경로 기억
  path.push_back(tank);

  for (int nextTank : channels[tank]) {
    if (nextTank == prevTank) {
      continue;
    }

    // 탱크를 또 만나면 사이클이므로 탐색 중지
    if (visited[nextTank]) {
      path.push_back(nextTank);
      cycleDetected = true;
      return;
    }

    // 사이클이 없었다면 다음 탱크 탐색
    walk(nextTank, tank);

    // 사이클을 만났다면 탐색 중지
    if (cycleDetected) {
      return;
    }
  }

  // 사이클이 없는 부분은 경로에서 버림
  path.pop_back();
}

void solve() {
  int numTanks;
  cin >> numTanks;

  for (int i = 0; i < numTanks; ++i) {
    int tank1, tank2;
    cin >> tank1 >> tank2;
    channels[tank1].push_back(tank2);
    channels[tank2].push_back(tank1);
  }

  walk(1, NULL_NODE);

  // 사이클 부분만 정렬해 답으로 구함
  int cycleNode = path.back();
  vector<int> cyclePath (find(path.begin(), path.end(), cycleNode), path.end()-1);
  sort(cyclePath.begin(), cyclePath.end());

  cout << cyclePath.size() << '\n';
  for (int tank : cyclePath) {
    cout << tank << " ";
  }
  cout << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  solve();
}
