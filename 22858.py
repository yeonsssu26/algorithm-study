N, K = map(int, input().split())
S = list(map(int, input().split()))
D = list(map(int, input().split()))
P = [0 for _ in range(N)]
for _ in range(K):
    for i in range(N):
        P[D[i] - 1] = S[i]
    for i in range(N):
        S[i] = P[i]
print(*P)