#include <iostream>

using namespace std;

constexpr int MAX_NUM_ENCRYPTED = 200000+1;
constexpr int MAX_NUM_DECRYPTED = 100000+1;

char encrypted[MAX_NUM_ENCRYPTED];
char decrypted[MAX_NUM_DECRYPTED];

void solve() {
  int numEncrypted;
  cin >> numEncrypted >> encrypted;

  for (int i = 0; i < numEncrypted; i += 2) {
    char encryptedChar = encrypted[i];
    int encryptedNum = encrypted[i+1] - '0';

    int encryptedIndex = encryptedChar - 'a';
    int decryptedIndex = (encryptedIndex + encryptedNum * encryptedNum) % 26;

    char decryptedChar = decryptedIndex + 'a';
    decrypted[i/2] = decryptedChar;
  }

  cout << decrypted << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  solve();
}
