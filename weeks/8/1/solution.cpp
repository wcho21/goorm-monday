#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

constexpr int MAX_LEN_GOORM_NUM = 1001;
char goormNum[MAX_LEN_GOORM_NUM];

unordered_map<string, int> table {
  { "qw", 1 },
  { "as", 2 },
  { "zx", 3 },
  { "we", 4 },
  { "sd", 5 },
  { "xc", 6 },
  { "er", 7 },
  { "df", 8 },
  { "cv", 9 },
  { "ze", 0 },
};

void solve() {
  int goormNumLen;
  cin >> goormNumLen;

  for (int i = 0; i < goormNumLen; ++i) {
    cin >> goormNum[i];
  }

  for (int i = 0; i < goormNumLen-1; ++i) {
    // 변환할 수 없으면 스킵
    string twoChars { goormNum[i], goormNum[i+1] };
    if (table.count(twoChars) == 0) {
      continue;
    }

    // 변환할 수 있으면 그 결과를 출력
    cout << table[twoChars];
  }

  cout << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  solve();
}
