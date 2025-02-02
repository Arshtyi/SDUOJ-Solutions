n = int(input())
last_op = None
for _ in range(n):
    data = input().split()
    if(len(data) == 3):
        op = data[0]
        a = int(data[1])
        b = int(data[2])
    else:
        op = last_op
        a = int(data[0])
        b = int(data[1])
    last_op = op
    if op == 'a':
        expression = f"{a}+{b}={a+b}"
    elif op == 'b':
        expression = f"{a}-{b}={a-b}"
    elif op == 'c':
        expression = f"{a}*{b}={a*b}"
    print(expression)
    print(len(expression))