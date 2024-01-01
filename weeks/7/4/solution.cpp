#include <iostream>
#include <queue>
#include <tuple>
#include <vector>

using namespace std;

typedef long long ll;
typedef tuple<ll, ll, ll> triplet;

constexpr ll MAX_NUM_ROOMS = (int)(1e5+1);
constexpr ll MAX_TIME = (ll)(1e15+1);

ll floorNumbers[MAX_NUM_ROOMS];
ll times[MAX_NUM_ROOMS][10];
vector<pair<ll, ll>> passages[MAX_NUM_ROOMS]; // next room, time

// 목적지 방 destRoom에 도달할 수 있으면 최소시간, 아니면 -1을 리턴
ll getTime(ll destRoom) {
  fill(&times[0][0], &times[0][0] + MAX_NUM_ROOMS*10, MAX_TIME);
  times[1][0] = 0;

  priority_queue<triplet, vector<triplet>, greater<triplet>> queue;

  // 1번 방의 다음 방을 큐에 대기
  for (auto [nextRoom, walkingTime] : passages[1]) {
    ll roomMod = 1 % floorNumbers[nextRoom]; // 현재 방이 속한 나머지 그룹
    ll nextTime = walkingTime;

    queue.push({ nextTime, nextRoom, roomMod });
  }

  while (!queue.empty()) {
    auto [time, room, prevMod] = queue.top();
    queue.pop();

    // 도달 했다면 시간을 리턴
    if (room == destRoom) {
      return time;
    }

    for (auto [nextRoom, walkingTime] : passages[room]) {
      ll roomMod = room % floorNumbers[nextRoom]; // 현재 방이 속한 나머지 그룹
      ll nextTime = time + walkingTime;

      // 같은 나머지 그룹의 방에서 이미 시도했다면 스킵
      if (nextTime >= times[nextRoom][roomMod]) {
        continue;
      }

      // 복도를 건널 수 있는지 확인
      ll floorNumber = floorNumbers[room];
      bool walkable = (prevMod % floorNumber) == (nextRoom % floorNumber);
      if (!walkable) {
        continue;
      }

      // 건널 수 있으면 큐에 대기
      times[nextRoom][roomMod] = nextTime;
      queue.push({ nextTime, nextRoom, roomMod });
    }
  }

  return -1;
}

void solve() {
  ll numRooms, numPassages;
  cin >> numRooms >> numPassages;

  ll destRoom = numRooms;

  for (ll i = 1; i <= numRooms; ++i) {
    cin >> floorNumbers[i];
  }

  for (ll i = 0; i < numPassages; ++i) {
    ll room1, room2, time;
    cin >> room1 >> room2 >> time;
    passages[room1].push_back({ room2, time });
    passages[room2].push_back({ room1, time });
  }

  cout << getTime(destRoom) << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  solve();
}
