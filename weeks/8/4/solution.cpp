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

  for (int neighbor : neighborCities[city]) {
    if (visited[neighbor]) {
      continue;
    }

    collectTrash(neighbor, capacity);

    for (int i = 1; i <= capacity; ++i) {
      dp[city][i] = max(dp[city][i], dp[neighbor][i]);
    }
  }

  visited[city] = false;

  int cityTrash = trashes[city];

  for (int i = capacity; i >= cityTrash; --i) {
    int notCollected = dp[city][i];
    int collected = dp[city][i-cityTrash]+cityTrash;

    dp[city][i] = max(notCollected, collected);
  }
}

void solve() {
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

  collectTrash(1, capacity);
  cout << dp[1][capacity] << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  solve();
}
