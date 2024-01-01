import sys
sys.setrecursionlimit(10**6)
readline = sys.stdin.readline

names = []

numNames, goormName = readline().split()
numNames = int(numNames)

for i in range(numNames):
    name = readline()
    names.append(name)

# 주인공의 이름을 포함하는 것을 세기
numIncluded = 0
for name in names:
    if goormName in name:
        numIncluded += 1

print(numIncluded)
