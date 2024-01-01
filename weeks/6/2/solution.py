import sys
sys.setrecursionlimit(10**6)
readline = sys.stdin.readline

numEncrypted = int(readline())
encrypted = readline()
decrypted = []

for i in range(0, numEncrypted, 2):
    encryptedChar = encrypted[i]
    encryptedNum = ord(encrypted[i+1]) - ord('0')

    encryptedAsciiIndex = ord(encryptedChar) - ord('a')
    decryptedAsciiIndex = (encryptedAsciiIndex + encryptedNum ** 2) % 26

    decryptedChar = chr(decryptedAsciiIndex + ord('a'))
    decrypted.append(decryptedChar)

print("".join(decrypted))
