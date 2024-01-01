#include <iostream>

using namespace std;

constexpr int MAX_NUM_PEOPLE = int(1e3+1);

int scores[MAX_NUM_PEOPLE];

void solveSub() {
  int numPeople;
  cin >> numPeople;

  for (int i = 0; i < numPeople; ++i) {
    cin >> scores[i];
  }

  int sumScore = 0;
  for (int i = 0; i < numPeople; ++i) {
    sumScore += scores[i];
  }

  int numPassed = 0;
  for (int i = 0; i < numPeople; ++i) {
    bool passed = scores[i] * numPeople >= sumScore; // avoid using division
    if (passed) {
      numPassed++;
    }
  }

  cout << numPassed << "/" << numPeople << '\n';
}

void solve() {
  int numExams;
  cin >> numExams;

  for (int i = 0; i < numExams; ++i) {
    solveSub();
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  solve();
}
