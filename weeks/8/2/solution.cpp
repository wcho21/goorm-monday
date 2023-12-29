#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

void solve() {
  int numPeaks;
  cin >> numPeaks;

  vector<int> peakStack;

  for (int i = 0; i < numPeaks; ++i) {
    int peak;
    cin >> peak;

    // 현재 스택의 개수 출력
    cout << (int)(peakStack.size()) << " ";

    // 현재 봉우리보다 작은 봉우리를 스택에서 버림
    while (true) {
      if (peakStack.empty()) {
        break;
      }
      if (peak < peakStack.back()) {
        break;
      }

      peakStack.pop_back();
    }

    // 현재 봉우리를 스택에 넣음
    peakStack.push_back(peak);
  }

  cout << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  solve();
}
