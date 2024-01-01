import sys
sys.setrecursionlimit(10**6)
readline = sys.stdin.readline

def solveSub():
    numPeople = int(readline())
    scores = list(map(int, readline().split()))

    sumScores = sum(scores)

    numPassed = len(list(filter(lambda n: n * numPeople >= sumScores, scores)))
    print(f'{numPassed}/{numPeople}')

numExams = int(readline())
for _ in range(numExams):
    solveSub()
