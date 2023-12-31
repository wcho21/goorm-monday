#include <string>
#include <iostream>
#include <map>

using namespace std;

constexpr int MAX_NUM_PRESSES = int(1e5+1);

char presses[MAX_NUM_PRESSES];
string pads[] = { "", "1.,?!", "2ABC", "3DEF", "4GHI", "5JKL", "6MNO", "7PQRS", "8TUV", "9WXYZ" };

char getCharFromPresses(char key, int presses) {
  // 숫자로 변환
  int keyNum = key - '0';

  // 키 패드의 문자 인덱스 구하기
  // 누른 횟수가 1부터 시작이므로 배열 인덱스로 쓰기 위해 -1
  int mod = int(pads[keyNum].size());
  int keyIndex = (presses-1) % mod;

  return pads[keyNum][keyIndex];
}

void solve() {
  int numPresses;
  cin >> numPresses;
  for (int i = 0; i < numPresses; ++i) {
    cin >> presses[i];
  }

  char curChar = presses[0];
  int numStreaks = 1;
  for (int i = 0; i < numPresses; ++i) {
    if (presses[i] == presses[i+1]) {
      numStreaks++;
      continue;
    }

    // 현재 문자와 다음 것과 다를 때 입력할 문자를 구함
    cout << getCharFromPresses(curChar, numStreaks);

    // 현재 문자와 입력 횟수 초기화
    numStreaks = 1;
    curChar = presses[i+1];
  }

  cout << '\n';
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  solve();
}
