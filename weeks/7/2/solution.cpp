#include <iostream>
#include <vector>

using namespace std;

constexpr int MAX_NUM_PEOPLE = 501;

vector<int> relationships[MAX_NUM_PEOPLE];
bool visited[MAX_NUM_PEOPLE];

// DFS로 방문한 사람을 visited로 기억
void visitGroup(int person) {
  if (visited[person]) {
    return;
  }
  visited[person] = true;

  for (int nextPerson : relationships[person]) {
    visitGroup(nextPerson);
  }
}

void solve() {
  int numPeople, numRelationships;
  cin >> numPeople >> numRelationships;

  for (int i = 0; i < numRelationships; ++i) {
    int person1, person2;
    cin >> person1 >> person2;

    relationships[person1].push_back(person2);
    relationships[person2].push_back(person1);
  }

  // 1번 사람부터 방문
  visitGroup(1);

  // 방문한 사람의 수
  int visitedCounts = 0;
  for (int i = 1; i <= numPeople; ++i) {
    if (visited[i]) {
      visitedCounts++;
    }
  }
  cout << visitedCounts << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  solve();
}
