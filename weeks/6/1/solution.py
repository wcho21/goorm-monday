import sys
sys.setrecursionlimit(100000)
readline = sys.stdin.readline
from functools import reduce
from operator import mul

for _ in range(5):
    digits = list(map(lambda c: ord(c) - ord('0'), readline()))[:7]

    oddDigitsSum = sum(d for d in digits[::2])
    nonZeroEvenDigits = filter(lambda n: n != 0, digits[1::2])
    evenDigitsProd = reduce(mul, nonZeroEvenDigits, 1)
    print((oddDigitsSum * evenDigitsProd) % 10)
