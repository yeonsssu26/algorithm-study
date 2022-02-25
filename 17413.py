# reference : https://kongpowder.tistory.com/128
import re

_input = input()
if "<" not in _input:
    for word in _input.split():
        print(word[::-1], end=" ")
else:
    pattern = re.compile("<[a-zA-Z0-9 ]+>|[a-zA-Z0-9 ]")
    S = pattern.findall(_input)
    # print(S)

    not_swap = ""
    for s in S:
        if s == " ":
            print(not_swap[::-1] + " ", end="")
            not_swap = ""
        elif "<" in s:
            print(not_swap[::-1], end="")
            not_swap = ""
            print(s, end="")
        else:
            not_swap += s
    print(not_swap[::-1])