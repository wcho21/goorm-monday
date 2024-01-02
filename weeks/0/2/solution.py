import sys
sys.setrecursionlimit(10**6)
readline = sys.stdin.readline
from resource import setrlimit, RLIMIT_STACK
setrlimit(RLIMIT_STACK, (-1, -1))

groupCards = []
groupPeople = []

numPeople, numFriends = map(int, readline().split())
cards = [0] + list(map(int, readline().split()))

visited = [False] * (numPeople+1)
friends = [[] for _ in range(numPeople+1)]

for _ in range(numFriends):
    person1, person2 = map(int, readline().split())
    friends[person1].append(person2)
    friends[person2].append(person1)

# DFS로 그룹 사람들의 번호와 카드를 모으는 함수
def collectGroup(person):
    groupCards.append(cards[person])
    groupPeople.append(person)

    for nextPerson in friends[person]:
        if visited[nextPerson]:
            continue
        visited[nextPerson] = True

        collectGroup(nextPerson)

unhappiness = 0

for person in range(1, numPeople+1):
    if visited[person]:
        continue
    visited[person] = True

    # 각 그룹마다 번호와 카드를 모아서 정렬
    groupCards = []
    groupPeople = []

    collectGroup(person)
    groupCards.sort()
    groupPeople.sort()

    # 불만족도를 계산하여 더함
    for i in range(len(groupCards)):
        unhappiness += abs(groupCards[i] - groupPeople[i])

print(unhappiness)
