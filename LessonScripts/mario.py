def mario(n):
    for i in range(n):
        for j in range(i+1):
            print("#",end="")
        print()
    print("?" * n)

    print("--EOF-- " * n)
mario(int(input("Bricks: ")))
