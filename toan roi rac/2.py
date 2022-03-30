def m(n : int) -> int:
    if n < 10:
        return n
    else :
        temp = n % 10
        return min(m(int(n/10)), temp)


if __name__=="__main__":
    n = input()
    n = int(n)
    print(m(n))