import sys
sys.setrecursionlimit(10**6)
readline = sys.stdin.readline
from heapq import heappop, heappush

MAX_NUM_ROOMS = int(1e5+1)
MAX_TIME = int(1e15+1)

floorNumbers = [1] * MAX_NUM_ROOMS
times = [[MAX_TIME] * 10 for _ in range(MAX_NUM_ROOMS)]
passages = [[] for _ in range(MAX_NUM_ROOMS)]

numRooms, numPassages = map(int, readline().split())
destRoom = numRooms

for i, floorNumber in enumerate(map(int, readline().split()), start=1):
    floorNumbers[i] = floorNumber

for _ in range(numPassages):
    room1, room2, time = map(int, readline().split())

    passages[room1].append((room2, time))
    passages[room2].append((room1, time))

# 목적지 방 destRoom에 도달할 수 있으면 최소시간, 아니면 -1을 리턴
def getTime(destRoom):
    times[1][0] = 0

    queue = []

    # 1번 방의 다음 방을 큐에 대기
    for nextRoom, walkingTime in passages[1]:
        roomMod = 1 % floorNumbers[nextRoom] # 현재 방이 속한 나머지 그룹
        nextTime = walkingTime

        heappush(queue, (nextTime, nextRoom, roomMod))

    while len(queue) > 0:
        time, room, prevMod = heappop(queue)

        # 도달 했다면 시간을 리턴
        if room == destRoom:
            return time

        for nextRoom, walkingTime in passages[room]:
            roomMod = room % floorNumbers[nextRoom] # 현재 방이 속한 나머지 그룹
            nextTime = time + walkingTime

            # 같은 나머지 그룹의 방에서 이미 시도했다면 스킵
            if nextTime >= times[nextRoom][roomMod]:
                continue

            # 복도를 건널 수 있는지 확인
            floorNumber = floorNumbers[room]
            walkable = (prevMod % floorNumber) == (nextRoom % floorNumber)
            if not walkable:
                continue

            # 건널 수 있으면 큐에 대기
            times[nextRoom][roomMod] = nextTime
            heappush(queue, (nextTime, nextRoom, roomMod))

    return -1

print(getTime(destRoom))
