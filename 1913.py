N, M = int(input()), int(input())
map = [[0 for _ in range(N)] for _ in range(N)]

num = N ** 2
for k in range(0, N // 2 + 1):
    for i in range(k, N - k):
        map[i][k] = num
        num -= 1
        if num == -1:
            break

    for j in range(k + 1, N - k):
        map[N - k - 1][j] = num
        num -= 1
        if num == -1:
            break

    for i in range(N - k - 2, k, -1):
        map[i][N - k - 1] = num
        num -= 1
        if num == -1:
            break

    for j in range(N - k - 1, k, -1):
        map[k][j] = num
        num -= 1
        if num == -1:
            break

for i in range(N):
    print(*map[i])

for i in range(N):
    for j in range(N):
        if map[i][j] == M:
            print(i + 1, j + 1)
