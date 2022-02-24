def draw(len, row, col):
    for i in range(len):
        if i == 0 or i == len - 1:  # 윗변, 아랫변
            for j in range(len):
                arr[row + i][col + j] = "*"
        else:  # 높이
            arr[row + i][col] = "*"  # 첫번째 열
            arr[row + i][col + len - 1] = "*"  # 마지막 열


def square(n, row, col):
    len = 4 * n - 3
    draw(len, row, col)
    if n == 1:
        return
    square(n - 1, row + 2, col + 2)


N = int(input())
arr = [[" " for _ in range(4 * N - 3)] for _ in range(4 * N - 3)]
square(N, 0, 0)

# for i in range(4 * N - 3):
#     print(*arr[i])

for i in range(4 * N - 3):
    for j in range(4 * N - 3):
        print(arr[i][j], end="")
    print()