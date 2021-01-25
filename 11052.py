n = int(input()) # n : 카드 개수

P = list(map(int, input().split())) # P : 카드 패키지 가격
P.insert(0,0) # i = 1부터 시작하도록 함

DP = [0 for i in range(1001)] # DP 배열

for i in range(1, n+1):
    for j in range(1, i+1):
        DP[i] = max(DP[i], DP[i-j] + P[j])
        # print(DP); print("") # for check

print(DP[n])