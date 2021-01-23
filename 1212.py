oct = int(input())      # 8진수 (input)
if oct == 0: print(0)
else:
    numbers = []        # 8진수의 각 자릿수 저장
    oct = str(oct)
    for i in range(len(oct)):
        numbers.append(int(oct[i]))
    # print(numbers)     # for check

    binary = ""     # 변환된 2진수 (output)
    for i in range(len(numbers)):
        tmp = []    # 각 자릿수를 2진수로 고침
        
        for j in range(3):
            tmp.append(numbers[i] % 2)
            numbers[i] = int(numbers[i] / 2)
        tmp.reverse()
        
        for j in range(3):
            binary += str(tmp[j])

    # print(binary)     # for check
    if binary[0] == '0':
        if binary[1] == '0': print(binary[2:])
        else: print(binary[1:])
    else: print(binary)