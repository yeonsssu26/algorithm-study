N = int(input())
map1, map2 = [list(input()) for _ in range(N)], [list(input()) for _ in range(N)]
map3 = [[0 for _ in range(N)] for _ in range(N)]

# 8개의 칸에서 *를 find하는 방식은 너무 지저분함
# *의 좌표를 저장해두고 그걸 바탕으로 주변칸에 1씩 더하는 방식으로 접근해보자
where = []
for i in range(N):
    for j in range(N):
        if map1[i][j] == "*":
            where.append([i, j])
            if i != 0:
                if j != 0:
                    map3[i - 1][j - 1] += 1
                map3[i - 1][j] += 1
                if j != N - 1:
                    map3[i - 1][j + 1] += 1
            if j != 0:
                map3[i][j - 1] += 1
            if j != N - 1:
                map3[i][j + 1] += 1
            if i != N - 1:
                if j != 0:
                    map3[i + 1][j - 1] += 1
                map3[i + 1][j] += 1
                if j != N - 1:
                    map3[i + 1][j + 1] += 1
# print(*where)
# for i in range(N):
#     for j in range(N):
#         print(map3[i][j], end="")
#     print()

flag = False
for i in range(N):
    for j in range(N):
        if map2[i][j] == "x" and map1[i][j] == "*":  # 지뢰밟음
            flag = True
            break

if flag:
    # 숫자랑 지뢰 표시
    for i in range(N):
        for j in range(N):
            if map1[i][j] == "*":
                print("*", end="")
            else:
                if map2[i][j] == "x":
                    print(map3[i][j], end="")
                else:
                    print(".", end="")
        print()
else:
    # 지뢰 표시 안하고 x 자리에 해당하는 숫자만 표시
    for i in range(N):
        for j in range(N):
            if map2[i][j] == "x":
                print(map3[i][j], end="")
            else:
                print(".", end="")
        print()