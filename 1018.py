n,m = map(int, input().split())
board = [[str(x) for x in input().split()] for y in range(n)]

for i in range(n):
    tmp = board[i][0]
    for j in range(len(tmp)):
        if j == 0 : board[i][j] = tmp[j]
        else: board[i].append(tmp[j])

wBoard = [['W' for x in range(m)] for y in range(n)]
bBoard = [['B' for x in range(m)] for y in range(n)]
for i in range(n):
    for j in range(m):
        if (i + j) % 2 != 0:
            bBoard[i][j] = 'W'
            wBoard[i][j] = 'B'

wCnt = 0; bCnt = 0
for i in range(n):
    for j in range(m):
        if(wBoard[i][j] != board[i][j]):
            wBoard[i][j] = 'O'; wCnt += 1
        if(bBoard[i][j] != board[i][j]):
            bBoard[i][j] = 'O'; bCnt += 1

cut = []
for i in range(n-8+1):
    for j in range(m-8+1):
        cnt1 = 0; cnt2 = 0
        for x in range(i, i+8):
            for y in range(j, j+8):
                if wBoard[x][y] == 'O': cnt1 += 1
                if bBoard[x][y] == 'O': cnt2 += 1
        cut.append(cnt1); cut.append(cnt2)
cut.sort()
print(cut[0])