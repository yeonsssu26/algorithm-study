"""
[문제조건] 각 테스트 케이스에 대해 어린 왕자가 거쳐야 할 최소의 행성계 진입/이탈 횟수를 출력한다.

[testcase]
2               : testcase 개수(T)

-5 1 12 1       : 출발점(x1,y1), 도착점(x2,y2)
7               : 행성의 개수(n)
1 1 8           : 행성의 중점과 반지름(cx,cy,r)
-3 -1 1         : 행성의 중점과 반지름(cx,cy,r)
2 2 2           : 행성의 중점과 반지름(cx,cy,r)
5 5 1           : 행성의 중점과 반지름(cx,cy,r)
-4 5 1          : 행성의 중점과 반지름(cx,cy,r)
12 1 1          : 행성의 중점과 반지름(cx,cy,r)
12 1 2          : 행성의 중점과 반지름(cx,cy,r)

-5 1 5 1        : 출발점(x1,y1), 도착점(x2,y2)
1               : 행성의 개수(n)
0 0 2           : 행성의 중점과 반지름(cx,cy,r)

[algorithm]
startpoint와 endpoint
    - 둘다 원 안에 있으면 0번
    - 둘다 원 밖에 있으면 0번
    - 둘중 하나만 원 안에 있으면 1번

"""

T = int(input())
for i in range(T):
    res = 0
    x1, y1, x2, y2 = map(int, input().split())  # 출발점, 도착점
    n = int(input())  # 행성의 개수

    for j in range(n):
        cx, cy, r = map(int, input().split())

        # 출발점
        if (x1 - cx) * (x1 - cx) + (y1 - cy) * (y1 - cy) < r * r:
            flag1 = 1
        else:
            flag1 = -1

        # 도착점
        if (x2 - cx) * (x2 - cx) + (y2 - cy) * (y2 - cy) < r * r:
            flag2 = 1
        else:
            flag2 = -1

        # 둘 중 하나만 원 안에 있으면 1
        if flag1 * flag2 == -1:
            res += 1

    print(res)
