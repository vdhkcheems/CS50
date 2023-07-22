def main():
    h = getheight()
    k=h-1
    n=1
    for i in range(h):
        for j in range(k):
            print(" ", end="")
        k -= 1
        for l in range(n):
            print("#", end="")
        n += 1
        print()




def getheight():
    while True:
        try:
            height = int(input("Height: "))
            if height > 0 and height < 9:
                return height
        except ValueError:
            print("Provide an integer between 1 and 8")

main()