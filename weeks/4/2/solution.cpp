#include <iostream>

using namespace std;

constexpr int SIDE_LEN = 42;

int grid[SIDE_LEN][SIDE_LEN];
int nextGrid[SIDE_LEN][SIDE_LEN];

bool isAllTurned(int side) {
  for (int y = 1; y <= side; ++y) {
    for (int x = 1; x <= side; ++x) {
      if (grid[y][x] > 0) {
        return false;
      }
    }
  }

  return true;
}

void turn(int side) {
  // write next state into next grid
  for (int y = 1; y <= side; ++y) {
    for (int x = 1; x <= side; ++x) {
      if (grid[y][x] == 0) {
        nextGrid[y][x] = 0;
        continue;
      }

      int turnedNeighbors = 0;
      if (grid[y+1][x] == 0) {
        turnedNeighbors++;
      }
      if (grid[y-1][x] == 0) {
        turnedNeighbors++;
      }
      if (grid[y][x+1] == 0) {
        turnedNeighbors++;
      }
      if (grid[y][x-1] == 0) {
        turnedNeighbors++;
      }

      nextGrid[y][x] = max(0, grid[y][x] - turnedNeighbors);
    }
  }

  // write next grid into current grid
  for (int y = 1; y <= side; ++y) {
    for (int x = 1; x <= side; ++x) {
      grid[y][x] = nextGrid[y][x];
    }
  }
}

void solve() {
  int side;

  for (int y = 0; y < SIDE_LEN; ++y) {
    fill(grid[y], grid[y] + SIDE_LEN, 1);
  }

  cin >> side;

  for (int y = 1; y <= side; ++y) {
    for (int x = 1; x <= side; ++x) {
      cin >> grid[y][x];
    }
  }

  int days = 0;
  while (!isAllTurned(side)) {
    turn(side);

    days++;
  }
  cout << days << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  solve();
}
