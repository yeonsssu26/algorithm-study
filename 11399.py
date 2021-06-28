N = int(input())
times = list(map(int, input().split()))
times.sort()
res = 0
for i in range(N):
    res += times[i] * (N - i)
print(res)