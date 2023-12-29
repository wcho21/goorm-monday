#include <iostream>
#include <vector>

using namespace std;

constexpr int MAX_NUM_CITIES = (int)(1e3+1);
constexpr int MAX_CAPACITY = (int)(1e4+1);

vector<int> neighborCities[MAX_NUM_CITIES];
int trashes[MAX_NUM_CITIES];
bool visited[MAX_NUM_CITIES];
int dp[MAX_NUM_CITIES][MAX_CAPACITY];

void collectTrash(int city, int capacity) {
  visited[city] = true;

  // 다음 도시에 대해 dp 테이블 완성
  for (int neighbor : neighborCities[city]) {
    if (visited[neighbor]) {
      continue;
    }

    collectTrash(neighbor, capacity);

    // 최댓값을 테이블에 반영
    for (int i = 1; i <= capacity; ++i) {
      dp[city][i] = max(dp[city][i], dp[neighbor][i]);
    }
  }

  visited[city] = false;

  int cityTrash = trashes[city];

  // 이 도시의 쓰레기를 수거한 경우와 아닌 경우 중에 최댓값 반영
  for (int i = capacity; i >= cityTrash; --i) {
    int notCollected = dp[city][i];
    int collected = dp[city][i-cityTrash]+cityTrash;

    dp[city][i] = max(notCollected, collected);
  }
}

void solve() {
  // 입력 처리
  int numCities, capacity;
  cin >> numCities >> capacity;

  for (int i = 0; i < numCities-1; ++i) {
    int city1, city2;
    cin >> city1 >> city2;

    neighborCities[city1].push_back(city2);
    neighborCities[city2].push_back(city1);
  }

  for (int i = 1; i <= numCities; ++i) {
    cin >> trashes[i];
  }

  // 1번 도시에서 시작
  collectTrash(1, capacity);

  cout << dp[1][capacity] << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  solve();
}
