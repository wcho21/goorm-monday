import sys
sys.setrecursionlimit(100000)
readline = sys.stdin.readline
from collections import defaultdict

numPeople = int(readline())
numRelationships = int(readline())

relationships = defaultdict(list)

for _ in range(numRelationships):
    person1, person2 = map(int, readline().split())

    relationships[person1].append(person2)
    relationships[person2].append(person1)

visited = [False] * (numPeople+1)

# DFS로 방문한 사람을 visited로 기억
def visitGroup(person):
    if visited[person]:
        return
    visited[person] = True

    for nextPerson in relationships[person]:
        visitGroup(nextPerson)

# 1번 사람부터 방문
visitGroup(1)

# 방문한 사람의 수
visitedCounts = len(list(filter(lambda _: _ == True, visited)))
print(visitedCounts)
