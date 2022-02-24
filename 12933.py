duck = input()
visited = [False for _ in range(len(duck))]

if len(duck) % 5 != 0:
    print(-1)  # quack은 5글자이므로 올바른 울음소리는 5로 나누었을 때 나머지가 0이어야 함
else:
    # 오리 수를 센다
    ans = 0
    for i in range(len(duck)):
        if duck[i] == "q" and not visited[i]:
            quack = "quack"
            idx = 0
            first = True

            for j in range(i, len(duck)):
                if duck[j] == quack[idx] and not visited[j]:
                    visited[j] = True
                    if duck[j] == "k":
                        if first:
                            ans += 1
                            first = False
                        idx = 0
                        continue
                    idx += 1

    if ans == 0 or False in visited:
        print(-1)  # 오리가 없거나 모든 울음소리가 체크되지 않았다면
    else:
        print(ans)
