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

    cout << (int)(peakStack.size()) << " ";

    while (true) {
      if (peakStack.empty()) {
        break;
      }
      if (peak < peakStack.back()) {
        break;
      }

      peakStack.pop_back();
    }
    peakStack.push_back(peak);
  }

  cout << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  solve();
}
