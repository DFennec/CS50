def main():#main should always be on line 1
    meow(5)

def meow(n):#these functions should and could be hidden so that you only need to call them in main
    for _ in range(n):
        print((_+1),"meow")

main()#likewise, it should be called last in your program
