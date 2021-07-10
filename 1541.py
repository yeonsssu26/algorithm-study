import re

s = input()
numbers = re.findall("\d+", s)
numbers = list(map(int, numbers))  # 리스트의 원소들을 한꺼번에 형변환
# print(numbers)

opers = []
for i in range(len(s)):
    if s[i] not in [str(n) for n in range(10)]:
        opers.append(s[i])
# print(opers)

if "-" not in opers:
    print(sum(numbers))

else:
    # 뺄셈 이후마다 괄호를 치면 최소가 됨
    res = numbers[0]
    plus, minus = [], []
    for i in range(len(opers)):
        # print(opers[i], numbers[i + 1])
        if opers[i] == "+":
            if minus == []:
                plus.append(numbers[i + 1])
            else:
                minus.append(numbers[i + 1])

        else:
            if plus != []:
                for item in plus:
                    res += item
                plus = []

            if minus != []:
                for item in minus:
                    res -= item
                minus = []
            minus.append(numbers[i + 1])

    if plus != []:
        for item in plus:
            res += item
    if minus != []:
        for item in minus:
            res -= item

    print(res)
