# input
N, M = map(int, input().split())
mat1 = [list(map(int, input())) for _ in range(N)]
mat2 = [list(map(int, input())) for _ in range(N)]

# convert
def convert3x3(mat2, i, j):
    for x in range(i, i + 3):
        for y in range(j, j + 3):
            mat2[x][y] = 1 - mat2[x][y]


res = 0
for i in range(N - 2):
    for j in range(M - 2):
        if mat1[i][j] != mat2[i][j]:
            convert3x3(mat2, i, j)
            res += 1

# not same >> -1
if mat1 != mat2:
    print(-1)
else:
    print(res)
