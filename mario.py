n=0
    while n<1 and n>8:
        n=int(input("Height: "))
        if n>0 and n<9:
            for i in range(n):
                for j in range(n-1-i):
                    print(" ", end="")
                for j in range(i+1):

                    print("#", end="")
                print(" ", end="")
                for j in range(i+1):
                    print("#", end="")
                print()
        else :
            print("Invalid input.")
