import sys
sys.stdin = open('data.in', 'r')
sys.stdout = open('data.out', 'w')
names=[]

def main():
    n,t,s = map(int, input().split())
    for _ in range(n):
        line = input().strip()
        parts = line.split(',')
        attacker, weapon = parts[0].split('use')
        parts = parts[1:]
        weapon = weapon.upper()
        if 'AK' not in weapon:
            continue
        parts[0]=parts[0][4:]
        parts[-1]=parts[-1][:-1]
        for part in parts:
            if 'ash' == part:
                t=t-s
                names.append(attacker)
                break
    if t<=0:
        print("Heros never die.")
    else:
        print(len(names))
        for name in names:
            print(name)
if __name__ == '__main__':
    main()