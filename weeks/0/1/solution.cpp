#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

constexpr int MAX_NUM_WORDS = int(1e6+1);

string words[MAX_NUM_WORDS];

void solve() {
  int numWords, wordPos; // N, K
  cin >> numWords >> wordPos;

  for (int i = 0; i < numWords; ++i) {
    cin >> words[i];
  }

  // 길이 오름차순으로 먼저 정렬하고, 그 다음 문자열을 사전순으로 정렬
  sort(begin(words), begin(words)+numWords, [](const string& w1, const string& w2) {
    return (w1.size() == w2.size()) ? (w1 < w2) : (w1.size() < w2.size());
  });

  string wordToFind = words[wordPos-1];
  cout << wordToFind << '\n';
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  solve();
}
