def judge(year,month):
    nums = {
        "1":31,
        "2":28,
        "3":31,
        "4":30,
        "5":31,
        "6":30,
        "7":31,
        "8":31,
        "9":30,
        "10":31,
        "11":30,
        "12":31
    }
    if year % 4 == 0 and year % 100 != 0 or year % 400 == 0:
        nums["2"] = 29
    return nums[str(month)]

def main():
    year,month = map(int,input().split())
    print(judge(year,month))

if __name__ == '__main__':
    main()