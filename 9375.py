T = int(input())
for t in range(T):
    N = int(input())

    wears = dict()
    for n in range(N):
        wear = list(map(str, input().split()))
        if wear[-1] not in wears:
            wears[wear[-1]] = [wear[0]]
        else:
            values = wears[wear[-1]]
            values.append(wear[0])
    # print(wears)

    cnt = 1
    for k in wears.keys():
        cnt *= len(wears[k]) + 1
    print(cnt - 1)
