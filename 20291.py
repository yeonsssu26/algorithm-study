N = int(input())
files = [input().split(".") for _ in range(N)]

ans = dict()
for i in range(len(files)):
    ans[files[i][1]] = 0

for i in range(len(files)):
    ans[files[i][1]] = ans.get(files[i][1]) + 1
ans = sorted(ans.items())

for i in range(len(ans)):
    print(*ans[i])