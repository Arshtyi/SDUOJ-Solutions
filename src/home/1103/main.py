def judge(n):
    if n % 100 and n % 4 == 0:
        return True
    elif n % 400 == 0:
        return True
    else:
        return False
    
def main():
    n = int(input())
    if judge(n):
        print(1)
    else:
        print(0)

if __name__ == '__main__':
    main()
