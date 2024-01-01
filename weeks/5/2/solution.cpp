#include <iostream>

using namespace std;

constexpr int SAND = 1;
constexpr int WATER = 0;
constexpr int MAX_SIDE_LEN = 101;

int dx[4] { -1, 1, 0, 0 };
int dy[4] { 0, 0, -1, 1 };
int grid[MAX_SIDE_LEN][MAX_SIDE_LEN];
int gridCopy[MAX_SIDE_LEN][MAX_SIDE_LEN];
bool visited[MAX_SIDE_LEN][MAX_SIDE_LEN];

// 좌표에 속하는 섬에 대해, visited 배열에 방문을 기록하는 함수
// 섬 구역은 DFS로 탐색
void visitIsland(int y, int x, int gridHeight, int gridWidth) {
  if (visited[y][x]) {
    return;
  }
  visited[y][x] = true;

  for (int i = 0; i < 4; ++i) {
    int ny = y + dy[i];
    int nx = x + dx[i];

    if (ny < 0 || nx < 0 || ny >= gridHeight || nx >= gridWidth) {
      continue;
    }
    if (grid[ny][nx] == WATER) {
      continue;
    }

    visitIsland(ny, nx, gridHeight, gridWidth);
  }
}

// 섬의 개수를 두 개까지 세는 함수
int countIslandsUptoTwo(int gridHeight, int gridWidth) {
  fill(&visited[0][0], &visited[0][0] + MAX_SIDE_LEN*MAX_SIDE_LEN, false);

  // 새로 방문하는 섬을 두 개까지 세고 리턴
  int count = 0;
  for (int y = 0; y < gridHeight; ++y) {
    for (int x = 0; x < gridWidth; ++x) {
      if (visited[y][x]) {
        continue;
      }
      if (grid[y][x] == WATER) {
        continue;
      }

      visitIsland(y, x, gridHeight, gridWidth);
      count++;

      if (count >= 2) {
        return count;
      }
    }
  }

  return count;
}

void solve() {
  int gridHeight, gridWidth;
  cin >> gridHeight >> gridWidth;

  for (int y = 0; y < gridHeight; ++y) {
    for (int x = 0; x < gridWidth; ++x) {
      cin >> grid[y][x];
    }
  }

  int minutes = 0;
  while (true) {
    // 섬의 개수를 세고, 결과를 내야할 때 루프를 멈춤
    int islands = countIslandsUptoTwo(gridHeight, gridWidth);
    if (islands == 0) {
      cout << -1 << '\n';
      return;
    }
    if (islands >= 2) {
      cout << minutes << '\n';
      return;
    }

    // grid를 다음 상태로 업데이트하고 분을 증가
    // 이전 상태를 복사한 뒤, 이로부터 다음 상태를 grid에 덮어 씀
    copy(&grid[0][0], &grid[0][0] + MAX_SIDE_LEN*MAX_SIDE_LEN, &gridCopy[0][0]);
    for (int y = 0; y < gridHeight; ++y) {
      for (int x = 0; x < gridWidth; ++x) {
        if (gridCopy[y][x] == SAND) {
          continue;
        }

        for (int i = 0; i < 4; ++i) {
          int ny = y + dy[i];
          int nx = x + dx[i];

          if (ny < 0 || nx < 0 || ny >= gridHeight || nx >= gridWidth) {
            continue;
          }
          grid[ny][nx] = WATER;
        }
      }
    }
    minutes++;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  solve();
}
