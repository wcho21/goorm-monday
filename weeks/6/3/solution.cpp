#include <iostream>

using namespace std;

string input, key, operation;

// 문자 ch를 (toShift % 26) 번 시프트
// 첫 번째 문자로서 취급할 것을 base로 받음
char convert(char ch, char base, int toShift) {
  int shifted = ((ch - base) + toShift) % 26;
  char converted = shifted + base;
  return converted;
}

void solveCase() {
  cin.get();
  getline(cin, input);
  cin >> operation >> key;

  // 각 문자에 대해 처리
  for (int i = 0; i < (int)input.size(); ++i) {
    char ch = input[i];

    // 알파벳이 아니면 그 문자 그대로 결과를 냄
    if (!isalpha(ch)) {
      cout << ch;
      continue;
    }

    // 오른쪽으로 시프트할 횟수를 구함
    int keyIndex = i % (int)key.size();
    int toShift = key[keyIndex] % 26;
    if (operation == "D") {
      toShift = 26 - toShift;
    }

    // 시프트한 결과를 냄
    if (islower(ch)) {
      cout << convert(ch, 'a', toShift);
    }
    if (isupper(ch)) {
      cout << convert(ch, 'A', toShift);
    }
  }

  cout << '\n';
}

void solve() {
  int numCases;
  cin >> numCases;

  for (int i = 0; i < numCases; ++i) {
    solveCase();
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  solve();
}
