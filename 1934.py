def GCD(num1, num2): # 최대공약수
    big = max(num1,num2)
    small = min(num1,num2)
    
    # 유클리드 호제법
    if small == 0: return big
    else: return GCD(small, big % small)
    
def LCM(num1, num2, gcd): # 최소공배수
    return int(num1 * num2 / gcd)

testcase = int(input())
for i in range(testcase):
    num1, num2 = map(int, input().split())
    gcd = GCD(num1, num2)
    lcm = LCM(num1, num2, gcd)
    print(lcm)