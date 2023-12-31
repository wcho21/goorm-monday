#include <string>
#include <iostream>

using namespace std;

constexpr int MAX_NUM_NAMES = int(1e4+1);

string names[MAX_NUM_NAMES];

void solve() {
  int numNames; // N
  string goormName;
  cin >> numNames >> goormName;

  for (int i = 0; i < numNames; ++i) {
    cin >> names[i];
  }

  // 주인공의 이름을 포함하는 것을 세기
  int numIncluded = 0;
  for (int i = 0; i < numNames; ++i) {
    string name = names[i];
    if (name.find(goormName) != string::npos) {
      numIncluded++;
    }
  }

  cout << numIncluded << '\n';
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  solve();
}
