#include <iostream>
#include <string>

using namespace std;

void solve() {
  int strLen;
  string str;
  cin >> strLen >> str;

  // 최소 개수를 구하기 위해, 문자가 바뀐 횟수를 1에서 더함
  char curChar = str[0];
  int numSubStrs = 1;

  for (int i = 1; i < strLen; ++i) {
    if (str[i] != curChar) {
      numSubStrs++;
      curChar = str[i];
    }
  }

  cout << numSubStrs << '\n';
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  solve();
}
