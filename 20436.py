right = {
    "y": [0, 5],
    "u": [0, 6],
    "i": [0, 7],
    "o": [0, 8],
    "p": [0, 9],
    "h": [1, 5],
    "j": [1, 6],
    "k": [1, 7],
    "l": [1, 8],
    "b": [2, 4],
    "n": [2, 5],
    "m": [2, 6],
}
left = {
    "q": [0, 0],
    "w": [0, 1],
    "e": [0, 2],
    "r": [0, 3],
    "t": [0, 4],
    "a": [1, 0],
    "s": [1, 1],
    "d": [1, 2],
    "f": [1, 3],
    "g": [1, 4],
    "z": [2, 0],
    "x": [2, 1],
    "c": [2, 2],
    "v": [2, 3],
}

SL, SR = map(str, input().split())

word = list(input())

IL, IR = left.get(SL), right.get(SR)

LT, RT = 0, 0
for w in word:
    if w in list(left.keys()):
        LT += abs(IL[0] - left.get(w)[0]) + abs(IL[1] - left.get(w)[1])
        IL = left.get(w)
        # print(IL)
    elif w in list(right.keys()):
        RT += abs(IR[0] - right.get(w)[0]) + abs(IR[1] - right.get(w)[1])
        IR = right.get(w)
        # print(IR)
print(LT + RT + len(word))