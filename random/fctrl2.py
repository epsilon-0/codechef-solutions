t = int(raw_input())

def fct(n):
    ans = 1
    for i in range(2, n+1):
        ans *= i
    return ans

for i in range(t):
    ans = int(raw_input())
    print fct(ans)
